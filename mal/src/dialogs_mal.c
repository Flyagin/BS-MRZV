#include "header_mal.h"

/*****************************
       _cbEmpty
*****************************/
void _cbEmpty(WM_MESSAGE * pMsg)
{
  // USER START (Optionally insert additional variables)
  // USER END
  switch (pMsg->MsgId)
  {
//  case WM_PAINT:
//    {
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
Ініціалізація запиту віка на перехід у режим редагування
*****************************/
void dialog_password_show(int win_id, unsigned int index)
{
#define XSIZE_W 172
#define YSIZE_W 69

#define XSIZE_B         72
#define YSIZE_E_B       20
  
  int x0 = (GUI_X_MAX - XSIZE_W) >> 1;
  int y0 = (GUI_Y_MAX - YSIZE_W) >> 1;
  
  WM_HWIN *Dialog_FrameWin, *Dialog_DP_Text, *Dialog_DP_ESC_Button, *Dialog_DP_ENTER_Button;
  _id_user_widget id_framewin, id_dp_text, id_dp_cancel_button, id_dp_ok_button;
  switch(win_id)
  {
  case ID_DIALOG_PASSWORD:
    {
      Dialog_FrameWin = &Dialog_password_FrameWin;
      id_framewin = ID_DIALOG_PASSWORD_FRAMEWIN;
      
      Dialog_DP_Text = &DP_Edit;
      id_dp_text = ID_DP_EDIT;
      
      Dialog_DP_ESC_Button = &DP_ESC_Button;
      id_dp_cancel_button = ID_DP_CANCEL_BUTTON;
      
      Dialog_DP_ENTER_Button = &DP_ENTER_Button;
      id_dp_ok_button = ID_DP_OK_BUTTON;

      break;
    }
  case ID_DIALOG_PASSWORD_LEVEL_2:
  case ID_DIALOG_PASSWORD_OLD_1:
  case ID_DIALOG_PASSWORD_OLD_2:
  case ID_DIALOG_PASSWORD_NEW_1:
  case ID_DIALOG_PASSWORD_NEW_2:
    {
      Dialog_FrameWin = &Dialog_password_level_2_FrameWin;
      id_framewin = ID_DIALOG_PASSWORD_LEVEL_2_FRAMEWIN;
      
      Dialog_DP_Text = &DP_level_2_Edit;
      id_dp_text = ID_DP_LEVEL_2_EDIT;
      
      Dialog_DP_ESC_Button = &DP_ESC_level_2_Button;
      id_dp_cancel_button = ID_DP_CANCEL_LEVEL_2_BUTTON;
      
      Dialog_DP_ENTER_Button = &DP_ENTER_level_2_Button;
      id_dp_ok_button = ID_DP_OK_LEVEL_2_BUTTON;

      break;
    }
  default:
    {
      while (1);
    }
  }
  
  *Dialog_FrameWin = FRAMEWIN_CreateEx(x0, y0, XSIZE_W, YSIZE_W, 0, WM_CF_HIDE, 0, id_framewin, Dialog_password_title[index].ptitle[sel_language], _cbEmpty);
  FRAMEWIN_SetFont(*Dialog_FrameWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTextAlign(*Dialog_FrameWin, GUI_TA_LEFT);

  int B_size = FRAMEWIN_GetBorderSize(*Dialog_FrameWin);
  int T_hight = FRAMEWIN_GetTitleHeight(*Dialog_FrameWin);
  int D_size = 1;
  int shift_to_button_x = (XSIZE_W - 2*(XSIZE_B + B_size)) >> 2;
  int shift_to_button_y = (YSIZE_W - 2*B_size - T_hight - D_size - 2*YSIZE_E_B)/3;
  
  *Dialog_DP_Text = EDIT_CreateEx(shift_to_button_x, shift_to_button_y, (XSIZE_W - 2*(shift_to_button_x + B_size)), YSIZE_E_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dp_text, MAX_NUMBER_SYMBOLS_IN_PASSWORD);
  EDIT_SetFont(*Dialog_DP_Text, &GUI_FontArialBold15_9_Unicode);
  EDIT_SetTextAlign(*Dialog_DP_Text, GUI_TA_LEFT | GUI_TA_VCENTER);
  
  *Dialog_DP_ESC_Button = BUTTON_CreateEx(shift_to_button_x, YSIZE_E_B + 2*shift_to_button_y, XSIZE_B, YSIZE_E_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dp_cancel_button);
  BUTTON_SetFont(*Dialog_DP_ESC_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DP_ESC_Button, ENTER_ESC[1].ptitle[sel_language]);

  *Dialog_DP_ENTER_Button = BUTTON_CreateEx(3*shift_to_button_x + XSIZE_B, YSIZE_E_B + 2*shift_to_button_y, XSIZE_B, YSIZE_E_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dp_ok_button);
  BUTTON_SetFont(*Dialog_DP_ENTER_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DP_ENTER_Button, ENTER_ESC[0].ptitle[sel_language]);

#undef XSIZE_W
#undef YSIZE_W

#undef XSIZE_B
#undef YSIZE_E_B
  
  WM_BringToTop(*Dialog_FrameWin);
  WM_ShowWindow(*Dialog_FrameWin);
}
/*****************************/

/*****************************
Відображення числа з курсором у полі EDIT
*****************************/
void Set_Test_and_cursor_into_EDIT(WM_HWIN hObj, char* s, int xPos, int hide, char hide_symbol)
{
  char *s_tmp;
  if (hide == 0) s_tmp = s;
  else
  {
    char string_tmp[256];
    int length = strlen_mal(s);
    for (int i = 0; i < length; i++ ) string_tmp[i] = hide_symbol;
    string_tmp[length] = '\0';
    s_tmp = string_tmp; 
  }
  EDIT_SetText(hObj, s_tmp);
  EDIT_SetCursorAtChar(hObj, xPos);
}
/*****************************/

/*****************************
Ініціалізація запиту на підтвердження
*****************************/
void dialog_confirmation_show(int win_id)
{
#define XSIZE_W 144
#define YSIZE_W 89

#define XSIZE_B         65
#define YSIZE_B         20
#define YSIZE_T         (2*YSIZE_B)
  
  WM_HWIN *Dialog_FrameWin, *Dialog_DC_Text, *Dialog_DC_ESC_Button, *Dialog_DC_ENTER_Button;
  _id_user_widget id_framewin, id_dc_text, id_dc_cancel_button, id_dc_ok_button;
  TITLE *Dialog_message;
  switch(win_id)
  {
  case ID_DIALOG_CONFIRMATION:
    {
      Dialog_FrameWin = &Dialog_confirmation_FrameWin;
      Dialog_message = &Dialog_confirmation_message;
      id_framewin = ID_DIALOG_CONFIRMATION_FRAMEWIN;
      
      Dialog_DC_Text = &DC_Text;
      id_dc_text = ID_DC_TEXT;
      
      Dialog_DC_ESC_Button = &DC_ESC_Button;
      id_dc_cancel_button = ID_DC_CANCEL_BUTTON;
      
      Dialog_DC_ENTER_Button = &DC_ENTER_Button;
      id_dc_ok_button = ID_DC_OK_BUTTON;

      break;
    }
  case ID_DIALOG_CONFIRMATION_LEVEL_2:
    {
      Dialog_FrameWin = &Dialog_confirmation_level_2_FrameWin;
      Dialog_message = &Dialog_confirmation_level_2_message;
      id_framewin = ID_DIALOG_CONFIRMATION_LEVEL_2_FRAMEWIN;

      Dialog_DC_Text = &DC_level_2_Text;
      id_dc_text = ID_DC_LEVEL_2_TEXT;

      Dialog_DC_ESC_Button = &DC_ESC_level_2_Button;
      id_dc_cancel_button = ID_DC_CANCEL_LEVEL_2_BUTTON;
      
      Dialog_DC_ENTER_Button = &DC_ENTER_level_2_Button;
      id_dc_ok_button = ID_DC_OK_LEVEL_2_BUTTON;

      break;
    }
  default:
    {
      while (1);
    }
  }
  
  int x0 = (GUI_X_MAX - XSIZE_W) >> 1;
  int y0 = (GUI_Y_MAX - YSIZE_W) >> 1;
  
  *Dialog_FrameWin = FRAMEWIN_CreateEx(x0, y0, XSIZE_W, YSIZE_W, 0, WM_CF_HIDE, 0, id_framewin, Dialog_confirmation_title.ptitle[sel_language], _cbEmpty);
  FRAMEWIN_SetFont(*Dialog_FrameWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTextAlign(*Dialog_FrameWin, GUI_TA_LEFT);

  int B_size = FRAMEWIN_GetBorderSize(*Dialog_FrameWin);
  int T_hight = FRAMEWIN_GetTitleHeight(*Dialog_FrameWin);
  int D_size = 1;
  int shift_to_button_x = (XSIZE_W - 2*(XSIZE_B + B_size)) >> 2;
  int shift_to_button_y = (YSIZE_W - 2*B_size - T_hight - D_size - YSIZE_T - YSIZE_B)/3;
  
  *Dialog_DC_Text = TEXT_CreateEx(shift_to_button_x, shift_to_button_y, (XSIZE_W - 2*(shift_to_button_x + B_size)), YSIZE_T, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dc_text, Dialog_message->ptitle[sel_language]);
  TEXT_SetFont(*Dialog_DC_Text, &GUI_FontArialStandard15_9_Unicode);
  TEXT_SetTextAlign(*Dialog_DC_Text, TEXT_CF_HCENTER | GUI_TA_VCENTER);
  TEXT_SetWrapMode(*Dialog_DC_Text, GUI_WRAPMODE_WORD);
  
  *Dialog_DC_ESC_Button = BUTTON_CreateEx(shift_to_button_x, YSIZE_T + 2*shift_to_button_y, XSIZE_B, YSIZE_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dc_cancel_button);
  BUTTON_SetFont(*Dialog_DC_ESC_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DC_ESC_Button, ENTER_ESC[1].ptitle[sel_language]);

  *Dialog_DC_ENTER_Button = BUTTON_CreateEx(3*shift_to_button_x + XSIZE_B, YSIZE_T + 2*shift_to_button_y, XSIZE_B, YSIZE_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_dc_ok_button);
  BUTTON_SetFont(*Dialog_DC_ENTER_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DC_ENTER_Button, ENTER_ESC[0].ptitle[sel_language]);

#undef XSIZE_W
#undef YSIZE_W

#undef XSIZE_B
#undef YSIZE_T
#undef YSIZE_B

  WM_BringToTop(*Dialog_FrameWin);
  WM_ShowWindow(*Dialog_FrameWin);
}
/*****************************/

/*****************************
Ініціалізація повідомлення про помилку
*****************************/
void dialog_error_show(int win_id)
{
#define XSIZE_W 216
#define YSIZE_W 134

#define XSIZE_B         65
#define YSIZE_B         20
#define YSIZE_T         (4*YSIZE_B)
  
  WM_HWIN *Dialog_FrameWin, *Dialog_DE_Text, *Dialog_DE_ESC_Button, *Dialog_DE_ENTER_Button;
  _id_user_widget id_framewin, id_de_text, id_de_cancel_button, id_de_ok_button;
  TITLE *Dialog_message;
  switch(win_id)
  {
  case ID_DIALOG_ERROR:
    {
      Dialog_FrameWin = &Dialog_error_FrameWin;
      Dialog_message = &Dialog_error_message;
      id_framewin = ID_DIALOG_ERROR_FRAMEWIN;
      
      Dialog_DE_Text = &DE_Text;
      id_de_text = ID_DE_TEXT;
      
      Dialog_DE_ESC_Button = &DE_ESC_Button;
      id_de_cancel_button = ID_DE_CANCEL_BUTTON;
      
      Dialog_DE_ENTER_Button = &DE_ENTER_Button;
      id_de_ok_button = ID_DE_OK_BUTTON;

      break;
    }
  case ID_DIALOG_ERROR_LEVEL_2:
    {
      Dialog_FrameWin = &Dialog_error_level_2_FrameWin;
      Dialog_message = &Dialog_error_level_2_message;
      id_framewin = ID_DIALOG_ERROR_LEVEL_2_FRAMEWIN;

      Dialog_DE_Text = &DE_level_2_Text;
      id_de_text = ID_DE_LEVEL_2_TEXT;

      Dialog_DE_ESC_Button = &DE_ESC_level_2_Button;
      id_de_cancel_button = ID_DE_CANCEL_LEVEL_2_BUTTON;
      
      Dialog_DE_ENTER_Button = &DE_ENTER_level_2_Button;
      id_de_ok_button = ID_DE_OK_LEVEL_2_BUTTON;

      break;
    }
  default:
    {
      while (1);
    }
  }

  int x0 = (GUI_X_MAX - XSIZE_W) >> 1;
  int y0 = (GUI_Y_MAX - YSIZE_W) >> 1;
  
  *Dialog_FrameWin = FRAMEWIN_CreateEx(x0, y0, XSIZE_W, YSIZE_W, 0, WM_CF_SHOW, 0, id_framewin, Dialog_message->ptitle[sel_language], _cbEmpty);
  FRAMEWIN_SetFont(*Dialog_FrameWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTextAlign(*Dialog_FrameWin, GUI_TA_LEFT);

  int B_size = FRAMEWIN_GetBorderSize(*Dialog_FrameWin);
  int T_hight = FRAMEWIN_GetTitleHeight(*Dialog_FrameWin);
  int D_size = 1;
  int shift_to_button_x = (XSIZE_W - 2*(XSIZE_B + B_size)) >> 2;
  int shift_to_button_y = (YSIZE_W - 2*B_size - T_hight - D_size - YSIZE_T - YSIZE_B)/3;
  
  *Dialog_DE_Text = TEXT_CreateEx(10, shift_to_button_y, (XSIZE_W - 2*(10 + B_size)), YSIZE_T, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_de_text, Dialog_error_message.ptitle[sel_language]);
  TEXT_SetFont(*Dialog_DE_Text, &GUI_FontArialStandard15_9_Unicode);
  TEXT_SetTextAlign(*Dialog_DE_Text, TEXT_CF_HCENTER | GUI_TA_VCENTER);
  TEXT_SetWrapMode(*Dialog_DE_Text, GUI_WRAPMODE_WORD);
  
  *Dialog_DE_ESC_Button = BUTTON_CreateEx(shift_to_button_x, YSIZE_T + 2*shift_to_button_y, XSIZE_B, YSIZE_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_de_cancel_button);
  BUTTON_SetFont(*Dialog_DE_ESC_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DE_ESC_Button, ENTER_ESC[1].ptitle[sel_language]);

  *Dialog_DE_ENTER_Button = BUTTON_CreateEx(3*shift_to_button_x + XSIZE_B, YSIZE_T + 2*shift_to_button_y, XSIZE_B, YSIZE_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_de_ok_button);
  BUTTON_SetFont(*Dialog_DE_ENTER_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_DE_ENTER_Button, ENTER_ESC[0].ptitle[sel_language]);

#undef XSIZE_W
#undef YSIZE_W

#undef XSIZE_B
#undef YSIZE_T
#undef YSIZE_B

  WM_BringToTop(*Dialog_FrameWin);
  WM_ShowWindow(*Dialog_FrameWin);
}
/*****************************/

/*****************************
Ініціалізація повідомлення недостовірність даних
*****************************/
void unreliable_error_show(int win_id)
{
#define XSIZE_W 216
#define YSIZE_W 134

#define XSIZE_B         65
#define YSIZE_B         20
#define YSIZE_T         (4*YSIZE_B)
  
  int x0 = (GUI_X_MAX - XSIZE_W) >> 1;
  int y0 = (GUI_Y_MAX - YSIZE_W) >> 1;
  
  WM_HWIN *Dialog_FrameWin, *Dialog_Text, *Dialog_ESC_Button;
  _id_user_widget id_framewin, id_text, id_cancel_button;
  
  switch(win_id)
  {
  case ID_UNRELIABLE_ERROR:
    {
      Dialog_FrameWin = &Unreliable_error_FrameWin;
      id_framewin = ID_UNRELIABLE_ERROR_FRAMEWIN;
      
      Dialog_Text = &UE_Text;
      id_text = ID_UE_TEXT;
      
      Dialog_ESC_Button = &UE_ESC_Button;
      id_cancel_button = ID_UE_CANCEL_BUTTON;

      break;
    }
  case ID_UNRELIABLE_ERROR_LEVEL_2:
    {
      Dialog_FrameWin = &Unreliable_error_level_2_FrameWin;
      id_framewin = ID_UNRELIABLE_ERROR_LEVEL_2_FRAMEWIN;

      Dialog_Text = &UE_level_2_Text;
      id_text = ID_UE_LEVEL_2_TEXT;

      Dialog_ESC_Button = &UE_ESC_level_2_Button;
      id_cancel_button = ID_UE_CANCEL_LEVEL_2_BUTTON;

      break;
    }
  default:
    {
      while (1);
    }
  }
  
  *Dialog_FrameWin = FRAMEWIN_CreateEx(x0, y0, XSIZE_W, YSIZE_W, 0, WM_CF_HIDE, 0, id_framewin, Unreliable_error_title.ptitle[sel_language], _cbEmpty);
  FRAMEWIN_SetFont(*Dialog_FrameWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTextAlign(*Dialog_FrameWin, GUI_TA_CENTER);
  FRAMEWIN_SetBarColor(*Dialog_FrameWin, 0, GUI_DARKRED);
  FRAMEWIN_SetBarColor(*Dialog_FrameWin, 1, GUI_DARKRED);
  FRAMEWIN_SetTextColor(*Dialog_FrameWin, GUI_WHITE);
  FRAMEWIN_SetClientColor(*Dialog_FrameWin, GUI_RED);

  int B_size = FRAMEWIN_GetBorderSize(*Dialog_FrameWin);
  int T_hight = FRAMEWIN_GetTitleHeight(*Dialog_FrameWin);
  int D_size = 1;
  int shift_to_button_x = (XSIZE_W - (XSIZE_B + B_size)) >> 1;
  int shift_to_button_y = (YSIZE_W - 2*B_size - T_hight - D_size - YSIZE_T - YSIZE_B)/3;
  
  *Dialog_Text = TEXT_CreateEx(10, shift_to_button_y, (XSIZE_W - 2*(10 + B_size)), YSIZE_T, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_text, Unreliable_error_message.ptitle[sel_language]);
  TEXT_SetFont(*Dialog_Text, &GUI_FontArialStandard15_9_Unicode);
  TEXT_SetTextColor(*Dialog_Text, GUI_WHITE);
  TEXT_SetTextAlign(*Dialog_Text, TEXT_CF_HCENTER | GUI_TA_VCENTER);
  TEXT_SetWrapMode(*Dialog_Text, GUI_WRAPMODE_WORD);
  
  *Dialog_ESC_Button = BUTTON_CreateEx(shift_to_button_x, YSIZE_T + 2*shift_to_button_y, XSIZE_B, YSIZE_B, WM_GetClientWindow(*Dialog_FrameWin), WM_CF_SHOW, 0, id_cancel_button);
  BUTTON_SetFont(*Dialog_ESC_Button, &GUI_FontArialBold14_8_Unicode);
  BUTTON_SetText(*Dialog_ESC_Button, ENTER_ESC[1].ptitle[sel_language]);

#undef XSIZE_W
#undef YSIZE_W

#undef XSIZE_B
#undef YSIZE_T
#undef YSIZE_B

  WM_BringToTop(*Dialog_FrameWin);
  WM_ShowWindow(*Dialog_FrameWin);
}
/*****************************/


