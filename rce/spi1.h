#ifndef SPI1_h
#define SPI1_h

//.SPI0 SPI0_MISO  PB0 A
//.SPI0 SPI0_MOSI  PB1 A
//.SPI0 SPI0_NPCS0 PB3 A
//.SPI0 SPI0_NPCS1 PB18 B
//.SPI0 SPI0_NPCS1 PD24 A
//.SPI0 SPI0_NPCS2 PB19 B
//.SPI0 SPI0_NPCS2 PD25 A
//.SPI0 SPI0_NPCS3 PD27 B
//.SPI0 SPI0_SPCK  PB2 A
//.SPI1 SPI1_MISO  PB14 A
//.SPI1 SPI1_MOSI  PB15 A
//.SPI1 SPI1_NPCS0 PB17 A
//.SPI1 SPI1_NPCS1 PD28 B
//.SPI1 SPI1_NPCS2 PD18 A
//.SPI1 SPI1_NPCS3 PD19 A
//.SPI1 SPI1_SPCK  PB16 A
#define SPI0_MISO   (1<< 0 )
#define SPI0_MOSI   (1<< 1 )
#define SPI0_NPCS0  (1<< 3 )
//.#define SPI0_NPCS1  (1<< 28)
//.#define SPI0_NPCS2  (1<< 18)
//.#define SPI0_NPCS3  (1<< 19)
#define SPI0_SPCK   (1<< 2)

#define SPI1_MISO   (1<< 14)
#define SPI1_MOSI   (1<< 15)
#define SPI1_NPCS0  (1<< 17)
#define SPI1_NPCS1  (1<< 28)
#define SPI1_NPCS2  (1<< 18)
#define SPI1_NPCS3  (1<< 19)
#define SPI1_SPCK   (1<< 16)

#define RTC_CS   (0)
#define EPR_CS   (1)
#define DREC_CS  (2)
#define AREC_CS  (3)
//BOARD_MCK/10000000

//.#define AT91C_SPI_SCBR        (0xFF <<  8) // (SPI) Serial Clock Baud Rate
//.#define AT91C_SPI_DLYBS       (0xFF << 16) // (SPI) Delay Before SPCK
//.#define AT91C_SPI_DLYBCT      (0xFF << 24) // (SPI) Delay Between Consecutive Transfers
/*
//------------------------------------------------------------------------------
//         Macros
//------------------------------------------------------------------------------

/// Calculates the value of the SCBR field of the Chip Select Register given
/// MCK and SPCK.
#define SPID_CSR_SCBR(mck, spck)    ((((mck) / (spck)) << 8) & AT91C_SPI_SCBR)

/// Calculates the value of the DLYBS field of the Chip Select Register given
/// the delay in ns and MCK.
#define SPID_CSR_DLYBS(mck, delay) \
    ((((((delay) * ((mck) / 1000000)) / 1000) + 1)  << 16) & AT91C_SPI_DLYBS)

/// Calculates the value of the DLYBCT field of the Chip Select Register given
/// the delay in ns and MCK.
#define SPID_CSR_DLYBCT(mck, delay) \
    ((((((delay) / 32 * ((mck) / 1000000)) / 1000) + 1) << 24) & AT91C_SPI_DLYBCT)
	
*/	
#endif // SPI1_h


