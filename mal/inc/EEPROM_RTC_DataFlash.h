#ifndef __EEPROM_RTC_DATAFLASH__
#define __EEPROM_RTC_DATAFLASH__

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


#define READ_BIT_OPERATION      0
#define WRITE_BIT_OPERATION     1

#define SPI1_RTC                0
#define SPI1_EEPROM             1
#define SPI1_DF_DR              2
#define SPI1_DF_AR              3

#define _DF_NONE                0
#define _DF_DR                  1
#define _DF_AR                  2
#define _DF_LOCK                ((unsigned int)(1 << 31))

#define SIZE_PAGE_EEPROM        128
#define SIZE_USTUVANNJA         (sizeof(ustuvannja) + sizeof(phi_ustuvannja) + sizeof(ustuvannja_P) + sizeof(ustuvannja_Q))

#define SIZE_PAGE_SERIAL_DATAFLASH_AR                   264
#define NUMBER_PAGES_INTO_SERIAL_DATAFLASH_AR           32768

#define SIZE_PAGE_SERIAL_DATAFLASH_DR                   264
#define NUMBER_PAGES_INTO_SERIAL_DATAFLASH_DR           4096

#define START_ADDRESS_USTUVANNJA_IN_EEPROM          0x0
#define START_ADDRESS_SETTINGS_PRT_IN_EEPROM        (((START_ADDRESS_USTUVANNJA_IN_EEPROM         + (SIZE_USTUVANNJA                  + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_SETTINGS_BS_IN_EEPROM         (((START_ADDRESS_SETTINGS_PRT_IN_EEPROM       + (sizeof(CfgTblDsc)                + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM  (((START_ADDRESS_SETTINGS_BS_IN_EEPROM        + (sizeof(AuxCfgTbl1Dsc)            + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM      (((START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM + 4                                     ) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_INFO_REJESTRATORS_AR          (((START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM     + (sizeof(trigger_active_functions) + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_INFO_REJESTRATORS_DR          (((START_ADDRESS_INFO_REJESTRATORS_AR         + (sizeof(EepromARecDesc)           + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)
#define START_ADDRESS_INFO_REJESTRATORS_PR_ERR      (((START_ADDRESS_INFO_REJESTRATORS_DR         + (sizeof(EepromDRecDesc)           + 1)) & (unsigned int)(~(SIZE_PAGE_EEPROM - 1))) + SIZE_PAGE_EEPROM)

#define SIZE_BUFFER_FOR_RED     ((sizeof(CfgTblDsc) + 1) + 3)

#define SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR      (5*SIZE_PAGE_SERIAL_DATAFLASH_AR)
#define SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR      (5*SIZE_PAGE_SERIAL_DATAFLASH_DR)

#define COMPARISON_WRITING_SETTINGS_PRT_BIT                     0
#define COMPARISON_WRITING_SETTINGS_PRT                         (1 << COMPARISON_WRITING_SETTINGS_PRT_BIT)
#define COMPARISON_WRITING_SETTINGS_BS_BIT                      1
#define COMPARISON_WRITING_SETTINGS_BS                          (1 << COMPARISON_WRITING_SETTINGS_BS_BIT)
#define COMPARISON_WRITING_USTUVANNJA_BIT                       2
#define COMPARISON_WRITING_USTUVANNJA                           (1 << COMPARISON_WRITING_USTUVANNJA_BIT)
#define COMPARISON_WRITING_STATE_LEDS_OUTPUTS_BIT               3
#define COMPARISON_WRITING_STATE_LEDS_OUTPUTS                   (1 << COMPARISON_WRITING_STATE_LEDS_OUTPUTS_BIT)
#define COMPARISON_WRITING_TRG_FUNC_BIT                         4
#define COMPARISON_WRITING_TRG_FUNC                             (1 << COMPARISON_WRITING_TRG_FUNC_BIT)
#define COMPARISON_WRITING_INFO_REJESTRATOR_AR_BIT              5
#define COMPARISON_WRITING_INFO_REJESTRATOR_AR                  (1 << COMPARISON_WRITING_INFO_REJESTRATOR_AR_BIT)
#define COMPARISON_WRITING_INFO_REJESTRATOR_DR_BIT              6
#define COMPARISON_WRITING_INFO_REJESTRATOR_DR                  (1 << COMPARISON_WRITING_INFO_REJESTRATOR_DR_BIT)
#define COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR_BIT          7
#define COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR              (1 << COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR_BIT)

