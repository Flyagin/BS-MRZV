#include "header_mal.h"


/**********
Startova konfiguracia SPI1 dlja konfiguruvannja EEPROM, RTC i DataFlash
**********/
void ConfigureSPI1(void)
{
  Pin SPI1_pins[] = {PINS_SPI1_CS_ALL, PINS_SPI1};
  PIO_Configure(SPI1_pins, PIO_LISTSIZE(SPI1_pins));
  
  //Mode-Register
  unsigned int SPI1_Config = AT91C_SPI_MSTR | AT91C_SPI_PS_VARIABLE | AT91C_SPI_MODFDIS |(AT91C_SPI_PCS & (0<<16));
  SPI_Configure(AT91C_BASE_SPI1, AT91C_ID_SPI1, SPI1_Config);

  // RTC
  unsigned int RTC_ConfigNPCS = AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (14<<8) | /*AT91C_SPI_CSAAT|*/ (AT91C_SPI_DLYBCT & (10 << 24)));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 0, RTC_ConfigNPCS);
  
  // EEPROM
  unsigned int EEPROM_ConfigNPCS =  AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (72<<8) | /*AT91C_SPI_CSAAT |*/ (AT91C_SPI_DLYBCT & (3 << 24)));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 1, EEPROM_ConfigNPCS);
  
  // Data Flash DR
  unsigned int DataFlashDigit_ConfigNPCS =   AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (9<<8)) | (AT91C_SPI_DLYBCT & (6 << 24));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 2, DataFlashDigit_ConfigNPCS);
  
  // Data Flash AR
  unsigned int DataFlashAnalog_ConfigNPCS =   AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (9<<8)) | (AT91C_SPI_DLYBCT & (6 << 24));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 3, DataFlashAnalog_ConfigNPCS);

  //Instalation PDC for SPI1
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
  AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RCR = 0;
  AT91C_BASE_SPI1->SPI_RNCR = 0;
  AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TCR = 0;
  AT91C_BASE_SPI1->SPI_TNCR = 0;
  
  AT91C_BASE_SPI1->SPI_SR;
  //Enable SPI1
  SPI_Enable(AT91C_BASE_SPI1);
  while ((AT91C_BASE_SPI1->SPI_SR & AT91C_SPI_RDRF) != 0) AT91C_BASE_SPI1->SPI_RDR;
}
/*********/

/*****************************************************/
//Запуск обміну по SPI1
/*****************************************************/
void start_exchange_via_SPI1(unsigned int device_type, unsigned int number)
{
  //Позначаємо, що іде одмін по каналу SPI1
  state_execution_spi1 = 0;

  //Зупиняємо SPI1_PDC якщо він запущений і виставляємо, скільки треба буде зараз передавати
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
  AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RCR = number;
  AT91C_BASE_SPI1->SPI_RNCR = 0;
  AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TCR = number;
  AT91C_BASE_SPI1->SPI_TNCR = 0;

  //Виставляємо chip_select
  unsigned int chip_select = 0x000f0000;
  switch (device_type)
  {
  case SPI1_RTC:
    {
      chip_select = 0x00000000;
      break;
    }
  case SPI1_EEPROM:
    {
      chip_select = 0x00010000;
      break;
    }
  case SPI1_DF_DR:
    {
      chip_select = 0x00030000;
      break;
    }
  case SPI1_DF_AR:
    {
      chip_select = 0x00070000;
      break;
    }
  default:
    {
      //Відбцлася невизначена помилка, тому треба піти на перезавантаження
      while(1);
    }
  }
  for (unsigned int i = 0; i < number; i++) Temporaty_SPI1_Buffer_Tx_with_CS[i] = Temporaty_SPI1_Buffer_Tx[i] | chip_select;
  number_transmit_SPI1 = number;
  
  //Очищаємо можливі помилкит
  AT91C_BASE_SPI1->SPI_RDR;
  while ((AT91C_BASE_SPI1->SPI_SR & AT91C_SPI_RDRF) != 0) AT91C_BASE_SPI1->SPI_RDR;


  //Запускаємо прийом-передачу 
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTEN | AT91C_PDC_RXTEN);
}
/*****************************************************/

