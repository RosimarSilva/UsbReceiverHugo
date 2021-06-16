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
bool enable = false;
uint8_t  cont;
int main(void) {

uint32_t freq = 0;
lptmr_config_t lptmrConfig;
rtc_datetime_t date;

uint8_t chama,chupa,putao;
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


      setRtc(2021,06,01,11,18);//configuradia e hora

	    date.year   = 2021;
	    date.month  = 6;
	    date.day    = 1;
	    date.hour   = 11;
	    date.minute = 18;
	    date.second = 5;

	   RTC_SetAlarm(RTC, &date);

      RTC_GetAlarm(RTC, &date);

      /* Print alarm time */
    //  printf("Alarm will occur at: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day,
      //       date.hour, date.minute, date.second);
      while (1)
      {
    	  if(enable == true)
    	  {


    		 enable = false;

    	   date.year   = 2021;
    	   date.month  = 6;
    	    date.day    = 1;
    	    date.hour   = 11;


    	    date.second  += 59;
    	    if(date.second >= 59)
    	    {
    	  	  date.second  = 0;
    	  	  date.minute ++;
    	  	  if(date.minute > 59) date.minute = 0;
    	    }

    	   RTC_SetAlarm(RTC, &date);

    	  RTC_GetAlarm(RTC, &date);
       //  printf("Alarm will occur at: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day,
         //      date.hour, date.minute, date.second);
         putao =~ putao;
         if(putao) chupa = 1;
         else chama = 1;

         if(chupa == 1)
         {
        	 chupa = 0;
        	 levantaClock();
        	 // LPUART_Init(LPUART0_PERIPHERAL, &LPUART0_config, LPUART0_CLOCK_SOURCE);
        	 cont = I2cReadByte(0x12);

         	printf("%d\n", cont );
         	 Delay(5);
         	 I2cWriteByte(0x24, 0x12);
         	 Delay(5);
        	 cont = I2cReadByte(0x12);
        	 Delay(5);
        	 printf("%d\n", cont );


        	  Led3_PutVal(1);
        	  Led6_PutVal(0);


       		  freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
       		  printf("frequ %d ", freq);

       		getRtc();
       		Delay(500);
         }
         else
         {
        	 chupa = 0;
        	 derrubaClock();

      		  freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
      		  printf("frequ %d ", freq);

        	// Delay(10);
             Led3_PutVal(0);
             Led6_PutVal(1);
         }


      }
      }
      return 0 ;
}


/* RTC_IRQn interrupt handler */

void RTC_COMMON_IRQHANDLER(void) {
  /* Get status flags */
  uint32_t status_flags = RTC_GetStatusFlags(RTC_PERIPHERAL);
//  RTC_ClearStatusFlags(RTC, kRTC_AlarmInterruptEnable);

enable = true;

  /* Place your interrupt code here */


  /* Clear status flags */
  RTC_ClearStatusFlags(RTC_PERIPHERAL, status_flags);

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

