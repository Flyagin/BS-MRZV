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
/// \dir
/// !Purpose
///
/// Definition and functions for using AT91SAM9G45-related features, such
/// has PIO pins, memories, etc.
///
/// !Usage
/// -# The code for booting the board is provided by board_cstartup.S and
///    board_lowlevel.c.
/// -# For using board PIOs, board characteristics (clock, etc.) and external
///    components, see board.h.
/// -# For manipulating memories (remapping, SDRAM, etc.), see board_memories.h.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \unit
/// !Purpose
///
/// Definition of AT91SAM9G45-EK characteristics, AT91SAM9G45-dependant PIOs and
/// external components interfacing.
///
/// !Usage
/// -# For operating frequency information, see "SAM9G45-EK - Operating frequencies".
/// -# For using portable PIO definitions, see "SAM9G45-EK - PIO definitions".
/// -# Several USB definitions are included here (see "SAM9G45-EK - USB device").
/// -# For external components definitions, see "SAM9G45-EK - External components".
/// -# For memory-related definitions, see "SAM79260-EK - Memories".
//------------------------------------------------------------------------------

#ifndef BOARD_H
#define BOARD_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#if defined(at91sam9g45)
    #include "at91sam9g45/chip.h"
    #include "at91sam9g45/AT91SAM9G45.h"
#else
    #error Board does not support the specified chip.
#endif

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK - Board Description"
/// This page lists several definition related to the board description.
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME              "AT91SAM9G45-EK"
/// Board definition.
#define at91sam9g45ek
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
///
/// !Definitions
/// - BOARD_MAINOSC
/// - BOARD_MCK

/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           12000000

/// Master clock frequency (when using board_lowlevel.c).
// ((12MHz / DIVA / PLLADIV2 / MDIV) * (MULA+1)
#define BOARD_MCK               ((unsigned long)((BOARD_MAINOSC / 3 / 2 / 3) * 200 )) // 133MHz
//#define BOARD_MCK               ((unsigned long)((BOARD_MAINOSC / 3 / 2 / 4) * 200 )) // 100MHz

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9RL-EK - USB device"
/// This page lists constants describing several characteristics (controller
/// type, D+ pull-up type, etc.) of the USB device controller of the chip/board.
///
/// !Constants
/// - BOARD_USB_UDPHS
/// - BOARD_USB_PULLUP_INTERNAL
/// - BOARD_USB_NUMENDPOINTS
/// - BOARD_USB_ENDPOINTS_MAXPACKETSIZE
/// - BOARD_USB_ENDPOINTS_BANKS
/// - BOARD_USB_BMATTRIBUTES

/// Chip has a UDPHS controller.
#define BOARD_USB_UDPHS

/// Indicates the D+ pull-up is internal to the USB controller.
#define BOARD_USB_PULLUP_INTERNAL

/// Number of endpoints in the USB controller.
#define BOARD_USB_NUMENDPOINTS                  7

/// Returns the maximum packet size of the given endpoint.
#define BOARD_USB_ENDPOINTS_MAXPACKETSIZE(i)    ((i == 0) ? 64 : 1024)

/// Returns the number of FIFO banks for the given endpoint.
#define BOARD_USB_ENDPOINTS_BANKS(i)            ((i == 0) ? 1 : ((i == 1) || (i == 2)) ? 2 : 3)

/// USB attributes configuration descriptor (bus or self powered, remote wakeup)
//#define BOARD_USB_BMATTRIBUTES                  USBConfigurationDescriptor_SELFPOWERED_RWAKEUP
#define BOARD_USB_BMATTRIBUTES                  USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK - PIO definitions"
/// This pages lists all the pio definitions contained in board.h. The constants
/// are named using the following convention: PIN_* for a constant which defines
/// a single Pin instance (but may include several PIOs sharing the same
/// controller), and PINS_* for a list of Pin instances.
///
/// !DBGU
/// - PINS_DBGU
///
/// !LEDs
/// - PIN_LED_0
/// - PIN_LED_1
/// - PINS_LEDS
/// - LED_POWER
/// - LED_DS1
///
/// !Push buttons
/// - PIN_PUSHBUTTON_1
/// - PIN_PUSHBUTTON_2
/// - PINS_PUSHBUTTONS
/// - PUSHBUTTON_BP1
/// - PUSHBUTTON_BP2
/// - JOYSTICK_LEFT
/// - JOYSTICK_RIGHT
///
/// !USART0
/// - PIN_USART0_RXD
/// - PIN_USART0_TXD
///
/// !SPI0
/// - PIN_SPI0_MISO
/// - PIN_SPI0_MOSI
/// - PIN_SPI0_SPCK
/// - PINS_SPI0
/// - PIN_SPI0_NPCS0
/// - PIN_SPI0_NPCS1
///
/// !SSC
/// - PINS_SSC_TX
///
/// !USB
/// - PIN_USB_VBUS
///
/// !MCI
/// - PINS_MCI
///
/// !TWI
/// - PINS_TWI0
///
/// !TSADC
/// - PINS_TSADCC
/// USART0 TXD pin definition.
#define PIN_USART0_TXD  {1 << 19, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 RXD pin definition.
#define PIN_USART0_RXD  {1 << 18, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 RTS pin definition.
#define PIN_USART0_RTS  {1 << 17, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 CTS pin definition.
#define PIN_USART0_CTS  {1 << 15, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 SCK pin definition.
#define PIN_USART0_SCK  {1 << 16, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// USART1 TXD pin definition.
#define PIN_USART1_TXD  {1 <<  4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// USART1 RXD pin definition.
#define PIN_USART1_RXD  {1 <<  5, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// USART1 RTS pin definition.
#define PIN_USART1_RTS  {1 << 16, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}
/// USART1 CTS pin definition.
#define PIN_USART1_CTS  {1 << 17, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}
/// USART1 SCK pin definition.
#define PIN_USART1_SCK  {1 << 29, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}