/*****************************************************/
//Управління обміном через SPI
/*****************************************************/
void main_routines_for_spi1(void)
{
  //Статична змінна, яка вказує який блок настройок треба записувати у EEPROM
  static unsigned int number_block_settings_prt_write_to_eeprom;
  //Статична змінна, яка вказує який блок настройок треба записувати у EEPROM
  static unsigned int number_block_settings_bs_write_to_eeprom;
  //Статична змінна, яка вказує який блок юстування треба записувати у EEPROM
  static unsigned int number_block_ustuvannja_write_to_eeprom;
  //Статична змінна, яка вказує який блок стану виходів і світлоіндикаторів треба записувати у EEPROM
  static unsigned int number_block_state_leds_outputs_write_to_eeprom;
  //Статична змінна, яка вказує який блок стану триґерних функцій треба записувати у EEPROM
  static unsigned int number_block_state_trg_func_write_to_eeprom;
  //Статична змінна, яка вказує який блок інформації по аналоговому реєстратору треба записувати у EEPROM
  static unsigned int number_block_info_rejestrator_ar_write_to_eeprom;
  //Статична змінна, яка вказує який блок інформації по дискретному реєстратору треба записувати у EEPROM
  static unsigned int number_block_info_rejestrator_dr_write_to_eeprom;
  //Статична змінна, яка вказує який блок інформації по реєстраторі програмних подій треба записувати у EEPROM
  static unsigned int number_block_info_rejestrator_pr_err_write_to_eeprom;

  static unsigned int temp_value_for_rtc;

  //Тимчасові статичні змінні, які потрібні для виконання операцій читанння/запису мікросхеми DataFlash
  static unsigned int address_read_write_ar_tmp, number_bytes_read_write_ar_tmp;
  static int etap_writing_df_ar;
  static unsigned int address_read_write_dr_tmp, number_bytes_read_write_dr_tmp;
  static int etap_writing_df_dr;
  
  //Статичні змінні для контролю коректності запису
  static CfgTblDsc eeprom_prt_tbl_comp;
  static AuxCfgTbl1Dsc eeprom_bs_settings_tbl_comp;
  static unsigned int ustuvannja_comp[NUMBER_CANALS], phi_ustuvannja_comp[NUMBER_CANALS], ustuvannja_P_comp[3], ustuvannja_Q_comp[3];
  static unsigned int state_trigger_leds_comp, state_signal_outputs_comp;
  static unsigned int trigger_active_functions_comp[N_TMP];
  static __TEMP_STRUCTURE EepromARecDesc_comp;
  static __TEMP_STRUCTURE EepromDRecDesc_comp;
  static __TEMP_STRUCTURE EepromErrRecDesc_comp;
  
  if (state_execution_spi1 == 0)
  {
    //Vidbuvajetsja obmin
    unsigned int status_SPI1 = AT91C_BASE_SPI1->SPI_SR;
    
    if (
        ((status_SPI1 & (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) == (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) ||
        ((status_SPI1 & AT91C_SPI_OVRES) != 0)
       )   
    {
      if ((status_SPI1 & AT91C_SPI_OVRES) != 0)
      {
        //Fiksacija pomylky pid chas opbinu
        state_execution_spi1 = 2;

        /*Виставляємо повідомлення про помилку обміну через SPI_RED*/
        _SET_BIT(diagnostyka, ERROR_SPI_RED_BIT);
      }
      else if ((status_SPI1 & (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) == (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE))
      {
        //Fiksacija zavershennja obminu
        for (unsigned int i = 0; i < number_transmit_SPI1; i++) Temporaty_SPI1_Buffer_Rx[i] = Temporaty_SPI1_Buffer_Rx_with_CS[i] & 0xff;
        state_execution_spi1 = 1;

        //Обмін відбувся вдало - скидаємо повідомлення про попередньо можливу помилку обміну через SPI_RED
        _CLEAR_BIT(diagnostyka, ERROR_SPI_RED_BIT);
      }
      
      AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
      AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
      AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
      AT91C_BASE_SPI1->SPI_RCR = 0;
      AT91C_BASE_SPI1->SPI_RNCR = 0;
      AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
      AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
      AT91C_BASE_SPI1->SPI_TCR = 0;
      AT91C_BASE_SPI1->SPI_TNCR = 0;
      number_transmit_SPI1 = 0;
    }
  }
  
  if (state_execution_spi1 < 0)
  {
    /*************************************************/
    //Зараз можна ініціювати нову трансакцію через SPI
    /*************************************************/
    
    if (
        ((control_spi1_taskes[0] & (MASKA_ACTION_DF_AR_0 | MASKA_ACTION_DF_DR_0)) != 0) ||
        ((control_spi1_taskes[1] & (MASKA_ACTION_DF_AR_1 | MASKA_ACTION_DF_DR_1)) != 0)
       ) 
    {    
      //Стоять у черзі команди для DataFlash
      if ((AR_DR & _DF_LOCK) == 0)
      {
        //Не потрібно завершувати якусь почату операцію по DataFlash
        if      (
                 (
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_AR_0) != 0) ||
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_AR_1) != 0)
                 )
                 &&  
                 (  
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_DR_0) == 0) &&
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_DR_1) == 0)
                 )   
                ) 
        {
          //Стоять у черзі на обробку тільки задачі для аналогового реєстратора
          AR_DR = _DF_AR | _DF_LOCK;
        }
        else if (
                 (
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_DR_0) != 0) ||
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_DR_1) != 0)
                 )
                 &&  
                 (  
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_AR_0) == 0) &&
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_AR_1) == 0)
                 )   
                ) 
        {
          //Стоять у черзі на обробку тільки задачі для дискретного реєстратора
          AR_DR = _DF_DR | _DF_LOCK;
        }
        else
        {
          //Стоять у черзі на обробку задачі і для аналогового реєстратора, і для дискретного реєстратора
          if (AR_DR == _DF_AR) AR_DR = _DF_DR | _DF_LOCK;
          else  AR_DR = _DF_AR | _DF_LOCK;
        }
      }
    }
    else AR_DR = _DF_NONE;
      
    unsigned int AR_DR_tmp = AR_DR & (unsigned int)(~_DF_LOCK);
    
    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0)
    {
      //Виставляння регістрів RTC у потрібні стартові значення для того, щоб на виході мати 1 Гц
      if (etap_settings_test_frequency == 0)
      {
        //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xC;
        Temporaty_SPI1_Buffer_Tx[1] = temp_register_rtc[0];
      
        //Запускаємо процес запису в RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
      else if (etap_settings_test_frequency == 1)
      {
        //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0x13;
        Temporaty_SPI1_Buffer_Tx[1] = 0xf0;
      
        //Запускаємо процес запису в RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
      else
      {
        //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xA;
        Temporaty_SPI1_Buffer_Tx[1] = temp_register_rtc[1];
      
        //Запускаємо процес запису в RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
    }
    else if((_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0) || (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0))
    {
      //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)

      if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0)
      {
        //Скидання OF-біт в RTC
        if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_STOP)
          Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] | (1<<7); //ST = 1
        else if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_CLEAR)
          Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] & (~(1<<7)) ; //ST = 0
        else
          Temporaty_SPI1_Buffer_Tx[1] = (unsigned char)(temp_value_for_rtc) & (~(1<<2)) ; //OF = 0
      }
      else
      {
        Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] & (~(1<<7)) ; //ST = 0;
      }
      
      //Запускаємо процес запису в RTC
      if ((_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0) && (etap_reset_of_bit != ETAP_CLEAR_OF_ST_STOP) && (etap_reset_of_bit != ETAP_CLEAR_OF_ST_CLEAR))
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xF;
      else
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0x1;

      start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
    }
    else if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) !=0)
    {
      unsigned int number;
      
      //Формуємо буфер для передачі у  EEPROM (біт запису + початкова адреса - інформаційні байти)
      if ((etap_eeprom_write_enable < 0) || ((etap_eeprom_write_enable > 1))) etap_eeprom_write_enable = 0;

      if (etap_eeprom_write_enable == 0)
      {
        //Читаємо регістр статусу
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_RDSR;
        Temporaty_SPI1_Buffer_Tx[1] = 0; //Будь-який байт для того, щоб здійснити читання регістру статусу;
        number = 2;
      }
      else if (etap_eeprom_write_enable == 1)
      {
        //Читаємо регістр статусу
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WREN;
        number = 1;
      }
      
      //Запускаємо процес запису в EEPROM
      start_exchange_via_SPI1(SPI1_EEPROM, number);
    }
    else if(
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
           )   
    {
      //Читаємо регістр статусу з мікросхеми DataFlash
      Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_STATUS_READ;
      Temporaty_SPI1_Buffer_Tx[1] = 0; //Будь-який байт для того, щоб здійснити читання регістру статусу;
      
      //Запускаємо процес запису в EEPROM
      AR_DR = AR_DR_tmp;
      start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, 2);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку у EEPROM настройок

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_settings_prt_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(eeprom_prt_tbl) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_SETTINGS_PRT_IN_EEPROM + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання настройок у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_SETTINGS_PRT_IN_EEPROM + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання настройок у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив настройок вже записаний, тому скидаємо умову запису настройок у EEPROM

        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_SETTINGS_PRT;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
        
        //Скидаємо умову запису настройок у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку у EEPROM настройок БС

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_settings_bs_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(eeprom_bs_settings_tbl) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_SETTINGS_BS_IN_EEPROM + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання настройок у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_SETTINGS_BS_IN_EEPROM + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання настройок у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив настройок вже записаний, тому скидаємо умову запису настройок у EEPROM

        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_SETTINGS_BS;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
        
        //Скидаємо умову запису настройок у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку у EEPROM юстування

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_ustuvannja_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (SIZE_USTUVANNJA + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_USTUVANNJA_IN_EEPROM + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання юстування і серійного номеру у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_USTUVANNJA_IN_EEPROM + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання юстування і серійного номеру у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив юстування вже записаний

        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_USTUVANNJA;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
        
        //Скидаємо умову запису юстування у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку у EEPROM стану виходів і світлоіндикаторів

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_state_leds_outputs_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = 4 - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання стану виходів і світлоіндикаторів у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання стану виходів і світлоіндикаторів у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив стану виходів і світлоіндикаторів вже записаний, тому скидаємо умову запису стану виходів і світлоіндикаторів у EEPROM

        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_STATE_LEDS_OUTPUTS;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);

        //Cкидаємо умову запису станів виходів-світлоіндикаторів у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку у EEPROM стану триґерних функцій

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_state_trg_func_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(trigger_active_functions) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання стану триґерних функцій у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання стану триґерних функцій у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив стану триґерних функцій вже записаний, тому скидаємо умову запису стану триґерних функцій у EEPROM

        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_TRG_FUNC;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);

        //Cкидаємо умову запису станів триґерних функцій у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку інформації аналогового реєстратора у EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_info_rejestrator_ar_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(EepromARecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_AR + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання структури аналогового реєстратора у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_AR + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання структури аналогового реєстратора у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив вже записаний
       
        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_AR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);

        //Cкидаємо умову запису інформації аналогового реєстратора у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку інформації дискретного реєстратора у EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_info_rejestrator_dr_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(EepromDRecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_DR + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання структури дискретного реєстратора у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_DR + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання структури дискретного реєстратора у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив вже записаний
       
        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_DR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);

        //Cкидаємо умову запису інформації дискретного реєстратора у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //Стоїть умова запису блоку інформації реєстратора програмних подій у EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //Визначаємо з якого місця треба почати записувати
      offset_from_start = number_block_info_rejestrator_pr_err_write_to_eeprom*SIZE_PAGE_EEPROM;

      //Кількість байт до кінця буферу 
      size_to_end = (sizeof(EepromErrRecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_PR_ERR + offset_from_start) >> 8) & 0xff; //старша  адреса початку зберігання структури реєстратора програмних подій у EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_PR_ERR + offset_from_start)     ) & 0xff; //молодша адреса початку зберігання структури реєстратора програмних подій у EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //Переміщаємо дані для запису до опкоду з адресою початку запису для того, щоб сформувати цілий масив для передачі по PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //Запускаємо процес запису в EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //Весь масив вже записаний
       
        //Виставляємо команду контрольного читання для перевідрки достовірності записаної інформації
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);

        //Cкидаємо умову запису інформації реєстратора програмних подій у EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання юстування - формуємо буфер для передавання в EEPROM щоб прочитати юстування і серійний номер
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_USTUVANNJA_IN_EEPROM >> 8) & 0xff; //старша  адреса початку зберігання юстування і серійного номеру у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_USTUVANNJA_IN_EEPROM     ) & 0xff; //молодша адреса початку зберігання юстування і серійного номеру у EEPROM
                                                                                      //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((SIZE_USTUVANNJA + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання настройок - формуємо буфер для передавання в EEPROM щоб прочитати настройки
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_SETTINGS_PRT_IN_EEPROM >> 8) & 0xff; //старша  адреса початку зберігання настройок у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_SETTINGS_PRT_IN_EEPROM     ) & 0xff; //молодша адреса початку зберігання настройок у EEPROM
                                                                                    //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(eeprom_prt_tbl) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання настройок - формуємо буфер для передавання в EEPROM щоб прочитати настройки БС
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_SETTINGS_BS_IN_EEPROM >> 8) & 0xff; //старша  адреса початку зберігання настройок БС у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_SETTINGS_BS_IN_EEPROM     ) & 0xff; //молодша адреса початку зберігання настройок БС у EEPROM
                                                                                    //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(eeprom_bs_settings_tbl) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання  даних про сигнальні виходи і тригерні свтлодіоди - формуємо буфер для передавання в EEPROM щоб прочитати  дані про сигнальні виходи і тригерні свтлодіоди
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM >> 8) & 0xff; //старша  адреса початку зберігання даних про сигнальні виходи і тригерні свтлодіоди у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM     ) & 0xff; //молодша адреса початку зберігання даних про сигнальні виходи і тригерні свтлодіоди у EEPROM
                                                                                              //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, (4 + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання  даних про ОТ - формуємо буфер для передавання в EEPROM щоб прочитати  дані про ОТ
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM >> 8) & 0xff; //старша  адреса початку зберігання даних про ОТ у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM     ) & 0xff; //молодша адреса початку зберігання даних про ОТ у EEPROM
                                                                                          //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(trigger_active_functions) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання інформації по аналоговому реєстратору - формуємо буфер для передавання в EEPROM щоб прочитати  дані по аналоговому реєстратору
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_AR >> 8) & 0xff; //старша  адреса початку зберігання даних по аналоговому реєстратору у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_AR     ) & 0xff; //молодша адреса початку зберігання даних по аналоговому реєстратору у EEPROM
                                                                                      //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromARecDesc) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання інформації по дискретному реєстратору - формуємо буфер для передавання в EEPROM щоб прочитати  дані по дискретному реєстратору
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_DR >> 8) & 0xff; //старша  адреса початку зберігання даних по дискретному реєстратору у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_DR     ) & 0xff; //молодша адреса початку зберігання даних по дискретному реєстратору у EEPROM
                                                                                      //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromDRecDesc) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //Запускаємо процес читання інформації по реєстратору програмних подій - формуємо буфер для передавання в EEPROM щоб прочитати  дані по реєстратору програмних подій
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_PR_ERR >> 8) & 0xff; //старша  адреса початку зберігання даних по реєстратору програмних подій у EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_PR_ERR     ) & 0xff; //молодша адреса початку зберігання даних по реєстратору програмних подій у EEPROM
                                                                                          //дальше значення байт не має значення
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromErrRecDesc) + 1) + 3));
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //Запускаємо процес переводу мікросхеми DataFlash не розмір сторінки у 256 байт
//      Temporaty_SPI1_Buffer_Tx[0] = 0x3D;
//      Temporaty_SPI1_Buffer_Tx[1] = 0x2A;
//      Temporaty_SPI1_Buffer_Tx[2] = 0x80;
//      Temporaty_SPI1_Buffer_Tx[3] = 0xA6;
//
//      start_exchange_via_SPI1(SPI1_DF, 4);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //Запускаємо процес стирання мікросхеми DataFlash
      Temporaty_SPI1_Buffer_Tx[0] = 0xC7;
      Temporaty_SPI1_Buffer_Tx[1] = 0x94;
      Temporaty_SPI1_Buffer_Tx[2] = 0x80;
      Temporaty_SPI1_Buffer_Tx[3] = 0x9A;

      AR_DR = AR_DR_tmp;
      start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, 4);
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //Стоїть умова запису мікросхеми DataFlash
      unsigned int size_page, size_buffer;
               int *point_to_etap_writing_df;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_number_bytes_read_write;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int *buffer_serial_DataFlash_read_write;
      
      if (AR_DR_tmp == _DF_AR)
      {
        size_page = SIZE_PAGE_SERIAL_DATAFLASH_AR;
        size_buffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        point_to_etap_writing_df = &etap_writing_df_ar;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_ar;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_ar;
      }
      else
      {
        size_page = SIZE_PAGE_SERIAL_DATAFLASH_DR;
        size_buffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR;
        point_to_etap_writing_df = &etap_writing_df_dr;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_dr;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_dr;
      }

      unsigned int _PA, _BA;
      _PA = *point_to_address_read_write_tmp / size_page;
      _BA = *point_to_address_read_write_tmp - _PA*size_page;
      
      if (*point_to_etap_writing_df == ETAP_WRITING_DF_NONE)
      {
        //Треба почати нову операцію

        //Кількість байт до кінця буферу 
        int size_to_end = *point_to_number_bytes_read_write - (*point_to_address_read_write_tmp - *point_to_address_read_write);

        if (size_to_end > 0)
        {
          int size_from_begin_page = *point_to_address_read_write_tmp % size_page;
          if (
              (size_to_end >= (int)size_page)  &&
              (size_from_begin_page == 0)
             )
          {
            //Можна записувати зразу цілу сторінку операцією "Main Memory Page Program Through Buffer"
            *point_to_number_bytes_read_write_tmp = size_page;
            
            *point_to_etap_writing_df = ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER;
          }
          else
          {
            //Треба виконувати "довгий ланцюжок операцій" для запису і починається він з операції "Main Memory Page to Buffer Transfer"
            int size_to_end_page = size_page - size_from_begin_page;
            if (size_to_end > size_to_end_page) *point_to_number_bytes_read_write_tmp = size_to_end_page;
            else *point_to_number_bytes_read_write_tmp = size_to_end;
            
            *point_to_etap_writing_df = ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER;
          }
        }
        else
        {
          //Весь масив вже записаний, тому скидаємо умову запису мікросхеми DataFlash
          *point_to_number_bytes_read_write_tmp = 0;
          
          *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
        }
      }
      
      unsigned int number_transmit;
      
      switch (*point_to_etap_writing_df)
      {
      case ETAP_WRITING_DF_NONE:
        {
          //Треба завершити процедуру запису
          _CLEAR_BIT(control_spi1_taskes, ((AR_DR_tmp == _DF_AR) ? TASK_WRITING_SERIAL_DATAFLASH_AR_BIT : TASK_WRITING_SERIAL_DATAFLASH_DR_BIT));
          break;
        }
      case ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER:
        {
          //Треба зчитати визначену цілу сторінку у пам'ять мікросхеми DataFlash 
          
          unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
          if ((base_index + size_page) > size_buffer)
          {
            //Відбулася невизначена помилка, тому треба піти на перезавантаження
            while(1);
          }

          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_PAGE_THROUGH_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          for (unsigned int i = 0; i < size_page; i++)
            Temporaty_SPI1_Buffer_Tx[4 + i] = buffer_serial_DataFlash_read_write[base_index + i];
            
          number_transmit = 4 + size_page;
          break;
        }
      case ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER:
        {
          //Треба зчитати визначену сторінку у буфер мікросхеми DataFlash 
          
          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_READ_PAGE_INTO_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          //Адреса в середині сторінки не має значення, але байт має піти
          
          number_transmit = 4;
          break;
        }
      case ETAP_WRITING_DF_BUFFER_WRITE:
        {
          //Треба модифікувати вмістиме буферу

          unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
          if ((base_index + *point_to_number_bytes_read_write_tmp) > size_buffer)
          {
            //Відбулася невизначена помилка, тому треба піти на перезавантаження
            while(1);
          }

          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[2] = ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[2] = ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          for (unsigned int i = 0; i < *point_to_number_bytes_read_write_tmp; i++)
            Temporaty_SPI1_Buffer_Tx[4 + i] = buffer_serial_DataFlash_read_write[base_index + i];
            
          number_transmit = 4 + *point_to_number_bytes_read_write_tmp;
          break;
        }
      case ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE:
        {
          //Треба записати буфер мікросхеми DataFlash у пам'ять мікросхеми DataFlash зі вказаного номеру сторінки
          
          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_BUFFER_INTO_MEMORY_WITH_ERASE;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          //Адреса в середині сторінки не має значення, але байт має піти
          
          number_transmit = 4;
          break;
        }
      default:
        {
          //Відбулася невизначена помилка, тому треба піти на перезавантаження
          while(1);
        }
      }

      
      AR_DR = AR_DR_tmp;
      if (*point_to_etap_writing_df != ETAP_WRITING_DF_NONE)
      {
        //Запускаємо процес обміну DataFlash, якщ оє що передавати
        start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, number_transmit);
      }
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //Стоїть умова читання мікросхеми DataFlash
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_number_bytes_read_write;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int _PA, _BA;
      
      if (AR_DR_tmp == _DF_AR)
      {
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_ar;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;

        _PA = *point_to_address_read_write_tmp / SIZE_PAGE_SERIAL_DATAFLASH_AR;
        _BA = *point_to_address_read_write_tmp - _PA*SIZE_PAGE_SERIAL_DATAFLASH_AR;
      }
      else
      {
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_dr;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;

        _PA = *point_to_address_read_write_tmp / SIZE_PAGE_SERIAL_DATAFLASH_DR;
        _BA = *point_to_address_read_write_tmp - _PA*SIZE_PAGE_SERIAL_DATAFLASH_DR;
      }

      int size_to_end;
      
      //Кількість байт до кінця буферу 
      size_to_end = *point_to_number_bytes_read_write - (*point_to_address_read_write_tmp - *point_to_address_read_write); 
      
      AR_DR = AR_DR_tmp;
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_READ_HIGH_FREQ;
        if (AR_DR_tmp == _DF_AR)
        {
          Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
          Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
          Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
        }
        else
        {
          Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
          Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
          Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
        }
        //Після адреси має іти один додатковй байт як буфер перед початком отримування реальних даних

        if (((unsigned int)(size_to_end + 5)) <= SIZE_BUFFER_FOR_RED) *point_to_number_bytes_read_write_tmp = size_to_end;
        else *point_to_number_bytes_read_write_tmp = (SIZE_BUFFER_FOR_RED - 5);
        
        //Запускаємо процес читання з DataFlash
        start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, (5 + *point_to_number_bytes_read_write_tmp));
      }
      else
      {
        //Весь масив вже зчитаний, тому скидаємо умову читання мікросхеми DataFlash
        _CLEAR_BIT(control_spi1_taskes, ((AR_DR_tmp == _DF_AR) ? TASK_READING_SERIAL_DATAFLASH_AR_BIT : TASK_READING_SERIAL_DATAFLASH_DR_BIT));
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM настройок
      /***/
      
      //Готуємо буфер для запису настройок у EEPROM разом з контрольною сумою
      unsigned char crc_eeprom_settings = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&eeprom_prt_tbl); 
      unsigned char  *point_2 = (unsigned char*)(&eeprom_prt_tbl_comp); 
      for (unsigned int i =0; i < sizeof(CfgTblDsc); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_settings += temp_value;
      }
      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(CfgTblDsc)] = (unsigned char)((~(unsigned int)crc_eeprom_settings) & 0xff);
      
