
#include "modbus_header.h"
#include "communication_constants.h"

extern unsigned char source_id;

unsigned char check_func1_data(unsigned short quantity_of_outputs,
                               unsigned short start_addr)
{
   
  //проверяем корректно ли задано количество считываемых выходов
  if( 
     quantity_of_outputs >= MIN_MODBUS_VALUE_OUTPUTS_FUNC1 &&
     quantity_of_outputs <= MAX_MODBUS_VALUE_OUTPUTS_FUNC1
    )
  {     
    //проверяем адрес устройства
    if (check_addr_dig_outputs(quantity_of_outputs, start_addr)         ||
        check_addr_active_func(quantity_of_outputs, start_addr)         ||
        check_addr_tripped_func(quantity_of_outputs, start_addr)
       )
      {
        response_ready = false;
        modbus_func_id = MODBUS_FUNC1;
        return SLAVE_DEVICE_BUSY; 
      }   
     else
      {
        return ILLEGAL_DATA_ADDRESS;
      }
  }  
  else  
  {
    return ILLEGAL_DATA_VALUE;
  }
}

unsigned char check_func2_data(unsigned short quantity_of_inputs,
                               unsigned short start_addr)
{
   
  //проверяем корректно ли задано количество считываемых выходов
  if( 
     quantity_of_inputs >= MIN_MODBUS_VALUE_OUTPUTS_FUNC2 &&
     quantity_of_inputs <= MAX_MODBUS_VALUE_OUTPUTS_FUNC2
    )
  {     
    //проверяем адрес устройства
    if (check_addr_dig_inputs(quantity_of_inputs, start_addr))
      {
        response_ready = false;
        modbus_func_id = MODBUS_FUNC2;
        return SLAVE_DEVICE_BUSY; 
      }   
     else
      {
        return ILLEGAL_DATA_ADDRESS;
      }
  }  
  else  
  {
    return ILLEGAL_DATA_VALUE;
  }
}

unsigned char check_func3_data(unsigned short quantity_of_registers,
                               unsigned short start_addr)
{
  //проверяем корректно ли задано количество считываемых регистров
  if (
      quantity_of_registers >= MIN_MODBUS_VALUE_REGISTER_FUNC3 &&
      quantity_of_registers <= MAX_MODBUS_VALUE_REGISTER_FUNC3
     )
  {
    //сверяем входной адрес с адресами из адресного пространства карты памяти
    if (check_addr_measurements1(quantity_of_registers, start_addr)                     ||
        check_addr_measurements2(quantity_of_registers, start_addr)                     ||
        check_addr_measurements3(quantity_of_registers, start_addr)                     ||
        check_addr_angles(quantity_of_registers, start_addr)                            ||
        check_addr_sectors(quantity_of_registers, start_addr)                           ||
        check_addr_floating_measurements(quantity_of_registers, start_addr)             ||
        check_addr_dig_oscilograph(quantity_of_registers, start_addr)			||
	check_addr_yust(quantity_of_registers, start_addr)                  	        ||
        check_addr_activ_deactiv_ust(start_addr)					||
          
        check_addr_global(quantity_of_registers, start_addr)                            ||
        check_addr_ranking_DO1(quantity_of_registers, start_addr)                       ||
        check_addr_ranking_DI1(quantity_of_registers, start_addr)
        
        )
    {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC3;
      return SLAVE_DEVICE_BUSY;
    }
    else
    {
      return ILLEGAL_DATA_ADDRESS;
    }
  }
  else
  {
    return ILLEGAL_DATA_VALUE;
  }
}

unsigned char check_func5_data(unsigned short const_out,
                               unsigned short start_addr)
// проверяем значение константы
{
  if (const_out == 0xFF00 || const_out == 0x0000)
    //проверяем адрес устройства
  
    if(check_addr_of_outputs(1, start_addr))
    {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC5;
      return SLAVE_DEVICE_BUSY; 
    } 
      
    else
    {
      return ILLEGAL_DATA_ADDRESS;
    }
  
  return ILLEGAL_DATA_VALUE;  
}

