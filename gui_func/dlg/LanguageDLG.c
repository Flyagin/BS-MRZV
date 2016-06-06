#include "header_mal.h"

/*********************************************************************
*
*       _cbLangWin
*/
static void _cbLangWin(WM_MESSAGE * pMsg) {
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
//      hItem = WM_GetDialogItem(pMsg->hWin, lang_id_list[ID_LANG_RADIO]);
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

void lang_dlg_init() {
  int xsize = 144;
  int ysize = 90;
  int x0 = (GUI_X_MAX >> 1) - (xsize >> 1);
  int y0 = (GUI_Y_MAX >> 1) - (ysize >> 1);
  
  langWin = FRAMEWIN_Create("Language", _cbLangWin, WM_CF_SHOW, x0, y0, xsize, ysize);
  
  langRadioButton = RADIO_CreateEx(5, 15, 80, 60, langWin, WM_CF_SHOW, 0, lang_id_list[ID_LANG_RADIO], LANG_LIST_SIZE, 15);
  langButtonOK = BUTTON_CreateAsChild(4, 65, 52, 20, langWin, lang_id_list[ID_LANG_BUTTON_OK], WM_CF_SHOW);
  langButtonCancel = BUTTON_CreateAsChild(81, 65, 58, 20, langWin, lang_id_list[ID_LANG_BUTTON_CANCEL], WM_CF_SHOW);
  
  RADIO_SetFont(langRadioButton, &GUI_FontArialBold14_8_Unicode);
  RADIO_SetText(langRadioButton, "Українська", 0);
  RADIO_SetText(langRadioButton, "Русский", 1);
  RADIO_SetText(langRadioButton, "English", 2);
  
  BUTTON_SetFont(langButtonOK, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(langButtonOK, "ENTER");
  BUTTON_SetFont(langButtonCancel, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(langButtonCancel, "ESC");
  
  RADIO_SetValue(langRadioButton, eeprom_bs_settings_tbl.chLngGUIText);
}

void change_language_next() {
  int index = RADIO_GetValue(langRadioButton);
  if (index >= LANG_LIST_SIZE - 1) {
    index = 0;
  } else {
    index++;
  }
  RADIO_SetValue(langRadioButton, index);
}

void change_language_previous() {
  int index = RADIO_GetValue(langRadioButton);
  if (index <= 0) {
    index = LANG_LIST_SIZE - 1;
  } else {
    index--;
  }
  RADIO_SetValue(langRadioButton, index);
}

void set_current_language(int index_position) {
  if (index_position == ID_LANG_BUTTON_CANCEL) {
    RADIO_SetValue(langRadioButton, eeprom_bs_settings_tbl.chLngGUIText);
  } else {
    change_language = 1;
    eeprom_bs_settings_tbl.chLngGUIText = RADIO_GetValue(langRadioButton);
    _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
  }
}

