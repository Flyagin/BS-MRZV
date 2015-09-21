
#include "modbus_header.h"
#include "communication_constants.h"

#include "header_mal.h"

extern void clear_all_updating_state(unsigned short, unsigned short);
extern void reset_all_modbus_modes();

extern void start_response(unsigned char*, unsigned int);

extern unsigned char source_id;

void modbus_routines()
{
  unsigned short crc16;
  unsigned char response[256];
  switch (modbus_dev_state) {
    
    case DEV_FREE:
      //do nothing
      break;
    
    case ILLEGAL_FUNCTION:
      response[0] = eeprom_bs_settings_tbl.RS_comm_addres;
      response[1] = 0x8F;
      response[2] = ILLEGAL_FUNCTION;
      crc16 = CRC16(response, 3);
      response[3] = (crc16 & 0xFF00) >> 8;
      response[4] = crc16 & 0xFF;
      start_response(response, 5);
      clear_all_updating_state(0, 0);
      reset_all_modbus_modes();
      break;
      
    case ILLEGAL_DATA_ADDRESS:
      response[0] = eeprom_bs_settings_tbl.RS_comm_addres;
      response[1] = modbus_func_id | 0x80;
      response[2] = ILLEGAL_DATA_ADDRESS;
      crc16 = CRC16(response, 3);
      response[3] = (crc16 & 0xFF00) >> 8;
      response[4] = crc16 & 0xFF;
      start_response(response, 5);
      clear_all_updating_state(0, 0);
      reset_all_modbus_modes();
      break;
      
    case ILLEGAL_DATA_VALUE:
      response[0] = eeprom_bs_settings_tbl.RS_comm_addres;
      response[1] = modbus_func_id | 0x80;
      response[2] = ILLEGAL_DATA_VALUE;
      crc16 = CRC16(response, 3);
      response[3] = (crc16 & 0xFF00) >> 8;
      response[4] = crc16 & 0xFF;
      start_response(response, 5);
      clear_all_updating_state(0, 0);
      reset_all_modbus_modes();
      break;
      
    case SLAVE_DEVICE_FAILURE:
      response[0] = eeprom_bs_settings_tbl.RS_comm_addres;
      response[1] = modbus_func_id | 0x80;
      response[2] = SLAVE_DEVICE_FAILURE;
      crc16 = CRC16(response, 3);
      response[3] = (crc16 & 0xFF00) >> 8;
      response[4] = crc16 & 0xFF;
      start_response(response, 5);
      clear_all_updating_state(0, 0);
      reset_all_modbus_modes();
      break;
      
    case SLAVE_DEVICE_BUSY:
        switch (modbus_func_id) {
          case MODBUS_FUNC1:
            func1();
            break;
          case MODBUS_FUNC3:
            func3();
            break;
          case MODBUS_FUNC5:
            func5();
            break;
          case MODBUS_FUNC6:
            func6();
            break;
          case MODBUS_FUNC15:
            func15();
            break;
          case MODBUS_FUNC16:
            func16();
            break;
          default:
            //Неопределенная ошибка
            clear_all_updating_state(0, 0);
            reset_all_modbus_modes();
            break;
        }
      break;
      
    default:
      //Неопределенная ошибка
      clear_all_updating_state(0, 0);
      reset_all_modbus_modes();
      break;
  }

}

