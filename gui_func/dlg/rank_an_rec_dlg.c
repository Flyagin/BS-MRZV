
#include "gui_header.h"
#include "header_mal.h"

static void focus_moving_at_rank_dlg_an_rec() {
  switch(current_ekran.index_position) {
    case 0:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT));
        break;
      }
    case 1:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_POST_FOULT));
        break;
      }
    default:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT));
        break;
      }
  }
}

/*********************************************************************
*
*       Обновление статус панели
*/
void update_an_rec_status_panel() {
  if (current_ekran.edition != 0) {
    char explanationText[100] = {0};
    unsigned int i = 0;
    for (; _rankDlgAnRecItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
      explanationText[i] = _rankDlgAnRecItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i];
    }
    _CONCAT_STR(explanationText, editModeAdditionalText[eeprom_bs_settings_tbl.chLngGUIText]);
    EDIT_SetText(hEdit, explanationText);
  } else {
    EDIT_SetText(hEdit, _rankDlgAnRecItem[0].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  }
}

/*********************************************************************
*
*       Обновление оглавления диалогового окна
*/
void update_an_rec_title() {
  char titleText[100] = {0};
  unsigned int i = 0;
  for (; _rankDlgAnRecItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
    titleText[i] = _rankDlgAnRecItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText][i];
  }
  FRAMEWIN_SetText(rankDlgAnRecPg, titleText);
}

/*********************************************************************
*
*       Обновление меток диалогового окна
*/
void update_an_rec_labels() {
  TEXT_SetText(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TEXT_LABEL1), timePreFaultArrTextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_UNIT1), secUnits[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TEXT_LABEL2), timePostFaultArrTextLabels[eeprom_bs_settings_tbl.chLngGUIText]);
  TEXT_SetText(WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_UNIT2), secUnits[eeprom_bs_settings_tbl.chLngGUIText]);
}

