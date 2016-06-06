//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "Spi_D.h"
#include <board.h>
#if !defined(SPI_USE_DMA)
//------------------------------------------------------------------------------
//         Macros
//------------------------------------------------------------------------------

//./ Write PMC register
#define WRITE_PMC(pPmc, regName, value) pPmc->regName = (value)

//./ Write SPI register
#define WRITE_SPI(pSpi, regName, value) pSpi->regName = (value)

//./ Read SPI registers
#define READ_SPI(pSpi, regName) (pSpi->regName)

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//./ Initializes the Spid structure and the corresponding SPI hardware.
//./ Always returns 0.
//./ \param pSpid  Pointer to a Spid instance.
//./ \param pSpiHw  Associated SPI peripheral.
//./ \param spiId  SPI peripheral identifier.
//------------------------------------------------------------------------------
unsigned char SPI_D_Configure(SpiD *pSpiD, AT91S_SPI *pSpiHw, unsigned char spiId)
{
    // Initialize the SPI structure
    pSpiD->pSpiHw = pSpiHw;
    pSpiD->spiId  = spiId;
    pSpiD->semaphore = 1;
    pSpiD->pCurrentCommand = 0;

    // Enable the SPI clock
    WRITE_PMC(AT91C_BASE_PMC, PMC_PCER, (1 << pSpiD->spiId));
    
    // Execute a software reset of the SPI twice
    WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SWRST);
    WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SWRST);

    // Configure SPI in Master Mode with No CS selected !!!
    WRITE_SPI(pSpiHw, SPI_MR, AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | AT91C_SPI_PCS);
     
    // Disable the PDC transfer    
    //~.WRITE_SPI(pSpiHw, SPI_PTCR, AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS);

    // Enable the SPI
    WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SPIEN);

    // Enable the SPI clock
    WRITE_PMC(AT91C_BASE_PMC, PMC_PCDR, (1 << pSpiD->spiId));
    
    return 0;
}

//------------------------------------------------------------------------------
//./ Configures the parameters for the device corresponding to the cs.
//./ \param pSpid  Pointer to a Spid instance.
//./ \param cs  number corresponding to the SPI chip select.
//./ \param csr  SPI_CSR value to setup.
//------------------------------------------------------------------------------
void SPI_D_ConfigureCS(SpiD *pSpiD, unsigned char cs, unsigned int csr)
{
    AT91S_SPI *pSpiHw = pSpiD->pSpiHw;
    WRITE_SPI(pSpiHw, SPI_CSR[cs], csr);
}
    
//------------------------------------------------------------------------------
//./ Starts a SPI master transfer. This is a non blocking function. It will
//./ return as soon as the transfer is started.
//./ Returns 0 if the transfer has been started successfully; otherwise returns
//./ SPID_ERROR_LOCK is the driver is in use, or SPID_ERROR if the command is not
//./ valid.
//./ \param pSpid  Pointer to a Spid instance.
//./ \param pCommand Pointer to the SPI command to execute.
//------------------------------------------------------------------------------
unsigned char SPI_D_SendCommand(SpiD *pSpiD, SpiDCmd *pCommand)
{
    AT91S_SPI *pSpiHw = pSpiD->pSpiHw;
     unsigned int spiMr;
         
     // Try to get the dataflash semaphore
     if (pSpiD->semaphore == 0) {
    
         return SPI_D_ERROR_LOCK;
    }
     pSpiD->semaphore--;

    // Enable the SPI clock
    WRITE_PMC(AT91C_BASE_PMC, PMC_PCER, (1 << pSpiD->spiId));
    
    // Disable transmitter and receiver
    //.WRITE_SPI(pSpiHw, SPI_PTCR, AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS);

     // Write to the MR register
     spiMr = READ_SPI(pSpiHw, SPI_MR);
     spiMr |= AT91C_SPI_PCS;
     spiMr &= ~((1 << pCommand->spiCs) << 16);
    WRITE_SPI(pSpiHw, SPI_MR, spiMr);
        
    // Initialize the two SPI PDC buffer
    //.WRITE_SPI(pSpiHw, SPI_RPR, (int) pCommand->pCmd);
    //.WRITE_SPI(pSpiHw, SPI_RCR, pCommand->cmdSize);
    //.WRITE_SPI(pSpiHw, SPI_TPR, (int) pCommand->pCmd);
    //.WRITE_SPI(pSpiHw, SPI_TCR, pCommand->cmdSize);
    
    //.WRITE_SPI(pSpiHw, SPI_RNPR, (int) pCommand->pData);
    //.WRITE_SPI(pSpiHw, SPI_RNCR, pCommand->dataSize);
    //.WRITE_SPI(pSpiHw, SPI_TNPR, (int) pCommand->pData);
    //.WRITE_SPI(pSpiHw, SPI_TNCR, pCommand->dataSize);

    // Initialize the callback
    pSpiD->pCurrentCommand = pCommand;
    
    // Enable transmitter and receiver
    //.WRITE_SPI(pSpiHw, SPI_PTCR, AT91C_PDC_RXTEN | AT91C_PDC_TXTEN);

    // Enable buffer complete interrupt
    //.WRITE_SPI(pSpiHw, SPI_IER, AT91C_SPI_RXBUFF);
    
    return 0;    
}

//------------------------------------------------------------------------------
//./ The SPI_Handler must be called by the SPI Interrupt Service Routine with the
//./ corresponding Spi instance.
//./ The SPI_Handler will unlock the Spi semaphore and invoke the upper application 
//./ callback.
//./ \param pSpid  Pointer to a Spid instance.
//------------------------------------------------------------------------------
void SPI_D_Handler(SpiD *pSpiD)
{
    SpiDCmd *pSpiDCmd = pSpiD->pCurrentCommand;
    AT91S_SPI *pSpiHw = pSpiD->pSpiHw;
    volatile unsigned int spiSr;
    
    // Read the status register
    spiSr = READ_SPI(pSpiHw, SPI_SR);    
    if (spiSr & AT91C_SPI_RXBUFF) {

        // Disable transmitter and receiver
        //.WRITE_SPI(pSpiHw, SPI_PTCR, AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS);

        // Disable the SPI clock
        WRITE_PMC(AT91C_BASE_PMC, PMC_PCDR, (1 << pSpiD->spiId));

        // Disable buffer complete interrupt
        //.WRITE_SPI(pSpiHw, SPI_IDR, AT91C_SPI_RXBUFF);

        // Release the dataflash semaphore
        pSpiD->semaphore++;
            
        // Invoke the callback associated with the current command
        if (pSpiDCmd && pSpiDCmd->callback) {
        
            pSpiDCmd->callback(0, pSpiDCmd->pArgument);
        }
            
        // Nothing must be done after. A new DF operation may have been started
        // in the callback function.
    }
}

//------------------------------------------------------------------------------
//./ Returns 1 if the SPI driver is currently busy executing a command; otherwise
//./ returns 0.
//./ \param pSpid  Pointer to a SPI driver instance.
//------------------------------------------------------------------------------
unsigned char SPI_D_IsBusy(const SpiD *pSpiD)
{
    if (pSpiD->semaphore == 0) {

        return 1;
    }
    else {

        return 0;
    }
}
#endif

