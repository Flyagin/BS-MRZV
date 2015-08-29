
#include "gui_header.h"
#include "header_mal.h"

static void focus_moving_at_rank_dlg_df() {
  switch(current_ekran.index_position) {
    case 0:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY));
        break;
      }
    case 1:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_WORK));
        break;
      }
    case 2:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TYPE));
        break;
      }
    default:
      {
        WM_SetFocus(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY));
        break;
      }
  }
}

/*********************************************************************
*
*       Обновление статус панели
*/
void update_df_status_panel() {
  if (current_ekran.edition != 0) {
    char explanationText[100] = {0};
    unsigned int i = 0;
    for (; _rankDlgDFItem[0].pExplanation[sel_language][i] != '\0'; i++) {
      explanationText[i] = _rankDlgDFItem[0].pExplanation[sel_language][i];
    }
    _CONCAT_STR(explanationText, editModeAdditionalText[sel_language]);
    EDIT_SetText(hEdit, explanationText);
  } else {
    EDIT_SetText(hEdit, _rankDlgDFItem[0].pExplanation[sel_language]);
  }
}

/*********************************************************************
*
*       Обновление оглавления диалогового окна
*/
void update_df_title() {
  char titleText[100] = {0};
  unsigned int i = 0;
  for (; _rankDlgDFItem[0].pText[sel_language][i] != '\0'; i++) {
    titleText[i] = _rankDlgDFItem[0].pText[sel_language][i];
  }
  char numberDFText[3] = {0};
  int numPg = df_index + 1;
  _PARSE_INT_TO_STR(numPg, numberDFText);
  _CONCAT_STR(titleText, numberDFText);
  FRAMEWIN_SetText(rankDlgDFPg, titleText);
}

/*********************************************************************
*
*       Обновление меток диалогового окна
*/
void update_df_labels() {
  TEXT_SetText(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TEXT_LABEL1), tmrDelayDFTextLabels[sel_language]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_UNIT1), secUnits[sel_language]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TEXT_LABEL2), tmrWorkDFTextLabels[sel_language]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_UNIT2), secUnits[sel_language]);
  TEXT_SetText(WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TEXT_LABEL3), typeDFTextLabels[sel_language]);
  
  //обновление названия для "тип функции" в соответствии с выбранным языком
  DROPDOWN_Handle typeDFListBox = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TYPE);
  DROPDOWN_DeleteItem(typeDFListBox, 0);
  DROPDOWN_InsertString(typeDFListBox, typesDF0[sel_language], 0);
  DROPDOWN_DeleteItem(typeDFListBox, 1);
  DROPDOWN_InsertString(typeDFListBox, typesDF1[sel_language], 1);
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

