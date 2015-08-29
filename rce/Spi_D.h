#ifndef SPI_D_h
#define SPI_D_h

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

/// An unspecified error has occured.
#define SPI_D_ERROR          1

/// SPI driver is currently in use.
#define SPI_D_ERROR_LOCK     2

//------------------------------------------------------------------------------
//         Macros
//------------------------------------------------------------------------------

//./ Calculates the value of the SCBR field of the Chip Select Register given
//./ MCK and SPCK.
#define SPID_CSR_SCBR(mck, spck)    ((((mck) / (spck)) << 8) & AT91C_SPI_SCBR)

//./ Calculates the value of the DLYBS field of the Chip Select Register given
//./ the delay in ns and MCK.
#define SPID_CSR_DLYBS(mck, delay) \
    ((((((delay) * ((mck) / 1000000)) / 1000) + 1)  << 16) & AT91C_SPI_DLYBS)

//./ Calculates the value of the DLYBCT field of the Chip Select Register given
//./ the delay in ns and MCK.
#define SPID_CSR_DLYBCT(mck, delay) \
    ((((((delay) / 32 * ((mck) / 1000000)) / 1000) + 1) << 24) & AT91C_SPI_DLYBCT)

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

//./ SPI transfer complete callback.
typedef void (*SpiDCallback )(unsigned char, void *);

//------------------------------------------------------------------------------
//./ Spi Transfer Request prepared by the application upper layer. This structure
//./ is sent to the SPI_SendCommand function to start the transfer. At the end of 
//./ the transfer, the callback is invoked by the interrupt handler.
//------------------------------------------------------------------------------
typedef struct _SpiDCmd {

    //./ Pointer to the command data.
	unsigned char *pCmd;
    //./ Command size in bytes.
	unsigned char cmdSize;
    //./ Pointer to the data to be sent.
	unsigned char *pData;
    //./ Data size in bytes.
	unsigned short dataSize;
    //./ SPI chip select.
	unsigned char spiCs;
    //./ Callback function invoked at the end of transfer.
	SpiDCallback callback;
    //./ Callback arguments.
	void *pArgument;

} SpiDCmd;

//------------------------------------------------------------------------------
//./ Constant structure associated with SPI port. This structure prevents
//./ client applications to have access in the same time.
//------------------------------------------------------------------------------
typedef struct {

    //./ Pointer to SPI Hardware registers
	AT91S_SPI *pSpiHw;
    //./ SPI Id as defined in the product datasheet
	char spiId;
    //./ Current SpiCommand being processed
	SpiDCmd *pCurrentCommand;
    //./ Mutual exclusion semaphore.
	volatile char semaphore;

} SpiD;

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

extern unsigned char SPI_D_Configure(
    SpiD *pSpiD,
    AT91S_SPI *pSpiHw,
    unsigned char spiId);

extern void SPI_D_ConfigureCS(SpiD *pSpiD, unsigned char cs, unsigned int csr);
	
extern unsigned char SPI_D_SendCommand(
	SpiD *pSpiD,
	SpiDCmd *pCommand);

extern void SPI_D_Handler(SpiD *pSpiD);

extern unsigned char SPI_D_IsBusy(const SpiD *pSpiD);

#endif // SPI _D_h
