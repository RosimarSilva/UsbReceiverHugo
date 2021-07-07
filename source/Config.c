/*
 * Config.c
 *
 *  Created on: 28 de mai de 2021
 *      Author: Rosimar
 */
#include "Config.h"

int contTempo,contBotao;

extern uint8_t dadoSalvo[I2C_DATA_LENGTH], dadoEEpromLido[I2C_DATA_LENGTH], usbRec[20];

uint8_t testLed[7];
uint8_t timeAcordado = 1, timeDormindo = 1,setAlarme;
extern uint8_t acordado;
extern uint32_t interrupt;

void iniciaPerifericos(void)
{
	inicializaI2c();
}
/******************************************************************************************************/
//inicia o canal I2C1, onde é feita a comunicação com a EEPROM
/******************************************************************************************************/
void inicializaI2c(void)
{
		i2c_master_config_t masterConfig;
    	uint32_t sourceClock;

       I2C_MasterGetDefaultConfig(&masterConfig);
       masterConfig.baudRate_Bps = I2C_BAUDRATE;

       sourceClock = I2C_FREQUENCIA;

       I2C_MasterInit(CANAL_I2C, &masterConfig, sourceClock);
}
/******************************************************************************************************/
/*Escreve apenas 1 byte na EEPROM
 * onde o primeiro parâmetro é o dado a ser gravado e o segundo parâmetro
 * o endereço da memória na EEPROM
 ******************************************************************************************************/
void I2cWriteByte(uint8_t data, uint8_t deviceAddress)
{

	i2c_master_transfer_t masterXfer;

	 memset(&masterXfer, 0, sizeof(masterXfer));


   masterXfer.slaveAddress = I2C_ENDERECO;
   masterXfer.direction = kI2C_Write;
   masterXfer.subaddress = (uint32_t)deviceAddress;
   masterXfer.subaddressSize = 2U;
   masterXfer.data = &data;
   masterXfer.dataSize = 1U;//I2C_DATA_LENGTH;
   masterXfer.flags = kI2C_TransferDefaultFlag;

   WC_control(0);

   I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);
   for(uint32_t i = 0; i<= 20000;++i)
   {
	   __asm volatile ("nop");
   }
  // Delay(10);
}
/******************************************************************************************************/
/*Faz a leitura apenas de 1 byte na EEPROM,
 * onde o  parâmetro é o endereço da memória na EEPROM
 ********************************************************************************************************/
uint8_t I2cReadByte(uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	 memset(&masterXfer, 0, sizeof(masterXfer));


    masterXfer.slaveAddress = I2C_ENDERECO;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = (uint32_t)deviceAddress;
    masterXfer.subaddressSize = 2U;
    masterXfer.data = &i2c_data.dadoLido;
    masterXfer.dataSize = 1U;//I2C_DATA_LENGTH ;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    WC_control(1);

    I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);

   // Delay(10);

    return i2c_data.dadoLido;;
}
/******************************************************************************************************/
/*Escreve vários bytes na EEPROM
 * onde o primeiro parâmetro são dado a ser gravado que deverão estar armazenados
 * em um vetor e o segundo parâmetro
 * o endereço da memória na EEPROM
 /******************************************************************************************************/
void I2cWritePageBytes(uint8_t data, uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	memset(&masterXfer, 0, sizeof(masterXfer));

   masterXfer.slaveAddress = 0x50;//I2C_ENDERECO;
   masterXfer.direction = kI2C_Write;
   masterXfer.subaddress = (uint32_t)deviceAddress;
   masterXfer.subaddressSize = 2U;
   masterXfer.data = dadoSalvo;
   masterXfer.dataSize = I2C_DATA_LENGTH;//I2C_DATA_LENGTH;
   masterXfer.flags = kI2C_TransferDefaultFlag;

   WC_control(0);

   I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);
   Delay(100);
}
/*********************************************************************************************************/
/*Faz a leitura de varios bytes na EEPROM,
 * onde o  parâmetro é o endereço da memória na EEPROM
 *********************************************************************************************************/
