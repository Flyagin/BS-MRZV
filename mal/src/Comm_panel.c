#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Ініціалізація панелі для налаштувань
*****************************/
void Comm_panel_show(void)
{
  if (Comm_IconView == WM_UNATTACHED)
  {
    Comm_IconView = ICONVIEW_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_SHOW | WM_CF_FGND, ICONVIEW_CF_AUTOSCROLLBAR_V, ID_COMM_ICONVIEW, 64 + 7, /*64 + 12*/ 76 + 12);

    for (unsigned int i = 0; i < COMM_SIZE; i++) 
    {
      ICONVIEW_AddBitmapItem(Comm_IconView, _aBitmapItem_Comm[i].pBitmap, _aBitmapItem_Comm[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
    }
    ICONVIEW_SetBkColor(Comm_IconView, ICONVIEW_CI_BK, GUI_BLACK);
    ICONVIEW_SetBkColor(Comm_IconView, ICONVIEW_CI_SEL, GUI_BLUE | 0x50000000);
    ICONVIEW_SetTextColor(Comm_IconView, ICONVIEW_CI_UNSEL, GUI_RED);
    ICONVIEW_SetTextColor(Comm_IconView, ICONVIEW_CI_SEL, GUI_YELLOW);
    ICONVIEW_SetFont(Comm_IconView, &GUI_CourierNewBold14_8_Unicode);
  }
  WM_SetFocus(Comm_IconView);
}
/*****************************/

/*****************************
Ініціалізація панелі для налаштувань
*****************************/
void redraw_panel_Comm(void)
{
  int sel_index = current_ekran.index_position;
  ICONVIEW_SetSel(Comm_IconView, sel_index);
  
  EDIT_SetText(hEdit, _aBitmapItem_Comm[sel_index].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  WM_SetFocus(Comm_IconView);
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
