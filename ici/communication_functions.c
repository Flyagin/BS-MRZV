
#include <stdio.h>

#include "communication_constants.h"
#include "modbus_header.h"

#include "header_mal.h"

unsigned char source_id = NULL_SOURCE;

extern unsigned short CRC16(unsigned char* arr, unsigned short size);

extern void start_response(unsigned char*, unsigned int);

extern _Bool check_func_code(char code);

extern unsigned char check_data();

//------------------------------------------------------------------------------
///Обработчик запросов USB, RS-485, TCP_IP
//------------------------------------------------------------------------------
void request_handler(unsigned short size)
{
  unsigned short crc16;
  unsigned char response[256];
  //Проверка источника запроса
  switch (source_id)
  {
    case USB_SOURCE:
      if (!response_ready) break;
      if (modbus_dev_state == DEV_FREE) {
        //Проверка CRC и адреса
        if (
             CRC16(puchMsg, size - NUMBER_CRC_BYTES) !=
             (
               *(puchMsg + size - NUMBER_CRC_BYTES) << 8 |
               *(puchMsg + size - (NUMBER_CRC_BYTES - 1))
              )
             ||
             *puchMsg != modbus_address
           )
        {
          //CRC не совпала (игнорируем пакет)
          break;
        }
        //Проверка кода функции
        if (!check_func_code(*(puchMsg + FUNCTION_CODE_OFFSET)))
        {
          //Неверный код функции
          modbus_dev_state = ILLEGAL_FUNCTION;
          break;
        }
        //Проверка данных
        modbus_dev_state = check_data();
      } else {
        response[0] = modbus_address;
        response[1] = 0x8F;
        response[2] = SLAVE_DEVICE_BUSY;
        crc16 = CRC16(response, 3);
        response[3] = (crc16 & 0xFF00) >> 8;
        response[4] = crc16 & 0xFF;
        start_response(response, 5);
        break;
      }
      break;
    case RS_485_SOURCE:
      if (modbus_dev_state == DEV_FREE) {
        //Проверка CRC и адреса
        if (
             CRC16(puchMsg, size - NUMBER_CRC_BYTES) !=
             (
               *(puchMsg + size - NUMBER_CRC_BYTES) << 8 |
               *(puchMsg + size - (NUMBER_CRC_BYTES - 1))
              )
             ||
             *puchMsg != modbus_address
           )
        {
          //CRC не совпала (игнорируем пакет)
          break;
        }
        //Проверка кода функции
        if (!check_func_code(*(puchMsg + FUNCTION_CODE_OFFSET)))
        {
          //Неверный код функции
          modbus_dev_state = ILLEGAL_FUNCTION;
          break;
        }
        //Проверка данных
        modbus_dev_state = check_data();
      } else {
        response[0] = modbus_address;
        response[1] = 0x8F;
        response[2] = SLAVE_DEVICE_BUSY;
        crc16 = CRC16(response, 3);
        response[3] = (crc16 & 0xFF00) >> 8;
        response[4] = crc16 & 0xFF;
        start_response(response, 5);
        break;
      }
      break;
    case TCP_IP_SOURCE:
      
      break;
    default:
      //неопределенная ошибка
      break;
  }
  
}
