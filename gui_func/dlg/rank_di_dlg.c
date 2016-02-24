
#include "gui_header.h"
#include "header_mal.h"

static void focus_moving_at_rank_dlg_di() {
  switch(current_ekran.index_position) {
    case 0:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION));
        break;
      }
    case 1:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_SIGNAL_TYPE));
        break;
      }
    case 2:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TYPE));
        break;
      }
    default:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION));
        break;
      }
  }
}

/*********************************************************************
*
*       Обновление статус панели
*/
void update_di_status_panel() {
  if (current_ekran.edition != 0) {
    char explanationText[100] = {0};
    unsigned int i = 0;
    for (; _rankDlgDIItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
      explanationText[i] = _rankDlgDIItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i];
    }
    _CONCAT_STR(explanationText, editModeAdditionalText[eeprom_bs_settings_tbl.chLngGUIText]);
    EDIT_SetText(hEdit, explanationText);
  } else {
    EDIT_SetText(hEdit, _rankDlgDIItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  }
}

/*********************************************************************
*
*       Обновление оглавления диалогового окна
*/
void update_di_title() {
  char titleText[100] = {0};
  unsigned int i = 0;
  for (; _rankDlgDIItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
    titleText[i] = _rankDlgDIItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText][i];
  }
  char numberDIText[3] = {0};
  int numPg = di_index + 1;
  _PARSE_INT_TO_STR(numPg, numberDIText);
  _CONCAT_STR(titleText, numberDIText);
  FRAMEWIN_SetText(rankDlgDIPg, titleText);
}

/*********************************************************************
*
*       Обновление меток диалогового окна
*/
void update_di_labels() {
  TEXT_SetText(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TEXT_LABEL1), durationDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_UNIT), msUnits[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TEXT_LABEL2), signalTypeDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TEXT_LABEL3), typeDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  
  //обновление названий для "тип вх. сигналов" и для "вид входа" в соответствии с выбранным языком
  DROPDOWN_Handle signalTypeDIListBox = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_SIGNAL_TYPE);
  DROPDOWN_Handle typeDIListBox = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TYPE);
  DROPDOWN_DeleteItem(signalTypeDIListBox, 0);
  DROPDOWN_InsertString(signalTypeDIListBox, signalTypesDI0[eeprom_bs_settings_tbl.chLngGUIText], 0);
  DROPDOWN_DeleteItem(signalTypeDIListBox, 1);
  DROPDOWN_InsertString(signalTypeDIListBox, signalTypesDI1[eeprom_bs_settings_tbl.chLngGUIText], 1);
  DROPDOWN_DeleteItem(typeDIListBox, 0);
  DROPDOWN_InsertString(typeDIListBox, typesDI0[eeprom_bs_settings_tbl.chLngGUIText], 0);
  DROPDOWN_DeleteItem(typeDIListBox, 1);
  DROPDOWN_InsertString(typeDIListBox, typesDI1[eeprom_bs_settings_tbl.chLngGUIText], 1);
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