void I2cReadPageBytes(uint8_t deviceAddress)
{
	i2c_master_transfer_t masterXfer;
	i2cDados_t i2c_data;

	 memset(&masterXfer, 0, sizeof(masterXfer));

    masterXfer.slaveAddress =  0x50;//I2C_ENDERECO;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = (uint32_t)deviceAddress;
    masterXfer.subaddressSize = 2U;
    masterXfer.data = dadoEEpromLido;
    masterXfer.dataSize = I2C_DATA_LENGTH;//I2C_DATA_LENGTH ;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    WC_control(1);

    I2C_MasterTransferBlocking(CANAL_I2C, &masterXfer);
    Delay(100);
}
/******************************************************************************************************/
//Estas são as entradas Rotinas que farão Leitura das entrads DS1,2,3 e 4
/******************************************************************************************************/
bool Ds1_GetVal(void){return  (GPIO_PinRead(GPIOC, 1U));}
bool Ds2_GetVal(void){ return (GPIO_PinRead(GPIOC, 0U));}
bool Ds3_GetVal(void){ return (GPIO_PinRead(GPIOB, 19U));}
bool Ds4_GetVal(void){ return (GPIO_PinRead(GPIOB, 18U));}
bool Sw2_GetVal(void){return (GPIO_PinRead(GPIOC, 3U));}
bool Sw3_GetVal(void){return (GPIO_PinRead(GPIOC, 2U));}
extern bool SW3,SW2;
void analisaBotao(void)
{
	if( !Sw2_GetVal())
	{
		Delay(200);
		contBotao = 300;
		while(!Sw2_GetVal())
		{
			SW2 = 1;
		}
	}
	else if(!Sw3_GetVal())
	{
		Delay(200);
		contBotao = 300;
		while(!Sw3_GetVal())
		{
			SW3 = 1;
		}
	}
}
/******************************************************************************************************/
//Faz a leitura da medida analógica
/******************************************************************************************************/
uint32_t medidaAnalogica(uint8_t canal)
{
	adc16_channel_config_t adc16ChannelConfigStruct;

	adc16ChannelConfigStruct.channelNumber = canal; /*PTB0/ADC0_SE8*/
	adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;
    ADC16_SetChannelConfig( ADC0, 0,&adc16ChannelConfigStruct);
    while (0U == (kADC16_ChannelConversionDoneFlag &
                  ADC16_GetChannelStatusFlags(ADC0, 0)))
    {
    }
    return ADC16_GetChannelConversionValue(ADC0, 0);
}
/******************************************************************************************************/
//Faz a contagem de tempo em milissegundos
/******************************************************************************************************/
void Delay(int t)
{
	contTempo = t;
	while(contTempo > 0)
	{
		__asm volatile ("nop");
	}
}
/******************************************************************************************************/
//Esta rotina envia um vetor inteiro de dados onde o primeiro parâmetro é o vetor carregadocom os dados
// e o segundo parmetro é o comprimeto do vetor
/******************************************************************************************************/
void sendBytes(uint8_t *data, uint8_t size)
{
	 LPUART_WriteBlocking(LPUART0, data, size);
}
/******************************************************************************************************/
//Esta rotina faz o micro voltar ao clock inicial ou seja ao modo RUN 48MHz
/******************************************************************************************************/
void levantaClock(void)
{
	uint32_t freq;
    /* Power mode change. */
    SMC_SetPowerModeRun(SMC);
    while (kSMC_PowerStateRun != SMC_GetPowerModeState(SMC))
    {
    }
    APP_SetClockRunFromVlpr();
 //   freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);

  //  if(freq == 48000000)
  //  {
    //    Led3_PutVal(1);
   //     Led6_PutVal(0);
  //  }
}
/***************************************************************************************************************/
void APP_SetClockRunFromVlpr(void)
{
    const mcglite_config_t mcgliteConfig = {.outSrc                  = kMCGLITE_ClkSrcLirc,
                                            .irclkEnableMode         = 0U,
                                            .ircs                    = kMCGLITE_Lirc2M,
                                            .fcrdiv                  = kMCGLITE_LircDivBy1,
                                            .lircDiv2                = kMCGLITE_LircDivBy1,
                                            .hircEnableInNotHircMode = true};

    const sim_clock_config_t simConfig = {
        .clkdiv1 = 0x00010000U, /* SIM_CLKDIV1. */
#if (defined(FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION) && FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION)
        .er32kSrc = 0U, /* SIM_SOPT1[OSC32KSEL]. */
#endif
    };

    CLOCK_SetSimSafeDivs();
    CLOCK_SetMcgliteConfig(&mcgliteConfig);
    CLOCK_SetSimConfig(&simConfig);

}

