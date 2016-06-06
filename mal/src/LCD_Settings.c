#include "header_mal.h"

/*****************************
       _cbProtection_FrameWin
*****************************/
static void _cbProtection_FrameWin(WM_MESSAGE * pMsg) 
{
  switch (pMsg->MsgId)
  {
  case WM_NOTIFY_PARENT:
    {
      WM_HWIN hObjSrc = pMsg->hWinSrc;
      int Id = WM_GetId(hObjSrc);
      int NCode = pMsg->Data.v;
      
      switch (NCode)
      {
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
          if (Id == ID_LCD_SETTINGS_EDIT)
          {
            float value = EDIT_GetFloatValue(hObjSrc);

            int  min = 0, max = 0, value_int;
            unsigned int changer_was_made = false;
            
            switch (Id)
            {
            case ID_LCD_SETTINGS_EDIT:
              {
                min = TIMEOUT_LCD_MIN;
                max = TIMEOUT_LCD_MAX;
                value_int = (int)(value);
                if (
                    (current_ekran.edition_level_2 != 0) &&
                    (edit_settings_1.chSleepTmVal != value_int)
                   )
                {
                  edit_settings_1.chSleepTmVal = value_int;
                  changer_was_made = true;
                }
                break;
              }
              default: break;
            }
            
            if (
                (changer_was_made == true) &&
                (current_ekran.edition_level_2 == 1)
               )    
            {
              //Помічаємо, що дані змінені
              char title[256];
              title[0] = '\0';
              strcat_mal(title, (char *)LCD_Settings_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, "*");
              FRAMEWIN_SetText(LCD_Settings_FrameWin, title);
              current_ekran.edition_level_2 = 2;
            }
            
            __info_data info_data;
            EDIT_GetUserData(hObjSrc, &info_data, sizeof(__info_data));
            if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) value_int = abs(value_int);
            if ((value_int >= min) && (value_int <= max))
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_BLACK);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_BLACK);
            }
            else
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_RED);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_RED);
            }
          }
          
          break;
        }
      }

      break;
    }
//  case WM_PAINT:
//    {
//      
//      break;
//    }
  default:
    {
      WM_DefaultProc(pMsg);
      break;
    }
  }
}
/*****************************/

