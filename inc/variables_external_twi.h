#ifndef _VARIABLES_EXTERNAL_TWI_H_
#define _VARIABLES_EXTERNAL_TWI_H_

#include "type_definition.h"
//#include "variables_twi.h"

/**************************** SPI1 RTC ****************************************/
// list of the SPI operation, see spi_BSG45.h "SPI Operations"
extern unsigned int SPIOperationTable;

// list of the SPI status flags, see spi_BSG45.h "SPI Diagnostic Statuses"
extern unsigned long SPIOperationDiagnosticTable;

// list of the SPI diagnostic information flag
extern unsigned long SPIStateDiagnosticTable;

extern rtcMgr pRtcMgr;
extern unsigned int rtc_Tx_Rx_arr[26];
extern unsigned int rtc_tempBuff[26];
/******************************************************************************/
/************************** SPI1 EEPROM ***************************************/

extern eeprom_manager pEEPROM_manager;
extern unsigned int eeprom_Tx_Rx_arr[10 * 1024]; // 10Kb
extern unsigned int eeprom_Tx_arr[10 * 1024]; // 10Kb

extern unsigned char EEPROMAdjustmentTable[EEPROM_ADJUSTMENT_SIZE];

extern unsigned char EEPROMSecurityTable[EEPROM_SECURITY_SIZE];

extern unsigned char EEPROMDigitalRegistrarSettingsTable[EEPROM_DIGITAL_SIZE];

extern unsigned char EEPROMAnalogRegistrarSettingsTable[EEPROM_ANALOG_SIZE];

extern unsigned char EEPROMFailureEventTable[EEPROM_FAILURE_SIZE];

extern unsigned short EEPROM_AdjustmentTableCheckSum;

extern unsigned short EEPROM_SettingsTableCheckSum;

extern unsigned short EEPROM_SecurityTableCheckSum;

extern unsigned short EEPROM_DigitCheckSum;

extern unsigned short EEPROM_AnalogCheckSum;

extern unsigned short EEPROM_FailureCheckSum;

extern unsigned short EEPROM_AddSettingsTableCheckSum;

/******************************************************************************/
/************************** SPI1 DataFlash DR *********************************/
extern DF_manager pDF_DR_manager;
extern DF_manager pDF_AR_manager;

extern unsigned int dataFlashDR_Tx_Rx_arr[DATAFLASH_DR_MAX_SIZE];
extern unsigned int dataFlashAR_Tx_Rx_arr[DATAFLASH_AR_MAX_SIZE];

/********************************* DEBUG **************************************/
extern unsigned int timeCounter;

#endif