/******************************************************************************************************/
//Esta rotina derruba o clock do micro fazendo fazendo o micro entrar em modo de economia
/******************************************************************************************************/
void derrubaClock(void)
{
	uint32_t freq;

	  freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
	  APP_SetClockVlpr();
   SMC_SetPowerModeVlpr(SMC);
    while (kSMC_PowerStateVlpr != SMC_GetPowerModeState(SMC))
    {
    }
    freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);

    if(freq <= 31250)
    {
  	  Led3_PutVal(0);
  	  Led6_PutVal(1);
    }
}
/********************************************************************************************************/
void APP_SetClockVlpr(void)
{
    const mcglite_config_t mcgliteConfig = {
        .outSrc                  = kMCGLITE_ClkSrcLirc,
        .irclkEnableMode         = kMCGLITE_IrclkEnable,
        .ircs                    = kMCGLITE_Lirc2M,
        .fcrdiv                  = kMCGLITE_LircDivBy64,
        .lircDiv2                = kMCGLITE_LircDivBy128,
        .hircEnableInNotHircMode = false,
    };

    const sim_clock_config_t simConfig = {
        .clkdiv1 = 0x00010000U, /* SIM_CLKDIV1. */
#if (defined(FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION) && FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION)
        .er32kSrc = 0U, /* SIM_SOPT1[OSC32KSEL]. */
#endif
    };

    CLOCK_SetSimSafeDivs();
    CLOCK_SetMcgliteConfig(&mcgliteConfig);
    CLOCK_SetSimConfig(&simConfig);
}
/******************************************************************************************************/
//Esta rotina  configura a data e hora
/******************************************************************************************************/
void setRtc(uint8_t day,uint8_t month,uint16_t year,uint8_t hour,uint8_t minute)
{

    rtc_datetime_t date;
    rtc_osc_cap_load_t cap;

    /* Set a start date time and start RT */
	    date.year   = year;
	    date.month  = month;
	    date.day    = day;
	    date.hour   = hour;
	    date.minute = minute;
	    date.second = 0;

	    /* RTC time counter has to be stopped before setting the date & time in the TSR register */
	    RTC_StopTimer(RTC);

	    /* Set RTC time to default */
	    RTC_SetDatetime(RTC, &date);

	    /* Start the RTC time counter */
	    RTC_StartTimer(RTC);


}
/******************************************************************************************************/
//Esta rotina lê data e hora
/******************************************************************************************************/
void getRtc(void)
{
	 rtc_datetime_t date;
	 uint8_t usbSend[10];
	   RTC_GetDatetime(RTC, &date);

	   date.year = date.year - 2000;
	   usbSend[0] = 0x54;
	   usbSend[1] = 0x25;
	   usbSend[2] = 0x9;
	   usbSend[3] = 0x06;
	   usbSend[4] = date.day;
	   usbSend[5] = date.month;
	   usbSend[6] = date.year;
	   usbSend[7] = date.hour;
	   usbSend[8] = date.minute;

	  // sendBytes(&usbSend,9);
	   LPUART_WriteBlocking(LPUART0, usbSend, 9); // envia pela USB a data e hora

    //  printf("informnado a hora certa: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day,
         //   date.hour, date.minute, date.second);
}
/******************************************************************************************************/
//Esta rotina seta um alarme o alrme será tocado la na interrupções.c
/******************************************************************************************************/
void setAlarm(bool state)
{
	 rtc_datetime_t date;
	 uint8_t mMes;

	 RTC_GetDatetime(RTC, &date);
	 Delay(50);

	 // date.second  += 30;
	 // Quando está acordado verifica eta hora
	  if(state)
	  {
		  date.second  = 0;
		  date.minute += timeAcordado;
		  if(date.minute > 59)
		  {
			  date.minute = 0;
			  date.hour ++;
			  if(date.hour > 23)
			  {
				  date.hour = 0;
				  date.day ++;
				  mMes = date.month % 2;//verifica se o mês tem 31 ou 30 dias
				  if((mMes)||(date.month == 7)&&(date.month != 2))// aqui o mes tem 31 dias
				  {
					  if(date.day > 31)
					  {
						  date.day = 1;
						  date.month ++;
						  if(date.month > 12){
							  date.month = 1;
							  date.year ++;
						  }
					  }
				  }
				  else if((!mMes)&&(date.month != 7)&&(date.month != 2))//não tem 31 dias
				  {
					  if(date.day > 30)
					  {
						  date.day = 1;
						  date.month ++;
						  if(date.month > 12){
							  date.month = 1;
							  date.year ++;
						  }
					  }

				  }

				  else if(date.month == 2)// verifica se o ano nõa é bisexto
				  {
					  mMes = date.year % 4;// se for divisível por 4 é o ano bisexto

					  if(!mMes)
					  {

						  if(date.day > 29)//bisexto
						  {
							  date.day = 1;
							  date.month ++;

						  }
					  }
					  else
					  {
						  if(date.day > 28)//não é bisexto
						  {
							  date.day = 1;
							  date.month ++;
						  }
					  }
				  }

			  }
		  }
	  }
	  else
	  {
		  date.second  = 0;
		  date.minute += timeDormindo;
		  if(date.minute > 59)
		  {
			  date.minute = 0;
			  date.hour ++;
			  if(date.hour > 23)
			  {
				  date.hour = 0;
				  date.day ++;
				  mMes = date.month % 2; //se for divisivel por 2 o mes não tem  31 dias
				  if((mMes)||(date.month == 7)&&(date.month != 2))// verifica se o aano vai até 31 ou 30
				  {
					  if(date.day > 31)
					  {
						  date.day = 1;
						  date.month ++;
						  if(date.month > 12)
						  {
							  date.month = 1;
							  date.year ++;
						  }
					  }
				  }
			  }
		  }
		  else if((!mMes)&&(date.month != 7)&&(date.month != 2))// aqui o mês não tem 31 dias
		  {
			  if(date.day > 30)
			  {
				  date.day = 1;
				  date.month ++;
				  if(date.month > 12){
					  date.month = 1;
					  date.year ++;
				  }
			  }

		  }
		  else if(date.month == 2)// aqui está no mes de fevereiro
		  {
			  mMes = date.year % 4;//verifica se o ano é bisexto

			  if(mMes)//é bisexto
			  {

				  if(date.day > 29)
				  {
					  date.day = 1;
					  date.month ++;

				  }
			  }
			  else
			  {
				  if(date.day > 28)// não é bisexto
				  {
					  date.day = 1;
					  date.month ++;
				  }
			  }
		  }
	  }
	 RTC_SetAlarm(RTC, &date); // seta no micro o alarme

		Delay(50);
		  RTC_GetAlarm(RTC, &date);

		  printf("O alarme sera as: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day,
		           date.hour, date.minute, date.second);
}
/********************************************************************************************************
 * Recebe do pc o comando por interrupção para fazer alguma função
 ********************************************************************************************************/
