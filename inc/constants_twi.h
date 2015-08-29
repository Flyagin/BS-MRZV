//------------------------------------------------------------------------------
//                        SPI main constants
//------------------------------------------------------------------------------

/* SPI1 pins */

/// SPI1 MISO pin definition.
#define PIN_SPI1_MISO  {1 << 14, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
/// SPI1 MOSI pin definition.
#define PIN_SPI1_MOSI  {1 << 15, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI1 SPCK pin definition.
#define PIN_SPI1_SPCK  {1 << 16, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI1 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI1      PIN_SPI1_MISO, PIN_SPI1_MOSI, PIN_SPI1_SPCK
/// SPI1 chip select 0 pin definition.
#define PIN_SPI1_NPCS0 {1 << 17, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI1 chip select 1 pin definition.
#define PIN_SPI1_NPCS1 {1 << 28, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_B, PIO_DEFAULT}
/// SPI1 chip select 2 pin definition.
#define PIN_SPI1_NPCS2 {1 << 18, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI1 chip select 3 pin definition.
#define PIN_SPI1_NPCS3 {1 << 19, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI1 pin definitions (CS0, CS1, CS2, CS3)
#define PINS_SPI1_CS_ALL        PIN_SPI1_NPCS0, PIN_SPI1_NPCS1, PIN_SPI1_NPCS2, PIN_SPI1_NPCS3

/****** SPI operations for SPIOperationTable********/
// RTC
#define RTC_READ_DATE                   (1 << 0)          // Reading all values operation
#define RTC_WRITE_DATE                  (1 << 1)          // Write date operation
#define RTC_WRITE_CALIB                 (1 << 2)          // Write calibration operation 
// service operations RTC
#define RTC_CLEAR_HT                    (1 << 3)          // Clear HT-bit
#define RTC_SET_ST                      (1 << 4)          // Set ST-bit
#define RTC_CLEAR_ST                    (1 << 5)          // Clear ST-bit
#define RTC_CLEAR_OF                    (1 << 6)          // Clear OF-bit

// EEPROM
#define EEPROM_WRITE_ADJUSTMENT         (1 << 9)          // Write the Adjustment Table to EEPROM
#define EEPROM_READ_ADJUSTMENT          (1 << 10)          // Read the Adjustment Table from EEPROM

#define EEPROM_WRITE_SETTINGS           (1 << 11)         // Write the Measure System Settings Table to EEPROM
#define EEPROM_READ_SETTINGS            (1 << 12)         // Read the Measure System Settings Table from EEPROM

#define EEPROM_WRITE_SECURITY           (1 << 13)         // Write Security Settings Table to EEPROM
#define EEPROM_READ_SECURITY            (1 << 14)         // Read Security Settings Table from EEPROM

#define EEPROM_WRITE_DIGITAL            (1 << 15)         // Write Digital Registrar Settings Table to EEPROM
#define EEPROM_READ_DIGITAL             (1 << 16)         // Read Digital Registrar Settings Table from EEPROM

#define EEPROM_WRITE_ANALOG             (1 << 17)         // Write Analog Registrar Settings Table to EEPROM
#define EEPROM_READ_ANALOG              (1 << 18)         // Read Analog Registrar Settings Table from EEPROM

#define EEPROM_WRITE_FAILURE            (1 << 19)         // Write Failure Events Table to EEPROM
#define EEPROM_READ_FAILURE             (1 << 20)         // Read Failure Events Table from EEPROM

#define EEPROM_WRITE_ADD_SETTINGS       (1 << 21)         // Write Failure Events Table to EEPROM
#define EEPROM_READ_ADD_SETTINGS        (1 << 22)         // Read Failure Events Table from EEPROM

// DataFlash Dig Registrar
#define DF_DR_WRITE                     (1 << 23)         // Write data to DataFlash Digital Registrar
#define DF_DR_READ                      (1 << 24)         // Read data from DataFlash Digital Registrar
#define DF_DR_CHIP_ERASE                (1 << 25)         // Erase all dataflash

//DataFlash Analog Registrar
#define DF_AR_WRITE                     (1 << 26)         // Write data to DataFlash Analog Registrar
#define DF_AR_READ                      (1 << 27)         // Read data from DataFlash Analog REgistrar
#define DF_AR_CHIP_ERASE                (1 << 28)         // Erase all dataflash

#define SPI_CHECK_CRC16                 (1 << 29)         // Routin of SPI, if no task is set

/****** SPI Diagnostic Statuses for SPIOperationDiagnosticTable ******/

