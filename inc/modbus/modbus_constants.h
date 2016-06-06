#ifndef __MODBUS_CONSTANTS__
#define __MODBUS_CONSTANTS__

#include <stdbool.h>

#define NUMBER_CRC_BYTES                        2

#define FUNCTION_CODE_OFFSET                    1
#define ADDRESS_OFFSET                          2

#define QUANTITY_OF_OUTPUTS_FUNC1_OFFSET        4

#define QUANTITY_OF_REGISTERS_FUNC3_OFFSET      4

#define CONST_OUT_ADDRESS_FUNC5_OFFSET          4

#define DATA_FUNC6_OFFSET                       4

#define QUANTITY_OF_OUTPUTS_FUNC15_OFFSET       4
#define NUMBER_OF_BYTES_FUNC15_OFFSET           6
#define DATA_FUNC15_OFFSET                      7

#define QUANTITY_OF_REGISTERS_FUNC16_OFFSET     4
#define NUMBER_OF_BYTES_FUNC16_OFFSET           6
#define DATA_FUNC16_OFFSET                      7

#define MIN_MODBUS_VALUE_OUTPUTS_FUNC1          0x0001
#define MAX_MODBUS_VALUE_OUTPUTS_FUNC1          0x07D0 

#define MIN_MODBUS_VALUE_OUTPUTS_FUNC2          0x0001
#define MAX_MODBUS_VALUE_OUTPUTS_FUNC2          0x07D0 

#define MIN_MODBUS_VALUE_REGISTER_FUNC3         0x0001
#define MAX_MODBUS_VALUE_REGISTER_FUNC3         0x007D

#define MIN_MODBUS_VALUE_OUTPUTS_FUNC15         0x0001
#define MAX_MODBUS_VALUE_OUTPUTS_FUNC15         0x07B0 


enum modbus_communication_error_list
{
  DEV_FREE = 0,
  ILLEGAL_FUNCTION,                             //exception code 1
  ILLEGAL_DATA_ADDRESS,                         //exception code 2
  ILLEGAL_DATA_VALUE,                           //exception code 3
  SLAVE_DEVICE_FAILURE,                         //exception code 4
  ACKNOWLEDGE,                                  //exception code 5
  SLAVE_DEVICE_BUSY,                            //exception code 6
  MEMORY_PARITY_ERROR,                          //exception code 7
  GATEWAY_PATH_UNAVAILABLE,                     //exception code 8
  GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND      //exception code 9
};

#define NUMBER_MODBUS_FUNCTIONS                 8
enum modbus_func_code_list
{
  MODBUS_FUNC1 = 1,
  MODBUS_FUNC2 = 2,
  MODBUS_FUNC3 = 3,
  MODBUS_FUNC4 = 4,
  MODBUS_FUNC5 = 5,
  MODBUS_FUNC6 = 6,
//  MODBUS_FUNC8 = 8,
  MODBUS_FUNC15 = 15,
  MODBUS_FUNC16 = 16,
//  MODBUS_FUNC20 = 20,
  MODBUS_EMPTY_FUNC
};

#define READ_YUST_COUNTER_MAX_VALUE             100000

#define NUMBER_CANALS_ADC1                      3
#define NUMBER_CANALS_ADC2                      4
#define NUMBER_CANALS_ADC3                      3
#define NUMBER_CANALS_SPI1                      (NUMBER_CANALS_ADC1 + NUMBER_CANALS_ADC2)
#define NUMBER_CANALS_SPI2                      (NUMBER_CANALS_ADC3)
#define NUMBER_CANALS                           (NUMBER_CANALS_SPI1 + NUMBER_CANALS_SPI2)

#endif

