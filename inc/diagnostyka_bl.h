#ifndef __DIAGNOSTYKA_H
#define __DIAGNOSTYKA_H

enum _error_id {
ERROR_VREF_ADC1_TEST_BIT = 0,
ERROR_VDD_ADC1_TEST_BIT,
ERROR_VREF_ADC1_TEST_COARSE_BIT,
ERROR_VDD_ADC1_TEST_COARSE_BIT,

ERROR_VREF_ADC2_TEST_BIT,
ERROR_VDD_ADC2_TEST_BIT,
ERROR_VREF_ADC2_TEST_COARSE_BIT,
ERROR_VDD_ADC2_TEST_COARSE_BIT,

ERROR_VREF_ADC3_TEST_BIT,
ERROR_VDD_ADC3_TEST_BIT,
ERROR_VREF_ADC3_TEST_COARSE_BIT,
ERROR_VDD_ADC3_TEST_COARSE_BIT,

ERROR_EXTERNAL_SRAM_BIT,
ERROR_EXTERNAL_FLASH_MEMORY_BIT,

ERROR_START_VIA_I2C_BIT,
ERROR_SETTINGS_EEPROM_BIT,
ERROR_SETTINGS_EEPROM_EMPTY_BIT,
ERROR_SETTINGS_EEPROM_COMPARISON_BIT,
ERROR_SETTINGS_EEPROM_CONTROL_BIT,
ERROR_SETTINGS_EEPROM_DEVICE_ID_FAIL_BIT,
ERROR_USTUVANNJA_EEPROM_BIT,
ERROR_USTUVANNJA_EEPROM_EMPTY_BIT,
ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT,
ERROR_USTUVANNJA_EEPROM_CONTROL_BIT,
ERROR_USTUVANNJA_EEPROM_ADJUSTMENT_ID_FAIL_BIT

};

#define ERROR_ADC1 (                                            \
                    (1 << ERROR_VREF_ADC1_TEST_BIT)        |    \
                    (1 << ERROR_VDD_ADC1_TEST_BIT)         |    \
                    (1 << ERROR_VREF_ADC1_TEST_COARSE_BIT) |    \
                    (1 << ERROR_VDD_ADC1_TEST_COARSE_BIT)       \
                   )


#define ERROR_ADC2 (                                            \
                    (1 << ERROR_VREF_ADC2_TEST_BIT)        |    \
                    (1 << ERROR_VDD_ADC2_TEST_BIT)         |    \
                    (1 << ERROR_VREF_ADC2_TEST_COARSE_BIT) |    \
                    (1 << ERROR_VDD_ADC2_TEST_COARSE_BIT)       \
                   )


#define ERROR_ADC3 (                                            \
                    (1 << ERROR_VREF_ADC3_TEST_BIT)        |    \
                    (1 << ERROR_VDD_ADC3_TEST_BIT)         |    \
                    (1 << ERROR_VREF_ADC3_TEST_COARSE_BIT) |    \
                    (1 << ERROR_VDD_ADC3_TEST_COARSE_BIT)       \
                   )

#endif
