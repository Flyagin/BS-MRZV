
#include "gui_header.h"
#include "header_mal.h"
#include "memory_map_header.h"

static unsigned char sel_conf_language;

/*********************************************************************
*
*       _cbConfigWin
*/
static void _cbConfigWin(WM_MESSAGE * pMsg) {
//  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case (GUI_ID_USER + 3): // Notifications sent by 'Multipage'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
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

void configuration_panel_init() {
  int frmWinWidth = GUI_X_MAX;
  int frmWinHeight = GUI_Y_MAX - 40;
  int x0 = 0;
  int y0 = 20;
  
  int checkBoxX = 5;
  int checkBoxY = 22;
  int checkBoxWidth = 60;
  int checkBoxHeight = 15;
  
  int buttonWidth = 90;
  int buttonHeight = 20;
  int buttonX = 5;
  int buttonY = frmWinHeight - (buttonHeight + 5);
  
  sel_conf_language = sel_language;
  
  configPageWin = FRAMEWIN_Create(confFrmText[sel_language], _cbConfigWin, WM_CF_SHOW, x0, y0, frmWinWidth, frmWinHeight);
  FRAMEWIN_SetFont(configPageWin, &GUI_FontArialBold14_8_Unicode);
  
  for (int i = 0; i < NUM_CONF_ITEMS; i++) {
    int id = i + ID_CONF_DSTP_CFG_PRT_ONB;
    CHECKBOX_Handle checkBox = CHECKBOX_Create(checkBoxX, checkBoxY, checkBoxWidth, checkBoxHeight, configPageWin, id, WM_CF_SHOW);
    CHECKBOX_SetFont(checkBox, &GUI_FontArialStandard14_8_Unicode);
    CHECKBOX_SetText(checkBox, conf_checkbox_item[sel_language][i]);
    CHECKBOX_SetBoxBkColor(checkBox, GUI_USER_LIGHTGRAY, CHECKBOX_CI_DISABLED);
    CHECKBOX_SetBoxBkColor(checkBox, GUI_YELLOW, CHECKBOX_CI_ENABLED);
    CHECKBOX_SetFocusColor(checkBox, GUI_BLUE);
    checkBoxY += 15;
  }
  
  BUTTON_Handle ESC_Button = BUTTON_CreateEx(buttonX, buttonY, buttonWidth, buttonHeight, configPageWin, WM_CF_SHOW, 0, ID_CONF_BUTTON_ESC);
  BUTTON_SetFont(ESC_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ESC_Button, escButtonExpl[sel_language]);
  
  buttonX = frmWinWidth - (buttonWidth + 5);
  BUTTON_Handle ENTER_Button = BUTTON_CreateEx(buttonX, buttonY, buttonWidth, buttonHeight, configPageWin, WM_CF_SHOW, 0, ID_CONF_BUTTON_ENTER);
  BUTTON_SetFont(ENTER_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(ENTER_Button, enterButtonExpl[sel_language]);
}

void copy_config_settings_to_buff() {
  CfgTblDsc* pConfig = &eeprom_prt_tbl;
  for (unsigned int i = 0; i < sizeof(selInfConf); i++) {
    selInfConf[i] = pConfig -> arUchCfgPrt[i];
  }
}

void copy_config_settings_from_buff() {
  CfgTblDsc* pConfig = &eeprom_prt_tbl;
  for (unsigned int i = 0; i < sizeof(selInfConf); i++) {
    pConfig -> arUchCfgPrt[i] = selInfConf[i];
  }
  disabling_protections();
  
  //-Бит запроса на запись к  системе Ici
  shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
}

void conf_enter_handler() {
  int index = current_ekran.index_position;
  current_ekran.edition = 2;
  if (_CHECK_BIT_UCHAR(selInfConf, index)) {
    _CLEAR_BIT_UCHAR(selInfConf, index);
  } else {
    _SET_BIT_UCHAR(selInfConf, index);
  }
}

void update_conf_item() {
  WM_SetFocus(
    WM_GetDialogItem(
      configPageWin,
      ID_CONF_DSTP_CFG_PRT_ONB + current_ekran.index_position
    )
  );
  
  for (int i = 0; i < NUM_CONF_ITEMS; i++) {
    CHECKBOX_Handle checkBox = WM_GetDialogItem(configPageWin, ID_CONF_DSTP_CFG_PRT_ONB + i);
    if (sel_conf_language != sel_language) {
      CHECKBOX_SetText(checkBox, conf_checkbox_item[sel_language][i]);
    }
    if (WM_HasFocus(checkBox)) {
      CHECKBOX_SetTextColor(checkBox, GUI_YELLOW);
      CHECKBOX_SetBkColor(checkBox, GUI_BLUE);
    } else {
      CHECKBOX_SetTextColor(checkBox, GUI_BLACK);
      CHECKBOX_SetBkColor(checkBox, GUI_FRM_COLOR);
    }
    if (_CHECK_BIT_UCHAR(selInfConf, i)) {
      if (CHECKBOX_GetState(checkBox) == 0) {
        CHECKBOX_SetState(checkBox, 1);
      }
    } else {
      if (CHECKBOX_GetState(checkBox) != 0) {
        CHECKBOX_SetState(checkBox, 0);
      }
    }
  }
  
  if (sel_conf_language != sel_language) {
    sel_conf_language = sel_language;
    
    BUTTON_SetText(
      WM_GetDialogItem(
        configPageWin,
        ID_CONF_BUTTON_ESC
      ),
      escButtonExpl[sel_language]
    );
    BUTTON_SetText(
      WM_GetDialogItem(
        configPageWin,
        ID_CONF_BUTTON_ENTER
      ),
      enterButtonExpl[sel_language]
    );
  }
  
  char titleText[100] = {0};
  unsigned int i = 0;
  for (; confFrmText[sel_language][i] != '\0'; i++) {
    titleText[i] = confFrmText[sel_language][i];
  }
  
  if (current_ekran.edition != 0) {
    _CONCAT_STR(titleText, editModeAdditionalText[sel_language]);
  }
  
  FRAMEWIN_SetText(configPageWin, titleText);
  
  EDIT_SetText(hEdit, confExplText[sel_language]);
}
