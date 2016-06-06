#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
       _cbProtection_FrameWin
*****************************/
static WM_HWIN focus_Transformer_settings;
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
          if (focus_Transformer_settings != hObjSrc)
          {
            /*
            Визначаємо координати об'єкта, який сфокусований
            */
            WM_SCROLL_STATE ScrollState;
            WM_GetScrollState(ScrollBar_Transformer, &ScrollState);

            int y_hWinSrc = _y_cbPickup_Transformer + WM_GetWindowOrgY(pMsg->hWinSrc);
            int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
            int y_tmp = y_hWinSrc - y_hWin;
            int v_scroll;
            v_scroll = y_tmp/ScrollState.PageSize;
            v_scroll *= ScrollState.PageSize;
        
            if (_y_cbPickup_Transformer != v_scroll)
            {
              int dy = _y_cbPickup_Transformer - v_scroll;
              for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_TRANSFORMER; i++) 
              {
                WM_MoveWindow(*(Transformer_t + i), 0, dy);
                WM_MoveWindow(*(Transformer_v + i), 0, dy);
              }
            }
            _y_cbPickup_Transformer = v_scroll;
            focus_Transformer_settings = hObjSrc;
            SCROLLBAR_SetValue(ScrollBar_Transformer, v_scroll);
          }
          break;
        }
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
          if (
              (Id == ID_TRANSFORMER_CT_VALUE) ||
              (Id == ID_TRANSFORMER_VT_VALUE)
             )   
          {
            CfgTblDsc *point;
            if (current_ekran.edition == 0) point = &eeprom_prt_tbl;
            else  point = &edit_settings;

            float value = EDIT_GetFloatValue(hObjSrc);

            int  min = 0, max = 0, value_int, *p_value_int_edit;
            unsigned int changer_was_made = false;
            
            switch (Id)
            {
            case ID_TRANSFORMER_CT_VALUE:
              {
                min = KOEF_CT_MIN;
                max = KOEF_CT_MAX;
                p_value_int_edit = (int *)&point->ownrTr_Line.Ktrans_I;
                break;
              }
            case ID_TRANSFORMER_VT_VALUE:
              {
                min = KOEF_VT_MIN;
                max = KOEF_VT_MAX;
                p_value_int_edit = (int *)&point->ownrTr_Line.Ktrans_U;
                break;
              }
              default: break;
            }
            
            value_int = (int)(value);
            if (
                (current_ekran.edition != 0) &&
                (*p_value_int_edit != value_int) &&
                (point == &edit_settings) /*це перестраховка*/
               )
            {
              *p_value_int_edit = value_int;
              changer_was_made = true;
            }
            
            if (
                (changer_was_made == true) &&
                (current_ekran.edition == 1)
               )    
            {
              //Помічаємо, що дані змінені
              char title[256];
              title[0] = '\0';
              strcat_mal(title, (char *)Transformer_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
              strcat_mal(title, "*");
              FRAMEWIN_SetText(Transformer_FrameWin, title);
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
Initializacija paneli nalashtuvan vymirjuvan
*****************************/
void transformer_panel_show(void)
{
  if (Transformer_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Transformer_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_TRANSFORMER_FRAMEWIN, Transformer_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbProtection_FrameWin);
    FRAMEWIN_SetFont(Transformer_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Transformer_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Transformer_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Transformer_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Transformer_FrameWin, GUI_BLUE);

#define COL_1_X         5
#define ROW_1_Y         10
#define HIGHT_Y         20
#define SHIFT_Y         (ROW_1_Y + HIGHT_Y)
#define WIDTH_X_T       165
#define WIDTH_X_V       80
#define SHIFT_X1        (WIDTH_X_T + 10)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 10)
    
    ScrollBar_Transformer = SCROLLBAR_CreateAttached(WM_GetClientWindow(Transformer_FrameWin), SCROLLBAR_CF_VERTICAL);
    SCROLLBAR_SetNumItems(ScrollBar_Transformer, MAX_NUMBER_ITEMS_TRANSFORMER*SHIFT_Y);
    SCROLLBAR_SetPageSize(ScrollBar_Transformer, 6*SHIFT_Y);

    //Linija
    Transformer_t[0] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 0*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_TRANSFORMER_LINIJA_TITLE,  Transformer_title[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Transformer_t[0], &GUI_FontArialStandard14_8_Unicode);
    Transformer_v[0] = DROPDOWN_CreateEx(COL_1_X + SHIFT_X1, ROW_1_Y + 0*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_TRANSFORMER_LINIJA_VALUE);
    DROPDOWN_SetFont(Transformer_v[0], &GUI_FontArialStandard14_8_Unicode);
    DROPDOWN_SetBkColor(Transformer_v[0],DROPDOWN_CI_UNSEL, GUI_GRAY);
    DROPDOWN_SetBkColor(Transformer_v[0],DROPDOWN_CI_SEL,  GUI_GRAY);
    DROPDOWN_SetBkColor(Transformer_v[0],DROPDOWN_CI_SELFOCUS, GUI_BLUE);
    DROPDOWN_AddString(Transformer_v[0], "");
    for (int i = 0; i < 3; i++) DROPDOWN_AddString(Transformer_v[0], Transformer_line_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

    //TT
    Transformer_t[1] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_TRANSFORMER_CT_TITLE,  Transformer_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Transformer_t[1], &GUI_FontArialStandard14_8_Unicode);
    Transformer_v[1] = EDIT_CreateUser(COL_1_X + SHIFT_X1, ROW_1_Y + 1*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, 0, ID_TRANSFORMER_CT_VALUE, 3, sizeof(__info_data));
    EDIT_SetFont(Transformer_v[1], &GUI_FontArialStandard14_8_Unicode);

    {
      __info_data info_data;
      int shift = 0, max = KOEF_CT_MAX, min = 0;

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

      EDIT_SetUserData(Transformer_v[1], &info_data, sizeof(__info_data));
      EDIT_SetFloatMode(Transformer_v[1], 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
    }

    //TН
    Transformer_t[2] = TEXT_CreateEx(COL_1_X, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_TRANSFORMER_VT_TITLE,  Transformer_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Transformer_t[2], &GUI_FontArialStandard14_8_Unicode);
    Transformer_v[2] = EDIT_CreateUser(COL_1_X + SHIFT_X1, ROW_1_Y + 2*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Transformer_FrameWin), WM_CF_SHOW, 0, ID_TRANSFORMER_VT_VALUE, 3, sizeof(__info_data));
    EDIT_SetFont(Transformer_v[2], &GUI_FontArialStandard14_8_Unicode);

    {
      __info_data info_data;
      int shift = 0, max = KOEF_VT_MAX, min = 0;

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
    
      EDIT_SetUserData(Transformer_v[2], &info_data, sizeof(__info_data));
      EDIT_SetFloatMode(Transformer_v[2], 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
    }
    
#undef COL_1_X
#undef ROW_1_Y
#undef HIGHT_Y
#undef SHIFT_Y
#undef WIDTH_X_T
#undef WIDTH_X_V
#undef SHIFT_X1
#undef SHIFT_X2
  }
  
  WM_BringToTop(Transformer_FrameWin);
  WM_ShowWindow(Transformer_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli nalashtuvan vymirjuvan
*****************************/
void redraw_panel_transformer(void)
{
  EDIT_SetText(hEdit, _aBitmapItem_settings[TRANSFORMER_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  
  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)Transformer_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
  
  unsigned int error_data = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);

  if (error_data)
  {
    //Nalashtuvannja nemaje u tablyci nalashtuvan
    strcat_mal(title, (char *)ERROR_MES.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    FRAMEWIN_SetText(Transformer_FrameWin, title);

    FRAMEWIN_SetBarColor(Transformer_FrameWin, 1, GUI_RED);
    FRAMEWIN_SetTextColor(Transformer_FrameWin, GUI_YELLOW);
    
    DROPDOWN_SetSel(Transformer_v[0], 0);
    EDIT_SetText(Transformer_v[1], "");
    EDIT_SetText(Transformer_v[2], "");
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
    FRAMEWIN_SetText(Transformer_FrameWin, title);
  
    if (current_ekran.edition == 0)
    {
      FRAMEWIN_SetBarColor(Transformer_FrameWin, 1, GUI_GREEN);
      FRAMEWIN_SetTextColor(Transformer_FrameWin, GUI_BLUE);
    }
    else
    {
      FRAMEWIN_SetBarColor(Transformer_FrameWin, 1, GUI_YELLOW);
      FRAMEWIN_SetTextColor(Transformer_FrameWin, GUI_RED);
    }

    CfgTblDsc *point;
    if (current_ekran.edition == 0) point = &eeprom_prt_tbl;
    else point = &edit_settings;

    DROPDOWN_SetSel(Transformer_v[0], (point->ownrTr_Line.chLineWGV + 1));

    __info_data info_data;
    U8 Flags;

    //CT
    int value_int = point->ownrTr_Line.Ktrans_I;
    EDIT_GetUserData(Transformer_v[1], &info_data, sizeof(__info_data));
    Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
    if (current_ekran.edition != 0) 
    {
      if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
      else Flags = 0;
    }
    EDIT_SetFloatMode(Transformer_v[1], value_int, info_data.min, info_data.max, info_data.shift, Flags);
    if ((value_int >= KOEF_CT_MIN) && (value_int <= KOEF_CT_MAX))
    {
      EDIT_SetTextColor(Transformer_v[1], EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(Transformer_v[1], EDIT_CI_ENABLED, GUI_BLACK);
    }
    else
    {
      EDIT_SetTextColor(Transformer_v[1], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Transformer_v[1], EDIT_CI_ENABLED, GUI_RED);
    }

    //VT
    value_int = point->ownrTr_Line.Ktrans_U;
    EDIT_GetUserData(Transformer_v[2], &info_data, sizeof(__info_data));
    Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
    if (current_ekran.edition != 0) 
    {
      if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
      else Flags = 0;
    }
    EDIT_SetFloatMode(Transformer_v[2], value_int, info_data.min, info_data.max, info_data.shift, Flags);
    if ((value_int >= KOEF_VT_MIN) && (value_int <= KOEF_VT_MAX))
    {
      EDIT_SetTextColor(Transformer_v[2], EDIT_CI_DISABLED, GUI_BLACK);
      EDIT_SetTextColor(Transformer_v[2], EDIT_CI_ENABLED, GUI_BLACK);
    }
    else
    {
      EDIT_SetTextColor(Transformer_v[2], EDIT_CI_DISABLED, GUI_RED);
      EDIT_SetTextColor(Transformer_v[2], EDIT_CI_ENABLED, GUI_RED);
    }
  }
  
  WM_HWIN FocussedWindow = (Transformer_v[current_ekran.index_position_1]);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_Transformer(CfgTblDsc* point)
{
  unsigned int  ok = true;
  if (
      ((point->ownrTr_Line.Ktrans_I < KOEF_CT_MIN) || (point->ownrTr_Line.Ktrans_I > KOEF_CT_MAX)) ||
      ((point->ownrTr_Line.Ktrans_U < KOEF_VT_MIN) || (point->ownrTr_Line.Ktrans_U > KOEF_VT_MAX))
     )   
  {
    ok = false;
  }
  
  return ok;
}
/*****************************/

/*****************************
Копіювання змінених даних з структури для редагування у робочу структуру
*****************************/
void copy_data_Transformer(CfgTblDsc *target, CfgTblDsc *source)
{
  target->ownrTr_Line = source->ownrTr_Line;
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
