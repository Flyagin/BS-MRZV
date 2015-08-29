#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Ініціалізація панелі для налаштувань
*****************************/
void settings_panel_show(void)
{
  if (Settings_IconView == WM_UNATTACHED)
  {
    Settings_IconView = ICONVIEW_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_SHOW | WM_CF_FGND, ICONVIEW_CF_AUTOSCROLLBAR_V, ID_SETTINGS_ICONVIEW, 64 + 7, /*64 + 12*/ 76 + 12);

    for (unsigned int i = 0; i < SETTINGS_SIZE; i++) 
    {
      const GUI_BITMAP *pBitmap;
      if (
          (i < 2) || 
          (i == SETTINGS_CB_ID) ||  
          (i == TRANSFORMER_ID) ||  
          (i == COMM_ID) || 
          (_CHECK_BIT_UCHAR(eeprom_prt_tbl.arUchCfgPrt, (i - 2))) 
         ) pBitmap = _aBitmapItem_settings[i].pBitmap;
      else
      {
        pBitmap = pBitmaps_prt_off[i - 2];
      }
      ICONVIEW_AddBitmapItem(Settings_IconView, pBitmap, _aBitmapItem_settings[i].pText[sel_language]);
    }
    ICONVIEW_SetBkColor(Settings_IconView, ICONVIEW_CI_BK, GUI_BLACK);
    ICONVIEW_SetBkColor(Settings_IconView, ICONVIEW_CI_SEL, GUI_BLUE | 0x50000000);
    ICONVIEW_SetTextColor(Settings_IconView, ICONVIEW_CI_UNSEL, GUI_RED);
    ICONVIEW_SetTextColor(Settings_IconView, ICONVIEW_CI_SEL, GUI_YELLOW);
    ICONVIEW_SetFont(Settings_IconView, &GUI_CourierNewBold14_8_Unicode);
  }
  WM_SetFocus(Settings_IconView);
}
/*****************************/

/*****************************
Ініціалізація панелі для налаштувань
*****************************/
void redraw_panel_settings(void)
{
  
  for (unsigned int i = 2; i < (2 + RESERV_CFG_PRT_ONB); i++) 
  {
    const GUI_BITMAP *pBitmap;
    if (_CHECK_BIT_UCHAR(eeprom_prt_tbl.arUchCfgPrt, (i - 2)))
      pBitmap = _aBitmapItem_settings[i].pBitmap;
    else
      pBitmap = pBitmaps_prt_off[i - 2];
    ICONVIEW_SetBitmapItem(Settings_IconView, i, pBitmap);
  }
  
  int sel_index = current_ekran.index_position;
  ICONVIEW_SetSel(Settings_IconView, sel_index);
  
  EDIT_SetText(hEdit, _aBitmapItem_settings[sel_index].pExplanation[sel_language]);
  WM_SetFocus(Settings_IconView);
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