//      /***
//      Тільки для відладки
//      ***/
//      for (int i1 = 0; i1 < 50; i1++)
//      {
//        array_status[i1][0] = 0;
//        array_status[i1][1] = 0;
//        array_status[i1][2] = -1;
//        array_status[i1][3] = 0;
//        array_status[i1][4] = 0;
//      }
//      iteration = 0;
//      error_spi_eeprom = 0;
//      good_spi_eeprom = 0;
//      /**/
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
      
      //Виставляємо перший блок настройок запису у EEPROM
      number_block_settings_prt_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM настройок БС
      /***/
      
      //Готуємо буфер для запису настройок у EEPROM разом з контрольною сумою
      unsigned char crc_bs_eeprom_settings = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&eeprom_bs_settings_tbl); 
      unsigned char  *point_2 = (unsigned char*)(&eeprom_bs_settings_tbl_comp); 
      for (unsigned int i =0; i < sizeof(AuxCfgTbl1Dsc); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_bs_eeprom_settings += temp_value;
      }
      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(AuxCfgTbl1Dsc)] = (unsigned char)((~(unsigned int)crc_bs_eeprom_settings) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
      
      //Виставляємо перший блок настройок запису у EEPROM
      number_block_settings_bs_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM юстування
      
      //Робимо копію записуваної інформації для контролю
      
      //Готуємо буфер для запису настройок у EEPROM разом з контрольноюсумою
      unsigned char crc_eeprom_ustuvannja = 0, temp_value;
      unsigned char  *point_1; 
      unsigned char  *point_2;
      unsigned int offset = 0;

      point_1 = (unsigned char*)(&ustuvannja); 
      point_2 = (unsigned char*)(&ustuvannja_comp); 
      for (unsigned int i =0; i < sizeof(ustuvannja); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja);

      //Додаємо юстуючі коефіцієнти фаз
      point_1 = (unsigned char*)(&phi_ustuvannja); 
      point_2 = (unsigned char*)(&phi_ustuvannja_comp);
      for (unsigned int i = 0; i < sizeof(phi_ustuvannja); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(phi_ustuvannja);

      //Додаємо юстуючі коефіцієнти для активної енергії
      point_1 = (unsigned char*)(&ustuvannja_P); 
      point_2 = (unsigned char*)(&ustuvannja_P_comp);
      for (unsigned int i = 0; i < sizeof(ustuvannja_P); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja_P);

      //Додаємо юстуючі коефіцієнти для реактивної енергії
      point_1 = (unsigned char*)(&ustuvannja_Q); 
      point_2 = (unsigned char*)(&ustuvannja_Q_comp);
      for (unsigned int i = 0; i < sizeof(ustuvannja_Q); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja_Q);
      
      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + offset] = (unsigned char)((~(unsigned int)crc_eeprom_ustuvannja) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT);
      
      //Виставляємо перший блок юстування запису у EEPROM
      number_block_ustuvannja_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM стану сигнальних виходів і тригерних світлоігдикаторів
      
      //Готуємо буфер для запису
      unsigned char temp_value = state_trigger_leds;
      state_trigger_leds_comp = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 0] = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 1] = (unsigned char)((~(unsigned int)temp_value) & 0xff);
      temp_value = state_signal_outputs;
      state_signal_outputs_comp = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 2] = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 3] = (unsigned char)((~(unsigned int)temp_value) & 0xff);

      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);

      //Виставляємо перший блок стану виходів-світлоіндикаторів запису у EEPROM
      number_block_state_leds_outputs_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM стану триґерних функцій

      //Готуємо буфер для запису настройок у EEPROM разом з контрольноюсумою
      unsigned char crc_eeprom_trg_func = 0, temp_value;
      unsigned char  *point_1; 
      unsigned char  *point_2;
      unsigned int offset = 0;

      //Додаємо триґерні функції
      point_1 = (unsigned char*)(&trigger_active_functions); 
      point_2 = (unsigned char*)(&trigger_active_functions_comp);
      for (unsigned int i =0; i < sizeof(trigger_active_functions); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_trg_func += temp_value;
      }
      offset += sizeof(trigger_active_functions);

      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + offset] = (unsigned char)((~(unsigned int)crc_eeprom_trg_func) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);

      //Виставляємо перший блок стану триґерних функцій запису у EEPROM
      number_block_state_trg_func_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM по інформації аналогового реєстратора
      
      //Готуємо буфер для запису у EEPROM разом з контрольною сумою
      unsigned char crc_eeprom_info_rejestrator_ar = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromARecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromARecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_ar += temp_value;
      }

      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_ar) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT);
      
      //Виставляємо перший блок запису у EEPROM
      number_block_info_rejestrator_ar_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM по інформації дискретного реєстратора
      
      //Готуємо буфер для запису у EEPROM разом з контрольною сумою
      unsigned char crc_eeprom_info_rejestrator_dr = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromDRecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromDRecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_dr += temp_value;
      }

      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_dr) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);
      
      //Виставляємо перший блок запису у EEPROM
      number_block_info_rejestrator_dr_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //Стоїть умова початку нового запису у EEPROM по інформації реєстратора програмних подій

      //Готуємо буфер для запису у EEPROM разом з контрольною сумою
      unsigned char crc_eeprom_info_rejestrator_pr_err = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromErrRecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromErrRecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
         Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_pr_err += temp_value;
      }

      //Добавляємо інвертовану контрольну суму у кінець масиву
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_pr_err) & 0xff);
      
      //Скидаємо біт запуску нового запису і виставляємо біт запису блоків у EEPROM з бітом встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      
      //Виставляємо перший блок запису у EEPROM
      number_block_info_rejestrator_pr_err_write_to_eeprom = 0;
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT             ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT           ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT            ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT               ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)  
            )
    {
      //Запускаємо процес читання

      //Читаємо регістр статусу томущо не можна читати EEPROM поки іде процес запису
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_RDSR;
      Temporaty_SPI1_Buffer_Tx[1] = 0; //Будь-який байт для того, щоб здійснити читання регістру статусу;

      //Запускаємо процес запису в RTC
      start_exchange_via_SPI1(SPI1_EEPROM, 2);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT) !=0)
    {
      //Формуємо буфер для передачі у RTC (біт читання + початкова адреса - решта байт не мають значення)
      Temporaty_SPI1_Buffer_Tx[0] = (READ_BIT_OPERATION << 7) | 0x0;
      
      //Cкидаємо біт запуску читання RTC і виставляємо біт процесу читання RTC
      _SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);

      //Запускаємо процес читання RTC
      start_exchange_via_SPI1(SPI1_RTC, 21);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT) !=0)
    {
      //Запускаємо процес запису часу в RTC
      //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)
      copying_time = 1; //Помічаємо, що зараз  ще також обновляємо масив часу
      Temporaty_SPI1_Buffer_Tx[    0] = (WRITE_BIT_OPERATION << 7) | 0x0;
      Temporaty_SPI1_Buffer_Tx[1 + 0] = rtc_time[0] = rtc_time_edit[0] & 0xFF;
      Temporaty_SPI1_Buffer_Tx[1 + 1] = rtc_time[1] = rtc_time_edit[1] & 0x7F;
      Temporaty_SPI1_Buffer_Tx[1 + 2] = rtc_time[2] = rtc_time_edit[2] & 0x7F;
      Temporaty_SPI1_Buffer_Tx[1 + 3] = rtc_time[3] = rtc_time_edit[3] & 0x3F;
      
      unsigned char time_edit_tmp = rtc_time_edit[4];
      if ((time_edit_tmp & 0x07) == 0) time_edit_tmp = (time_edit_tmp & 0x80) | 0x1;
      rtc_time[4] = time_edit_tmp & 0x07;
      Temporaty_SPI1_Buffer_Tx[1 + 4] = time_edit_tmp & 0x87;
      
      Temporaty_SPI1_Buffer_Tx[1 + 5] = rtc_time[5] = rtc_time_edit[5] & 0x3F;
      Temporaty_SPI1_Buffer_Tx[1 + 6] = rtc_time[6] = rtc_time_edit[6] & 0x1F;
      Temporaty_SPI1_Buffer_Tx[1 + 7] = rtc_time[7] = rtc_time_edit[7] & 0xFF;
      
      copying_time = 0; //Помічаємо, що обновлення масив часу завершене
      
      //Робимо копію масиву часу для того, щоб коли основний масив буде обновлятися можна було іншим модулям взяти попереднє, але достовірне значення часу і дати з цього масиву
      for(unsigned int i = 0; i < 8; i++) rtc_time_copy[i] = rtc_time[i];

      //Скидаємо біт запуску RTC і виставляємо біт процесу читання RTC
      _SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT);

      //Запускаємо процес запису в RTC
      start_exchange_via_SPI1(SPI1_RTC, (1 + 8));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT) !=0)
    {
      //Запускаємо процес запису калібровки в RTC
      //Формуємо буфер для передачі у RTC (біт запису + початкова адреса - інформаційні байти)
      Temporaty_SPI1_Buffer_Tx[    0] = (WRITE_BIT_OPERATION << 7) | 0x8;
      Temporaty_SPI1_Buffer_Tx[1 + 0] = (rtc_calibration_edit & 0x3f) | (copy_register8_RTC & 0xC0);
      
      //Скидаємо біт запуску RTC і виставляємо біт процесу читання RTC
      _SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT);

      //Запускаємо процес запису в RTC
      start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_MAKE_PAGE_SIZE_256_BIT) !=0)