#define SPI1_NECESSARY_REBOOT           (1 << 0)        // It is necessary to reboot device
#define SPI1_IN_PROC                    (1 << 1)        // Operation in process
#define SPI1_ERROR                      (1 << 2)        // Some unexpected error has appeared
// RTC
#define RTC_FIRST_START                 (1 << 3)        // Initial power up in the RTC
#define RTC_READING                     (1 << 4)        // Reading in process
#define RTC_WRITING                     (1 << 5)        // Writing in process
#define RTC_BUSY                        (1 << 6)        // Waiting few seconds

// EEPROM
#define EEPROM_WRITING                  (1 << 16)        // writing in process
#define EEPROM_READING                  (1 << 17)        // reading in process

// DataFlash DR
#define DF_DR_WRITING                   (1 << 20)       // Writing in process
#define DF_DR_READING                   (1 << 21)       // Reading in process
#define DF_DR_ERASING                   (1 << 22)       // Erasing
// DataFlash AR
#define DF_AR_WRITING                   (1 << 23)       // Writing in process
#define DF_AR_READING                   (1 << 24)       // Reading in process
#define DF_AR_ERASING                   (1 << 25)       // Erasing

/************ SPI Diagnostic Statuses for SPIStateDiagnosticTable ******************/

// RTC
#define RTC_ST_DETECTED                 (1 << 0)        // ST-bit detected
#define RTC_OF_DETECTED                 (1 << 1)        // OF-bit detected
#define RTC_HT_DETECTED                 (1 << 2)        // HT-bit detected 

// EEPROM
#define EEPROM_ADJUSTMENT_FAIL          (1 << 9)          // Checksum of Adjustment Table wasn't confirmed during write/read cycle
#define EEPROM_ADJUSTMENT_EMPTY         (1 << 10)         // Adjustment Table is empty
#define EEPROM_ADJUSTMENT_CS_FAIL       (1 << 11)         // checksum of Adjustment Table is incorrect

#define EEPROM_SETTINGS_FAIL            (1 << 12)         // Checksum of Measure System Settings Table wasn't confirmed during write/read cycle
#define EEPROM_SETTINGS_EMPTY           (1 << 13)         // Measure System Settings Table is empty
#define EEPROM_SETTINGS_CS_FAIL         (1 << 14)         // checksum of Measure System Settings Table is incorrect

#define EEPROM_SECURITY_FAIL            (1 << 15)       // Checksum of Security System Settings Table wasn't confirmed during write/read cycle
#define EEPROM_SECURITY_EMPTY           (1 << 16)       // Security System Settings Table is empty
#define EEPROM_SECURITY_CS_FAIL         (1 << 17)         // checksum of Security Settings Table is incorrect

#define EEPROM_DIGITAL_FAIL             (1 << 18)       // Checksum of Digital Registrar Settings Table wasn't confirmed during write/read cycle
#define EEPROM_DIGITAL_EMPTY            (1 << 19)       // Digital Registrar Settings Table is empty
#define EEPROM_DIGITAL_CS_FAIL          (1 << 20)         // checksum of Digital Registrar Settings Table is incorrect

#define EEPROM_ANALOG_FAIL              (1 << 21)       // Checksum of Analog Registrar Settings Table wasn't confirmed during write/read cycle
#define EEPROM_ANALOG_EMPTY             (1 << 22)       // Analog Reigstrar Settings Table is empty
#define EEPROM_ANALOG_CS_FAIL           (1 << 23)         // checksum of Analog Registrar Settings Table is incorrect

#define EEPROM_FAILURE_FAIL             (1 << 24)       // Checksum of Failure Events Table wasn't confirmed during write/read cycle
#define EEPROM_FAILURE_EMPTY            (1 << 25)       // Failure Events Table is empty
#define EEPROM_FAILURE_CS_FAIL          (1 << 26)         // checksum of Failure Events Table is incorrect

#define EEPROM_ADD_SETTINGS_FAIL        (1 << 27)       // Checksum of Additional Settings Table wasn't confirmed during write/read cycle
#define EEPROM_ADD_SETTINGS_EMPTY       (1 << 28)       // Additional Settings Table is empty
#define EEPROM_ADD_SETTINGS_CS_FAIL     (1 << 29)         // checksum of Additional Settings Table is incorrect

//------------------------------------------------------------------------------
//                 SPI RTC variables
//------------------------------------------------------------------------------
#define RTCLOCK_CS             (0xE << 16)

// definition for READ or WRITE cycles
#define RTC_WRITE_CYCLE        1 << 7
#define RTC_READ_CYCLE         0 << 7

//------------------------------------------------------------------------------
//                    RTC bits
//------------------------------------------------------------------------------