#define PIN_USART2_TXD  {1 <<  6, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
/// USART1 RXD pin definition.
#define PIN_USART2_RXD  {1 <<  7, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// USART1 RTS pin definition.
#define PIN_USART2_RTS  {1 << 11, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
/// USART1 CTS pin definition.
#define PIN_USART2_CTS  {1 << 9, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
/// USART1 SCK pin definition.
#define PIN_USART2_SCK  {1 << 30, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}
                         //Podnaval Dimki
/// USART3 TXD pin definition.
#define PIN_USART3_TXD  {1 <<  8, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A,  PIO_PULLUP}
/// USART3 RXD pin definition.
#define PIN_USART3_RXD  {1 <<  9, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A,  PIO_PULLUP}
/// USART3 RTS pin definition.
#define PIN_USART3_RTS  {1 << 23, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B,  PIO_PULLUP}




/// USB VBus monitoring pin definition.
//#define PIN_USB_VBUS    {1 << 19, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT}
#define PIN_USB_VBUS    {(unsigned int)(1 << 31), AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_INPUT, PIO_DEFAULT}

/// USB VBus supply pin definition.



//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the AT91SAM9G45-EK.
///
/// !AT45 Dataflash Card (A)
/// - BOARD_AT45_A_SPI_BASE
/// - BOARD_AT45_A_SPI_ID
/// - BOARD_AT45_A_SPI_PINS
/// - BOARD_AT45_A_SPI
/// - BOARD_AT45_A_NPCS
/// - BOARD_AT45_A_NPCS_PIN
///
/// !AT45 Dataflash (B)
/// - BOARD_AT45_B_SPI_BASE
/// - BOARD_AT45_B_SPI_ID
/// - BOARD_AT45_B_SPI_PINS
/// - BOARD_AT45_B_SPI
/// - BOARD_AT45_B_NPCS
/// - BOARD_AT45_B_NPCS_PIN
///
/// !LCD
/// - PINS_LCD
/// - BOARD_LCD_WIDTH
/// - BOARD_LCD_HEIGHT
/// - BOARD_LCD_BPP
/// - BOARD_LCD_IFWIDTH
/// - BOARD_LCD_FRAMESIZE_PIXELS
/// - BOARD_LCD_FRAMESIZE
/// - BOARD_LCD_FRAMERATE
/// - BOARD_LCD_PIXELCLOCK
/// - BOARD_LCD_DISPLAYTYPE
/// - BOARD_LCD_POLARITY_INVVD
/// - BOARD_LCD_POLARITY_INVFRAME
/// - BOARD_LCD_POLARITY_INVLINE
/// - BOARD_LCD_POLARITY_INVCLK
/// - BOARD_LCD_POLARITY_INVDVAL
/// - BOARD_LCD_CLOCKMODE
/// - BOARD_LCD_TIMING_VFP
/// - BOARD_LCD_TIMING_VBP
/// - BOARD_LCD_TIMING_VPW
/// - BOARD_LCD_TIMING_VHDLY
/// - BOARD_LCD_TIMING_HFP
/// - BOARD_LCD_TIMING_HBP
/// - BOARD_LCD_TIMING_HPW
/// 
/// !Touchscreen
/// - BOARD_TOUCHSCREEN_ADCCLK
/// - BOARD_TOUCHSCREEN_STARTUP
/// - BOARD_TOUCHSCREEN_SHTIM
/// - BOARD_TOUCHSCREEN_DEBOUNCE
/// 
/// !SD Card
/// - BOARD_SD_MCI_BASE
/// - BOARD_SD_MCI_ID
/// - BOARD_SD_PINS
/// - BOARD_SD_SLOT
/// - BOARD_SD_BOOT_MCISLOT
///
/// !AC97
/// - PINS_AC97
///
/// !ISI
/// - BOARD_ISI_PIO_CNTRL1
/// - BOARD_ISI_PIO_CNTRL2
/// - BOARD_ISI_TWCK
/// - BOARD_ISI_TWD
/// - BOARD_ISI_MCK
/// - BOARD_ISI_VSYNC
/// - BOARD_ISI_HSYNC
/// - BOARD_ISI_PCK
/// - BOARD_ISI_PINS_DATA




