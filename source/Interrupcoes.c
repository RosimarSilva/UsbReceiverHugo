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

extern int contTempo;


uint8_t pont, usbRec[6];
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
    	if(pont >= 6)
    	{
    		pont =0;
    		for(uint8_t i = 0; i<= 5;++i)
    		{
    			usbRec[i] = 0;
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
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = TPM_GetStatusFlags(TPM0_PERIPHERAL);
  TPM_ClearStatusFlags(TPM0_PERIPHERAL, intStatus);


  if(contTempo)
  {
	  contTempo --;
	  if(contTempo <= 0) contTempo  = 0;
  }

  /* Place your code here */

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}




