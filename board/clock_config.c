/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/
/*
 * How to setup clock using clock driver functions:
 *
 * 1. CLOCK_SetSimSafeDivs, to make sure core clock, bus clock, flexbus clock
 *    and flash clock are in allowed range during clock mode switch.
 *
 * 2. Call CLOCK_Osc0Init to setup OSC clock, if it is used in target mode.
 *
 * 3. Call CLOCK_SetMcgliteConfig to set MCG_Lite configuration.
 *
 * 4. Call CLOCK_SetSimConfig to set the clock configuration in SIM.
 */

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v7.0
processor: MKL33Z64xxx4
package_id: MKL33Z64VLH4
mcu_data: ksdk2_0
processor_version: 9.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

#include "fsl_rtc.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define RTC_CLKIN_32768HZ                             32768U  /*!< RTC_CLKIN frequency: 32768Hz */
#define SIM_CLKOUT_SEL_LPO_CLK                            3U  /*!< CLKOUT pin clock select: LPO clock */
#define SIM_FLEXIO_CLK_SEL_MCGIRCLK_CLK                   3U  /*!< FLEXIO clock select: MCGIRCLK clock */
#define SIM_LPUART_CLK_SEL_MCGIRCLK_CLK                   3U  /*!< LPUART clock select: MCGIRCLK clock */
#define SIM_OSC32KSEL_OSC32KCLK_CLK                       0U  /*!< OSC32KSEL select: OSC32KCLK clock */
#define SIM_RTC_CLKOUT_SEL_RTC1HZCLK_CLK                  0U  /*!< RTC clock output select: RTC1HzCLK clock */
#define SIM_TPM_CLK_SEL_MCGIRCLK_CLK                      3U  /*!< TPM clock select: MCGIRCLK clock */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_CONFIG_SetRtcClock
 * Description   : This function is used to configuring RTC clock
 *
 *END**************************************************************************/
static void CLOCK_CONFIG_SetRtcClock()
{
  /* RTC clock gate enable */
  CLOCK_EnableClock(kCLOCK_Rtc0);
  /* Set RTC_TSR if there is fault value in RTC */
  if (RTC->SR & RTC_SR_TIF_MASK) {
    RTC -> TSR = RTC -> TSR;
  }
  /* RTC clock gate disable */
  CLOCK_DisableClock(kCLOCK_Rtc0);
}

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
    BOARD_BootClockRUN();
}

/*******************************************************************************
 ********************** Configuration BOARD_BootClockRUN ***********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockRUN
called_from_default_init: true
outputs:
- {id: Bus_clock.outFreq, value: 1 MHz}
- {id: CLKOUT.outFreq, value: 1 kHz}
- {id: COPCLK.outFreq, value: 1 kHz}
- {id: Core_clock.outFreq, value: 2 MHz}
- {id: ERCLK32K.outFreq, value: 32.768 kHz}
- {id: FLEXIOCLK.outFreq, value: 2 MHz}
- {id: Flash_clock.outFreq, value: 1 MHz}
- {id: LPO_clock.outFreq, value: 1 kHz}
- {id: LPUART0CLK.outFreq, value: 2 MHz}
- {id: MCGIRCLK.outFreq, value: 2 MHz}
- {id: OSCERCLK.outFreq, value: 32.768 kHz}
- {id: RTC_CLKOUT.outFreq, value: 1 Hz}
- {id: System_clock.outFreq, value: 2 MHz}
- {id: TPMCLK.outFreq, value: 2 MHz}
settings:
- {id: MCGMode, value: LIRC2M}
- {id: CLKOUTConfig, value: 'yes'}
- {id: COPClkConfig, value: 'yes'}
- {id: FLEXIOClkConfig, value: 'yes'}
- {id: LPUART0ClkConfig, value: 'yes'}
- {id: LPUART1ClkConfig, value: 'yes'}
- {id: MCG.LIRCDIV1.scale, value: '1', locked: true}
- {id: MCG.LIRCDIV2.scale, value: '1', locked: true}
- {id: MCG_C2_OSC_MODE_CFG, value: ModeOscLowPower}
- {id: OSC0_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC0_CR_EREFSTEN_CFG, value: Enabled}
- {id: OSC_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC_CR_EREFSTEN_CFG, value: Enabled}
- {id: OSC_CR_SYS_OSC_CAP_LOAD_CFG, value: SC12PF}
- {id: RTCCLKOUTConfig, value: 'yes'}
- {id: RTCClkConfig, value: 'yes'}
- {id: SIM.CLKOUTSEL.sel, value: PMC.LPOCLK}
- {id: SIM.FLEXIOSRCSEL.sel, value: MCG.MCGIRCLK}
- {id: SIM.LPUART0SRCSEL.sel, value: MCG.MCGIRCLK}
- {id: SIM.OUTDIV1.scale, value: '1', locked: true}
- {id: SIM.OUTDIV4.scale, value: '2', locked: true}
- {id: SIM.TPMSRCSEL.sel, value: MCG.MCGIRCLK}
- {id: TPMClkConfig, value: 'yes'}
sources:
- {id: MCG.LIRC.outFreq, value: 2 MHz}
- {id: OSC.OSC.outFreq, value: 32.768 kHz, enabled: true}
- {id: SIM.RTC_CLK_EXT_IN.outFreq, value: 32.768 kHz, enabled: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockRUN configuration
 ******************************************************************************/