/// LCD pin list.
#define PINS_LCD    \
    {0x7FFFFFFF, AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}
//

/// Board is wired in BGR 565.
//#define BOARD_LCD_BGR565

/// LCD pixel clock is not divide by two                                                                    //./// LCD pixel clock is not divide by two
//#define LCDC_PIXELCLOCK_DOUBLE																			//.//#define LCDC_PIXELCLOCK_DOUBLE
/// Display width in pixels.																				//./// Display width in pixels.
#define BOARD_LCD_WIDTH             320//320//240																		//.#define BOARD_LCD_WIDTH             480
/// Display height in pixels.																				//./// Display height in pixels.
#define BOARD_LCD_HEIGHT            240//240//320																		//.#define BOARD_LCD_HEIGHT            272
/// Display resolution in bits per pixel (bpp).																//./// Display resolution in bits per pixel (bpp).
#define BOARD_LCD_BPP               AT91C_LCDC_PIXELSIZE_TWENTYFOURBITSPERPIXEL								//.#define BOARD_LCD_BPP               AT91C_LCDC_PIXELSIZE_TWENTYFOURBITSPERPIXEL
/// Display interface width in bits.																		//./// Display interface width in bits.
#define BOARD_LCD_IFWIDTH           24																		//.#define BOARD_LCD_IFWIDTH           24
/// Frame size in pixels (height * width * bpp).															//./// Frame size in pixels (height * width * bpp).
#define BOARD_LCD_FRAMESIZE_PIXELS  (BOARD_LCD_WIDTH * BOARD_LCD_HEIGHT * 24)								//.#define BOARD_LCD_FRAMESIZE_PIXELS  (BOARD_LCD_WIDTH * BOARD_LCD_HEIGHT * 24)
/// Frame size in words (height * width * bpp / 32)															//./// Frame size in words (height * width * bpp / 32)
#define BOARD_LCD_FRAMESIZE         (BOARD_LCD_FRAMESIZE_PIXELS / 32)										//.#define BOARD_LCD_FRAMESIZE         (BOARD_LCD_FRAMESIZE_PIXELS / 32)
/// Frame rate in Hz.																						//./// Frame rate in Hz.
#define BOARD_LCD_FRAMERATE         60																		//.#define BOARD_LCD_FRAMERATE         60
/// Pixel clock rate in Hz (frameSize * frameRate / interfaceWidth).										//./// Pixel clock rate in Hz (frameSize * frameRate / interfaceWidth).
#define BOARD_LCD_PIXELCLOCK        (BOARD_LCD_FRAMESIZE_PIXELS * BOARD_LCD_FRAMERATE / BOARD_LCD_IFWIDTH)	//.#define BOARD_LCD_PIXELCLOCK        (BOARD_LCD_FRAMESIZE_PIXELS * BOARD_LCD_FRAMERATE / BOARD_LCD_IFWIDTH)
/// LCD display type.																						//./// LCD display type.
#define BOARD_LCD_DISPLAYTYPE       AT91C_LCDC_DISTYPE_TFT													//.#define BOARD_LCD_DISPLAYTYPE       AT91C_LCDC_DISTYPE_TFT
/// LCDC polarity.																							//./// LCDC polarity.
#define BOARD_LCD_POLARITY_INVVD    AT91C_LCDC_INVVD_NORMALPOL												//.#define BOARD_LCD_POLARITY_INVVD    AT91C_LCDC_INVVD_NORMALPOL
/// LCDVSYNC polarity.																						//./// LCDVSYNC polarity.
#define BOARD_LCD_POLARITY_INVFRAME AT91C_LCDC_INVFRAME_INVERTEDPOL											//.#define BOARD_LCD_POLARITY_INVFRAME AT91C_LCDC_INVFRAME_INVERTEDPOL
/// LCDHSYNC polarity.																						//./// LCDHSYNC polarity.
#define BOARD_LCD_POLARITY_INVLINE   AT91C_LCDC_INVLINE_INVERTEDPOL											//.#define BOARD_LCD_POLARITY_INVLINE  AT91C_LCDC_INVLINE_INVERTEDPOL
/// LCDDOTCLK polarity.																						//./// LCDDOTCLK polarity.
#define BOARD_LCD_POLARITY_INVCLK   /*AT91C_LCDC_INVCLK_NORMALPOL*/AT91C_LCDC_INVCLK_INVERTEDPOL												//.#define BOARD_LCD_POLARITY_INVCLK   AT91C_LCDC_INVCLK_NORMALPOL
/// LCDDEN polarity.																						//./// LCDDEN polarity.
#define BOARD_LCD_POLARITY_INVDVAL  AT91C_LCDC_INVDVAL_NORMALPOL											//.#define BOARD_LCD_POLARITY_INVDVAL  AT91C_LCDC_INVDVAL_NORMALPOL
/// Pixel clock mode.																						//./// Pixel clock mode.
#define BOARD_LCD_CLOCKMODE         AT91C_LCDC_CLKMOD_ALWAYSACTIVE											//.#define BOARD_LCD_CLOCKMODE         AT91C_LCDC_CLKMOD_ALWAYSACTIVE
/// Vertical front porch in number of lines.																//./// Vertical front porch in number of lines.
#define BOARD_LCD_TIMING_VFP        4																		//.#define BOARD_LCD_TIMING_VFP        4
/// Vertical back porch in number of lines.																	//./// Vertical back porch in number of lines.
#define BOARD_LCD_TIMING_VBP        18																		//.#define BOARD_LCD_TIMING_VBP        4
/// Vertical pulse width in LCDDOTCLK cycles.																//./// Vertical pulse width in LCDDOTCLK cycles.
#define BOARD_LCD_TIMING_VPW        4																		//.#define BOARD_LCD_TIMING_VPW        4
/// Number of cycles between VSYNC edge and HSYNC rising edge.												//./// Number of cycles between VSYNC edge and HSYNC rising edge.
#define BOARD_LCD_TIMING_VHDLY      15																		//.#define BOARD_LCD_TIMING_VHDLY      2
/// Horizontal front porch in LCDDOTCLK cycles.																//./// Horizontal front porch in LCDDOTCLK cycles.
#define BOARD_LCD_TIMING_HFP        80//20																		//.#define BOARD_LCD_TIMING_HFP        5
/// Horizontal back porch in LCDDOTCLK cycles.																//./// Horizontal back porch in LCDDOTCLK cycles.
#define BOARD_LCD_TIMING_HBP        39																		//.#define BOARD_LCD_TIMING_HBP        5
/// Horizontal pulse width in LCDDOTCLK cycles.																//./// Horizontal pulse width in LCDDOTCLK cycles.
#define BOARD_LCD_TIMING_HPW        30																		//.#define BOARD_LCD_TIMING_HPW        5






