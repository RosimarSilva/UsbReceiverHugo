/*
 * Config.h
 *
 *  Created on: 28 de mai de 2021
 *      Author: Rosimar
 */


#ifndef CONFIGS_H_
#define CONFIGS_H_

#include "fsl_gpio.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL33Z644.h"
#include "fsl_i2c.h"
#include "fsl_lpuart.h"
#include "fsl_uart.h"
#include "fsl_adc16.h"
#include "fsl_rtc.h"

#include "fsl_lptmr.h"
#include "fsl_smc.h"
#include "fsl_llwu.h"
#include "fsl_rcm.h"
#include "clock_mcglite.c"
#include "peripherals.h"
/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o rele  PTB17 */
#define Rele_PutVal(output)  \
FGPIO_PinWrite(GPIOB, 17,output); \
GPIOB->PDDR |= (1U << 17)

/*Esta macro coloca em nivel lógico high ou low o pino
 * do USBON  PTE31*/
#define UsbOn_PutVal(output)  \
FGPIO_PinWrite(GPIOE, 31,output); \
GPIOB->PDDR |= (1U << 31)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED1  PTD1*/
#define Led1_PutVal(output)  \
FGPIO_PinWrite(GPIOD, 1,output); \
GPIOD->PDDR |= (1U << 1U)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED2  PTD0*/
#define Led2_PutVal(output)  \
FGPIO_PinWrite(GPIOD, 0,output); \
GPIOD->PDDR |= (1U << 0U)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED3  PTC7*/
#define Led3_PutVal(output)  \
FGPIO_PinWrite(GPIOC, 7,output); \
GPIOC->PDDR |= (1U << 7U)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED4  PTB16*/
#define Led4_PutVal(output)  \
FGPIO_PinWrite(GPIOB, 16,output); \
GPIOB->PDDR |= (1U << 16U)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED5  PTA13*/
#define Led5_PutVal(output)  \
FGPIO_PinWrite(GPIOA, 13,output); \
GPIOA->PDDR |= (1U << 13U)

/*Esta macro coloca em nivel lógico high ou low o pino
 * que aciona o LED5 PTA4*/
#define Led6_PutVal(output)  \
FGPIO_PinWrite(GPIOA, 4,output); \
GPIOA->PDDR |= (1U << 4U)

/*Esta macro coloca em nivel lógico high ou low o pino de
 *controle de leitura e escrita da EEPROM  PTE29*/
#define WC_control(output)  \
FGPIO_PinWrite(GPIOE, 29,output); \
GPIOE->PDDR |= (1U << 29)


/* Essas são macros referente ao canal I2C1*/
#define I2C_CLOCK_SRC I2C1_CLK_SRC
#define I2C_FREQUENCIA CLOCK_GetFreq(I2C1_CLK_SRC)
#define CANAL_I2C I2C1

#define I2C_ENDERECO 0x50U
#define I2C_BAUDRATE 100000U
#define I2C_DATA_LENGTH 10U


void iniciaPerifericos(void);
void inicializaI2c(void);

//Escreve e faz Leitura de apenas um byte por vez
void I2cWriteByte(uint8_t data, uint8_t deviceAddress);
uint8_t I2cReadByte(uint8_t deviceAddress);

//escreve e faz a Leitura de varios bytes
void I2cWritePageBytes(uint8_t data, uint8_t deviceAddress);
void I2cReadPageBytes(uint8_t deviceAddress);


//Estas são as entradas Rotinas que faram Leitura das entrads DS1,2,3 e 4
bool Ds1_GetVal(void);
bool Ds2_GetVal(void);
bool Ds3_GetVal(void);
bool Ds4_GetVal(void);
bool Sw2_GetVal(void);
bool Sw3_GetVal(void);

//Lê a medida analógica
uint32_t medidaAnalogica(void);

void Delay(int t);
void sendBytes(uint8_t *data, uint8_t size);

void APP_SetClockVlpr(void);// faz o micro entrar em ecomonia de energia
void APP_SetClockRunFromVlpr(void);//faz o micro sair do modo energia

void setRtc(uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute);//configuradia e hora
void getRtc(void); //Lê dia e hora

void derrubaClock(void);
void levantaClock(void);

void analisaBotao(void);
typedef struct _i2cDados_t
{
	uint8_t dadoLido;
	uint8_t dadoSalvo[I2C_DATA_LENGTH];
	uint8_t dadoEEpromLido[I2C_DATA_LENGTH];
}i2cDados_t;

/* Power mode definition used in application. */
typedef enum _app_power_mode
{
    kAPP_PowerModeMin = 'A' - 1,
    kAPP_PowerModeRun,   /* Normal RUN mode */
    kAPP_PowerModeWait,  /* WAIT mode. */
    kAPP_PowerModeStop,  /* STOP mode. */
    kAPP_PowerModeVlpr,  /* VLPR mode. */
    kAPP_PowerModeVlpw,  /* VLPW mode. */
    kAPP_PowerModeVlps,  /* VLPS mode. */
    kAPP_PowerModeLls,   /* LLS mode. */
    kAPP_PowerModeVlls0, /* VLLS0 mode. */
    kAPP_PowerModeVlls1, /* VLLS1 mode. */
    kAPP_PowerModeVlls3, /* VLLS3 mode. */
    kAPP_PowerModeMax
} app_power_mode_t;

typedef enum _app_wakeup_source
{
    kAPP_WakeupSourceLptmr, /*!< Wakeup by LPTMR.        */
    kAPP_WakeupSourcePin    /*!< Wakeup by external pin. */
} app_wakeup_source_t;



#endif /* CONFIG_H_ */
