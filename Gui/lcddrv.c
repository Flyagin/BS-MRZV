#include "header_mal.h"

#include "lcddrv.h"//put part for  PIOs
#include "../LibG45/boards/bs_g45/board.h"
#include "../LibG45/peripherals/lcd/lcd.h" // AT91C_BASE_PIOE


#include "../LibG45/peripherals/pio/pio.h"

#define BS_PIN_PCK0 {(unsigned int)(1 << 31), AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
#define BS_PIN_PCK1 {(unsigned int)(1 << 31), AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}


#define BS_PIN_LCD_09   {M_R_0   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}   
#define BS_PIN_LCD_10   {M_R_1   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_11   {M_R_2   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_12   {M_R_3   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_13   {M_R_4   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_14   {M_R_5   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_17   {M_G_0   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_18   {M_G_1   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_19   {M_G_2   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_20   {M_G_3   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_21   {M_G_4   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_22   {M_G_5   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_25   {M_B_0   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_26   {M_B_1   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_27   {M_B_2   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_28   {M_B_3   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_29   {M_B_4   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_30   {M_B_5   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_06   {M_DEN   , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_04   {M_HSYNC , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_03   {M_VSYNC , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_05   {M_DCLK  , AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
#define BS_PIN_LCD_00   {M_LCDPWR, AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}  
//#define BS_PIN_LCD_x {1 << xx, AT91C_BASE_PIOE, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}




static const Pin pinsPCK[]  = {BS_PIN_PCK0 , BS_PIN_PCK1};

static const Pin BSpinsLCD[] = {
BS_PIN_LCD_09,
BS_PIN_LCD_10,
BS_PIN_LCD_11,
BS_PIN_LCD_12,
BS_PIN_LCD_13,
BS_PIN_LCD_14,
BS_PIN_LCD_17,
BS_PIN_LCD_18,
BS_PIN_LCD_19,
BS_PIN_LCD_20,
BS_PIN_LCD_21,
BS_PIN_LCD_22,
BS_PIN_LCD_25,
BS_PIN_LCD_26,
BS_PIN_LCD_27,
BS_PIN_LCD_28,
BS_PIN_LCD_29,
BS_PIN_LCD_30,
BS_PIN_LCD_06,
BS_PIN_LCD_04,
BS_PIN_LCD_03,
BS_PIN_LCD_05,
BS_PIN_LCD_00


};

#define DDR2_B3_DATA _Pragma("location=\"DDR2_Bank3_variables\"")

DDR2_B3_DATA unsigned long lcd_buf       [ BOARD_LCD_FRAMESIZE*3  ]; //Block memory regulary output on LCD
//unsigned long shadow_lcd_buf[ BOARD_LCD_FRAMESIZE  ];
/// Primary display buffer.
unsigned char *primaryBuffer = (unsigned char *) lcd_buf;//(IMAGE_BUF_BASE_ADDR + 0x00010000);

/// Back buffer (for double-buffering).
unsigned char *backBuffer = (unsigned char *) lcd_buf;//shadow_lcd_buf;//(IMAGE_BUF_BASE_ADDR + 0x00100000);


//char chIdxBuf;
char* pLcdOutBuf;

 static const Pin pinsLCD[] = {PINS_LCD};
void ConfigurePinsLcd(void)
{
   
    //PIO_Configure(pins, PIO_LISTSIZE(pins));
	PIO_Configure( BSpinsLCD, PIO_LISTSIZE( BSpinsLCD));
	//~.PIO_Configure(pinsPCK, PIO_LISTSIZE(pinsPCK));
	//~.AT91C_BASE_PMC->PMC_PCKR[0] = AT91C_PMC_SLCKMCK_MCK;
	//~.AT91C_BASE_PMC->PMC_PCKR[1] = AT91C_PMC_SLCKMCK_MCK;
	//~.AT91C_BASE_PMC->PMC_SCER = (AT91C_PMC_PCK0)|(AT91C_PMC_PCK1);
	//~.while(1);
	//AT91C_BASE_PMC->PMC_PCER = 1 << (AT91C_ID_PIOA);
}

