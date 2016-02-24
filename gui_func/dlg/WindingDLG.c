#include "header_mal.h"

const char* pWindingTitle[LANG_LIST_SIZE] = {"Обмотка","Обмотка","Winding"};
const char* pWindingSelection1Title[LANG_LIST_SIZE] = {"Первинна","Первичная","Primary"};
const char* pWindingSelection2Title[LANG_LIST_SIZE] = {"Вторинна","Вторичная","Secondary"};
const char* pButtonEnterTitle[LANG_LIST_SIZE] = {"ТАК","ДА","ENTER"};
const char* pButtonEscTitle[LANG_LIST_SIZE] = {"НІ","НЕТ","ESC"};

/*********************************************************************
*
*       _cbWindingWin
*/

static void _cbWindingWin(WM_MESSAGE * pMsg) {
//  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
    case WM_INIT_DIALOG:
      //
      // Initialization of 'Radio'
      //
//      hItem = WM_GetDialogItem(pMsg->hWin, winding_id_list[ID_WINDING_RADIO]);
//      RADIO_SetText(hItem, "Українська", 0);
//      RADIO_SetText(hItem, "Русский", 1);
//      RADIO_SetText(hItem, "English", 2);
      // USER START (Optionally insert additional code for further widget initialization)
      // USER END
      break;
    case WM_NOTIFY_PARENT:
      Id    = WM_GetId(pMsg->hWinSrc);
      NCode = pMsg->Data.v;
      switch(Id) {
        case GUI_ID_RADIO0: // Notifications sent by 'Radio'
          switch(NCode) {
            case WM_NOTIFICATION_CLICKED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            case WM_NOTIFICATION_RELEASED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            case WM_NOTIFICATION_VALUE_CHANGED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            // USER START (Optionally insert additional code for further notification handling)
            // USER END
          }
          break;
        case GUI_ID_BUTTON0: // Notifications sent by 'OK'
          switch(NCode) {
            case WM_NOTIFICATION_CLICKED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            case WM_NOTIFICATION_RELEASED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            // USER START (Optionally insert additional code for further notification handling)
            // USER END
          }
          break;
        case GUI_ID_BUTTON1: // Notifications sent by 'Cancel'
          switch(NCode) {
            case WM_NOTIFICATION_CLICKED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            case WM_NOTIFICATION_RELEASED:
              // USER START (Optionally insert code for reacting on notification message)
              // USER END
              break;
            // USER START (Optionally insert additional code for further notification handling)
            // USER END
          }
          break;
        // USER START (Optionally insert additional code for further Ids)
        // USER END
      }
      break;
    // USER START (Optionally insert additional message handling)
    // USER END
    default:
      WM_DefaultProc(pMsg);
      break;
  }
}

void winding_dlg_init() {
  int xsize = 144;
  int ysize = 87;
  int x0 = (GUI_X_MAX >> 1) - (xsize >> 1);
  int y0 = (GUI_Y_MAX >> 1) - (ysize >> 1);
  
  windingWin = FRAMEWIN_Create(pWindingTitle[eeprom_bs_settings_tbl.chLngGUIText], _cbWindingWin, WM_CF_SHOW, x0, y0, xsize, ysize);
  FRAMEWIN_SetFont(windingWin, &GUI_FontArialBold14_8_Unicode);
  
  windingRadioButton = RADIO_CreateEx(5, 22, 90, 60, windingWin, WM_CF_SHOW, 0, winding_id_list[ID_WINDING_RADIO], 2, 15);
  windingButtonOK = BUTTON_CreateAsChild(4, 62, 52, 20, windingWin, winding_id_list[ID_WINDING_BUTTON_OK], WM_CF_SHOW);
  windingButtonCancel = BUTTON_CreateAsChild(81, 62, 58, 20, windingWin, winding_id_list[ID_WINDING_BUTTON_CANCEL], WM_CF_SHOW);
  
  RADIO_SetFont(windingRadioButton, &GUI_FontArialBold14_8_Unicode);
  RADIO_SetText(windingRadioButton, pWindingSelection1Title[eeprom_bs_settings_tbl.chLngGUIText], 0);
  RADIO_SetText(windingRadioButton, pWindingSelection2Title[eeprom_bs_settings_tbl.chLngGUIText], 1);
  
  BUTTON_SetFont(windingButtonOK, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(windingButtonOK, pButtonEnterTitle[eeprom_bs_settings_tbl.chLngGUIText]);
  BUTTON_SetFont(windingButtonCancel, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(windingButtonCancel, pButtonEscTitle[eeprom_bs_settings_tbl.chLngGUIText]);
  
  RADIO_SetValue(windingRadioButton, eeprom_bs_settings_tbl.chWinding);
}

void change_winding_next() {
  int index = RADIO_GetValue(windingRadioButton);
  if (index >= 1) {
    index = 0;
  } else {
    index++;
  }
  RADIO_SetValue(windingRadioButton, index);
}

void change_winding_previous() {
  int index = RADIO_GetValue(windingRadioButton);
  if (index <= 0) {
    index = 1;
  } else {
    index--;
  }
  RADIO_SetValue(windingRadioButton, index);
}

void set_current_winding(int index_position) {
  if (index_position == ID_WINDING_BUTTON_CANCEL) {
    RADIO_SetValue(windingRadioButton, eeprom_bs_settings_tbl.chWinding);
  } else {
    eeprom_bs_settings_tbl.chWinding = RADIO_GetValue(windingRadioButton);
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
  }
}

