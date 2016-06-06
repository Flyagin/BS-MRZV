#include "header_mal.h"
#include <lcd/lcd.h>


/***********************************************************************************
Переривання від LCD peripherals
***********************************************************************************/
void LCD_IrqHandler(void)
{
  register unsigned long status= AT91C_BASE_LCDC->LCDC_ISR;
  AT91C_BASE_LCDC-> LCDC_ICR = status;
  
  if ((status & AT91C_LCDC_EOFI) != 0)
  {
    unsigned long Addr, BufferSize;
    if (_PendingBuffer >= 0) 
    {
      //
      // Calculate address of the given buffer
      //
      BufferSize = (BOARD_LCD_FRAMESIZE_PIXELS) / 8;
      Addr       = (unsigned long)lcd_buf + BufferSize * _PendingBuffer;
      //
      // Make the given buffer visible
      //
      LCD_BOARD_SetFrameBufferAddress((void *)Addr);
      //
      // Send a confirmation that the buffer is visible now
      //
      GUI_MULTIBUF_Confirm(_PendingBuffer);
      _PendingBuffer = -1;
    }
  }
}
/***********************************************************************************/
