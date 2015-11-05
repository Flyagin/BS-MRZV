#include "header_mal.h"

/***********************
Функція очистки таблиці заповненості

-----------------------
Вхідні параметри:
-----------------------
Немає
-----------------------

-----------------------
Вихідні значення:
-----------------------
Немає
-----------------------
***********************/
void clean_table_data_dr(void)
{
  /*
  У таблиці заповненості помічаємо , що всі блоки є пустими і формуємо правильну
  контрольну суму
  */
  unsigned char checksum = 0;
  for (unsigned int i = 0; i < NUMBER_DATA_BLOCKS; i++) 
  {
    table_data_ar[i] = DATA_BLOCK_EMPTY;
    checksum += DATA_BLOCK_EMPTY;
  }
  table_data_ar[NUMBER_DATA_BLOCKS] = checksum;
}
/********************/

/***********************
Функція управління обмінами між програмою і мікросхемою DataFlash
аналогового реєстратора

-----------------------
Вхідні параметри:
-----------------------
Немає
-----------------------

-----------------------
Вихідні значення:
-----------------------
Немає
-----------------------
***********************/
void main_routines_for_ar(void)
{
  static unsigned int base_address;
  static int unprocessed_size;
  static int size_to_process;
  if (
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT) == 0) &&
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT    ) == 0) &&
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT ) == 0) &&
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT    ) == 0) &&
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_AR_BIT       ) == 0) &&
      (_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT           ) == 0)
     )
  {
    //Можна або починати нову операцію з аналоговим реєстратором, або аналізувати виконану
    if ((control_ar_taskes & (1 << TASK_WRITING_TABLE_DATA)) != 0)
    {
      //Змінюємо вхідні величини для продовження запису
      base_address += size_to_process;
      unprocessed_size -= size_to_process;
      
      if ( unprocessed_size > 0)
      {
        //Запис ще не завершений
        
        //Визначаємо скільки за одну операцію можемо записати
        if (unprocessed_size >= SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR)
          size_to_process = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        else
          size_to_process = unprocessed_size;
        
        //Починаємо читати
        for (int i = 0; i < size_to_process; i++) buffer_serial_DataFlash_read_write_ar[i] = table_data_ar[(base_address - GLOBAL_ADDRESS_TABLE_AR) + i];
        address_read_write_ar = base_address;
        number_bytes_read_write_ar = size_to_process;
        _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
        //Вся таблиця заповненості записана
        control_ar_taskes &= (unsigned int)(~(1 << TASK_WRITING_TABLE_DATA));
      }
    }
    else if ((control_ar_taskes & (1 << TASK_READING_TABLE_DATA)) != 0)
    {
      //Забираємо прочитані дані
      for (int i = 0; i < size_to_process; i++) table_data_ar[(base_address - GLOBAL_ADDRESS_TABLE_AR) + i] = buffer_serial_DataFlash_read_write_ar[i];
      base_address += size_to_process;
      unprocessed_size -= size_to_process;
      
      if ( unprocessed_size > 0)
      {
        //Читання ще все не завершене
        
        //Визначаємо скільки за одну операцію можемо прочитати
        if (unprocessed_size >= SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR)
          size_to_process = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        else
          size_to_process = unprocessed_size;
        
        //Починаємо читати
        address_read_write_ar = base_address;
        number_bytes_read_write_ar = size_to_process;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
        //Вся таблиця заповненості прочитана
        control_ar_taskes &= (unsigned int)(~(1 << TASK_READING_TABLE_DATA));

        //Перевіряємо конрольну суму
        unsigned char checksum = 0;
        for (unsigned int i = 0; i < NUMBER_DATA_BLOCKS; i++ ) checksum += table_data_ar[i];
        if (checksum == table_data_ar[NUMBER_DATA_BLOCKS]) _CLEAR_BIT(diagnostyka, ERROR_AR_TABLE_DATA);
        else 
        {
          //Зафіксовано недостовірні дані
          _SET_BIT(diagnostyka, ERROR_AR_TABLE_DATA);
          
          //Очищуємо таблицю заповненості
          clean_table_data_dr();
          
          //Починаємо запис відновленої таблиці заповненості
          control_ar_taskes |= (1 << TASK_START_WRITE_TABLE_DATA);
        }
      }
    }
    else if ((control_ar_taskes & (1 << TASK_START_WRITE_TABLE_DATA)) != 0)
    {
      //Визначаэмо початкову адресу початкову кількість зчитуваних байт
      base_address = GLOBAL_ADDRESS_TABLE_AR;
      unprocessed_size = NUMBER_DATA_BLOCKS + 1;
      size_to_process = 0;
      
      control_ar_taskes |= (1 << TASK_WRITING_TABLE_DATA);
      control_ar_taskes &= (unsigned int)(~(1 << TASK_START_WRITE_TABLE_DATA));
    }
    else if ((control_ar_taskes & (1 << TASK_START_READ_TABLE_DATA)) != 0)
    {
      //Визначаэмо початкову адресу початкову кількість зчитуваних байт
      base_address = GLOBAL_ADDRESS_TABLE_AR;
      unprocessed_size = NUMBER_DATA_BLOCKS + 1;
      size_to_process = 0;
      
      control_ar_taskes |= (1 << TASK_READING_TABLE_DATA);
      control_ar_taskes &= (unsigned int)(~(1 << TASK_START_READ_TABLE_DATA));
    }
  }
  else
  {
    //Ще не завершилася попередня операція обміну
  }
      
}
/********************/

