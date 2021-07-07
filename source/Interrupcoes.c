/*
 * Interrupcoes.c
 *
 *  Created on: 28 de mai de 2021
 *      Author: Rosimar
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL33Z644.h"
#include "config.h"
#include "fsl_lpuart.h"
/* TODO: insert other include files here. */

bool SW3;
bool SW2;
int ContPiscaLed,contMedida;
extern int contTempo,contBotao,contMed;;

extern bool enable,enableMed,piscaLed;
uint8_t pont,endFrame, usbRec[20];
uint32_t interrupt;
extern int contHora;
extern uint8_t acordado,tela;
/**********************************************************************************************************************/
// Nesta interrupção faz a leitura dos dados que chegam na serial
/**********************************************************************************************************************/
void LPUART0_SERIAL_RX_TX_IRQHANDLER(void) {

	  if ((kLPUART_RxOverrunFlag ) & LPUART_GetStatusFlags(LPUART0))
	  {
		  LPUART_ClearStatusFlags(LPUART0_PERIPHERAL, kLPUART_RxOverrunFlag);
	  }


    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART0))
    {
    	usbRec[pont] = LPUART_ReadByte(LPUART0);
    	pont++;
    	if(pont >= 3)
    	{
    		endFrame = usbRec[2];

    		if(endFrame == pont)
    		{
    			endFrame =0;
    			pont =0;

    			comandoUsb(usbRec[3]);
    			for(uint8_t i = 0; i<= 20;++i)
    			{
    				usbRec[i] = 0;
    			}
    		}
    	}
    			//LPUART_ReadBlocking(LPUART0, &usbRec, sizeof(usbRec));
    }


  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
/**********************************************************************************************************************/
// Nesta interrupção faz a leitura das entradas SW2 e SW3 somente
/**********************************************************************************************************************/
void GPIOC_IRQHANDLER(void) {
  /* Get pin flags */

  uint32_t pin_flags = GPIO_PortGetInterruptFlags(GPIOC);

 switch(pin_flags)
 {
 	 case 4:SW3 = 1; break;
 	 case 8: SW2 = 1; break;
 	 default :
 	 {
 		 SW3 = 0;
 		 SW2 = 0;
 	 }break;
 }


  /* Place your interrupt code here */

  /* Clear pin flags */
  GPIO_PortClearInterruptFlags(GPIOC, pin_flags);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

/**********************************************************************************************************************/
// Esta interrupção é gerada a cada 1 milissegundo 1000Hz, para mudar este tempo vá em Peripherals no canto superior direito (ìcone)
// e altere a frequência no campo especificado.
/**********************************************************************************************************************/
void timerInterrupt(void) {
  uint32_t intStatus,med;
  /* Reading all interrupt flags of status register */
  intStatus = TPM_GetStatusFlags(TPM0_PERIPHERAL);
  TPM_ClearStatusFlags(TPM0_PERIPHERAL, intStatus);


  if(contTempo)
  {
	  contTempo --;
	  if(contTempo <= 0) contTempo  = 0;
  }

  if(contBotao)
  {
	  contBotao --;
	  if(contBotao <= 0) contBotao  = 0;
  }

  if(contMed)
  {
	  contMed --;
	  if(contMed <= 0){ contMed  = 200; interrupt = medidaAnalogica(3);}
  }

  if(contHora)
  {
	  contHora--;
	  if(contHora <= 0){contHora = 0;}
  }


  if(contMedida)
  {
	  contMedida--;
	  if(contMedida <= 0){contMedida = 0;}
  }

  if(ContPiscaLed)
  {
	  ContPiscaLed--;
	  if(ContPiscaLed <= 0){
		  piscaLed = false;
		  ContPiscaLed = 0;
		  Led2_PutVal(0);
		  Led3_PutVal(0);
		  Led4_PutVal(0);
		  Led5_PutVal(0);
		  Led1_PutVal(0);}
  }


  /* Place your code here */

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
/**********************************************************************************************************************/
// Quando o alarme tocar será aqui que ira gerar a interrupção
/**********************************************************************************************************************/
void RTC_COMMON_IRQHANDLER(void) {
  /* Get status flags */
  uint32_t status_flags = RTC_GetStatusFlags(RTC_PERIPHERAL);
//  RTC_ClearStatusFlags(RTC, kRTC_AlarmInterruptEnable);

  enable = true;
  acordado =~ acordado;
  if(acordado) tela = 1;
  else tela = 0;

  /* Place your interrupt code here */


  /* Clear status flags */
  RTC_ClearStatusFlags(RTC_PERIPHERAL, status_flags);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

/* ADC0_IRQn interrupt handler */
void adcInterrupt(void) {
  /* Array of result values*/
	adc16_channel_config_t adc16ChannelConfigStruct;

	uint32_t status = 0;

	uint32_t result_values[3] = {0};
  /* Get flags for each group */
  for ( int i=0; i<2; i++){
   status = ADC16_GetChannelStatusFlags(ADC0_PERIPHERAL, i);
  	if ( status == kADC16_ChannelConversionDoneFlag){
  		result_values[i] = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL, i);
 	}
  }

  adc16ChannelConfigStruct.channelNumber = 3U; /*PTB0/ADC0_SE8*/
  ADC16_SetChannelConfig( ADC0, 0,&adc16ChannelConfigStruct);
  if(0U == (kADC16_ChannelConversionDoneFlag &
                ADC16_GetChannelStatusFlags(ADC0, 0)))
  {
  }
   interrupt = ADC16_GetChannelConversionValue(ADC0, 0);

   ADC16_ClearStatusFlags(ADC0, status);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}




