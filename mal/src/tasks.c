#include "header_mal.h"

/***********
Задачі, які мають запускатися раз при старті програми
***********/
void global_variables_installation(void)
{
  for(unsigned int i=0; i<MAX_LEVEL_MENU; i++)
  {
    position_in_current_level_menu[i] = 0;
    previous_level_in_current_level_menu[i] = -1;
  }

  //Визначення початкового стану екрану
  current_ekran.current_level = ID_EKRAN_MAIN;
  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
  current_ekran.edition = 0;
  
  for (unsigned int i = 0; i < MAX_PAGES_PROTECTION_SDC; i++) 
  {
    position_in_level_1_menu_DZ[i] = 0;
    position_in_level_1_menu_MTZ[i] = 0;
    position_in_level_1_menu_Umin[i] = 0;
    position_in_level_1_menu_Umax[i] = 0;
    position_in_level_1_menu_TZNP[i] = 0;
    position_in_level_1_menu_ZOP[i] = 0;
    position_in_level_1_menu_APV[i] = 0;
    position_in_level_1_menu_UROV[i] = 0;
    position_in_level_1_menu_CB[i] = 0;
  }
  
  for (unsigned int i = 0; i < NR_KEY_ITEMS; i++)
  {
    time_key_pressed[i] = -1;
  }
}
/**********/

/***********
Задачі, які мають запускатися раз при старті програми
***********/
void start_tasks_mal(void)
{
  /**********************
  Стартова ініціалізація змінних
  **********************/
  global_variables_installation();
  /**********************/

  /**********************
  Startova konfiguracia SPI1 dlja konfiguruvannja EEPROM, RTC i DataFlash
  **********************/
  ConfigureSPI1();
  /**********************/
  
  /**********************
  Налаштування таймеру PIT на генерацію періодчиних
  низькопріоритетних переривнь
  **********************/
  ConfigurePIT();
  /**********************/

  //Тестові біти
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOC);
//  PIO_Configure(pPins_test, PIO_LISTSIZE(pPins_test));
  
//  start_settings_emWin();
//  my_graph();

  /**********************/
  //Читаємо збережені дані юстування з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_USTUVANNJA);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані настройок захистів з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_PRT);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані настройок БС з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_BS);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані про сигнальні виходи і тригерні свтлодіоди
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_STATE_LEDS_OUTPUTS);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані про тригерну інформацію
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_TRG_FUNC);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо таблицю заповненості аналогового реєстратора
  /**********************/
  control_ar_taskes |= (1 << TASK_START_READ_TABLE_DATA);
  while (control_ar_taskes != 0)
  {
    main_routines_for_ar();
    while(
          (control_spi1_taskes[0] != 0) ||
          (control_spi1_taskes[1] != 0) ||
          (state_execution_spi1 > 0)
         )
    {
      main_routines_for_spi1();
    }
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані аналогового реєстратора з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_AR);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані дискретного реєстратора з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_DR);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/

  /**********************/
  //Читаємо збережені дані реєстратора програмних подій з EEPROM
  /**********************/
  comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR);/*зчитування, а не порівняння*/
  _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
  while(
        (control_spi1_taskes[0] != 0) ||
        (control_spi1_taskes[1] != 0) ||
        (state_execution_spi1 > 0)
       )
  {
    main_routines_for_spi1();
  }
  /**********************/
  
  restart_resurs_count = 0xff;/*Ненульове значення перезапускає лічильники*/

//  time_2_period = time_period;
//  restart_timing_period = 0xff;
}
/**********/