//    {
//      //Скидаємо біт початку переведення мікросхеми до розміру сторінки у 256 байт і виставляємо біт переведення мікросхеми до розміру сторінки у 256 байт з бітом читання регістру статусу
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//      _SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT);
//      _CLEAR_BIT(control_spi1_taskes, TASK_START_MAKE_PAGE_SIZE_256_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //Скидаємо біт початку стирання всієї мікросхеми DataFlash і виставляємо біт стирання мікросхеми DataFlash з бітом читання регістру статусу
      if (AR_DR_tmp == _DF_AR)
      {
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_AR_BIT);
      }
      else
      {
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_DR_BIT);
      }
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      if (AR_DR_tmp == _DF_AR)
      {
//        /*****/
//        //Тільки для відладки
//        /*****/
//        for(unsigned int i = 0; i < number_bytes_read_write_ar; i++)
//          buffer_serial_DataFlash_read_write_ar[i] = (i+1) & 0xff;
//        /*****/

        //Визначаємо адресу у мікросхемі DataFlash з якої треба почати записувати
        address_read_write_ar_tmp = address_read_write_ar;
        //Помічаємо, що на даний момент ще не іде ніякий запис
        number_bytes_read_write_ar_tmp = 0;
        //Помічаємо, що операція запису невизначена
        etap_writing_df_ar = ETAP_WRITING_DF_NONE;
      
        //Скидаємо біт початку запису мікросхеми DataFlash і виставляємо біт запису мікросхеми DataFlash з бітом читання регістру статусу
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
//        /*****/
//        //Тільки для відладки
//        /*****/
//        for(unsigned int i = number_bytes_read_write_dr; i > 0; i--)
//          buffer_serial_DataFlash_read_write_dr[number_bytes_read_write_dr - i] = (i) & 0xff;
//        /*****/

        //Визначаємо адресу у мікросхемі DataFlash з якої треба почати записувати
        address_read_write_dr_tmp = address_read_write_dr;
        //Помічаємо, що на даний момент ще не іде ніякий запис
        number_bytes_read_write_dr_tmp = 0;
        //Помічаємо, що операція запису невизначена
        etap_writing_df_dr = ETAP_WRITING_DF_NONE;
      
        //Скидаємо біт початку запису мікросхеми DataFlash і виставляємо біт запису мікросхеми DataFlash з бітом читання регістру статусу
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT);
      }
        
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      if (AR_DR_tmp == _DF_AR)
      {
        //Визначаємо адресу у мікросхемі DataFlash з якої треба почати читання
        address_read_write_ar_tmp = address_read_write_ar;
        //Помічаємо, що на даний момент ще не іде ніяке зчитування
        number_bytes_read_write_ar_tmp = 0;
      
        //Скидаємо біт початку читання мікросхеми DataFlash і виставляємо біт читання мікросхеми DataFlash з бітом читання регістру статусу
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
        //Визначаємо адресу у мікросхемі DataFlash з якої треба почати читання
        address_read_write_dr_tmp = address_read_write_dr;
        //Помічаємо, що на даний момент ще не іде ніяке зчитування
        number_bytes_read_write_dr_tmp = 0;
      
        //Скидаємо біт початку читання мікросхеми DataFlash і виставляємо біт читання мікросхеми DataFlash з бітом читання регістру статусу
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT);
      }
    }
    /*************************************************/
  }
  else if (state_execution_spi1 == 1)
  {
    /*************************************************/
    //Обмін завершився без помилок
    /*************************************************/

    //Виставляємо повідомлення, що I2C готовий до нової транзакції 
    state_execution_spi1 = -1;

    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) !=0)
    {
//      /***
//      Тільки для відладки
//      ***/
//      if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT))
//      {
//        if (etap_eeprom_write_enable == 0)
//        {
//          if (iteration == 0) array_status[number_block_settings_write_to_eeprom_prt][0] = Temporaty_SPI1_Buffer_Rx[1 + 0];
//          iteration++;
//          
//          if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & 0x70) != 0)
//          {
//            if (Temporaty_SPI1_Buffer_Rx[1 + 0] != 0xff)
//            {
//              error_spi_eeprom++;
//            }
//            else good_spi_eeprom++;
//          }
//          else good_spi_eeprom++;
//        }
//      }
//      /**/

      //Цей блок має бути завжди першим, щоб коли іде перевірка на доступність запису не виконувалися помилковоінші задачі
      if (etap_eeprom_write_enable == 0)
      {
        //Прочитано ресістр статусу

        if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & 0x70) != 0)
        {
          /*
          Біти 4-6 знаходятся у "1" тільки під час внутрішнього процесу зпапису - 
          Треба продовжувати читати регістр статусу
          */
          etap_eeprom_write_enable = 0;  
          if (Temporaty_SPI1_Buffer_Rx[1 + 0] != 0xff)
          {
            /*
            Під час внутрішнього процесу запису всі біти 0-7 регстру статусу, 
            згідно документації, мають бути встановлені.
            Якщо ні - це питання, яке потребує дослідження, покищо я це просто фіксую
            встановлекнням "1" на контрольній точці КТ3
            */
//            GPIO_KT3->BSRR = GPIO_KT3_Pin;
          }
          else
          {
            /*
            Під час внутрішнього процесу запису всі біти 0-7 регстру статусу, 
            згідно документації, мають бути встановлені.
            Якщо так і є, то я фіксую нормальну роботу встановлекнням "0" на контрольній точці КТ3
            */
//             GPIO_KT3->BRR = GPIO_KT3_Pin;
          }
        }
        else if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 0)) == 0)
        {
          /*
          Встановлекнням "0" на контрольній точці КТ3 фіксуємо нормальну роботу з
          регістром статусу/дозволом запису EEPROM
          */
//          GPIO_KT3->BRR = GPIO_KT3_Pin;
          
          //Процес запису у EEPROM не відбувається
          if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 1)) != 0)
          {
//            /***
//            Тільки для відладки
//            ***/
//            if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT))
//            {
//              array_status[number_block_settings_write_to_eeprom_prt][1] = Temporaty_SPI1_Buffer_Rx[1 + 0];
//              array_status[number_block_settings_write_to_eeprom_prt][2] = iteration;
//              array_status[number_block_settings_write_to_eeprom_prt][3] = error_spi_eeprom;
//              array_status[number_block_settings_write_to_eeprom_prt][4] = good_spi_eeprom;
//              iteration = 0;
//              error_spi_eeprom = 0;
//              good_spi_eeprom = 0;
//            }
//            /**/

            //EEPROM є доступною до запису
            //Скидаємо біт підготовки до запису EEPROM
            _CLEAR_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
            etap_eeprom_write_enable = -1;
          }
          else
          {
            //EEPROM є не доступною до запису - переходимо на етап подачі команди дозволу запису в EEPROM
            etap_eeprom_write_enable = 1;
          }
        }
        else
        {
          //Інакше виконуємо повторно ту саму опрецію, поки в EEPROM не завершится процес запису

          /*
          Встановлекнням "0" на контрольній точці КТ3 фіксуємо нормальну роботу з
          регістром статусу/дозволом запису EEPROM
          */
//          GPIO_KT3->BRR = GPIO_KT3_Pin;
        }
      }
      else if (etap_eeprom_write_enable == 1)
      {
        /*
        Встановлекнням "0" на контрольній точці КТ3 фіксуємо нормальну роботу з
        регістром статусу/дозволом запису EEPROM
        */
//        GPIO_KT3->BRR = GPIO_KT3_Pin;
        
        //Передано команду дозволу запису - повторно читаємо регістра статусу
        etap_eeprom_write_enable = 0;
        //Біт підготовки до запису EEPROM не скидаємо, бо маємо переконатися, що щдозвіл запису успішно встановився
      }
      else
      {
        //Теоретично програма сюди б не мала ніколи зайти
        //Відбцлася невизначена помилка, тому треба піти на перезавантаження
        while(1);
      }
    }
    else if(
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) !=0) && (AR_DR == _DF_DR))
           )   
    {
      //Цей блок має бути завжди першим після читання регістру статусу EEPROM, щоб коли іде перевірка на доступність запису не виконувалися помилковоінші задачі
      
      unsigned int *point_to_status_register_df; 
      if (AR_DR == _DF_AR) point_to_status_register_df = &status_register_df_ar;
      else point_to_status_register_df = &status_register_df_dr;
      
      *point_to_status_register_df = Temporaty_SPI1_Buffer_Rx[1 + 0];

      //Прочитано ресістр статусу
      if ((*point_to_status_register_df & (1 << 7)) != 0)
      {
        //Мікросхема DataFlash не є у стані "BUSY"
        _CLEAR_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
      }
      else
      {
        //Інакше виконуємо повторно ту саму опрецію, поки Мікросхема DataFlash не перейде у стан "BUSY"
      }
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT           ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT            ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT             ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT               ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
            )
    {
      //Стоїть умова запису блоку у EEPROM

      if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT) !=0)
      {
        //Виставляємо наступний блок настройок запису у EEPROM
        number_block_settings_prt_write_to_eeprom++;
      }
      else if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT) !=0)
      {
        //Виставляємо наступний блок настройок БС запису у EEPROM
        number_block_settings_bs_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT) !=0)
      {
        //Виставляємо наступний блок юстування запису у EEPROM
        number_block_ustuvannja_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT) != 0)
      {
        //Виставляємо що стани виходів-світлоіндикаторів вже записані - треба тільки коректно завершити цю операцію з витримкою часу на саму процедуру запису у мікросхемі
        number_block_state_leds_outputs_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT) != 0)
      {
        //Виставляємо що стани триґерних функцій вже записані - треба тільки коректно завершити цю операцію з витримкою часу на саму процедуру запису у мікросхемі
        number_block_state_trg_func_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT) != 0)
      {
        //Виставляємо наступний блок інформації по реєстраторах запису у EEPROM
        number_block_info_rejestrator_ar_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT) != 0)
      {
        //Виставляємо наступний блок інформації по реєстраторах запису у EEPROM
        number_block_info_rejestrator_dr_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) != 0)
      {
        //Виставляємо наступний блок інформації по реєстраторах запису у EEPROM
        number_block_info_rejestrator_pr_err_write_to_eeprom++;
      }
      else
      {
        //Сюди програма не мала б теоретично ніколи заходити
        //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
        while(1);
      }

      //Виставляємо біт встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
    }
    else if(
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT             ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT           ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT            ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT               ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) ||  
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)  
           )  
    {
      //Прочитано ресістр статусу
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 0)) == 0)
      {
        //Процес запису у EEPROM не відбувається
        if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання юстування і виставляємо біт процесу читання юстування
          _SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання настройок і виставляємо біт процесу читання настройок
          _SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання настройок і виставляємо біт процесу читання настройок БС
          _SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання стану тригерних світлодіодів і сигнальних реле і виставляємо біт процесу читання тригерних світлодіодів і сигнальних реле
          _SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання стану триґерних функцій і виставляємо біт процесу читання триґерних функцій
          _SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання інформації по аналоговому реєстратору і виставляємо біт процесу читання інформації по аналоговому реєстратору
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання інформації по дискретному реєстратору і виставляємо біт процесу читання інформації по дискретному реєстратору
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
        {
          //Скидаємо біт запуску читання інформації по дискретному реєстратору і виставляємо біт процесу читання інформації по дискретному реєстратору
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        }
        else
        {
          //Сюди програма не мала б теоретично ніколи заходити
          //Якщо сюди дійшла програма, значить відбулася недопустива помилка, тому треба зациклити програму, щоб вона пішла на перезагрузку
          while(1);
        }
      }
      else
      {
        //Інакше виконуємо повторно ту саму опрецію, поки в EEPROM не завершится процес запису
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      DDR2_B1_2_DATA static CfgTblDsc eeprom_prt_tbl_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(CfgTblDsc) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок настроювання не є пустим
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у структуру управління
        unsigned char crc_eeprom_settings = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&eeprom_prt_tbl_tmp); 
        for (i =0; i < sizeof(CfgTblDsc); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_settings += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(CfgTblDsc)]  == ((unsigned char)((~(unsigned int)crc_eeprom_settings) & 0xff)))
        {
          //Контролдьна сума сходиться

          //Зберігаємо контрольну суму (не інвертовану)
          crc_settings_prt = crc_eeprom_settings;

          if ((comparison_writing & COMPARISON_WRITING_SETTINGS_PRT) == 0)
          {
            //Виконувалося зчитування настройок у таблицю настройок
            
            //Перекидаємо таблицю настройок з тимчасового масиву у робочу таблицю
            eeprom_prt_tbl = eeprom_prt_tbl_tmp;
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned char  *point_to_read  = (unsigned char*)(&eeprom_prt_tbl_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&eeprom_prt_tbl_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(CfgTblDsc)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_FAIL);
          state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_GOOD;
          
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_GOOD);
          state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_FAIL;
 
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок настройок є пустим
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_GOOD);
        state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_EMPTY;
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
      }

      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_PRT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      DDR2_B1_2_DATA static AuxCfgTbl1Dsc eeprom_bs_settings_tbl_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(AuxCfgTbl1Dsc) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок настроювання не є пустим
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у структуру управління
        unsigned char crc_eeprom_settings_bs = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&eeprom_bs_settings_tbl_tmp); 
        for (i =0; i < sizeof(AuxCfgTbl1Dsc); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_settings_bs += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(AuxCfgTbl1Dsc)]  == ((unsigned char)((~(unsigned int)crc_eeprom_settings_bs) & 0xff)))
        {
          //Контролдьна сума сходиться

          //Зберігаємо контрольну суму (не інвертовану)
          crc_settings_bs = crc_eeprom_settings_bs;

          if ((comparison_writing & COMPARISON_WRITING_SETTINGS_BS) == 0)
          {
            //Виконувалося зчитування настройок БС у таблицю настройок БС
            
            //Перекидаємо таблицю настройок БС з тимчасового масиву у робочу таблицю БС
            eeprom_bs_settings_tbl = eeprom_bs_settings_tbl_tmp;
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned char  *point_to_read  = (unsigned char*)(&eeprom_bs_settings_tbl_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&eeprom_bs_settings_tbl_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(AuxCfgTbl1Dsc)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_FAIL);
          state_spi1_task |= STATE_SETTINGS_BS_EEPROM_GOOD;
          
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_GOOD);
          state_spi1_task |= STATE_SETTINGS_BS_EEPROM_FAIL;
 
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок настройок є пустим
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_GOOD);
        state_spi1_task |= STATE_SETTINGS_BS_EEPROM_EMPTY;
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
      }

      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_BS);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      unsigned int ustuvannja_tmp[NUMBER_CANALS], phi_ustuvannja_tmp[NUMBER_CANALS];
      unsigned int ustuvannja_P_tmp[3], ustuvannja_Q_tmp[3];
      
      while ((empty_block != 0) && ( i < (SIZE_USTUVANNJA + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок настроювання не є пустим
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у масив юстування з серійним номером
        unsigned char crc_eeprom_ustuvannja = 0, temp_value;
        unsigned char  *point;
        unsigned int offset = 0;

        point = (unsigned char*)(&ustuvannja_tmp); 
        for (i =0; i < sizeof(ustuvannja_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_tmp);
        
        point = (unsigned char*)(&phi_ustuvannja_tmp); 
        for (i =0; i < sizeof(phi_ustuvannja_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(phi_ustuvannja_tmp);
        
        point = (unsigned char*)(&ustuvannja_P_tmp); 
        for (i =0; i < sizeof(ustuvannja_P_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_P_tmp);
        
        point = (unsigned char*)(&ustuvannja_Q_tmp); 
        for (i =0; i < sizeof(ustuvannja_Q_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_Q_tmp);
        
        if (Temporaty_SPI1_Buffer_Rx[3 + SIZE_USTUVANNJA]  == ((unsigned char)((~(unsigned int)crc_eeprom_ustuvannja) & 0xff)))
        {
          //Контролдьна сума сходиться
    
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);

          //Зберігаємо контрольну суму (не інвертовану)
          crc_ustuvannja = crc_eeprom_ustuvannja;
          
          if ((comparison_writing & COMPARISON_WRITING_USTUVANNJA) == 0)
          {
            //Виконувалося зчитування юстування у масив юстування
            
            //Перекидаємо масив юстування з тимчасового масиву у робочий масив
            for(unsigned int l = 0; l < NUMBER_CANALS; l++) 
            {
              ustuvannja[l] = ustuvannja_tmp[l];
              phi_ustuvannja[l] = phi_ustuvannja_tmp[l];
            }
            for(unsigned int l = 0; l < 3; l++) 
            {
              ustuvannja_P[l] = ustuvannja_P_tmp[l];
              ustuvannja_Q[l] = ustuvannja_Q_tmp[l];
            }
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && (i < NUMBER_CANALS))
            {
              //Перевірка запису юстуючих коефіцієнтів
              if (
                  (ustuvannja_comp[i] != ustuvannja_tmp[i]) ||
                  (phi_ustuvannja_comp[i] != phi_ustuvannja_tmp[i])
                 )
              {
                difference = 0xff;
              }
              else
              {
                i++;
              }
            }
            
            i = 0;
            while ((difference == 0) && (i < 3))
            {
              //Перевірка запису юстуючих коефіцієнтів для потужностей
              if (
                  (ustuvannja_P_comp[i] != ustuvannja_P_tmp[i]) ||
                  (ustuvannja_Q_comp[i] != ustuvannja_Q_tmp[i])
                 )
              {
                difference = 0xff;
              }
              else
              {
                i++;
              }
            }
            
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_FAIL);
          state_spi1_task |= STATE_USTUVANNJA_EEPROM_GOOD;
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_GOOD);
          state_spi1_task |= STATE_USTUVANNJA_EEPROM_FAIL;
     
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок юстування є пустим
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_GOOD);
        state_spi1_task |= STATE_USTUVANNJA_EEPROM_EMPTY;

        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_EMPTY_BIT);
      }
            
      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_USTUVANNJA);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      unsigned char state_trigger_leds_tmp, state_signal_outputs_tmp;
      
      while ((empty_block != 0) && ( i < 4))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок не є пустим
        state_spi1_task &= (unsigned int)(~STATE_LEDS_OUTPUTS_EEPROM_EMPTY);
        
        //Скидаємо повідомлення у слові діагностики, що блок пустий
        _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT);
        
        //Перевіряємо достовірність стану тригерних індикаторів
        state_trigger_leds_tmp = Temporaty_SPI1_Buffer_Rx[3 + 0];
        state_signal_outputs_tmp = Temporaty_SPI1_Buffer_Rx[3 + 2];
        
        unsigned char value_1 = Temporaty_SPI1_Buffer_Rx[3 + 1];
        if (state_trigger_leds_tmp == (unsigned char)((~(unsigned int)value_1) & 0xff))
        {
          //Контролдь зійшовся

          if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
          {
            //Виконувалося зчитування станів тригерних світлоіндикаторів/сигнальних виходів

            //Відновлюємо інформацію по тригерних світлоіндикаторах
            /*state_leds = */state_trigger_leds = state_trigger_leds_tmp;
          }

          state_spi1_task &= (unsigned int)(~STATE_LEDS_EEPROM_FAIL);
          state_spi1_task |= STATE_LEDS_EEPROM_GOOD;
          
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        }
        else
        {
          //Контролдь не зійшовся
          state_spi1_task &= (unsigned int)(~STATE_LEDS_EEPROM_GOOD);
          state_spi1_task |= STATE_LEDS_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        }

        //Перевіряємо достовірність стану сигнальних виходів
        value_1 = Temporaty_SPI1_Buffer_Rx[3 + 3];
        if (state_signal_outputs_tmp == (unsigned char)((~(unsigned int)value_1) & 0xff))
        {
          //Контролдь зійшовся

          if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
          {
            //Виконувалося зчитування станів тригерних світлоіндикаторів/сигнальних виходів

            //Відновлюємо інформацію по сигнальних виходах
            /*state_outputs = */state_signal_outputs = state_signal_outputs_tmp;
          }

          state_spi1_task &= (unsigned int)(~STATE_OUTPUTS_EEPROM_FAIL);
          state_spi1_task |= STATE_OUTPUTS_EEPROM_GOOD;
          
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        }
        else
        {
          //Контролдь не зійшовся
          state_spi1_task &= (unsigned int)(~STATE_OUTPUTS_EEPROM_GOOD);
          state_spi1_task |= STATE_OUTPUTS_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок є пустим
        state_spi1_task &= (unsigned int)(~(STATE_LEDS_EEPROM_FAIL | STATE_LEDS_EEPROM_GOOD | STATE_OUTPUTS_EEPROM_FAIL | STATE_OUTPUTS_EEPROM_GOOD));
        state_spi1_task |= STATE_LEDS_OUTPUTS_EEPROM_EMPTY;
        
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        _CLEAR_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT);

//        if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
//        {
//          /*
//          Виставляємо повідомлення про те, що в EEPROM треба записати нові значення
//          сигнальних виходів і тригерних світлоіндикаторів тільки тоді, коли ми зчитуємо
//          збережені дані для відновлення їх у оперативній пам'яті, а не коли ми проводимо 
//          контроль запису.
//          Бо для контролю запису нам важливо знати чи успішно записалися дані, які є у 
//          оперативній пам'яті і при цьому, навіть, якщо запис відбувся невдало, то,
//          оскільки ми працюємо зі змінними з оперативної пам'яті,  які є у нас достовірні,
//          бо ми їх якраз і записували, то на роботу до перезавантаження програмного забезперечння 
//          збій запису у EEPROM не мав би вплинути
//          */
//          _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
//        }
      }
      
      if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) != 0)
      {
        //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
        
        if(
           ((state_spi1_task & STATE_LEDS_EEPROM_GOOD   ) != 0) &&
           ((state_spi1_task & STATE_OUTPUTS_EEPROM_GOOD) != 0)
          )
        {
          //Контроль запису здійснюємо тільки тоді, коли коли блок читання не є пустим і помилок не зафіксовано
          
          if (
              (state_trigger_leds_comp   == state_trigger_leds_tmp   ) &&
              (state_signal_outputs_comp == state_signal_outputs_tmp )
             )   
          {
            //Контроль порівнняння пройшов успішно

            //Скидаємо повідомлення у слові діагностики
            _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT);
          }
          else
          {
            //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

            //Виствляємо повідомлення у слові діагностики
            _SET_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT);
          }
        }
      }

      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_STATE_LEDS_OUTPUTS);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прийнятий блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      unsigned int trigger_active_functions_tmp[N_TMP];
      
      while ((empty_block != 0) && ( i < sizeof(trigger_active_functions_tmp) + 1))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок не є пустим
        state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_EMPTY);
        
        //Скидаємо повідомлення у слові діагностики, що блок пустий
        _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у тимчасові змінні
        unsigned char crc_eeprom_trg_func = 0, temp_value;
        unsigned char  *point;
        unsigned int offset = 0;

        point = (unsigned char*)(&trigger_active_functions_tmp); 
        for (i =0; i < sizeof(trigger_active_functions_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_trg_func += temp_value;
          point++;
        }
        offset +=  sizeof(trigger_active_functions_tmp);
        
        if (Temporaty_SPI1_Buffer_Rx[3 + offset]  == ((unsigned char)((~(unsigned int)crc_eeprom_trg_func) & 0xff)))
        {
          //Контролдь зійшовся

          if ((comparison_writing & COMPARISON_WRITING_TRG_FUNC) == 0)
          {
            //Виконувалося зчитування станів триґерних функцій

            //Перекидаємо триґерну інформацію у робочі змінні
            for(unsigned int k = 0; k < N_TMP; k++) trigger_active_functions[k] = trigger_active_functions_tmp[k];
//            restore_trigger_functions(trigger_active_functions);
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned int difference = 0;
  
            i = 0;
            while ((difference == 0) && (i < N_TMP))
            {
              //Перевірка запису функцій значення яких зберігається у енергонезалежній пам'яті
              if (trigger_active_functions_comp[i] != trigger_active_functions_tmp[i]) difference = 0xff;
              else
              {
                i++;
              }
            }
            
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно
  
              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_FAIL);
          state_spi1_task |= STATE_TRG_FUNC_EEPROM_GOOD;
          
          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        }
        else
        {
          //Контролдь не зійшовся
          state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_GOOD);
          state_spi1_task |= STATE_TRG_FUNC_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок є пустим
        state_spi1_task &= (unsigned int)(~(STATE_TRG_FUNC_EEPROM_FAIL | STATE_TRG_FUNC_EEPROM_GOOD));
        state_spi1_task |= STATE_TRG_FUNC_EEPROM_EMPTY;
        
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_EMPTY_BIT);
      }

      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_TRG_FUNC);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromARecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок не є пустим
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у структуру
        unsigned char crc_eeprom_info_rejestrator_ar = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromARecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_ar += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_ar) & 0xff)))
        {
          //Контролдьна сума сходиться

          //Зберігаємо контрольну суму (не інвертовану)
          crc_info_rejestrator_ar = crc_eeprom_info_rejestrator_ar;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD;

          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_AR) == 0)
          {
            //Виконувалося зчитування інформації по аналоговому реєстратору у робочу структуру
            
            //Перекидаємо інформації по аналоговому реєстратору з тимчасової структури у робочу структуру
            EepromARecDesc = EepromARecDesc_tmp;
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromARecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromARecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок є пустим
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY;
        
        
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT);
      }
     
      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_AR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromDRecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок не є пустим
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у структуру
        unsigned char crc_eeprom_info_rejestrator_dr = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromDRecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_dr += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_dr) & 0xff)))
        {
          //Контролдьна сума сходиться

          //Зберігаємо контрольну суму (не інвертовану)
          crc_info_rejestrator_dr = crc_eeprom_info_rejestrator_dr;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD;

          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_DR) == 0)
          {
            //Виконувалося зчитування інформації по дискретному реєстратору у робочу структуру
            
            //Перекидаємо інформації по дискретному реєстратору з тимчасової структури у робочу структуру
            EepromDRecDesc = EepromDRecDesc_tmp;
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromDRecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromDRecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
             _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок є пустим
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY;
        
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT);
      }
      
      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_DR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      
      //Аналізуємо прочитані дані
      //Спочатку аналізуємо, чи прояитаний блок є пустим, чи вже попередньо записаним
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromErrRecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //Помічаємо, що блок не є пустим
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY);
        //Скидаємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT);
        
        //Перевіряємо контрольну суму і переписуємо прочитані дані у структуру
        unsigned char crc_eeprom_info_rejestrator_pr_err = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromErrRecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_pr_err += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_pr_err) & 0xff)))
        {
          //Контролдьна сума сходиться

          //Зберігаємо контрольну суму (не інвертовану)
          crc_info_rejestrator_pr_err = crc_eeprom_info_rejestrator_pr_err;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD;

          //Скидаємо повідомлення у слові діагностики
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR) == 0)
          {
            //Виконувалося зчитування інформації по реєстратору програмних подій у робочу структуру
            
            //Перекидаємо інформації по реєстратору програмних подій з тимчасової структури у робочу структуру
            EepromErrRecDesc = EepromErrRecDesc_tmp;
          }
          else
          {
            //Виконувалося контроль достовірності записаної інформації у EEPROM з записуваною
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromErrRecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromErrRecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //Контроль порівнняння пройшов успішно

              //Скидаємо повідомлення у слові діагностики
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT);
            }
            else
            {
              //Контроль порівнняння зафіксував розбіжності між записаною і записуваною інформацією

              //Виствляємо повідомлення у слові діагностики
              _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //Контрольна сума не сходиться
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL;
          
          //Виствляємо повідомлення у слові діагностики
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        }
      }
      else
      {
        //Помічаємо, що прочитаний блок є пустим
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY;
        
        //Виствляємо повідомлення у слові діагностики
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT);
      }

      //Знімаємо можливу сигналізацію, що виконувалося порівнняння
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
      
      //Аналізуємо прочитані дані
      if (
          ((Temporaty_SPI1_Buffer_Rx[1 + 0xA ] & (1<< 6)) == 0 ) /*SQWE = 0*/ ||
          ((Temporaty_SPI1_Buffer_Rx[1 + 0xC ] & (1<< 6)) != 0 ) /*HT  = 1 */ ||
          ((Temporaty_SPI1_Buffer_Rx[1 + 0x13]          ) != 0xf0) /*Потрібна частота*/ 
         )
      {
        //Треба потрібні біти  і слова виставити у робочі значення, щоб на виході отримати 1гц
        temp_register_rtc[0] = Temporaty_SPI1_Buffer_Rx[1 + 0xC ] & (unsigned char)(~ (1<< 6));
        temp_register_rtc[1] = Temporaty_SPI1_Buffer_Rx[1 + 0xA ] | (1<< 6);

        //Повідомлення про цю несправність виставляємо, коли не йде тільки-но перше зчитування
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 ) _SET_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
        else _CLEAR_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
        
        etap_settings_test_frequency = 0;
        _SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT);
      } 
      else
        _CLEAR_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
      
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0x1] &  (1<< 7)) != 0) /*ST = 1 */
      {
        //Треба запустиити осцилятор для RTC
        _SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT);
      }
      else if ((etap_reset_of_bit < ETAP_CLEAR_OF_ST_STOP) && ((Temporaty_SPI1_Buffer_Rx[1 + 0xf] & (1<<2)) != 0))
      {
        _SET_BIT(diagnostyka, RTC_OSCILLATOR_FAIL_BIT);
        //Треба ST-біт виставити в 1 і негайно скинути його в 0. Почекати через 5 секунд він має скинутися
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 )
        {
          etap_reset_of_bit = ETAP_CLEAR_OF_ST_STOP;
          _SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
        }
        else
          etap_reset_of_bit = ETAP_CLEAR_OF_ST_START_WAITING_5S;
      }
      else if (etap_reset_of_bit == ETAP_CLEAR_OF_WRITE_OF_0)
      {
        //Треба очистити OF-біт
        temp_value_for_rtc = Temporaty_SPI1_Buffer_Rx[1 + 0xf];
        _SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
      
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xC] & (1<< 6)) != 0) /*встановлений HT-біт*/
      {
        //Повідомлення про цю несправність виставляємо, коли не йде тільки-но перше зчитування
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 ) _SET_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
        else _CLEAR_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
      }
      else _CLEAR_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0x1] &  (1<< 7)) != 0) _SET_BIT(diagnostyka, RTC_OSCILLATOR_STOPED_BIT);
      else _CLEAR_BIT(diagnostyka, RTC_OSCILLATOR_STOPED_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xF] &  (1<< 4)) != 0) _SET_BIT(diagnostyka, RTC_BATTERY_LOW_BIT);
      else _CLEAR_BIT(diagnostyka, RTC_BATTERY_LOW_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xF] &  (1<< 2)) == 0) _CLEAR_BIT(diagnostyka, RTC_OSCILLATOR_FAIL_BIT);

      if((state_spi1_task & STATE_FIRST_READING_RTC) !=0)
      {
        //Зараз відбувається перше зчитування даних з RTC - скидаємо біт першого читання
        state_spi1_task &= (unsigned int)(~STATE_FIRST_READING_RTC);
      }

      //Обновлюємо час
      copying_time = 1; //Помічаємо, що зараз обновляємо масив часу
      rtc_time[0] = Temporaty_SPI1_Buffer_Rx[1 + 0] & 0xff;
      rtc_time[1] = Temporaty_SPI1_Buffer_Rx[1 + 1] & 0x7f;
      rtc_time[2] = Temporaty_SPI1_Buffer_Rx[1 + 2] & 0x7f;
      rtc_time[3] = Temporaty_SPI1_Buffer_Rx[1 + 3] & 0x3f;

      rtc_time[4] = Temporaty_SPI1_Buffer_Rx[1 + 4] & 0x07;
      if ((rtc_time[4] & 0x07) == 0) rtc_time[4] = (rtc_time[4] & 0x80) | 0x1;

      rtc_time[5] = Temporaty_SPI1_Buffer_Rx[1 + 5] & 0x3f;
      rtc_time[6] = Temporaty_SPI1_Buffer_Rx[1 + 6] & 0x1f;
      rtc_time[7] = Temporaty_SPI1_Buffer_Rx[1 + 7] & 0xff;
      copy_register8_RTC = Temporaty_SPI1_Buffer_Rx[1 + 8];
      rtc_calibration = copy_register8_RTC & 0x3f;


      copying_time = 0; //Помічаємо, що обновлення масив часу завершене
      
      //Робимо копію масиву часу для того, щоб коли основний масив буде обновлятися можна було іншим модулям взяти попереднє, але достовірне значення часу і дати з цього масиву
      for(unsigned int i = 0; i < 8; i++) rtc_time_copy[i] = rtc_time[i];
      rtc_calibration_copy = rtc_calibration;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0)
    {
      etap_settings_test_frequency++;
      if (etap_settings_test_frequency > 2)
      {
        //Скидаємо біт виставляння бітів і полів у потрібні значення, якщо всі поля записані
        _CLEAR_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT);
        //Повторно запускаємо читання регістрів RTC
        _SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);
        etap_settings_test_frequency = -1;
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0)
    {
      //Скидаємо біт запуску осцилятора RTC
      _CLEAR_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0)
    {
      etap_reset_of_bit++;
      if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_START_WAITING_5S)
      {
        //Скидаємо запущені операції попереднього  скидання OF-біту, але ще маємо витримати 5с для остаточного скидання OF-біту
        _CLEAR_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
      else if (etap_reset_of_bit >= ETAP_CLEAR_OF_WRITE_OF_0)
      {
        //Скидаємо запущені операції скидання OF-біту
        etap_reset_of_bit = ETAP_CLEAR_OF_NONE;
        _CLEAR_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //Завершився процес переводу мікросхеми DataFlash не розмір сторінки у 256 байт
//
//      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//
//      //Скидаємо біт запуску переводу мікросхеми DataFlash не розмір сторінки у 256 байт
//      _CLEAR_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //Завершився процес стирання мікросхеми DataFlash

      /*
      Не виставляємо біт повторного читання регістру - хай стирається у процесі 
      інших операцій (не з мікросхемою DataFlash). а перед новою операцією роботи з 
      мікросхемою DataFlash завжди буду виставляти читання регістру статусу
      */
//      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));

      //Скидаємо біт стирання мікросхеми DataFlash
      _CLEAR_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_ERASING_DATAFLASH_AR_BIT : TASK_ERASING_DATAFLASH_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //Завершився етап процесу запису інформації, визнаеної змінною  number_bytes_read_write_tmp, в мікросхему DataFlash
               int *point_to_etap_writing_df;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_address_read_write_tmp;
      
      if (AR_DR == _DF_AR)
      {
        point_to_etap_writing_df = &etap_writing_df_ar;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
      }
      else
      {
        point_to_etap_writing_df = &etap_writing_df_dr;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
      }
      
      if (
          (*point_to_etap_writing_df == ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER              ) ||
          (*point_to_etap_writing_df == ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE)
         ) 
      {
        //Завершилася операція запису порції інформації у пам'ять мікросхеми DataFlash

        //Збільшуємо адресу з якої, можливо, треба буде продовжити читання
        *point_to_address_read_write_tmp += *point_to_number_bytes_read_write_tmp;
        
        //Помічаємо. що треба підготувати нову порцію інформації для запису
        *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
      }
      else if (
               (*point_to_etap_writing_df == ETAP_WRITING_DF_NONE                                           ) ||
               (*point_to_etap_writing_df >  ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE)  
              )   
      {
        //Відбулася невизначена помилка, тому треба піти на перезавантаження
        while(1);
      }
      else
      {
        //Переходимо на наступний етап запису порції інформації визнаеної змінною  number_bytes_read_write_tmp
        (*point_to_etap_writing_df)++;
      }

      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      unsigned int size_biffer;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int *buffer_serial_DataFlash_read_write;
      
      //Завершився процес читання інформації, визнаеної вказівником  point_to_number_bytes_read_write_tmp, з мікросхеми DataFlash
      if (AR_DR == _DF_AR)
      {
        size_biffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;

        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;
        
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_ar;
      }
      else
      {
        size_biffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;

        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;
        
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_dr;
      }
      
      //Копіюємо отриману інформацію
      unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
      if ((base_index + *point_to_number_bytes_read_write_tmp) > size_biffer)
      {
        //Відбулася невизначена помилка, тому треба піти на перезавантаження
        while(1);
      }
      for(unsigned int i = 0; i < *point_to_number_bytes_read_write_tmp; i++)
        buffer_serial_DataFlash_read_write[base_index + i] = Temporaty_SPI1_Buffer_Rx[5 + i];
      
      //Збільшуємо адресу з якої, можливо, треба буде продовжити читання
      *point_to_address_read_write_tmp += *point_to_number_bytes_read_write_tmp;

      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else
    {
      //Сюди, теоретично, ніколи не мала б дійти
      //У всіх інакших випадках нічого не робимо
    }
    /*************************************************/
  }
  else if (state_execution_spi1 == 2)
  {
    /*************************************************/
    //Обмін завершився з помилкою
    /*************************************************/

    //Виставляємо повідомлення, що I2C готовий до нової транзакції 
    state_execution_spi1 = -1;

    //Визначаємося з наступними діями
    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) != 0)
    {
      //Переходимо на початок цієї процедури
      etap_eeprom_write_enable = -1;
    }
    else if(
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) != 0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) != 0)
           )   
    {
      //Читається регістр статусу мікросхеми DataFlash 
      
      //Повторно читаємо регістр статусу мікросхеми DataFlash  
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT           ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT            ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT             ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT               ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) != 0)
            )
    {
      //Стоїть умова запису блоку у EEPROM
      //Залишаємо номер блоку для запису в EEPROM той самий, бо немає підтвердження, що він записався
      //Виставляємо біт встановлення дозволу на запис
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM настройок
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM настройок БС
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM юстування
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM стану тригерних світлоіндикаторів і сигнальних виходів
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM стану триґерних функцій
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM по аналоговому реєстраторі
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM по дискретному реєстраторі
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //Стоїть умова читання блоку у EEPROM по реєстраторі програмнихподій
      
      //Повторно запускаємо процес читання
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT) !=0)
    {
      //Стоїть умова читання RTC
      
      //Повторно запускаємо процес читання RTC
      _SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT) !=0)
    {
      //Стоїть умова запису дати-часу в RTC
      
      //Повторно запускаємо процес запису RTC
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT) !=0)
    {
      //Стоїть умова запису калібровки RTC
      
      //Повторно запускаємо процес запису RTC
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT          ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0     )
            )
    {
      //Стоїть умова скидання перевстановлення полів RTC 
      
      //Повторно запускаємо перевстановлення полів RTC з того самого місця, який не вийшов
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //Виконується процес переводу мікросхеми DataFlash не розмір сторінки у 256 байт
//
//      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //Виконується процес стирання мікросхеми DataFlash

      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //Виконується процес запис інформації в мікросхему DataFlash
      int *point_to_etap_writing_df;
      
      if (AR_DR == _DF_AR)
      {
        point_to_etap_writing_df = &etap_writing_df_ar;
      }
      else
      {
        point_to_etap_writing_df = &etap_writing_df_dr;
      }
      
      //Переводимо етап запису порції інформації (визнаеної змінною  number_bytes_read_write_tmp) у початковий стан
      *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
      
      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //Виконується процес читання інформації з мікросхеми DataFlash
      
      //Виставляємо біт повторного читання регістру статусу мікросхеми DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else
    {
      //У всіх інакших випадках нічого не робимо
    }
    /*************************************************/
  }
}
/*****************************************************/

