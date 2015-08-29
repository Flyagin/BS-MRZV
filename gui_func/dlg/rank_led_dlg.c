
#include "gui_header.h"
#include "header_mal.h"

/*********************************************************************
*
*       Обновление статус панели
*/
void update_led_status_panel() {
  if (current_ekran.edition != 0) {
    char explanationText[100] = {0};
    unsigned int i = 0;
    for (; _rankDlgLEDItem[0].pExplanation[sel_language][i] != '\0'; i++) {
      explanationText[i] = _rankDlgLEDItem[0].pExplanation[sel_language][i];
    }
    _CONCAT_STR(explanationText, editModeAdditionalText[sel_language]);
    EDIT_SetText(hEdit, explanationText);
  } else {
    EDIT_SetText(hEdit, _rankDlgLEDItem[0].pExplanation[sel_language]);
  }
}

/*********************************************************************
*
*       Обновление оглавления диалогового окна
*/
void update_led_title() {
  char titleText[100] = {0};
  unsigned int i = 0;
  for (; _rankDlgLEDItem[0].pText[sel_language][i] != '\0'; i++) {
    titleText[i] = _rankDlgLEDItem[0].pText[sel_language][i];
  }
  char numberLEDText[3] = {0};
  int numPg = led_index + 1;
  _PARSE_INT_TO_STR(numPg, numberLEDText);
  _CONCAT_STR(titleText, numberLEDText);
  FRAMEWIN_SetText(rankDlgLEDPg, titleText);
}

/*********************************************************************
*
*       Обновление меток диалогового окна
*/
void update_led_labels() {
  TEXT_SetText(WM_GetDialogItem(rankDlgLEDPg, ID_RANK_LED_TEXT_LABEL), typeLEDTextLabels[sel_language]);
  
  DROPDOWN_Handle typeLEDListBox = WM_GetDialogItem(rankDlgLEDPg, ID_RANK_LED_TYPE);
  DROPDOWN_DeleteItem(typeLEDListBox, 0);
  DROPDOWN_InsertString(typeLEDListBox, typesLED0[sel_language], 0);
  DROPDOWN_DeleteItem(typeLEDListBox, 1);
  DROPDOWN_InsertString(typeLEDListBox, typesLED1[sel_language], 1);
}