/*********************************************************************
*
*       _cbRankDlgWin
*/
static void _cbRankDlgWin(WM_MESSAGE * pMsg) {
  int     NCode;
  int     Id;
  switch (pMsg->MsgId) {
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case (GUI_ID_USER + 3):
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    }
    break;
  case WM_PAINT:
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

void rank_dlg_an_rec_init() {
  #define WIDTH_DLG     220
  #define HEIGHT_DLG    110

  #define WIDTH_B       65
  #define HEIGHT_B      20
  #define WIDTH_T       110
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
  
  EDIT_Handle timePreFaultArrTextField; //текстовое поле для введения уставок доавар. массива
  EDIT_Handle timePostFaultArrTextField; //текстовое поле для введения уставок послеавар. массива
  
  TEXT_Handle timePreFaultArrUnit;
  TEXT_Handle timePostFaultArrUnit;
  
  BUTTON_Handle ESC_Button_an_rec_rank_dlg;
  BUTTON_Handle ENTER_Button_an_rec_rank_dlg;
  
  rankDlgAnRecPg = FRAMEWIN_CreateEx(
    x0, y0,
    WIDTH_DLG, HEIGHT_DLG,
    0,
    WM_CF_SHOW,
    0,
    win_id_list[ID_RANK_AN_REC_DLG],
    _rankDlgAnRecItem[0].pText[eeprom_bs_settings_tbl.chLngGUIText],
    _cbRankDlgWin
  );
  FRAMEWIN_SetFont(rankDlgAnRecPg, &GUI_FontArialBold14_8_Unicode);
  
  label1 = TEXT_CreateEx(
    x_textLabel, y_textLabel,
    WIDTH_T, HEIGHT_T,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_TEXT_LABEL1,
    timePreFaultArrTextLabels[eeprom_bs_settings_tbl.chLngGUIText]
  );
  TEXT_SetFont(label1, &GUI_FontArialBold14_8_Unicode);
  
  timePreFaultArrUnit = TEXT_CreateEx(
    x_components + WIDTH_COMP + 5, y_textLabel,
    20, HEIGHT_T,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_UNIT1,
    msUnits[eeprom_bs_settings_tbl.chLngGUIText]
  );
  TEXT_SetFont(timePreFaultArrUnit, &GUI_FontArialBold14_8_Unicode);
  
  y_textLabel += HEIGHT_T + 10;
  label2 = TEXT_CreateEx(
    x_textLabel, y_textLabel,
    WIDTH_T, HEIGHT_T,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_TEXT_LABEL2,
    timePostFaultArrTextLabels[eeprom_bs_settings_tbl.chLngGUIText]
  );
  TEXT_SetFont(label2, &GUI_FontArialBold14_8_Unicode);
  
  timePostFaultArrUnit = TEXT_CreateEx(
    x_components + WIDTH_COMP + 5, y_textLabel,
    20, HEIGHT_T,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_UNIT2,
    msUnits[eeprom_bs_settings_tbl.chLngGUIText]
  );
  TEXT_SetFont(timePostFaultArrUnit, &GUI_FontArialBold14_8_Unicode);
  
  timePreFaultArrTextField = EDIT_CreateEx(
    x_components, y_components,
    WIDTH_COMP, HEIGHT_COMP,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_TIME_PRE_FOULT,
    RANK_AN_REC_TIME_PREFAULT_ARR_VAL_LENGTH
  );
  EDIT_SetFont(timePreFaultArrTextField, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetFloatMode(
    timePreFaultArrTextField,
    (float) MIN_TIME_PREFAULT_ARR_AN_REC / RANK_AN_REC_DIVIDER,
    0,
    99.99f,
    2,
    GUI_EDIT_SUPPRESS_LEADING_ZEROES
  );
  
  y_components += HEIGHT_COMP + 11;
  timePostFaultArrTextField = EDIT_CreateEx(
    x_components, y_components,
    WIDTH_COMP, HEIGHT_COMP,
    rankDlgAnRecPg,
    WM_CF_SHOW,
    0,
    ID_RANK_AN_REC_TIME_POST_FOULT,
    RANK_AN_REC_TIME_POSTFAULT_ARR_VAL_LENGTH
  );
  EDIT_SetFont(timePostFaultArrTextField, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetFloatMode(
    timePostFaultArrTextField,
    (float) MIN_TIME_POSTFAULT_ARR_AN_REC / RANK_AN_REC_DIVIDER,
    0,
    99.99f,
    2,
    GUI_EDIT_SUPPRESS_LEADING_ZEROES
  );
    
  ESC_Button_an_rec_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgAnRecPg, WM_CF_SHOW, 0, ID_RANK_AN_REC_DLGBUT_ESC);
  BUTTON_SetFont(ESC_Button_an_rec_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ESC_Button_an_rec_rank_dlg, "ESC");
  
  x_b = WIDTH_DLG - (WIDTH_B + 5);
  ENTER_Button_an_rec_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgAnRecPg, WM_CF_SHOW, 0, ID_RANK_AN_REC_DLGBUT_ENTER);
  BUTTON_SetFont(ENTER_Button_an_rec_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ENTER_Button_an_rec_rank_dlg, "ENTER");
  
  WM_BringToTop(rankDlgAnRecPg);

  #undef WIDTH_DLG
  #undef HEIGHT_DLG

  #undef WIDTH_B
  #undef HEIGHT_B
  #undef WIDTH_T
  #undef HEIGHT_T
  #undef WIDTH_COMP
  #undef HEIGHT_COMP
}

_Bool an_rec_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed) {
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
              if (timePreFaultArrVal > MAX_TIME_PREFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                timePreFaultArrVal = MAX_TIME_PREFAULT_ARR_AN_REC;
              } else if (timePreFaultArrVal > MIN_TIME_PREFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                if (timePreFaultArrVal % TIME_PREFAULT_ARR_STEP_AN_REC > 0) {
                  timePreFaultArrVal = (timePreFaultArrVal / TIME_PREFAULT_ARR_STEP_AN_REC) * TIME_PREFAULT_ARR_STEP_AN_REC;
                } else {
                  timePreFaultArrVal -= TIME_PREFAULT_ARR_STEP_AN_REC;
                }
              }
              return 1;
            }
          case 1:
            {
              if (timePostFaultArrVal > MAX_TIME_POSTFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                timePostFaultArrVal = MAX_TIME_POSTFAULT_ARR_AN_REC;
              } else if (timePostFaultArrVal > MIN_TIME_POSTFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                if (timePostFaultArrVal % TIME_POSTFAULT_ARR_STEP_AN_REC > 0) {
                  timePostFaultArrVal = (timePostFaultArrVal / TIME_POSTFAULT_ARR_STEP_AN_REC) * TIME_POSTFAULT_ARR_STEP_AN_REC;
                } else {
                  timePostFaultArrVal -= TIME_POSTFAULT_ARR_STEP_AN_REC;
                }
              }
              return 1;
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
              if (timePreFaultArrVal < MAX_TIME_PREFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                if (timePreFaultArrVal % TIME_PREFAULT_ARR_STEP_AN_REC > 0) {
                  timePreFaultArrVal = (timePreFaultArrVal / TIME_PREFAULT_ARR_STEP_AN_REC) * TIME_PREFAULT_ARR_STEP_AN_REC + TIME_PREFAULT_ARR_STEP_AN_REC;
                } else {
                  timePreFaultArrVal += TIME_PREFAULT_ARR_STEP_AN_REC;
                }
              }
              return 1;
            }
          case 1:
            {
              if (timePostFaultArrVal < MAX_TIME_POSTFAULT_ARR_AN_REC) {
                current_ekran.edition = 2;
                if (timePostFaultArrVal % TIME_POSTFAULT_ARR_STEP_AN_REC > 0) {
                  timePostFaultArrVal = (timePostFaultArrVal / TIME_POSTFAULT_ARR_STEP_AN_REC) * TIME_POSTFAULT_ARR_STEP_AN_REC + TIME_POSTFAULT_ARR_STEP_AN_REC;
                } else {
                  timePostFaultArrVal += TIME_POSTFAULT_ARR_STEP_AN_REC;
                }
              }
              return 1;
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
        EDIT_Handle timePreFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT);
        EDIT_Handle timePostFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_POST_FOULT);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(timePreFaultArrTextField, GUI_KEY_LEFT);
              return 1;
            }
          case 1:
            {
              EDIT_AddKey(timePostFaultArrTextField, GUI_KEY_LEFT);
              return 1;
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
        EDIT_Handle timePreFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT);
        EDIT_Handle timePostFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_POST_FOULT);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(timePreFaultArrTextField, GUI_KEY_RIGHT);
              return 1;
            }
          case 1:
            {
              EDIT_AddKey(timePostFaultArrTextField, GUI_KEY_RIGHT);
              return 1;
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
        EDIT_Handle timePreFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT);
        EDIT_Handle timePostFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_POST_FOULT);
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
              EDIT_AddKey(timePreFaultArrTextField, _key);
              timePreFaultArrVal = (long) (EDIT_GetFloatValue(timePreFaultArrTextField) * RANK_AN_REC_DIVIDER);
              return 1;
            }
          case 1:
            {
              current_ekran.edition = 2;
              EDIT_AddKey(timePostFaultArrTextField, _key);
              timePostFaultArrVal = (long) (EDIT_GetFloatValue(timePostFaultArrTextField) * RANK_AN_REC_DIVIDER);
              return 1;
            }
          default: break;
        }
      } else (*command_state) |= (1 << error_fixed);
    }
  }
  return 0;
}

