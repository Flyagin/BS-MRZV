#include "header_mal.h"

static void change_names_menu(MENU_Handle hObj, unsigned int *index)
{
  unsigned int NumItems = MENU_GetNumItems(hObj);
  for (unsigned int i = 0; i < NumItems; i++)
  {
    MENU_ITEM_DATA Item;
    MENU_GetItem(hObj, id_menu[*index], &Item);
    Item.pText = menu_option_title[*index].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
    MENU_SetItem(hObj, id_menu[*index], &Item);
    (*index)++;
    
    change_names_menu(Item.hSubmenu, index);
  }
}

/*****************************
Обновлення інформації на панелі вибраного захисту
*****************************/
void repaint_actions(__index_level_menu id_panel)
{
  if (change_language)
  {
    //Main-menu
    unsigned int index = 0;
    change_names_menu(hMenu_main, &index);
  }

  unsigned int error_data = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
  unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
  
  MENU_ITEM_DATA Item;
  MENU_GetItem(hMin_settings, ID_MENU_MIN_SETTINGS_PRT, &Item);
  Item.pText = menu_option_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data)
    Item.Flags = 0;
  else
    Item.Flags = MENU_IF_DISABLED;
  MENU_SetItem(hMin_settings, ID_MENU_MIN_SETTINGS_PRT, &Item);

  MENU_GetItem(hMin_settings, ID_MENU_MIN_SETTINGS_1, &Item);
  Item.pText = menu_option_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data_1)
    Item.Flags = 0;
  else
    Item.Flags = MENU_IF_DISABLED;
  MENU_SetItem(hMin_settings, ID_MENU_MIN_SETTINGS_1, &Item);

  MENU_GetItem(hOption, ID_MENU_OPTION_LANGUAGE, &Item);
  Item.pText = menu_option_title[4].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data_1)
    Item.Flags = MENU_IF_DISABLED;
  else
    Item.Flags = 0;
  MENU_SetItem(hOption, ID_MENU_OPTION_LANGUAGE, &Item);

  MENU_GetItem(hOption, ID_MENU_OPTION_LCD, &Item);
  Item.pText = menu_option_title[5].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data_1)
    Item.Flags = MENU_IF_DISABLED;
  else
    Item.Flags = 0;
  MENU_SetItem(hOption, ID_MENU_OPTION_LCD, &Item);

  MENU_GetItem(hPasswords, ID_MENU_OPTION_PASSWORD1, &Item);
  Item.pText = menu_option_title[7].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data_1)
    Item.Flags = MENU_IF_DISABLED;
  else
    Item.Flags = 0;
  MENU_SetItem(hPasswords, ID_MENU_OPTION_PASSWORD1, &Item);  

  MENU_GetItem(hPasswords, ID_MENU_OPTION_PASSWORD2, &Item);
  Item.pText = menu_option_title[8].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  if (error_data_1)
    Item.Flags = MENU_IF_DISABLED;
  else
    Item.Flags = 0;
  MENU_SetItem(hPasswords, ID_MENU_OPTION_PASSWORD2, &Item);  

  unsigned int NumItems = MENU_GetNumItems(hCommands);
  for (unsigned int i = 0; i < NumItems; i++)
  {
    MENU_GetItem(hCommands, (ID_MENU_COMMANDS_1 + i), &Item);
    Item.pText = menu_option_title[15 + i].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
    if (error_data | error_data_1)
      Item.Flags = MENU_IF_DISABLED;
    else
      Item.Flags = 0;
    MENU_SetItem(hCommands, (ID_MENU_COMMANDS_1 + i), &Item);
  }
  
  //Pomichajemo vybranu grupu
  NumItems = MENU_GetNumItems(hPickup_Group);
  for (unsigned int i = 0; i < NumItems; i++)
  {
    MENU_GetItem(hPickup_Group, ID_MENU_GROUPS_1 + i, &Item);

    char string_empty[] = " ";
    char string_point[] = "•";
    char new_name[256];
    new_name[0] = '\0';

    if (
        (i == eeprom_prt_tbl.PckpStpm_store_selection) &&
        (error_data == 0)
       )
      strcat_mal(new_name, string_point);
    else
      strcat_mal(new_name, string_empty);
    strcat_mal(new_name, (char *)menu_option_title[10 + i].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

    Item.pText = new_name;

    if (error_data)
      Item.Flags = MENU_IF_DISABLED;
    else
      Item.Flags = 0;

    MENU_SetItem(hPickup_Group, ID_MENU_GROUPS_1 + i, &Item);
  }

  switch (id_panel)
  {
  case ID_EKRAN_MAIN:
    {
      for (unsigned int i = 0; i < ICONVIEW_SIZE; i++) 
      {
        ICONVIEW_SetItemText(iconWin, i, _aBitmapItem[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
      }
      
      break;
    }
  case ID_DIALOG_PASSWORD:
  case ID_DIALOG_PASSWORD_LEVEL_2:
  case ID_DIALOG_PASSWORD_OLD_1:
  case ID_DIALOG_PASSWORD_OLD_2:
  case ID_DIALOG_PASSWORD_NEW_1:
  case ID_DIALOG_PASSWORD_NEW_2:
    {
      WM_HWIN *Dialog_FrameWin, *Dialog_DP_Text, *Dialog_DP_ESC_Button, *Dialog_DP_ENTER_Button;
      unsigned int index;
      char *point_to_typed_password;
      int *point_to_cursor_position_dp;
      switch(id_panel)
      {
      case ID_DIALOG_PASSWORD:
        {
          Dialog_FrameWin = &Dialog_password_FrameWin;
      
          Dialog_DP_Text = &DP_Edit;
      
          Dialog_DP_ESC_Button = &DP_ESC_Button;
      
          Dialog_DP_ENTER_Button = &DP_ENTER_Button;
          
          index = 0;
          point_to_typed_password = typed_password;
          point_to_cursor_position_dp = &cursor_position_dp;

          break;
        }
      case ID_DIALOG_PASSWORD_LEVEL_2:
      case ID_DIALOG_PASSWORD_OLD_1:
      case ID_DIALOG_PASSWORD_OLD_2:
      case ID_DIALOG_PASSWORD_NEW_1:
      case ID_DIALOG_PASSWORD_NEW_2:
        {
          Dialog_FrameWin = &Dialog_password_level_2_FrameWin;
      
          Dialog_DP_Text = &DP_level_2_Edit;
      
          Dialog_DP_ESC_Button = &DP_ESC_level_2_Button;
      
          Dialog_DP_ENTER_Button = &DP_ENTER_level_2_Button;

          index = id_panel - ID_DIALOG_PASSWORD_LEVEL_2;
          point_to_typed_password = typed_password_level_2;
          point_to_cursor_position_dp = &cursor_position_dp_level_2;

          break;
        }
      default:
        {
          while (1);
        }
      }
      WM_SetFocus(*Dialog_FrameWin);

      FRAMEWIN_SetText(*Dialog_FrameWin, Dialog_password_title[index].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DP_ENTER_Button, ENTER_ESC[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DP_ESC_Button, ENTER_ESC[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      Set_Test_and_cursor_into_EDIT(*Dialog_DP_Text, point_to_typed_password, *point_to_cursor_position_dp, 1, '*');
      break;
    }
  case ID_DIALOG_CONFIRMATION:
  case ID_DIALOG_CONFIRMATION_LEVEL_2:
    {
      WM_HWIN *Dialog_FrameWin, *Dialog_DC_Text, *Dialog_DC_ESC_Button, *Dialog_DC_ENTER_Button;
      TITLE *Dialog_message;
      switch(id_panel)
      {
        case ID_DIALOG_CONFIRMATION:
        {
          Dialog_FrameWin = &Dialog_confirmation_FrameWin;
          Dialog_message = &Dialog_confirmation_message;
          Dialog_DC_Text = &DC_Text;
          Dialog_DC_ESC_Button = &DC_ESC_Button;
          Dialog_DC_ENTER_Button = &DC_ENTER_Button;

          break;
        }
      case ID_DIALOG_CONFIRMATION_LEVEL_2:
        {
          Dialog_FrameWin = &Dialog_confirmation_level_2_FrameWin;
          Dialog_message = &Dialog_confirmation_level_2_message;
          Dialog_DC_Text = &DC_level_2_Text;
          Dialog_DC_ESC_Button = &DC_ESC_level_2_Button;
          Dialog_DC_ENTER_Button = &DC_ENTER_level_2_Button;

          break;
        }
      default:
        {
          while (1);
        }
      }
      WM_SetFocus(*Dialog_FrameWin);

      FRAMEWIN_SetText(*Dialog_FrameWin, Dialog_confirmation_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(*Dialog_DC_Text, Dialog_message->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DC_ESC_Button, ENTER_ESC[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DC_ENTER_Button, ENTER_ESC[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      WM_SetFocus(*Dialog_DC_ENTER_Button);

      break;
    }
  case ID_DIALOG_ERROR:
  case ID_DIALOG_ERROR_LEVEL_2:
    {
      WM_HWIN *Dialog_FrameWin, *Dialog_DE_Text, *Dialog_DE_ESC_Button, *Dialog_DE_ENTER_Button;
      TITLE *Dialog_message;
      switch(id_panel)
      {
      case ID_DIALOG_ERROR:
        {
          Dialog_FrameWin = &Dialog_error_FrameWin;
          Dialog_message = &Dialog_error_message;
      
          Dialog_DE_Text = &DE_Text;
      
          Dialog_DE_ESC_Button = &DE_ESC_Button;
      
          Dialog_DE_ENTER_Button = &DE_ENTER_Button;

          switch (previous_level_in_current_level_menu[ID_DIALOG_ERROR])
          {
          case ID_RANK_PG:
          case ID_CONFIG_PG:
            {
              FRAMEWIN_SetText(Dialog_error_FrameWin, rank_msg_title[eeprom_bs_settings_tbl.chLngGUIText]);
              break;
            }
          default:
            {
              FRAMEWIN_SetText(Dialog_error_FrameWin, Dialog_error_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              break;
            }
          }
          
          break;
        }
      case ID_DIALOG_ERROR_LEVEL_2:
        {
          Dialog_FrameWin = &Dialog_error_level_2_FrameWin;
          Dialog_message = &Dialog_error_level_2_message;

          Dialog_DE_Text = &DE_level_2_Text;

          Dialog_DE_ESC_Button = &DE_ESC_level_2_Button;
      
          Dialog_DE_ENTER_Button = &DE_ENTER_level_2_Button;

          FRAMEWIN_SetText(Dialog_error_level_2_FrameWin, Dialog_error_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

          break;
        }
      default:
        {
          while (1);
        }
      }
      
      WM_SetFocus(*Dialog_FrameWin);

      TEXT_SetText(*Dialog_DE_Text, Dialog_message->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DE_ESC_Button, ENTER_ESC[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      BUTTON_SetText(*Dialog_DE_ENTER_Button, ENTER_ESC[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      WM_SetFocus(*Dialog_DE_ENTER_Button);

      break;
    }
  case ID_UNRELIABLE_ERROR:
    {
      WM_HWIN *Dialog_FrameWin, *Dialog_Text, *Dialog_ESC_Button;
      const char *pText, *pTitle;
      switch(id_panel)
      {
        case ID_UNRELIABLE_ERROR:
        {
          Dialog_FrameWin = &Unreliable_error_FrameWin;
          Dialog_Text = &UE_Text;
          Dialog_ESC_Button = &UE_ESC_Button;
      
          pTitle = Unreliable_error_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText];
          pText = Unreliable_error_message.ptitle[eeprom_bs_settings_tbl.chLngGUIText];

          break;
        }
      case ID_UNRELIABLE_ERROR_LEVEL_2:
        {
          Dialog_FrameWin = &Unreliable_error_level_2_FrameWin;
          Dialog_Text = &UE_level_2_Text;
          Dialog_ESC_Button = &UE_ESC_level_2_Button;
      
          pTitle = Unreliable_error_level_2_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText];
          pText = Unreliable_error_level_2_message.ptitle[eeprom_bs_settings_tbl.chLngGUIText];

          break;
        }
      default:
        {
          while (1);
        }
      }
      
      WM_SetFocus(*Dialog_FrameWin);
      FRAMEWIN_SetText(*Dialog_FrameWin, pTitle);
      TEXT_SetText(*Dialog_Text, pText);
      BUTTON_SetText(*Dialog_ESC_Button, ENTER_ESC[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      WM_SetFocus(*Dialog_ESC_Button);

      break;
    }
  case ID_LCD_SETTINGS:
    {
      WM_SetFocus(LCD_Settings_FrameWin);
      FRAMEWIN_SetText(LCD_Settings_FrameWin, LCD_Settings_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(LCD_Settings_t, LCD_Settings_Delay_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(LCD_Settings_d, LCD_Settings_Delay_dimention.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      WM_SetFocus(LCD_Settings_Edit);

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
      switch (current_ekran.index_position)
      {
      case 0:
        {
          unsigned int max_number_pickup_protection;
          WM_HWIN *Protection_Pickup_t, *Protection_Pickup_m;
          const TITLE *Protection_Pickup_title;
          const char* (*Protection_pickup_dimantion)(unsigned int);
      
          switch (id_panel)
          {
          case ID_DZ_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_DZ;
          
              Protection_Pickup_t = DZ_Pickup_t;
              Protection_Pickup_title = DZ_Pickup_title;
            
              Protection_Pickup_m = DZ_Pickup_m;
              Protection_pickup_dimantion = DZ_pickup_dimention;

              break;
            }
          case ID_MTZ_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_MTZ;
          
              Protection_Pickup_t = MTZ_Pickup_t;
              Protection_Pickup_title = MTZ_Pickup_title;
            
              Protection_Pickup_m = MTZ_Pickup_m;
              Protection_pickup_dimantion = MTZ_pickup_dimention;

              break;
            }
          case ID_UMIN_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_UMIN;

              Protection_Pickup_t = Umin_Pickup_t;
              Protection_Pickup_title = Umin_Pickup_title;
            
              Protection_Pickup_m = Umin_Pickup_m;
              Protection_pickup_dimantion = Umin_pickup_dimention;

              break;
            }
          case ID_UMAX_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_UMAX;

              Protection_Pickup_t = Umax_Pickup_t;
              Protection_Pickup_title = Umax_Pickup_title;
            
              Protection_Pickup_m = Umax_Pickup_m;
              Protection_pickup_dimantion = Umax_pickup_dimention;

              break;
            }
          case ID_TZNP_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_TZNP;

              Protection_Pickup_t = TZNP_Pickup_t;
              Protection_Pickup_title = TZNP_Pickup_title;
            
              Protection_Pickup_m = TZNP_Pickup_m;
              Protection_pickup_dimantion = TZNP_pickup_dimention;

              break;
            }
          case ID_ZOP_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_ZOP;

              Protection_Pickup_t = ZOP_Pickup_t;
              Protection_Pickup_title = ZOP_Pickup_title;
            
              Protection_Pickup_m = ZOP_Pickup_m;
              Protection_pickup_dimantion = ZOP_pickup_dimention;

              break;
            }
          case ID_APV_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_APV;

              Protection_Pickup_t = APV_Pickup_t;
              Protection_Pickup_title = APV_Pickup_title;
            
              Protection_Pickup_m = APV_Pickup_m;
              Protection_pickup_dimantion = APV_pickup_dimention;

              break;
            }
          case ID_UROV_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_UROV;

              Protection_Pickup_t = UROV_Pickup_t;
              Protection_Pickup_title = UROV_Pickup_title;
            
              Protection_Pickup_m = UROV_Pickup_m;
              Protection_pickup_dimantion = UROV_pickup_dimention;

              break;
            }
          case ID_CB_PG:
            {
              max_number_pickup_protection = MAX_NUMBER_PICKUP_CB;

              Protection_Pickup_t = CB_Pickup_t;
              Protection_Pickup_title = CB_Pickup_title;
            
              Protection_Pickup_m = CB_Pickup_m;
              Protection_pickup_dimantion = CB_pickup_dimention;

              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          for (unsigned int i = 0; i < max_number_pickup_protection; i++)
          {
            TEXT_SetText(*(Protection_Pickup_t + i),  (Protection_Pickup_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

            const char *p_title = NULL;
            p_title = (*Protection_pickup_dimantion)(i);
            if (p_title != NULL) TEXT_SetText(*(Protection_Pickup_m + i),  p_title);
          }
          
          break;
        }
      case 1:
        {
          unsigned int max_number_delay_protection;
          WM_HWIN *Protection_Delay_t, *Protection_Delay_m;
          const TITLE *Protection_Delay_title;
          unsigned int index_shift = 0;
      
          switch (id_panel)
          {
          case ID_DZ_PG:
            {
              Protection_Delay_t = DZ_Delay_t;
              Protection_Delay_title = DZ_Delay_title;
 
              Protection_Delay_m = DZ_Delay_m;
          
              if (WM_IsVisible(DZ_SubPages_delay[0]))
              {
                max_number_delay_protection = MAX_NUMBER_DELAY_DZ;
              }
              else
              {
                index_shift = MAX_NUMBER_DELAY_DZ;
                max_number_delay_protection = MAX_NUMBER_DELAY_DZ_G;
              }

              break;
            }
          case ID_MTZ_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_MTZ;
          
              Protection_Delay_t = MTZ_Delay_t;
              Protection_Delay_title = MTZ_Delay_title;
           
              Protection_Delay_m = MTZ_Delay_m;

              break;
            }
          case ID_UMIN_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_UMIN;

              Protection_Delay_t = Umin_Delay_t;
              Protection_Delay_title = Umin_Delay_title;
            
              Protection_Delay_m = Umin_Delay_m;

              break;
            }
          case ID_UMAX_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_UMAX;

              Protection_Delay_t = Umax_Delay_t;
              Protection_Delay_title = Umax_Delay_title;
            
              Protection_Delay_m = Umax_Delay_m;

              break;
            }
          case ID_TZNP_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_TZNP;

              Protection_Delay_t = TZNP_Delay_t;
              Protection_Delay_title = TZNP_Delay_title;
            
              Protection_Delay_m = TZNP_Delay_m;

              break;
            }
          case ID_ZOP_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_ZOP;

              Protection_Delay_t = ZOP_Delay_t;
              Protection_Delay_title = ZOP_Delay_title;
            
              Protection_Delay_m = ZOP_Delay_m;

              break;
            }
          case ID_APV_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_APV;

              Protection_Delay_t = APV_Delay_t;
              Protection_Delay_title = APV_Delay_title;
            
              Protection_Delay_m = APV_Delay_m;

              break;
            }
          case ID_UROV_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_UROV;

              Protection_Delay_t = UROV_Delay_t;
              Protection_Delay_title = UROV_Delay_title;
            
              Protection_Delay_m = UROV_Delay_m;

              break;
            }
          case ID_CB_PG:
            {
              max_number_delay_protection = MAX_NUMBER_DELAY_CB;

              Protection_Delay_t = CB_Delay_t;
              Protection_Delay_title = CB_Delay_title;
            
              Protection_Delay_m = CB_Delay_m;

              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          for (unsigned int i = 0; i < max_number_delay_protection; i++)
          {
            TEXT_SetText(*(Protection_Delay_t + index_shift + i),  (Protection_Delay_title + index_shift + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
            TEXT_SetText(*(Protection_Delay_m + index_shift + i),  MEASURES[MEASURES_OF_SECOND].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
          }

          break;
        }
      case 2:
        {
          unsigned int max_number_ctrl_protection;
          WM_HWIN *Protection_State_t, *Protection_State_v;
          const TITLE *Protection_State_title;
          const TITLE* (*Protection_control_info)(unsigned int, int*);
      
          switch (id_panel)
          {
          case ID_DZ_PG:
            {               
              max_number_ctrl_protection = MAX_NUMBER_CTRL_DZ;
          
              Protection_State_t = DZ_State_t;
              Protection_State_title = DZ_State_title;
              Protection_State_v = DZ_State_v;
          
              Protection_control_info = DZ_control_info;

              break;
            }
          case ID_MTZ_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_MTZ;
          
              Protection_State_t = MTZ_State_t;
              Protection_State_title = MTZ_State_title;
              Protection_State_v = MTZ_State_v;
          
              Protection_control_info = MTZ_control_info;

              break;
            }
          case ID_UMIN_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_UMIN;
          
              Protection_State_t = Umin_State_t;
              Protection_State_title = Umin_State_title;
              Protection_State_v = Umin_State_v;

              Protection_control_info = Umin_control_info;

              break;
            }
          case ID_UMAX_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_UMAX;
          
              Protection_State_t = Umax_State_t;
              Protection_State_title = Umax_State_title;
              Protection_State_v = Umax_State_v;

              Protection_control_info = Umax_control_info;

              break;
            }
          case ID_TZNP_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_TZNP;
          
              Protection_State_t = TZNP_State_t;
              Protection_State_title = TZNP_State_title;
              Protection_State_v = TZNP_State_v;

              Protection_control_info = TZNP_control_info;

              break;
            }
          case ID_ZOP_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_ZOP;
          
              Protection_State_t = ZOP_State_t;
              Protection_State_title = ZOP_State_title;
              Protection_State_v = ZOP_State_v;

              Protection_control_info = ZOP_control_info;

              break;
            }
          case ID_APV_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_APV;
          
              Protection_State_t = APV_State_t;
              Protection_State_title = APV_State_title;
              Protection_State_v = APV_State_v;

              Protection_control_info = APV_control_info;

              break;
            }
          case ID_UROV_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_UROV;
          
              Protection_State_t = UROV_State_t;
              Protection_State_title = UROV_State_title;
              Protection_State_v = UROV_State_v;

              Protection_control_info = UROV_control_info;

              break;
            }
          case ID_CB_PG:
            {
              max_number_ctrl_protection = MAX_NUMBER_CTRL_CB;
          
              Protection_State_t = CB_State_t;
              Protection_State_title = CB_State_title;
              Protection_State_v = CB_State_v;

              Protection_control_info = CB_control_info;

              break;
            }
          default:
            {
              //Сюди програма ніколи б не мала зайти
              while(1);
            }
          }

          for (unsigned int i = 0; i < max_number_ctrl_protection; i++)
          {
            TEXT_SetText(*(Protection_State_t + i),  (Protection_State_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
        
            int j_max;
            const TITLE *p_control_list_name;
        
            p_control_list_name = Protection_control_info(i, &j_max);
            for (int j = 0; j < j_max; j++)
            {
              DROPDOWN_DeleteItem(*(Protection_State_v + i), (j + 1)); //Tomu shcho 0-j index je povidomlennja "", jake oznachaje, shcho dani nedostovirni
              DROPDOWN_InsertString(*(Protection_State_v + i), (p_control_list_name + j)->ptitle[eeprom_bs_settings_tbl.chLngGUIText], (j + 1));
            }
          }
          
          break;
        }
      default: break;
      }

      WM_HWIN *Protection_MultiPage_groups, *Protection_MultiPage_type_info;
      unsigned int groups = AMOUNT_SERIES_PPSPM_SETTINGS;
  
      switch (id_panel)
      {
      case ID_DZ_PG:
        {
          Protection_MultiPage_groups = &DZ_MultiPage_groups;
          Protection_MultiPage_type_info = &DZ_MultiPage_type_info;
          break;
        }
      case ID_MTZ_PG:
        {
          Protection_MultiPage_groups = &MTZ_MultiPage_groups;
          Protection_MultiPage_type_info = &MTZ_MultiPage_type_info;
          break;
        }
      case ID_UMIN_PG:
        {
          Protection_MultiPage_groups = &Umin_MultiPage_groups;
          Protection_MultiPage_type_info = &Umin_MultiPage_type_info;
          break;
        }
      case ID_UMAX_PG:
        {
          Protection_MultiPage_groups = &Umax_MultiPage_groups;
          Protection_MultiPage_type_info = &Umax_MultiPage_type_info;
          break;
        }
      case ID_TZNP_PG:
        {
          Protection_MultiPage_groups = &TZNP_MultiPage_groups;
          Protection_MultiPage_type_info = &TZNP_MultiPage_type_info;
          break;
        }
      case ID_ZOP_PG:
        {
          Protection_MultiPage_groups = &ZOP_MultiPage_groups;
          Protection_MultiPage_type_info = &ZOP_MultiPage_type_info;
          break;
        }
      case ID_APV_PG:
        {
          Protection_MultiPage_groups = &APV_MultiPage_groups;
          Protection_MultiPage_type_info = &APV_MultiPage_type_info;
          break;
        }
      case ID_UROV_PG:
        {
          Protection_MultiPage_groups = &UROV_MultiPage_groups;
          Protection_MultiPage_type_info = &UROV_MultiPage_type_info;
          break;
        }
      case ID_CB_PG:
        {
          Protection_MultiPage_groups = &CB_MultiPage_groups;
          Protection_MultiPage_type_info = &CB_MultiPage_type_info;
          groups = 1;
          break;
        }
      default:
        {
          //Сюди програма ніколи б не мала зайти
          while(1);
        }
      }
      
      if (groups > 1)
      {
        for (unsigned int i = 0; i < (groups + 1); i++)
        {
          MULTIPAGE_SetText(*Protection_MultiPage_groups, _MultiPage_groups_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText], i);
        }
      }

      for (unsigned int i = 0; i < MAX_PAGES_PROTECTION_SDC; i++)
      {
        MULTIPAGE_SetText(*Protection_MultiPage_type_info, _MultiPage_type_info_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText], i);
      }
      
      break;
    }
  case ID_SETTINGS_PG:
    {
      for (int i = 0; i < SETTINGS_SIZE; i++)
      {
        ICONVIEW_SetItemText(Settings_IconView, i, _aBitmapItem_settings[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
      }
      
      break;
    }
  case ID_TRANSFORMER_PG:
    {
      TEXT_SetText(Transformer_t[0], Transformer_title[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      for (int i = 0; i < 3; i++)
      {
        DROPDOWN_DeleteItem(Transformer_v[0], (i + 1)); //Tomu shcho 0-j index je povidomlennja "", jake oznachaje, shcho dani nedostovirni
        DROPDOWN_InsertString(Transformer_v[0], Transformer_line_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText], (i + 1));
      }

      TEXT_SetText(Transformer_t[1], Transformer_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(Transformer_t[2], Transformer_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      break;
    }
  case ID_RESURS_PG:
    {
      FRAMEWIN_SetText(Resurs_FrameWin, Resurs_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_RESURS; i++)
      {
        TEXT_SetText(Resurs_t[i], Resurs_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      }
      
      break;
    }
  case ID_COMM_PG:
    {
      for (int i = 0; i < COMM_SIZE; i++)
      {
        ICONVIEW_SetItemText(Comm_IconView, i, _aBitmapItem_Comm[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
      }
      
      break;
    }
  case ID_MODBUS_PG:
    {
      TEXT_SetText(Modbus_t[0], Modbus_title[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      TEXT_SetText(Modbus_t[1], Modbus_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      TEXT_SetText(Modbus_t[2], Modbus_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      for (int i = 0; i < 3; i++)
      {
        DROPDOWN_DeleteItem(Modbus_v[2], (i + 1));
        DROPDOWN_InsertString(Modbus_v[2], Parity_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText], (i + 1));
      }

      TEXT_SetText(Modbus_t[3], Modbus_title[3].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      TEXT_SetText(Modbus_t[4], Modbus_title[4].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(Modbus_d,  Modbus_Timeout_dimention.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      
      break;
    }
  case ID_NET_PG:
    {
      break;
    }
  case ID_CLOCK_PG:
    {
      TEXT_SetText(Clock_t[4], Calibration_title[eeprom_bs_settings_tbl.chLngGUIText]);
      break;
    }
  case ID_TM_PG:
  case ID_DIAGNOSTICS_PG:
    {
      unsigned int number_pages;
      WM_HWIN *Info_n_MultiPage_type_info, *Info_n_FrameWin;
      const LANG_ITEM *Page_name;
      const TITLE *Info_n_panel_title;
      
      __DIAGN state_diagnostyka;

      switch (id_panel)
      {
      case ID_TM_PG:
        {
          number_pages = 2;
          
          Info_n_FrameWin = &TM_FrameWin;
          Info_n_panel_title = &TM_panel_title;
          Info_n_MultiPage_type_info = &TM_MultiPage_type_info;
          Page_name = TM_Page_name;

          switch (current_ekran.index_position)
          {
          case 0:
            {
              HEADER_SetItemText(TM_IO_Header, 0, TM_IO_columns[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              HEADER_SetItemText(TM_IO_Header, 1, TM_IO_columns[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              break;
            }
          case 1:
            {
              HEADER_SetItemText(TM_F_Header, 0, TM_F_columns[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              HEADER_SetItemText(TM_F_Header, 1, TM_F_columns[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              break;
            }
          default: break;
          }
          
          break;
        
        }
      case ID_DIAGNOSTICS_PG:
        {
          GetDiagnfield(&state_diagnostyka);
          
          number_pages = 4;

          Info_n_FrameWin = &Diagnostics_FrameWin;
          Info_n_panel_title = &Diagnostics_panel_title;
          Info_n_MultiPage_type_info = &Diagnostics_MultiPage_type_info;
          Page_name = Diagnostics_Page_name;
          
          break;
        }
      default:
        {
          //Сюди програма ніколи б не мала зайти
          while(1);
        }
      }
      
      FRAMEWIN_SetText(*Info_n_FrameWin, Info_n_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      for (unsigned int i = 0; i < number_pages; i++)
      {
        char title[256];
        title[0] = '\0';
        strcat_mal(title, (char *)Page_name[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);

        if (id_panel == ID_DIAGNOSTICS_PG)
        {
          if (i < (number_pages - 1))
          {
            long *target_array;
            unsigned int number_set_bits = 0;
            if (i == 0)
            {
              target_array = state_diagnostyka.hldrPrgEvtBs.UNBsRamPrgEvts.lArBsPrgEvts;
          
              for (unsigned int j = 0; j < ERROR_BS_FATAL_EROR_LAST_BIT; j++)
              {
                if (target_array[j >> 5] & (1 << (j & 0x1f))) number_set_bits++;
              }
            }
            else if (i == 1)
            {
              target_array = state_diagnostyka.hldrPrgEvtBm.UNBmRamPrgEvts.lArBmPrgEvts;
          
              for (unsigned int j = 0; j < ERROR_BM_FATAL_EROR_LAST_BIT; j++)
              {
                if (target_array[j >> 5] & (1 << (j & 0x1f))) number_set_bits++;
              }
            }
            else 
            {
              target_array = state_diagnostyka.hldrPrgEvtBr.UNBrRamPrgEvts.lArBrPrgEvts;
          
              for (unsigned int j = 0; j < ERROR_BR_FATAL_EROR_LAST_BIT; j++)
              {
                if (target_array[j >> 5] & (1 << (j & 0x1f))) number_set_bits++;
              }
            }
        
            Diagnistics_max_number_bits[i] = number_set_bits;
            
            char number_sting[3 + 3 + 1];
            number_sting[0] = ' ';
            number_sting[1] = '[';
            if (number_set_bits > 1000)
            {
              number_sting[2] = '?';

              number_sting[3] = ']';
              number_sting[4] = '\0';
            }
            else if (number_set_bits > 100)
            {
              number_sting[2] = number_set_bits/100 + 0x30;
              number_set_bits %= 100;

              number_sting[3] = number_set_bits/10 + 0x30;
              number_set_bits %= 10;

              number_sting[4] = number_set_bits + 0x30;

              number_sting[5] = ']';
              number_sting[6] = '\0';
            }
            else if (number_set_bits > 10)
            {
              number_sting[2] = number_set_bits/10 + 0x30;
              number_set_bits %= 10;

              number_sting[3] = number_set_bits + 0x30;

              number_sting[4] = ']';
              number_sting[5] = '\0';
            }
            else
            {
              number_sting[2] = number_set_bits + 0x30;

              number_sting[3] = ']';
              number_sting[4] = '\0';
            }

            strcat_mal(title, number_sting);
          }
        }
        
        MULTIPAGE_SetText(*Info_n_MultiPage_type_info, title, i);
      }
      
      break;
    }
  case ID_ABOUT_PG:
    {
      FRAMEWIN_SetText(About_FrameWin, About_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      TITLE About_Line_x_2_text = {ABOUT_LINE_X_2_UKR, ABOUT_LINE_X_2_RUS, ABOUT_LINE_X_2_ENG};
      char string_point[] = ".";
      char string_1[256], string_2[256];
      string_1[0] = string_2[0] = '\0';
      TITLE About_Line_1_text = {ABOUT_LINE_1_UKR, ABOUT_LINE_1_RUS, ABOUT_LINE_1_ENG};
      strcat_mal(string_1, (char *)About_Line_1_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      unsigned int number_tmp = pDevIdentification.IdentNumberDevice;
      if (int_to_str (number_tmp, string_2)) strcat_mal(string_1, string_2);
      TEXT_SetText(About_Line_1, string_1);

      string_1[0] = string_2[0] = '\0';
      TITLE About_Line_2_1_text = {ABOUT_LINE_2_1_UKR, ABOUT_LINE_2_1_RUS, ABOUT_LINE_2_1_ENG};
      strcat_mal(string_1, (char *)About_Line_2_1_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (int_to_str (pTotVerInfoBs->mVerInfo.ver, string_2))
      {
        strcat_mal(string_1, string_2);
        strcat_mal(string_1, string_point);

        string_2[0] = '\0';
        if (int_to_str (pTotVerInfoBs->mVerInfo.sub_ver, string_2))
        {
          strcat_mal(string_1, string_2);
          strcat_mal(string_1, string_point);

          string_2[0] = '\0';
          if (int_to_str (pTotVerInfoBs->mVerInfo.corr_num, string_2))
          {
            strcat_mal(string_1, string_2);
            strcat_mal(string_1, string_point);

            string_2[0] = '\0';
            if (int_to_str (pTotVerInfoBs->mVerInfo.Bield_num, string_2))
            {
              strcat_mal(string_1, string_2);

              strcat_mal(string_1, (char *)About_Line_x_2_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
        
              unsigned int index = 0;
              while ((string_1[index] != '\0') && (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))) index++;
              if (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))
              {
                for (unsigned int i = 0; i < (sizeof(__DATE__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBs->ArDateStr[i] >= 0x20) ? pTotVerInfoBs->ArDateStr[i] : '?';
                }
                string_1[index++] = ' ';

                for (unsigned int i = 0; i < (sizeof(__TIME__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBs->ArTimeStr[i] >= 0x20) ? pTotVerInfoBs->ArTimeStr[i] : '?';
                }
              }
              string_1[index] = '\0';
            }
          }
        }
      }
      TEXT_SetText(About_Line_2, string_1);

      string_1[0] = string_2[0] = '\0';
      TITLE About_Line_3_1_text = {ABOUT_LINE_3_1_UKR, ABOUT_LINE_3_1_RUS, ABOUT_LINE_3_1_ENG};
      strcat_mal(string_1, (char *)About_Line_3_1_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (int_to_str (pTotVerInfoBm->mVerInfo.ver, string_2))
      {
        strcat_mal(string_1, string_2);
        strcat_mal(string_1, string_point);
  
        string_2[0] = '\0';
        if (int_to_str (pTotVerInfoBm->mVerInfo.sub_ver, string_2))
        {
          strcat_mal(string_1, string_2);
          strcat_mal(string_1, string_point);

          string_2[0] = '\0';
          if (int_to_str (pTotVerInfoBm->mVerInfo.corr_num, string_2))
          {
            strcat_mal(string_1, string_2);
            strcat_mal(string_1, string_point);

            string_2[0] = '\0';
            if (int_to_str (pTotVerInfoBm->mVerInfo.Bield_num, string_2))
            {
              strcat_mal(string_1, string_2);

              strcat_mal(string_1, (char *)About_Line_x_2_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
        
              unsigned int index = 0;
              while ((string_1[index] != '\0') && (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))) index++;
              if (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))
              {
                for (unsigned int i = 0; i < (sizeof(__DATE__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBm->ArDateStr[i] >= 0x20) ? pTotVerInfoBm->ArDateStr[i] : '?';
                }
                string_1[index++] = ' ';

                for (unsigned int i = 0; i < (sizeof(__TIME__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBm->ArTimeStr[i] >= 0x20) ? pTotVerInfoBm->ArTimeStr[i] : '?';
                }
              }
              string_1[index] = '\0';
            }
          }
        }
      }
      TEXT_SetText(About_Line_3, string_1);

      string_1[0] = string_2[0] = '\0';
      TITLE About_Line_4_1_text = {ABOUT_LINE_4_1_UKR, ABOUT_LINE_4_1_RUS, ABOUT_LINE_4_1_ENG};
      strcat_mal(string_1, (char *)About_Line_4_1_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (int_to_str (pTotVerInfoBr->mVerInfo.ver, string_2))
      {
        strcat_mal(string_1, string_2);
        strcat_mal(string_1, string_point);

        string_2[0] = '\0';
        if (int_to_str (pTotVerInfoBr->mVerInfo.sub_ver, string_2))
        {
          strcat_mal(string_1, string_2);
          strcat_mal(string_1, string_point);

          string_2[0] = '\0';
          if (int_to_str (pTotVerInfoBr->mVerInfo.corr_num, string_2))
          {
            strcat_mal(string_1, string_2);
            strcat_mal(string_1, string_point);

            string_2[0] = '\0';
            if (int_to_str (pTotVerInfoBr->mVerInfo.Bield_num, string_2))
            {
              strcat_mal(string_1, string_2);

              strcat_mal(string_1, (char *)About_Line_x_2_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
        
              unsigned int index = 0;
              while ((string_1[index] != '\0') && (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))) index++;
              if (index < (256 - ((sizeof(__DATE__) - 1) + (sizeof(__TIME__) - 1) + 1)))
              {
                for (unsigned int i = 0; i < (sizeof(__DATE__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBr->ArDateStr[i] >= 0x20) ? pTotVerInfoBr->ArDateStr[i] : '?';
                }
                string_1[index++] = ' ';

                for (unsigned int i = 0; i < (sizeof(__TIME__) - 1); i++) 
                {
                  string_1[index++] = (pTotVerInfoBr->ArTimeStr[i] >= 0x20) ? pTotVerInfoBr->ArTimeStr[i] : '?';
                }
              }
              string_1[index] = '\0';
            }
          }
        }
      }
      TEXT_SetText(About_Line_4, string_1);
  

      string_1[0] = string_2[0] = '\0';
      TITLE About_Line_5_1_text = {ABOUT_LINE_5_1_UKR, ABOUT_LINE_5_1_RUS, ABOUT_LINE_5_1_ENG};
      strcat_mal(string_1, (char *)About_Line_5_1_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (int_to_str (BO_MRZV_KP_V1X, string_2))
      {
        strcat_mal(string_1, string_2);
        strcat_mal(string_1, string_point);
        string_2[0] = '\0';
        if (int_to_str (BO_MRZV_KP_VX1, string_2))
        {
          strcat_mal(string_1, string_2);
        }
      }
      TEXT_SetText(About_Line_5, string_1);
    
      string_1[0] = '\0';
      TITLE About_Line_6_text = {ABOUT_LINE_6_UKR, ABOUT_LINE_6_RUS, ABOUT_LINE_6_ENG};
      strcat_mal(string_1, (char *)About_Line_6_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(About_Line_6, string_1);

      string_1[0] = '\0';
      TITLE About_Line_7_text = {ABOUT_LINE_7_UKR, ABOUT_LINE_7_RUS, ABOUT_LINE_7_ENG};
      strcat_mal(string_1, (char *)About_Line_7_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(About_Line_7, string_1);

      string_1[0] = '\0';
      TITLE About_Line_8_text = {ABOUT_LINE_8_UKR, ABOUT_LINE_8_RUS, ABOUT_LINE_8_ENG};
      strcat_mal(string_1, (char *)About_Line_8_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(About_Line_8, string_1);
  
      string_1[0] = '\0';
      TITLE About_Line_9_text = {ABOUT_LINE_9_UKR, ABOUT_LINE_9_RUS, ABOUT_LINE_9_ENG};
      strcat_mal(string_1, (char *)About_Line_9_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(About_Line_9, string_1);
  
      string_1[0] = '\0';
      TITLE About_Line_10_text = {ABOUT_LINE_10_UKR, ABOUT_LINE_10_RUS, ABOUT_LINE_10_ENG};
      strcat_mal(string_1, (char *)About_Line_10_text.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetText(About_Line_10, string_1);

      break;
    }
  case ID_REGISTRATORS_PG:
    {
      FRAMEWIN_SetText(Registrators_FrameWin, Registrators_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      for (unsigned int i = 0; i < 3; i++)
      {
        MULTIPAGE_SetText(Registrators_MultiPage_type, Registrators_MultiPage_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText], i);
      }
      TEXT_SetText(Registrator_number_from, title_from.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

      break;
    }
  default:
    {
      break;
    }
  }
}
/*****************************/