//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK - Memories"
/// This page lists definitions related to external on-board memories.
///
/// !DDRAM
/// - BOARD_DDRAM_SIZE
/// - PINS_DDRAM
/// - BOARD_DDRAM_BUSWIDTH
/// - BOARD_SDRAM_BUSWIDTH
///
/// !Nandflash
/// - PINS_NANDFLASH
/// - BOARD_NF_EBI_COMMAND_ADDR
/// - BOARD_NF_EBI_ADDRESS_ADDR
/// - BOARD_NF_EBI_DATA_ADDR
/// - BOARD_NF_CE_PIN
/// - BOARD_NF_RB_PIN
///
/// !NorFlash
/// - BOARD_NORFLASH_ADDR
/// - BOARD_NORFLASH_DFT_BUS_SIZE
//

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM9G45-EK- Individual chip definition"
/// This page lists the definitions related to different chip's definition
/// located in the board.h file for the SAM9G45-EK.


/// USART
#define BOARD_PIN_USART_RXD_RS485        PIN_USART3_RXD
#define BOARD_PIN_USART_TXD_RS485        PIN_USART3_TXD
//#define BOARD_PIN_USART_CTS_RS485        PIN_USART1_CTS
#define BOARD_PIN_USART_RTS_RS485        PIN_USART3_RTS
#define BOARD_USART_BASE_RS485           AT91C_BASE_US3
#define BOARD_ID_USART_RS485             AT91C_ID_US3



//РўРµСЃС‚РѕРІС– РїС–РЅРё
#define PIN_TEST   {1 << 11, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT}

#endif //#ifndef BOARD_H

