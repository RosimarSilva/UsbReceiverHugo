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
extern bool SW3;
extern bool SW2;


/********************************ATENÇÃO ***********************************************
 * OS PROTÓTIPOS DAS FUNÇÕES ESTÃO TUDO EM CONFIG.H
 * BOTÕES SW2 E SW3 ESTÃO SENDO LIDOS POR INTERRUPÇÃO
 * SELETORES DS1, DS2, DS3 E DS2 NÃO ESTÃO SENDO LIDOS POR INTERRUPÇÃO (ROTINAS SE ENCONTRAM CONFIG.C)
 * AS ROTINAS DE LEITURA E ESCRITA DA EEPROM TAMBÉM ESTÃO LÁ EM CONFIG.C
 *****************************************************************************************/
uint8_t dadoSalvo[I2C_DATA_LENGTH], dadoEEpromLido[I2C_DATA_LENGTH];
int main(void) {
uint8_t b = 0;
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    //Inicia todos os perigéricos
      iniciaPerifericos();
      dadoEEpromLido[0]= 1;
      dadoEEpromLido[1]= 2;
      dadoEEpromLido[2]= 3;
      dadoEEpromLido[3]= 4;
      dadoEEpromLido[4]= 5;
      dadoEEpromLido[5]= 6;
      dadoEEpromLido[6]= 7;
      dadoEEpromLido[7]= 8;
      dadoEEpromLido[8]= 9;
      dadoEEpromLido[9]= 10;

     printf("dado %d\n", I2cReadByte(53));
      while(1)
      {
      	if(SW2)
      	{
      		b++;
      		if(b>10) b=0;
      		SW2 = 0;
      		Led1_PutVal(1);
      		Led2_PutVal(1);
      		Led3_PutVal(1);
      		sendBytes(dadoEEpromLido,b);
      		Delay(1000);
      		printf("medida %d\n",medidaAnalogica());
      		Led4_PutVal(1);
      		Led5_PutVal(1);
      		Led6_PutVal(1);
      	}

      	if(SW3)
      	{
      		SW3 = 0;
      		Led1_PutVal(0);
      		Led2_PutVal(0);
      		Led3_PutVal(0);
      		Led4_PutVal(0);
      		Led5_PutVal(0);
      		Led6_PutVal(0);
      	}

      	Delay(500);
      	__asm volatile ("nop");

      }
      return 0 ;
}