void rank_dlg_di_init() {
  #define WIDTH_DLG     220
  #define HEIGHT_DLG    140

  #define WIDTH_B       65
  #define HEIGHT_B      20
  #define WIDTH_T       90
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
  int y_components = y_textLabel - 3;
  
  TEXT_Handle label1;
  TEXT_Handle label2;
  TEXT_Handle label3;
  
  EDIT_Handle durationDITextField; //текстовое поле для допуска дискр. входов
  DROPDOWN_Handle signalTypeDIListBox; //список для выбора типа входного сигнала
  DROPDOWN_Handle typeDIListBox; //список для выбора вида дискр. входа
  
  TEXT_Handle durationUnit;
  
  BUTTON_Handle ESC_Button_di_rank_dlg;
  BUTTON_Handle ENTER_Button_di_rank_dlg;
  
  rankDlgDIPg = FRAMEWIN_CreateEx(x0, y0, WIDTH_DLG, HEIGHT_DLG, 0, WM_CF_SHOW, 0, win_id_list[ID_RANK_DI_DLG], _rankDlgDIItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText], _cbRankDlgWin);
  FRAMEWIN_SetFont(rankDlgDIPg, &GUI_FontArialBold14_8_Unicode);
  
  label1 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_TEXT_LABEL1, durationDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(label1, &GUI_FontArialBold14_8_Unicode);
  
  durationUnit = TEXT_CreateEx(x_components + WIDTH_COMP + 5, y_textLabel, 20, HEIGHT_T, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_UNIT, msUnits[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(durationUnit, &GUI_FontArialBold14_8_Unicode);
  
  y_textLabel += HEIGHT_T + 10;
  label2 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_TEXT_LABEL2, signalTypeDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(label2, &GUI_FontArialBold14_8_Unicode);
  
  y_textLabel += HEIGHT_T + 10;
  label3 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_TEXT_LABEL3, typeDITextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetFont(label3, &GUI_FontArialBold14_8_Unicode);
  
  durationDITextField = EDIT_CreateEx(x_components, y_components, WIDTH_COMP, HEIGHT_COMP, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_DURATION, RANK_DI_DURATION_VAL_LENGTH);
  EDIT_SetFont(durationDITextField, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetDecMode(durationDITextField, 0, DURATION_MIN_VAL_DI_DIRECT_CURRENT, 99, 0, 0);
  
  y_components += HEIGHT_COMP + 11;
  signalTypeDIListBox = DROPDOWN_CreateEx(x_components, y_components, WIDTH_COMP + 25, HEIGHT_COMP, rankDlgDIPg, WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_RANK_DI_SIGNAL_TYPE);
  DROPDOWN_SetFont(signalTypeDIListBox, &GUI_FontArialStandard14_8_Unicode);
  DROPDOWN_SetBkColor(signalTypeDIListBox, DROPDOWN_CI_UNSEL, GUI_GRAY);
  DROPDOWN_SetBkColor(signalTypeDIListBox, DROPDOWN_CI_SEL, GUI_GRAY);
  DROPDOWN_SetBkColor(signalTypeDIListBox, DROPDOWN_CI_SELFOCUS, GUI_BLUE);
  DROPDOWN_AddString(signalTypeDIListBox, signalTypesDI0[eeprom_bs_settings_tbl.chLngGUIText]);
  DROPDOWN_AddString(signalTypeDIListBox, signalTypesDI1[eeprom_bs_settings_tbl.chLngGUIText]);
  
  y_components += HEIGHT_COMP + 11;
  typeDIListBox = DROPDOWN_CreateEx(x_components, y_components, WIDTH_COMP + 25, HEIGHT_COMP, rankDlgDIPg, WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_RANK_DI_TYPE);
  DROPDOWN_SetFont(typeDIListBox, &GUI_FontArialStandard14_8_Unicode);
  DROPDOWN_SetBkColor(typeDIListBox, DROPDOWN_CI_UNSEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeDIListBox, DROPDOWN_CI_SEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeDIListBox, DROPDOWN_CI_SELFOCUS, GUI_BLUE);
  DROPDOWN_AddString(typeDIListBox, typesDI0[eeprom_bs_settings_tbl.chLngGUIText]);
  DROPDOWN_AddString(typeDIListBox, typesDI1[eeprom_bs_settings_tbl.chLngGUIText]);
  
  ESC_Button_di_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_DLGBUT_ESC);
  BUTTON_SetFont(ESC_Button_di_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ESC_Button_di_rank_dlg, "ESC");
  
  x_b = WIDTH_DLG - (WIDTH_B + 5);
  ENTER_Button_di_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgDIPg, WM_CF_SHOW, 0, ID_RANK_DI_DLGBUT_ENTER);
  BUTTON_SetFont(ENTER_Button_di_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ENTER_Button_di_rank_dlg, "ENTER");
  
  WM_BringToTop(rankDlgDIPg);
  
  #undef WIDTH_DLG
  #undef HEIGHT_DLG

  #undef WIDTH_B
  #undef HEIGHT_B
  #undef WIDTH_T
  #undef HEIGHT_T
  #undef WIDTH_COMP
  #undef HEIGHT_COMP
}