void rank_dlg_df_init() {
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
  
  EDIT_Handle tmrDelayDFTextField; //текстовое поле для таймера паузы ОФ
  EDIT_Handle tmrWorkDFTextField; //текстовое поле для таймера работы ОФ
  DROPDOWN_Handle typeDFListBox; //список для выбора ОФ
  
  TEXT_Handle tmrDelayUnit;
  TEXT_Handle tmrWorkUnit;
  
  BUTTON_Handle ESC_Button_df_rank_dlg;
  BUTTON_Handle ENTER_Button_df_rank_dlg;
  
  rankDlgDFPg = FRAMEWIN_CreateEx(x0, y0, WIDTH_DLG, HEIGHT_DLG, 0, WM_CF_SHOW, 0, win_id_list[ID_RANK_DF_DLG], _rankDlgDFItem[0].pText[sel_language], _cbRankDlgWin);
  FRAMEWIN_SetFont(rankDlgDFPg, &GUI_FontArialBold14_8_Unicode);
  
  label1 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_TEXT_LABEL1, tmrDelayDFTextLabels[sel_language]);
  TEXT_SetFont(label1, &GUI_FontArialBold14_8_Unicode);
  
  tmrDelayUnit = TEXT_CreateEx(x_components + WIDTH_COMP + 5, y_textLabel, 20, HEIGHT_T, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_UNIT1, msUnits[sel_language]);
  TEXT_SetFont(tmrDelayUnit, &GUI_FontArialBold14_8_Unicode);
  
  y_textLabel += HEIGHT_T + 10;
  label2 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_TEXT_LABEL2, tmrWorkDFTextLabels[sel_language]);
  TEXT_SetFont(label2, &GUI_FontArialBold14_8_Unicode);
  
  tmrWorkUnit = TEXT_CreateEx(x_components + WIDTH_COMP + 5, y_textLabel, 20, HEIGHT_T, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_UNIT2, msUnits[sel_language]);
  TEXT_SetFont(tmrWorkUnit, &GUI_FontArialBold14_8_Unicode);
  
  y_textLabel += HEIGHT_T + 10;
  label3 = TEXT_CreateEx(x_textLabel, y_textLabel, WIDTH_T, HEIGHT_T, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_TEXT_LABEL3, typeDFTextLabels[sel_language]);
  TEXT_SetFont(label3, &GUI_FontArialBold14_8_Unicode);
  
  tmrDelayDFTextField = EDIT_CreateEx(x_components, y_components, WIDTH_COMP, HEIGHT_COMP, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_TMR_DELAY, RANK_DF_TMR_DELAY_VAL_LENGTH);
  EDIT_SetFont(tmrDelayDFTextField, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetFloatMode(tmrDelayDFTextField, (float) MIN_TMR_DELAY_DF / RANK_DF_DIVIDER, 0, 99.99f, 2, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
  
  y_components += HEIGHT_COMP + 11;
  tmrWorkDFTextField = EDIT_CreateEx(x_components, y_components, WIDTH_COMP, HEIGHT_COMP, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_TMR_WORK, RANK_DF_TMR_WORK_VAL_LENGTH);
  EDIT_SetFont(tmrWorkDFTextField, &GUI_FontArialStandard14_8_Unicode);
  EDIT_SetFloatMode(tmrWorkDFTextField, (float) MIN_TMR_WORK_DF / RANK_DF_DIVIDER, 0, 99.999f, 3, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
  
  y_components += HEIGHT_COMP + 11;
  typeDFListBox = DROPDOWN_CreateEx(x_components, y_components, WIDTH_COMP + 25, HEIGHT_COMP, rankDlgDFPg, WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_RANK_DF_TYPE);
  DROPDOWN_SetFont(typeDFListBox, &GUI_FontArialStandard14_8_Unicode);
  DROPDOWN_SetBkColor(typeDFListBox, DROPDOWN_CI_UNSEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeDFListBox, DROPDOWN_CI_SEL, GUI_GRAY);
  DROPDOWN_SetBkColor(typeDFListBox, DROPDOWN_CI_SELFOCUS, GUI_BLUE);
  DROPDOWN_AddString(typeDFListBox, typesDF0[sel_language]);
  DROPDOWN_AddString(typeDFListBox, typesDF1[sel_language]);
  
  ESC_Button_df_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_DLGBUT_ESC);
  BUTTON_SetFont(ESC_Button_df_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ESC_Button_df_rank_dlg, "ESC");
  
  x_b = WIDTH_DLG - (WIDTH_B + 5);
  ENTER_Button_df_rank_dlg = BUTTON_CreateEx(x_b, y_b, WIDTH_B, HEIGHT_B, rankDlgDFPg, WM_CF_SHOW, 0, ID_RANK_DF_DLGBUT_ENTER);
  BUTTON_SetFont(ENTER_Button_df_rank_dlg, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ENTER_Button_df_rank_dlg, "ENTER");
  
  WM_BringToTop(rankDlgDFPg);

  #undef WIDTH_DLG
  #undef HEIGHT_DLG

  #undef WIDTH_B
  #undef HEIGHT_B
  #undef WIDTH_T
  #undef HEIGHT_T
  #undef WIDTH_COMP
  #undef HEIGHT_COMP
}

_Bool df_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed) {
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
              if (tmrDelayDF[df_index] > MAX_TMR_DELAY_DF) {
                current_ekran.edition = 2;
                tmrDelayDF[df_index] = MAX_TMR_DELAY_DF;
              } else if (tmrDelayDF[df_index] > MIN_TMR_DELAY_DF) {
                current_ekran.edition = 2;
                if (tmrDelayDF[df_index] % TMR_DELAY_STEP_DF > 0) {
                  tmrDelayDF[df_index] = (tmrDelayDF[df_index] / TMR_DELAY_STEP_DF) * TMR_DELAY_STEP_DF;
                } else {
                  tmrDelayDF[df_index] -= TMR_DELAY_STEP_DF;
                }
              }
              return 1;
            }
          case 1:
            {
              if (tmrWorkDF[df_index] > MAX_TMR_WORK_DF) {
                current_ekran.edition = 2;
                tmrWorkDF[df_index] = MAX_TMR_WORK_DF;
              } else if (tmrWorkDF[df_index] > MIN_TMR_WORK_DF) {
                current_ekran.edition = 2;
                if (tmrWorkDF[df_index] % TMR_WORK_STEP_DF > 0) {
                  tmrWorkDF[df_index] = (tmrWorkDF[df_index] / TMR_WORK_STEP_DF) * TMR_WORK_STEP_DF;
                } else {
                  tmrWorkDF[df_index] -= TMR_WORK_STEP_DF;
                }
              }
              return 1;
            }
          case 2:
            {
              if (typeDF[df_index] != 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 0;
                return 1;
              } else if (typeDF[df_index] == 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 1;
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
              if (tmrDelayDF[df_index] < MAX_TMR_DELAY_DF) {
                current_ekran.edition = 2;
                if (tmrDelayDF[df_index] % TMR_DELAY_STEP_DF > 0) {
                  tmrDelayDF[df_index] = (tmrDelayDF[df_index] / TMR_DELAY_STEP_DF) * TMR_DELAY_STEP_DF + TMR_DELAY_STEP_DF;
                } else {
                  tmrDelayDF[df_index] += TMR_DELAY_STEP_DF;
                }
              }
              return 1;
            }
          case 1:
            {
              if (tmrWorkDF[df_index] < MAX_TMR_WORK_DF) {
                current_ekran.edition = 2;
                if (tmrWorkDF[df_index] % TMR_WORK_STEP_DF > 0) {
                  tmrWorkDF[df_index] = (tmrWorkDF[df_index] / TMR_WORK_STEP_DF) * TMR_WORK_STEP_DF + TMR_WORK_STEP_DF;
                } else {
                  tmrWorkDF[df_index] += TMR_WORK_STEP_DF;
                }
              }
              return 1;
            }
          case 2:
            {
              if (typeDF[df_index] != 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 0;
                return 1;
              } else if (typeDF[df_index] == 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 1;
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
        EDIT_Handle tmrDelayDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY);
        EDIT_Handle tmrWorkDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_WORK);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(tmrDelayDFTextField, GUI_KEY_LEFT);
              return 1;
            }
          case 1:
            {
              EDIT_AddKey(tmrWorkDFTextField, GUI_KEY_LEFT);
              return 1;
            }
          case 2:
            {
              if (typeDF[df_index] != 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 0;
                return 1;
              } else if (typeDF[df_index] == 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 1;
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
        EDIT_Handle tmrDelayDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY);
        EDIT_Handle tmrWorkDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_WORK);
        switch (current_ekran.index_position) {
          case 0:
            {
              EDIT_AddKey(tmrDelayDFTextField, GUI_KEY_RIGHT);
              return 1;
            }
          case 1:
            {
              EDIT_AddKey(tmrWorkDFTextField, GUI_KEY_RIGHT);
              return 1;
            }
          case 2:
            {
              if (typeDF[df_index] != 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 0;
                return 1;
              } else if (typeDF[df_index] == 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 1;
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
        EDIT_Handle timerDelayDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY);
        EDIT_Handle timerWorkDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_WORK);
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
              EDIT_AddKey(timerDelayDFTextField, _key);
              tmrDelayDF[df_index] = (long) (EDIT_GetFloatValue(timerDelayDFTextField) * RANK_DF_DIVIDER);
              return 1;
            }
          case 1:
            {
              current_ekran.edition = 2;
              EDIT_AddKey(timerWorkDFTextField, _key);
              tmrWorkDF[df_index] = (long) (EDIT_GetFloatValue(timerWorkDFTextField) * RANK_DF_DIVIDER);
              return 1;
            }
          case 2:
            {
              if (_key == '0' && typeDF[df_index] != 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 0;
                return 1;
              } else if (_key == '1' && typeDF[df_index] == 0) {
                current_ekran.edition = 2;
                typeDF[df_index] = 1;
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

_Bool timerDelayDFIsCorrect() {
  for (int i = 0; i < NUM_DEF_FUN; i++) {
    if ((tmrDelayDF[i] < MIN_TMR_DELAY_DF)
        || (tmrDelayDF[i] > MAX_TMR_DELAY_DF)
        || ((tmrDelayDF[i] % TMR_DELAY_STEP_DF) != 0)) {
      return 0;
    }
  }
  return 1;
}

_Bool timerWorkDFIsCorrect() {
  for (int i = 0; i < NUM_DEF_FUN; i++) {
    if ((tmrWorkDF[i] < MIN_TMR_WORK_DF)
        || (tmrWorkDF[i] > MAX_TMR_WORK_DF)
        || ((tmrWorkDF[i] % TMR_WORK_STEP_DF) != 0)) {
      return 0;
    }
  }
  return 1;
}

void update_df_settings() {
  focus_moving_at_rank_dlg_df();
  EDIT_Handle timerDelayDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_DELAY);
  EDIT_Handle timerWorkDFTextField = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TMR_WORK);
  DROPDOWN_Handle typeDFListBox = WM_GetDialogItem(rankDlgDFPg, ID_RANK_DF_TYPE);
  
  if (tmrDelayDF[df_index] != (long) (EDIT_GetFloatValue(timerDelayDFTextField) * RANK_DF_DIVIDER)) {
    EDIT_SetFloatValue(timerDelayDFTextField, (float) tmrDelayDF[df_index] / RANK_DF_DIVIDER);
  }
  
  if (tmrWorkDF[df_index] != (long) (EDIT_GetFloatValue(timerWorkDFTextField) * RANK_DF_DIVIDER)) {
    EDIT_SetFloatValue(timerWorkDFTextField, (float) tmrWorkDF[df_index] / RANK_DF_DIVIDER);
  }
  
  if (typeDF[df_index] == 0) {
    DROPDOWN_SetSel(typeDFListBox, 0);
  } else {
    DROPDOWN_SetSel(typeDFListBox, 1);
  }
  
  if ((tmrDelayDF[df_index] >= MIN_TMR_DELAY_DF)
        && (tmrDelayDF[df_index] <= MAX_TMR_DELAY_DF)
        && ((tmrDelayDF[df_index] % TMR_DELAY_STEP_DF) == 0)) {
    EDIT_SetTextColor(timerDelayDFTextField, EDIT_CI_ENABLED, GUI_BLACK);
  } else {
    EDIT_SetTextColor(timerDelayDFTextField, EDIT_CI_ENABLED, GUI_RED);
  }
  
  if ((tmrWorkDF[df_index] >= MIN_TMR_WORK_DF)
        && (tmrWorkDF[df_index] <= MAX_TMR_WORK_DF)
        && ((tmrWorkDF[df_index] % TMR_WORK_STEP_DF) == 0)) {
    EDIT_SetTextColor(timerWorkDFTextField, EDIT_CI_ENABLED, GUI_BLACK);
  } else {
    EDIT_SetTextColor(timerWorkDFTextField, EDIT_CI_ENABLED, GUI_RED);
  }
}
