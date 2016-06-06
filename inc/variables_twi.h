#ifndef _VARIABLES_TWI_H_
#define _VARIABLES_TWI_H_

#include "spi_BSG45.h"
#include "type_definition.h"


///**************************** SPI1 RTC ****************************************/
//// list of the SPI operation, see spi_BSG45.h "SPI Operations"
 unsigned int SPIOperationTable = 0;

// list of the SPI status flags, see spi_BSG45.h "SPI Diagnostic Statuses"
 unsigned long SPIOperationDiagnosticTable;

// list of the SPI diagnostic information flag
 unsigned long SPIStateDiagnosticTable;

 rtcMgr pRtcMgr;
 unsigned int rtc_Tx_Rx_arr[26] @"DDR2B3_Data_NC_region";
 unsigned int rtc_tempBuff[26] @"DDR2B3_Data_NC_region";
/******************************************************************************/
/************************** SPI1 EEPROM ***************************************/

 eeprom_manager pEEPROM_manager;
 unsigned int eeprom_Tx_Rx_arr[10 * 1024] @"DMA_BUFFERS"; // 10Kb
 unsigned int eeprom_Tx_arr[10 * 1024] @"DMA_BUFFERS"; 

 unsigned char EEPROMAdjustmentTable[EEPROM_ADJUSTMENT_SIZE];

 unsigned char EEPROMSecurityTable[EEPROM_SECURITY_SIZE];

 unsigned char EEPROMDigitalRegistrarSettingsTable[EEPROM_DIGITAL_SIZE];

 unsigned char EEPROMAnalogRegistrarSettingsTable[EEPROM_ANALOG_SIZE];

 unsigned char EEPROMFailureEventTable[EEPROM_FAILURE_SIZE];

 unsigned short EEPROM_AdjustmentTableCheckSum;

 unsigned short EEPROM_SettingsTableCheckSum;

 unsigned short EEPROM_SecurityTableCheckSum;

 unsigned short EEPROM_DigitCheckSum;

 unsigned short EEPROM_AnalogCheckSum;

 unsigned short EEPROM_FailureCheckSum;
 
 unsigned short EEPROM_AddSettingsTableCheckSum;

/******************************************************************************/
/************************** SPI1 DataFlash ************************************/
 DF_manager pDF_DR_manager;
 DF_manager pDF_AR_manager;

 unsigned int dataFlashDR_Tx_Rx_arr[DATAFLASH_DR_MAX_SIZE] @"DMA_BUFFERS";
 unsigned int dataFlashAR_Tx_Rx_arr[DATAFLASH_AR_MAX_SIZE] @"DMA_BUFFERS";
 
 
 /******************************* DEBUG ***********************************/
 unsigned int timeCounter = 0;

#endif
