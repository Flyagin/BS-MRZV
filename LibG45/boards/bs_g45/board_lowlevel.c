/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
/// \unit
///
/// !Purpose
///
/// Provides the low-level initialization function that gets called on chip
/// startup.
///
/// !Usage
///
/// LowLevelInit() is called in #board_cstartup.S#.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "board.h"
#include "board_memories.h"
#include <pmc/pmc.h>
#include "./at91sam9g45/g45_TCM.h"
#include "../peripherals/pio/pio.h"


//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------

/* Settings at 400/133MHz */
#define BOARD_OSCOUNT           (AT91C_CKGR_OSCOUNT & (64 << 8))
#define BOARD_CKGR_PLLA         (AT91C_CKGR_SRCA | AT91C_CKGR_OUTA_0)
#define BOARD_PLLACOUNT         (0x3F << 8)
#define BOARD_MULA              (AT91C_CKGR_MULA & (198 << 16))
#define BOARD_DIVA              (AT91C_CKGR_DIVA & 3)

#define BOARD_PRESCALER         (0x00001300) //400/133MHz
//#define BOARD_PRESCALER         (0x00001200) //400/100MHz

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Default spurious interrupt handler. Infinite loop.
//------------------------------------------------------------------------------
void defaultSpuriousHandler( void )
{
 // AT91C_BASE_PIOD->PIO_CODR = (0x2);  
  while (1);
}

//------------------------------------------------------------------------------
/// Default handler for fast interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultFiqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for standard interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultIrqHandler( void )
{
    while (1);
}