#define TASK_EEPROM_WRITE_PREPARATION_BIT                       0      

#define TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT                1      
#define TASK_WRITING_SETTINGS_PRT_EEPROM_BIT                    2      

#define TASK_START_READ_SETTINGS_PRT_EEPROM_BIT                 3      
#define TASK_READING_SETTINGS_PRT_EEPROM_BIT                    4      

#define TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT                 5      
#define TASK_WRITING_SETTINGS_BS_EEPROM_BIT                     6      

#define TASK_START_READ_SETTINGS_BS_EEPROM_BIT                  7      
#define TASK_READING_SETTINGS_BS_EEPROM_BIT                     8      

#define TASK_START_WRITE_USTUVANNJA_EEPROM_BIT                  9      
#define TASK_WRITING_USTUVANNJA_EEPROM_BIT                      10      

#define TASK_START_READ_USTUVANNJA_EEPROM_BIT                   11      
#define TASK_READING_USTUVANNJA_EEPROM_BIT                      12      

#define TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT          13      
#define TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT              14      

#define TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT           15      
#define TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT              16      

#define TASK_START_WRITE_TRG_FUNC_EEPROM_BIT                    17      
#define TASK_WRITING_TRG_FUNC_EEPROM_BIT                        18      

#define TASK_START_READ_TRG_FUNC_EEPROM_BIT                     19      
#define TASK_READING_TRG_FUNC_EEPROM_BIT                        20      

#define TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT         21      
#define TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT             22      

#define TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT          23      
#define TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT             24      

#define TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT         25      
#define TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT             26      

#define TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT          27      
#define TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT             28      

#define TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT     29      
#define TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT         30      

#define TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT      31      
#define TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT         32      

#define TASK_START_READ_RTC_BIT                                 33      
#define TASK_READING_RTC_BIT                                    34     

#define TASK_START_WRITE_RTC_BIT                                35      
#define TASK_WRITING_RTC_BIT                                    36      

#define TASK_START_WRITE_CALIBR_RTC_BIT                         37      
#define TASK_WRITING_CALIBR_RTC_BIT                             38      

#define TASK_SET_START_SETTINGS_RTC_BIT                         39      
#define TASK_RESET_ST_RTC_BIT                                   40      
#define TASK_RESET_OF_RTC_BIT                                   41      

#define TASK_READ_SR_DF_AR_BIT                                  42   

//#define TASK_START_MAKE_PAGE_SIZE_256_AR_BIT                    43      
//#define TASK_MAKING_PAGE_SIZE_256_AR_BIT                        44      

#define TASK_START_ERASE_DATAFLASH_AR_BIT                       43
#define TASK_ERASING_DATAFLASH_AR_BIT                           44

#define TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT                45      
#define TASK_WRITING_SERIAL_DATAFLASH_AR_BIT                    46      

#define TASK_START_READ_SERIAL_DATAFLASH_AR_BIT                 47      
#define TASK_READING_SERIAL_DATAFLASH_AR_BIT                    48      

#define TASK_READ_SR_DF_DR_BIT                                  49   

//#define TASK_START_MAKE_PAGE_SIZE_256_DR_BIT                    52      
//#define TASK_MAKING_PAGE_SIZE_256_DR_BIT                        53      

#define TASK_START_ERASE_DATAFLASH_DR_BIT                       50
#define TASK_ERASING_DATAFLASH_DR_BIT                           51

#define TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT                52      
#define TASK_WRITING_SERIAL_DATAFLASH_DR_BIT                    53      

#define TASK_START_READ_SERIAL_DATAFLASH_DR_BIT                 54      
#define TASK_READING_SERIAL_DATAFLASH_DR_BIT                    55      