unsigned char check_func6_data(unsigned short func_data,
                               unsigned short start_addr)
{
	if (check_addr_global(1, start_addr)) {
	    response_ready = false;
	    modbus_func_id = MODBUS_FUNC6;
	    return SLAVE_DEVICE_BUSY;
  } else if (start_addr == MA_PART_RECEIVE_DIG_OSCILOGRAPH) {
    if (func_data < NUMBER_REGISTER_DIG_OSCILOGRAPH / STEP_DIG_OSCILOGRAPH) {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC6;
      return SLAVE_DEVICE_BUSY;
    }
    return ILLEGAL_DATA_VALUE;
  } else if (start_addr == MA_PART_SETTINGS_FIRST_ADDR) {
    if (func_data == 1) {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC6;
      return SLAVE_DEVICE_BUSY;
    }
    return ILLEGAL_DATA_VALUE;
  } else if (check_addr_activ_deactiv_ust(start_addr)) {
    if (!ust_is_active && func_data != activatingUstValue) {
      return ILLEGAL_DATA_VALUE;
    } else if (ust_is_active && func_data != activatingUstValue) {
      ust_is_active = false;
      response_ready = false;
      modbus_func_id = MODBUS_FUNC6;
      return SLAVE_DEVICE_BUSY;
    } else if (func_data == activatingUstValue) {
      ust_is_active = true;
      response_ready = false;
      modbus_func_id = MODBUS_FUNC6;
      return SLAVE_DEVICE_BUSY;
    } else {
      return ILLEGAL_DATA_VALUE;
    }
  } else if (check_addr_yust(1, start_addr)) {
    response_ready = false;
    modbus_func_id = MODBUS_FUNC6;
    return SLAVE_DEVICE_BUSY;
  }
  return ILLEGAL_DATA_ADDRESS;
}

unsigned char check_func15_data(unsigned short quantity_of_outputs15,
                                unsigned char byte_count, unsigned short start_addr)
{
  //проверяем количество байт
 unsigned char N = quantity_of_outputs15 % 8 == 0 ? quantity_of_outputs15 >> 3 : (quantity_of_outputs15 >> 3) + 1 ;
  
   //проверяем корректно ли задано количество считываемых выходов  
  if  ( 
        quantity_of_outputs15 >= MIN_MODBUS_VALUE_OUTPUTS_FUNC15 &&
        quantity_of_outputs15 <= MAX_MODBUS_VALUE_OUTPUTS_FUNC15
        &&
        byte_count == N)  
    {   
            //проверяем адрес устройства
      if (check_addr_of_outputs(quantity_of_outputs15, start_addr))
        {
          response_ready = false;
          modbus_func_id = MODBUS_FUNC15;
          return SLAVE_DEVICE_BUSY;
        }   
      else  
        {
          return ILLEGAL_DATA_ADDRESS;
        }
    }
      return ILLEGAL_DATA_VALUE;
}

unsigned char check_func16_data(unsigned short quantity_of_registers,
                                unsigned char byte_count, unsigned short start_addr)
{ 
  //проверяем корректно ли задано количество регистров
  if (quantity_of_registers >= MIN_MODBUS_VALUE_REGISTER_FUNC3 && //константы для ф-ций 3 и 16 идентичны
      quantity_of_registers <= MAX_MODBUS_VALUE_REGISTER_FUNC3 &&
      byte_count == quantity_of_registers * 2) {   
    //проверяем адрес
    if (check_addr_settings(quantity_of_registers, start_addr)) {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC16;
      return SLAVE_DEVICE_BUSY;
    } else if (check_addr_yust(quantity_of_registers, start_addr)) {
      if (!ust_is_active) {
        return ILLEGAL_DATA_VALUE;
      }
      response_ready = false;
      modbus_func_id = MODBUS_FUNC16;
      return SLAVE_DEVICE_BUSY;
    }
    
    else if (check_addr_global(quantity_of_registers, start_addr))
    {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC16;
      return SLAVE_DEVICE_BUSY;
    }
   
    else if (check_addr_ranking_DO1(quantity_of_registers, start_addr))
    {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC16;
      return SLAVE_DEVICE_BUSY;
    }
    else if (check_addr_ranking_DI1(quantity_of_registers, start_addr))
    {
      response_ready = false;
      modbus_func_id = MODBUS_FUNC16;
      return SLAVE_DEVICE_BUSY;
    }
    
    else {
      return ILLEGAL_DATA_ADDRESS;
    }
  }
  return ILLEGAL_DATA_VALUE;
}