/***********
Періодичні, які мають запускатися на найнтжчому пріоритеті
***********/
void periodical_tasks_mal(void)
{
//  key_listener();

  //Обробка дій системи меню
  main_menu_function();

  //Управління мікросхемою для аналогового реєстратора
  if (control_ar_taskes != 0)
  {
    main_routines_for_ar();
  }
  //Обміну через SPI1
  if (
      (control_spi1_taskes[0] != 0) ||
      (control_spi1_taskes[1] != 0) ||
      (state_execution_spi1 > 0)
     )
    main_routines_for_spi1();

  /*******************/
  //Контроль достовірності важливих даних
  /*******************/
  /*
  Я перевіряю поставлені задачі через
  if ()
  else if()
  else if()
  ...
  else if ()
  Щоб за один оберт виконувалася тільки одна перевірка, тобто щоб в одному оберті
  не було надто довга затримка на фонову перевірку, хоч і важливу.
  */
  if (periodical_tasks_TEST_SETTINGS_PRT != 0)
  {
    //Стоїть у черзі активна задача самоконтролю таблиці настройок
    if ((state_spi1_task & STATE_SETTINGS_PRT_EEPROM_GOOD) != 0)
    {
      //Перевірку здійснюємо тільки тоді, коли таблиця настройок була успішно прочитана
      if (
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT    ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT    ) == 0)
         ) 
      {
        //На даний моммент не іде читання-запис таблиці настройок, тому можна здійснити контроль достовірності
        control_settings_prt();

        //Скидаємо активну задачу самоконтролю таблиці настройок
        periodical_tasks_TEST_SETTINGS_PRT = false;
      }
    }
    else
    {
      //Скидаємо активну задачу самоконтролю таблиці настройок, бо не було її успішне зчитування
      periodical_tasks_TEST_SETTINGS_PRT = false;
    }
  }
  else if (periodical_tasks_TEST_SETTINGS_BS != 0)
  {
    //Стоїть у черзі активна задача самоконтролю таблиці настройок
    if ((state_spi1_task & STATE_SETTINGS_BS_EEPROM_GOOD) != 0)
    {
      //Перевірку здійснюємо тільки тоді, коли таблиця настройок була успішно прочитана
      if (
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT    ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT    ) == 0)
         ) 
      {
        //На даний моммент не іде читання-запис таблиці настройок, тому можна здійснити контроль достовірності
        control_settings_bs();

        //Скидаємо активну задачу самоконтролю таблиці настройок
        periodical_tasks_TEST_SETTINGS_BS = false;
      }
    }
    else
    {
      //Скидаємо активну задачу самоконтролю таблиці настройок, бо не було її успішне зчитування
      periodical_tasks_TEST_SETTINGS_BS = false;
    }
  }
  else if (periodical_tasks_TEST_USTUVANNJA != 0)
  {
    //Стоїть у черзі активна задача самоконтролю юстування (і щоб не ускладнювати задачу і серійного номеру пристрою)
    if ((state_spi1_task & STATE_USTUVANNJA_EEPROM_GOOD) != 0)
    {
      //Перевірку здійснюємо тільки тоді, коли юстування було успішно прочитане
      if (
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT    ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT ) == 0) &&
          (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT    ) == 0)
         ) 
      {
        //На даний моммент не іде читання-запис юстування, тому можна здійснити контроль достовірності
        control_ustuvannja();

        //Скидаємо активну задачу самоконтролю юстування
        periodical_tasks_TEST_USTUVANNJA = false;
      }
    }
    else
    {
      //Скидаємо активну задачу самоконтролю таблиці настройок, бо не було її успішне зчитування
      periodical_tasks_TEST_USTUVANNJA = false;
    }
  }
  /*******************/
  
  /********
  Підрахунок вільного ресуру процесор-програма
  ********/
  if(resurs_temp < 0xfffffffe) resurs_temp++;
//  if (PIO_GetOutputDataStatus(pPins_test)) 
//  {
//    PIO_Clear(pPins_test);
//  }
//  else 
//  {
//    PIO_Set(pPins_test);
//  }
  
  if (period_10ms != 0)
  {
    /*Ця операція є додатковою для забезпечення роботи вікна Live Watch з-під відладчика*/
    JLINKDCC_Process();
    
    period_10ms = false;
  }
  
  
//  if (time_2_period != time_period)
//  {
//    time_1_period = time_2_period;
//    time_2_period = time_period;
//    unsigned int delta_time;
//    if (time_2_period >= time_1_period) delta_time = time_2_period - time_1_period;
//    else delta_time = (time_2_period - time_1_period) + 0xffffffff + 1;
//    time_delta_period = delta_time;
//  
//    if (restart_timing_period != 0)
//    {
//      restart_timing_period = 0;
//        
//      time_delta_period_min = 0xffffffff;
//      time_delta_period_max = 0;
//    }
//    if (time_delta_period < time_delta_period_min) time_delta_period_min = time_delta_period;
//    if (time_delta_period > time_delta_period_max) time_delta_period_max = time_delta_period;
//  }
  /*******/
}
/**********/

