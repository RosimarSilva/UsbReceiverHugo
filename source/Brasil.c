/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    Brasil.c
 * @brief   Application entry point.
 */
/* TODO: insert other include files here. */
#include "Config.h"



/*******************************************************************************
 * Variables
 ******************************************************************************/
//extern bool SW3;
//extern bool SW2;


/********************************ATENÇÃO ***********************************************
 * OS PROTÓTIPOS DAS FUNÇÕES ESTÃO TUDO EM CONFIG.H
 * BOTÕES SW2 E SW3 ESTÃO SENDO LIDOS POR INTERRUPÇÃO
 * SELETORES DS1, DS2, DS3 E DS2 NÃO ESTÃO SENDO LIDOS POR INTERRUPÇÃO (ROTINAS SE ENCONTRAM CONFIG.C)
 * AS ROTINAS DE LEITURA E ESCRITA DA EEPROM TAMBÉM ESTÃO LÁ EM CONFIG.C
 *****************************************************************************************/
uint8_t dadoSalvo[I2C_DATA_LENGTH], dadoEEpromLido[I2C_DATA_LENGTH];

#include "fsl_pmc.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*!
 * @brief main demo function.
 */

bool piscaLed;
bool enable = false,enableMed = false;
uint8_t  cont;
uint8_t acordado = 255,tela;

extern uint8_t setAlarme;
extern uint32_t interrupt;
int contMed,contHora;
extern int ContPiscaLed,contMedida;
extern uint8_t timeAcordado, timeDormindo;

int main(void) {
	lptmr_config_t lptmrConfig;
    /* Init board hardware. */
    BOARD_InitBootPins();

    /* Power related. */
    SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll);
    if (kRCM_SourceWakeup & RCM_GetPreviousResetSources(RCM)) /* Wakeup from VLLS. */
    {
        PMC_ClearPeriphIOIsolationFlag(PMC);
        NVIC_ClearPendingIRQ(LLWU_IRQn);
    }
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

      LPTMR_GetDefaultConfig(&lptmrConfig);
      lptmrConfig.prescalerClockSource = kLPTMR_PrescalerClock_1; /* Use LPO as clock source. */
      lptmrConfig.bypassPrescaler      = true;


      if (kRCM_SourceWakeup & RCM_GetPreviousResetSources(RCM)) /* Wakeup from VLLS. */
      {
         // PRINTF("\r\nMCU wakeup from VLLS modes...\r\n");
      }


      inicializaI2c();

      timeDormindo = I2cReadByte(0x01);
      if(timeDormindo <= 1)timeDormindo = 1;
      timeAcordado = I2cReadByte(0x00);
      if(timeAcordado <= 1)timeAcordado = 1;


   setRtc(28,06,2021,20,40);//configuradia e hora
      Delay(200);

      getRtc();


      enableMed = 1;
      contMed = 100;
      contHora = 10000;
      tela = 1;
      while (1)
      {
    	  __asm volatile ("nop");

    	  screen();

      }


      return 0 ;
}

void screen(void)
{
	switch(tela)
	{
		case 0: tela0();break;
		case 1: tela1();break;
		default: tela = 1;break;
	}
}

void tela0(void)
{
	 sinalFunc(0);

	setAlarm(0);
	Led1_PutVal(1);
	Led6_PutVal(0);

	 derrubaClock();
	while(tela == 0)
	{

	}
}
void tela1(void)
{
	rtc_datetime_t date;

	 levantaClock();
	 Delay(300);
	 sinalFunc(1);
	setAlarm(1);
	Led1_PutVal(0);
	Led6_PutVal(1);
	 getRtc();
	  Delay(200);
	while(tela == 1)
	{
	   	 if(!contHora)//a cada minuto envia horae data
	    	 {
	    		 contHora = 60000;
	    		 getRtc();
	    		  Delay(200);
	    		 getRtc();
	    		  Delay(200);
	    		  getRtc();
	    		  Delay(200);
	    		  getRtc();
	    	 }

	    	 if(setAlarme) // quando chegar uma configuração de alarme pela USB
	    	 {
	 			setAlarme =0;
	 			I2cWriteByte(timeAcordado, 0x00);
	 			Delay(10);
	 			I2cWriteByte(timeDormindo, 0x01);
	 			Delay(10);
	 			setAlarm(1);
	 			Delay(50);
	 			RTC_GetAlarm(RTC, &date);

	 			 piscaLed = true;
	 				  Led1_PutVal(1);
	 				  Led2_PutVal(1);
	 				  Led3_PutVal(1);
	 				  Led4_PutVal(1);
	 				  Led5_PutVal(1);
	 				 ContPiscaLed = 3000;

	    	 }

	    	 if(!contMedida)//envia para a Usb as medidas do sensores
	    	 {
	    		 contMedida = 1500;
	    		 sendDiferential();
	    		 printf("med%d\n",interrupt);
	    	 }
	}
}


/*
 *     		  contMed = 5000;
    		//  dif1 = medidaAnalogica(0x3);
    		  for(int i = 0;i<200;++i)
    		  {

    			  a = dif2 + a;
    			  an1 = medidaAnalogica(9);Delay(5);
    			  b = an1 + b;
    			  an2 = medidaAnalogica(12);Delay(50);
    			  c= an2+c;
    			  an3 = medidaAnalogica(13);Delay(5);
    			  d=an3+c;
    		  }

    		  dif2 = (a/200);
    		  an1 = b/200;
    		  an2 = c/200;
    		  an3 = d/200;
    		  aux = dif1/256;
    		  aux1  = dif1%256;

    		  ana.sens1 = 0x24;
    		  ana.sens11 = 0x25;

    		  aux = 0;
    		  aux1 = 0;

    		  aux = dif2/256;
    		  aux1  = dif2%256;
    		  ana.sens2 = aux;
    		  ana.sens22 = aux1;

    		  aux2 = 0;
    		  aux22 = 0;

    		  aux2 = an1/256;
    		  aux22  = an1%256;
    		  ana.analog1 = aux2;
    		  ana.analog11 = aux22;

    		  aux3 = 0;
    		  aux33 = 0;

    		  aux3 = an2/256;
    		  aux33  = an2%256;
    		  ana.analog2 = aux3;
    		  ana.analog22 = aux33;

    		  aux4 = 0;
    		  aux44 = 0;

    		  aux4 = an3/256;
    		  aux44  = an3%256;
    		  ana.analog3 = aux4;
    		  ana.analog33 = aux44;
 */