/*****************************
Ініціалізація віка стану РКІ
*****************************/
void lcd_settings_show()
{
#define XSIZE_W 250
#define YSIZE_W 60

#define COL_1_X         20
#define ROW_1_Y         10
#define HIGHT_Y         20
#define WIDTH_X_T       70
#define WIDTH_X_V       40
#define SHIFT_X1        (WIDTH_X_T + 10)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 10)
  
  int x0 = (GUI_X_MAX - XSIZE_W) >> 1;
  int y0 = (GUI_Y_MAX - YSIZE_W) >> 1;
  
  
  LCD_Settings_FrameWin = FRAMEWIN_CreateEx(x0, y0, XSIZE_W, YSIZE_W, 0, WM_CF_SHOW, 0, ID_LCD_SETTINGS_FRAMEWIN, LCD_Settings_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbProtection_FrameWin);
  FRAMEWIN_SetFont(LCD_Settings_FrameWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTextAlign(LCD_Settings_FrameWin, GUI_TA_HCENTER);
  FRAMEWIN_SetBarColor(LCD_Settings_FrameWin, 1, GUI_GREEN);
  FRAMEWIN_SetBarColor(LCD_Settings_FrameWin, 0, GUI_LIGHTGRAY);
  FRAMEWIN_SetTextColor(LCD_Settings_FrameWin, GUI_BLUE);

  LCD_Settings_t = TEXT_CreateEx(COL_1_X, ROW_1_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(LCD_Settings_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_LCD_SETTINGS_TITLE,  LCD_Settings_Delay_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(LCD_Settings_t, &GUI_FontArialStandard14_8_Unicode);


  LCD_Settings_Edit = EDIT_CreateUser(COL_1_X + SHIFT_X1, ROW_1_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(LCD_Settings_FrameWin), WM_CF_SHOW, 0, ID_LCD_SETTINGS_EDIT, 2, sizeof(__info_data));
  EDIT_SetFont(LCD_Settings_Edit, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetTextAlign(LCD_Settings_Edit, GUI_TA_LEFT | GUI_TA_VCENTER);

  __info_data info_data;
  int shift = 0, max = TIMEOUT_LCD_MAX, min = 0;

  info_data.extra_param =  0;
  info_data.shift =  shift;
  float _shift = 0.0f;
  for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
  {
    _shift /= 10.0f;
    _shift += 0.9f;
  }

  int max_tmp = max;
  float _max = 10;
  while ( abs(max_tmp /= 10) >= 1) _max *= 10.0f;
  if (max > 0)
  {
    _max = _max - 1 + _shift;
  }
  else if (max < 0)
  {   
    _max = -(_max / 10);
  }
  else _max = 0;
  info_data.max =  _max;
    
  int min_tmp = min;
  float _min = 10;
  while ( abs(min_tmp /= 10) >= 1) _min *= 10.0f;
  if (min > 0)
  {
    _min = (_min / 10);
  }
  else if (min < 0)
  {
    _min = -(_min - 1 + _shift);
  }
  else _min = 0;
  info_data.min =  _min;
    
  EDIT_SetUserData(LCD_Settings_Edit, &info_data, sizeof(__info_data));
  EDIT_SetFloatMode(LCD_Settings_Edit, 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
  
  LCD_Settings_d = TEXT_CreateEx(COL_1_X + SHIFT_X2 , ROW_1_Y, 20, HIGHT_Y, WM_GetClientWindow(LCD_Settings_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_LCD_SETTINGS_DIMENSION,  LCD_Settings_Delay_dimention.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(LCD_Settings_d, &GUI_FontArialStandard14_8_Unicode);

#undef XSIZE_W
#undef YSIZE_W

#undef COL_1_X
#undef ROW_1_Y
#undef HIGHT_Y
#undef WIDTH_X_T
#undef WIDTH_X_V
#undef SHIFT_X1
#undef SHIFT_X2
  
  WM_BringToTop(LCD_Settings_FrameWin);
}
/*****************************/

/*****************************
Peremaljovuvannja paneli comunicaciji
*****************************/
void redraw_panel_lcd_settings(void)
{
  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)LCD_Settings_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

  unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);

  
  if (error_data_1)
  {
    //Nalashtuvannja nemaje u tablyci nalashtuvan
    strcat_mal(title, (char *)ERROR_MES.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    FRAMEWIN_SetText(LCD_Settings_FrameWin, title);

    FRAMEWIN_SetBarColor(LCD_Settings_FrameWin, 1, GUI_RED);
    FRAMEWIN_SetTextColor(LCD_Settings_FrameWin, GUI_YELLOW);
    
    EDIT_SetText(LCD_Settings_Edit, "");
  }
  else
  {
    //Nalashtuvannja realno je u tablyci nalashtuvan
    if (current_ekran.edition_level_2 != 0)
    {
      strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (current_ekran.edition_level_2 != 1)
      {
        //Помічаємо, що дані змінені
        strcat_mal(title, "*");
      }
    }
    FRAMEWIN_SetText(LCD_Settings_FrameWin, title);
  
    if (current_ekran.edition_level_2 == 0)
    {
      FRAMEWIN_SetBarColor(LCD_Settings_FrameWin, 1, GUI_GREEN);
      FRAMEWIN_SetTextColor(LCD_Settings_FrameWin, GUI_BLUE);
    }
    else
    {
      FRAMEWIN_SetBarColor(LCD_Settings_FrameWin, 1, GUI_YELLOW);
      FRAMEWIN_SetTextColor(LCD_Settings_FrameWin, GUI_RED);
    }

    unsigned char *point;
    if (current_ekran.edition_level_2 == 0) 
    {
      point = &eeprom_bs_settings_tbl.chSleepTmVal;
    }
    else
    {
      point = &edit_settings_1.chSleepTmVal;
    }

    __info_data info_data;
    U8 Flags;

    EDIT_GetUserData(LCD_Settings_Edit, &info_data, sizeof(__info_data));
    Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
    if (current_ekran.edition_level_2 != 0) 
    {
      if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
      else Flags = 0;
    }
    EDIT_SetFloatMode(LCD_Settings_Edit, *point, info_data.min, info_data.max, info_data.shift, Flags);
    int value_int = *point;
    if ((value_int >= TIMEOUT_LCD_MIN) && (value_int <= TIMEOUT_LCD_MAX))
    {
      EDIT_SetTextColor(LCD_Settings_Edit, EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(LCD_Settings_Edit, EDIT_CI_ENABLED, GUI_BLACK);
    }
    else
    {
      EDIT_SetTextColor(LCD_Settings_Edit, EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(LCD_Settings_Edit, EDIT_CI_ENABLED, GUI_RED);
    }
  }
  
  WM_HWIN FocussedWindow = (LCD_Settings_Edit);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
extern unsigned int check_pickup_delay_LCD_Settings(unsigned int timeout_tmp)
{
  unsigned int  ok = true;
  if (
      ((timeout_tmp < TIMEOUT_LCD_MIN) || (timeout_tmp > TIMEOUT_LCD_MAX))
     )   
  {
    ok = false;
  }
  
  return ok;
}
/*****************************/