//==================================================================================
//Body func                                                              
//==================================================================================
void StartUPInitLCD(void)
{
register long i,j;
//.register unsigned long lrVal;
//.register void *pv;
//.struct 
//.	{
//.		//short         shCountCmd;  
//.		unsigned char uChIdxByte ;
//.		unsigned char uChIdxBit ;
//.		short shVal;
//.		//unsigned short ushBeg,ushEnd;
//.		void *pvOr;
//.		
//.	} sLV;	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Init Peripheral         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
AT91C_BASE_PMC->PMC_PCER = 1 << (AT91C_ID_PIOA);

	AT91C_BASE_PIOA->PIO_ODR   = (unsigned long)FUV;
	AT91C_BASE_PIOA->PIO_CODR  = (unsigned long)FUV;
	AT91C_BASE_PIOA->PIO_IFER  = (unsigned long)FUV;

//OUTPUT
	// PIOB_BASE->PIO_ODR   = COLUMNS_MASK;
	AT91C_BASE_PIOA->PIO_OER   = (unsigned long)( (SCAN_RL) | (SCAN_UD) |(SHDN_LCD) );
	AT91C_BASE_PIOA->PIO_CODR  = (unsigned long)( (SCAN_RL) | (SCAN_UD) |(SHDN_LCD) );
	
//	PIO Init
    AT91C_BASE_PIOA->PIO_IDR   = (unsigned long)(FUV |( (SCAN_RL) | (SCAN_UD) |(SHDN_LCD) ));
    AT91C_BASE_PIOA->PIO_MDDR  = (unsigned long)(FUV |( (SCAN_RL) | (SCAN_UD) |(SHDN_LCD) ));
	
	AT91C_BASE_PIOA->PIO_SODR  = (unsigned long)SHDN_LCD;
	
    AT91C_BASE_PIOA->PIO_PER   = (unsigned long)(FUV |( (SCAN_RL) | (SCAN_UD) |(SHDN_LCD) ));
	AT91C_BASE_PIOA->PIO_SODR  = (unsigned long)SHDN_LCD;

AT91C_BASE_PMC->PMC_PCER = 1 << (AT91C_ID_LCDC);
//AT91C_BASE_PMC->PMC_SCER = AT91C_PMC_HCK1;
//	PIO Init


AT91C_BASE_PMC->PMC_PCER = 1 << (AT91C_ID_PIOD_E);

ConfigurePinsLcd();

AT91C_BASE_PIOE->PIO_ASR  = LCD_PERIPH_A_PINS;
AT91C_BASE_PIOE->PIO_PDR  = LCD_PERIPH_A_PINS;

//memset(primaryBuffer, 0x0, BOARD_LCD_FRAMESIZE*4 );
for (i = 0; i < ((4*BOARD_LCD_FRAMESIZE)-9) ; i+=3)
{
	primaryBuffer[i+0] = 0;//xf<<2;
	primaryBuffer[i+1] = 0;//x3f<<2;//0;//
	primaryBuffer[i+2] = 0x1f<<2;//0;//
	primaryBuffer[i+3] = 0;

}
/*
for (i = 0,j =(1*BOARD_LCD_FRAMESIZE)/3; i < j ; i+=3)
//for (i = 0; i < BOARD_LCD_FRAMESIZE ; i+=4)
{
	primaryBuffer[i+0] = 0;//x7<<3;
	primaryBuffer[i+1] = 0;//0x7<<3;
	primaryBuffer[i+2] = 0xf<<2;
	//primaryBuffer[i+3] = 0;

}

for (i = (1*BOARD_LCD_FRAMESIZE)/3,j =(2*BOARD_LCD_FRAMESIZE)/3; i < j ; i+=3)
//for (i = 0,j =4*3200/3; i < j ; i+=3)
{
	primaryBuffer[i+0] = 0;//0x7<<3;
	primaryBuffer[i+1] = 0x7<<2;
	primaryBuffer[i+2] = 0x0;
	//primaryBuffer[i+3] = 0;

}
for (i = (2*BOARD_LCD_FRAMESIZE)/3,j =(4*BOARD_LCD_FRAMESIZE); i < j ; i+=3)
//for (i = 0,j =4*3200/3; i < j ; i+=3)
{
	primaryBuffer[i+0] = 0x7<<2;
	primaryBuffer[i+1] = 0;//0x7<<3;
	primaryBuffer[i+2] = 0;//0x7<<3;//0x0;
	//primaryBuffer[i+3] = 0;

}
*/


//.memset(backBuffer, 0x45, BOARD_LCD_FRAMESIZE * 4);
// Disable the LCD and the DMA
LCD_BOARD_DisableDma();//  Disables the DMA of the LCD controller.
LCD_BOARD_Disable(0);
//./ Disables the LCD controller, after waiting for the specified number of
//./ frames.
//./ \param frames  Number of frames before the LCD is shut down.


// Configure the LCD controller

LCD_BOARD_SetPixelClock(BOARD_MCK, 6400000);
LCD_BOARD_SetPixelClock( ((BOARD_MCK*3)>>1)-(BOARD_MCK>>16) , BOARD_LCD_PIXELCLOCK);
//./ Configures the internal clock of the LCD controller given the master clock of
//./ the system and the desired pixel clock in MHz.
//./ \param masterClock  Master clock frequency.
//./ \param pixelClock  Pixel clock frequency.

LCD_BOARD_SetDisplayType(BOARD_LCD_DISPLAYTYPE);
//./ Sets the type of display used with the LCD controller.
//./ \param displayType  Type of display used.
LCD_BOARD_SetScanMode(AT91C_LCDC_SCANMOD_SINGLESCAN);
//./ Sets the scan mode used by the LCD (either single scan or double-scan).
//./ \param scanMode  Scan mode to use.

LCD_BOARD_SetBitsPerPixel((0x5 <<  5));//BOARD_LCD_BPP);
//./ Sets the number of bits per pixel used by the LCD display.
//./ \param bitsPerPixel  Number of bits per pixel to use.
LCD_BOARD_SetPolarities(BOARD_LCD_POLARITY_INVVD,
                  BOARD_LCD_POLARITY_INVFRAME,
                  BOARD_LCD_POLARITY_INVLINE,
                  BOARD_LCD_POLARITY_INVCLK,
                  BOARD_LCD_POLARITY_INVDVAL); 
//./ Sets the LCDD, LCDVSYNC, LCDHSYNC, LCDDOTCLK and LCDDEN signal polarities.
//./ \param lcdd  LCDD signal polarity.
//./ \param lcdvsync  LCDVSYNC signal polarity.
//./ \param lcdhsync  LCDHSYNC signal polarity.
//./ \param lcddotclk  LCDDOTCLK signal polarity.
//./ \param lcdden  LCDDEN signal polarity.				  
LCD_BOARD_SetClockMode(BOARD_LCD_CLOCKMODE);
//./ Sets the LCD clock mode, i.e. always active or active only during display
//./ period.
//./ \param clockMode  Clock mode to use.
LCD_BOARD_SetMemoryFormat((unsigned int) AT91C_LCDC_MEMOR_LITTLEIND);
//./ Sets the format of the frame buffer memory.
//./ \param format  Memory ordering format.
LCD_BOARD_SetSize(BOARD_LCD_WIDTH, BOARD_LCD_HEIGHT);
//./ Sets the size in pixel of the LCD display.
//./ \param width  Width in pixel of the LCD display.
//./ \param height  Height in pixel of the LCD display.

// Configure timings
LCD_BOARD_SetVerticalTimings(/*BOARD_LCD_TIMING_VFP*/12,
                       /*BOARD_LCD_TIMING_VBP*/23,
                       /*BOARD_LCD_TIMING_VPW*/3,
                       /*BOARD_LCD_TIMING_VHDLY*/2);
//./ Sets the vertical timings of the LCD controller. Only meaningful when
//./ using a TFT display.
//./ \param vfp  Number of idle lines at the end of a frame.
//./ \param vbp  Number of idle lines at the beginning of a frame.
//./ \param vpw  Vertical synchronization pulse width in number of lines.
//./ \param vhdly  Delay between LCDVSYNC edge and LCDHSYNC rising edge, in
//./               LCDDOTCLK cycles.					   
AT91C_BASE_LCDC->LCDC_TIM1 |= 0x80000000;
LCD_BOARD_SetHorizontalTimings(/*BOARD_LCD_TIMING_HBP*/38,
                         /*BOARD_LCD_TIMING_HPW*/30,
                         /*BOARD_LCD_TIMING_HFP*/20);
//./ Sets the horizontal timings of the LCD controller. Meaningful for both
//./ STN and TFT displays.
//./ \param hbp  Number of idle LCDDOTCLK cycles at the beginning of a line.
//./ \param hpw  Width of the LCDHSYNC pulse, in LCDDOTCLK cycles.
//./ \param hfp  Number of idel LCDDOTCLK cycles at the end of a line.
// Configure contrast (TODO functions)
LCD_BOARD_SetContrastPrescaler(AT91C_LCDC_PS_NOTDIVIDED);
//./ Sets the prescaler value of the contrast control PWM.
//./ \param prescaler  Desired prescaler value.
LCD_BOARD_SetContrastPolarity(AT91C_LCDC_POL_POSITIVEPULSE);
//./ Sets the polarity of the contrast PWM.
//./ \param polarity  PWM polarity
LCD_BOARD_SetContrastValue(0x80);
//./ Sets the threshold value of the constrast PWM.
//./ \param value  PWM threshold value.
// LCD_EnableContrast();//./ Enables the contrast PWM generator.

// Configure DMA
i = ( long)BOARD_LCD_FRAMESIZE;
LCD_BOARD_SetFrameSize((unsigned int)i>>0);//i>>4,3,2
//./ Sets the size in pixels of a frame (height * width * bpp).
//./ \param frameSize  Size of frame in pixels.
LCD_BOARD_SetBurstLength(4);//4
//./ Sets the DMA controller burst length.
//./ \param burstLength  Desired burst length.
i = ( long)primaryBuffer;
// Set frame buffer
LCD_BOARD_SetFrameBufferAddress((void *)i);//primaryBuffer
//./ Sets the address of the frame buffer in the LCD controller DMA. When using
//./ dual-scan mode, this is the upper frame buffer.
//./ \param address  Frame buffer address.
AT91C_BASE_LCDC->LCDC_IER = (AT91C_LCDC_EOFI)/*|(AT91C_LCDC_UFLWI)|(AT91C_LCDC_OWRI)|( AT91C_LCDC_MERI)*/;

IRQ_ConfigureIT(AT91C_ID_LCDC, AT91C_AIC_PRIOR_LOWEST, LCD_IrqHandler);
AT91C_BASE_AIC->AIC_IECR = 1 << AT91C_ID_LCDC;


AT91C_BASE_LCDC->LCDC_DMA2DCFG = 0;
// Enable DMA and LCD
LCD_BOARD_EnableDma();//./ Enables the DMA of the LCD controller.

LCD_BOARD_Enable(0x0C);//C);
//./ Enables the LCD controller, after waiting for the specified number of
//./ frames.
//./ \param frames  Number of frames before the LCD is enabled.


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
}
//-----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
//==================================================================================
//Body func                                                              
//==================================================================================
void Power_ON_LCD(void)
{
//register long i;
register unsigned long lrVal;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Control RESET         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    SET ~SHDN_LCD        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
AT91C_BASE_PIOA->PIO_SODR  = (unsigned long)SHDN_LCD;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Sleep 0.5 c        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
lrVal = 0x500000;
while(lrVal--) ;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Control ~FUV         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Enable Data         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
LCD_BOARD_DMAReset();
while((AT91C_BASE_LCDC->LCDC_DMACON & AT91C_LCDC_DMABUSY) == AT91C_LCDC_DMABUSY )
;
LCD_BOARD_EnableDma();
//while( (AT91C_BASE_LCDC->LCDC_PWRCON & AT91C_LCDC_BUSY) == AT91C_LCDC_BUSY )
;
LCD_BOARD_Enable(0x0C);

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    sleep 0,1c         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
lrVal = 0x100000;
while(lrVal--) ;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    RESET ~SHDN_LCD        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
AT91C_BASE_PIOA->PIO_CODR  = (unsigned long)SHDN_LCD;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
		
}
//-----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
//==================================================================================
//Body func                                                              
//==================================================================================
void Power_OFF_LCD(void)
{
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Control ~FUV         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    SET ~SHDN_LCD        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Sleep 0.1 c        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""






//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Disable Data         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
LCD_BOARD_DMAReset();
while((AT91C_BASE_LCDC->LCDC_DMACON & AT91C_LCDC_DMABUSY) == AT91C_LCDC_DMABUSY )
;
LCD_BOARD_DisableDma();

//while( (AT91C_BASE_LCDC->LCDC_PWRCON & AT91C_LCDC_BUSY) == AT91C_LCDC_BUSY );
LCD_BOARD_Disable(0x0C);

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    sleep 0,1c         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


		
}
//-----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
//==================================================================================
//Body func                                                              
//==================================================================================
void ON_BackLight(void)
{
register unsigned long lrVal;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Enable Data         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
LCD_BOARD_Disable(0x0C);
while( (AT91C_BASE_LCDC->LCDC_PWRCON & AT91C_LCDC_BUSY) == AT91C_LCDC_BUSY )
;
LCD_BOARD_DMAReset1();
while((AT91C_BASE_LCDC->LCDC_DMACON & AT91C_LCDC_DMABUSY) == AT91C_LCDC_DMABUSY )
;

/*MTO*/
AT91C_BASE_AIC->AIC_IECR = 1 << AT91C_ID_LCDC;
/***/

LCD_BOARD_EnableDma();
while((AT91C_BASE_LCDC->LCDC_DMACON & AT91C_LCDC_DMABUSY) == AT91C_LCDC_DMABUSY )
;
//while( (AT91C_BASE_LCDC->LCDC_PWRCON & AT91C_LCDC_BUSY) == AT91C_LCDC_BUSY )
;

LCD_BOARD_Enable(0x0C);


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    sleep 0,1c         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
lrVal = 0x100000;
while(lrVal--) ;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    RESET ~SHDN_LCD        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//AT91C_BASE_PIOA->PIO_SODR  = (unsigned long)SHDN_LCD;
AT91C_BASE_PIOA->PIO_CODR  = (unsigned long)SHDN_LCD; //цвет дисплея устанавливается в красный
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
	
}
//-----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
//==================================================================================
//Body func                                                              
//==================================================================================
void OFF_BackLight(void)
{
register unsigned long lrVal;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    SET ~SHDN_LCD        ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//AT91C_BASE_PIOA->PIO_CODR  = (unsigned long)SHDN_LCD;
AT91C_BASE_PIOA->PIO_SODR  = (unsigned long)SHDN_LCD;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    sleep 0,1c         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
lrVal = 0x100000;
while(lrVal--) ; 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Disable Data         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

/*MTO*/
AT91C_BASE_AIC->AIC_IDCR = 1 << AT91C_ID_LCDC;
/***/

LCD_BOARD_DisableDma();
while((AT91C_BASE_LCDC->LCDC_DMACON & AT91C_LCDC_DMABUSY) == AT91C_LCDC_DMABUSY )
;
LCD_BOARD_DMAReset();

//while( (AT91C_BASE_LCDC->LCDC_PWRCON & AT91C_LCDC_BUSY) == AT91C_LCDC_BUSY )
;

LCD_BOARD_Disable(0x0C);

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

}
//-----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////
void ChangeOrient(void)
{
//.AT91C_BASE_PIOA->PIO_CODR = SCAN_RL;
//.AT91C_BASE_PIOA->PIO_CODR = SCAN_UD;
      
    AT91C_BASE_PIOA->PIO_CODR = SCAN_RL;//-  Real Normal Orientation 
    AT91C_BASE_PIOA->PIO_SODR = SCAN_UD;
    //  
//    AT91C_BASE_PIOA->PIO_CODR = SCAN_UD;  //Current work Regime
//    AT91C_BASE_PIOA->PIO_SODR = SCAN_RL;  //Current work Regime
    //  
    //AT91C_BASE_PIOA->PIO_SODR = SCAN_RL;
    //AT91C_BASE_PIOA->PIO_SODR = SCAN_UD;  
      
}
void ControlDma(void)
{
	register unsigned long rV;
	rV = AT91C_BASE_LCDC->LCDC_ISR;
	
	
	if (rV)//&(AT91C_LCDC_EOFI))
	{
		AT91C_BASE_LCDC-> LCDC_ICR = rV;
		switch (rV)
		{
		case (AT91C_LCDC_EOFI):
			rV = AT91C_LCDC_EOFI;
			break;
		case (AT91C_LCDC_UFLWI):
			rV = AT91C_LCDC_UFLWI;
			break;
		case (AT91C_LCDC_OWRI):
			rV = AT91C_LCDC_OWRI;
			break;
		case (AT91C_LCDC_MERI):
			rV = AT91C_LCDC_MERI;
			break;
		
		default:
		AT91C_BASE_LCDC-> LCDC_ICR = AT91C_LCDC_MERI;
		}




 //
	}
	
	
      
}

#include "test.c"