void comandoUsb(uint8_t comando)
{
	uint16_t x;
	rtc_datetime_t date;
	switch(comando)
	{
		case 0://liga ou desliga o led 1
		{
			testLed[comando] =~ testLed[comando];
			 Led1_PutVal(testLed[comando]);
		}break;
		case 1://liga ou desliga o led 2
		{
			testLed[comando] =~ testLed[comando];
			 Led2_PutVal(testLed[comando]);
		}break;
		case 2://liga ou desliga o led 3
		{
			testLed[comando] =~ testLed[comando];
			 Led3_PutVal(testLed[comando]);
		}break;
		case 3://liga ou desliga o led 4
		{
			testLed[comando] =~ testLed[comando];
			 Led4_PutVal(testLed[comando]);
		}break;

		case 4://liga ou desliga o led 5
		{
			testLed[comando] =~ testLed[comando];
			 Led5_PutVal(testLed[comando]);
		}break;
		case 5://liga ou desliga o led 6
		{
			testLed[comando] =~ testLed[comando];
			 Led6_PutVal(testLed[comando]);
		}break;

		case 6://pega a hora configurada pelo PC
		{
			if(acordado)
			{
				x = usbRec[6] + 2000;
				setRtc(usbRec[4],usbRec[5],x,usbRec[7],usbRec[8]);
				getRtc();
			}
		}break;

		case 7://define o tempo de acordado e espera
		{
			timeAcordado = usbRec[4];
			timeDormindo = usbRec[5];
			setAlarme = 1;
		}break;

		case 8:// liga ou desliga o pino para medida de tensão
		{
			if(acordado)
			{
				testLed[comando] =~ testLed[comando];
				Tensao1_PutVal(testLed[comando]);
			}
		}break;

		case 9:// liga ou desliga o pino para medida de tensão
		{
			if(acordado)
			{
				testLed[comando] =~ testLed[comando];
				Tensao2_PutVal(testLed[comando]);
			}
		}break;

		default: break;
	}
}
/*********************************************************************************************
 * // envia para o programa se o sistema está dormindo ou acordao
 *********************************************************************************************/
