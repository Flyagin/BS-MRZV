#include "header_mal.h"

#define X0                              0 + 90
#define Y0                              20 + 30
#define X_SIZE                          GUI_X_MAX - 140
#define Y_SIZE                          (GUI_Y_MAX - 40 - 80)

#define LEFT   (1 << 0)
#define MIDDLE (1 << 1)
#define RIGHT  (1 << 2)
#define TOP    (1 << 3)
#define BOTTOM (1 << 4)

#define LIGHTBLUE 0xEE8822

const char *_apData[] = 
{
  "??",
  "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", 
  "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
  "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
  "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
  "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
  "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
  "60", "61", "62", "63", "64", "65", "66", "67", "68", "69",
  "70", "71", "72", "73", "74", "75", "76", "77", "78", "79",
  "80", "81", "82", "83", "84", "85", "86", "87", "88", "89",
  "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"
};

const char *_apMonth[][13] = 
{
  {"??", "Січень" , "Лютий"   , "Березень", "Квітень", "Травень", "Червень", "Липень", "Серпень", "Вересень" , "Жовтень", "Листопад", "Грудень" },
  {"??", "Январь" , "Февраль" , "Март"    , "Апрель" , "Май"    , "Июнь"   , "Июль"  , "Август" , "Сентябрь" , "Октябрь", "Ноябрь"  , "Декабрь" },
  {"??", "January", "February", "March"   , "April"  , "May"    , "June"   , "July"  , "August" , "September", "October", "November", "December"}
}; 

