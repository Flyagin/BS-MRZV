#include    "spi1.h"
#include "../LibG45/boards/bs_g45/board.h"
#include "../LibG45/peripherals/spi/spi.h" 
#include "../LibG45/peripherals/pio/pio.h"

#include "../LibG45/memories/spi-flash/spid.h"
#include "at25.h"
/// Pins used by SPI
/// SPI0 MISO pin definition.
#define PIN_SPI0_MISO  {1 << 0, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
/// SPI0 MOSI pin definition.
#define PIN_SPI0_MOSI  {1 << 1, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI0 SPCK pin definition.
#define PIN_SPI0_SPCK  {1 << 2, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI0 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI0      PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK
/// SPI0 chip select 0 pin definition.
#define PIN_SPI0_NPCS0 {1 << 3, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}



/*
#define SPI_DLYBCS(delay, masterClock) \
            ((unsigned int) (((masterClock / 1000000) * delay) / 1000) << 24)


#define RTC_SPI_SCBR        ((BOARD_MCK/9000000) <<  8) // (SPI) Serial Clock Baud Rate
#define RTC_SPI_DLYBS       (0x100 << 16) // (SPI) Delay Before SPCK
#define RTC_SPI_DLYBCT      (0xF << 24) // (SPI) Delay Between Consecutive Transfers

#define RTC_SPI1_SCBR       (SPI_SCBR(5000000,BOARD_MCK))
#define RTC_SPI1_DLYBS      (SPI_DLYBS(100,BOARD_MCK))
#define RTC_SPI1_DLYBCT     (SPI_DLYBCT(100,BOARD_MCK))

#define EPR01_SPI1_SCBR       (SPI_SCBR(5000000,BOARD_MCK))
#define EPR01_SPI1_DLYBS      (SPI_DLYBS(200,BOARD_MCK))
#define EPR01_SPI1_DLYBCT     (SPI_DLYBCT(200,BOARD_MCK))

#define EPR02_SPI1_SCBR       (SPID_CSR_SCBR  (BOARD_MCK,5000000))
#define EPR02_SPI1_DLYBS      (SPID_CSR_DLYBS (BOARD_MCK,200    ))
#define EPR02_SPI1_DLYBCT     (SPID_CSR_DLYBCT(BOARD_MCK,300     ))
*/
static const Pin pinsSPI0[]  = {PINS_SPI0 , PIN_SPI0_NPCS0};
/*
static const unsigned long arConfParam[] ={

((unsigned long)RTC_SPI_SCBR     ) ,//0   | 0x00000E00
((unsigned long)RTC_SPI_DLYBS    ) ,//1   | 0x01000000
((unsigned long)RTC_SPI_DLYBCT   ) ,//2   | 0x0F000000
((unsigned long)EPR01_SPI1_SCBR  ) ,//3   | 0x00000E00
((unsigned long)EPR01_SPI1_DLYBS ) ,//4   | 0x000D0000
((unsigned long)EPR01_SPI1_DLYBCT) ,//5   | 0x00000000
((unsigned long)EPR02_SPI1_SCBR  ) ,//6   | 0x00000E00
((unsigned long)EPR02_SPI1_DLYBS ) ,//7   | 0x000E0000
((unsigned long)EPR02_SPI1_DLYBCT) ,//8   | 0x01000000
((unsigned long)BOARD_MCK        )  //0x07F280D0
};
*/

#define BOARD_TSC_NPCS             2