extern void TestLite(void);
#if !defined(ddram)
long StartTest(void);
#endif
//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Performs the low-level initialization of the chip. Initialisation depends
/// on where the application is executed: 
/// - in sdram: it means that sdram has previously been initialized. No further
///             initialization is required.
/// - in sram:  PLL shall be initialized in LowLevelInit. Other initializations 
///             can be done later by the application.
/// - in norflash: LowLevelInit can't be executed in norflash because SMC 
///             settings can't be changed while executing in external flash.
///             LowLevelInit shall be executed in internal sram. It initializes
///             PLL and SMC. 
/// This function also reset the AIC and disable RTT and PIT interrupts
//------------------------------------------------------------------------------
void LowLevelInit(void)
{
    unsigned char i;
	

	 //Настроюємо SMC0
    AT91C_BASE_SMC->SMC_SETUP0 = ((AT91C_SMC_NWESETUP & (3 <<0))
                                 |(AT91C_SMC_NCSSETUPWR & (3 <<8))
                                 |(AT91C_SMC_NRDSETUP &   (0 <<16))
                                 |(AT91C_SMC_NCSSETUPRD & (0 <<24)));

    AT91C_BASE_SMC->SMC_PULSE0 = ((AT91C_SMC_NWEPULSE &   (10 <<0))
                                 |(AT91C_SMC_NCSPULSEWR & (10 <<8))
                                 |(AT91C_SMC_NRDPULSE &   (11 <<16))
                                 |(AT91C_SMC_NCSPULSERD & (11 <<24)));

    AT91C_BASE_SMC->SMC_CYCLE0 = ((AT91C_SMC_NWECYCLE & (15 <<0))
                                 |(AT91C_SMC_NRDCYCLE & (12 <<16)));
    
    AT91C_BASE_SMC->SMC_CTRL0 = ( (AT91C_SMC_READMODE & (1<<0))
                                | (AT91C_SMC_WRITEMODE & (1<<1))
                                | (AT91C_SMC_NWAITM_NWAIT_DISABLE  )
                                | (AT91C_SMC_BAT_BYTE_SELECT       )
                                | (AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS)
                                | (AT91C_SMC_TDF & (1<<16))
                                | (AT91C_SMC_TDFEN & (1<<20))
                                | (AT91C_SMC_PMEN & (0<<24))
                                | (AT91C_SMC_PS & (0<<24)));
/*
    //Настроюємо SMC1
	AT91C_BASE_SMC->SMC_SETUP1 =  ((AT91C_SMC_NWESETUP & (3 <<0))
                                  |(AT91C_SMC_NCSSETUPWR & (3 <<8))
                                  |(AT91C_SMC_NRDSETUP & (0 <<16))
                                  |(AT91C_SMC_NCSSETUPRD & (0 <<24)));
                                 
    AT91C_BASE_SMC->SMC_PULSE1 =  ((AT91C_SMC_NWEPULSE & (9 <<0))
                                  |(AT91C_SMC_NCSPULSEWR & (9 <<8))
                                  |(AT91C_SMC_NRDPULSE & (9 <<16))
                                  |(AT91C_SMC_NCSPULSERD & (9 <<24)));
                                 
    AT91C_BASE_SMC->SMC_CYCLE1 =  ((AT91C_SMC_NWECYCLE & (17 <<0))
                                  |(AT91C_SMC_NRDCYCLE & (12 <<16)));
                                 
    AT91C_BASE_SMC->SMC_CTRL1 =  ( (AT91C_SMC_READMODE & (1<<0))
                                 | (AT91C_SMC_WRITEMODE & (1<<1))
                                 | (AT91C_SMC_NWAITM_NWAIT_DISABLE  )
                                 | (AT91C_SMC_BAT_BYTE_SELECT       )
                                 | (AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS)
                                 | (AT91C_SMC_TDF & (0<<16))
                                 | (AT91C_SMC_TDFEN & (0<<20))
                                 | (AT91C_SMC_PMEN & (0<<24))
                                 | (AT91C_SMC_PS & (0<<24)));
								 
*-/
AT91C_BASE_SMC->SMC_SETUP1 = ((AT91C_SMC_NWESETUP & (3 <<0))
                                 |(AT91C_SMC_NCSSETUPWR & (3 <<8))
                                 |(AT91C_SMC_NRDSETUP & (2 <<16))
                                 |(AT91C_SMC_NCSSETUPRD & (1 <<24)));

    AT91C_BASE_SMC->SMC_PULSE1 = ((AT91C_SMC_NWEPULSE & (9 <<0))
                                 |(AT91C_SMC_NCSPULSEWR & (9 <<8))
                                 |(AT91C_SMC_NRDPULSE & (12 <<16))
                                 |(AT91C_SMC_NCSPULSERD & (15 <<24)));

    AT91C_BASE_SMC->SMC_CYCLE1 = ((AT91C_SMC_NWECYCLE & (17 <<0))
                                 |(AT91C_SMC_NRDCYCLE & (20 <<16)));
    
    AT91C_BASE_SMC->SMC_CTRL1 = ( (AT91C_SMC_READMODE & (1<<0))
                                | (AT91C_SMC_WRITEMODE & (1<<1))
                                | (AT91C_SMC_NWAITM_NWAIT_DISABLE  )
                                | (AT91C_SMC_BAT_BYTE_SELECT       )
                                | (AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS)
                                | (AT91C_SMC_TDF & (0<<16))
                                | (AT91C_SMC_TDFEN & (0<<20))
                                | (AT91C_SMC_PMEN & (0<<24))
                                | (AT91C_SMC_PS & (0<<24)));*/
								 
	AT91C_BASE_SMC->SMC_SETUP1 = ((AT91C_SMC_NWESETUP & (1 <<0))
                                 |(AT91C_SMC_NCSSETUPWR & (1 <<8))
                                 |(AT91C_SMC_NRDSETUP & (0 <<16))
                                 |(AT91C_SMC_NCSSETUPRD & (0 <<24)));

    AT91C_BASE_SMC->SMC_PULSE1 = ((AT91C_SMC_NWEPULSE & (4 <<0))
                                 |(AT91C_SMC_NCSPULSEWR & (4 <<8))
                                 |(AT91C_SMC_NRDPULSE & (4 <<16))
                                 |(AT91C_SMC_NCSPULSERD & (4 <<24)));

    AT91C_BASE_SMC->SMC_CYCLE1 = ((AT91C_SMC_NWECYCLE & (6 <<0))
                                 |(AT91C_SMC_NRDCYCLE & (6 <<16)));
    
    AT91C_BASE_SMC->SMC_CTRL1 = ( (AT91C_SMC_READMODE & (1<<0))
                                | (AT91C_SMC_WRITEMODE & (1<<1))
                                | (AT91C_SMC_NWAITM_NWAIT_DISABLE     )
                                | (AT91C_SMC_BAT_BYTE_SELECT          )
                                | (AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS)
                                | (AT91C_SMC_TDF & (0<<16))
                                | (AT91C_SMC_TDFEN & (1<<20))
                                | (AT91C_SMC_PMEN & (0<<24))
                                | (AT91C_SMC_PS & (0<<24)));							 
	
								 
#if !defined(ddram)
    /* Initialize main oscillator
     ****************************/
    AT91C_BASE_PMC->PMC_MOR = BOARD_OSCOUNT | AT91C_CKGR_MOSCEN;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));

    /* Initialize PLLA */
    AT91C_BASE_PMC->PMC_PLLAR = BOARD_CKGR_PLLA
                                | BOARD_PLLACOUNT
                                | BOARD_MULA
                                | BOARD_DIVA;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKA));
    
    /* Wait for the master clock if it was already initialized */
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
  // printf("board_lowlevel.Ini EBI&PLL \n");
   

	/* Switch to fast clock
     **********************/
    /* Switch to main oscillator + prescaler */
    AT91C_BASE_PMC->PMC_MCKR = BOARD_PRESCALER;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
 
    /* Switch to PLL + prescaler */
    AT91C_BASE_PMC->PMC_MCKR |= AT91C_PMC_CSS_PLLA_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
