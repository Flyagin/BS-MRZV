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
/// Interface for configuration the LCD Controller (LCDC) peripheral.
///
/// !Usage
///
/// -# Decode the RGB file to designated buffer using LCD_DecodeRGB().
/// -# Sets the address of the frame buffer in the LCD controller DMA using
/// LCD_SetFrameBufferAddress().
/// -# LCD Configuration functions prefixed with "LCD_Set" refer to 
/// the functions in the #Overview# tab.
/// 
/// Please refer to the list of functions in the #Overview# tab of this unit
/// for more detailed information.
//------------------------------------------------------------------------------

#ifndef LCD_H
#define LCD_H

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

extern void LCD_BOARD_Enable(unsigned int frames);

extern void LCD_BOARD_Disable(unsigned int frames);

extern void LCD_BOARD_EnableDma(void);

extern void LCD_BOARD_DisableDma(void);

extern void LCD_BOARD_EnableInterrupts(unsigned int sources);

extern void LCD_BOARD_SetPixelClock(unsigned int masterClock, unsigned int pixelClock);

extern void LCD_BOARD_SetDisplayType(unsigned int displayType);

extern void LCD_BOARD_SetScanMode(unsigned int scanMode);

extern void LCD_BOARD_SetBitsPerPixel(unsigned int bitsPerPixel);

extern void LCD_BOARD_SetPolarities(
    unsigned int lcdd,
    unsigned int lcdvsync,
    unsigned int lcdhsync,
    unsigned int lcddotclk,
    unsigned int lcdden);

extern void LCD_BOARD_SetClockMode(unsigned int clockMode);

extern void LCD_BOARD_SetMemoryFormat(unsigned int format);

extern void LCD_BOARD_SetSize(unsigned int width, unsigned int height);

extern void LCD_BOARD_SetVerticalTimings(
    unsigned int vfp,
    unsigned int vbp,
    unsigned int vpw,
    unsigned int vhdly);

extern void LCD_BOARD_SetHorizontalTimings(
    unsigned int hbp,
    unsigned int hpw,
    unsigned int hfp);

extern void* LCD_BOARD_SetFrameBufferAddress(void *address);

extern void LCD_BOARD_SetFrameSize(unsigned int frameSize);

extern void LCD_BOARD_SetBurstLength(unsigned int burstLength);

extern void LCD_BOARD_SetContrastPrescaler(unsigned int prescaler);

extern void LCD_BOARD_SetContrastPolarity(unsigned int polarity);

extern void LCD_BOARD_SetContrastValue(unsigned int value);

extern void LCD_BOARD_EnableContrast(void);

extern void LCD_BOARD_SetPixelClock(unsigned int masterClock, unsigned int pixelClock);

extern void LCD_BOARD_DMAReset(void);

extern void LCD_BOARD_DecodeRGB(
    unsigned char *file,
    unsigned char *bufferLCD,
    unsigned int width,
    unsigned int height,
    unsigned char bpp);

#endif //#ifndef LCD_H