unsigned char check_data() {
  unsigned short func_data;
  unsigned short const_out;
  unsigned char byte_count;
  unsigned short quantity_of_registers;
  unsigned short quantity_of_outputs;
  unsigned short quantity_of_inputs;
  unsigned short quantity_of_outputs15;
  unsigned short start_addr = *(puchMsg + ADDRESS_OFFSET) << 8 |
                              *(puchMsg + ADDRESS_OFFSET + 1);
  //для каждой функции есть своя функция проверки которая запускается в
  //соответствии с кодом функции взятой из входного запроса
  switch (*(puchMsg + FUNCTION_CODE_OFFSET))
  {
    case MODBUS_FUNC1:
      quantity_of_outputs = *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC1_OFFSET) << 8 |
                            *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC1_OFFSET + 1);
      return check_func1_data(quantity_of_outputs, start_addr);
      
    case MODBUS_FUNC2:
      quantity_of_inputs = *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC1_OFFSET) << 8 |
                           *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC1_OFFSET + 1);
      return check_func2_data(quantity_of_inputs, start_addr);
    case MODBUS_FUNC3:
    case MODBUS_FUNC4:
      quantity_of_registers = *(puchMsg + QUANTITY_OF_REGISTERS_FUNC3_OFFSET) << 8 |
                              *(puchMsg + QUANTITY_OF_REGISTERS_FUNC3_OFFSET + 1);
      return check_func3_data(quantity_of_registers, start_addr);
      
    case MODBUS_FUNC5:
      const_out = *(puchMsg + CONST_OUT_ADDRESS_FUNC5_OFFSET) << 8 |
                  *(puchMsg + CONST_OUT_ADDRESS_FUNC5_OFFSET + 1);
      
      return check_func5_data(const_out, start_addr);
      
    case MODBUS_FUNC6:
      func_data = *(puchMsg + DATA_FUNC6_OFFSET) << 8 |
                  *(puchMsg + DATA_FUNC6_OFFSET + 1);
      return check_func6_data(func_data, start_addr);
      
    case MODBUS_FUNC15:
       quantity_of_outputs15 = *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC15_OFFSET) << 8 |
                                *(puchMsg + QUANTITY_OF_OUTPUTS_FUNC15_OFFSET + 1);
       
       byte_count = *(puchMsg + NUMBER_OF_BYTES_FUNC15_OFFSET);
       return check_func15_data(quantity_of_outputs15, byte_count, start_addr);
       
     case MODBUS_FUNC16:
       quantity_of_registers = *(puchMsg + QUANTITY_OF_REGISTERS_FUNC16_OFFSET) << 8 |
                               *(puchMsg + QUANTITY_OF_REGISTERS_FUNC16_OFFSET + 1);
       byte_count = *(puchMsg + NUMBER_OF_BYTES_FUNC16_OFFSET);
       return check_func16_data(quantity_of_registers, byte_count, start_addr);
     
    default:
      //Неопределенная ошибка
      return ILLEGAL_DATA_VALUE;
  }
}

_Bool check_func_code(unsigned char func_code)
{
  for (unsigned int i = 0; i < sizeof(modbus_func_code_arr); i++)
  {
    if (func_code == modbus_func_code_arr[i]) return true;
  }
  return false;
}

void clear_all_updating_state(unsigned short quantity_of_registers, unsigned short address)
{
  if (!check_addr_yust(quantity_of_registers, address)) {
    yust_values_is_updated = false;
  }
}

void reset_all_modbus_modes()
{
  modbus_dev_state = DEV_FREE;
  source_id = NULL_SOURCE;
  modbus_func_id = MODBUS_EMPTY_FUNC;
  start_update_adc = false;
  start_update_yust_values = false;
  get_settings = false;
  send_settings = false;
  get_yust = false;
  send_yust = false;
//  data_ADC_index = 0;
  response_ready = true;
  read_yust_counter = 0;
}