#define MASKA_ACTION_DF_AR_0             0
#define MASKA_ACTION_DF_AR_1             (unsigned int)(        \
  (1 << (TASK_READ_SR_DF_AR_BIT - 32))                  | /*42*/\
  (1 << (TASK_START_ERASE_DATAFLASH_AR_BIT - 32))       | /*43*/\
  (1 << (TASK_ERASING_DATAFLASH_AR_BIT - 32))           | /*44*/\
  (1 << (TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT - 32))| /*45*/\
  (1 << (TASK_WRITING_SERIAL_DATAFLASH_AR_BIT - 32))    | /*46*/\
  (1 << (TASK_START_READ_SERIAL_DATAFLASH_AR_BIT - 32)) | /*47*/\
  (1 << (TASK_READING_SERIAL_DATAFLASH_AR_BIT - 32))      /*48*/\
)

#define MASKA_ACTION_DF_DR_0             0
#define MASKA_ACTION_DF_DR_1             (unsigned int)(        \
  (1 << (TASK_READ_SR_DF_DR_BIT - 32))                  | /*49*/\
  (1 << (TASK_START_ERASE_DATAFLASH_DR_BIT - 32))       | /*50*/\
  (1 << (TASK_ERASING_DATAFLASH_DR_BIT - 32))           | /*51*/\
  (1 << (TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT - 32))| /*52*/\
  (1 << (TASK_WRITING_SERIAL_DATAFLASH_DR_BIT - 32))    | /*53*/\
  (1 << (TASK_START_READ_SERIAL_DATAFLASH_DR_BIT - 32)) | /*54*/\
  (1 << (TASK_READING_SERIAL_DATAFLASH_DR_BIT - 32))      /*55*/\
)


#define STATE_SETTINGS_PRT_EEPROM_EMPTY_BIT                   0      
#define STATE_SETTINGS_PRT_EEPROM_EMPTY                       (1<<STATE_SETTINGS_PRT_EEPROM_EMPTY_BIT)      
#define STATE_SETTINGS_PRT_EEPROM_FAIL_BIT                    1      
#define STATE_SETTINGS_PRT_EEPROM_FAIL                        (1<<STATE_SETTINGS_PRT_EEPROM_FAIL_BIT)      
#define STATE_SETTINGS_PRT_EEPROM_GOOD_BIT                    2      
#define STATE_SETTINGS_PRT_EEPROM_GOOD                        (1<<STATE_SETTINGS_PRT_EEPROM_GOOD_BIT)      

#define STATE_SETTINGS_BS_EEPROM_EMPTY_BIT                    3      
#define STATE_SETTINGS_BS_EEPROM_EMPTY                        (1<<STATE_SETTINGS_BS_EEPROM_EMPTY_BIT)      
#define STATE_SETTINGS_BS_EEPROM_FAIL_BIT                     4      
#define STATE_SETTINGS_BS_EEPROM_FAIL                         (1<<STATE_SETTINGS_BS_EEPROM_FAIL_BIT)      
#define STATE_SETTINGS_BS_EEPROM_GOOD_BIT                     5      
#define STATE_SETTINGS_BS_EEPROM_GOOD                         (1<<STATE_SETTINGS_BS_EEPROM_GOOD_BIT)      

#define STATE_USTUVANNJA_EEPROM_EMPTY_BIT                     6      
#define STATE_USTUVANNJA_EEPROM_EMPTY                         (1<<STATE_USTUVANNJA_EEPROM_EMPTY_BIT)      
#define STATE_USTUVANNJA_EEPROM_FAIL_BIT                      7      
#define STATE_USTUVANNJA_EEPROM_FAIL                          (1<<STATE_USTUVANNJA_EEPROM_FAIL_BIT)      
#define STATE_USTUVANNJA_EEPROM_GOOD_BIT                      8      
#define STATE_USTUVANNJA_EEPROM_GOOD                          (1<<STATE_USTUVANNJA_EEPROM_GOOD_BIT)      