_Bool di_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed) {
  if (current_ekran.edition != 0) {
    if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_MINUS) != 0) {
      _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_MINUS);
      if (
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)
         ) {
        switch (current_ekran.index_position) {
          case 0:
            {
              _Bool directSignal = (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0);
              int min = directSignal ? DURATION_MIN_VAL_DI_DIRECT_CURRENT : DURATION_MIN_VAL_DI_ALTERNATING_CURRENT;
              if (durationDI[di_index] > DURATION_MAX_VAL_DI) {
                current_ekran.edition = 2;
                durationDI[di_index] = DURATION_MAX_VAL_DI;
              } else if (durationDI[di_index] > min) {
                current_ekran.edition = 2;
                if (durationDI[di_index] % DURATION_STEP_VAL_DI > 0) {
                  durationDI[di_index] = (durationDI[di_index] / DURATION_STEP_VAL_DI) * DURATION_STEP_VAL_DI;
                } else {
                  durationDI[di_index] -= DURATION_STEP_VAL_DI;
                }
              }
              return 1;
            }
          case 1:
            {
              if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              }
              break;
            }
          case 2:
            {
              if (_CHECK_BIT_UCHAR(diTypeInput, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              }
              break;
            }
          default: break;
        }
      }
      else (*command_state) |= (1 << error_fixed);
    }
    else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_PLUS) != 0) {
      _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_PLUS);
      if (
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)
         ) {
        switch (current_ekran.index_position) {
          case 0:
            {
              if (durationDI[di_index] < DURATION_MAX_VAL_DI) {
                current_ekran.edition = 2;
                if (durationDI[di_index] % DURATION_STEP_VAL_DI > 0) {
                  durationDI[di_index] = (durationDI[di_index] / DURATION_STEP_VAL_DI) * DURATION_STEP_VAL_DI + DURATION_STEP_VAL_DI;
                } else {
                  durationDI[di_index] += DURATION_STEP_VAL_DI;
                }
              }
              return 1;
            }
          case 1:
            {
              if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              }
              break;
            }
          case 2:
            {
              if (_CHECK_BIT_UCHAR(diTypeInput, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              }
              break;
            }
          default: break;
        }
      }
      else (*command_state) |= (1 << error_fixed);
    }
    else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_LEFT) != 0) {
      _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_LEFT);
      if (
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)
         ) {
        EDIT_Handle durationDITextField = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(durationDITextField, GUI_KEY_LEFT);
              return 1;
            }
          case 1:
            {
              if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              }
              break;
            }
          case 2:
            {
              if (_CHECK_BIT_UCHAR(diTypeInput, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              }
              break;
            }
          default: break;
        }
      }
      else (*command_state) |= (1 << error_fixed);
    }
    else if (_CHECK_KEY_SET_BIT(key_pressed, VK_OFFSET_RIGHT) != 0) {
      _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_RIGHT);
      if (
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)
         ) {
        EDIT_Handle durationDITextField = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(durationDITextField, GUI_KEY_RIGHT);
              return 1;
            }
          case 1:
            {
              if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              }
              break;
            }
          case 2:
            {
              if (_CHECK_BIT_UCHAR(diTypeInput, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              } else if (_CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              }
              break;
            }
          default: break;
        }
      }
      else (*command_state) |= (1 << error_fixed);
    }
    else if (
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_0) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_1) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_2) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_3) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_4) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_5) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_6) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_7) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_8) != 0) ||
             (_CHECK_KEY_SET_BIT(key, VK_OFFSET_9) != 0)
            )   
    {
      unsigned int pressed_0, pressed_1, pressed_2, pressed_3, pressed_4;
      unsigned int pressed_5, pressed_6, pressed_7, pressed_8, pressed_9;

      if (pressed_0 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_0) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_0);

      if (pressed_1 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_1) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_1);

      if (pressed_2 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_2) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_2);

      if (pressed_3 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_3) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_3);

      if (pressed_4 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_4) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_4);

      if (pressed_5 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_5) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_5);

      if (pressed_6 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_6) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_6);

      if (pressed_7 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_7) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_7);

      if (pressed_8 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_8) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_8);

      if (pressed_9 = (_CHECK_KEY_SET_BIT(key, VK_OFFSET_9) != 0))
        _CLEAR_KEY_BIT(key_pressed, VK_OFFSET_9);
      
      if (
          ((pressed_0 + pressed_1 + pressed_2 + pressed_3 + pressed_4 + 
            pressed_5 + pressed_6 + pressed_7 + pressed_8 + pressed_9) == 1) &&
          (key_pressed[0] == 0) &&
          (key_pressed[1] == 0)
         )  
      {
        EDIT_Handle durationDITextField = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION);
        int _key;
        if      (pressed_0 != 0) _key = '0';
        else if (pressed_1 != 0) _key = '1';
        else if (pressed_2 != 0) _key = '2';
        else if (pressed_3 != 0) _key = '3';
        else if (pressed_4 != 0) _key = '4';
        else if (pressed_5 != 0) _key = '5';
        else if (pressed_6 != 0) _key = '6';
        else if (pressed_7 != 0) _key = '7';
        else if (pressed_8 != 0) _key = '8';
        else if (pressed_9 != 0) _key = '9';
        switch (current_ekran.index_position) {
          case 0:
            {
              current_ekran.edition = 2;
              EDIT_AddKey(durationDITextField, _key);
              durationDI[di_index] = EDIT_GetValue(durationDITextField);
              return 1;
            }
          case 1:
            {
              if (_key == '0' && _CHECK_BIT_UCHAR(diTypeSignal, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              } else if (_key == '1' && _CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeSignal, di_index);
                return 1;
              }
              break;
            }
          case 2:
            {
              if (_key == '0' && _CHECK_BIT_UCHAR(diTypeInput, di_index) != 0) {
                current_ekran.edition = 2;
                _CLEAR_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              } else if (_key == '1' && _CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
                current_ekran.edition = 2;
                _SET_BIT_UCHAR(diTypeInput, di_index);
                return 1;
              }
              break;
            }
          default: break;
        }
      } else (*command_state) |= (1 << error_fixed);
    }
  }
  return 0;
}