/*****************************
Initializacija paneli daty i chasu
*****************************/
void clock_panel_show(void)
{
  if (Clock_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Clock_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_CLOCK_FRAMEWIN, Clock_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbEmpty);
    FRAMEWIN_SetFont(Clock_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Clock_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Clock_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Clock_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Clock_FrameWin , GUI_BLUE);

#define COL_1_X         25
#define ROW_1_Y         10
#define HIGHT_Y         20
#define SHIFT_Y         (ROW_1_Y + HIGHT_Y)
#define WIDTH_X_T       10
#define WIDTH_X_T_C     90
#define WIDTH_X_V1      20
#define WIDTH_X_V2      60
#define WIDTH_X_V3      30
   
    __info_data info_data;

    //Date
    Clock_v[0] = EDIT_CreateUser(COL_1_X, ROW_1_Y, WIDTH_X_V1, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_DAY, 2, sizeof(__info_data));
    EDIT_SetFont(Clock_v[0], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[0], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[0], 1);
    info_data.min = 1;
    info_data.max = 31;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[0], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[0]);

    Clock_t[0] = TEXT_CreateEx(COL_1_X + WIDTH_X_V1, ROW_1_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, TEXT_CF_HCENTER | TEXT_CF_VCENTER, ID_CLOCK_TEXT_HYPHEN1,  "-");
    TEXT_SetFont(Clock_t[0], &GUI_FontArialStandard14_8_Unicode);
    
    //Month
    Clock_v[1] = EDIT_CreateUser(COL_1_X + WIDTH_X_V1 + WIDTH_X_T, ROW_1_Y, WIDTH_X_V2, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_MONTH, 9, sizeof(__info_data));
    EDIT_SetFont(Clock_v[1], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[1], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[1], 1);
    info_data.min = 1;
    info_data.max = 12;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[1], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[1]);

    Clock_t[1] = TEXT_CreateEx(COL_1_X + WIDTH_X_V1 + WIDTH_X_T + WIDTH_X_V2, ROW_1_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, TEXT_CF_HCENTER | TEXT_CF_VCENTER, ID_CLOCK_TEXT_HYPHEN2,  "-");
    TEXT_SetFont(Clock_t[1], &GUI_FontArialStandard14_8_Unicode);

    //Year
    Clock_v[2] = EDIT_CreateUser(COL_1_X + WIDTH_X_V1 + 2*WIDTH_X_T + WIDTH_X_V2, ROW_1_Y, WIDTH_X_V1, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_YEAR, 2, sizeof(__info_data));
    EDIT_SetFont(Clock_v[2], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[2], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[2], 1);
    info_data.min = 0;
    info_data.max = 99;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[2], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[2]);

    //Hour
    Clock_v[3] = EDIT_CreateUser(COL_1_X, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_V1, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_HOUR, 2, sizeof(__info_data));
    EDIT_SetFont(Clock_v[3], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[3], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[3], 1);
    info_data.min = 0;
    info_data.max = 23;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[3], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[3]);

    Clock_t[2] = TEXT_CreateEx(COL_1_X + WIDTH_X_V1, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, TEXT_CF_HCENTER | TEXT_CF_VCENTER, ID_CLOCK_TEXT_HYPHEN3,  ":");
    TEXT_SetFont(Clock_t[2], &GUI_FontArialStandard14_8_Unicode);

    //Minute
    Clock_v[4] = EDIT_CreateUser(COL_1_X + WIDTH_X_V1 + WIDTH_X_T, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_V1, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_MINUTE, 2, sizeof(__info_data));
    EDIT_SetFont(Clock_v[4], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[4], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[4], 1);
    info_data.min = 0;
    info_data.max = 59;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[4], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[4]);

    Clock_t[3] = TEXT_CreateEx(COL_1_X + 2*WIDTH_X_V1 + WIDTH_X_T, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, TEXT_CF_HCENTER | TEXT_CF_VCENTER, ID_CLOCK_TEXT_HYPHEN4,  ":");
    TEXT_SetFont(Clock_t[3], &GUI_FontArialStandard14_8_Unicode);

    //Second
    Clock_v[5] = EDIT_CreateUser(COL_1_X + 2*WIDTH_X_V1 + 2*WIDTH_X_T, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_V1, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_SECOND, 2, sizeof(__info_data));
    EDIT_SetFont(Clock_v[5], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[5], GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[5], 1);
    info_data.min = 0;
    info_data.max = 59;
    info_data.shift = 0;
    info_data.extra_param =  0;
    EDIT_SetUserData(Clock_v[5], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[5]);  

    //Calibration
    Clock_t[4] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_T_C, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_CLOCK_TEXT_CALIBRATION,  Calibration_title[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Clock_t[4], &GUI_FontArialStandard14_8_Unicode);

    Clock_v[6] = EDIT_CreateUser(COL_1_X + WIDTH_X_T_C, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_V3, HIGHT_Y, WM_GetClientWindow(Clock_FrameWin), WM_CF_SHOW, 0, ID_CLOCK_EDIT_CALIBRATION, 3, sizeof(__info_data));
    EDIT_SetFont(Clock_v[6], &GUI_FontArialStandard14_8_Unicode);
    EDIT_SetTextAlign(Clock_v[6], GUI_TA_LEFT | GUI_TA_VCENTER);
    EDIT_SetInsertMode(Clock_v[6], 1);
    info_data.min = -31;
    info_data.max = 31;
    info_data.shift = 0;
    info_data.extra_param =  FLAG_SIGNED_FATA;
    EDIT_SetUserData(Clock_v[6], &info_data, sizeof(__info_data));
    EDIT_SetTextMode(Clock_v[6]);  
  }
  
  WM_BringToTop(Clock_FrameWin);
  WM_ShowWindow(Clock_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli daty i chasu
*****************************/
void redraw_panel_clock(void)
{
  EDIT_SetText(hEdit, _aBitmapItem[ICONVIEW_CLOCK_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);

  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)Clock_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
  if (current_ekran.edition != 0)
  {
    strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    if (current_ekran.edition != 1)
    {
      //Помічаємо, що дані змінені
      strcat_mal(title, "*");
    }
  }
  FRAMEWIN_SetText(Clock_FrameWin, title);
  
  if (current_ekran.edition == 0)
  {
    FRAMEWIN_SetBarColor(Clock_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetTextColor(Clock_FrameWin, GUI_BLUE);
  }
  else
  {
    FRAMEWIN_SetBarColor(Clock_FrameWin, 1, GUI_YELLOW);
    FRAMEWIN_SetTextColor(Clock_FrameWin, GUI_RED);
  }

  unsigned char *point;
  unsigned char *point_calibr;
  if (current_ekran.edition == 0) 
  {
    if (copying_time == 0)
    {
      point = rtc_time;
      point_calibr = &rtc_calibration;
    }
    else
    {
      point = rtc_time_copy;
      point_calibr = &rtc_calibration_copy;
    }
  }
  else
  {
    point = rtc_time_edit;
    point_calibr = &rtc_calibration_edit;
  }

  __info_data info_data;
  int data_tmp1, data_tmp2, shift;
  const char **s;
  

  for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_CLOCK - 1; i++)
  {
    s = _apData;
    shift = 1;
    switch (i)
    {
    case 0:
      {
        data_tmp1 = point[5];
        break;
      }
    case 1:
      {
        data_tmp1 = point[6];
        s = _apMonth[eeprom_bs_settings_tbl.chLngGUIText];
        shift = 0;
        break;
      }
    case 2:
      {
        data_tmp1 = point[7];
        break;
      }
    case 3:
      {
        data_tmp1 = point[3];
        break;
      }
    case 4:
      {
        data_tmp1 = point[2];
        break;
      }
    case 5:
      {
        data_tmp1 = point[1];
        break;
      }
    default:
      {
        while(1);
      }
    }
    int cursor_position_tmp = EDIT_GetCursorCharPos(Clock_v[i]);
  
    int high_tetrad = data_tmp1 >> 4;
    int low_tetrad = data_tmp1 & 0xf;
    data_tmp2 = 10*high_tetrad + low_tetrad;

    EDIT_GetUserData(Clock_v[i], &info_data, sizeof(__info_data));
    if (
        ((data_tmp2 < (int)info_data.min) || (data_tmp2 > (int)info_data.max)) &&
        (
         (current_ekran.edition != 2) ||
         (
          (
           (i != 1) &&
           ((data_tmp2 < 0) || (data_tmp2 > 99))  
          )
          ||  
          (
           (i == 1) &&
           ((data_tmp2 < 1) || (data_tmp2 > 12))  
          )
         )  
        )   
       )   
    { 
      data_tmp2 = 0;
      shift = 0;
      cursor_position_tmp = 0;
    }
    EDIT_SetText(Clock_v[i], *(s + data_tmp2 + shift));
    if (current_ekran.edition != 2) EDIT_SetCursorAtChar(Clock_v[i], 0);
    else EDIT_SetCursorAtChar(Clock_v[i], cursor_position_tmp);
  }
  
  char calibr_s[] = {'\0','\0','\0','\0',};
  int cursor_position_tmp = EDIT_GetCursorCharPos(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1]);
  data_tmp1 = *point_calibr;
  data_tmp2 = data_tmp1 & 0x1f;
  calibr_s[1] = 0x30+ data_tmp2 / 10;
  calibr_s[2] = 0x30+ data_tmp2 % 10;
  if ((data_tmp1 & 0x20) != 0)
  {
    calibr_s[0] = '+';
  }
  else
  {
    calibr_s[0] = '-';
    data_tmp2 = - data_tmp2;
  }
  EDIT_GetUserData(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], &info_data, sizeof(__info_data));
  if (
      ((data_tmp2 < (int)info_data.min) || (data_tmp2 > (int)info_data.max)) &&
      (
       (current_ekran.edition != 2) ||
       ((data_tmp2 < 0) || (data_tmp2 > 99))  
      )   
     )   
  {
    calibr_s[0] = calibr_s[1] = '?';
    calibr_s[2] = '\0';
    cursor_position_tmp = 1;
  }
  EDIT_SetText(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], calibr_s);
  if (current_ekran.edition != 2) EDIT_SetCursorAtChar(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], 1);
  else EDIT_SetCursorAtChar(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], cursor_position_tmp);

  check_Date_Time_clock(point, point_calibr);
  WM_HWIN FocussedWindow = (Clock_v[0 + current_ekran.index_position_1]);
  if (WM_HasFocus(FocussedWindow) == 0)
  {
    int Pos = (FocussedWindow != Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1]) ? 0 : 1;
    EDIT_SetCursorAtChar(FocussedWindow, Pos);
    WM_SetFocus(FocussedWindow);
  }
  selection_for_Clock(FocussedWindow);
}
/*****************************/