/*********************************************************************
*
*       _cbRankDlgWin
*/
static void _cbRankDlgWin(WM_MESSAGE * pMsg) {
//  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
//  case WM_INIT_DIALOG:
//    //
//    // Initialization of 'Multipage'
//    //
//    hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIPAGE_0);
//    MULTIPAGE_AddEmptyPage(hItem, 0, "Page");
//    MULTIPAGE_AddEmptyPage(hItem, 0, "Page");
//    // USER START (Optionally insert additional code for further widget initialization)
//    // USER END
//    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case (GUI_ID_USER + 3): // Notifications sent by 'Multipage'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
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
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  case WM_PAINT:
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

void rank_dlg_led_init() {
  #define WIDTH_DLG     185
  #define HEIGHT_DLG    85

  #define WIDTH_B       65
  #define HEIGHT_B      20
  #define WIDTH_T       70
  #define HEIGHT_T      20
  #define WIDTH_COMP    65
  #define HEIGHT_COMP   20
  
  int x0 = (GUI_X_MAX - WIDTH_DLG) >> 1;
  int y0 = (GUI_Y_MAX - HEIGHT_DLG) >> 1;
  
  int x_b = 5;
  int y_b = HEIGHT_DLG - (HEIGHT_B + 5);
  int x_textLabel = x_b;
  int y_textLabel = 30;
  
  int x_components = WIDTH_T + 10;
  
  TEXT_Handle label;
  
  DROPDOWN_Handle typeLEDListBox; //список для выбора вида дискр. выхода
  
  BUTTON_Handle ESC_Button_led_rank_dlg;
  BUTTON_Handle ENTER_Button_led_rank_dlg;
  
  rankDlgLEDPg = FRAMEWIN_CreateEx(x0, y0, WIDTH_DLG, HEIGHT_DLG, 0, WM_CF_SHOW, 0, win_id_list[ID_RANK_LED_DLG], _rankDlgLEDItem[0].pText[sel_language], _cbRankDlgWin);
  FRAMEWIN_SetFont(rankDlgLEDPg, &GUI_FontArialBold14_8_Unicode);
  
  label = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgLEDPg, WM_CF_SHOW, 0, ID_RANK_LED_TEXT_LABEL, typeLEDTextLabels[sel_language]);
  TEXT_SetFont(label, &GUI_FontArialBold14_8_Unicode);
  
  typeLEDListBox = DROPDOWN_CreateEx(x_components, y_textLabel, WIDTH_COMP + 25, HEIGHT_COMP, rankDlgLEDPg, WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_RANK_LED_TYPE);
  DROPDOWN_SetFont(typeLEDListBox, &GUI_FontArialStandard14_8_Unicode);
  DROPDOWN_SetBkColor(typeLEDListBox, DROPDOWN_CI_UNSEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeLEDListBox, DROPDOWN_CI_SEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeLEDListBox, DROPDOWN_CI_SELFOCUS, GUI_BLUE);
  DROPDOWN_AddString(typeLEDListBox, typesLED0[sel_language]);
  DROPDOWN_AddString(typeLEDListBox, typesLED1[sel_language]);
  
  ESC_Button_led_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgLEDPg, WM_CF_SHOW, 0, ID_RANK_LED_DLGBUT_ESC);
  BUTTON_SetFont(ESC_Button_led_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ESC_Button_led_rank_dlg, "ESC");
  
  x_b = WIDTH_DLG - (WIDTH_B + 5);
  ENTER_Button_led_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgLEDPg, WM_CF_SHOW, 0, ID_RANK_LED_DLGBUT_ENTER);
  BUTTON_SetFont(ENTER_Button_led_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ENTER_Button_led_rank_dlg, "ENTER");
  
  WM_BringToTop(rankDlgLEDPg);

  #undef WIDTH_DLG
  #undef HEIGHT_DLG

  #undef WIDTH_B
  #undef HEIGHT_B
  #undef WIDTH_T
  #undef HEIGHT_T
  #undef WIDTH_COMP
  #undef HEIGHT_COMP
}

_Bool led_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed) {
  if (current_ekran.edition != 0) {
    if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0
          || _CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0
          || _CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0
          || _CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0
          || _CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0
          || _CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) {
            
      int _key;
      if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0) _key = VK_OFFSET_MINUS;
      else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0) _key = VK_OFFSET_PLUS;
      else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0) _key = VK_OFFSET_LEFT;
      else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0) _key = VK_OFFSET_RIGHT;
      else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_0) != 0) _key = VK_OFFSET_0;
      else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_1) != 0) _key = VK_OFFSET_1;
      else return 0;
      _CLEAR_KEY_BIT(key_pressed, _key);
      
      if (
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)) {
        current_ekran.edition = 2;
        if (_key == VK_OFFSET_0 || _key == VK_OFFSET_1) {
          if (_key == VK_OFFSET_0 && _CHECK_BIT_UCHAR(ledsType, led_index) != 0) {
            _CLEAR_BIT_UCHAR(ledsType, led_index);
          } else if (_key == VK_OFFSET_1 && _CHECK_BIT_UCHAR(ledsType, led_index) == 0) {
            _SET_BIT_UCHAR(ledsType, led_index);
          }
        } else {
          if (_CHECK_BIT_UCHAR(ledsType, led_index) != 0) {
            _CLEAR_BIT_UCHAR(ledsType, led_index);
          } else {
            _SET_BIT_UCHAR(ledsType, led_index);
          }
        }
        return 1;
      }
      else (*command_state) |= (1 << error_fixed);
    }
  }
  return 0;
}

void update_led_settings() {
  DROPDOWN_Handle typeLEDListBox = WM_GetDialogItem(rankDlgLEDPg, ID_RANK_LED_TYPE);
  
  WM_SetFocus(typeLEDListBox);
  
  if (_CHECK_BIT_UCHAR(ledsType, led_index) == 0) {
    DROPDOWN_SetSel(typeLEDListBox, 0);
  } else {
    DROPDOWN_SetSel(typeLEDListBox, 1);
  }
}