#endif

    /* Initialize AIC
     ****************/
    AT91C_BASE_AIC->AIC_IDCR = 0xFFFFFFFF;
    AT91C_BASE_AIC->AIC_SVR[0] = (unsigned int) defaultFiqHandler;
    for (i = 1; i < 31; i++) {

        AT91C_BASE_AIC->AIC_SVR[i] = (unsigned int) defaultIrqHandler;
    }
    AT91C_BASE_AIC->AIC_SPU = (unsigned int) defaultSpuriousHandler;
AT91C_BASE_SMC->SMC_CTRL0 = ( (AT91C_SMC_READMODE & (1<<0))
                                | (AT91C_SMC_WRITEMODE & (1<<1))
                                | (AT91C_SMC_NWAITM_NWAIT_DISABLE  )
                                | (AT91C_SMC_BAT_BYTE_SELECT       )
                                | (AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS)
                                | (AT91C_SMC_TDF   & (2<<16))
                                | (AT91C_SMC_TDFEN & (1<<20))
                                | (AT91C_SMC_PMEN  & (0<<24))
                                | (AT91C_SMC_PS    & (0<<24)));
    AT91C_BASE_SMC->SMC_CYCLE0 = ((AT91C_SMC_NWECYCLE & (15 <<0))
                                 |(AT91C_SMC_NRDCYCLE & (12 <<16)));
								// Unstack nested interrupts
    AT91C_BASE_SMC->SMC_SETUP0 = ((AT91C_SMC_NWESETUP   & (3 <<0))
                                 |(AT91C_SMC_NCSSETUPWR & (3 <<8))
                                 |(AT91C_SMC_NRDSETUP   & (1 <<16))
                                 |(AT91C_SMC_NCSSETUPRD & (1 <<24)));	
    for (i = 0; i < 8 ; i++) {

        AT91C_BASE_AIC->AIC_EOICR = 0;
    }


    /* Watchdog initialization
     *************************/
  #ifndef WDT_APP // Watchdog init in application ?
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;
  #endif
     AT91C_BASE_PIOC->PIO_PDR  = 0xFFFF0000;
    //AT91C_PIOC_PDR =  0xFFFF0000;


    AT91C_BASE_SMC->SMC_PULSE0 = ((AT91C_SMC_NWEPULSE   & (11 <<0))
                                 |(AT91C_SMC_NCSPULSEWR & (11 <<8))
                                 |(AT91C_SMC_NRDPULSE   & (10 <<16))
                                 |(AT91C_SMC_NCSPULSERD & (10 <<24)));

    /* Remap
     *******/
    BOARD_RemapRam();
	//..tcm_init();
	//SetUpArm926ej();

    
    // Disable RTT and PIT interrupts (potential p roblem when program A
    // configures RTT, then program B wants to use PIT only, interrupts
    // from the RTT will still occur since they both use AT91C_ID_SYS)
    AT91C_BASE_RTTC->RTTC_RTMR &= (unsigned int)(~(AT91C_RTTC_ALMIEN | AT91C_RTTC_RTTINCIEN));
    AT91C_BASE_PITC->PITC_PIMR &= (unsigned int)(~AT91C_PITC_PITIEN);
#if !defined(ddram)
    BOARD_ConfigureDdram(DDR_MICRON_MT47H32M16HR, 16);
#endif    
	#ifdef BS_G45_TEST // 
    //StartTest();
#if !defined(ddram)
//  	#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//	#endif  
    StartTest();
//	   printf("board_lowlevel.Test Passed \n");
#endif

    #endif
		#ifdef  flash //.. //FL_REL 

   TestLite();
    #endif   
    
#if defined(norflash)
    BOARD_ConfigureNorFlash(BOARD_NORFLASH_DFT_BUS_SIZE);
#endif    
//.#if !defined(ddram)
//.	BOARD_ConfigureDdram(DDR_MICRON_MT47H32M16HR, 16);  
//.#endif
//Дозволяємо мультипортовість
     AT91C_BASE_MATRIX->MATRIX_DDRMPR = 0;
//	  #ifdef  BS_G45_FL_RL
//  __asm volatile("BKPT 4");
//  #endif 
}
#include "./at91sam9g45/g45_TCM.c"
//G:\HVP_pj\Hvps\hvps01_03_13\HS1_0100_00_i670\LibG45\boards\bs_g45\at91sam9g45
