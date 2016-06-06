void LCD_X_Config(void)
{
//
// Set display driver and color conversion
//GUIDRV_LIN_24 24bpp, default orientation
//GUICC_M666, 18 bpp, red and blue swapped

GUI_DEVICE_CreateAndLink(GUIDRV_LIN_24 , // Display driver 
GUICC_M666, // Color conversion
0, 0);
LCD_SetSizeEx (0, 320, 240); // Physical display size in pixels
LCD_SetVSizeEx (0, 320, 480); // Virtual display size in pixels
LCD_SetVRAMAddrEx(0, (void *)0x20000000); // Video RAM start address
}