const mcglite_config_t mcgliteConfig_BOARD_BootClockRUN =
    {
        .outSrc = kMCGLITE_ClkSrcLirc,            /* MCGOUTCLK source is LIRC */
        .irclkEnableMode = kMCGLITE_IrclkEnable,  /* MCGIRCLK enabled, MCGIRCLK disabled in STOP mode */
        .ircs = kMCGLITE_Lirc2M,                  /* Slow internal reference (LIRC) 2 MHz clock selected */
        .fcrdiv = kMCGLITE_LircDivBy1,            /* Low-frequency Internal Reference Clock Divider: divided by 1 */
        .lircDiv2 = kMCGLITE_LircDivBy1,          /* Second Low-frequency Internal Reference Clock Divider: divided by 1 */
        .hircEnableInNotHircMode = false,         /* HIRC source is not enabled */
    };
const sim_clock_config_t simConfig_BOARD_BootClockRUN =
    {
        .er32kSrc = SIM_OSC32KSEL_OSC32KCLK_CLK,  /* OSC32KSEL select: OSC32KCLK clock */
        .clkdiv1 = 0x10000U,                      /* SIM_CLKDIV1 - OUTDIV1: /1, OUTDIV4: /2 */
    };
const osc_config_t oscConfig_BOARD_BootClockRUN =
    {
        .freq = 32768U,                           /* Oscillator frequency: 32768Hz */
        .capLoad = (kOSC_Cap4P | kOSC_Cap8P),     /* Oscillator capacity load: 12pF */
        .workMode = kOSC_ModeOscLowPower,         /* Oscillator low power */
        .oscerConfig =
            {
                .enableMode = kOSC_ErClkEnable | kOSC_ErClkEnableInStop,/* Enable external reference clock, enable external reference clock in STOP mode */
            }
    };

/*******************************************************************************
 * Code for BOARD_BootClockRUN configuration
 ******************************************************************************/
void BOARD_BootClockRUN(void)
{
    /* Use RTC_CLKIN input clock directly. */
    CLOCK_SetXtal32Freq(RTC_CLKIN_32768HZ);
    /* Set the system clock dividers in SIM to safe value. */
    CLOCK_SetSimSafeDivs();
    /* Initializes OSC0 according to board configuration. */
    CLOCK_InitOsc0(&oscConfig_BOARD_BootClockRUN);
    CLOCK_SetXtal0Freq(oscConfig_BOARD_BootClockRUN.freq);
    /* Set MCG to LIRC2M mode. */
    CLOCK_SetMcgliteConfig(&mcgliteConfig_BOARD_BootClockRUN);
    /* Set the clock configuration in SIM module. */
    CLOCK_SetSimConfig(&simConfig_BOARD_BootClockRUN);
    /* Configure RTC clock. */
    CLOCK_CONFIG_SetRtcClock();
    /* Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKRUN_CORE_CLOCK;
    /* Set RTC_CLKOUT source. */
    CLOCK_SetRtcClkOutClock(SIM_RTC_CLKOUT_SEL_RTC1HZCLK_CLK);
    /* Set LPUART0 clock source. */
    CLOCK_SetLpuart0Clock(SIM_LPUART_CLK_SEL_MCGIRCLK_CLK);
    /* Set FLEXIO clock source. */
    CLOCK_SetFlexio0Clock(SIM_FLEXIO_CLK_SEL_MCGIRCLK_CLK);
    /* Set TPM clock source. */
    CLOCK_SetTpmClock(SIM_TPM_CLK_SEL_MCGIRCLK_CLK);
    /* Set CLKOUT source. */
    CLOCK_SetClkOutClock(SIM_CLKOUT_SEL_LPO_CLK);
}