/***********
Мінімальні налаштування додаткових галаштувань для БС
***********/
void make_min_settings_1(AuxCfgTbl1Dsc *target)
{
  target->RS_comm_addres = KOEF_ADDRESS_MAX;
  target->chSpeed = 6;
  target->chParityCheck = 2;
  target->chAmtStopBit = 1;
  target->chTimeOut_RS = VALUE_TIME_OUT_1_INTERFACE_MIN;
  
  target->chSleepTmVal = TIMEOUT_LCD_MAX;
  
  target->chLngGUIText = ENG_LANG;
  change_language = 1;
  
  target->chWinding = 1;
  
  target->psw_interface_USB = 0;
  target->psw_interface_RS485 = 0;
  target->psw_interface_ZigBee = 0;
  
  for (unsigned int i = 0; i < 8; i++)
  {
    target->arPsw1[i] = '\0';
    target->arPsw2[i] = '\0';
  }
  const char password_2[] = "1234";
  strcat_mal(target->arPsw2, (char *)password_2);
  
  for (unsigned int i = 0; i < 48; i++)
  {
    target->Name_cell[i] = '\0';
  }
  const char name[] = "No mame";
  strcat_mal(target->Name_cell, (char *)name);
  
  for (unsigned int i = 0; i < 32; i++)
  {
    target->dt_tm_of_adjustment[i] = 0;
  }
  
  for (unsigned int i = 0; i < 6; i++)
  {
    target->dev_serial_number[i] = 0;
    target->bs_serial_number[i] = 0;
    target->bm_serial_number[i] = 0;
    target->br_serial_number[i] = 0;
    target->bdvv_serial_number[i] = 0;
    target->bax_serial_number[i] = 0;
  }
}
/**********/

/*****************************************************/
//Контроль достовірності настройок захистів
/*****************************************************/
void control_settings_prt(void)
{
  unsigned char crc_settings_prt_tmp = 0;

  unsigned char  *point = (unsigned char*)(&eeprom_prt_tbl); 
  for (unsigned int i = 0; i < sizeof(CfgTblDsc); i++)
  {
    crc_settings_prt_tmp += *(point++);
  }
  
  if (crc_settings_prt == crc_settings_prt_tmp)
  {
    //Контроль достовірності таблиці настройок пройшов успішно
    
    //Скидаємо повідомлення у слові діагностики
    _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_CONTROL_BIT);
  }
  else
  {
    //Контроль достовірності таблиці настройок не пройшов

    //Виствляємо повідомлення у слові діагностики
    _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_CONTROL_BIT);
  }
}
/*****************************************************/

/*****************************************************/
//Контроль достовірності настройок БС
/*****************************************************/
void control_settings_bs(void)
{
  unsigned char crc_settings_bs_tmp = 0;

  unsigned char  *point = (unsigned char*)(&eeprom_bs_settings_tbl); 
  for (unsigned int i = 0; i < sizeof(AuxCfgTbl1Dsc); i++)
  {
    crc_settings_bs_tmp += *(point++);
  }
  
  if (crc_settings_bs == crc_settings_bs_tmp)
  {
    //Контроль достовірності таблиці настройок пройшов успішно
    
    //Скидаємо повідомлення у слові діагностики
    _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_CONTROL_BIT);
  }
  else
  {
    //Контроль достовірності таблиці настройок не пройшов

    //Виствляємо повідомлення у слові діагностики
    _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_CONTROL_BIT);
  }
}
/*****************************************************/

/*****************************************************/
//Контроль достовірності юстування
/*****************************************************/
void control_ustuvannja(void)
{
  unsigned char crc_ustuvannja_tmp = 0;
  unsigned char  *point_1; 

  point_1 = (unsigned char*)(&ustuvannja); 
  for (unsigned int i= 0; i < sizeof(ustuvannja); i++) crc_ustuvannja_tmp += *(point_1++);

  point_1 = (unsigned char*)(&phi_ustuvannja); 
  for (unsigned int i= 0; i < sizeof(phi_ustuvannja); i++) crc_ustuvannja_tmp += *(point_1++);

  point_1 = (unsigned char*)(&ustuvannja_P); 
  for (unsigned int i= 0; i < sizeof(ustuvannja_P); i++) crc_ustuvannja_tmp += *(point_1++);
  
  point_1 = (unsigned char*)(&ustuvannja_Q); 
  for (unsigned int i= 0; i < sizeof(ustuvannja_Q); i++) crc_ustuvannja_tmp += *(point_1++);
  
  if (crc_ustuvannja == crc_ustuvannja_tmp)
  {
    //Контроль достовірності юстування пройшов успішно
    
    //Скидаємо повідомлення у слові діагностики
    _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_CONTROL_BIT);
  }
  else
  {
    //Контроль достовірності юстування не пройшов

    //Виствляємо повідомлення у слові діагностики
     _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_CONTROL_BIT);
  }
}
/*****************************************************/
