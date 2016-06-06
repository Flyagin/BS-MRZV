#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
       _cbProtection_FrameWin
*****************************/
static WM_HWIN focus_Modbus_settings;
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
      case WM_NOTIFICATION_GOT_FOCUS:
        {
          if (focus_Modbus_settings != hObjSrc)
          {
            /*
            Визначаємо координати об'єкта, який сфокусований
            */
            WM_SCROLL_STATE ScrollState;
            WM_GetScrollState(ScrollBar_Modbus, &ScrollState);

            int y_hWinSrc = _y_cbPickup_Modbus + WM_GetWindowOrgY(pMsg->hWinSrc);
            int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
            int y_tmp = y_hWinSrc - y_hWin;
            int v_scroll;
            v_scroll = y_tmp/ScrollState.PageSize;
            v_scroll *= ScrollState.PageSize;
        
            if (_y_cbPickup_Modbus != v_scroll)
            {
              int dy = _y_cbPickup_Modbus - v_scroll;
              for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_MODBUS; i++) 
              {
                WM_MoveWindow(*(Modbus_t + i), 0, dy);
                WM_MoveWindow(*(Modbus_v + i), 0, dy);
              }
              WM_MoveWindow(Modbus_d, 0, dy);
            }
            _y_cbPickup_Modbus = v_scroll;
            focus_Modbus_settings = hObjSrc;
            SCROLLBAR_SetValue(ScrollBar_Modbus, v_scroll);
          }
          break;
        }
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
          if (
              (Id == ID_MODBUS_ADDRESS_VALUE) ||
              (Id == ID_MODBUS_TIMEOUT_VALUE)
             )   
          {
            float value = EDIT_GetFloatValue(hObjSrc);

            int  min = 0, max = 0, value_int;
            unsigned int changer_was_made = false;
            
            switch (Id)
            {
            case ID_MODBUS_ADDRESS_VALUE:
              {
                min = KOEF_ADDRESS_MIN;
                max = KOEF_ADDRESS_MAX;
                value_int = (int)(value);
                if (
                    (current_ekran.edition != 0) &&
                    (edit_settings_1.RS_comm_addres != value_int)
                   )
                {
                  edit_settings_1.RS_comm_addres = value_int;
                  changer_was_made = true;
                }
                break;
              }
            case ID_MODBUS_TIMEOUT_VALUE:
              {
                min = VALUE_TIME_OUT_1_INTERFACE_MIN;
                max = VALUE_TIME_OUT_1_INTERFACE_MAX;
                value_int = (int)(round(value*10.0f));
                if (
                    (current_ekran.edition != 0) &&
                    (edit_settings_1.chTimeOut_RS != value_int)
                   )
                {
                  edit_settings_1.chTimeOut_RS = value_int;
                  changer_was_made = true;
                }
                break;
              }
              default: break;
            }
            
            if (
                (changer_was_made == true) &&
                (current_ekran.edition == 1)
               )    
            {
              //Помічаємо, що дані змінені
              char title[256];
              title[0] = '\0';
              strcat_mal(title, (char *)Modbus_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, "*");
              FRAMEWIN_SetText(Modbus_FrameWin, title);
              current_ekran.edition = 2;
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
Initializacija paneli comunikaciji
*****************************/
void Modbus_panel_show(void)
{
  if (Modbus_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Modbus_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_MODBUS_FRAMEWIN, Modbus_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbProtection_FrameWin);
    FRAMEWIN_SetFont(Modbus_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Modbus_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Modbus_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Modbus_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Modbus_FrameWin, GUI_BLUE);

#define COL_1_X         5
#define ROW_1_Y         10
#define HIGHT_Y         20
#define SHIFT_Y         (ROW_1_Y + HIGHT_Y)
#define WIDTH_X_T       165
#define WIDTH_X_V       60
#define SHIFT_X1        (WIDTH_X_T + 10)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 10)
    
    ScrollBar_Modbus = SCROLLBAR_CreateAttached(WM_GetClientWindow(Modbus_FrameWin), SCROLLBAR_CF_VERTICAL);
    SCROLLBAR_SetNumItems(ScrollBar_Modbus, MAX_NUMBER_ITEMS_MODBUS*SHIFT_Y);
    SCROLLBAR_SetPageSize(ScrollBar_Modbus, 6*SHIFT_Y);

    //Address
    Modbus_t[0] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 0*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_ADDRESS_TITLE,  Modbus_title[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_t[0], &GUI_FontArialStandard14_8_Unicode);
    Modbus_v[0] = EDIT_CreateUser(COL_1_X + SHIFT_X1, ROW_1_Y + 0*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, 0, ID_MODBUS_ADDRESS_VALUE, 3, sizeof(__info_data));
    EDIT_SetFont(Modbus_v[0], &GUI_FontArialStandard14_8_Unicode);

    __info_data info_data;
    int shift = 0, max = KOEF_ADDRESS_MAX, min = 0;

    info_data.extra_param =  0;
    info_data.shift =  shift;
    float _shift = 0.0f;
    for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
    {
      _shift /= 10.0f;
      _shift += 0.9f;
    }

//    int max_tmp = max;
//    float _max = 10;
//    while ( abs(max_tmp /= 10) >= 1) _max *= 10.0f;
//    if (max > 0)
//    {
//      _max = _max - 1 + _shift;
//    }
//    else if (max < 0)
//    {   
//      _max = -(_max / 10);
//    }
//    else _max = 0;
//    info_data.max =  _max;
    float _max = 255; //maksymalne odnobajtne chyslo, bo adresu ob'javleno jak typ char
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
    
    EDIT_SetUserData(Modbus_v[0], &info_data, sizeof(__info_data));
    EDIT_SetFloatMode(Modbus_v[0], 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);

    //Baud Rate
    Modbus_t[1] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_BAUD_RATE_TITLE,  Modbus_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_t[1], &GUI_FontArialStandard14_8_Unicode);
    Modbus_v[1] = DROPDOWN_CreateEx(COL_1_X + SHIFT_X1, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_MODBUS_BAUD_RATE_VALUE);
    DROPDOWN_SetFont(Modbus_v[1], &GUI_FontArialStandard14_8_Unicode);
    DROPDOWN_SetBkColor(Modbus_v[1],DROPDOWN_CI_UNSEL, GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[1],DROPDOWN_CI_SEL,  GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[1],DROPDOWN_CI_SELFOCUS, GUI_BLUE);
    DROPDOWN_AddString(Modbus_v[1], "");
    for (int i = 0; i < 7; i++) DROPDOWN_AddString(Modbus_v[1], Baud_rate_title[i]);

    //Parity
    Modbus_t[2] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_PARITY_TITLE,  Modbus_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_t[2], &GUI_FontArialStandard14_8_Unicode);
    Modbus_v[2] = DROPDOWN_CreateEx(COL_1_X + SHIFT_X1, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_MODBUS_PARITY_VALUE);
    DROPDOWN_SetFont(Modbus_v[2], &GUI_FontArialStandard14_8_Unicode);
    DROPDOWN_SetBkColor(Modbus_v[2],DROPDOWN_CI_UNSEL, GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[2],DROPDOWN_CI_SEL,  GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[2],DROPDOWN_CI_SELFOCUS, GUI_BLUE);
    DROPDOWN_AddString(Modbus_v[2], "");
    for (int i = 0; i < 3; i++) DROPDOWN_AddString(Modbus_v[2], Parity_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

    //Stop bits
    Modbus_t[3] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 3*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_STOP_BITS_TITLE,  Modbus_title[3].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_t[3], &GUI_FontArialStandard14_8_Unicode);
    Modbus_v[3] = DROPDOWN_CreateEx(COL_1_X + SHIFT_X1, ROW_1_Y + 3*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_MODBUS_STOP_BITS_VALUE);
    DROPDOWN_SetFont(Modbus_v[3], &GUI_FontArialStandard14_8_Unicode);
    DROPDOWN_SetBkColor(Modbus_v[3],DROPDOWN_CI_UNSEL, GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[3],DROPDOWN_CI_SEL,  GUI_GRAY);
    DROPDOWN_SetBkColor(Modbus_v[3],DROPDOWN_CI_SELFOCUS, GUI_BLUE);
    DROPDOWN_AddString(Modbus_v[3], "");
    for (int i = 0; i < 2; i++) DROPDOWN_AddString(Modbus_v[3], Stop_bits_title[i]);

    //Time-Out
    Modbus_t[4] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 4*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_TIMEOUT_TITLE,  Modbus_title[4].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_t[4], &GUI_FontArialStandard14_8_Unicode);
    Modbus_v[4] = EDIT_CreateUser(COL_1_X + SHIFT_X1, ROW_1_Y + 4*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, 0, ID_MODBUS_TIMEOUT_VALUE, 5, sizeof(__info_data));
    EDIT_SetFont(Modbus_v[4], &GUI_FontArialStandard14_8_Unicode);

    shift = 1;
    max = VALUE_TIME_OUT_1_INTERFACE_MAX/10;
    min = 0;

    info_data.extra_param =  0;
    info_data.shift =  shift;
    _shift = 0.0f;
    for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
    {
      _shift /= 10.0f;
      _shift += 0.9f;
    }

    int max_tmp = max;
    _max = 10;
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
    
    min_tmp = min;
    _min = 10;
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
    
    EDIT_SetUserData(Modbus_v[4], &info_data, sizeof(__info_data));
    EDIT_SetFloatMode(Modbus_v[4], 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);

    Modbus_d = TEXT_CreateEx(COL_1_X + SHIFT_X2 , ROW_1_Y + 4*SHIFT_Y, 40, HIGHT_Y, WM_GetClientWindow(Modbus_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_MODBUS_TIMEOUT_DIMENSION,  Modbus_Timeout_dimention.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Modbus_d, &GUI_FontArialStandard14_8_Unicode);
    
#undef COL_1_X
#undef ROW_1_Y
#undef HIGHT_Y
#undef SHIFT_Y
#undef WIDTH_X_T
#undef WIDTH_X_V
#undef SHIFT_X1
#undef SHIFT_X2
  }
  
  WM_BringToTop(Modbus_FrameWin);
  WM_ShowWindow(Modbus_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli comunicaciji
*****************************/
void redraw_panel_Modbus(void)
{
  EDIT_SetText(hEdit, _aBitmapItem_Comm[COMM_MODBUS_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  
  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)Modbus_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

  unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
  
  if (error_data_1)
  {
    //Nalashtuvannja nemaje u tablyci nalashtuvan
    strcat_mal(title, (char *)ERROR_MES.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    FRAMEWIN_SetText(Modbus_FrameWin, title);

    FRAMEWIN_SetBarColor(Modbus_FrameWin, 1, GUI_RED);
    FRAMEWIN_SetTextColor(Modbus_FrameWin, GUI_YELLOW);
    
    EDIT_SetText(Modbus_v[0], "");
    DROPDOWN_SetSel(Modbus_v[1], 0);
    DROPDOWN_SetSel(Modbus_v[2], 0);
    DROPDOWN_SetSel(Modbus_v[3], 0);
    EDIT_SetText(Modbus_v[4], "");
  }
  else
  {
    //Nalashtuvannja realno je u tablyci nalashtuvan
    if (current_ekran.edition != 0)
    {
      strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (current_ekran.edition != 1)
      {
        //Помічаємо, що дані змінені
        strcat_mal(title, "*");
      }
    }
    FRAMEWIN_SetText(Modbus_FrameWin, title);
  
    if (current_ekran.edition == 0)
    {
      FRAMEWIN_SetBarColor(Modbus_FrameWin, 1, GUI_GREEN);
      FRAMEWIN_SetTextColor(Modbus_FrameWin, GUI_BLUE);
    }
    else
    {
      FRAMEWIN_SetBarColor(Modbus_FrameWin, 1, GUI_YELLOW);
      FRAMEWIN_SetTextColor(Modbus_FrameWin, GUI_RED);
    }

    AuxCfgTbl1Dsc *point_1;
    if (current_ekran.edition == 0) point_1 = &eeprom_bs_settings_tbl;
    else point_1 = &edit_settings_1;

    __info_data info_data;
    U8 Flags;

    EDIT_GetUserData(Modbus_v[0], &info_data, sizeof(__info_data));
    Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
    if (current_ekran.edition != 0) 
    {
      if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
      else Flags = 0;
    }
    EDIT_SetFloatMode(Modbus_v[0], point_1->RS_comm_addres, info_data.min, info_data.max, info_data.shift, Flags);
    int value_int = point_1->RS_comm_addres;
    if ((value_int >= KOEF_ADDRESS_MIN) && (value_int <= KOEF_ADDRESS_MAX))
    {
      EDIT_SetTextColor(Modbus_v[0], EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(Modbus_v[0], EDIT_CI_ENABLED, GUI_BLACK);
    }
    else
    {
      EDIT_SetTextColor(Modbus_v[0], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Modbus_v[0], EDIT_CI_ENABLED, GUI_RED);
    }
  
    DROPDOWN_SetSel(Modbus_v[1], point_1->chSpeed + 1);
    DROPDOWN_SetSel(Modbus_v[2], point_1->chParityCheck + 1);
    DROPDOWN_SetSel(Modbus_v[3], point_1->chAmtStopBit - 1 + 1);

    EDIT_GetUserData(Modbus_v[4], &info_data, sizeof(__info_data));
    Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
    if (current_ekran.edition != 0) 
    {
      if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
      else Flags = 0;
    }
    EDIT_SetFloatMode(Modbus_v[4], (float)point_1->chTimeOut_RS/10, info_data.min, info_data.max, info_data.shift, Flags);
    value_int = point_1->chTimeOut_RS;
    if ((value_int >= VALUE_TIME_OUT_1_INTERFACE_MIN) && (value_int <= VALUE_TIME_OUT_1_INTERFACE_MAX))
    {
      EDIT_SetTextColor(Modbus_v[4], EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(Modbus_v[4], EDIT_CI_ENABLED, GUI_BLACK);
    }
    else
    {
      EDIT_SetTextColor(Modbus_v[4], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Modbus_v[4], EDIT_CI_ENABLED, GUI_RED);
    }
  }
  
  WM_HWIN FocussedWindow = (Modbus_v[0 + current_ekran.index_position_1]);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_Modbus(AuxCfgTbl1Dsc *point_1)
{
  unsigned int  ok = true;
  if (
      ((point_1->RS_comm_addres >= KOEF_ADDRESS_MIN              ) && (point_1->RS_comm_addres <= KOEF_ADDRESS_MAX              )) &&
      ((point_1->chTimeOut_RS   >= VALUE_TIME_OUT_1_INTERFACE_MIN) && (point_1->chTimeOut_RS   <= VALUE_TIME_OUT_1_INTERFACE_MAX))
     )   
  {
    ok = true;
  }
  else
  {
    ok = false;
  }
  
  return ok;
}
/*****************************/

/*****************************
Копіювання змінених данихз структури для редагування у робочу структуру
*****************************/
void copy_data_Modbus(AuxCfgTbl1Dsc *target, AuxCfgTbl1Dsc *source)
{
  target->RS_comm_addres = source->RS_comm_addres;
  target->chSpeed = source->chSpeed;
  target->chParityCheck = source->chParityCheck;
  target->chAmtStopBit = source->chAmtStopBit;
  target->chTimeOut_RS = source->chTimeOut_RS;
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
