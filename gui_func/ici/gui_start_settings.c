
#include <tc/tc.h>
#include "irq/irq.h"

#include "GUI.h"
#include "gui_header.h"
#include "header_mal.h"

extern void ChangeOrient();
extern void ON_BackLight();

extern void _DemoMultiPage(void);

void gui_init() {
  ChangeOrient();
  
  ON_BackLight();
  
//  WM_SetCreateFlags(WM_CF_MEMDEV);
  GUI_Init();
//  WM_MULTIBUF_Enable(1);
  
  GUI_UC_SetEncodeUTF8();
  
  desctop_init();
  rank_panel_init();
  
//  dialog_password_init();
//  dialog_confirmation_init();
//  dialog_error_init();
  
  WM_SetFocus(iconWin);
  start_gui_exec = 1;
  
//  char *p1 = SETTINGS_UKR_TXT;
  
//  int tmp = (int) p1;
  
//  GUI_SetBkColor(GUI_BLACK);
  
//  GUI_SetBkColor(0xFFFF00);
  
//  GUI_Clear();
  
//  GUI_SetColor(GUI_WHITE);
//  GUI_SetFont(&GUI_FontArialBold19_12_Unicode);
//  GUI_DispStringHCenterAt("`1234567890-=~!@#$", 160, 30);
//  GUI_DispStringHCenterAt("%^&*()_+qwertyuiop[]", 160, 50);
//  GUI_DispStringHCenterAt("asdfghjkl;'zxcvbnm,.", 160, 70);
//  GUI_DispStringHCenterAt("/QWERTYUIOP{}ASDFGH", 160, 90);
//  GUI_DispStringHCenterAt("JKL:|ZXCVBNM<>?", 160, 110);
//  GUI_DispStringHCenterAt("ЁёЭэЇїыЫйцукенгшщз", 160, 130);
//  GUI_DispStringHCenterAt("хфівапролджєячсмитьбю", 160, 150);
//  GUI_DispStringHCenterAt("ЙЦУКЕНГШЩЗХЇФІВА", 160, 170);
//  GUI_DispStringHCenterAt("ПРОЛДЖЄЯЧСМИТЬБЮ", 160, 190);
  
//  GUI_DispStringHCenterAt((char*)tmp, 160, 50);
}

