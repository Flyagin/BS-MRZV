#include "header_mal.h"

enum __local_events
{
  REDRAW = 0,
  ERROR_FIXED
};

/**************
Функція меню з якої здійснюються всі інші операції
**************/
void main_menu_function(void)
{
  static unsigned int date_time_ctrl;
  if (_CHECK_KEY_SET_BIT(key_released, VK_OFFSET_CTRL) != 0) /*knopka vipushchena*/
  {
     if (executed_action_after_press_ctrl == 0)    /*Natyskuvannja CTRL ne pryvodylo do jakychos dij na menu.*/
     {
       _CLEAR_KEY_BIT(key_pressed , VK_OFFSET_CTRL);
       _CLEAR_KEY_BIT(key_released, VK_OFFSET_CTRL);
       date_time_ctrl ^= true;
     }
     else
     {
       /*Znimajemo sygnalizaciju pro vykonannja pevnych dij u jakych brala uchast knopka CTRL*/
       executed_action_after_press_ctrl = false;
     }
  }
  if ((date_time_ctrl != true) && (date_time_ctrl != false)) date_time_ctrl = false;
  
  
  if ((state_command_power_LCD & ((unsigned int)(1 << 31))) == 0)
  {
    //Vymknutyj ekran - ne vykonujemo obnovkennja ekranu
    redraw_status_bar = 0;
    command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
  }
  
  if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ALT) != 0) /*knopka natysnuta*/
  {
    //Зафіксована натиснута кнопка Alt
    _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ALT);
              
    if (
        
        (key_pressed[0] == 0) &&
        (key_pressed[1] == 0)
       )  
    {
      if (
          (current_modal_form == false) &&
          (current_ekran.current_level != ID_MAIN_MENU)
         )
      {
        position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
        previous_level_in_current_level_menu[ID_MAIN_MENU] = current_ekran.current_level;
        current_ekran.current_level = ID_MAIN_MENU;
    
        command_menu |= (1 << REWRITE_MENU);
      }
    }
  }

  if (redraw_status_bar != 0)
  {
    //Обновлення інформації по панелі статусу
    char string[2] = {'\0', '\0'};
    unsigned int error_res = false;
    TeleMechsInfoDsc locTeleMechsInfo;
        
    long Key = GetUserKeyTeleMechsData();
    if ((Key > 0) && (Key <= 16))
    {
      long lRes = GetTeleMechsData(Key,(void*)&locTeleMechsInfo);
      if (lRes != SUCCESS_EXEC)
      {
        if ((lRes == ERROR_EXEC) || (lRes == STATE_EXEC))
        {
          lRes = GetTeleMechsData(Key,(void*)&locTeleMechsInfo);
          if (lRes != SUCCESS_EXEC) error_res = true;
        }
        else error_res = true;
      }
          
      ReturnUserKeyTeleMechsData(Key);
    }
    else error_res = true;

//    unsigned int error_data = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
    unsigned int Pick_up_Set = /*eeprom_prt_tbl.PckpStpm_store_selection + 1*/locTeleMechsInfo.chGrpSelector + 1;
    if ((error_res == false) && (Pick_up_Set >= 1) && (Pick_up_Set <= AMOUNT_SERIES_PPSPM_SETTINGS))
      string[0] = 0x30 + Pick_up_Set;
    else
      string[0] = '?';
    EDIT_SetText(Edit_groups,string);
    
    if (
        (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT) !=0) ||
        (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT    ) !=0)
       )
      EDIT_SetBkColor(Edit_saving_EERPOM, EDIT_CI_ENABLED, GUI_RED);
    else  
      EDIT_SetBkColor(Edit_saving_EERPOM, EDIT_CI_ENABLED, GUI_WHITE);
    
    if ((lStateWriting & (1 << WR_PRT_TBL_BIT)) != 0)
      EDIT_SetBkColor(Edit_transmit_settings_L, EDIT_CI_ENABLED, GUI_RED);
    else  
      EDIT_SetBkColor(Edit_transmit_settings_L, EDIT_CI_ENABLED, GUI_WHITE);
    
    if ((lStateWriting & (1 << WR_STNG_TBL_BIT)) != 0)
      EDIT_SetBkColor(Edit_transmit_settings_M, EDIT_CI_ENABLED, GUI_RED);
    else  
      EDIT_SetBkColor(Edit_transmit_settings_M, EDIT_CI_ENABLED, GUI_WHITE);
    
    unsigned char *point_data_time;
    if (copying_time == 0) point_data_time = rtc_time;
    else point_data_time = rtc_time_copy;

    char date_time[8+1];
    date_time[8] = '\0';
    if (date_time_ctrl)
    {
      //Відображаємо дату
      unsigned int data_tmp = point_data_time[5];
      date_time[0] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[1] = 0x30 + (data_tmp & 0x0f);
      date_time[2] = '.';

      data_tmp = point_data_time[6];
      date_time[3] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[4] = 0x30 + (data_tmp & 0x0f);
      date_time[5] = '.';

      data_tmp = point_data_time[7];
      date_time[6] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[7] = 0x30 + (data_tmp & 0x0f);
    }
    else
    {
      //Відображаємо час
      unsigned int data_tmp = point_data_time[3];
      date_time[0] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[1] = 0x30 + (data_tmp & 0x0f);
      date_time[2] = ':';

      data_tmp = point_data_time[2];
      date_time[3] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[4] = 0x30 + (data_tmp & 0x0f);
      date_time[5] = ':';

      data_tmp = point_data_time[1];
      date_time[6] = 0x30 + ((data_tmp & 0xf0) >> 4);
      date_time[7] = 0x30 + (data_tmp & 0x0f);
    }
    EDIT_SetText(Edit_clock,date_time);
    
    start_gui_exec = 1;
    redraw_status_bar = 0;
  }
  
  if ((command_menu & (1 << REFRESH_ACTIVE_PANELS)) != 0)
  {
    WM_HWIN FocussedWindow = WM_GetFocussedWindow();
    int index_position_tmp = current_ekran.index_position;
    int index_position_1_tmp = current_ekran.index_position_1;
    
    //Obnovlennja informaciji po vsikh vidkrytykh vkladkakh, jaki mogut zminuvatysja
    if (Settings_IconView != WM_UNATTACHED) 
    {
      current_ekran.index_position = position_in_current_level_menu[ID_SETTINGS_PG];
      redraw_panel_settings();
    }
    if (DZ_FrameWin   != WM_UNATTACHED) 
    {
      current_ekran.index_position = position_in_current_level_menu[ID_DZ_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_DZ[current_ekran.index_position];
      redraw_panel_protection(ID_DZ_PG);
    }
    if (MTZ_FrameWin  != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_MTZ_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_MTZ[current_ekran.index_position];
      redraw_panel_protection(ID_MTZ_PG);
    }
    if (TZNP_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_TZNP_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_TZNP[current_ekran.index_position];
      redraw_panel_protection(ID_TZNP_PG);
    }
    if (ZOP_FrameWin  != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_ZOP_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_ZOP[current_ekran.index_position];
      redraw_panel_protection(ID_ZOP_PG);
    }
    if (Umin_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_UMIN_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Umin[current_ekran.index_position];
      redraw_panel_protection(ID_UMIN_PG);
    }
    if (Umax_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_UMAX_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Umax[current_ekran.index_position];
      redraw_panel_protection(ID_UMAX_PG);
    }
    if (APV_FrameWin  != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_APV_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_APV[current_ekran.index_position];
      redraw_panel_protection(ID_APV_PG);
    }
    if (UROV_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_UROV_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_UROV[current_ekran.index_position];
      redraw_panel_protection(ID_UROV_PG);
    }
    if (CB_FrameWin   != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_CB_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_CB[current_ekran.index_position];
      redraw_panel_protection(ID_CB_PG);
    }
    if (Transformer_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_TRANSFORMER_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Transformer;
      redraw_panel_transformer();
    }
    if (Resurs_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_RESURS_PG];
      redraw_panel_resurs();
    }
    if (Comm_IconView != WM_UNATTACHED) 
    {
      current_ekran.index_position = position_in_current_level_menu[ID_COMM_PG];
      redraw_panel_Comm();
    }
    if (Modbus_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_MODBUS_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Modbus;
      redraw_panel_Modbus();
    }
    if (Net_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_NET_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Net;
      redraw_panel_Net();
    }
    if (Clock_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_CLOCK_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Clock;
      redraw_panel_clock();
    }
    if (TM_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_TM_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_TM[current_ekran.index_position];
      redraw_panel_info_n(ID_TM_PG);
    }
    if (Diagnostics_FrameWin != WM_UNATTACHED)
    {
      current_ekran.index_position = position_in_current_level_menu[ID_DIAGNOSTICS_PG];
      current_ekran.index_position_1 = position_in_level_1_menu_Diagnostics[current_ekran.index_position];
      redraw_panel_info_n(ID_DIAGNOSTICS_PG);
    }
    
    current_ekran.index_position = index_position_tmp;
    current_ekran.index_position_1 = index_position_1_tmp;
    WM_SetFocus(FocussedWindow);
    start_gui_exec = 1;

    command_menu &= (unsigned int)(~(1 << REFRESH_ACTIVE_PANELS));
  }
  
  //Перевіряємо чи якась кнопка натиснута
  if (
      ((command_menu & (1 << REWRITE_MENU)) != 0) ||
      (key_pressed[0] != 0) ||
      (key_pressed[1] != 0)
     )   
  {
    
    unsigned int command_state = ((1 << REDRAW));
    switch (current_ekran.current_level)
    {
      case ID_MAIN_MENU:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            WM_HWIN FocussedWindow = WM_GetFocussedWindow();
            if (
                (FocussedWindow != hMenu_main) &&
                (FocussedWindow != hMin_settings) &&
                (FocussedWindow != hOption) &&
                (FocussedWindow != hPasswords) &&
                (FocussedWindow != hPickup_Group)
               )
            {
              WM_SetFocus(hMenu_main);
            }
          }
          else
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */

                if (WM_GetFocussedWindow() == hMenu_main)
                {
//                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                  /*
                  Завершальною операцією є зняття команди на перемальованування
                  старого пункту меню і виставлення команди на обновлення нового 
                  пункту меню
                  */
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  command_menu |= (1 << REWRITE_MENU);
                }
                GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка Enter
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */

                GUI_SendKeyMsg(GUI_KEY_ENTER, 1);

                if (WM_GetFocussedWindow() == hMenu_main)
                {
                  current_ekran.current_level = previous_level_in_current_level_menu[ID_MAIN_MENU];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                  /*
                  Завершальною операцією є зняття команди на перемальованування
                  старого пункту меню і виставлення команди на обновлення нового 
                  пункту меню
                  */
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  command_menu |= (1 << REWRITE_MENU);
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                GUI_SendKeyMsg(GUI_KEY_RIGHT, 1);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                GUI_SendKeyMsg(GUI_KEY_LEFT, 1);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                GUI_SendKeyMsg(GUI_KEY_UP, 1);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                GUI_SendKeyMsg(GUI_KEY_DOWN, 1);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW)) /*При такій умові гарантовано біт з номером ERROR_FIXED не може бути встановленим*/
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_EKRAN_MAIN:
      case ID_SETTINGS_PG:
      case ID_COMM_PG:
        {
          WM_HWIN *Panel_Win;
          int number_icons;
          switch (current_ekran.current_level)
          {
           case ID_EKRAN_MAIN:
            {
              Panel_Win = &iconWin;
              number_icons = ICONVIEW_SIZE;

              break;
            }
           case ID_SETTINGS_PG:
            {
              Panel_Win = &Settings_IconView;
              number_icons = SETTINGS_SIZE;

              break;
            }
           case ID_COMM_PG:
            {
              Panel_Win = &Comm_IconView;
              number_icons = COMM_SIZE;

              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (
                (*Panel_Win == WM_UNATTACHED) ||
                (*Panel_Win == iconWin)  
               )
            {
              show_window(current_ekran.current_level);
            }
          }
          else
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (
                (current_ekran.current_level != ID_EKRAN_MAIN) &&
                (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
               )   
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                //Виходимо з панелі
                WM_DeleteWindow(*Panel_Win);
                *Panel_Win = WM_UNATTACHED;

                position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка Enter
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.current_level == ID_EKRAN_MAIN)
                {
                  switch (current_ekran.index_position) {
                    case ICONVIEW_LANGUAGE_ID:
                    case ICONVIEW_MEAS_ID:
//                    case ICONVIEW_CONFIG_ID:
//                    case ICONVIEW_RANK_ID:
                      {
                        int panel_id = get_main_panel_id();
                        position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                        previous_level_in_current_level_menu[panel_id] = current_ekran.current_level;
                        current_ekran.current_level = panel_id;
                        current_ekran.index_position = 0;
                        break;
                      }
                  case ICONVIEW_SETTINGS_ID:
                    {
                      position_in_current_level_menu[ID_EKRAN_MAIN] = current_ekran.index_position;
                      current_ekran.current_level = ID_SETTINGS_PG;
                    
                      previous_level_in_current_level_menu[current_ekran.current_level] = ID_EKRAN_MAIN;
                      current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];

                      break;
                    }
                  case ICONVIEW_CLOCK_ID:
                    {
                      position_in_current_level_menu[ID_EKRAN_MAIN] = current_ekran.index_position;
                      current_ekran.current_level = ID_CLOCK_PG;
                    
                      previous_level_in_current_level_menu[current_ekran.current_level] = ID_EKRAN_MAIN;

//                      current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level]; //Для цього вікне на має значення, бо немає мультивкладок
                      current_ekran.index_position_1 = position_in_level_1_menu_Clock;

                      break;
                    }
                  case ICONVIEW_IO_ID:
                  case ICONVIEW_DIAGN_ID:
                    {
                      position_in_current_level_menu[ID_EKRAN_MAIN] = current_ekran.index_position;
                      int *point_to_position_in_level_1_menu;
                    
                      switch (current_ekran.index_position)
                      {
                      case ICONVIEW_IO_ID:
                        {
                          current_ekran.current_level = ID_TM_PG;
                          point_to_position_in_level_1_menu = position_in_level_1_menu_TM;
                          break;
                        }
                      case ICONVIEW_DIAGN_ID:
                        {
                          current_ekran.current_level = ID_DIAGNOSTICS_PG;
                          point_to_position_in_level_1_menu = position_in_level_1_menu_Diagnostics;
                          break;
                        }
                      default:
                        {
                          //Сюди програма ніколи б не мала зайти
                          while(1);
                        }
                      }
                      
                      previous_level_in_current_level_menu[current_ekran.current_level] = ID_EKRAN_MAIN;
                      current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                      current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);

                      break;
                    }
                  case ICONVIEW_REGISTRATORS_ID:
                  case ICONVIEW_RES_COUNTER_ID:
                    {
                      position_in_current_level_menu[ID_EKRAN_MAIN] = current_ekran.index_position;
                    
                      switch (current_ekran.index_position)
                      {
                      case ICONVIEW_REGISTRATORS_ID:
                        {
                          current_ekran.current_level = ID_REGISTRATORS_PG;
                          
                          break;
                        }
                      case ICONVIEW_RES_COUNTER_ID:
                        {
                          current_ekran.current_level = ID_RESURS_PG;
                          
                          break;
                        }
                      }
                      previous_level_in_current_level_menu[current_ekran.current_level] = ID_EKRAN_MAIN;
                      current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];

                      break;
                    }
                  default:
                    {
                      //do nothing
                      break;
                    }
                  }
                }
                else if (current_ekran.current_level == ID_SETTINGS_PG)
                {
                  unsigned int error_data   = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
                  
                  switch (current_ekran.index_position)
                  {
                  case SETTINGS_CONFIG_ID:
                  case SETTINGS_RANK_ID:
                    {
                      if (error_data == 0)
                      {
                        int panel_id = get_settings_panel_id();
                        position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                        previous_level_in_current_level_menu[panel_id] = current_ekran.current_level;
                        current_ekran.current_level = panel_id;
                        current_ekran.index_position = 0;
                      }
                      else
                      {
                        Unreliable_error_title.ptitle[0] = TITLE_UNRELIABLE_ERROR_UKR;
                        Unreliable_error_title.ptitle[1] = TITLE_UNRELIABLE_ERROR_RUS;
                        Unreliable_error_title.ptitle[2] = TITLE_UNRELIABLE_ERROR_ENG;
                     
                        Unreliable_error_message.ptitle[0] = UNRELIABLE_SETTINGS_MSG_UKR;
                        Unreliable_error_message.ptitle[1] = UNRELIABLE_SETTINGS_MSG_RUS;
                        Unreliable_error_message.ptitle[2] = UNRELIABLE_SETTINGS_MSG_ENG;
                          
                        position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                        previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR] = current_ekran.current_level;
                        current_ekran.current_level = ID_UNRELIABLE_ERROR;
                      }
                      break;
                    }
                  case SETTINGS_DZ_ID:
                  case SETTINGS_MTZ_ID:
                  case SETTINGS_UMIN_ID:
                  case SETTINGS_UMAX_ID:
                  case SETTINGS_TZNP_ID:
                  case SETTINGS_ZOP_ID:
                  case SETTINGS_APV_ID:
                  case SETTINGS_UROV_ID:
                  case SETTINGS_CB_ID:
                  case TRANSFORMER_ID:
                    {
                      CfgTblDsc* pConfig = &eeprom_prt_tbl;
                      int index_position_tmp = current_ekran.index_position;
                      if (
                          (error_data == 0) &&
                          (  
                           (index_position_tmp == SETTINGS_CB_ID) || 
                           (index_position_tmp == TRANSFORMER_ID) || 
                           (_CHECK_BIT_UCHAR(pConfig->arUchCfgPrt, (index_position_tmp - 2))) )
                          )  
                      { 
                        position_in_current_level_menu[ID_SETTINGS_PG] = current_ekran.index_position;
                        int *point_to_position_in_level_1_menu;
                    
                        switch (current_ekran.index_position)
                        {
                        case SETTINGS_DZ_ID:
                          {
                            current_ekran.current_level = ID_DZ_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_DZ;
                            break;
                          }
                        case SETTINGS_MTZ_ID:
                          {
                            current_ekran.current_level = ID_MTZ_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_MTZ;
                            break;
                          }
                        case SETTINGS_UMIN_ID:
                          {
                            current_ekran.current_level = ID_UMIN_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_Umin;
                            break;
                          }
                        case SETTINGS_UMAX_ID:
                          {
                            current_ekran.current_level = ID_UMAX_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_Umax;
                            break;
                          }
                        case SETTINGS_TZNP_ID:
                          {
                            current_ekran.current_level = ID_TZNP_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_TZNP;
                            break;
                          }
                        case SETTINGS_ZOP_ID:
                          {
                            current_ekran.current_level = ID_ZOP_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_ZOP;
                            break;
                          }
                        case SETTINGS_APV_ID:
                          {
                            current_ekran.current_level = ID_APV_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_APV;
                            break;
                          }
                        case SETTINGS_UROV_ID:
                          {
                            current_ekran.current_level = ID_UROV_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_UROV;
                            break;
                          }
                        case SETTINGS_CB_ID:
                          {
                            current_ekran.current_level = ID_CB_PG;
                            point_to_position_in_level_1_menu = position_in_level_1_menu_CB;
                            break;
                          }
                        case TRANSFORMER_ID:
                          {
                            current_ekran.current_level = ID_TRANSFORMER_PG;
                            point_to_position_in_level_1_menu = &position_in_level_1_menu_Transformer;
                            break;
                          }
                        default:
                          {
                            //Сюди програма ніколи б не мала зайти
                            while(1);
                          }
                        }
                      
                        previous_level_in_current_level_menu[current_ekran.current_level] = ID_SETTINGS_PG;
                        current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                        if (
                            (current_ekran.current_level == ID_CB_PG) ||
                            (current_ekran.current_level == ID_TRANSFORMER_PG)
                          )
                        {
                          current_ekran.index_position_1 = *point_to_position_in_level_1_menu;
                        }
                        else if (
                                 (current_ekran.current_level != ID_DZ_PG) ||
                                 (current_ekran.index_position != 1)  
                                )
                        {
                          current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);
                        }
                        else
                        {
                          current_ekran.index_position_1 = position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])];
                        }
                      }
                      else
                      {
                        position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                        if (error_data == 0)
                        {
                          previous_level_in_current_level_menu[ID_DIALOG_ERROR] = current_ekran.current_level;
                          current_ekran.current_level = ID_DIALOG_ERROR;
                        }
                        else
                        {
                          Unreliable_error_title.ptitle[0] = TITLE_UNRELIABLE_ERROR_UKR;
                          Unreliable_error_title.ptitle[1] = TITLE_UNRELIABLE_ERROR_RUS;
                          Unreliable_error_title.ptitle[2] = TITLE_UNRELIABLE_ERROR_ENG;
                     
                          Unreliable_error_message.ptitle[0] = UNRELIABLE_SETTINGS_MSG_UKR;
                          Unreliable_error_message.ptitle[1] = UNRELIABLE_SETTINGS_MSG_RUS;
                          Unreliable_error_message.ptitle[2] = UNRELIABLE_SETTINGS_MSG_ENG;
                          
                          previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR] = current_ekran.current_level;
                          current_ekran.current_level = ID_UNRELIABLE_ERROR;
                        }
                      }
                      break;
                    }
                  case COMM_ID:
                    {
                      position_in_current_level_menu[ID_SETTINGS_PG] = current_ekran.index_position;
                      current_ekran.current_level = ID_COMM_PG;
                    
                      previous_level_in_current_level_menu[current_ekran.current_level] = ID_SETTINGS_PG;
                      current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];

                      break;
                    }
                    default:
                      {
                        //do nothing
                        break;
                      }
                  }

                  if (
                      (current_ekran.current_level != ID_DIALOG_ERROR) &&
                      (current_ekran.current_level != ID_UNRELIABLE_ERROR)
                     )
                  {
                    //Ввидаляємо панель на якій було натиснуто ENTER
                    WM_DeleteWindow(*Panel_Win);
                    *Panel_Win = WM_UNATTACHED;
                  }
                }
                else if (current_ekran.current_level == ID_COMM_PG)
                {
                  unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);

                  if (error_data_1 == 0)
                  {
                    position_in_current_level_menu[ID_COMM_PG] = current_ekran.index_position;
                    int *point_to_position_in_level_1_menu;
                    
                    switch (current_ekran.index_position)
                    {
                    case COMM_MODBUS_ID:
                      {
                        current_ekran.current_level = ID_MODBUS_PG;
                        point_to_position_in_level_1_menu = &position_in_level_1_menu_Modbus;
                        break;
                      }
                    case COMM_NET_ID:
                      {
                        current_ekran.current_level = ID_NET_PG;
                        point_to_position_in_level_1_menu = &position_in_level_1_menu_Net;
                        break;
                      }
                    default:
                      {
                        //Сюди програма ніколи б не мала зайти
                        while(1);
                      }
                    }
                      
                    previous_level_in_current_level_menu[current_ekran.current_level] = ID_COMM_PG;
                    current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                    current_ekran.index_position_1 = *point_to_position_in_level_1_menu;
                  }
                  else
                  {
                    Unreliable_error_title.ptitle[0] = TITLE_UNRELIABLE_ERROR_UKR;
                    Unreliable_error_title.ptitle[1] = TITLE_UNRELIABLE_ERROR_RUS;
                    Unreliable_error_title.ptitle[2] = TITLE_UNRELIABLE_ERROR_ENG;
                     
                    Unreliable_error_message.ptitle[0] = UNRELIABLE_SETTINGS_MSG_UKR;
                    Unreliable_error_message.ptitle[1] = UNRELIABLE_SETTINGS_MSG_RUS;
                    Unreliable_error_message.ptitle[2] = UNRELIABLE_SETTINGS_MSG_ENG;

                    position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR] = current_ekran.current_level;
                    current_ekran.current_level = ID_UNRELIABLE_ERROR;
                  }

                  if (current_ekran.current_level != ID_UNRELIABLE_ERROR)
                  {
                    //Ввидаляємо панель на якій було натиснуто ENTER
                    WM_DeleteWindow(*Panel_Win);
                    *Panel_Win = WM_UNATTACHED;
                  }
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position = 0;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                current_ekran.index_position = number_icons - 1;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */

                int index_position_tmp = current_ekran.index_position;
                if (
                    ( (index_position_tmp + 1) >= number_icons) ||
                    (((index_position_tmp + 1) / MAX_ICONVIEW_COLUMN_LENGTH) != (index_position_tmp / MAX_ICONVIEW_COLUMN_LENGTH))
                   )
                {
                  index_position_tmp = (index_position_tmp / MAX_ICONVIEW_COLUMN_LENGTH)* MAX_ICONVIEW_COLUMN_LENGTH;
                }
                else 
                {
                  index_position_tmp++;
                }
                current_ekran.index_position = index_position_tmp;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                int index_position_tmp = current_ekran.index_position;
                if (
                    ( (index_position_tmp - 1) < 0) ||
                    (((index_position_tmp - 1) / MAX_ICONVIEW_COLUMN_LENGTH) != (index_position_tmp / MAX_ICONVIEW_COLUMN_LENGTH))
                   )
                {
                  int index_next_row_icon =  (index_position_tmp / MAX_ICONVIEW_COLUMN_LENGTH  + 1)*MAX_ICONVIEW_COLUMN_LENGTH;
                  
                  if (index_next_row_icon <= number_icons) index_position_tmp = index_next_row_icon - 1;
                  else index_position_tmp = number_icons - 1;
                }
                else
                {
                  index_position_tmp--;
                }
                current_ekran.index_position = index_position_tmp;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
            {
              //Зафіксована натиснута кнопка PAGE UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PAGE UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                int index_position_tmp = current_ekran.index_position - MAX_ICONVIEW_ROW_LENGTH*MAX_ICONVIEW_COLUMN_LENGTH;
                while (index_position_tmp < 0) index_position_tmp += MAX_ICONVIEW_COLUMN_LENGTH;
                current_ekran.index_position = index_position_tmp;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
            {
              //Зафіксована натиснута кнопка PAGE DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PAGE DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                int index_position_tmp = current_ekran.index_position + MAX_ICONVIEW_ROW_LENGTH*MAX_ICONVIEW_COLUMN_LENGTH;
                while (index_position_tmp >= number_icons) index_position_tmp -= MAX_ICONVIEW_COLUMN_LENGTH;
                current_ekran.index_position = index_position_tmp;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                int index_position_tmp = current_ekran.index_position - MAX_ICONVIEW_COLUMN_LENGTH;
                while (index_position_tmp < 0)
                {
                  index_position_tmp = (number_icons / MAX_ICONVIEW_COLUMN_LENGTH)*MAX_ICONVIEW_COLUMN_LENGTH +  (current_ekran.index_position % MAX_ICONVIEW_COLUMN_LENGTH);
                  if (index_position_tmp >= number_icons ) index_position_tmp -= MAX_ICONVIEW_COLUMN_LENGTH;
                }
                current_ekran.index_position = index_position_tmp;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                int index_position_tmp = current_ekran.index_position + MAX_ICONVIEW_COLUMN_LENGTH;
                while (index_position_tmp >= number_icons)
                {
                  index_position_tmp = current_ekran.index_position % MAX_ICONVIEW_COLUMN_LENGTH;
                }
                current_ekran.index_position = index_position_tmp;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW)) /*При такій умові гарантовано біт з номером ERROR_FIXED не може бути встановленим*/
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_LANG_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            show_window(ID_LANG_DLG);
          } else {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                set_current_language(ID_LANG_BUTTON_CANCEL); //set previous language
                
                hide_window(ID_LANG_DLG);
                current_ekran.current_level = previous_level_in_current_level_menu[ID_LANG_DLG];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                current_modal_form = false;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_language_next();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_language_previous();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_language_previous();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_language_next();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (++current_ekran.index_position >= MAX_LEVEL_LANG_DLG)
                  current_ekran.index_position = 0;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                set_current_language(current_ekran.index_position); //check CANCEL or OK into set_current_language
                
                hide_window(ID_LANG_DLG);
                current_ekran.current_level = previous_level_in_current_level_menu[ID_LANG_DLG];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                current_modal_form = false;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //redraw language dialog
            win_handler();
          }
          
          break;
        }
      case ID_WINDING_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            show_window(ID_WINDING_DLG);
          } else {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                set_current_winding(ID_WINDING_BUTTON_CANCEL); //set previous language
                
                hide_window(ID_WINDING_DLG);
                //hide_window(ID_WINDING_DLG);
                /*if(current_ekran.current_level == ID_EKRAN_MAIN){
                    hide_window(ID_LANG_DLG);
                    current_ekran.current_level = previous_level_in_current_level_menu[ID_LANG_DLG];
                }
                else{
                    hide_window(ID_WINDING_DLG);
                    current_ekran.current_level = previous_level_in_current_level_menu[ID_WINDING_DLG];
                } */   
                current_ekran.current_level = previous_level_in_current_level_menu[ID_WINDING_DLG];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                current_modal_form = false;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_winding_next();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_winding_previous();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_winding_previous();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                change_winding_next();
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (++current_ekran.index_position >= MAX_LEVEL_WINDING_DLG)
                  current_ekran.index_position = 0;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                set_current_winding(current_ekran.index_position); //check CANCEL or OK into set_current_language
                
                hide_window(ID_WINDING_DLG);
                current_ekran.current_level = previous_level_in_current_level_menu[ID_WINDING_DLG];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                current_modal_form = false;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //redraw language dialog
            win_handler();
          }
          
          break;
        }
      case ID_MEAS_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = meas_index_position;
            if (measMultiPageWin == WM_UNATTACHED) {
              show_window(ID_MEAS_PG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                hide_window(ID_MEAS_PG);
                current_ekran.current_level = previous_level_in_current_level_menu[ID_MEAS_PG];
                meas_index_position = current_ekran.index_position;
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                show_window(windingWin);
                previous_level_in_current_level_menu[ID_WINDING_DLG] = current_ekran.current_level;
                current_ekran.current_level = ID_WINDING_DLG;
                meas_index_position = current_ekran.index_position;
                current_ekran.index_position = 0;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.index_position == MAX_LEVEL_MEAS_PG - 1) {
                  current_ekran.index_position = ID_MEAS_FOURIER_PG;
                } else {
                  current_ekran.index_position++;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == ID_MEAS_FOURIER_PG) {
                  current_ekran.index_position = MAX_LEVEL_MEAS_PG - 1;
                } else {
                  current_ekran.index_position--;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка Up
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою Up не була натиснута інша кнопка
                Можна виконувати дії
                */
                switch(current_ekran.index_position) {
                  case ID_MEAS_RESISTANCES_PG:
                    {
                      if (resistancesPosition == 0) {
                        resistancesPosition = MEAS_NUM_LEVEL_RESISTANCES - 1;
                      } else {
                        resistancesPosition--;
                      }
                      select_meas_multipage_up_down();
                      break;
                    }
                  case ID_MEAS_OTHER_PG:
                    {
                      meas_scrolling_direction(UP);
                      break;
                    }
                  default:break;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка Down
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою Down не була натиснута інша кнопка
                Можна виконувати дії
                */
                switch(current_ekran.index_position) {
                  case ID_MEAS_RESISTANCES_PG:
                    {
                      if (resistancesPosition == MEAS_NUM_LEVEL_RESISTANCES - 1) {
                        resistancesPosition = 0;
                      } else {
                        resistancesPosition++;
                      }
                      select_meas_multipage_up_down();
                      break;
                    }
                  case ID_MEAS_OTHER_PG:
                    {
                      meas_scrolling_direction(DOWN);
                      break;
                    }
                  default:break;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
            {
              //Зафіксована натиснута кнопка PgUp
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PgUp не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.index_position == MAX_LEVEL_MEAS_PG - 1) {
                  current_ekran.index_position = ID_MEAS_FOURIER_PG;
                } else {
                  current_ekran.index_position++;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
            {
              //Зафіксована натиснута кнопка PgDn
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PgDn не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == ID_MEAS_FOURIER_PG) {
                  current_ekran.index_position = MAX_LEVEL_MEAS_PG - 1;
                } else {
                  current_ekran.index_position--;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка END
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position = MAX_LEVEL_MEAS_PG - 1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка HOME
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position = ID_MEAS_FOURIER_PG;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_CONFIG_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = config_index_position;
            if (configPageWin == WM_UNATTACHED) {
              show_window(ID_CONFIG_PG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0 || current_ekran.edition == 1) {
                  /*
                  Дані не змінювалися, тому виходимо з режиму редагування без запиту
                  на підтвердження змін
                  */
                  current_ekran.edition = 0;
                  
                  hide_window(ID_CONFIG_PG);
                  current_ekran.current_level = previous_level_in_current_level_menu[ID_CONFIG_PG];
                  config_index_position = current_ekran.index_position;
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                } else {
                  /*
                  Дані змінювалися, тому формуємо запит на підтердження змін
                  */
                  position_in_current_level_menu[ID_CONFIG_PG] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_CONFIG_PG;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_CONFIG_PG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_CONFIG_PG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення нового 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    conf_enter_handler();
                  }
                } else {
                  conf_enter_handler();
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_SHIFT) != 0)
            {
              //Зафіксована натиснута кнопка SHIFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_SHIFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                if (current_ekran.edition != 0) {
                  position_in_current_level_menu[ID_CONFIG_PG] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_CONFIG_PG;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                  
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  command_menu |= (1 << REWRITE_MENU);
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0) {
                  current_ekran.index_position = NUM_CONF_ITEMS - 1;
                } else {
                  current_ekran.index_position--;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == NUM_CONF_ITEMS - 1) {
                  current_ekran.index_position = 0;
                } else {
                  current_ekran.index_position++;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_RANK_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = rank_index_position;
            show_window(ID_RANK_PG);
          } else {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (rank_vk_esc_handler()) {
                  //do nothing
                } else {
                  if (current_ekran.edition == 0 || current_ekran.edition == 1) {
                    /*
                    Дані не змінювалися, тому виходимо з режиму редагування без запиту
                    на підтвердження змін
                    */
                    current_ekran.edition = 0;
                    
                    hide_window(ID_RANK_PG);
                    current_ekran.current_level = previous_level_in_current_level_menu[ID_RANK_PG];
                    current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                  } else {
                    /*
                    Дані змінювалися, тому формуємо запит на підтердження змін
                    */
                    position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_RANK_PG;
                      
                    current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                  }
                  /*
                  Завершальною операцією є зняття команди на перемальованування
                  старого пункту меню і виставлення команди на обновлення ногого 
                  пункту меню
                  */
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  command_menu |= (1 << REWRITE_MENU);
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                int multi_pg_val;
                switch (current_ekran.index_position) {
                  case ID_RANK_DISCRETE_INPUT_PG:
                    {
                      multi_pg_val = di_index;
                      break;
                    }
                  case ID_RANK_DISCRETE_OUTPUT_PG:
                    {
                      multi_pg_val = do_index;
                      break;
                    }
                  case ID_RANK_LED_PG:
                    {
                      multi_pg_val = led_index;
                      break;
                    }
                  case ID_RANK_DF_PLUS_PG:
                    {
                      multi_pg_val = df_plus_index;
                      break;
                    }
                  case ID_RANK_DF_MINUS_PG:
                    {
                      multi_pg_val = df_minus_index;
                      break;
                    }
                  case ID_RANK_DF_BLK_PG:
                    {
                      multi_pg_val = df_blk_index;
                      break;
                    }
                  case ID_RANK_F_PG:
                    {
                      multi_pg_val = f_index;
                      break;
                    }
                  case ID_RANK_TRG_SET_PL_PG:
                    {
                      multi_pg_val = trg_set_pl_index;
                      break;
                    }
                  case ID_RANK_TRG_SET_MN_PG:
                    {
                      multi_pg_val = trg_set_mn_index;
                      break;
                    }
                  case ID_RANK_TRG_RST_PL_PG:
                    {
                      multi_pg_val = trg_rst_pl_index;
                      break;
                    }
                  case ID_RANK_TRG_RST_MN_PG:
                    {
                      multi_pg_val = trg_rst_mn_index;
                      break;
                    }
                  case ID_RANK_AN_DIG_REC_PG:
                    {
                      multi_pg_val = an_dig_rec_index;
                      break;
                    }
                  default:
                    {
                      multi_pg_val = di_index;
                    }
                }
                
                if (((multi_pg_val & 0x80000000) > 0) && checkbox_is_enabled()) {
                  
                  if (current_ekran.edition == 0) {
                    if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                      //Переходимо на запит паролю
                      position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_PG;
                      
                      current_ekran.current_level = ID_DIALOG_PASSWORD;
                  
                      //Обнуляємо введений пароль
                      typed_password[0] = '\0';
                      cursor_position_dp = 0;
                      
                      /*
                      Завершальною операцією є зняття команди на перемальованування
                      старого пункту меню і виставлення команди на обновлення ногого 
                      пункту меню
                      */
                      command_state &= (unsigned int)(~(1 << REDRAW));
                      command_menu |= (1 << REWRITE_MENU);
                    } else {
                      //Переходимо в режим редагування 
                      current_ekran.edition = 1;
                      rank_vk_enter_handler();
                    }
                  } else {
                    rank_vk_enter_handler();
                  }
                  
                } else if ((multi_pg_val & 0x80000000) == 0) {
                  rank_vk_enter_handler();
                } else {
                  //do nothing
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0)
            {
              //Зафіксована натиснута кнопка 1
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою 1 не була натиснута інша кнопка
                Можна виконувати дії
                */
                switch (current_ekran.index_position) {
                  case ID_RANK_DISCRETE_INPUT_PG:
                    {
                      rank_vk_esc_handler();
                      position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_RANK_DI_DLG] = ID_RANK_PG;
                        
                      current_ekran.current_level = ID_RANK_DI_DLG;
                      
                      rank_index_position = current_ekran.index_position;
                      
                      command_state &= (unsigned int)(~(1 << REDRAW));
                      command_menu |= (1 << REWRITE_MENU);
                      break;
                    }
                  case ID_RANK_DISCRETE_OUTPUT_PG:
                    {
                      rank_vk_esc_handler();
                      position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_RANK_DO_DLG] = ID_RANK_PG;
                        
                      current_ekran.current_level = ID_RANK_DO_DLG;
                      
                      rank_index_position = current_ekran.index_position;
                      
                      command_state &= (unsigned int)(~(1 << REDRAW));
                      command_menu |= (1 << REWRITE_MENU);
                      break;
                    }
                  case ID_RANK_LED_PG:
                    {
                      rank_vk_esc_handler();
                      position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_RANK_LED_DLG] = ID_RANK_PG;
                        
                      current_ekran.current_level = ID_RANK_LED_DLG;
                      
                      rank_index_position = current_ekran.index_position;
                      
                      command_state &= (unsigned int)(~(1 << REDRAW));
                      command_menu |= (1 << REWRITE_MENU);
                      break;
                    }
                  case ID_RANK_DF_PLUS_PG:
                  case ID_RANK_DF_MINUS_PG:
                  case ID_RANK_DF_BLK_PG:
                    {
                      if (current_ekran.index_position == ID_RANK_DF_PLUS_PG) {
                        df_index = ignore_hbit(df_plus_index);
                      } else if (current_ekran.index_position == ID_RANK_DF_MINUS_PG) {
                        df_index = ignore_hbit(df_minus_index);
                      } else if (current_ekran.index_position == ID_RANK_DF_BLK_PG) {
                        df_index = ignore_hbit(df_blk_index);
                      }
                      rank_vk_esc_handler();
                      position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_RANK_DF_DLG] = ID_RANK_PG;
                        
                      current_ekran.current_level = ID_RANK_DF_DLG;
                      
                      rank_index_position = current_ekran.index_position;
                      
                      command_state &= (unsigned int)(~(1 << REDRAW));
                      command_menu |= (1 << REWRITE_MENU);
                      break;
                    }
                  case ID_RANK_AN_DIG_REC_PG:
                    {
                      if (ignore_hbit(an_dig_rec_index) == 0) {
                        rank_vk_esc_handler();
                        position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                        previous_level_in_current_level_menu[ID_RANK_AN_REC_DLG] = ID_RANK_PG;
                          
                        current_ekran.current_level = ID_RANK_AN_REC_DLG;
                        
                        rank_index_position = current_ekran.index_position;
                        
                        command_state &= (unsigned int)(~(1 << REDRAW));
                        command_menu |= (1 << REWRITE_MENU);
                      }
                      break;
                    }
                  case ID_RANK_F_PG:
                  case ID_RANK_TRG_SET_PL_PG:
                  case ID_RANK_TRG_SET_MN_PG:
                  case ID_RANK_TRG_RST_PL_PG:
                  case ID_RANK_TRG_RST_MN_PG:
                  default:
                    //do nothing
                    break;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_SHIFT) != 0)
            {
              //Зафіксована натиснута кнопка SHIFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_SHIFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                if (current_ekran.edition != 0) {
                  rank_vk_esc_handler();
                  position_in_current_level_menu[ID_RANK_PG] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_RANK_PG;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                  
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  command_menu |= (1 << REWRITE_MENU);
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                rank_vk_esc_handler();
                if (current_ekran.index_position == MAX_LEVEL_RANK_PG - 1) {
                  current_ekran.index_position = ID_RANK_DISCRETE_INPUT_PG;
                } else {
                  current_ekran.index_position++;
                }
                rank_control_bits |= RIGHT_OR_LEFT_MOVING_MASK;
                init_sub_pg(current_ekran.index_position);
                rank_index_position = current_ekran.index_position;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                rank_vk_esc_handler();
                if (current_ekran.index_position == ID_RANK_DISCRETE_INPUT_PG) {
                  current_ekran.index_position = MAX_LEVEL_RANK_PG - 1;
                } else {
                  current_ekran.index_position--;
                }
                rank_control_bits |= RIGHT_OR_LEFT_MOVING_MASK;
                init_sub_pg(current_ekran.index_position);
                rank_index_position = current_ekran.index_position;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
            {
              //Зафіксована натиснута кнопка PgUp
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PgUp не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(UP, 1/*страничный переход*/, MAX_RANK_MUL_PG_JUMP, CHECKBOX_JUMP_VAL);
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
            {
              //Зафіксована натиснута кнопка PgDn
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою PgDn не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(DOWN, 1/*страничный переход*/, MAX_RANK_MUL_PG_JUMP, CHECKBOX_JUMP_VAL);
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка END
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(DOWN, 1/*страничный переход*/, MAX_NUM_RANK_PGS, MAX_CHECKBOX_JUMP_VAL);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка HOME
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(UP, 1/*страничный переход*/, MAX_NUM_RANK_PGS, MAX_CHECKBOX_JUMP_VAL);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(UP, 0, 0, 0);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                select_rank_sub_multipage(DOWN, 0, 0, 0);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_RANK_DI_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0) {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = 0;
            if (rankDlgDIPg == WM_UNATTACHED) {
              show_window(ID_RANK_DI_DLG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_RANK_DI_DLG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_DI_DLG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                  }
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0) {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                hide_window(ID_RANK_DI_DLG);

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
                
              } else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0) {
                  current_ekran.index_position = RANK_DI_DLG_NUM_COMP - 1;
                } else {
                  current_ekran.index_position--;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == RANK_DI_DLG_NUM_COMP - 1) {
                  current_ekran.index_position = 0;
                } else {
                  current_ekran.index_position++;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (di_dlg_event_listener(key_pressed, &command_state, ERROR_FIXED)) {
              //do nothing
            }
            else {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
            
          }
          if (command_state == (1 << REDRAW)) {
            win_handler();
          }
          break;
        }
      case ID_RANK_DO_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0) {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = 0;
            if (rankDlgDOPg == WM_UNATTACHED) {
              show_window(ID_RANK_DO_DLG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_RANK_DO_DLG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_DO_DLG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                  }
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0) {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                hide_window(ID_RANK_DO_DLG);

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
                
              } else command_state |= (1 << ERROR_FIXED);
            }
            else if (do_dlg_event_listener(key_pressed, &command_state, ERROR_FIXED)) {
              //do nothing
            }
            else {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
            
          }
          if (command_state == (1 << REDRAW)) {
            win_handler();
          }
          break;
        }
      case ID_RANK_LED_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0) {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = 0;
            if (rankDlgLEDPg == WM_UNATTACHED) {
              show_window(ID_RANK_LED_DLG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_RANK_LED_DLG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_LED_DLG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                  }
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0) {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                hide_window(ID_RANK_LED_DLG);

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
                
              } else command_state |= (1 << ERROR_FIXED);
            }
            else if (led_dlg_event_listener(key_pressed, &command_state, ERROR_FIXED)) {
              //do nothing
            }
            else {
              key_pressed[0] = 0;
              key_pressed[1] = 0;
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
            
          }
          if (command_state == (1 << REDRAW)) {
            win_handler();
          }
          break;
        }
      case ID_RANK_DF_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0) {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = 0;
            if (rankDlgDFPg == WM_UNATTACHED) {
              show_window(ID_RANK_DF_DLG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_RANK_DF_DLG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_DF_DLG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                  }
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0) {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                hide_window(ID_RANK_DF_DLG);

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
                
              } else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0) {
                  current_ekran.index_position = RANK_DF_DLG_NUM_COMP - 1;
                } else {
                  current_ekran.index_position--;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == RANK_DF_DLG_NUM_COMP - 1) {
                  current_ekran.index_position = 0;
                } else {
                  current_ekran.index_position++;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (df_dlg_event_listener(key_pressed, &command_state, ERROR_FIXED)) {
              //do nothing
            }
            else {
              key_pressed[0] = 0;
              key_pressed[1] = 0;
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
            
          }
          if (command_state == (1 << REDRAW)) {
            win_handler();
          }
          break;
        }
      case ID_RANK_AN_REC_DLG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0) {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            current_ekran.index_position = 0;
            if (rankDlgAnRecPg == WM_UNATTACHED) {
              show_window(ID_RANK_AN_REC_DLG);
              command_state &= (unsigned int)(~(1 << REDRAW));
              command_menu |= (1 << REWRITE_MENU);
            }
          } else {
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0) {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0') {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[ID_RANK_AN_REC_DLG] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = ID_RANK_AN_REC_DLG;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                    
                    /*
                    Завершальною операцією є зняття команди на перемальованування
                    старого пункту меню і виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_state &= (unsigned int)(~(1 << REDRAW));
                    command_menu |= (1 << REWRITE_MENU);
                  } else {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                  }
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0) {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                hide_window(ID_RANK_AN_REC_DLG);

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
                
              } else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка UP
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0) {
                  current_ekran.index_position = RANK_AN_REC_DLG_NUM_COMP - 1;
                } else {
                  current_ekran.index_position--;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка DOWN
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == RANK_AN_REC_DLG_NUM_COMP - 1) {
                  current_ekran.index_position = 0;
                } else {
                  current_ekran.index_position++;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (an_rec_dlg_event_listener(key_pressed, &command_state, ERROR_FIXED)) {
              //do nothing
            }
            else {
              key_pressed[0] = 0;
              key_pressed[1] = 0;
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
            
          }
          if (command_state == (1 << REDRAW)) {
            win_handler();
          }
          break;
        }
        
      case ID_DIALOG_PASSWORD:
      case ID_DIALOG_PASSWORD_LEVEL_2:
      case ID_DIALOG_PASSWORD_OLD_1:
      case ID_DIALOG_PASSWORD_OLD_2:
      case ID_DIALOG_PASSWORD_NEW_1:
      case ID_DIALOG_PASSWORD_NEW_2:
      case ID_DIALOG_CONFIRMATION:
      case ID_DIALOG_CONFIRMATION_LEVEL_2:
      case ID_DIALOG_ERROR:
      case ID_DIALOG_ERROR_LEVEL_2:
      case ID_UNRELIABLE_ERROR:
      case ID_UNRELIABLE_ERROR_LEVEL_2:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            WM_HWIN *Panel_Win;
            switch (current_ekran.current_level)
            {
              case ID_DIALOG_PASSWORD:
              {
                Panel_Win = &Dialog_password_FrameWin;

                break;
              }
              case ID_DIALOG_PASSWORD_LEVEL_2:
              case ID_DIALOG_PASSWORD_OLD_1:
              case ID_DIALOG_PASSWORD_OLD_2:
              case ID_DIALOG_PASSWORD_NEW_1:
              case ID_DIALOG_PASSWORD_NEW_2:
              {
                Panel_Win = &Dialog_password_level_2_FrameWin;

                break;
              }
            case ID_DIALOG_CONFIRMATION:
              {
                Panel_Win = &Dialog_confirmation_FrameWin;

                break;
              }
            case ID_DIALOG_CONFIRMATION_LEVEL_2:
              {
                Panel_Win = &Dialog_confirmation_level_2_FrameWin;

                break;
              }
            case ID_DIALOG_ERROR:
              {
                Panel_Win = &Dialog_error_FrameWin;

                break;
              }
            case ID_DIALOG_ERROR_LEVEL_2:
              {
                Panel_Win = &Dialog_error_level_2_FrameWin;

                break;
              }
            case ID_UNRELIABLE_ERROR:
              {
                Panel_Win = &Unreliable_error_FrameWin;

                break;
              }
            case ID_UNRELIABLE_ERROR_LEVEL_2:
              {
                Panel_Win = &Unreliable_error_level_2_FrameWin;

                break;
              }
            default:
              {
                //Сюди програма ніколи б не мала зайти
                while(1);
              }
            }
            
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));

            if (current_ekran.current_level == ID_DIALOG_CONFIRMATION_LEVEL_2)
            {
              if (min_settings != false)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_MIN_SETTINGS_PRT_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_MIN_SETTINGS_PRT_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_MIN_SETTINGS_PRT_MSG_ENG;
              }
              else if (min_settings_1 != false)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_MIN_SETTINGS_1_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_MIN_SETTINGS_1_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_MIN_SETTINGS_1_MSG_ENG;
              }
              else if (command_from_menu & (1 << BIT_CLEAR_ACTUATED_FUNCTIONS))
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_COMMAND_1_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_COMMAND_1_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_COMMAND_1_MSG_ENG;
              }
              else if (command_from_menu & (1 << BIT_CLEAR_AR))
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_COMMAND_2_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_COMMAND_2_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_COMMAND_2_MSG_ENG;
              }
              else if (command_from_menu & (1 << BIT_CLEAR_DR))
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_COMMAND_3_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_COMMAND_3_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_COMMAND_3_MSG_ENG;
              }
              else if (command_from_menu & (1 << BIT_CLEAR_RPP))
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_COMMAND_4_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_COMMAND_4_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_COMMAND_4_MSG_ENG;
              }
              else if (command_from_menu & (1 << BIT_CLEAR_RESOURCE_COUNTER))
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_ACTIVATED_COMMAND_5_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_ACTIVATED_COMMAND_5_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_ACTIVATED_COMMAND_5_MSG_ENG;
              }
              else if (set_new_Pick_up_Set == true)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_CHANGE_PICK_UP_SET_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_CHANGE_PICK_UP_SET_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_CHANGE_PICK_UP_SET_MSG_ENG;
              }
              else if (command_word_for_change_password & CHANGING_PASSWORD_1)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_PASSWORD_NEW_1_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_PASSWORD_NEW_1_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_PASSWORD_NEW_1_MSG_ENG;
              }
              else if (command_word_for_change_password & CHANGING_PASSWORD_2)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_PASSWORD_NEW_2_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_PASSWORD_NEW_2_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_PASSWORD_NEW_2_MSG_ENG;
              }
              else if (previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] == ID_LCD_SETTINGS)
              {
                Dialog_confirmation_level_2_message.ptitle[0] = CONFIRM_LCD_SETTINGS_MSG_UKR;
                Dialog_confirmation_level_2_message.ptitle[1] = CONFIRM_LCD_SETTINGS_MSG_RUS;
                Dialog_confirmation_level_2_message.ptitle[2] = CONFIRM_LCD_SETTINGS_MSG_ENG;
              }
            }
            else if (current_ekran.current_level == ID_DIALOG_CONFIRMATION)
            {
              switch (previous_level_in_current_level_menu[current_ekran.current_level])
              {
              case ID_DZ_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_DZ_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_DZ_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_DZ_MSG_ENG;

                  break;
                }
              case ID_MTZ_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_MTZ_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_MTZ_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_MTZ_MSG_ENG;

                  break;
                }
              case ID_UMIN_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_UMIN_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_UMIN_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_UMIN_MSG_ENG;

                  break;
                }
              case ID_UMAX_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_UMAX_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_UMAX_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_UMAX_MSG_ENG;

                  break;
                }
              case ID_TZNP_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_TZNP_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_TZNP_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_TZNP_MSG_ENG;

                  break;
                }
              case ID_ZOP_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_ZOP_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_ZOP_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_ZOP_MSG_ENG;

                  break;
                }
              case ID_APV_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_APV_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_APV_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_APV_MSG_ENG;

                  break;
                }
              case ID_UROV_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_UROV_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_UROV_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_UROV_MSG_ENG;

                  break;
                }
              case ID_CB_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_CB_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_CB_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_CB_MSG_ENG;

                  break;
                }
              case ID_TRANSFORMER_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_TRANSFORMER_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_TRANSFORMER_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_TRANSFORMER_MSG_ENG;

                  break;
                }
              case ID_MODBUS_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_MODBUS_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_MODBUS_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_MODBUS_MSG_ENG;

                  break;
                }
              case ID_NET_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_NET_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_NET_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_NET_MSG_ENG;

                  break;
                }
              case ID_CLOCK_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_CLOCK_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_CLOCK_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_CLOCK_MSG_ENG;

                  break;
                }
              case ID_RANK_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_RANK_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_RANK_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_RANK_MSG_ENG;
                  break;
                }
              case ID_CONFIG_PG:
                {
                  Dialog_confirmation_message.ptitle[0] = CONFIRM_CONFIG_MSG_UKR;
                  Dialog_confirmation_message.ptitle[1] = CONFIRM_CONFIG_MSG_RUS;
                  Dialog_confirmation_message.ptitle[2] = CONFIRM_CONFIG_MSG_ENG;
                  break;
                }
              default:
                {
                  //Сюди програма може заходити!!! (якщо попереднім вікном не є вікно уставок-витримок-налаштувань)
                  break;
                }
              }
            }

            if (*Panel_Win == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (
                (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0) ||
                (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC  ) != 0)
               )   
            {
              //Зафіксована натиснута кнопка ENDER або ESC
              unsigned int enter, esc;
              if (enter = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
                
              if (esc   = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC  ) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (current_ekran.current_level == ID_UNRELIABLE_ERROR) ||
                  (current_ekran.current_level == ID_UNRELIABLE_ERROR_LEVEL_2)
                 ) 
              {
                //Dlja danogo vikna knopka ENTER ne pracjue
                enter = 0; 
              }
              
              if (
                  ((enter + esc) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER або ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                unsigned int (*check_pickup_delay_protection)(CfgTblDsc*);
                void (*copy_data_protection)(CfgTblDsc*, CfgTblDsc*);
                
                switch (previous_level_in_current_level_menu[current_ekran.current_level])
                {
                case ID_DZ_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_DZ;
                    copy_data_protection = copy_data_DZ;
                    break;
                  }
                case ID_MTZ_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_MTZ;
                    copy_data_protection = copy_data_MTZ;
                    break;
                  }
                case ID_UMIN_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_Umin;
                    copy_data_protection = copy_data_Umin;
                    break;
                  }
                case ID_UMAX_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_Umax;
                    copy_data_protection = copy_data_Umax;
                    break;
                  }
                case ID_TZNP_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_TZNP;
                    copy_data_protection = copy_data_TZNP;
                    break;
                  }
                case ID_ZOP_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_ZOP;
                    copy_data_protection = copy_data_ZOP;
                    break;
                  }
                case ID_APV_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_APV;
                    copy_data_protection = copy_data_APV;
                    break;
                  }
                case ID_UROV_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_UROV;
                    copy_data_protection = copy_data_UROV;
                    break;
                  }
                case ID_CB_PG:
                  {
                    check_pickup_delay_protection = check_pickup_delay_CB;
                    copy_data_protection = copy_data_CB;
                    break;
                  }
                default:
                  {
                    //Інші неоднотипні вікна з вікнами парамтрування захистів
                    break;
                  }
                }
                
                if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                {
                  if (
                      (enter != 0) &&
                      (strcmp_mal((char *)eeprom_bs_settings_tbl.arPsw1, typed_password) == true)
                     )   
                  {
                    current_ekran.edition = 1;
                    switch (previous_level_in_current_level_menu[ID_DIALOG_PASSWORD])
                    {
                    case ID_RANK_PG:
                      {
                        rank_vk_enter_handler();
                        break;
                      }
                    case ID_CONFIG_PG:
                      {
                        conf_enter_handler();
                        break;
                      }
                    case ID_RANK_DO_DLG:
                    case ID_RANK_DI_DLG:
                    case ID_RANK_LED_DLG:
                    case ID_RANK_DF_DLG:
                    case ID_RANK_AN_REC_DLG: break;
                    case ID_TRANSFORMER_PG:
                      {
                        copy_data_Transformer(&edit_settings, &eeprom_prt_tbl);
                        break;
                      }
                    case ID_MODBUS_PG:
                      {
                        copy_data_Modbus(&edit_settings_1, &eeprom_bs_settings_tbl);
                        break;
                      }
                    case ID_NET_PG:
                      {
//                        copy_data_Net();
                        break;
                      }
                    case ID_CLOCK_PG:
                      {
                        unsigned char *label_to_time_array, *label_calibration;
                        if (copying_time == 0)
                        {
                          label_to_time_array = rtc_time;
                          label_calibration = &rtc_calibration;
                        }
                        else
                        {
                          label_to_time_array = rtc_time_copy;
                          label_calibration = &rtc_calibration_copy;
                        }             
                        for(unsigned int index = 0; index < 8; index++) rtc_time_edit[index] = *(label_to_time_array + index);
                        rtc_calibration_edit = *label_calibration;
                        break;
                      }
                    default:
                      {
                        (*copy_data_protection)(&edit_settings, &eeprom_prt_tbl);
                        break;
                      }
                    }
                  } 
                  else
                  {
                    switch (previous_level_in_current_level_menu[ID_DIALOG_PASSWORD])
                    {
                    case ID_RANK_PG:
                      {
                        rank_control_bits |= CHECKBOX_IS_UPDATED_MASK;
                        break;
                      }
                    default: break;
                    }
                  }
                  
                  WM_DeleteWindow(Dialog_password_FrameWin);
                  Dialog_password_FrameWin = WM_UNATTACHED;
                }
                else if (
                         (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                         (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2  )
                        )   
                {
                  if (current_ekran.current_level == ID_DIALOG_PASSWORD_LEVEL_2)
                  {
                    if (
                        (enter != 0) &&
                        (
                         (
                          ((command_from_menu & (1 << BIT_CLEAR_RESOURCE_COUNTER)) == 0) &&
                          (strcmp_mal((char *)eeprom_bs_settings_tbl.arPsw1, typed_password_level_2) == true)
                         )
                         ||  
                         (
                          ((command_from_menu & (1 << BIT_CLEAR_RESOURCE_COUNTER)) != 0) &&
                          (strcmp_mal((char *)eeprom_bs_settings_tbl.arPsw2, typed_password_level_2) == true)
                         )
                        )   
                       )   
                    {
                      if (
                          (command_from_menu != 0) ||
                          (set_new_Pick_up_Set == true)
                         )   
                      {
                        previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2];						                 
                        previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                      }
                      else
                      {
                        current_ekran.edition_level_2 = 1;
                        switch (previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2])
                        {
                        case ID_LCD_SETTINGS:
                          {
                            edit_settings_1.chSleepTmVal = eeprom_bs_settings_tbl.chSleepTmVal;
                            break;
                          }
                        default:
                          {
                            break;
                          }
                        }
                      }
                    } 
                    else
                    {
                      if (command_from_menu != 0) 
                      {
                        command_from_menu = 0;
                        current_modal_form = false;
                      }
                      
                      if (set_new_Pick_up_Set == true) 
                      {
                        set_new_Pick_up_Set = false;
                        current_modal_form = false;
                      }
                    }
                  }  
                  else if (
                           (current_ekran.current_level == ID_DIALOG_PASSWORD_OLD_1) ||
                           (current_ekran.current_level == ID_DIALOG_PASSWORD_OLD_2)
                          )
                  {
                    char *point_to_password = (current_ekran.current_level == ID_DIALOG_PASSWORD_OLD_1) ? eeprom_bs_settings_tbl.arPsw1 : eeprom_bs_settings_tbl.arPsw2;
                    if (
                        (enter != 0) &&
                        (strcmp_mal(point_to_password, typed_password_level_2) == true)
                       )   
                    {
                      typed_password_level_2[0] = '\0';
                      cursor_position_dp_level_2 = 0;
                    } 
                    else
                    {
                      //Cu diju vykonujemo shchob propustyty vkhid u vikno vvedennja novogo parolu
                      current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                      current_modal_form = false;
                    }
                  }  
                  else if (
                           (current_ekran.current_level == ID_DIALOG_PASSWORD_NEW_1) ||
                           (current_ekran.current_level == ID_DIALOG_PASSWORD_NEW_2)
                          )   
                  {
                    if (enter != 0)
                    {
                      if (current_ekran.current_level == ID_DIALOG_PASSWORD_NEW_1)
                      {
                        command_word_for_change_password |=  CHANGING_PASSWORD_1;
                        previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_1];						                 
                        previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_1] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                      }
                      else
                      {
                        if (typed_password_level_2[0] != '\0')
                        {
                          command_word_for_change_password |=  CHANGING_PASSWORD_2;
                          previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_2];						                 
                          previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_2] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                        }
                        else
                        {
                          command_word_for_change_password |=  ERROR_PASSWORD_2;
                        }
                      }
                    } 
                    else
                    {
                      current_modal_form = false;
                    }
                  }
                  
                  if ((command_word_for_change_password &  ERROR_PASSWORD_2) == 0)  
                  {
                    WM_DeleteWindow(Dialog_password_level_2_FrameWin);
                    Dialog_password_level_2_FrameWin = WM_UNATTACHED;
                  }
                  
                }
                else if (current_ekran.current_level == ID_DIALOG_CONFIRMATION)
                {
                  if (enter != 0)
                  {
                    int previous_level_in_current_level_menu_tmp = previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION];
                    switch (previous_level_in_current_level_menu_tmp)
                    {
                    case ID_RANK_PG:
                    case ID_CONFIG_PG:
                      {
                        copy_settings_from_buff(previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION]);
                        
                        //Komanda na zapys zminenykh nalashtuvan jaki idut do BO(r)
                        shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
                        
                        previous_level_in_current_level_menu[ID_DIALOG_ERROR] = previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION];
                        position_in_current_level_menu[ID_DIALOG_ERROR] = position_in_current_level_menu[ID_DIALOG_CONFIRMATION];
                        
                        previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_DIALOG_ERROR;
                        break;
                      }
                    default:
                      {
                        if (
                            ((previous_level_in_current_level_menu_tmp == ID_CLOCK_PG      )                                                             && (check_Date_Time_clock(rtc_time_edit, &rtc_calibration_edit) == true)) ||
                            ((previous_level_in_current_level_menu_tmp == ID_TRANSFORMER_PG)                                                             && (check_pickup_delay_Transformer(&edit_settings)            == true)) ||
                            ((previous_level_in_current_level_menu_tmp == ID_MODBUS_PG     )                                                             && (check_pickup_delay_Modbus(&edit_settings_1)               == true)) ||
//                            ((previous_level_in_current_level_menu_tmp == ID_NET_PG        )                                                             && (check_pickup_delay_Net(&edit_settings_1)                  == true)) ||
                            ((previous_level_in_current_level_menu_tmp >= ID_DZ_PG         ) && (previous_level_in_current_level_menu_tmp <= ID_CB_PG  ) && ((*check_pickup_delay_protection)(&edit_settings)          == true))
                           )   
                        {
                          if (previous_level_in_current_level_menu_tmp == ID_CLOCK_PG)
                          {
                            _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT);
                            
                            if (rtc_calibration != rtc_calibration_edit)
                            {
                              _SET_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT);
                            }
                          }
                          else if (previous_level_in_current_level_menu_tmp == ID_TRANSFORMER_PG)
                          {
                            copy_data_Transformer(&eeprom_prt_tbl, &edit_settings);
                            
                            //Komanda na zapys zminenykh nalashtuvan jaki idut do BO(r)
                            shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
                          }
                          else if (previous_level_in_current_level_menu_tmp == ID_MODBUS_PG)
                          {
                            unsigned int need_recof = false;
                            if (
                                (edit_settings_1.chSpeed       != eeprom_bs_settings_tbl.chSpeed      ) ||
                                (edit_settings_1.chParityCheck != eeprom_bs_settings_tbl.chParityCheck) ||
                                (edit_settings_1.chAmtStopBit  != eeprom_bs_settings_tbl.chAmtStopBit )
                               )   
                            {
                              need_recof = true;
                            }
                            copy_data_Modbus(&eeprom_bs_settings_tbl, &edit_settings_1);
                            
                            //Vystavljaemo komandu pro perekonfiguraciju RS-485
                            if (need_recof == true) ChangeConfRS485(eeprom_bs_settings_tbl.chSpeed, eeprom_bs_settings_tbl.chParityCheck, eeprom_bs_settings_tbl.chAmtStopBit);


                            //Komanda na zapys zminenykh nalashtuvan jaki tilky dlja BS
                            _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
                          }
                          else if (previous_level_in_current_level_menu_tmp == ID_NET_PG)
                          {
//                            copy_data_Net();
                            
                            //Komanda na zapys zminenykh nalashtuvan jaki tilky dlja BS
                            _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
                          }
                          else
                          {
                            (*copy_data_protection)(&eeprom_prt_tbl, &edit_settings);
                            
                            //Komanda na zapys zminenykh nalashtuvan
                            shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
                          }
                          current_ekran.edition = 0;
                        }
                        else
                        {
                          /*
                          Переходимо на відображення вікна про помилкові дані
                             
                          Це робимо таким чином, щоб, небовби, повернення з діалогового вікна підвердження
                          перейшло у діалогове вікно помилки, а при поверненні з діалогового вікна помилки ми б 
                          повернулися у те вікно ,яке викликало вікно підтвердження операції
                          */
                          previous_level_in_current_level_menu[ID_DIALOG_ERROR] = previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION];
                          position_in_current_level_menu[ID_DIALOG_ERROR] = position_in_current_level_menu[ID_DIALOG_CONFIRMATION];
                              
                          previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = ID_DIALOG_ERROR;
                        }
                        break;
                      }
                    }
                  }
                  else if (esc != 0) 
                  {
                    switch (previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION])
                    {
                    case ID_RANK_PG:
                    case ID_CONFIG_PG:
                      {
                        current_ekran.edition = 1;
                        break;
                      }
                    default:
                      {
                        current_ekran.edition = 0;
                        break;
                      }
                    }
                  }
                  
                  WM_DeleteWindow(Dialog_confirmation_FrameWin);
                  Dialog_confirmation_FrameWin = WM_UNATTACHED;
                }
                else if (current_ekran.current_level == ID_DIALOG_CONFIRMATION_LEVEL_2)
                {
                  if (min_settings != false)
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Minimalni nalashtuvannja dlja zakhystiv"
                      shbsRQChangeCfgTablesState |= 1<< BS_RQ_SET_MIN_CFG_TBL_BIT;
                    }
                    min_settings = false;
                    current_modal_form = false;
                  }
                  else if (min_settings_1 != false)
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Minimalni dodatkovi nalashtuvannja"
                      make_min_settings_1(&eeprom_bs_settings_tbl);
                      ChangeConfRS485(eeprom_bs_settings_tbl.chSpeed, eeprom_bs_settings_tbl.chParityCheck, eeprom_bs_settings_tbl.chAmtStopBit);

                      //Komanda na zapys zminenykh nalashtuvan jaki tilky dlja BS
                      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
                    }
                    min_settings_1 = false;
                    current_modal_form = false;
                  }
                  else if (command_from_menu & (1 << BIT_CLEAR_ACTUATED_FUNCTIONS))
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Ochystyty spracjovani funkciji"
                    }
                    command_from_menu = 0;
                    current_modal_form = false;
                  }
                  else if (command_from_menu & (1 << BIT_CLEAR_AR))
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Ochystra analogovogo rejestratora"
                    }
                    command_from_menu = 0;
                    current_modal_form = false;
                  }
                  else if (command_from_menu & (1 << BIT_CLEAR_DR))
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Ochystra dyskretnogo rejestratora"
                    }
                    command_from_menu = 0;
                    current_modal_form = false;
                  }
                  else if (command_from_menu & (1 << BIT_CLEAR_RPP))
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Ochystra rejestratora programnykh podij"
                    }
                    command_from_menu = 0;
                    current_modal_form = false;
                  }
                  else if (command_from_menu & (1 << BIT_CLEAR_RESOURCE_COUNTER))
                  {
                    if (enter != 0)
                    {
                      //Podaty komandu na actyvaciju komandy "Skydannja resursu vymykacha"
                      
#define SIZE_TMP_ARRAY ((RESERV_MAX_F_CMD_ONB >> 5) + 1)
                      unsigned long tmp_array[SIZE_TMP_ARRAY];
                      for (unsigned int i = 0; i < SIZE_TMP_ARRAY; i++) tmp_array[i] = 0;
#undef SIZE_TMP_ARRAY
                      _SET_BIT(tmp_array, RESET_HCB_MNU_CMD_ONB);
                      long rez = SetCmdHVPS((void*)&tmp_array, 1);
                      if (rez == 3)
                      {
                        current_modal_form = false;
                      }
                      else
                      {
                        Unreliable_error_level_2_title.ptitle[0] = TITLE_UNRELIABLE_ERROR_CMD_UKR;
                        Unreliable_error_level_2_title.ptitle[1] = TITLE_UNRELIABLE_ERROR_CMD_RUS;
                        Unreliable_error_level_2_title.ptitle[2] = TITLE_UNRELIABLE_ERROR_CMD_ENG;
                        
                        if (rez == 2)
                        {
                          Unreliable_error_level_2_message.ptitle[0] = UNRELIABLE_WINDOW_INFO_1_MSG_UKR;
                          Unreliable_error_level_2_message.ptitle[1] = UNRELIABLE_WINDOW_INFO_1_MSG_RUS;
                          Unreliable_error_level_2_message.ptitle[2] = UNRELIABLE_WINDOW_INFO_1_MSG_ENG;
                        }
                        else
                        {
                          Unreliable_error_level_2_message.ptitle[0] = UNRELIABLE_WINDOW_INFO_2_MSG_UKR;
                          Unreliable_error_level_2_message.ptitle[1] = UNRELIABLE_WINDOW_INFO_2_MSG_RUS;
                          Unreliable_error_level_2_message.ptitle[2] = UNRELIABLE_WINDOW_INFO_2_MSG_ENG;
                     
                        }
                        
                        previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR_LEVEL_2] = previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2];						                 
                        previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = ID_UNRELIABLE_ERROR_LEVEL_2;


//                        if (WM_GetFocussedWindow() == hMenu_main)
//                        {
//                          current_ekran.current_level = previous_level_in_current_level_menu[ID_MAIN_MENU];
//                          current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
//                
//                          /*
//                          Завершальною операцією є зняття команди на перемальованування
//                          старого пункту меню і виставлення команди на обновлення нового 
//                          пункту меню
//                          */
//                          command_state &= (unsigned int)(~(1 << REDRAW));
//                          command_menu |= (1 << REWRITE_MENU);
//                        }                        
                      }
                    }
                    else
                    {
                      current_modal_form = false;
                    }

                    command_from_menu = 0;
                  }
                  else if(set_new_Pick_up_Set == true)
                  {
                    if (enter != 0)
                    {
                      eeprom_prt_tbl.PckpStpm_store_selection = edit_Pick_up_Set;

                      //Komanda na zapys zminenykh nalashtuvan jaki idut do BO(r)
                      shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
                    }

                    set_new_Pick_up_Set = false;
                    current_modal_form = false;
                  }
                  else if (command_word_for_change_password & (CHANGING_PASSWORD_1 | CHANGING_PASSWORD_2))
                  {
                    if (enter != 0)
                    {
                      char *point_to_password;
                      if (command_word_for_change_password & CHANGING_PASSWORD_1) 
                      {
                        point_to_password = eeprom_bs_settings_tbl.arPsw1;
                        command_word_for_change_password &= (unsigned int)(~CHANGING_PASSWORD_1);
                      }
                      else 
                      {
                        point_to_password = eeprom_bs_settings_tbl.arPsw2;
                        command_word_for_change_password &= (unsigned int)(~CHANGING_PASSWORD_2);
                      }

                      unsigned int index = 0;
                      while (
                             (typed_password_level_2[index] != '\0') &&
                             (index < (MAX_NUMBER_SYMBOLS_IN_PASSWORD + 1))  
                            )
                      {
                        *(point_to_password + index) = typed_password_level_2[index];
                        index++;
                      }
                      *(point_to_password + index) = '\0';


                      //Komanda na zapys zminenykh nalashtuvan jaki tilky dlja BS
                      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
                    }
                    
                    current_modal_form = false;
                  }
                  else if (previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] == ID_LCD_SETTINGS)
                  {
                    if (enter != 0)
                    {
                      if (check_pickup_delay_LCD_Settings(edit_settings_1.chSleepTmVal) == true)
                      {
                        eeprom_bs_settings_tbl.chSleepTmVal = edit_settings_1.chSleepTmVal;
                        current_ekran.edition_level_2 = 0;

                        //Komanda na zapys zminenykh nalashtuvan jaki tilky dlja BS
                        _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
                      }
                      else
                      {
                        /*
                        Переходимо на відображення вікна про помилкові дані
                           
                        Це робимо таким чином, щоб, небовби, повернення з діалогового вікна підвердження
                        перейшло у діалогове вікно помилки, а при поверненні з діалогового вікна помилки ми б 
                        повернулися у те вікно, яке викликало вікно підтвердження операції
                        */
                        previous_level_in_current_level_menu[ID_DIALOG_ERROR_LEVEL_2] = previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2];
                        previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = ID_DIALOG_ERROR_LEVEL_2;
                      }
                    }
                    else if (esc != 0)
                    {
                      current_ekran.edition_level_2 = 0;
                    }
                  }

                  WM_DeleteWindow(Dialog_confirmation_level_2_FrameWin);
                  Dialog_confirmation_level_2_FrameWin = WM_UNATTACHED;
                }
                else if (current_ekran.current_level == ID_DIALOG_ERROR)
                {
                  if (enter != 0)
                  {
                    switch (previous_level_in_current_level_menu[ID_DIALOG_ERROR])
                    {
                    case ID_RANK_PG:
                      {
                        if (checkAllRankVal()) {
                          //Повертаэмося у режим редагування із задіяними значеннями (якщо одразу натиснути кнопку ESC - відбудеться вихід із ранжування без запиту на збереження даних)
                          current_ekran.edition = 1;
                        } else {
                          //Повертаэмося у режим редагування із не задіяними значеннями (якщо одразу натиснути кнопку ESC - відбудеться вихід із ранжування з повторним запитом на збереження даних)
                          current_ekran.edition = 2;
                        }
                        break;
                      }
                    case ID_SETTINGS_PG:
                    case ID_COMM_PG:
                      {
                        //Для цьоговікна не потрібно використовувати режим редагування
                        current_ekran.edition = 0;
                      }
                    default:
                      {
                        //Повертаємося у режим редагування зі зміненими значеннями
                        current_ekran.edition = 2;
                        break;
                      }
                    }
                  } else if(esc != 0) {
                    current_ekran.edition = 0;
                  }
                  
                  WM_DeleteWindow(Dialog_error_FrameWin);
                  Dialog_error_FrameWin = WM_UNATTACHED;
                }
                else if (current_ekran.current_level == ID_DIALOG_ERROR_LEVEL_2)
                {
                  switch (previous_level_in_current_level_menu[ID_DIALOG_ERROR_LEVEL_2])
                  {
                  case ID_DIALOG_PASSWORD_NEW_2:
                    {
                      if (enter != 0)
                      {
                        //Nijakych dodatkovychdij ne vykonujemo
                      }
                      else if (esc != 0)
                      {
                        //Cu diju vykonujemo shchob propustyty vkhid u vikno vvedennja novogo parolu
                        current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                        current_modal_form = false;

                        if (Dialog_password_level_2_FrameWin != WM_UNATTACHED)
                        {
                          WM_DeleteWindow(Dialog_password_level_2_FrameWin);
                          Dialog_password_level_2_FrameWin = WM_UNATTACHED;
                        }
                      }
                      
                      break;
                    }
                  default:
                    {
                      if (enter != 0)
                      {
                        //Повертаємося у режим редагування зі зміненими значеннями
                        current_ekran.edition_level_2 = 2;
                      }
                      else if (esc != 0)
                      {
                        current_ekran.edition_level_2 = 0;
                        current_modal_form = false;
                      }
                      
                      break;
                    }
                  }

                  WM_DeleteWindow(Dialog_error_level_2_FrameWin);
                  Dialog_error_level_2_FrameWin = WM_UNATTACHED;
                }
                else if (current_ekran.current_level == ID_UNRELIABLE_ERROR)
                {
                  
                  WM_DeleteWindow(Unreliable_error_FrameWin);
                  Unreliable_error_FrameWin = WM_UNATTACHED;
                }
                else if (current_ekran.current_level == ID_UNRELIABLE_ERROR_LEVEL_2)
                {
                  current_modal_form = false;
                  WM_DeleteWindow(Unreliable_error_level_2_FrameWin);
                  Unreliable_error_level_2_FrameWin = WM_UNATTACHED;
                }

                if ((command_word_for_change_password &  ERROR_PASSWORD_2) == 0)
                {
                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                }
                else
                {
                  command_word_for_change_password &= (unsigned int)(~ERROR_PASSWORD_2);
                  previous_level_in_current_level_menu[ID_DIALOG_ERROR_LEVEL_2] = current_ekran.current_level;
                  current_ekran.current_level = ID_DIALOG_ERROR_LEVEL_2;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  cursor_position_dp = 0;
                else if (
                         (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                         (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                        ) 
                  cursor_position_dp_level_2 = 0;
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  cursor_position_dp = strlen_mal(typed_password);
                else if (
                         (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                         (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                        ) 
                  cursor_position_dp_level_2 = strlen_mal(typed_password_level_2);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DEL) != 0)
            {
              //Зафіксована натиснута кнопка DEL
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DEL);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DEL не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (
                    (current_ekran.current_level >= ID_DIALOG_PASSWORD) &&
                    (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                   ) 
                {
                  char *point_po_typed_password;
                  int *point_to_cursor_position_dp;
                  if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  {
                    point_po_typed_password = typed_password;
                    point_to_cursor_position_dp = &cursor_position_dp;
                  }
                  else if (
                           (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                           (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                          ) 
                  {
                    point_po_typed_password = typed_password_level_2;
                    point_to_cursor_position_dp = &cursor_position_dp_level_2;
                  }

                  if (*point_to_cursor_position_dp < strlen_mal(point_po_typed_password))
                  {
                    strdel_mal(point_po_typed_password, *point_to_cursor_position_dp, 1);
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
#ifdef KBD_2016
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_BACK_SPACE) != 0)
#else
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
#endif
            {
              //Зафіксована натиснута кнопка TAB(має бути насправді Backspace)
#ifdef KBD_2016
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_BACK_SPACE);
#else
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
#endif
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAP(має бути насправді Backspace) не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.current_level >= ID_DIALOG_PASSWORD) &&
                    (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                   ) 
                {
                  char *point_po_typed_password;
                  int *point_to_cursor_position_dp;
                  if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  {
                    point_po_typed_password = typed_password;
                    point_to_cursor_position_dp = &cursor_position_dp;
                  }
                  else if (
                           (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                           (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                          ) 
                  {
                    point_po_typed_password = typed_password_level_2;
                    point_to_cursor_position_dp = &cursor_position_dp_level_2;
                  }

                  if (*point_to_cursor_position_dp > 0)
                  {
                    (*point_to_cursor_position_dp)--;
                    strdel_mal(point_po_typed_password, *point_to_cursor_position_dp, 1);
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.current_level >= ID_DIALOG_PASSWORD) &&
                    (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                   ) 
                {
                  char *point_po_typed_password;
                  int *point_to_cursor_position_dp;
                  if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  {
                    point_po_typed_password = typed_password;
                    point_to_cursor_position_dp = &cursor_position_dp;
                  }
                  else if (
                           (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                           (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                          ) 
                  {
                    point_po_typed_password = typed_password_level_2;
                    point_to_cursor_position_dp = &cursor_position_dp_level_2;
                  }

                  if (*point_to_cursor_position_dp < strlen_mal(point_po_typed_password)) (*point_to_cursor_position_dp)++;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                int *point_to_cursor_position_dp;
                if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                {
                  point_to_cursor_position_dp = &cursor_position_dp;
                }
                else if (
                         (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                         (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                        ) 
                {
                  point_to_cursor_position_dp = &cursor_position_dp_level_2;
                }
                if (*point_to_cursor_position_dp > 0) (*point_to_cursor_position_dp)--;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Натиснута тільки одна кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.current_level >= ID_DIALOG_PASSWORD) &&
                    (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                   ) 
                {
                  char *point_po_typed_password;
                  int *point_to_cursor_position_dp;
                  if (current_ekran.current_level == ID_DIALOG_PASSWORD)
                  {
                    point_po_typed_password = typed_password;
                    point_to_cursor_position_dp = &cursor_position_dp;
                  }
                  else if (
                           (current_ekran.current_level >= ID_DIALOG_PASSWORD_LEVEL_2) &&
                           (current_ekran.current_level <= ID_DIALOG_PASSWORD_NEW_2)
                          ) 
                  {
                    point_po_typed_password = typed_password_level_2;
                    point_to_cursor_position_dp = &cursor_position_dp_level_2;
                  }

                  char string_tmp[2] = {'\0', '\0'};
                  if      (pressed_0 != 0) string_tmp[0] = '0';
                  else if (pressed_1 != 0) string_tmp[0] = '1';
                  else if (pressed_2 != 0) string_tmp[0] = '2';
                  else if (pressed_3 != 0) string_tmp[0] = '3';
                  else if (pressed_4 != 0) string_tmp[0] = '4';
                  else if (pressed_5 != 0) string_tmp[0] = '5';
                  else if (pressed_6 != 0) string_tmp[0] = '6';
                  else if (pressed_7 != 0) string_tmp[0] = '7';
                  else if (pressed_8 != 0) string_tmp[0] = '8';
                  else if (pressed_9 != 0) string_tmp[0] = '9';
                  if (strlen_mal(point_po_typed_password) < MAX_NUMBER_SYMBOLS_IN_PASSWORD)
                  {
                    strinsert_mal(point_po_typed_password, *point_to_cursor_position_dp, string_tmp);
                    (*point_to_cursor_position_dp)++;
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
               command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //redraw language dialog
            win_handler();
          }
          
          break;
        }
      case ID_DZ_PG:
      case ID_MTZ_PG:
      case ID_UMIN_PG:
      case ID_UMAX_PG:
      case ID_TZNP_PG:
      case ID_ZOP_PG:
      case ID_APV_PG:
      case ID_UROV_PG:
      case ID_CB_PG:
        {
          WM_HWIN *Protection_Pickup_v, *Protection_Delay_v;
          WM_HWIN *Panel_Win;
          int *point_to_position_in_level_1_menu, *point_to_select_group, max_number[MAX_PAGES_PROTECTION_SDC];
          unsigned int max_kilkist_stupeniv_protection;
          const unsigned short int *nalashtuvannja_protection;
          
          const TITLE* (*Protection_control_info)(unsigned int, int*);
          unsigned char* (*Protection_pointer_to_state)(unsigned int number, CfgTblDsc*);
          void (*Protection_change_state_callback)(unsigned int, CfgTblDsc*);
          void (*protection_pickup_info)(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
          void (*copy_data_protection)(CfgTblDsc*, CfgTblDsc*);

          unsigned int groups = AMOUNT_SERIES_PPSPM_SETTINGS;
          
          unsigned int error_data = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
          
          switch (current_ekran.current_level)
          {
          case ID_DZ_PG:
            {
              Panel_Win = &DZ_FrameWin;
              
              point_to_position_in_level_1_menu = position_in_level_1_menu_DZ;
              point_to_select_group = &DZ_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_DZ;
              max_number[1] = MAX_NUMBER_DELAY_DZ;
              max_number[2] = MAX_NUMBER_CTRL_DZ;

              Protection_Pickup_v = DZ_Pickup_v;
              protection_pickup_info = DZ_pickup_info;
              Protection_Delay_v = DZ_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_DZ + 1;
              nalashtuvannja_protection = nalashtuvannja_DZ;
              
              Protection_control_info = DZ_control_info;
              Protection_pointer_to_state = DZ_pointer_to_state;
              Protection_change_state_callback = DZ_change_state_callback;
              copy_data_protection = copy_data_DZ;
      
              break;
            }
          case ID_MTZ_PG:
            {
              Panel_Win = &MTZ_FrameWin;
              
              point_to_position_in_level_1_menu = position_in_level_1_menu_MTZ;
              point_to_select_group = &MTZ_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_MTZ;
              max_number[1] = MAX_NUMBER_DELAY_MTZ;
              max_number[2] = MAX_NUMBER_CTRL_MTZ;

              Protection_Pickup_v = MTZ_Pickup_v;
              protection_pickup_info = MTZ_pickup_info;
              Protection_Delay_v = MTZ_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_MTZ + 1;
              nalashtuvannja_protection = nalashtuvannja_MTZ;
              
              Protection_control_info = MTZ_control_info;
              Protection_pointer_to_state = MTZ_pointer_to_state;
              Protection_change_state_callback = MTZ_change_state_callback;
              copy_data_protection = copy_data_MTZ;
      
              break;
            }
          case ID_UMIN_PG:
            {
              Panel_Win = &Umin_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_Umin;
              point_to_select_group = &Umin_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_UMIN;
              max_number[1] = MAX_NUMBER_DELAY_UMIN;
              max_number[2] = MAX_NUMBER_CTRL_UMIN;

              Protection_Pickup_v = Umin_Pickup_v;
              protection_pickup_info = Umin_pickup_info;
              Protection_Delay_v = Umin_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_UMIN + 1;
              nalashtuvannja_protection = nalashtuvannja_Umin;
      
              Protection_control_info = Umin_control_info;
              Protection_pointer_to_state = Umin_pointer_to_state;
              Protection_change_state_callback = Umin_change_state_callback;
              copy_data_protection = copy_data_Umin;
              
              break;
            }
          case ID_UMAX_PG:
            {
              Panel_Win = &Umax_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_Umax;
              point_to_select_group = &Umax_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_UMAX;
              max_number[1] = MAX_NUMBER_DELAY_UMAX;
              max_number[2] = MAX_NUMBER_CTRL_UMAX;

              Protection_Pickup_v = Umax_Pickup_v;
              protection_pickup_info = Umax_pickup_info;
              Protection_Delay_v = Umax_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_UMAX + 1;
              nalashtuvannja_protection = nalashtuvannja_Umax;
      
              Protection_control_info = Umax_control_info;
              Protection_pointer_to_state = Umax_pointer_to_state;
              Protection_change_state_callback = Umax_change_state_callback;
              copy_data_protection = copy_data_Umax;
              
              break;
            }
          case ID_TZNP_PG:
            {
              Panel_Win = &TZNP_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_TZNP;
              point_to_select_group = &TZNP_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_TZNP;
              max_number[1] = MAX_NUMBER_DELAY_TZNP;
              max_number[2] = MAX_NUMBER_CTRL_TZNP;

              Protection_Pickup_v = TZNP_Pickup_v;
              protection_pickup_info = TZNP_pickup_info;
              Protection_Delay_v = TZNP_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_TZNP + 1;
              nalashtuvannja_protection = nalashtuvannja_TZNP;
      
              Protection_control_info = TZNP_control_info;
              Protection_pointer_to_state = TZNP_pointer_to_state;
              Protection_change_state_callback = TZNP_change_state_callback;
              copy_data_protection = copy_data_TZNP;
              
              break;
            }
          case ID_ZOP_PG:
            {
              Panel_Win = &ZOP_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_ZOP;
              point_to_select_group = &ZOP_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_ZOP;
              max_number[1] = MAX_NUMBER_DELAY_ZOP;
              max_number[2] = MAX_NUMBER_CTRL_ZOP;

              Protection_Pickup_v = ZOP_Pickup_v;
              protection_pickup_info = ZOP_pickup_info;
              Protection_Delay_v = ZOP_Delay_v;
              
              max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_ZOP + 1;
              nalashtuvannja_protection = nalashtuvannja_ZOP;
      
              Protection_control_info = ZOP_control_info;
              Protection_pointer_to_state = ZOP_pointer_to_state;
              Protection_change_state_callback = ZOP_change_state_callback;
              copy_data_protection = copy_data_ZOP;
              
              break;
            }
          case ID_APV_PG:
            {
              Panel_Win = &APV_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_APV;
              point_to_select_group = &APV_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_APV;
              max_number[1] = MAX_NUMBER_DELAY_APV;
              max_number[2] = MAX_NUMBER_CTRL_APV;

              Protection_Pickup_v = APV_Pickup_v;
              protection_pickup_info = APV_pickup_info;
              Protection_Delay_v = APV_Delay_v;
              
              max_kilkist_stupeniv_protection = /*MAX_KILKIST_STUPENIV_APV + 1*/8;
              nalashtuvannja_protection = nalashtuvannja_APV;
      
              Protection_control_info = APV_control_info;
              Protection_pointer_to_state = APV_pointer_to_state;
              Protection_change_state_callback = APV_change_state_callback;
              copy_data_protection = copy_data_APV;
              
              break;
            }
          case ID_UROV_PG:
            {
              Panel_Win = &UROV_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_UROV;
              point_to_select_group = &UROV_select_group;
              max_number[0] = MAX_NUMBER_PICKUP_UROV;
              max_number[1] = MAX_NUMBER_DELAY_UROV;
              max_number[2] = MAX_NUMBER_CTRL_UROV;

              Protection_Pickup_v = UROV_Pickup_v;
              protection_pickup_info = UROV_pickup_info;
              Protection_Delay_v = UROV_Delay_v;
              
              max_kilkist_stupeniv_protection = /*MAX_KILKIST_STUPENIV_UROV + 1*/8;
              nalashtuvannja_protection = nalashtuvannja_UROV;
      
              Protection_control_info = UROV_control_info;
              Protection_pointer_to_state = UROV_pointer_to_state;
              Protection_change_state_callback = UROV_change_state_callback;
              copy_data_protection = copy_data_UROV;
              
              break;
            }
          case ID_CB_PG:
            {
              Panel_Win = &CB_FrameWin;

              point_to_position_in_level_1_menu = position_in_level_1_menu_CB;
              point_to_select_group = &one_group;
              max_number[0] = MAX_NUMBER_PICKUP_CB;
              max_number[1] = MAX_NUMBER_DELAY_CB;
              max_number[2] = MAX_NUMBER_CTRL_CB;

              Protection_Pickup_v = CB_Pickup_v;
              protection_pickup_info = CB_pickup_info;
              Protection_Delay_v = CB_Delay_v;
              
              max_kilkist_stupeniv_protection = 1;
              nalashtuvannja_protection = nalashtuvannja_CB;
      
              Protection_control_info = CB_control_info;
              Protection_pointer_to_state = CB_pointer_to_state;
              Protection_change_state_callback = CB_change_state_callback;
              copy_data_protection = copy_data_CB;
              
              groups = 1;
              
              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (*Panel_Win == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  //Виходимо з панелі захисту
                  WM_DeleteWindow(*Panel_Win);
                  *Panel_Win = WM_UNATTACHED;

                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                }
                else
                {
                  //Виходимо з режимму редагування
                  current_ekran.edition = 0;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                int max_position;
                if (
                    (current_ekran.current_level != ID_DZ_PG) ||
                    (current_ekran.index_position != 1)  
                   )
                {
                  max_position = max_number[current_ekran.index_position];
                }
                else
                {
                  if (WM_IsVisible(DZ_SubPages_delay[0]))
                  {
                     max_position = MAX_NUMBER_DELAY_DZ;
                  }
                  else
                  {
                     max_position = MAX_NUMBER_DELAY_DZ_G;
                  }
                }
                int index_position_1_tmp = current_ekran.index_position_1;
                if (++index_position_1_tmp >= max_position) 
                {
                  index_position_1_tmp = 0;
                }
                current_ekran.index_position_1 = index_position_1_tmp;
                
                if (
                    (current_ekran.current_level != ID_DZ_PG) ||
                    (current_ekran.index_position != 1)  
                   )
                {
                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                }
                else
                {
                  position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])] = current_ekran.index_position_1;
                }
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  if (error_data == 0)
                  {
                    //Dani z EEPROM dostovirni
                    if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                    {
                      //Переходимо на запит паролю
                      position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                      previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = current_ekran.current_level;
                    
                      current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                      //Обнуляємо введений пароль
                      typed_password[0] = '\0';
                      cursor_position_dp = 0;
                    }
                    else
                    {
                      //Переходимо в режим редагування 
                      current_ekran.edition = 1;
                      (*copy_data_protection)(&edit_settings, &eeprom_prt_tbl);
                    }
                  }
                }
                else if (current_ekran.edition == 1)
                {
                  /*
                  Дані не змінювалися, тому виходимо з режиму редагування без запиту
                  на підтвердження змін
                  */
                  current_ekran.edition = 0;
                }
                else
                {
                  /*
                  Дані змінювалися, тому формуємо запит на підтердження змін
                  */
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = current_ekran.current_level;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                }
                
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = 0;
                
                if (
                    (current_ekran.current_level != ID_DZ_PG) ||
                    (current_ekran.index_position != 1)  
                   )
                {
                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                }
                else
                {
                  position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])] = current_ekran.index_position_1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                int max_position;
                if (
                    (current_ekran.current_level != ID_DZ_PG) ||
                    (current_ekran.index_position != 1)  
                   )
                {
                  max_position = max_number[current_ekran.index_position];
                }
                else
                {
                  if (WM_IsVisible(DZ_SubPages_delay[0]))
                  {
                     max_position = MAX_NUMBER_DELAY_DZ;
                  }
                  else
                  {
                     max_position = MAX_NUMBER_DELAY_DZ_G;
                  }
                }
                current_ekran.index_position_1 = max_position - 1;
                
                if (
                    (current_ekran.current_level != ID_DZ_PG) ||
                    (current_ekran.index_position != 1)  
                   )
                {
                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                }
                else
                {
                  position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])] = current_ekran.index_position_1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_CTRL) != 0)
              {
                /*
                Поряд з кнопкою LEFT утримується кнопка CTRL
                */
                unsigned int key_pressed_tmp[RANG_KEY] = {key_pressed[0], key_pressed[1]};
                _CLEAR_KEY_BIT(key_pressed_tmp, VK_OFFSET_CTRL);
                if (
                    (key_pressed_tmp[0] == 0) &&
                    (key_pressed_tmp[1] == 0)
                   )
                {
                  /*
                  Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                  біту, який відповідає за CTRL у основному масиві
                  */
                  _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_CTRL);
                  executed_action_after_press_ctrl = true;

                  /*
                  Виконуємо зміну вкладок Уставки-Витримки-Управління
                  */
                  if (--current_ekran.index_position < 0) 
                    current_ekran.index_position = MAX_PAGES_PROTECTION_SDC - 1;
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;

                  if (
                      (current_ekran.current_level != ID_DZ_PG) ||
                      (current_ekran.index_position != 1)  
                     )
                  {
                    current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);
                    if (current_ekran.current_level != ID_CB_PG)
                    {
                      if(*point_to_select_group >= AMOUNT_SERIES_PPSPM_SETTINGS) *point_to_select_group = AMOUNT_SERIES_PPSPM_SETTINGS - 1;
                    }
                  }
                  else
                  {
                    current_ekran.index_position_1 = position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])];
                  }
                }
              }
              else if (
                       (key_pressed[0] == 0) &&
                       (key_pressed[1] == 0)
                      )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0)
                {
                  //Переміщення вліво у вибраному елементі
                  if (current_ekran.edition != 0)
                  {
                    EDIT_AddKey(*(Protection_Pickup_v + current_ekran.index_position_1), GUI_KEY_LEFT);
                    start_gui_exec = 1;
                  }
                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
                else if (current_ekran.index_position == 1)
                {
                  //Переміщення вліво у вибраному елементі
                  if (current_ekran.edition != 0)
                  {
                    unsigned int index_shift;
                    if ((current_ekran.current_level != ID_DZ_PG) || WM_IsVisible(DZ_SubPages_delay[0])) index_shift = 0;
                    else index_shift = MAX_NUMBER_DELAY_DZ;
                    
                    EDIT_AddKey(*(Protection_Delay_v + index_shift + current_ekran.index_position_1), GUI_KEY_LEFT);
                    start_gui_exec = 1;
                  }
                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
                else
                {
                  //Зміна вибраного елементув ідбувається у влкадці управління
                  int index_position_1_tmp = current_ekran.index_position_1;
                  unsigned int gaps_before = 0;
                  calc_number_gaps_ctrl_protection(&gaps_before, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                  index_position_1_tmp = (index_position_1_tmp + gaps_before) ^ 0x1;
                  index_position_1_tmp -= gaps_before;
                  unsigned int gaps_after = 0;
                  calc_number_gaps_ctrl_protection(&gaps_after, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                  if (gaps_after == gaps_before)
                    current_ekran.index_position_1 = index_position_1_tmp;
                  
                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_CTRL) != 0)
              {
                /*
                Поряд з кнопкою RIGHT утримується кнопка CTRL
                */
                unsigned int key_pressed_tmp[RANG_KEY] = {key_pressed[0], key_pressed[1]};
                _CLEAR_KEY_BIT(key_pressed_tmp, VK_OFFSET_CTRL);
                if (
                    (key_pressed_tmp[0] == 0) &&
                    (key_pressed_tmp[1] == 0)
                   )
                {
                  /*
                  Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                  біту, який відповідає за CTRL у основному масиві
                  */
                  _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_CTRL);
                  executed_action_after_press_ctrl = true;

                  /*
                  Виконуємо зміну вкладок Уставки-Витримки-Управління
                  */
                  if (++current_ekran.index_position >= MAX_PAGES_PROTECTION_SDC) 
                    current_ekran.index_position = 0;
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;

                  if (
                      (current_ekran.current_level != ID_DZ_PG) ||
                      (current_ekran.index_position != 1)  
                     )
                  {
                    current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);
                    if (current_ekran.current_level != ID_CB_PG)
                    {
                      if(*point_to_select_group >= AMOUNT_SERIES_PPSPM_SETTINGS) *point_to_select_group = AMOUNT_SERIES_PPSPM_SETTINGS - 1;
                    }
                  }
                  else
                  {
                    current_ekran.index_position_1 = position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])];
                  }
                }
              }
              else if (
                       (key_pressed[0] == 0) &&
                       (key_pressed[1] == 0)
                      )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0)
                {
                  //Переміщення вправо у вибраному елементі
                  if (current_ekran.edition != 0)
                  {
                    if(
                       (Protection_Pickup_v != CB_Pickup_v) ||
                       (
                        (current_ekran.index_position_1 != 1) &&
                        (current_ekran.index_position_1 <  4)
                       ) ||
                       (EDIT_GetCursorCharPos(*(Protection_Pickup_v + current_ekran.index_position_1)) != 4)  
                      )
                    {
                      EDIT_AddKey(*(Protection_Pickup_v + current_ekran.index_position_1), GUI_KEY_RIGHT);
                      start_gui_exec = 1;
                    }
                  }
                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
                else if (current_ekran.index_position == 1)
                {
                  //Переміщення вправо у вибраному елементі
                  if (current_ekran.edition != 0)
                  {
                    unsigned int index_shift;
                    if ((current_ekran.current_level != ID_DZ_PG) || WM_IsVisible(DZ_SubPages_delay[0])) index_shift = 0;
                    else index_shift = MAX_NUMBER_DELAY_DZ;
                    
                    EDIT_AddKey(*(Protection_Delay_v + index_shift + current_ekran.index_position_1), GUI_KEY_RIGHT);
                    start_gui_exec = 1;
                  }
                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
                else
                {
                  //Зміна вибраного елементу відбувається у влкадці управління
                  int index_position_1_tmp = current_ekran.index_position_1;
                  unsigned int gaps_before = 0;
                  calc_number_gaps_ctrl_protection(&gaps_before, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                  index_position_1_tmp = (index_position_1_tmp + gaps_before) ^ 0x1;
                  index_position_1_tmp -= gaps_before;
                  unsigned int gaps_after = 0;
                  calc_number_gaps_ctrl_protection(&gaps_after, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                  if (gaps_after == gaps_before)
                    current_ekran.index_position_1 = index_position_1_tmp;

                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP   ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "UP" або"Page Up"
              unsigned int up, pg_up;
              if (up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
                
              if (pg_up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if ((up + pg_up) == 1)
              {
                if (
                    (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_CTRL) != 0) &&
                    (up == 1) &&
                    (groups > 1)  
                   )   
                {
                  /*
                  Поряд з кнопкою UP утримується кнопка CTRL
                  */
                  unsigned int key_pressed_tmp[RANG_KEY] = {key_pressed[0], key_pressed[1]};
                  _CLEAR_KEY_BIT(key_pressed_tmp, VK_OFFSET_CTRL);
                  if (
                      (key_pressed_tmp[0] == 0) &&
                      (key_pressed_tmp[1] == 0)
                    )
                  {
                    /*
                    Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                    біту, який відповідає за CTRL у основному масиві
                    */
                    _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_CTRL);
                    executed_action_after_press_ctrl = true;

                    /*
                    Виконуємо зміну вкладок груп уставок
                    */
                    if (
                        (current_ekran.index_position == 0) ||
                        (current_ekran.index_position == 1)
                       )   
                    {
                      if ((current_ekran.current_level != ID_DZ_PG) || (current_ekran.index_position != 1))
                      {
                        if (current_ekran.current_level != ID_CB_PG)
                        {
                          if (--(*point_to_select_group) < 0) *point_to_select_group = AMOUNT_SERIES_PPSPM_SETTINGS - 1;
                        }
                      }
                      else
                      {
                        position_in_level_1_menu_DZ_delay[(*point_to_select_group) == AMOUNT_SERIES_PPSPM_SETTINGS] = current_ekran.index_position_1;
                        if (--(*point_to_select_group) < 0) *point_to_select_group = AMOUNT_SERIES_PPSPM_SETTINGS;
                        current_ekran.index_position_1 = position_in_level_1_menu_DZ_delay[(*point_to_select_group) == AMOUNT_SERIES_PPSPM_SETTINGS];
                      }
                    }
                  }
                }
                else if (
                         (key_pressed[0] == 0) &&
                         (key_pressed[1] == 0)
                        )  
                {
                  /*
                  Поряд з кнопкою UP не була натиснута інша кнопка
                  Можна виконувати дії
                  */
                  if (
                      (current_ekran.index_position == 0) ||
                      (current_ekran.index_position == 1)
                     )   
                  {
                    //Зміна вибраного елементу відбувається у влкадці уставок або витримок
                    
                    int index_position_1_tmp = current_ekran.index_position_1;
                    if (up != 0) index_position_1_tmp -= 1;
                    else index_position_1_tmp -= 5;
                    
                    if (index_position_1_tmp < 0) index_position_1_tmp = 0;
                    current_ekran.index_position_1 = index_position_1_tmp;
                  }
                  else
                  {
                    //Зміна вибраного елементу відбувається у влкадці управління
                    int index_position_1_tmp = current_ekran.index_position_1;
                    unsigned int gaps_before = 0;
                    calc_number_gaps_ctrl_protection(&gaps_before, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    int position_in_matrix = index_position_1_tmp + gaps_before;
                    unsigned int col = (position_in_matrix & 0x1);

                    if (up != 0) index_position_1_tmp -= 2;
                    else index_position_1_tmp -= 10;

                    unsigned int gaps_tmp = 0;
                    calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    for (int i = 0; i < (int)(gaps_before - gaps_tmp); i++) 
                    {
                      if (col == 0) index_position_1_tmp++;
                      else index_position_1_tmp--;

                      calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    }

                    if (index_position_1_tmp < 0)
                    {
                      index_position_1_tmp = 0;
                      
                      calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                      while (((index_position_1_tmp + gaps_tmp) & 0x1) != col) 
                      {
                        index_position_1_tmp++;
                        calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                      }
                    }
                    current_ekran.index_position_1 = index_position_1_tmp;
                  }

                  if (
                      (current_ekran.current_level != ID_DZ_PG) ||
                      (current_ekran.index_position != 1)  
                     )
                  {
                    *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                  }
                  else
                  {
                    position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])] = current_ekran.index_position_1;
                  }
                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "DOWN" або"Page Down"
              unsigned int down, pg_down;
              if (down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
                
              if (pg_down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if ((down + pg_down) == 1)
              {
                if (
                    (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_CTRL) != 0) &&
                    (down == 1) &&
                    (groups > 1)  
                   )   
                {
                  /*
                  Поряд з кнопкою DOWN утримується кнопка CTRL
                  */
                  unsigned int key_pressed_tmp[RANG_KEY] = {key_pressed[0], key_pressed[1]};
                  _CLEAR_KEY_BIT(key_pressed_tmp, VK_OFFSET_CTRL);
                  if (
                      (key_pressed_tmp[0] == 0) &&
                      (key_pressed_tmp[1] == 0)
                    )
                  {
                    /*
                    Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                    біту, який відповідає за CTRL у основному масиві
                    */
                    _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_CTRL);
                    executed_action_after_press_ctrl = true;

                    if (
                        (current_ekran.index_position == 0) ||
                        (current_ekran.index_position == 1)
                       )   
                    {
                      /*
                      Виконуємо зміну вкладок груп уставок
                      */
                      if ((current_ekran.current_level != ID_DZ_PG) || (current_ekran.index_position != 1))
                      {
                        if (current_ekran.current_level != ID_CB_PG)
                        {
                          if (++(*point_to_select_group) >= AMOUNT_SERIES_PPSPM_SETTINGS) *point_to_select_group = 0;
                        }
                      }
                      else
                      {
                        position_in_level_1_menu_DZ_delay[(*point_to_select_group) == AMOUNT_SERIES_PPSPM_SETTINGS] = current_ekran.index_position_1;
                        if (++(*point_to_select_group) >= (AMOUNT_SERIES_PPSPM_SETTINGS + 1)) *point_to_select_group = 0;
                        current_ekran.index_position_1 = position_in_level_1_menu_DZ_delay[(*point_to_select_group) == AMOUNT_SERIES_PPSPM_SETTINGS];
                      }
                    }
                  }
                }
                else if (
                         (key_pressed[0] == 0) &&
                         (key_pressed[1] == 0)
                        )  
                {
                  /*
                  Поряд з кнопкою DOWN  або Page Down не була натиснута інша кнопка
                  Можна виконувати дії
                  */
                  if (
                      (current_ekran.index_position == 0) ||
                      (current_ekran.index_position == 1)
                     )   
                  {
                    //Зміна вибраного елементу відбувається у влкадці уставок або витримок
                    
                    int index_position_1_tmp = current_ekran.index_position_1;
                    if (down != 0) index_position_1_tmp += 1;
                    else index_position_1_tmp += 5;
                    
                    int max_position;
                    if (
                        (current_ekran.current_level != ID_DZ_PG) ||
                        (current_ekran.index_position != 1)  
                       )
                    {
                      max_position = max_number[current_ekran.index_position];
                    }
                    else
                    {
                      if (WM_IsVisible(DZ_SubPages_delay[0]))
                      {
                        max_position = MAX_NUMBER_DELAY_DZ;
                      }
                      else
                      {
                        max_position = MAX_NUMBER_DELAY_DZ_G;
                      }
                    }
                    if (index_position_1_tmp >=  max_position) index_position_1_tmp = max_position - 1;
                    current_ekran.index_position_1 = index_position_1_tmp;
                  }
                  else
                  {
                    //Зміна вибраного елементу відбувається у влкадці управління
                    int index_position_1_tmp = current_ekran.index_position_1;
                    unsigned int gaps_before = 0;
                    calc_number_gaps_ctrl_protection(&gaps_before, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    int position_in_matrix = index_position_1_tmp + gaps_before;
                    unsigned int col = (position_in_matrix & 0x1);

                    if (down != 0) index_position_1_tmp += 2;
                    else index_position_1_tmp += 10;

                    unsigned int gaps_tmp = 0;
                    calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    for (int i = 0; i < (int)(gaps_tmp - gaps_before); i++) 
                    {
                      if (col == 0) index_position_1_tmp--;
                      else index_position_1_tmp++;

                      calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                    }

                    int max_number_ctrl_protection = max_number[2];
                    if (index_position_1_tmp >=max_number_ctrl_protection)
                    {
                      index_position_1_tmp = max_number_ctrl_protection - 1;
                      
                      calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                      while (((index_position_1_tmp + gaps_tmp) & 0x1) != col) 
                      {
                        index_position_1_tmp--;
                        calc_number_gaps_ctrl_protection(&gaps_tmp, &index_position_1_tmp, 0, nalashtuvannja_protection, max_kilkist_stupeniv_protection);
                      }
                    }
                    current_ekran.index_position_1 = index_position_1_tmp;
                  }

                  if (
                      (current_ekran.current_level != ID_DZ_PG) ||
                      (current_ekran.index_position != 1)  
                     )
                  {
                    *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                  }
                  else
                  {
                    position_in_level_1_menu_DZ_delay[WM_IsVisible(DZ_SubPages_delay[1])] = current_ekran.index_position_1;
                  }
                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "+" або"-"
              unsigned int plus, minus;
              if (plus = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PLUS);
                
              if (minus   = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_MINUS);
              
              if (
                  ((plus + minus) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition != 0) &&
                  (
                   (current_ekran.index_position == 0) ||
                   (current_ekran.index_position == 2)
                  )   
                 )  
              {
                /*
                Поряд з кнопкою "+" або "-" не була натиснута інша кнопка
                Ми у режимі редагування
                Можна виконувати дії
                */
                if (current_ekran.index_position == 0)
                {
                  float value = 0, value_new;
                  int value_int, min, max;
        
                  (*protection_pickup_info)(current_ekran.index_position_1, &edit_settings, &min, &max, &value, &value_int);
                  
                   value_new = fabsf(value);
                  if (minus) value_new = -value_new;

                  __info_data info_data;
                  WM_HWIN widget = *(Protection_Pickup_v + current_ekran.index_position_1);
                  EDIT_GetUserData(widget, &info_data, sizeof(__info_data));
                  if (
                      (value_new != value) &&
                      ((info_data.extra_param & FLAG_SIGNED_FATA) != 0)
                     )   
                  {
                    int char_before = EDIT_GetCursorCharPos(widget);
                    EDIT_SetFloatValue(widget, value_new);
                    EDIT_SetCursorAtChar(widget, char_before);

                    current_ekran.edition = 2;
                    start_gui_exec = 1;
                  }
                }
                else if (current_ekran.index_position == 2)
                {
                  int item_tmp, item, max_item;
                  unsigned char *item_point = NULL;
                
                  (*Protection_control_info)(current_ekran.index_position_1, &max_item);
                  item_point = (*Protection_pointer_to_state)(current_ekran.index_position_1, &edit_settings);

                  if (item_point != NULL)
                  {
                    item_tmp = item = (int)(*item_point);
                
                    if (plus) 
                    {
                      if(++item >= max_item) item = 0;
                    }
                    else
                    {
                      if(--item < 0) item = max_item - 1;
                    }
                    if (item_tmp != item)
                    {
                      *item_point = (unsigned char)item;
                      (*Protection_change_state_callback)(current_ekran.index_position_1, &edit_settings);

                      current_ekran.edition = 2;

                      /*
                      Завершальною операцією виставлення команди на обновлення ногого 
                      пункту меню
                      */
                      command_menu |= (1 << REWRITE_MENU);
                    }
                  }
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Натиснута тільки одна кнопка
                Можна виконувати дії
                */
                
                {
                  if (current_ekran.edition != 0)
                  {
                    //Переміщення вправо у вибраному елементі
                    int key;
                    if      (pressed_0 != 0) key = '0';
                    else if (pressed_1 != 0) key = '1';
                    else if (pressed_2 != 0) key = '2';
                    else if (pressed_3 != 0) key = '3';
                    else if (pressed_4 != 0) key = '4';
                    else if (pressed_5 != 0) key = '5';
                    else if (pressed_6 != 0) key = '6';
                    else if (pressed_7 != 0) key = '7';
                    else if (pressed_8 != 0) key = '8';
                    else                     key = '9';

                    if (current_ekran.index_position == 0)
                    {
                      WM_HWIN widget = *(Protection_Pickup_v + current_ekran.index_position_1);
                      int char_before = EDIT_GetNumChars(widget);
                      EDIT_AddKey(widget, key);
                      int char_after = EDIT_GetNumChars(widget);
                      if (char_after != char_before)
                      {
                        int differnece = char_after - char_before;
                        while (differnece != 0)
                        {
                          if (differnece < 0)
                          {
                            EDIT_AddKey(widget, GUI_KEY_LEFT);
                            differnece++;
                          }
                          else
                          {
                            EDIT_AddKey(widget, GUI_KEY_RIGHT);
                            differnece--;
                          }
                        }
                      }
                      if(
                         (Protection_Pickup_v == CB_Pickup_v) &&
                         (
                          (current_ekran.index_position_1 == 1) ||
                          (current_ekran.index_position_1 >= 4)
                         ) &&
                         (EDIT_GetCursorCharPos(*(Protection_Pickup_v + current_ekran.index_position_1)) > 4)  
                        )
                      {
                        EDIT_SetCursorAtChar(*(Protection_Pickup_v + current_ekran.index_position_1), 4);
                      }
                      start_gui_exec = 1;
                    }
                    else if (current_ekran.index_position == 1)
                    {
                      unsigned int index_shift;
                      if ((current_ekran.current_level != ID_DZ_PG) || WM_IsVisible(DZ_SubPages_delay[0])) index_shift = 0;
                      else index_shift = MAX_NUMBER_DELAY_DZ;
                    
                      EDIT_AddKey(*(Protection_Delay_v + index_shift + current_ekran.index_position_1), key);
                      start_gui_exec = 1;
                    }
                    command_state &= (unsigned int)(~(1 << REDRAW));
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_TRANSFORMER_PG:
      case ID_MODBUS_PG:
      case ID_NET_PG:
        {
          WM_HWIN *Panel_Win, *Pickup_v;
          int *point_to_position_in_level_1_menu, max_number_items;
          switch (current_ekran.current_level)
          {
          case ID_TRANSFORMER_PG:
            {
              Panel_Win = &Transformer_FrameWin;
              Pickup_v = Transformer_v;
              point_to_position_in_level_1_menu = &position_in_level_1_menu_Transformer;
              max_number_items = MAX_NUMBER_ITEMS_TRANSFORMER;
              break;
            }
          case ID_MODBUS_PG:
            {
              Panel_Win = &Modbus_FrameWin;
              Pickup_v = Modbus_v;
              point_to_position_in_level_1_menu = &position_in_level_1_menu_Modbus;
              max_number_items = MAX_NUMBER_ITEMS_MODBUS;
              break;
            }
          case ID_NET_PG:
            {
              Panel_Win = &Net_FrameWin;
//              Pickup_v = Net_v;
              point_to_position_in_level_1_menu = &position_in_level_1_menu_Net;
              max_number_items = MAX_NUMBER_ITEMS_NET;
              break;
            }
          default:
            {
              while(1);
            }
          }
          
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (*Panel_Win == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  //Виходимо з панелі захисту
                  WM_DeleteWindow(*Panel_Win);
                  *Panel_Win = WM_UNATTACHED;

                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                }
                else
                {
                  //Виходимо з режимму редагування
                  current_ekran.edition = 0;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                int index_position_1_tmp = current_ekran.index_position_1;
                if (++index_position_1_tmp >= max_number_items) 
                {
                  index_position_1_tmp = 0;
                }
                current_ekran.index_position_1 = index_position_1_tmp;
                
                *point_to_position_in_level_1_menu = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                  {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = current_ekran.current_level;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                  }
                  else
                  {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;
                    switch(current_ekran.current_level)
                    {
                    case ID_TRANSFORMER_PG:
                      {
                        copy_data_Transformer(&edit_settings, &eeprom_prt_tbl);
                        break;
                      }
                    case ID_MODBUS_PG:
                      {
                        copy_data_Modbus(&edit_settings_1, &eeprom_bs_settings_tbl);
                        break;
                      }
                    case ID_NET_PG:
                      {
//                        copy_data_Net();
                        break;
                      }
                    default:
                      {
                        while(1);
                      }
                    }
                  }
                }
                else if (current_ekran.edition == 1)
                {
                  /*
                  Дані не змінювалися, тому виходимо з режиму редагування без запиту
                  на підтвердження змін
                  */
                  current_ekran.edition = 0;
                }
                else
                {
                  /*
                  Дані змінювалися, тому формуємо запит на підтердження змін
                  */
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = current_ekran.current_level;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                }
                
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = 0;
                *point_to_position_in_level_1_menu = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = max_number_items - 1;
                *point_to_position_in_level_1_menu = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.edition != 0) &&
                    (  
                     (
                      (current_ekran.current_level == ID_TRANSFORMER_PG) &&
                      (  
                       (current_ekran.index_position_1 == 1) ||
                       (current_ekran.index_position_1 == 2)
                      )
                     )
                     ||  
                     (
                      (current_ekran.current_level == ID_MODBUS_PG) &&
                      (  
                       (current_ekran.index_position_1 == 0) ||
                       (current_ekran.index_position_1 == (MAX_NUMBER_ITEMS_MODBUS - 1))
                      )
                     )   
                    )   
                   )   
                {
                  //Переміщення вправо у вибраному елементі
                  EDIT_AddKey(*(Pickup_v + current_ekran.index_position_1), GUI_KEY_LEFT);
                  start_gui_exec = 1;
                }
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.edition != 0) &&
                    (  
                     (
                      (current_ekran.current_level == ID_TRANSFORMER_PG) &&
                      (  
                       (current_ekran.index_position_1 == 1) ||
                       (current_ekran.index_position_1 == 2)
                      )
                     )
                     ||  
                     (
                      (current_ekran.current_level == ID_MODBUS_PG) &&
                      (  
                       (current_ekran.index_position_1 == 0) ||
                       (current_ekran.index_position_1 == (MAX_NUMBER_ITEMS_MODBUS - 1))
                      )
                     )   
                    )   
                   )   
                {
                  //Переміщення вправо у вибраному елементі
                  EDIT_AddKey(*(Pickup_v + current_ekran.index_position_1), GUI_KEY_RIGHT);
                  start_gui_exec = 1;
                }
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP   ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "UP" або"Page Up"
              unsigned int up, pg_up;
              if (up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
                
              if (pg_up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if ((up + pg_up) == 1)
              {
                if(
                   (key_pressed[0] == 0) &&
                   (key_pressed[1] == 0)
                  )  
                {
                  /*
                  Поряд з кнопкою UP не була натиснута інша кнопка
                  Можна виконувати дії
                  */
                  int index_position_1_tmp = current_ekran.index_position_1;
                  if (up != 0) index_position_1_tmp -= 1;
                  else index_position_1_tmp -= 5;
                    
                  if (index_position_1_tmp < 0) index_position_1_tmp = 0;
                  current_ekran.index_position_1 = index_position_1_tmp;

                  *point_to_position_in_level_1_menu = current_ekran.index_position_1;
                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "DOWN" або"Page Down"
              unsigned int down, pg_down;
              if (down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
                
              if (pg_down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if ((down + pg_down) == 1)
              {
                if (
                    (key_pressed[0] == 0) &&
                    (key_pressed[1] == 0)
                   )  
                {
                  /*
                  Поряд з кнопкою DOWN  або Page Down не була натиснута інша кнопка
                  Можна виконувати дії
                  */
                    
                  int index_position_1_tmp = current_ekran.index_position_1;
                  if (down != 0) index_position_1_tmp += 1;
                  else index_position_1_tmp += 5;
                    
                  if (index_position_1_tmp >=  max_number_items) index_position_1_tmp = max_number_items - 1;
                  current_ekran.index_position_1 = index_position_1_tmp;
 
                  *point_to_position_in_level_1_menu = current_ekran.index_position_1;
                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "+" або"-"
              unsigned int plus, minus;
              if (plus = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PLUS);
                
              if (minus   = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_MINUS);
              
              if (
                  ((plus + minus) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition != 0) &&
                  (  
                   (
                    (current_ekran.current_level == ID_TRANSFORMER_PG) &&
                    (  
                     (current_ekran.index_position_1 == 0)
                    )
                   )
                   ||  
                   (
                    (current_ekran.current_level == ID_MODBUS_PG) &&
                    (  
                     (current_ekran.index_position_1 >= 1) &&
                     (current_ekran.index_position_1 <= 3)
                    )
                   )   
                  )   
                 )  
              {
                /*
                Поряд з кнопкою "+" або "-" не була натиснута інша кнопка
                Ми у режимі редагування
                Можна виконувати дії
                */
                
                int item_tmp, item, max_item;
                unsigned char *item_point = NULL;
                
                switch (current_ekran.current_level)
                {
                case ID_TRANSFORMER_PG:
                {
                  switch (current_ekran.index_position_1)
                  {
                  case 0:
                    {
                      max_item = 3;
                      item_point = &edit_settings.ownrTr_Line.chLineWGV;
                      break;
                    }
                  default:
                    {
                      //Сюди програма ніколи б не мала зайти
                      while(1);
                    }
                  }
                  
                  break;
                }
                case ID_MODBUS_PG:
                  {
                    switch (current_ekran.index_position_1)
                    {
                      case 1:
                      {
                        max_item = 7;
                        item_point = &edit_settings_1.chSpeed;
                        break;
                      }
                    case 2:
                      {
                        max_item = 3;
                        item_point = &edit_settings_1.chParityCheck;
                        break;
                      }
                    case 3:
                      {
                        max_item = 2;
                        item_point = &edit_settings_1.chAmtStopBit;
                        break;
                      }
                    default:
                      {
                        //Сюди програма ніколи б не мала зайти
                        while(1);
                      }
                    }
                
                    break;
                  }
                default:
                  {
                    while(1);
                  }
                }

                if (item_point != NULL)
                {
                  if (
                      (current_ekran.current_level == ID_TRANSFORMER_PG) ||
                      (current_ekran.index_position_1 != 3)
                     )   
                  {
                    item_tmp = item = (int)(*item_point);
                  }
                  else
                  {
                    item_tmp = item = (int)(*item_point) - 1;
                  }
                  
                  if (plus) 
                  {
                    if(++item >= max_item) item = 0;
                  }
                  else
                  {
                    if(--item < 0) item = max_item - 1;
                  }
                  if (item_tmp != item)
                  {
                    if (
                        (current_ekran.current_level == ID_TRANSFORMER_PG) ||
                        (current_ekran.index_position_1 != 3)
                       )   
                    {
                      *item_point = (unsigned short)item;
                    }
                    else
                    {
                      *item_point = ((unsigned short)item + 1);
                    }

                    current_ekran.edition = 2;

                    /*
                    Завершальною операцією виставлення команди на обновлення ногого 
                    пункту меню
                    */
                    command_menu |= (1 << REWRITE_MENU);
                  }
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition != 0) &&
                  (  
                   (
                    (current_ekran.current_level == ID_TRANSFORMER_PG) &&
                    (  
                     (current_ekran.index_position_1 == 1) ||
                     (current_ekran.index_position_1 == 2)
                    )
                   )
                   ||  
                   (
                    (current_ekran.current_level == ID_MODBUS_PG) &&
                    (  
                     (current_ekran.index_position_1 == 0) ||
                     (current_ekran.index_position_1 == (MAX_NUMBER_ITEMS_MODBUS - 1))
                    )
                   )   
                  )   
                 )  
              {
                /*
                Натиснута тільки одна кнопка
                Можна виконувати дії
                */
                
                {
                  //Переміщення вправо у вибраному елементі
                  int key;
                  if      (pressed_0 != 0) key = '0';
                  else if (pressed_1 != 0) key = '1';
                  else if (pressed_2 != 0) key = '2';
                  else if (pressed_3 != 0) key = '3';
                  else if (pressed_4 != 0) key = '4';
                  else if (pressed_5 != 0) key = '5';
                  else if (pressed_6 != 0) key = '6';
                  else if (pressed_7 != 0) key = '7';
                  else if (pressed_8 != 0) key = '8';
                  else                     key = '9';

                  WM_HWIN widget = *(Pickup_v + current_ekran.index_position_1);
                  int char_before = EDIT_GetNumChars(widget);
                  EDIT_AddKey(widget, key);
                  int char_after = EDIT_GetNumChars(widget);
                  if (char_after != char_before)
                  {
                    int differnece = char_after - char_before;
                    while (differnece != 0)
                    {
                      if (differnece < 0)
                      {
                        EDIT_AddKey(widget, GUI_KEY_LEFT);
                        differnece++;
                      }
                      else
                      {
                        EDIT_AddKey(widget, GUI_KEY_RIGHT);
                        differnece--;
                      }
                    }
                  }
                  start_gui_exec = 1;

                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_RESURS_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (Resurs_FrameWin == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                //Виходимо з панелі захисту
                WM_DeleteWindow(Resurs_FrameWin);
                Resurs_FrameWin = WM_UNATTACHED;

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_CLOCK_PG:
        {
          if (_CHECK_KEY_SET_BIT(key_released, VK_OFFSET_SHIFT) != 0)
          {
            _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_SHIFT);
            _CLEAR_KEY_BIT(key_released, VK_OFFSET_SHIFT);
          }
          
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (Clock_FrameWin == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  //Виходимо з панелі захисту
                  WM_DeleteWindow(Clock_FrameWin);
                  Clock_FrameWin = WM_UNATTACHED;

                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                }
                else
                {
                  //Виходимо з режимму редагування
                  current_ekran.edition = 0;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_SHIFT) != 0)
              {
                /*
                Поряд з кнопкою LEFT утримується кнопка SHIFT
                */
                unsigned int key_pressed_tmp[RANG_KEY] = {key_pressed[0], key_pressed[1]};
                _CLEAR_KEY_BIT(key_pressed_tmp, VK_OFFSET_SHIFT);
                if (
                    (key_pressed_tmp[0] == 0) &&
                    (key_pressed_tmp[1] == 0)
                   )
                {
                  /*
                  Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                  біту, який відповідає за SHIFT у основному масиві
                  */
                  _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_SHIFT);

                  int index_position_1_tmp = current_ekran.index_position_1;
                  if (--index_position_1_tmp < 0) 
                  {
                    index_position_1_tmp = MAX_NUMBER_ITEMS_CLOCK - 1;
                  }
                  current_ekran.index_position_1 = index_position_1_tmp;
                
                  position_in_level_1_menu_Clock = current_ekran.index_position_1;
                }
              }
              else if (
                       (key_pressed[0] == 0) &&
                       (key_pressed[1] == 0)
                      )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
                int index_position_1_tmp = current_ekran.index_position_1;
                if (++index_position_1_tmp >= MAX_NUMBER_ITEMS_CLOCK) 
                {
                  index_position_1_tmp = 0;
                }
                current_ekran.index_position_1 = index_position_1_tmp;
                
                position_in_level_1_menu_Clock = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition == 0)
                {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                  {
                    //Переходимо на запит паролю
                    position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD] = current_ekran.current_level;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD;
                
                    //Обнуляємо введений пароль
                    typed_password[0] = '\0';
                    cursor_position_dp = 0;
                  }
                  else
                  {
                    //Переходимо в режим редагування 
                    current_ekran.edition = 1;

                    unsigned char *label_to_time_array, *label_calibration;
                    if (copying_time == 0)
                    {
                      label_to_time_array = rtc_time;
                      label_calibration = &rtc_calibration;
                    }
                    else
                    {
                      label_to_time_array = rtc_time_copy;
                      label_calibration = &rtc_calibration_copy;
                    }
                    for(unsigned int index = 0; index < 8; index++) rtc_time_edit[index] = *(label_to_time_array + index);
                    rtc_calibration_edit = *label_calibration;
                  }
                }
                else if (current_ekran.edition == 1)
                {
                  /*
                  Дані не змінювалися, тому виходимо з режиму редагування без запиту
                  на підтвердження змін
                  */
                  current_ekran.edition = 0;
                }
                else
                {
                  /*
                  Дані змінювалися, тому формуємо запит на підтердження змін
                  */
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION] = current_ekran.current_level;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION;
                }
                
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = 0;
                position_in_level_1_menu_Clock = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = MAX_NUMBER_ITEMS_CLOCK - 1;
                position_in_level_1_menu_Clock = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0)
                {
                  int index_position_1_tmp = current_ekran.index_position_1;
                  if (index_position_1_tmp < (MAX_NUMBER_ITEMS_CLOCK - 1))
                  {
                    if (
                        ( (index_position_1_tmp - 1) < 0) ||
                        (((index_position_1_tmp - 1) / 3) != (index_position_1_tmp / 3))
                       )
                    {
                      int index_next_row =  (index_position_1_tmp /3  + 1)*3;
                      index_position_1_tmp = index_next_row - 1;
                    }
                    else
                    {
                      index_position_1_tmp--;
                    }
                    current_ekran.index_position_1 = index_position_1_tmp;
                
                    position_in_level_1_menu_Clock = current_ekran.index_position_1;
                  }
                }
                else
                {
                  //Переміщення вліво у вибраному елементі
                  if (
                      (current_ekran.index_position_1 != (MAX_NUMBER_ITEMS_CLOCK - 1)) ||
                      (EDIT_GetCursorCharPos(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1]) > 1)  
                     )   
                  EDIT_AddKey(*(Clock_v + current_ekran.index_position_1), GUI_KEY_LEFT);
                  selection_for_Clock(*(Clock_v + current_ekran.index_position_1));
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  start_gui_exec = 1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition == 0)
                {
                  int index_position_1_tmp = current_ekran.index_position_1;
                  if (index_position_1_tmp < (MAX_NUMBER_ITEMS_CLOCK - 1))
                  {
                    if (
                        (((index_position_1_tmp + 1) /3) != (index_position_1_tmp /3))
                      )
                    {
                      index_position_1_tmp = (index_position_1_tmp / 3)*3;
                    }
                    else 
                    {
                      index_position_1_tmp++;
                    }
                    current_ekran.index_position_1 = index_position_1_tmp;
                    position_in_level_1_menu_Clock = current_ekran.index_position_1;
                  }
                }
                else if (current_ekran.edition != 0)
                {
                  //Переміщення вправо у вибраному елементі
                  EDIT_AddKey(*(Clock_v + current_ekran.index_position_1), GUI_KEY_RIGHT);
                  selection_for_Clock(*(Clock_v + current_ekran.index_position_1));
                  command_state &= (unsigned int)(~(1 << REDRAW));
                  start_gui_exec = 1;
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0)
            {
              //Зафіксована натиснута кнопка "UP"
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
                
              if(
                 (key_pressed[0] == 0) &&
                 (key_pressed[1] == 0)
                )  
              {
                /*
                Поряд з кнопкою UP не була натиснута інша кнопка
                Можна виконувати дії
                */
                int index_position_1_tmp = current_ekran.index_position_1;
                if (index_position_1_tmp == (MAX_NUMBER_ITEMS_CLOCK - 1)) index_position_1_tmp = (MAX_NUMBER_ITEMS_CLOCK - 1 - 1);
                else if (index_position_1_tmp >= 3) index_position_1_tmp -= 3;
                    
                if (index_position_1_tmp < 0) index_position_1_tmp = 0;
                current_ekran.index_position_1 = index_position_1_tmp;

                position_in_level_1_menu_Clock = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0)
            {
              //Зафіксована натиснута кнопка "DOWN"
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
                
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою DOWN  або Page Down не була натиснута інша кнопка
                Можна виконувати дії
                */
                    
                int index_position_1_tmp = current_ekran.index_position_1;
                if (index_position_1_tmp < 3) index_position_1_tmp += 3;
                else if (index_position_1_tmp < (MAX_NUMBER_ITEMS_CLOCK - 1)) index_position_1_tmp = (MAX_NUMBER_ITEMS_CLOCK - 1);
                    
                if (index_position_1_tmp >=  MAX_NUMBER_ITEMS_CLOCK) index_position_1_tmp = MAX_NUMBER_ITEMS_CLOCK - 1;
                current_ekran.index_position_1 = index_position_1_tmp;
 
                position_in_level_1_menu_Clock = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "+" або"-"
              unsigned int plus, minus;
              if (plus = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PLUS);
                
              if (minus   = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_MINUS);
              
              if (
                  ((plus + minus) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition != 0) &&
                  (
                   (current_ekran.index_position_1 == 1) ||
                   (current_ekran.index_position_1 == (MAX_NUMBER_ITEMS_CLOCK - 1))
                  )   
                 )  
              {
                /*
                Поряд з кнопкою "+" або "-" не була натиснута інша кнопка
                Ми у режимі редагування
                Можна виконувати дії
                */
                
                int item_tmp_bcd, item_bcd;
                if (current_ekran.index_position_1 == 1)
                {
                  item_tmp_bcd = item_bcd = rtc_time_edit[6];
                  int item = (item_bcd >> 4)*10 + (item_bcd & 0xf);
                
                  if ((item < 1) || (item > 12)) item = 1;
                  if (plus) 
                  {
                    if(++item >= 12) item = 1;
                  }
                  else
                  {
                    if(--item <= 0) item = 12;
                  }
                  item_bcd = ((item / 10) << 4) | (item % 10);
                
                  if (item_tmp_bcd != item_bcd)
                  {
                    rtc_time_edit[6] = item_bcd;
                    current_ekran.edition = 2;
                  }
                }
                else
                {
                  item_tmp_bcd = item_bcd = rtc_calibration_edit;
                  if (plus)
                  {
                    item_bcd |= 0x20;
                  }
                  else
                  {
                    item_bcd &= (unsigned int)(~0x20);
                  }

                  if (item_tmp_bcd != item_bcd)
                  {
                    rtc_calibration_edit = item_bcd;
                    current_ekran.edition = 2;
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition != 0) &&
                  (current_ekran.index_position_1 != 1)
                 )  
              {
                /*
                Натиснути тільки одна кнопка цифри
                Ми у режимі редагування
                Можна виконувати дії
                */
                
                unsigned char *point_to_target = NULL;
                int item_tmp_bcd, item_bcd/*, min, max*/;
                switch (current_ekran.index_position_1)
                {
                case 0:
                  {
//                    min = 1;
//                    max = 31;  
                    point_to_target = &rtc_time_edit[5]; 
                    break;
                  }
                case 2:
                  {
//                    min = 0;
//                    max = 99;  
                    point_to_target = &rtc_time_edit[7]; 
                    break;
                  }
                case 3:
                  {
//                    min = 0;
//                    max = 23;  
                    point_to_target = &rtc_time_edit[3]; 
                    break;
                  }
                case 4:
                  {
//                    min = 0;
//                    max = 59;  
                    point_to_target = &rtc_time_edit[2]; 
                    break;
                  }
                case 5:
                  {
//                    min = 0;
//                    max = 59;  
                    point_to_target = &rtc_time_edit[1]; 
                    break;
                  }
                case 6:
                  {
//                    min = 0;
//                    max = 31;  
                    point_to_target = &rtc_calibration_edit; 
                    break;
                  }
                }
                
                if (point_to_target != NULL)
                {
                  int key_value;
                  if (pressed_0) key_value = 0;
                  else if (pressed_1) key_value = 1;
                  else if (pressed_2) key_value = 2;
                  else if (pressed_3) key_value = 3;
                  else if (pressed_4) key_value = 4;
                  else if (pressed_5) key_value = 5;
                  else if (pressed_6) key_value = 6;
                  else if (pressed_7) key_value = 7;
                  else if (pressed_8) key_value = 8;
                  else if (pressed_9) key_value = 9;
                  
                  item_tmp_bcd = item_bcd = *point_to_target;
                  int item;
                  if (current_ekran.index_position_1 != (MAX_NUMBER_ITEMS_CLOCK - 1))
                  {
                    int high_tetrad = item_tmp_bcd >> 4;
                    if (high_tetrad > 9) high_tetrad = 0;
                    int low_tetrad = item_tmp_bcd & 0xf;
                    if (low_tetrad > 9) low_tetrad = 0;
                    item = high_tetrad*10 + low_tetrad;
                  }
                  else
                  {
                    item = item_tmp_bcd & 0x1f;
                  }
                
//                  if ((item < min) || (item > max)) item = min;
                  WM_HWIN widget = Clock_v[current_ekran.index_position_1];

                  if (current_ekran.index_position_1 != (MAX_NUMBER_ITEMS_CLOCK - 1))
                  {
                    if (EDIT_GetCursorCharPos(widget) == 0)
                    {
                      item_bcd = (key_value << 4) | (item % 10);
                      EDIT_AddKey(widget, GUI_KEY_RIGHT);
                    }
                    else
                    {
                      item_bcd = ((item / 10) << 4) | (key_value);
                    }
                  }
                  else
                  {
                    if (EDIT_GetCursorCharPos(widget) == 1)
                    {
                      item_bcd = (key_value)*10 + (item % 10);
                      if (item_bcd > 31) item_bcd = 31;
                      EDIT_AddKey(widget, GUI_KEY_RIGHT);
                    }
                    else
                    {
                      item_bcd = (item / 10)*10 + (key_value);
                      if (item_bcd > 31) item_bcd = 31;
                    }
                    item_bcd += (item_tmp_bcd & 0x20);
                  }
                
                  if (item_tmp_bcd != item_bcd)
                  {
                    *point_to_target = item_bcd;
                    current_ekran.edition = 2;
                  }
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              _SET_KEY_BIT(key_maska, VK_OFFSET_SHIFT);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_LCD_SETTINGS:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (LCD_Settings_FrameWin == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition_level_2 == 0)
                {
                  //Виходимо з панелі захисту
                  WM_DeleteWindow(LCD_Settings_FrameWin);
                  LCD_Settings_FrameWin = WM_UNATTACHED;

                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];

                  current_modal_form = false;
                }
                else
                {
                  //Виходимо з режимму редагування
                  current_ekran.edition_level_2 = 0;
                }
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                if (current_ekran.edition_level_2 == 0)
                {
                  if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                  {
                    //Переходимо на запит паролю
//                    position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                    previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2] = current_ekran.current_level;
                    
                    current_ekran.current_level = ID_DIALOG_PASSWORD_LEVEL_2;
                
                    //Обнуляємо введений пароль
                    typed_password_level_2[0] = '\0';
                    cursor_position_dp_level_2 = 0;
                  }
                  else
                  {
                    //Переходимо в режим редагування 
                    current_ekran.edition_level_2 = 1;
                    switch(current_ekran.current_level)
                    {
                    case ID_LCD_SETTINGS:
                      {
                        edit_settings_1.chSleepTmVal = eeprom_bs_settings_tbl.chSleepTmVal;
                        break;
                      }
                    default:
                      {
                        while(1);
                      }
                    }
                  }
                }
                else if (current_ekran.edition_level_2 == 1)
                {
                  /*
                  Дані не змінювалися, тому виходимо з режиму редагування без запиту
                  на підтвердження змін
                  */
                  current_ekran.edition_level_2 = 0;
                }
                else
                {
                  /*
                  Дані змінювалися, тому формуємо запит на підтердження змін
                  */
                  position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;
                  previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = current_ekran.current_level;
                    
                  current_ekran.current_level = ID_DIALOG_CONFIRMATION_LEVEL_2;
                }
                
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition_level_2 != 0)
                {
                  //Переміщення вправо у вибраному елементі
                  EDIT_AddKey(LCD_Settings_Edit, GUI_KEY_LEFT);
                  start_gui_exec = 1;
                }
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (current_ekran.edition_level_2 != 0) 
                {
                  //Переміщення вправо у вибраному елементі
                  EDIT_AddKey(LCD_Settings_Edit, GUI_KEY_RIGHT);
                  start_gui_exec = 1;
                }
                command_state &= (unsigned int)(~(1 << REDRAW));
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0) &&
                  (current_ekran.edition_level_2 != 0)
                 )  
              {
                /*
                Натиснута тільки одна кнопка
                Можна виконувати дії
                */
                
                {
                  //Переміщення вправо у вибраному елементі
                  int key;
                  if      (pressed_0 != 0) key = '0';
                  else if (pressed_1 != 0) key = '1';
                  else if (pressed_2 != 0) key = '2';
                  else if (pressed_3 != 0) key = '3';
                  else if (pressed_4 != 0) key = '4';
                  else if (pressed_5 != 0) key = '5';
                  else if (pressed_6 != 0) key = '6';
                  else if (pressed_7 != 0) key = '7';
                  else if (pressed_8 != 0) key = '8';
                  else                     key = '9';

                  int char_before = EDIT_GetNumChars(LCD_Settings_Edit);
                  EDIT_AddKey(LCD_Settings_Edit, key);
                  int char_after = EDIT_GetNumChars(LCD_Settings_Edit);
                  if (char_after != char_before)
                  {
                    int differnece = char_after - char_before;
                    while (differnece != 0)
                    {
                      if (differnece < 0)
                      {
                        EDIT_AddKey(LCD_Settings_Edit, GUI_KEY_LEFT);
                        differnece++;
                      }
                      else
                      {
                        EDIT_AddKey(LCD_Settings_Edit, GUI_KEY_RIGHT);
                        differnece--;
                      }
                    }
                  }
                  start_gui_exec = 1;

                  command_state &= (unsigned int)(~(1 << REDRAW));
                }
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_TM_PG:
      case ID_DIAGNOSTICS_PG:
        {
          WM_HWIN *Panel_Win;
          int *point_to_position_in_level_1_menu;
          unsigned int number_pages;
          __DIAGN state_diagnostyka;
          
          switch (current_ekran.current_level)
          {
          case ID_TM_PG:
            {
              number_pages = 2;
              
              Panel_Win = &TM_FrameWin;
              point_to_position_in_level_1_menu = position_in_level_1_menu_TM;

              unsigned int number_set_bits = 0;
              char state_active_functions[AMOUNT_BYTE_FOR_OEPRF];
              if (GetActiveCmdsDemo(state_active_functions) == SUCCESS_EXEC)
              {
                for (unsigned int j = 0; j < RESERV_MAX_OEPRF_ONB; j++)
                {
                  unsigned int word = j >> 3;
                  unsigned int maska = 1 << (j & 0x7);
                    
                  if (state_active_functions[word] & maska) number_set_bits++;
                }
              }
              TM_max_number_bits = number_set_bits;
              
              break;
            }
          case ID_DIAGNOSTICS_PG:
            {
              GetDiagnfield(&state_diagnostyka);
              
              number_pages = 4;
              
              Panel_Win = &Diagnostics_FrameWin;
              point_to_position_in_level_1_menu = position_in_level_1_menu_Diagnostics;

              unsigned int number_set_bits_1 = 0, number_set_bits_2 = 0, number_set_bits_3 = 0;
              for (unsigned int j = 0; j < ERROR_BS_FATAL_EROR_LAST_BIT; j++)
              {
                unsigned int word = j >> 5;
                unsigned int maska = 1 << (j & 0x1f);
                    
                if (state_diagnostyka.hldrPrgEvtBs.UNBsRamPrgEvts.lArBsPrgEvts[word] & maska) number_set_bits_1++;
              }
              for (unsigned int j = 0; j < ERROR_BM_FATAL_EROR_LAST_BIT; j++)
              {
                unsigned int word = j >> 5;
                unsigned int maska = 1 << (j & 0x1f);
                    
                if (state_diagnostyka.hldrPrgEvtBm.UNBmRamPrgEvts.lArBmPrgEvts[word] & maska) number_set_bits_2++;
              }
              for (unsigned int j = 0; j < ERROR_BR_FATAL_EROR_LAST_BIT; j++)
              {
                unsigned int word = j >> 5;
                unsigned int maska = 1 << (j & 0x1f);
                    
                if (state_diagnostyka.hldrPrgEvtBr.UNBrRamPrgEvts.lArBrPrgEvts[word] & maska) number_set_bits_3++;
              }
              Diagnistics_max_number_bits[0] = number_set_bits_1;
              Diagnistics_max_number_bits[1] = number_set_bits_2;
              Diagnistics_max_number_bits[2] = number_set_bits_3;
              
              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));

            if (
                (current_ekran.current_level == ID_TM_PG) &&
                (current_ekran.index_position == 1)  
               )
            {
              int max_number_bits = TM_max_number_bits;
              if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
              
              if (current_ekran.index_position_1 > max_number_bits) 
              {
                current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_F_IN_PANEL)*MAX_NUMBER_F_IN_PANEL;
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
            }
            else if (current_ekran.current_level == ID_DIAGNOSTICS_PG)
            {
              int max_number_bits = Diagnistics_max_number_bits[current_ekran.index_position];
              if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
              
              if (current_ekran.index_position_1 > max_number_bits) 
              {
                current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_DIAGN_IN_PANEL)*MAX_NUMBER_DIAGN_IN_PANEL;
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
            }
            
            if (*Panel_Win == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                //Виходимо з панелі
                WM_DeleteWindow(*Panel_Win);
                *Panel_Win = WM_UNATTACHED;

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                current_ekran.index_position_1 = 0;
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */
                if (
                    (current_ekran.current_level == ID_TM_PG) &&
                    (current_ekran.index_position == 1)  
                   )
                {
                  unsigned int max_number_bits = TM_max_number_bits;
                  if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
                  current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_F_IN_PANEL)*MAX_NUMBER_F_IN_PANEL;
                }
                else if (current_ekran.current_level == ID_DIAGNOSTICS_PG)
                {
                  unsigned int max_number_bits = Diagnistics_max_number_bits[current_ekran.index_position];
                  if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
                  current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_DIAGN_IN_PANEL)*MAX_NUMBER_DIAGN_IN_PANEL;
                }
                else
                {
                  current_ekran.index_position_1 = 0;
                }
                
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )
              {
                /*
                Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                біту, який відповідає за CTRL у основному масиві
                */
 
                /*
                Виконуємо зміну вкладок
                */
                if (--current_ekran.index_position < 0) 
                  current_ekran.index_position = number_pages - 1;
                position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;

                current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )
              {
                /*
                Більше ніяких кнопок не було зафіксовано - Підтверджуємо це очищенням
                біту, який відповідає за CTRL у основному масиві
                */
                  
                /*
                Виконуємо зміну вкладок
                */
                if ((unsigned int)(++current_ekran.index_position) >= number_pages) 
                  current_ekran.index_position = 0;
                position_in_current_level_menu[current_ekran.current_level] = current_ekran.index_position;

                current_ekran.index_position_1 = *(point_to_position_in_level_1_menu + current_ekran.index_position);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "Page Up" або"Page Down"
              unsigned int pg_up, pg_down;
              if (pg_up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);

              if (pg_down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);

                if (
                    ((pg_up + pg_down) == 1) &&
                    (key_pressed[0] == 0) &&
                    (key_pressed[1] == 0)
                   )  
                {
                  /*
                  Поряд з кнопкою "Page Up" або"Page Down" не була натиснута інша кнопка
                  Можна виконувати дії
                  */
                  if (
                      (current_ekran.current_level == ID_TM_PG) &&
                      (current_ekran.index_position == 1)  
                     )
                  {
                    int max_number_bits = TM_max_number_bits;
                    if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
                    
                    int index_position_1_tmp = current_ekran.index_position_1;
                    if (pg_up)
                      index_position_1_tmp -= MAX_NUMBER_F_IN_PANEL;
                    else if (pg_down)
                      index_position_1_tmp += MAX_NUMBER_F_IN_PANEL;
                    
                    if (index_position_1_tmp < 0) index_position_1_tmp = 0;
                    else if (index_position_1_tmp > max_number_bits) index_position_1_tmp = max_number_bits;
                      
                    current_ekran.index_position_1 = (index_position_1_tmp/MAX_NUMBER_F_IN_PANEL)*MAX_NUMBER_F_IN_PANEL;
                  }
                  else if (current_ekran.current_level == ID_DIAGNOSTICS_PG)
                  {
                    int max_number_bits = Diagnistics_max_number_bits[current_ekran.index_position];
                    if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
                    
                    int index_position_1_tmp = current_ekran.index_position_1;
                    if (pg_up)
                      index_position_1_tmp -= MAX_NUMBER_DIAGN_IN_PANEL;
                    else if (pg_down)
                      index_position_1_tmp += MAX_NUMBER_DIAGN_IN_PANEL;
                    
                    if (index_position_1_tmp < 0) index_position_1_tmp = 0;
                    else if (index_position_1_tmp > max_number_bits) index_position_1_tmp = max_number_bits;
                      
                    current_ekran.index_position_1 = (index_position_1_tmp/MAX_NUMBER_DIAGN_IN_PANEL)*MAX_NUMBER_DIAGN_IN_PANEL;
                  }
                  else
                  {
                    current_ekran.index_position_1 = 0;
                  }
                  *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
                  
                }
                else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            if (
                (current_ekran.current_level == ID_TM_PG) &&
                (current_ekran.index_position == 1)  
               )
            {
              int max_number_bits = TM_max_number_bits;
              if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
              
              if (current_ekran.index_position_1 > max_number_bits) 
              {
                current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_F_IN_PANEL)*MAX_NUMBER_F_IN_PANEL;
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
            }
            else if (current_ekran.current_level == ID_DIAGNOSTICS_PG)
            {
              int max_number_bits = Diagnistics_max_number_bits[current_ekran.index_position];
              if (max_number_bits != 0 ) max_number_bits -= 1; /*Bo indeksy idut vid 0*/
              
              if (current_ekran.index_position_1 > max_number_bits) 
              {
                current_ekran.index_position_1 = (max_number_bits/MAX_NUMBER_DIAGN_IN_PANEL)*MAX_NUMBER_DIAGN_IN_PANEL;
                *(point_to_position_in_level_1_menu + current_ekran.index_position) = current_ekran.index_position_1;
              }
            }

            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      case ID_ABOUT_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (About_FrameWin == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                //Виходимо з панелі захисту
                WM_DeleteWindow(About_FrameWin);
                About_FrameWin = WM_UNATTACHED;

                current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];

                current_modal_form = false;
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
            WM_SetFocus(About_FrameWin);
          }
          
          break;
        }
      case ID_REGISTRATORS_PG:
        {
          if ((command_menu & (1 << REWRITE_MENU)) != 0)
          {
            //Стоїть команда на обновлення вмістимого екрану
            command_menu &= (unsigned int)(~(1 << REWRITE_MENU));
            if (Registrators_FrameWin == WM_UNATTACHED) show_window(current_ekran.current_level);
          } 
          else 
          {
            //Натиснута та кнопка, на яку треба відреагувати
            if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ESC) != 0)
            {
              //Зафіксована натиснута кнопка ESC
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ESC);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ESC не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                //Виходимо з панелі захисту
                WM_DeleteWindow(Registrators_FrameWin);
                Registrators_FrameWin = WM_UNATTACHED;

                  current_ekran.current_level = previous_level_in_current_level_menu[current_ekran.current_level];
                  current_ekran.index_position = position_in_current_level_menu[current_ekran.current_level];
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_TAB) != 0)
            {
              //Зафіксована натиснута кнопка TAB
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_TAB);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою TAB не була натиснута інша кнопка
                Можна виконувати дії
                */
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_ENTER) != 0)
            {
              //Зафіксована натиснута кнопка ENTER
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_ENTER);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою ENTER не була натиснута інша кнопка
                Можна виконувати дії
                */
                
                /*
                Завершальною операцією є зняття команди на перемальованування
                старого пункту меню і виставлення команди на обновлення ногого 
                пункту меню
                */
                command_state &= (unsigned int)(~(1 << REDRAW));
                command_menu |= (1 << REWRITE_MENU);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_HOME) != 0)
            {
              //Зафіксована натиснута кнопка Home
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_HOME);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою HOME не була натиснута інша кнопка
                Можна виконувати дії
                */
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_END) != 0)
            {
              //Зафіксована натиснута кнопка End
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_END);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою END не була натиснута інша кнопка
                Можна виконувати дії
                */

              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0)
            {
              //Зафіксована натиснута кнопка LEFT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою LEFT не була натиснута інша кнопка
                Можна виконувати дії
                */

              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0)
            {
              //Зафіксована натиснута кнопка RIGHT
              _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
              
              if (
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Поряд з кнопкою RIGHT не була натиснута інша кнопка
                Можна виконувати дії
                */
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP   ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "UP" або"Page Up"
              unsigned int up, pg_up;
              if (up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_UP);
                
              if (pg_up = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_UP) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_UP);
              
              if ((up + pg_up) == 1)
              {
                if (
                    (key_pressed[0] == 0) &&
                    (key_pressed[1] == 0)
                   )  
                {
                  /*
                  Поряд з кнопкою UP не була натиснута інша кнопка
                  Можна виконувати дії
                  */

                  if (up == 1)
                  {
                    /*
                    Minjaemo vybranyj rejestratir
                    */
                    if (--current_ekran.index_position < 0) current_ekran.index_position = (3 - 1);
                  }

                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN ) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка "DOWN" або"Page Down"
              unsigned int down, pg_down;
              if (down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_DOWN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_DOWN);
                
              if (pg_down = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PG_DN) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PG_DN);
              
              if ((down + pg_down) == 1)
              {
                if (
                    (key_pressed[0] == 0) &&
                    (key_pressed[1] == 0)
                   )  
                {
                  /*
                  Поряд з кнопкою DOWN  або Page Down не була натиснута інша кнопка
                  Можна виконувати дії
                  */

                  if (down == 1)
                  {
                    /*
                    Minjaemo vybranyj rejestratir
                    */
                    if (++current_ekran.index_position >= 3) current_ekran.index_position = 0;
                  }

                }
                else command_state |= (1 << ERROR_FIXED);
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else if (
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0) ||
                     (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0)
                    )   
            {
              //Зафіксована натиснута кнопка цимфри
              unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
              unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

              if (pressed_0 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

              if (pressed_1 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

              if (pressed_2 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_2) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

              if (pressed_3 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_3) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

              if (pressed_4 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_4) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

              if (pressed_5 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_5) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

              if (pressed_6 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_6) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

              if (pressed_7 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_7) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

              if (pressed_8 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_8) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

              if (pressed_9 = (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_9) != 0))
                _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
              
              if (
                  ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
                    pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
                  (key_pressed[0] == 0) &&
                  (key_pressed[1] == 0)
                 )  
              {
                /*
                Натиснута тільки одна кнопка
                Можна виконувати дії
                */
                
              }
              else command_state |= (1 << ERROR_FIXED);
            }
            else
            {
              unsigned int key_maska[RANG_KEY] = {0, 0};
              _SET_KEY_BIT(key_maska, VK_OFFSET_CTRL);
              
              key_pressed[0] &= key_maska[0];
              key_pressed[1] &= key_maska[1];
              command_state &= (unsigned int)(~(1 << REDRAW));
            }
          }
          
          if (command_state == (1 << REDRAW))
          {
            //Виклик функції виводу інформації головного меню
            win_handler();
          }
          
          break;
        }
      default:  break;
    }
  }
}
