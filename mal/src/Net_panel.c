#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
       _cbProtection_FrameWin
*****************************/
static WM_HWIN focus_Net_settings;
static void _cbProtection_FrameWin(WM_MESSAGE * pMsg) 
{
  switch (pMsg->MsgId)
  {
  case WM_NOTIFY_PARENT:
    {
      WM_HWIN hObjSrc = pMsg->hWinSrc;
//      int Id = WM_GetId(hObjSrc);
      int NCode = pMsg->Data.v;
      
      switch (NCode)
      {
      case WM_NOTIFICATION_GOT_FOCUS:
        {
          if (focus_Net_settings != hObjSrc)
          {
            /*
            Визначаємо координати об'єкта, який сфокусований
            */
            WM_SCROLL_STATE ScrollState;
            WM_GetScrollState(ScrollBar_Net, &ScrollState);

            int y_hWinSrc = _y_cbPickup_Net + WM_GetWindowOrgY(pMsg->hWinSrc);
            int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
            int y_tmp = y_hWinSrc - y_hWin;
            int v_scroll;
            v_scroll = y_tmp/ScrollState.PageSize;
            v_scroll *= ScrollState.PageSize;
        
            if (_y_cbPickup_Net != v_scroll)
            {
//              int dy = _y_cbPickup_Net - v_scroll;
//              for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_NET; i++) 
//              {
//                WM_MoveWindow(*(Net_t + i), 0, dy);
//                WM_MoveWindow(*(Net_v + i), 0, dy);
//              }
//              WM_MoveWindow(Net_d, 0, dy);
            }
            _y_cbPickup_Net = v_scroll;
            focus_Net_settings = hObjSrc;
            SCROLLBAR_SetValue(ScrollBar_Net, v_scroll);
          }
          break;
        }
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
//          if (
//              (Id == ID_NET_ADDRESS_VALUE) ||
//              (Id == ID_NET_TIMEOUT_VALUE)
//             )   
//          {
//            float value = EDIT_GetFloatValue(hObjSrc);
//
//            int  min = 0, max = 0, value_int;
//            unsigned int changer_was_made = false;
//            
//            switch (Id)
//            {
//            case ID_NET_ADDRESS_VALUE:
//              {
//                min = KOEF_ADDRESS_MIN;
//                max = KOEF_ADDRESS_MAX;
//                value_int = (int)(value);
//                if (
//                    (current_ekran.edition != 0) &&
//                    (edit_settings_1.RS_comm_addres != value_int)
//                   )
//                {
//                  edit_settings_1.RS_comm_addres = value_int;
//                  changer_was_made = true;
//                }
//                break;
//              }
//            case ID_NET_TIMEOUT_VALUE:
//              {
//                min = VALUE_TIME_OUT_1_INTERFACE_MIN;
//                max = VALUE_TIME_OUT_1_INTERFACE_MAX;
//                value_int = (int)(round(value*10.0f));
//                if (
//                    (current_ekran.edition != 0) &&
//                    (edit_settings_1.chTimeOut_RS != value_int)
//                   )
//                {
//                  edit_settings_1.chTimeOut_RS = value_int;
//                  changer_was_made = true;
//                }
//                break;
//              }
//              default: break;
//            }
//            
//            if (
//                (changer_was_made == true) &&
//                (current_ekran.edition == 1)
//               )    
//            {
//              //Помічаємо, що дані змінені
//              char title[256];
//              title[0] = '\0';
//              strcat_mal(title, (char *)Net_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
//              strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
//              strcat_mal(title, "*");
//              FRAMEWIN_SetText(Net_FrameWin, title);
//              current_ekran.edition = 2;
//            }
//            
//            __info_data info_data;
//            EDIT_GetUserData(hObjSrc, &info_data, sizeof(__info_data));
//            if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) value_int = abs(value_int);
//            if ((value_int >= min) && (value_int <= max))
//            {
//              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_BLACK);
//              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_BLACK);
//            }
//            else
//            {
//              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_RED);
//              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_RED);
//            }
//          }
          
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
void Net_panel_show(void)
{
  if (Net_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Net_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_NET_FRAMEWIN, Net_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbProtection_FrameWin);
    FRAMEWIN_SetFont(Net_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Net_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Net_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Net_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Net_FrameWin, GUI_BLUE);
  }
  
  WM_BringToTop(Net_FrameWin);
  WM_ShowWindow(Net_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli comunicaciji
*****************************/
void redraw_panel_Net(void)
{
  EDIT_SetText(hEdit, _aBitmapItem_Comm[COMM_NET_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  
  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)Net_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

  unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
  
  if (error_data_1)
  {
    //Nalashtuvannja nemaje u tablyci nalashtuvan
    strcat_mal(title, (char *)ERROR_MES.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    FRAMEWIN_SetText(Net_FrameWin, title);

    FRAMEWIN_SetBarColor(Net_FrameWin, 1, GUI_RED);
    FRAMEWIN_SetTextColor(Net_FrameWin, GUI_YELLOW);
    
//    EDIT_SetText(Net_v[0], "");
//    DROPDOWN_SetSel(Net_v[1], 0);
//    DROPDOWN_SetSel(Net_v[2], 0);
//    DROPDOWN_SetSel(Net_v[3], 0);
//    EDIT_SetText(Net_v[4], "");
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
    FRAMEWIN_SetText(Net_FrameWin, title);
  
    if (current_ekran.edition == 0)
    {
      FRAMEWIN_SetBarColor(Net_FrameWin, 1, GUI_GREEN);
      FRAMEWIN_SetTextColor(Net_FrameWin, GUI_BLUE);
    }
    else
    {
      FRAMEWIN_SetBarColor(Net_FrameWin, 1, GUI_YELLOW);
      FRAMEWIN_SetTextColor(Net_FrameWin, GUI_RED);
    }

//    AuxCfgTbl1Dsc *point_1;
//    if (current_ekran.edition == 0) point_1 = &eeprom_bs_settings_tbl;
//    else point_1 = &edit_settings_1;
  }
  
//  WM_HWIN FocussedWindow = (Net_v[0 + current_ekran.index_position_1]);
//  WM_SetFocus(FocussedWindow);
}
/*****************************/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_Net(AuxCfgTbl1Dsc *point_1)
{
  unsigned int  ok = true;
  
  return ok;
}
/*****************************/

/*****************************
Копіювання змінених данихз структури для редагування у робочу структуру
*****************************/
void copy_data_Net(AuxCfgTbl1Dsc *target, AuxCfgTbl1Dsc *source)
{
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
