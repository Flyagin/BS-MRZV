//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : init.c
//* Object              : Low level initialisations written in C
//* Creation            : ODi   06/26/2002
//*
//*----------------------------------------------------------------------------

#include "AT91SAM9264.h"
#include "lib_AT91SAM9264.h"

#define AT91C_MASTER_CLOCK			48000000
#define DELAY			 		100000
//*----------------------------------------------------------------------------
//* \fn    AT91F_DBGU_Printk
//* \brief This function is used to send a string through the DBGU channel (Very low level debugging)
//*----------------------------------------------------------------------------
void AT91F_DBGU_Printk(
	char *buffer) // \arg pointer to a string ending by \0
{
	while(*buffer != '\0') {
		while (!AT91F_US_TxReady((AT91PS_USART)AT91C_BASE_DBGU));
		AT91F_US_PutChar((AT91PS_USART)AT91C_BASE_DBGU, *buffer++);
	}
}
//*----------------------------------------------------------------------------
//* \fn    AT91F_Putc
//* \brief This function sends a car through the DBGU
//*----------------------------------------------------------------------------
int AT91F_Putc(int ch) 
{
    /* Our implementation of fputc */ 
    while (!AT91F_US_TxReady((AT91PS_USART)AT91C_BASE_DBGU));
    AT91F_US_PutChar((AT91PS_USART)AT91C_BASE_DBGU, (char)ch);
    return ch; 
}


//*----------------------------------------------------------------------------
//* \fn    AT91F_Getc
//* \brief This function receives a car through the DBGU
//*----------------------------------------------------------------------------
int AT91F_Getc() 
{
    while(!AT91F_US_RxReady((AT91PS_USART)AT91C_BASE_DBGU));
    return((int)AT91F_US_GetChar((AT91PS_USART)AT91C_BASE_DBGU));
}
//*----------------------------------------------------------------------------
//* \fn    AT91F_DataAbort
//* \brief This function reports an Abort
//*----------------------------------------------------------------------------
void AT91F_SpuriousHandler()
{
	AT91F_DBGU_Printk("-F- Spurious Interrupt detected\n\r");
	while (1);
}


//*----------------------------------------------------------------------------
//* \fn    AT91F_DataAbort
//* \brief This function reports an Abort
//*----------------------------------------------------------------------------
void AT91F_DataAbort()
{
	AT91F_DBGU_Printk("-F- Data Abort detected\n\r");
	while (1);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_FetchAbort
//* \brief This function reports an Abort
//*----------------------------------------------------------------------------
void AT91F_FetchAbort()
{
	AT91F_DBGU_Printk("-F- Prefetch Abort detected\n\r");
	while (1);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_Undef
//* \brief This function reports an Abort
//*----------------------------------------------------------------------------
void AT91F_Undef()
{
	AT91F_DBGU_Printk("-F- Undef detected\n\r");
	while (1);
}

//*----------------------------------------------------------------------------
//* \fn    AT91F_UndefHandler
//* \brief This function reports that no handler have been set for current IT
//*----------------------------------------------------------------------------
void AT91F_UndefHandler()
{
	AT91F_DBGU_Printk("-F- Undef detected\n\r");
	while (1);
}


//*----------------------------------------------------------------------------
//* \fn    AT91F_LowLevelInit
//* \brief This function performs very low level HW initialization
//*----------------------------------------------------------------------------
void AT91F_LowLevelInit()
{
	unsigned int	tmp	= 0;
	AT91PS_PMC pPmc = AT91C_BASE_PMC;
	// Disable watchdog
	*(AT91C_WDTC_WDMR) = AT91C_WDTC_WDDIS;


	AT91F_MATRIX_Remap_ARM(AT91C_BASE_MATRIX);

	// Open PIO for DBGU
	AT91F_DBGU_CfgPIO();

	// Configure DBGU
	AT91F_US_Configure (
		(AT91PS_USART) AT91C_BASE_DBGU,          // DBGU base address
		AT91C_MASTER_CLOCK,
		AT91C_US_ASYNC_MODE,        // mode Register to be programmed
		115200 ,              // baudrate to be programmed
		0);                   // timeguard to be programmed

	// Enable Transmitter
	AT91F_US_EnableTx((AT91PS_USART) AT91C_BASE_DBGU);
	AT91F_US_EnableRx((AT91PS_USART) AT91C_BASE_DBGU);

}