void selection_for_Clock (WM_HWIN hObj)
{
  if (hObj != Clock_v[1])
  {
    int cursor_position = EDIT_GetCursorCharPos(hObj);
    int num_chars = EDIT_GetNumChars(hObj);
    if (
        (cursor_position >= num_chars) &&
        (cursor_position > 0)  
       )   
    {
      EDIT_SetCursorAtChar(hObj, --cursor_position);
    }
    EDIT_SetSel(hObj, cursor_position, cursor_position);
  }
  else
  {
    EDIT_SetSel(hObj, 0, -1);
  }
}

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_Date_Time_clock(unsigned char* p_edit_time, unsigned char* p_edit_calibr)
{
  unsigned int  ok = true;
  
   int value_int[MAX_NUMBER_ITEMS_CLOCK - 1];
  for (unsigned int i = 0; i < (MAX_NUMBER_ITEMS_CLOCK - 1); i++)
  {
    /*перевірка на коректність діапазону дати і часу*/
    int value_bcd, min, max;
    switch (i)
    {
    case 0:
      {
        min = 1;
        max = 31;
        value_bcd = p_edit_time[5];
        break;
      }
    case 1:
      {
        min = 1;
        max = 12;
        value_bcd = p_edit_time[6];
        break;
      }
    case 2:
      {
        min = 0;
        max = 99;
        value_bcd = p_edit_time[7];
        break;
      }
    case 3:
      {
        min = 0;
        max = 23;
        value_bcd = p_edit_time[3];
        break;
      }
    case 4:
      {
        min = 0;
        max = 59;
        value_bcd = p_edit_time[2];
        break;
      }
    case 5:
      {
        min = 0;
        max = 59;
        value_bcd = p_edit_time[1];
        break;
      }
    default: break;
    }
    value_int[i] = (value_bcd >> 4)*10 + (value_bcd & 0xf);
    
    if ((value_int[i] < min) || (value_int[i] > max)) 
    {
      ok = false;
      EDIT_SetTextColor(Clock_v[i], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Clock_v[i], EDIT_CI_ENABLED, GUI_RED);
    }
    else
    {
      EDIT_SetTextColor(Clock_v[i], EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(Clock_v[i], EDIT_CI_ENABLED, GUI_BLACK);
    }
  }
  
  /*Перевірка на коректність калібровочного числа*/
  if (((*p_edit_calibr) & 0x1f) > 31) 
  {
    ok = false;
    EDIT_SetTextColor(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], EDIT_CI_DISABLED, GUI_RED);
    EDIT_SetTextColor(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], EDIT_CI_ENABLED, GUI_RED);
  }
  else
  {
    EDIT_SetTextColor(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], EDIT_CI_DISABLED, GUI_BLACK);
    EDIT_SetTextColor(Clock_v[MAX_NUMBER_ITEMS_CLOCK - 1], EDIT_CI_ENABLED, GUI_BLACK);
  }
  /***/
  
  /*Перевірка на коректність кількості днів у вибраному місяця*/
  int month_tmp = value_int[1];
  int day_of_month_tmp = value_int[0];
  if (
      ((month_tmp == 2) && ((day_of_month_tmp > 29) || (((value_int[2] & 0x3) != 0) && (day_of_month_tmp == 29)))) ||
      ((month_tmp <= 7) && ((month_tmp & 0x1) == 0) && (day_of_month_tmp > 30)) ||
      ((month_tmp >= 8) && ((month_tmp & 0x1) != 0) && (day_of_month_tmp > 30))
     )
  {
    ok = false;

    EDIT_SetTextColor(Clock_v[0], EDIT_CI_DISABLED, GUI_RED);
    EDIT_SetTextColor(Clock_v[0], EDIT_CI_ENABLED, GUI_RED);

    EDIT_SetTextColor(Clock_v[1], EDIT_CI_DISABLED, GUI_RED);
    EDIT_SetTextColor(Clock_v[1], EDIT_CI_ENABLED, GUI_RED);
    
    if ((month_tmp == 2) && (day_of_month_tmp == 29))
    {
      EDIT_SetTextColor(Clock_v[2], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Clock_v[2], EDIT_CI_ENABLED, GUI_RED);
    }
  }
  /***/
  
  return ok;
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