#define STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT                   9      
#define STATE_LEDS_OUTPUTS_EEPROM_EMPTY                       (1<<STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT)      
#define STATE_LEDS_EEPROM_FAIL_BIT                            10      
#define STATE_LEDS_EEPROM_FAIL                                (1<<STATE_LEDS_EEPROM_FAIL_BIT)      
#define STATE_LEDS_EEPROM_GOOD_BIT                            11     
#define STATE_LEDS_EEPROM_GOOD                                (1<<STATE_LEDS_EEPROM_GOOD_BIT)      
#define STATE_OUTPUTS_EEPROM_FAIL_BIT                         12     
#define STATE_OUTPUTS_EEPROM_FAIL                             (1<<STATE_OUTPUTS_EEPROM_FAIL_BIT)      
#define STATE_OUTPUTS_EEPROM_GOOD_BIT                         13      
#define STATE_OUTPUTS_EEPROM_GOOD                             (1<<STATE_OUTPUTS_EEPROM_GOOD_BIT)      

#define STATE_TRG_FUNC_EEPROM_EMPTY_BIT                       14      
#define STATE_TRG_FUNC_EEPROM_EMPTY                           (1<<STATE_TRG_FUNC_EEPROM_EMPTY_BIT)      
#define STATE_TRG_FUNC_EEPROM_FAIL_BIT                        15     
#define STATE_TRG_FUNC_EEPROM_FAIL                            (1<<STATE_TRG_FUNC_EEPROM_FAIL_BIT)      
#define STATE_TRG_FUNC_EEPROM_GOOD_BIT                        16     
#define STATE_TRG_FUNC_EEPROM_GOOD                            (1<<STATE_TRG_FUNC_EEPROM_GOOD_BIT)      

#define STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT            17      
#define STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY                (1<<STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT)      
#define STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL_BIT             18      
#define STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL                 (1<<STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL_BIT)      
#define STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD_BIT             19      
#define STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD                 (1<<STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD_BIT)      

#define STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT            20      
#define STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY                (1<<STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT)      
#define STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL_BIT             21      
#define STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL                 (1<<STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL_BIT)      
#define STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD_BIT             22      
#define STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD                 (1<<STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD_BIT)      

#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT        23      
#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY            (1<<STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT)      
#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL_BIT         24      
#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL             (1<<STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL_BIT)      
#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD_BIT         25      
#define STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD             (1<<STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD_BIT)      

#define STATE_FIRST_READING_RTC_BIT                           30      
#define STATE_FIRST_READING_RTC                               (1<<STATE_FIRST_READING_RTC_BIT)    

#define ETAP_CLEAR_OF_NONE                                      -1                                            //-1
#define ETAP_CLEAR_OF_ST_STOP                                   0                                             //0
#define ETAP_CLEAR_OF_ST_CLEAR                                  (ETAP_CLEAR_OF_ST_STOP + 1)                   //1
#define ETAP_CLEAR_OF_ST_START_WAITING_5S                       (ETAP_CLEAR_OF_ST_CLEAR + 1)                  //2
#define ETAP_CLEAR_OF_ST_WAITING_5S                             (ETAP_CLEAR_OF_ST_START_WAITING_5S + 1)       //3
#define ETAP_CLEAR_OF_WRITE_OF_0                                (ETAP_CLEAR_OF_ST_WAITING_5S + 1)             //4

/*EEPROM*/
#define OPCODE_WRITE                                          0x02
#define OPCODE_READ                                           0x03
#define OPCODE_RDSR                                           0x05
#define OPCODE_WREN                                           0x06

/*DataFlash*/
#define CODE_OPERATION_STATUS_READ                            0xD7
#define CODE_OPERATION_READ_HIGH_FREQ                         0x0B
#define CODE_OPERATION_WRITE_PAGE_THROUGH_BUFFER              0x82
#define CODE_OPERATION_READ_PAGE_INTO_BUFFER                  0x53
#define CODE_OPERATION_WRITE_BUFFER                           0x84
#define CODE_OPERATION_WRITE_BUFFER_INTO_MEMORY_WITH_ERASE    0x83


#define ETAP_WRITING_DF_NONE                                             -1
#define ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER               (ETAP_WRITING_DF_NONE + 1)
#define ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER                   (ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER + 1)
#define ETAP_WRITING_DF_BUFFER_WRITE                                     (ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER + 1)
#define ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE (ETAP_WRITING_DF_BUFFER_WRITE + 1)


#define N_TMP   10
#endif