#define RTC_ST          (1 << 7)          // Stop Bit 
#define RTC_OF          (1 << 2)          // Oscillator Fail bit
#define RTC_HT          (1 << 6)          // Halt update bit

//------------------------------------------------------------------------------
//                 SPI EEPROM variables
//------------------------------------------------------------------------------
#define EEPROM_CS      (0xD << 16) 

// Instructions for EEPROM AT25512
#define EEPROM_WEN              (0x6 & 0xff)    // Set Write Enable Latch
#define EEPROM_WRDI             (0x4 & 0xff)   // Reset Write Enable Latch
#define EEPROM_RDSR             (0x5 & 0xff)   // Read Status Register
#define EEPROM_WRSR             (0x1 & 0xff)    // Write Status Register
#define EEPROM_READ             (0x3 & 0xff)    // Read Data from Memory Array
#define EEPROM_WRITE            (0x2 & 0xff)    // Write Data to Memory Array

// Definitions for Status Register
#define EEPROM_RDY_BIT          (1 << 0)       // Ready state of EEPROM
#define EEPROM_WEN_BIT          (1 << 1)       // Write Enable

// EEPROM block sizes in bytes. Suplying 1 is necessary for checksum
#define EEPROM_ADJUSTMENT_SIZE          255
#define EEPROM_SECURITY_SIZE            7935
#define EEPROM_DIGITAL_SIZE             255
#define EEPROM_ANALOG_SIZE              255
#define EEPROM_SETTINGS_SIZE            sizeof(eeprom_prt_tbl) // ~ 6KB
#define EEPROM_FAILURE_SIZE             1023
#define EEPROM_ADD_SETTINGS_SIZE        sizeof(AuxCfgTbl1) // test

// EEPROM block firts addresses
#define EEPROM_ADJUSTMENT_ADDR          0x0000                          // First address of Adjustment Table block                            
#define EEPROM_SECURITY_ADDR            0x0200                          // First address of Security Table block
#define EEPROM_DIGITAL_ADDR             0x2100                          // Firts address of Digital Registrar Settings Table block
#define EEPROM_ANALOG_ADDR              0x2300                          // First address of Analog Registrar Settings Table block
#define EEPROM_SETTINGS_ADDR            0x2500                          // Firts address of System Measure Settings Table block
#define EEPROM_FAILURE_ADDR             0x3f00                          // Firts address of Failure Events Description Table block
#define EEPROM_ADD_SETTINGS_ADDR        0x4000 // test

//------------------------------------------------------------------------------
//                 SPI DataFlash Analog constants
//------------------------------------------------------------------------------
#define DATAFLASH_AR_CS            (0x7 << 16) 


// Instructions for DataFlash AT45DB642D
#define DATAFLASH_AR_WRITE_BUFFER1                 (0x84 & 0xff)         // Write Data to Buffer 1 
#define DATAFLASH_AR_READ_STATUSREG                (0xD7 & 0xff)         // Read Status Register
#define DATAFLASH_AR_BUFF1_TO_MEMORY_WITH_ERASE    (0x83 & 0xff)
#define DATAFLASH_AR_MEMORY_PROG_THROW_BUFF1            (0x82 & 0xff)          
#define DATAFLASH_AR_MEMORY_PAGE_TO_BUFF1               (0x53 & 0xff)
#define DATAFLASH_AR_CONTINUOUS_ARR_READ                (0x03 & 0xff)

#define DATAFLASH_AR_RDY                                0x80                // RDY bit in status reg

#define DATAFLASH_AR_MAX_SIZE                           (5 * 1024 + 4)

//------------------------------------------------------------------------------
//                 SPI DataFlash Dig Registrar constants
//------------------------------------------------------------------------------
#define DATAFLASH_DR_CS          (0xB << 16) 


// Instructions for DataFlash AT45DB081D
#define DATAFLASH_DR_WRITE_BUFFER1                      (0x84 & 0xff)           // Write Data to Buffer 1 
#define DATAFLASH_DR_READ_STATUSREG                     (0xD7 & 0xff)           // Read Status Register
#define DATAFLASH_DR_BUFF1_TO_MEMORY_WITH_ERASE         (0x83 & 0xff)           // Buff1 to Main Memory Progr
#define DATAFLASH_DR_MEMORY_PROG_THROW_BUFF1            (0x82 & 0xff)          
#define DATAFLASH_DR_MEMORY_PAGE_TO_BUFF1               (0x53 & 0xff)
#define DATAFLASH_DR_CONTINUOUS_ARR_READ                (0x03 & 0xff)

#define DATAFLASH_DR_RDY                                0x80                // RDY bit in status reg

#define DATAFLASH_DR_MAX_SIZE                           (5 * 1024 + 4)