_Bool timePreFaultAnRecIsCorrect() {
  if ((timePreFaultArrVal < MIN_TIME_PREFAULT_ARR_AN_REC)
      || (timePreFaultArrVal > MAX_TIME_PREFAULT_ARR_AN_REC)
      || ((timePreFaultArrVal % TIME_PREFAULT_ARR_STEP_AN_REC) != 0)) {
    return 0;
  } else {
    return 1; //correct
  }
}

_Bool timePostFaultAnRecIsCorrect() {
  if ((timePostFaultArrVal < MIN_TIME_POSTFAULT_ARR_AN_REC)
      || (timePostFaultArrVal > MAX_TIME_POSTFAULT_ARR_AN_REC)
      || ((timePostFaultArrVal % TIME_POSTFAULT_ARR_STEP_AN_REC) != 0)) {
    return 0;
  } else {
    return 1; //correct
  }
}

void update_an_rec_settings() {
  focus_moving_at_rank_dlg_an_rec();
  
  EDIT_Handle timePreFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_PRE_FOULT);
  EDIT_Handle timePostFaultArrTextField = WM_GetDialogItem(rankDlgAnRecPg, ID_RANK_AN_REC_TIME_POST_FOULT);
  
  if (timePreFaultArrVal != (long) (EDIT_GetFloatValue(timePreFaultArrTextField) * RANK_AN_REC_DIVIDER)) {
    EDIT_SetFloatValue(timePreFaultArrTextField, (float) timePreFaultArrVal / RANK_AN_REC_DIVIDER);
  }
  
  if (timePostFaultArrVal != (long) (EDIT_GetFloatValue(timePostFaultArrTextField) * RANK_AN_REC_DIVIDER)) {
    EDIT_SetFloatValue(timePostFaultArrTextField, (float) timePostFaultArrVal / RANK_AN_REC_DIVIDER);
  }
  
  if ((timePreFaultArrVal >= MIN_TIME_PREFAULT_ARR_AN_REC)
        && (timePreFaultArrVal <= MAX_TIME_PREFAULT_ARR_AN_REC)
        && ((timePreFaultArrVal % TIME_PREFAULT_ARR_STEP_AN_REC) == 0)) {
    EDIT_SetTextColor(timePreFaultArrTextField, EDIT_CI_ENABLED, GUI_BLACK);
  } else {
    EDIT_SetTextColor(timePreFaultArrTextField, EDIT_CI_ENABLED, GUI_RED);
  }
  
  if ((timePostFaultArrVal >= MIN_TIME_POSTFAULT_ARR_AN_REC)
        && (timePostFaultArrVal <= MAX_TIME_POSTFAULT_ARR_AN_REC)
        && ((timePostFaultArrVal % TIME_POSTFAULT_ARR_STEP_AN_REC) == 0)) {
    EDIT_SetTextColor(timePostFaultArrTextField, EDIT_CI_ENABLED, GUI_BLACK);
  } else {
    EDIT_SetTextColor(timePostFaultArrTextField, EDIT_CI_ENABLED, GUI_RED);
  }
}