#define DELAY_BEFORE_SPCK          (200 << 16) // 2us min (tCSS) <=> 200/100 000 000 = 2us
#define DELAY_BETWEEN_CONS_COM     (0xf << 24) // 5us min (tCSH) <=> (32 * 15) / (100 000 000) = 5us
void Spi0Init(void)
{
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;


// Configure pins
    PIO_Configure(pinsSPI0, PIO_LISTSIZE(pinsSPI0));
	/*
unnV1.ulVal = 	RTC_CS;	
unnV1.ulVal = 	(RTC_SPI1_DLYBS);
unnV1.ulVal = 	SPI_PCS(RTC_CS);
unnV1.ulVal |= AT91C_SPI_MSTR | AT91C_SPI_PS_FIXED |AT91C_SPI_MODFDIS ;
unnV1.ulVal |= 10<<24;
*/

 SPI_Configure(AT91C_BASE_SPI0,
                  AT91C_ID_SPI0,
                  AT91C_SPI_MODFDIS ); // Value of the SPI configuration register.
    

    SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,// BOARD_TSC_NPCS,
                     AT91C_SPI_CPOL|AT91C_SPI_BITS_16 // | (AT91C_SPI_DLYBS & DELAY_BEFORE_SPCK) |< AT91C_SPI_NCPHA |
                     /* (AT91C_SPI_DLYBCT & DELAY_BETWEEN_CONS_COM) | (0xC8 << 8)*/ );

    SPI_Enable(AT91C_BASE_SPI0);
	unnV1.ushAr[0] = 0;unnV1.ushAr[1] = 0x9483;
	//return;
	while(1)//unnV1.ushAr[0]!=0x2875)
	{
		unnV1.ushAr[0] = SPI_Read(AT91C_BASE_SPI0);
		SPI_Write(AT91C_BASE_SPI0,(unsigned int) 0,(unsigned short)unnV1.ushAr[1]);//Write 1 byte
	}
	//Channel Syncronize
	//Init PDC
}
    
	
/*
//.PIO_Configure(pinBusy, PIO_LISTSIZE(pinBusy));
    SPI_Configure(AT91C_BASE_SPI0,
                  AT91C_ID_SPI0,
                  AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | SPI_PCS(BOARD_TSC_NPCS) // Value of the SPI configuration register.
    );

    SPI_ConfigureNPCS(AT91C_BASE_SPI0, BOARD_TSC_NPCS,
                      AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DELAY_BEFORE_SPCK) |
                      (AT91C_SPI_DLYBCT & DELAY_BETWEEN_CONS_COM) | (0xC8 << 8) );

    SPI_Enable(AT91C_BASE_SPI0);
*/
void Spi0Test(void)
{
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
struct 
	{
		
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		short shVal;
		unsigned long nVal;  
		//.void *pvOrCurSC1;
		//.void *pvOrCurSC2;
		//.void *pvOrSC;

	} sLV;		
sLV.nVal = 	RTC_CS;
//unnV1.ulVal = (RTC_SPI1_SCBR)  ;
//unnV1.ulVal = (RTC_SPI1_DLYBS) ;
//unnV1.ulVal = (RTC_SPI1_DLYBCT);
SPI_Disable(AT91C_BASE_SPI0);
/*
	SPI_ConfigureNPCS(AT91C_BASE_SPI1, RTC_CS,0
                       |(RTC_SPI1_SCBR)
					   |(RTC_SPI1_DLYBS)
					   |(RTC_SPI1_DLYBCT)
					   );*/
SPI_Enable(AT91C_BASE_SPI0);					   
//AT91C_SPI_LASTXFER  AT91C_SPI_CSAAT
//unnV1.ulVal = SPI_PCS(RTC_CS);
//.unnV1.ulVal = (RTC_SPI1_SCBR)  ;
//.unnV1.ulVal = (RTC_SPI1_DLYBS) ;
//.unnV1.ulVal = (RTC_SPI1_DLYBCT);
//sLV.nVal = RTC_CS;
sLV.uChIdxBit = 0;
do
{
sLV.shVal = 0x80|0x19;
//SPI_Write(AT91C_BASE_SPI0,(unsigned int) sLV.nVal,(unsigned short) sLV.shVal);//Write 1 byte
//...AT91C_BASE_SPI1->SPI_CR  |= AT91C_SPI_LASTXFER;
sLV.shVal = 0x0|5;
//SPI_Write(AT91C_BASE_SPI0,(unsigned int) sLV.nVal,(unsigned short) sLV.shVal);//Write 1 byte

//~}
//~while (sLV.uChIdxBit);
//~do
//~{
//Read Answer
sLV.shVal = 0x0|0x19;
//SPI_Write(AT91C_BASE_SPI0,(unsigned int) sLV.nVal,(unsigned short) sLV.shVal);//Write 1 byte
//unsigned short SPI_Read(AT91S_SPI *spi)


//Write 1 byte
sLV.shVal = 0x0|6;
//SPI_Write(AT91C_BASE_SPI0,(unsigned int) sLV.nVal,(unsigned short) sLV.shVal);//Write 1 byte
unnV1.ushAr[0] = SPI_Read(AT91C_BASE_SPI1);


sLV.uChIdxByte = unnV1.uchAr [0];
}
while (sLV.uChIdxBit);
}





