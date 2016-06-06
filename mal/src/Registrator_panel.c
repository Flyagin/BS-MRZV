#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Initializacija paneli dlja rejestratoriv
*****************************/
void registrators_panel_show(void)
{
  if (Registrators_FrameWin == WM_UNATTACHED)
  {
    //Stvorjujemo FrameWin
    Registrators_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, ID_REGISTRATORS_FRAMEWIN, Registrators_panel_title.ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbEmpty);
    FRAMEWIN_SetFont(Registrators_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(Registrators_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(Registrators_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(Registrators_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(Registrators_FrameWin, GUI_BLUE);

    //Створюємо вкладки для вибору груп уставок
    Registrators_MultiPage_type = MULTIPAGE_CreateEx(0, 0, X_SIZE, Y_SIZE, WM_GetClientWindow(Registrators_FrameWin), WM_CF_SHOW, 0, ID_REGISTRATORS_MULTIPAGE_TYPES); 
    WIDGET_OrState(Registrators_MultiPage_type, WIDGET_STATE_FOCUSSABLE);
    MULTIPAGE_SetFont(Registrators_MultiPage_type, &GUI_FontArialBold14_8_Unicode);
    MULTIPAGE_SetBkColor(Registrators_MultiPage_type, GUI_BLACK, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetTextColor(Registrators_MultiPage_type, GUI_BLACK, MULTIPAGE_CI_DISABLED);
    MULTIPAGE_SetTextColor(Registrators_MultiPage_type, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetRotation(Registrators_MultiPage_type, MULTIPAGE_CF_ROTATE_CW);
  
    Registrators_Window = WINDOW_CreateEx(0, 0, X_SIZE, Y_SIZE, WM_UNATTACHED,  WM_CF_SHOW, 0, ID_REGISTRATORS_WINDOW, _cbEmpty);
    WINDOW_SetBkColor(Registrators_Window, GUI_GRAY);
    Registrators_Window_up = WINDOW_CreateEx(0, 0, X_SIZE, Y_SIZE/6 - 1, WM_GetClientWindow(Registrators_Window),  WM_CF_SHOW, 0, ID_REGISTRATORS_WINDOW_UP, _cbEmpty);
    WINDOW_SetBkColor(Registrators_Window_up, GUI_GRAY);
    Registrators_Window_up_left = WINDOW_CreateEx(0, 0, 5*X_SIZE/12 - 1, Y_SIZE/6 - 1, WM_GetClientWindow(Registrators_Window_up),  WM_CF_SHOW, 0, ID_REGISTRATORS_WINDOW_UP_LEFT, _cbEmpty);
    Registrators_Window_up_right = WINDOW_CreateEx(5*X_SIZE/12 + 1, 0, 7*X_SIZE/12 - 1, Y_SIZE/6 - 1, WM_GetClientWindow(Registrators_Window_up),  WM_CF_SHOW, 0, ID_REGISTRATORS_WINDOW_UP_RIGHT, _cbEmpty);
    Registrators_Window_down = WINDOW_CreateEx(0, Y_SIZE/6 + 1, X_SIZE, 5*Y_SIZE/6 - 1, WM_GetClientWindow(Registrators_Window),  WM_CF_SHOW, 0, ID_REGISTRATORS_WINDOW_DOWN, _cbEmpty);

    Registrator_number = DROPDOWN_CreateEx(3, 5, 60, 15, WM_GetClientWindow(Registrators_Window_up_left), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, ID_REGISTRATOR_NUMBER);
    DROPDOWN_SetFont(Registrator_number, &GUI_FontArialStandard14_8_Unicode);
    DROPDOWN_SetBkColor(Registrator_number,DROPDOWN_CI_UNSEL, GUI_WHITE);
    DROPDOWN_SetBkColor(Registrator_number,DROPDOWN_CI_SEL,  GUI_WHITE);
    DROPDOWN_SetBkColor(Registrator_number,DROPDOWN_CI_SELFOCUS, GUI_WHITE);
    
    Registrator_number_from = TEXT_CreateEx(70, 10, 20, 15, WM_GetClientWindow(Registrators_Window_up_left), WM_CF_SHOW, TEXT_CF_HCENTER | TEXT_CF_VCENTER, ID_REGISTRATOR_NUMBER_FROM, title_from.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    TEXT_SetFont(Registrator_number_from, &GUI_FontArialStandard14_8_Unicode);

    Registrator_total_number = TEXT_CreateEx(100, 10, 30, 15, WM_GetClientWindow(Registrators_Window_up_left), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_REGISTRATOR_TOTAL_NUMBER, "???");
    TEXT_SetFont(Registrator_total_number, &GUI_FontArialStandard14_8_Unicode);
    
    Registrator_date_time_fault = TEXT_CreateEx(5, 3, 7*X_SIZE/12 - 1 - 1, 10, WM_GetClientWindow(Registrators_Window_up_right), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_REGISTRATOR_DT_FAULT, "Date & Time fault");
    TEXT_SetFont(Registrator_date_time_fault, &GUI_FontArialStandard14_8_Unicode);

    Registrator_date_time_prefault = TEXT_CreateEx(5, 20, 7*X_SIZE/12 - 1 - 1, 10, WM_GetClientWindow(Registrators_Window_up_right), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, ID_REGISTRATOR_DT_PREFAULT, "Date & Time prefault");
    TEXT_SetFont(Registrator_date_time_prefault, &GUI_FontArialStandard14_8_Unicode);
    
    for (unsigned int i = 0; i < 3; i++)
    {
      MULTIPAGE_AddPage(Registrators_MultiPage_type, Registrators_Window, Registrators_MultiPage_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
      MULTIPAGE_DisablePage(Registrators_MultiPage_type, i);
    }
    MULTIPAGE_EnablePage(Registrators_MultiPage_type, current_ekran.index_position);
    MULTIPAGE_SelectPage(Registrators_MultiPage_type, current_ekran.index_position);
  }
  
  WM_BringToTop(Registrators_FrameWin);
  WM_ShowWindow(Registrators_FrameWin);
  
}
/*****************************/

/*****************************
Peremaljovuvannja paneli dlja rejestratoriv
*****************************/
void redraw_panel_registrators(void)
{
  EDIT_SetText(hEdit, _aBitmapItem[ICONVIEW_REGISTRATORS_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  
  int index_position_tmp = current_ekran.index_position;
  if (MULTIPAGE_GetSelection(Registrators_MultiPage_type) != index_position_tmp)
  {
    for (int i = 0; i < 3; i++)
    {
      if(i != index_position_tmp) 
      {
        MULTIPAGE_DisablePage(Registrators_MultiPage_type, i);
      }
      else
      {
        MULTIPAGE_EnablePage(Registrators_MultiPage_type, index_position_tmp);
        MULTIPAGE_SelectPage(Registrators_MultiPage_type, index_position_tmp);
      }
    }
  }
  
  WM_HWIN FocussedWindow = (Registrators_FrameWin);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