_Bool durationDIIsCorrect() {
  _Bool directSignal;
  int durationMinVal;
  for (int i = 0; i < NUM_IN; i++) {
    directSignal = (_CHECK_BIT_UCHAR(diTypeSignal, i) == 0);
    durationMinVal = directSignal ? DURATION_MIN_VAL_DI_DIRECT_CURRENT : DURATION_MIN_VAL_DI_ALTERNATING_CURRENT;
    if ((durationDI[i] < durationMinVal)
        || (durationDI[i] > DURATION_MAX_VAL_DI)
        || ((durationDI[i] % DURATION_STEP_VAL_DI) != 0)) {
      return 0;
    }
  }
  return 1;
}

void update_di_settings() {
  focus_moving_at_rank_dlg_di();
  EDIT_Handle durationDITextField = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_DURATION);
  DROPDOWN_Handle signalTypeDIListBox = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_SIGNAL_TYPE);
  DROPDOWN_Handle typeDIListBox = WM_GetDialogItem(rankDlgDIPg, ID_RANK_DI_TYPE);
  
  _Bool directSignal = (_CHECK_BIT_UCHAR(diTypeSignal, di_index) == 0);
  if (directSignal) {
    DROPDOWN_SetSel(signalTypeDIListBox, 0);
  } else {
    DROPDOWN_SetSel(signalTypeDIListBox, 1);
  }
  
  if (_CHECK_BIT_UCHAR(diTypeInput, di_index) == 0) {
    DROPDOWN_SetSel(typeDIListBox, 0);
  } else {
    DROPDOWN_SetSel(typeDIListBox, 1);
  }
  
  if (durationDI[di_index] != EDIT_GetValue(durationDITextField)) {
    EDIT_SetValue(durationDITextField, durationDI[di_index]);
  }
  
  int durationMinVal = directSignal ? DURATION_MIN_VAL_DI_DIRECT_CURRENT : DURATION_MIN_VAL_DI_ALTERNATING_CURRENT;
  if ((durationDI[di_index] >= durationMinVal)
        && (durationDI[di_index] <= DURATION_MAX_VAL_DI)
        && ((durationDI[di_index] % DURATION_STEP_VAL_DI) == 0)) {
    EDIT_SetTextColor(durationDITextField, EDIT_CI_ENABLED, GUI_BLACK);
  } else {
    EDIT_SetTextColor(durationDITextField, EDIT_CI_ENABLED, GUI_RED);
  }
}