void sinalFunc(bool enanble)
{
	uint8_t usbSend[10];
	   usbSend[0] = 0x54;
	   usbSend[1] = 0x25;
	   usbSend[2] = 0x5;
	   usbSend[3] = 0x03;
	   usbSend[4] = enanble;
	   Delay(135);
	   LPUART_WriteBlocking(LPUART0, usbSend, 5);
}
/*********************************************************************************************
 * // envia para o programa do pc medidas analogicas
 *********************************************************************************************/
void sendDiferential(void)
{
	uint8_t usbSend[15];
	uint8_t aux, aux1;
	int med;

	   usbSend[0] = 0x54;
	   usbSend[1] = 0x25;
	   usbSend[2] = 0x0C;
	   usbSend[3] = 0x04;

	   aux = interrupt/256;
	   aux1 = interrupt%256;
	   usbSend[4] = aux;
	   usbSend[5] = aux1;

	   med =  medidaAnalogica(9);
	   aux = med/256;
	   aux1 = med%256;
	   usbSend[6] = aux;
	   usbSend[7] = aux1;

	   med =  medidaAnalogica(12);
	   aux = med/256;
	   aux1 = med%256;
	   usbSend[8] = aux;
	   usbSend[9] = aux1;

	   med =  medidaAnalogica(13);
	   aux = med/256;
	   aux1 = med%256;
	   usbSend[10] = aux;
	   usbSend[11] = aux1;


	   Delay(135);

	   LPUART_WriteBlocking(LPUART0, usbSend, 12);
}

