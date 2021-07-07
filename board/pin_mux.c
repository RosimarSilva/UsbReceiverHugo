/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MKL33Z64xxx4
package_id: MKL33Z64VLH4
mcu_data: ksdk2_0
processor_version: 9.0.0
pin_labels:
- {pin_num: '17', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, label: Wc, identifier: Wc}
- {pin_num: '64', pin_signal: LCD_P47/PTD7/SPI1_MISO/LPUART0_TX/I2C1_SCL/SPI1_MOSI/FXIO0_D7, label: Tx_usb, identifier: Tx_Usb}
- {pin_num: '63', pin_signal: LCD_P46/ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/LPUART0_RX/I2C1_SDA/SPI1_MISO/FXIO0_D6, label: Rx_usb, identifier: Rx_usb}
- {pin_num: '1', pin_signal: LCD_P48/PTE0/CLKOUT32K/SPI1_MISO/LPUART1_TX/RTC_CLKOUT/CMP0_OUT/I2C1_SDA, label: Sda, identifier: Sda}
- {pin_num: '2', pin_signal: LCD_P49/PTE1/SPI1_MOSI/LPUART1_RX/SPI1_MISO/I2C1_SCL, label: Scl, identifier: Scl}
- {pin_num: '19', pin_signal: PTE31/TPM0_CH4, label: Usb_on, identifier: Usb_on}
- {pin_num: '35', pin_signal: LCD_P0/ADC0_SE8/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0/SPI1_MOSI/SPI1_MISO, label: Analog2, identifier: Analog;Analog2}
- {pin_num: '40', pin_signal: LCD_P13/PTB17/SPI1_MISO/LPUART0_TX/TPM_CLKIN1/SPI1_MOSI, label: Rele, identifier: Rele}
- {pin_num: '58', pin_signal: LCD_P41/ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1/FXIO0_D1, label: Led1, identifier: Led1}
- {pin_num: '57', pin_signal: LCD_P40/PTD0/SPI0_PCS0/TPM0_CH0/FXIO0_D0, label: Led2, identifier: Led2}
- {pin_num: '56', pin_signal: LCD_P27/CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, label: Led3, identifier: Led3}
- {pin_num: '39', pin_signal: LCD_P12/PTB16/SPI1_MOSI/LPUART0_RX/TPM_CLKIN0/SPI1_MISO, label: Led4, identifier: Led4}
- {pin_num: '29', pin_signal: PTA13/TPM1_CH1, label: Led5, identifier: Led5}
- {pin_num: '26', pin_signal: PTA4/I2C1_SDA/TPM0_CH1/NMI_b, label: Led6, identifier: Led6}
- {pin_num: '45', pin_signal: LCD_P22/ADC0_SE11/PTC2/I2C1_SDA/TPM0_CH1, label: Sw3, identifier: Sw3}
- {pin_num: '46', pin_signal: LCD_P23/PTC3/LLWU_P7/SPI1_SCK/LPUART1_RX/TPM0_CH2/CLKOUT, label: Sw2, identifier: Sw2}
- {pin_num: '44', pin_signal: LCD_P21/ADC0_SE15/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0, label: Ds1, identifier: Ds1}
- {pin_num: '43', pin_signal: LCD_P20/ADC0_SE14/PTC0/EXTRG_IN/CMP0_OUT, label: Ds2, identifier: Ds2}
- {pin_num: '42', pin_signal: LCD_P15/PTB19/TPM2_CH1, label: Ds3, identifier: Ds3}
- {pin_num: '41', pin_signal: LCD_P14/PTB18/TPM2_CH0, label: Ds4, identifier: Ds4}
- {pin_num: '11', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX/FXIO0_D6, label: Analog1Dif1, identifier: Analog1Dif1}
- {pin_num: '12', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX/FXIO0_D7, label: Analog1Dif2, identifier: Analog1Dif2}
- {pin_num: '36', pin_signal: LCD_P1/ADC0_SE9/PTB1/I2C0_SDA/TPM1_CH1/SPI1_MISO/SPI1_MOSI, label: Analog3, identifier: Analog3}
- {pin_num: '37', pin_signal: LCD_P2/ADC0_SE12/PTB2/I2C0_SCL/TPM2_CH0, label: Analog4, identifier: Analog4}
- {pin_num: '38', pin_signal: LCD_P3/ADC0_SE13/PTB3/I2C0_SDA/TPM2_CH1, label: analog5, identifier: Analog5}
- {pin_num: '53', pin_signal: LCD_P24/PTC4/LLWU_P8/SPI0_PCS0/LPUART1_TX/TPM0_CH3/SPI1_PCS0, label: PinoTensao1, identifier: PinoTensao1}
- {pin_num: '54', pin_signal: LCD_P25/PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, label: PinoTensao2, identifier: PinoTensao2}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '64', peripheral: LPUART0, signal: TX, pin_signal: LCD_P47/PTD7/SPI1_MISO/LPUART0_TX/I2C1_SCL/SPI1_MOSI/FXIO0_D7, direction: INPUT/OUTPUT, slew_rate: slow,
    pull_select: up, pull_enable: disable}
  - {pin_num: '63', peripheral: LPUART0, signal: RX, pin_signal: LCD_P46/ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/LPUART0_RX/I2C1_SDA/SPI1_MISO/FXIO0_D6, slew_rate: slow,
    pull_select: up, pull_enable: disable}
  - {pin_num: '1', peripheral: I2C1, signal: SDA, pin_signal: LCD_P48/PTE0/CLKOUT32K/SPI1_MISO/LPUART1_TX/RTC_CLKOUT/CMP0_OUT/I2C1_SDA, pull_enable: enable}
  - {pin_num: '2', peripheral: I2C1, signal: SCL, pin_signal: LCD_P49/PTE1/SPI1_MOSI/LPUART1_RX/SPI1_MISO/I2C1_SCL, pull_enable: enable}
  - {pin_num: '17', peripheral: GPIOE, signal: 'GPIO, 29', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, direction: OUTPUT, gpio_init_state: 'false',
    pull_enable: enable}
  - {pin_num: '19', peripheral: GPIOE, signal: 'GPIO, 31', pin_signal: PTE31/TPM0_CH4, direction: OUTPUT}
  - {pin_num: '35', peripheral: ADC0, signal: 'SE, 8', pin_signal: LCD_P0/ADC0_SE8/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0/SPI1_MOSI/SPI1_MISO, identifier: Analog2}
  - {pin_num: '40', peripheral: GPIOB, signal: 'GPIO, 17', pin_signal: LCD_P13/PTB17/SPI1_MISO/LPUART0_TX/TPM_CLKIN1/SPI1_MOSI, direction: OUTPUT}
  - {pin_num: '58', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: LCD_P41/ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1/FXIO0_D1, direction: OUTPUT}
  - {pin_num: '57', peripheral: GPIOD, signal: 'GPIO, 0', pin_signal: LCD_P40/PTD0/SPI0_PCS0/TPM0_CH0/FXIO0_D0, direction: OUTPUT}
  - {pin_num: '56', peripheral: GPIOC, signal: 'GPIO, 7', pin_signal: LCD_P27/CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, direction: OUTPUT}
  - {pin_num: '39', peripheral: GPIOB, signal: 'GPIO, 16', pin_signal: LCD_P12/PTB16/SPI1_MOSI/LPUART0_RX/TPM_CLKIN0/SPI1_MISO, direction: OUTPUT}
  - {pin_num: '29', peripheral: GPIOA, signal: 'GPIO, 13', pin_signal: PTA13/TPM1_CH1, direction: OUTPUT}
  - {pin_num: '26', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: PTA4/I2C1_SDA/TPM0_CH1/NMI_b, direction: OUTPUT}
  - {pin_num: '45', peripheral: GPIOC, signal: 'GPIO, 2', pin_signal: LCD_P22/ADC0_SE11/PTC2/I2C1_SDA/TPM0_CH1, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge}
  - {pin_num: '46', peripheral: GPIOC, signal: 'GPIO, 3', pin_signal: LCD_P23/PTC3/LLWU_P7/SPI1_SCK/LPUART1_RX/TPM0_CH2/CLKOUT, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge}
  - {pin_num: '44', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: LCD_P21/ADC0_SE15/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0, direction: INPUT, gpio_interrupt: no_init}
  - {pin_num: '43', peripheral: GPIOC, signal: 'GPIO, 0', pin_signal: LCD_P20/ADC0_SE14/PTC0/EXTRG_IN/CMP0_OUT, direction: INPUT, gpio_interrupt: no_init}
  - {pin_num: '42', peripheral: GPIOB, signal: 'GPIO, 19', pin_signal: LCD_P15/PTB19/TPM2_CH1, direction: INPUT, gpio_interrupt: no_init}
  - {pin_num: '41', peripheral: GPIOB, signal: 'GPIO, 18', pin_signal: LCD_P14/PTB18/TPM2_CH0, direction: INPUT, gpio_interrupt: no_init}
  - {pin_num: '11', peripheral: ADC0, signal: 'DP, 3', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX/FXIO0_D6}
  - {pin_num: '12', peripheral: ADC0, signal: 'DM, 3', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX/FXIO0_D7}
  - {pin_num: '36', peripheral: ADC0, signal: 'SE, 9', pin_signal: LCD_P1/ADC0_SE9/PTB1/I2C0_SDA/TPM1_CH1/SPI1_MISO/SPI1_MOSI}
  - {pin_num: '37', peripheral: ADC0, signal: 'SE, 12', pin_signal: LCD_P2/ADC0_SE12/PTB2/I2C0_SCL/TPM2_CH0}
  - {pin_num: '38', peripheral: ADC0, signal: 'SE, 13', pin_signal: LCD_P3/ADC0_SE13/PTB3/I2C0_SDA/TPM2_CH1}
  - {pin_num: '53', peripheral: GPIOC, signal: 'GPIO, 4', pin_signal: LCD_P24/PTC4/LLWU_P8/SPI0_PCS0/LPUART1_TX/TPM0_CH3/SPI1_PCS0, direction: OUTPUT}
  - {pin_num: '54', peripheral: GPIOC, signal: 'GPIO, 5', pin_signal: LCD_P25/PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t Led6_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA4 (pin 26)  */
    GPIO_PinInit(BOARD_INITPINS_Led6_GPIO, BOARD_INITPINS_Led6_PIN, &Led6_config);

    gpio_pin_config_t Led5_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA13 (pin 29)  */
    GPIO_PinInit(BOARD_INITPINS_Led5_GPIO, BOARD_INITPINS_Led5_PIN, &Led5_config);

    gpio_pin_config_t Led4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB16 (pin 39)  */
    GPIO_PinInit(BOARD_INITPINS_Led4_GPIO, BOARD_INITPINS_Led4_PIN, &Led4_config);

    gpio_pin_config_t Rele_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB17 (pin 40)  */
    GPIO_PinInit(BOARD_INITPINS_Rele_GPIO, BOARD_INITPINS_Rele_PIN, &Rele_config);

    gpio_pin_config_t Ds4_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB18 (pin 41)  */
    GPIO_PinInit(BOARD_INITPINS_Ds4_GPIO, BOARD_INITPINS_Ds4_PIN, &Ds4_config);

    gpio_pin_config_t Ds3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB19 (pin 42)  */
    GPIO_PinInit(BOARD_INITPINS_Ds3_GPIO, BOARD_INITPINS_Ds3_PIN, &Ds3_config);

    gpio_pin_config_t Ds2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC0 (pin 43)  */
    GPIO_PinInit(BOARD_INITPINS_Ds2_GPIO, BOARD_INITPINS_Ds2_PIN, &Ds2_config);

    gpio_pin_config_t Ds1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC1 (pin 44)  */
    GPIO_PinInit(BOARD_INITPINS_Ds1_GPIO, BOARD_INITPINS_Ds1_PIN, &Ds1_config);

    gpio_pin_config_t Sw3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC2 (pin 45)  */
    GPIO_PinInit(BOARD_INITPINS_Sw3_GPIO, BOARD_INITPINS_Sw3_PIN, &Sw3_config);

    gpio_pin_config_t Sw2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC3 (pin 46)  */
    GPIO_PinInit(BOARD_INITPINS_Sw2_GPIO, BOARD_INITPINS_Sw2_PIN, &Sw2_config);

    gpio_pin_config_t PinoTensao1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC4 (pin 53)  */
    GPIO_PinInit(BOARD_INITPINS_PinoTensao1_GPIO, BOARD_INITPINS_PinoTensao1_PIN, &PinoTensao1_config);

    gpio_pin_config_t PinoTensao2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC5 (pin 54)  */
    GPIO_PinInit(BOARD_INITPINS_PinoTensao2_GPIO, BOARD_INITPINS_PinoTensao2_PIN, &PinoTensao2_config);

    gpio_pin_config_t Led3_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC7 (pin 56)  */
    GPIO_PinInit(BOARD_INITPINS_Led3_GPIO, BOARD_INITPINS_Led3_PIN, &Led3_config);

    gpio_pin_config_t Led2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD0 (pin 57)  */
    GPIO_PinInit(BOARD_INITPINS_Led2_GPIO, BOARD_INITPINS_Led2_PIN, &Led2_config);

    gpio_pin_config_t Led1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD1 (pin 58)  */
    GPIO_PinInit(BOARD_INITPINS_Led1_GPIO, BOARD_INITPINS_Led1_PIN, &Led1_config);

    gpio_pin_config_t Wc_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE29 (pin 17)  */
    GPIO_PinInit(BOARD_INITPINS_Wc_GPIO, BOARD_INITPINS_Wc_PIN, &Wc_config);

    gpio_pin_config_t Usb_on_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE31 (pin 19)  */
    GPIO_PinInit(BOARD_INITPINS_Usb_on_GPIO, BOARD_INITPINS_Usb_on_PIN, &Usb_on_config);

    /* PORTA13 (pin 29) is configured as PTA13 */
    PORT_SetPinMux(BOARD_INITPINS_Led5_PORT, BOARD_INITPINS_Led5_PIN, kPORT_MuxAsGpio);

    /* PORTA4 (pin 26) is configured as PTA4 */
    PORT_SetPinMux(BOARD_INITPINS_Led6_PORT, BOARD_INITPINS_Led6_PIN, kPORT_MuxAsGpio);

    /* PORTB0 (pin 35) is configured as ADC0_SE8 */
    PORT_SetPinMux(BOARD_INITPINS_Analog2_PORT, BOARD_INITPINS_Analog2_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB1 (pin 36) is configured as ADC0_SE9 */
    PORT_SetPinMux(BOARD_INITPINS_Analog3_PORT, BOARD_INITPINS_Analog3_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB16 (pin 39) is configured as PTB16 */
    PORT_SetPinMux(BOARD_INITPINS_Led4_PORT, BOARD_INITPINS_Led4_PIN, kPORT_MuxAsGpio);

    /* PORTB17 (pin 40) is configured as PTB17 */
    PORT_SetPinMux(BOARD_INITPINS_Rele_PORT, BOARD_INITPINS_Rele_PIN, kPORT_MuxAsGpio);

    /* PORTB18 (pin 41) is configured as PTB18 */
    PORT_SetPinMux(BOARD_INITPINS_Ds4_PORT, BOARD_INITPINS_Ds4_PIN, kPORT_MuxAsGpio);

    /* PORTB19 (pin 42) is configured as PTB19 */
    PORT_SetPinMux(BOARD_INITPINS_Ds3_PORT, BOARD_INITPINS_Ds3_PIN, kPORT_MuxAsGpio);

    /* PORTB2 (pin 37) is configured as ADC0_SE12 */
    PORT_SetPinMux(BOARD_INITPINS_Analog4_PORT, BOARD_INITPINS_Analog4_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB3 (pin 38) is configured as ADC0_SE13 */
    PORT_SetPinMux(BOARD_INITPINS_Analog5_PORT, BOARD_INITPINS_Analog5_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTC0 (pin 43) is configured as PTC0 */
    PORT_SetPinMux(BOARD_INITPINS_Ds2_PORT, BOARD_INITPINS_Ds2_PIN, kPORT_MuxAsGpio);

    /* PORTC1 (pin 44) is configured as PTC1 */
    PORT_SetPinMux(BOARD_INITPINS_Ds1_PORT, BOARD_INITPINS_Ds1_PIN, kPORT_MuxAsGpio);

    /* PORTC2 (pin 45) is configured as PTC2 */
    PORT_SetPinMux(BOARD_INITPINS_Sw3_PORT, BOARD_INITPINS_Sw3_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTC2 (pin 45): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_Sw3_PORT, BOARD_INITPINS_Sw3_PIN, kPORT_InterruptFallingEdge);

    /* PORTC3 (pin 46) is configured as PTC3 */
    PORT_SetPinMux(BOARD_INITPINS_Sw2_PORT, BOARD_INITPINS_Sw2_PIN, kPORT_MuxAsGpio);

    /* Interrupt configuration on PORTC3 (pin 46): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_Sw2_PORT, BOARD_INITPINS_Sw2_PIN, kPORT_InterruptFallingEdge);

    /* PORTC4 (pin 53) is configured as PTC4 */
    PORT_SetPinMux(BOARD_INITPINS_PinoTensao1_PORT, BOARD_INITPINS_PinoTensao1_PIN, kPORT_MuxAsGpio);

    /* PORTC5 (pin 54) is configured as PTC5 */
    PORT_SetPinMux(BOARD_INITPINS_PinoTensao2_PORT, BOARD_INITPINS_PinoTensao2_PIN, kPORT_MuxAsGpio);

    /* PORTC7 (pin 56) is configured as PTC7 */
    PORT_SetPinMux(BOARD_INITPINS_Led3_PORT, BOARD_INITPINS_Led3_PIN, kPORT_MuxAsGpio);

    /* PORTD0 (pin 57) is configured as PTD0 */
    PORT_SetPinMux(BOARD_INITPINS_Led2_PORT, BOARD_INITPINS_Led2_PIN, kPORT_MuxAsGpio);

    /* PORTD1 (pin 58) is configured as PTD1 */
    PORT_SetPinMux(BOARD_INITPINS_Led1_PORT, BOARD_INITPINS_Led1_PIN, kPORT_MuxAsGpio);

    /* PORTD6 (pin 63) is configured as LPUART0_RX */
    PORT_SetPinMux(BOARD_INITPINS_Rx_usb_PORT, BOARD_INITPINS_Rx_usb_PIN, kPORT_MuxAlt3);

    PORTD->PCR[6] = ((PORTD->PCR[6] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | PORT_PCR_PS(kPORT_PullUp)

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTD7 (pin 64) is configured as LPUART0_TX */
    PORT_SetPinMux(BOARD_INITPINS_Tx_Usb_PORT, BOARD_INITPINS_Tx_Usb_PIN, kPORT_MuxAlt3);

    PORTD->PCR[7] = ((PORTD->PCR[7] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | PORT_PCR_PS(kPORT_PullUp)

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable)

                     /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is
                      * configured as a digital output. */
                     | PORT_PCR_SRE(kPORT_SlowSlewRate));

    /* PORTE0 (pin 1) is configured as I2C1_SDA */
    PORT_SetPinMux(BOARD_INITPINS_Sda_PORT, BOARD_INITPINS_Sda_PIN, kPORT_MuxAlt6);

    PORTE->PCR[0] = ((PORTE->PCR[0] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin. */
                     | (uint32_t)(PORT_PCR_PE_MASK));

    /* PORTE1 (pin 2) is configured as I2C1_SCL */
    PORT_SetPinMux(BOARD_INITPINS_Scl_PORT, BOARD_INITPINS_Scl_PIN, kPORT_MuxAlt6);

    PORTE->PCR[1] = ((PORTE->PCR[1] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin. */
                     | (uint32_t)(PORT_PCR_PE_MASK));

    /* PORTE22 (pin 11) is configured as ADC0_DP3 */
    PORT_SetPinMux(BOARD_INITPINS_Analog1Dif1_PORT, BOARD_INITPINS_Analog1Dif1_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTE23 (pin 12) is configured as ADC0_DM3 */
    PORT_SetPinMux(BOARD_INITPINS_Analog1Dif2_PORT, BOARD_INITPINS_Analog1Dif2_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTE29 (pin 17) is configured as PTE29 */
    PORT_SetPinMux(BOARD_INITPINS_Wc_PORT, BOARD_INITPINS_Wc_PIN, kPORT_MuxAsGpio);

    PORTE->PCR[29] = ((PORTE->PCR[29] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                      /* Pull Enable: Internal pullup or pulldown resistor is enabled on the corresponding pin. */
                      | (uint32_t)(PORT_PCR_PE_MASK));

    /* PORTE31 (pin 19) is configured as PTE31 */
    PORT_SetPinMux(BOARD_INITPINS_Usb_on_PORT, BOARD_INITPINS_Usb_on_PIN, kPORT_MuxAsGpio);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK)))

                  /* LPUART0 Transmit Data Source Select: LPUART0_TX pin. */
                  | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX)

                  /* LPUART0 Receive Data Source Select: LPUART_RX pin. */
                  | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
