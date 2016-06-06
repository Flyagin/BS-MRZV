#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Initializacija paneli nalashtuvan resursu
*****************************/
void resurs_panel_show(void)
{
  if (Resurs_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Resurs_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_RESURS_FRAMEWIN, Resurs_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbEmpty);
    FRAMEWIN_SetFont(Resurs_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Resurs_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Resurs_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Resurs_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Resurs_FrameWin, GUI_BLUE);  

#define COL_1_X         5
#define ROW_1_Y         10
#define HIGHT_Y         10
#define SHIFT_Y         (ROW_1_Y + HIGHT_Y)
#define WIDTH_X_T       165
#define WIDTH_X_V       80
#define SHIFT_X1        (WIDTH_X_T + 10)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 10)

    for (unsigned int i = 0; i < MAX_NUMBER_ITEMS_RESURS; i++)
    {
      Resurs_t[i] = TEXT_CreateEx(COL_1_X, ROW_1_Y + i*SHIFT_Y, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Resurs_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_RESURS_1_TITLE + i,  Resurs_title[i].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetFont(Resurs_t[i], &GUI_FontArialStandard14_8_Unicode);

      Resurs_v[i] = TEXT_CreateEx(COL_1_X + SHIFT_X1, ROW_1_Y + i*SHIFT_Y, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Resurs_FrameWin), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_RESURS_1_VALUE + i,  "");
      TEXT_SetFont(Resurs_v[i], &GUI_FontArialStandard14_8_Unicode);
    }
  
#undef COL_1_X
#undef ROW_1_Y
#undef HIGHT_Y
#undef SHIFT_Y
#undef WIDTH_X_T
#undef WIDTH_X_V
#undef SHIFT_X1
#undef SHIFT_X2

  }
  
  WM_BringToTop(Resurs_FrameWin);
  WM_ShowWindow(Resurs_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli resursu
*****************************/
void redraw_panel_resurs(void)
{
  struct resurs_data
  {
    long lResourceCB;   //Resurs Vikluchtelya
    long lAmountSetOnCB;//Kol-vo otkl

  }resurs;
  long result = GetHvpBrOnCalcInfo(&resurs);
  
  EDIT_SetText(hEdit, _aBitmapItem[ICONVIEW_RES_COUNTER_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  
  char string_tmp[10 + 1];
  
  if ((result != SUCCESS_EXEC) || (!int_to_str (resurs.lResourceCB, string_tmp))) 
  {
    string_tmp[0] = '?';
    string_tmp[1] = '\0';
  }
 TEXT_SetText(Resurs_v[0], string_tmp);

  if ((result != SUCCESS_EXEC) || (!int_to_str (resurs.lAmountSetOnCB, string_tmp))) 
  {
    string_tmp[0] = '?';
    string_tmp[1] = '\0';
  }
  TEXT_SetText(Resurs_v[1], string_tmp);
  
  WM_HWIN FocussedWindow = (Resurs_FrameWin);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
