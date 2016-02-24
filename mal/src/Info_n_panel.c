#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Вибір сторінки
*****************************/
void select_multipage_info_n(WM_HWIN widget, int index, unsigned int number_pages) 
{
  if (MULTIPAGE_GetSelection(widget) != index)
  {
    for (unsigned int i = 0; i < number_pages; i++)
    {
      if(i != index) 
      {
        MULTIPAGE_DisablePage(widget, i);
      }
      else
      {
        MULTIPAGE_EnablePage(widget, index);
        MULTIPAGE_SelectPage(widget, index);
      }
    }
  }
}
/*****************************/

/*****************************
Ініціалізація панелі для захистів
*****************************/
void info_n_panel_show(unsigned int id_protection)
{
  _id_user_widget id_info_n_framewin, id_info_n_multipage_type_info, id_info_n_page_1;

  const TITLE *Info_n_panel_title;
  const LANG_ITEM *Page_name;
  
  WM_HWIN *Info_n_FrameWin, *Info_n_MultiPage_type_info, *Info_n_Pages, *ScrollBar_Info_n_Pages;
  unsigned int number_pages;

  switch (id_protection)
  {
  case ID_TM_PG:
    {
      number_pages = 2;
      
      id_info_n_framewin = ID_TM_FRAMEWIN;
      Info_n_panel_title = &TM_panel_title;
      Info_n_FrameWin = &TM_FrameWin;

      id_info_n_multipage_type_info = ID_TM_MULTIPAGE_TYPE_INFO;
      Info_n_MultiPage_type_info = &TM_MultiPage_type_info;
      
      id_info_n_page_1 = ID_TM_PAGE_1;
      Info_n_Pages = TM_Pages;
      Page_name = TM_Page_name;
      
      ScrollBar_Info_n_Pages = ScrollBar_TM_Pages;

      break;
    }
  case ID_DIAGNOSTICS_PG:
    {
      number_pages = 4;
      
      id_info_n_framewin = ID_DIAGNOSTICS_FRAMEWIN;
      Info_n_panel_title = &Diagnostics_panel_title;
      Info_n_FrameWin = &Diagnostics_FrameWin;

      id_info_n_multipage_type_info = ID_DIAGNOSTICS_MULTIPAGE_TYPE_INFO;
      Info_n_MultiPage_type_info = &Diagnostics_MultiPage_type_info;
      
      id_info_n_page_1 = ID_DIAGNOSTICS_PAGE;
      Info_n_Pages = &Diagnostics_Pages;
      Page_name = Diagnostics_Page_name;
      
      ScrollBar_Info_n_Pages = &ScrollBar_Diagnostics_Pages;

      break;
    }
  default:
    {
      //Сюди програма ніколи б не мала зайти
      while(1);
    }
  }
  
  if (*Info_n_FrameWin == WM_UNATTACHED)
  {
    
    //Створюємо FrameWin
    *Info_n_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, id_info_n_framewin, Info_n_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbEmpty);
    FRAMEWIN_SetFont(*Info_n_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(*Info_n_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(*Info_n_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(*Info_n_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(*Info_n_FrameWin, GUI_BLUE);
 
    //Створюємо вкладки
    *Info_n_MultiPage_type_info = MULTIPAGE_CreateEx(0, 0, X_SIZE, (Y_SIZE - 20), WM_GetClientWindow(*Info_n_FrameWin), WM_CF_SHOW, 0, id_info_n_multipage_type_info);
    WIDGET_OrState(*Info_n_MultiPage_type_info, WIDGET_STATE_FOCUSSABLE);
    MULTIPAGE_SetBkColor(*Info_n_MultiPage_type_info, GUI_BLACK, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetTextColor(*Info_n_MultiPage_type_info, GUI_BLACK, MULTIPAGE_CI_DISABLED);
    MULTIPAGE_SetTextColor(*Info_n_MultiPage_type_info, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetFont(*Info_n_MultiPage_type_info, &GUI_FontArialBold14_8_Unicode);
    MULTIPAGE_SetAlign(*Info_n_MultiPage_type_info, /*(MULTIPAGE_ALIGN_TOP | MULTIPAGE_ALIGN_LEFT)*/(MULTIPAGE_ALIGN_BOTTOM | MULTIPAGE_ALIGN_LEFT));
    
    if (id_protection == ID_TM_PG)
    {
      for (unsigned int i = 0; i < number_pages; i++)
      {
        WM_CALLBACK *cb  = _cbEmpty;

        *(Info_n_Pages + i) = WINDOW_CreateEx(0, 0, (X_SIZE - 6), Y_SIZE - 42,  WM_UNATTACHED,  WM_CF_SHOW, 0, id_info_n_page_1 + i, cb);
        WINDOW_SetBkColor(*(Info_n_Pages + i), GUI_GRAY);

        MULTIPAGE_AddPage(*Info_n_MultiPage_type_info, *(Info_n_Pages + i), Page_name[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
        MULTIPAGE_DisablePage(*Info_n_MultiPage_type_info, i);
      }
      MULTIPAGE_EnablePage(*Info_n_MultiPage_type_info, 0);
      MULTIPAGE_SelectPage(*Info_n_MultiPage_type_info, 0);
    
      TM_IO_Header = HEADER_CreateAttached(TM_Pages[0], ID_TM_IO_HEADER, 0);
      HEADER_SetFont(TM_IO_Header, &GUI_FontArialBold14_8_Unicode);
      HEADER_AddItem(TM_IO_Header, (X_SIZE - 6)/2, TM_IO_columns[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText], GUI_TA_VCENTER | GUI_TA_HCENTER);
      TM_IO_Pages[0] = WINDOW_CreateEx(0, 15, (X_SIZE - 6)/2 - 1, Y_SIZE - 52,  WM_GetClientWindow(TM_Pages[0]),  WM_CF_SHOW, 0, ID_TM_IO_PAGE_1, _cbEmpty);
      HEADER_AddItem(TM_IO_Header, (X_SIZE - 6)/2, TM_IO_columns[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText], GUI_TA_VCENTER | GUI_TA_HCENTER);
      TM_IO_Pages[1] = WINDOW_CreateEx((X_SIZE - 6)/2 + 1, 15, (X_SIZE - 6)/2 - 1, Y_SIZE - 52,  WM_GetClientWindow(TM_Pages[0]),  WM_CF_SHOW, 0, ID_TM_IO_PAGE_2, _cbEmpty);

      *(ScrollBar_Info_n_Pages + 1) = SCROLLBAR_CreateAttached(WM_GetClientWindow(*(Info_n_Pages + 1)), SCROLLBAR_CF_VERTICAL);
      SCROLLBAR_SetPageSize(*(ScrollBar_Info_n_Pages + 1), MAX_NUMBER_F_IN_PANEL);

      TM_F_Header = HEADER_CreateAttached(TM_Pages[1], ID_TM_F_HEADER, 0);
      HEADER_SetFont(TM_F_Header, &GUI_FontArialBold14_8_Unicode);
      HEADER_AddItem(TM_F_Header, (X_SIZE - 6 - 10)/2, TM_F_columns[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText], GUI_TA_VCENTER | GUI_TA_HCENTER);
      TM_F_Pages[0] = WINDOW_CreateEx(0, 15, (X_SIZE - 6 - 10)/2 - 1, Y_SIZE - 52,  WM_GetClientWindow(TM_Pages[1]),  WM_CF_SHOW, 0, ID_TM_F_PAGE_1, _cbEmpty);
      WINDOW_SetBkColor(TM_F_Pages[0], GUI_WHITE);
      HEADER_AddItem(TM_F_Header, (X_SIZE - 6 - 10)/2, TM_F_columns[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText], GUI_TA_VCENTER | GUI_TA_HCENTER);
      TM_F_Pages[1] = WINDOW_CreateEx((X_SIZE - 6 - 10)/2 + 1, 15, (X_SIZE - 6 - 10)/2 - 1, Y_SIZE - 52,  WM_GetClientWindow(TM_Pages[1]),  WM_CF_SHOW, 0, ID_TM_F_PAGE_2, _cbEmpty);
      WINDOW_SetBkColor(TM_F_Pages[1], GUI_WHITE);

#define X_START         3
#define X_WHIGHT        15
#define X_INTERVAL      3
#define Y_START         3
#define Y_HIGHT         15
#define Y_INTERVAL      3
      
      for (unsigned int i = 0; i < NUM_IN; i++)
      {
        TM_Inputs[i] = BUTTON_CreateEx(X_START + (i % 8)*(X_WHIGHT + X_INTERVAL), Y_START + (i / 8)*(Y_HIGHT + Y_INTERVAL), X_WHIGHT, Y_HIGHT, WM_GetClientWindow(TM_IO_Pages[0]), WM_CF_SHOW, 0, ID_TM_INPUT_1 + i);
        BUTTON_SetFont(TM_Inputs[i], &GUI_FontArialBold14_8_Unicode);
        
        char number_chars[3] = {'\0', '\0', '\0'};
        if ((i + 1) < 10)
        {
          number_chars[0] = (i + 1) + 0x30;
        }
        else
        {
          number_chars[0] = (i + 1)/10 + 0x30;
          number_chars[1] = (i + 1)%10 + 0x30;
        }
        BUTTON_SetText(TM_Inputs[i], number_chars);

      }

      for (unsigned int i = 0; i < NUM_OUT; i++)
      {
        TM_Outputs[i] = BUTTON_CreateEx(X_START + (i % 8)*(X_WHIGHT + X_INTERVAL), Y_START + (i / 8)*(Y_HIGHT + Y_INTERVAL), X_WHIGHT, Y_HIGHT, WM_GetClientWindow(TM_IO_Pages[1]), WM_CF_SHOW, 0, ID_TM_OUTPUT_1 + i);
        BUTTON_SetFont(TM_Outputs[i], &GUI_FontArialBold14_8_Unicode);
        
        char number_chars[3] = {'\0', '\0', '\0'};
        if ((i + 1) < 10)
        {
          number_chars[0] = (i + 1) + 0x30;
        }
        else
        {
          number_chars[0] = (i + 1)/10 + 0x30;
          number_chars[1] = (i + 1)%10 + 0x30;
        }
        BUTTON_SetText(TM_Outputs[i], number_chars);

      }
#undef X_START
#undef X_WHIGHT
#undef X_INTERVAL
#undef Y_START
#undef Y_HIGHT
#undef Y_INTERVAL
      
#define X_START         3
#define X_WHIGHT        (X_SIZE - 6 - 10)/2 - 1 - X_START
#define Y_START         2
#define Y_WHIGHT        12
#define Y_INTERVAL      2
      
      for (unsigned int i = 0; i < 2; i++)
      {
        _id_user_widget id_base_f = (i == 0) ? ID_TM_F1_1 : ID_TM_F2_1;
        for (unsigned int j = 0; j < MAX_NUMBER_F_IN_PANEL; j++)
        {
          char empty = '\0';
          TM_F[i][j] = TEXT_CreateEx(X_START, Y_START + j*(Y_WHIGHT + Y_INTERVAL), X_WHIGHT, Y_WHIGHT, WM_GetClientWindow(TM_F_Pages[i]), WM_CF_SHOW, TEXT_CF_LEFT | GUI_TA_BOTTOM, id_base_f + j,  &empty);
          TEXT_SetFont(TM_F[i][j], &GUI_FontArialStandard14_8_Unicode);
        }
      }
      
#undef X_START
#undef X_WHIGHT
#undef Y_START
#undef Y_WHIGHT
#undef Y_INTERVAL
    }
    else if (id_protection == ID_DIAGNOSTICS_PG)
    {
      WM_CALLBACK *cb = _cbEmpty;

      *Info_n_Pages = WINDOW_CreateEx(0, 0, (X_SIZE - 6), Y_SIZE - 42,  WM_UNATTACHED,  WM_CF_SHOW, 0, id_info_n_page_1, cb);
      WINDOW_SetBkColor(*Info_n_Pages, GUI_WHITE);

      for (unsigned int i = 0; i < number_pages; i++)
      {
        MULTIPAGE_AddPage(*Info_n_MultiPage_type_info, *Info_n_Pages, Page_name[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
        MULTIPAGE_DisablePage(*Info_n_MultiPage_type_info, i);
      }
      MULTIPAGE_EnablePage(*Info_n_MultiPage_type_info, 0);
      MULTIPAGE_SelectPage(*Info_n_MultiPage_type_info, 0);
    
      *ScrollBar_Info_n_Pages = SCROLLBAR_CreateAttached(WM_GetClientWindow(*Info_n_Pages), SCROLLBAR_CF_VERTICAL);
      SCROLLBAR_SetPageSize(*ScrollBar_Info_n_Pages, MAX_NUMBER_DIAGN_IN_PANEL);

#define X_START         3
#define X_WHIGHT        (X_SIZE - 6 - 10) - 1 - X_START
#define Y_START         2
#define Y_WHIGHT        12
#define Y_INTERVAL      2
      
      _id_user_widget id_base_info = ID_DIAGNOSTICS_INFO_1;
      for (unsigned int i = 0; i < MAX_NUMBER_DIAGN_IN_PANEL; i++)
      {
        char empty = '\0';
        Diagnostics_Info[i] = TEXT_CreateEx(X_START, Y_START + i*(Y_WHIGHT + Y_INTERVAL), X_WHIGHT, Y_WHIGHT, WM_GetClientWindow(*Info_n_Pages), WM_CF_SHOW, TEXT_CF_LEFT | GUI_TA_BOTTOM, id_base_info + i,  &empty);
        TEXT_SetFont(Diagnostics_Info[i], &GUI_CourierNewStandard14_8_Unicode);
      }
      
#undef X_START
#undef X_WHIGHT
#undef Y_START
#undef Y_WHIGHT
#undef Y_INTERVAL
    }
  }
  
  WM_BringToTop(*Info_n_FrameWin);
  WM_ShowWindow(*Info_n_FrameWin);
}
/*****************************/

/*****************************
Обновлення інформації на панелі вибраного захисту
*****************************/
void redraw_panel_info_n(__index_level_menu id_protection)
{
  WM_HWIN *Info_n_MultiPage_type_info;
  unsigned int number_pages;
  
  switch (id_protection)
  {
  case ID_TM_PG:
    {
      Info_n_MultiPage_type_info = &TM_MultiPage_type_info;
      
      number_pages = 2;

      EDIT_SetText(hEdit, _aBitmapItem[ICONVIEW_IO_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
      break;
    }
  case ID_DIAGNOSTICS_PG:
    {
      Info_n_MultiPage_type_info = &Diagnostics_MultiPage_type_info;
      
      number_pages = 4;

      EDIT_SetText(hEdit, _aBitmapItem[ICONVIEW_DIAGN_ID].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
      break;
    }
  default:
    {
      //Сюди програма ніколи б не мала зайти
      while(1);
    }
  }

  select_multipage_info_n(*Info_n_MultiPage_type_info, current_ekran.index_position, number_pages);
  
  if (id_protection == ID_TM_PG)
  {
    switch (current_ekran.index_position)
    {
    case 0:
      {
        unsigned int error_res = false;
        TeleMechsInfoDsc locTeleMechsInfo;
        unsigned int *p_state_inputs_tmp;
        unsigned int *p_state_outputs_tmp;
        unsigned int *p_state_outputs_trg_tmp;
        
        long Key = GetUserKeyTeleMechsData();
        if ((Key > 0) && (Key <= 16))
        {
          long lRes = GetTeleMechsData(Key,(void*)&locTeleMechsInfo);
          if (lRes != SUCCESS_EXEC)
          {
            if ((lRes == ERROR_EXEC) || (lRes == STATE_EXEC))
            {
              lRes = GetTeleMechsData(Key,(void*)&locTeleMechsInfo);
              if (lRes != SUCCESS_EXEC) error_res = true;
            }
            else error_res = true;
          }
          
          ReturnUserKeyTeleMechsData(Key);
        }
        else error_res = true;
        
        if (error_res == false)
        {
          p_state_inputs_tmp      = (unsigned int *)locTeleMechsInfo.chArIn;
          p_state_outputs_tmp     = (unsigned int *)locTeleMechsInfo.chArOut;
          p_state_outputs_trg_tmp = (unsigned int *)locTeleMechsInfo.chArOutTrg;
        }
        
        for (unsigned int i = 0; i < NUM_IN; i++)
        {
          GUI_COLOR Color_Bk, Color_Text;
          if (error_res == false)
          {
            if (*p_state_inputs_tmp & (1 << i))
            {
              Color_Bk = GUI_RED;
              Color_Text =  GUI_WHITE;
            }
            else
            {
              Color_Bk = GUI_WHITE;
              Color_Text =  GUI_BLACK;
            }
          }
          else
          {
            Color_Bk = GUI_YELLOW;
            Color_Text = GUI_BLACK;
          }
          BUTTON_SetBkColor(TM_Inputs[i], BUTTON_CI_UNPRESSED, Color_Bk);
          BUTTON_SetTextColor(TM_Inputs[i], BUTTON_CI_UNPRESSED, Color_Text);
        }

        for (unsigned int i = 0; i < NUM_OUT; i++)
        {
          GUI_COLOR Color_Bk, Color_Text;
          if (error_res == false)
          {
            if ((*p_state_outputs_tmp | *p_state_outputs_trg_tmp) & (1 << i))
            {
              Color_Bk =  GUI_RED;
              Color_Text =  GUI_WHITE;
            }
            else
            {
              Color_Bk =  GUI_WHITE;
              Color_Text =  GUI_BLACK;
            }
          }
          else
          {
            Color_Bk = GUI_YELLOW;
            Color_Text = GUI_BLACK;
          }
          BUTTON_SetBkColor(TM_Outputs[i], BUTTON_CI_UNPRESSED, Color_Bk);
          BUTTON_SetTextColor(TM_Outputs[i], BUTTON_CI_UNPRESSED, Color_Text);
        }
      
        break;
      }
    case 1:
      {
        unsigned int TM_max_number_bits_tmp = (TM_max_number_bits < MAX_NUMBER_F_IN_PANEL) ? MAX_NUMBER_F_IN_PANEL : TM_max_number_bits;
        SCROLLBAR_SetNumItems(ScrollBar_TM_Pages[1], TM_max_number_bits_tmp);
        SCROLLBAR_SetValue(ScrollBar_TM_Pages[1], current_ekran.index_position_1);

        for (unsigned int i = 0; i < 2; i++)
        {
          unsigned int *target_array = (i == 0) ? state_active_functions : state_actuated_functions;
          
          unsigned int number_set_bits = 0;
          for (unsigned int j = 0; j < All_NUMB_RANK_ELEM; j++)
          {
            if (target_array[j >> 5] & (1 << (j & 0x1f))) number_set_bits++;
          }
          
          char empty = '\0';
          if (
              (number_set_bits == 0) &&
              (current_ekran.index_position_1 < MAX_NUMBER_F_IN_PANEL)
             ) 
          {
            TEXT_SetTextAlign(TM_F[i][0], TEXT_CF_HCENTER | TEXT_CF_BOTTOM);
            TEXT_SetText(TM_F[i][0], NONE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

            for (unsigned int j = 1; j < MAX_NUMBER_F_IN_PANEL; j++)
            {
              TEXT_SetText(TM_F[i][j], &empty);
            }
          }
          else
          {
            TEXT_SetTextAlign(TM_F[i][0], TEXT_CF_LEFT | TEXT_CF_BOTTOM);

            unsigned int continue_index = 0;
            for (int j = 0; j < current_ekran.index_position_1; j++)
            {
              while (
                     ((target_array[continue_index >> 5] & (1 << (continue_index & 0x1f))) == 0) &&
                     (continue_index < All_NUMB_RANK_ELEM)  
                    )
              {
                continue_index++;
              }
              
              if ((++continue_index) >= All_NUMB_RANK_ELEM) break; 
            }
            
            for (unsigned int j = 0; j < MAX_NUMBER_F_IN_PANEL; j++)
            {
              char *point_string;
              if ((current_ekran.index_position_1 + j) < number_set_bits)
              {
                unsigned int bit;
                while (
                       ((bit = (target_array[continue_index >> 5] & (1 << (continue_index & 0x1f)))) == 0) &&
                       (continue_index < All_NUMB_RANK_ELEM)  
                      )
                {
                  continue_index++;
                }

                char interrogatory[]  = "???";
                point_string = ((bit != 0) && (continue_index < All_NUMB_RANK_ELEM)) ? rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][continue_index++] : interrogatory;
              }
              else point_string = &empty;
              
              TEXT_SetText(TM_F[i][j], point_string);
            }
          }
        }

        break;
      }
    default:
      {
        while(1);
      }
    }
  }
  else if (id_protection == ID_DIAGNOSTICS_PG)
  {
    switch (current_ekran.index_position)
    {
    case 0:
    case 1:
    case 2:
      {
        unsigned int Diagnostics_max_number_bits_tmp = (Diagnistics_max_number_bits[current_ekran.index_position] < MAX_NUMBER_DIAGN_IN_PANEL) ? MAX_NUMBER_DIAGN_IN_PANEL : Diagnistics_max_number_bits[current_ekran.index_position];
        SCROLLBAR_SetNumItems(ScrollBar_Diagnostics_Pages, Diagnostics_max_number_bits_tmp);
        SCROLLBAR_SetValue(ScrollBar_Diagnostics_Pages, current_ekran.index_position_1);
        
        unsigned int *target_array;
        char *(*target_name)[ALL_NUMB_DIAGNOSTICS];
        if (current_ekran.index_position == 0)
        {
          target_array = diagnostics_bs_mrzv_tmp;
          target_name = diagnostics_bs_mrzv_str_tmp;
        }
        else if (current_ekran.index_position == 1)
        {
          target_array = diagnostics_bo_mrzv_m_tmp;
          target_name = diagnostics_bo_mrzv_m_str_tmp;
        }
        else
        {
          target_array = diagnostics_bo_mrzv_l_tmp;
          target_name = diagnostics_bo_mrzv_l_str_tmp;
        }
          
        unsigned int number_set_bits = 0;
        for (unsigned int j = 0; j < ALL_NUMB_DIAGNOSTICS; j++)
        {
          if (target_array[j >> 5] & (1 << (j & 0x1f))) number_set_bits++;
        }
          
        char empty = '\0';
        if (
            (number_set_bits == 0) &&
            (current_ekran.index_position_1 < MAX_NUMBER_DIAGN_IN_PANEL)
           ) 
        {
          TEXT_SetTextAlign(Diagnostics_Info[0], TEXT_CF_HCENTER | TEXT_CF_BOTTOM);
          TEXT_SetText(Diagnostics_Info[0], NONE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);

          for (unsigned int j = 1; j < MAX_NUMBER_DIAGN_IN_PANEL; j++)
          {
            TEXT_SetText(Diagnostics_Info[j], &empty);
          }
        }
        else
        {
          TEXT_SetTextAlign(Diagnostics_Info[0], TEXT_CF_LEFT | TEXT_CF_BOTTOM);

          unsigned int continue_index = 0;
          for (int i = 0; i < current_ekran.index_position_1; i++)
          {
            while (
                   ((target_array[continue_index >> 5] & (1 << (continue_index & 0x1f))) == 0) &&
                   (continue_index < ALL_NUMB_DIAGNOSTICS)  
                  )
            {
              continue_index++;
            }
              
            if ((++continue_index) >= ALL_NUMB_DIAGNOSTICS) break; 
          }
            
          for (unsigned int i = 0; i < MAX_NUMBER_DIAGN_IN_PANEL; i++)
          {
            char *point_string;
            if ((current_ekran.index_position_1 + i) < number_set_bits)
            {
              unsigned int bit;
              while (
                     ((bit = (target_array[continue_index >> 5] & (1 << (continue_index & 0x1f)))) == 0) &&
                     (continue_index < ALL_NUMB_DIAGNOSTICS)  
                    )
              {
                continue_index++;
              }

              char interrogatory[]  = "???";
              point_string = ((bit != 0) && (continue_index < All_NUMB_RANK_ELEM)) ? target_name[eeprom_bs_settings_tbl.chLngGUIText][continue_index++] : interrogatory;
            }
            else point_string = &empty;
              
            TEXT_SetText(Diagnostics_Info[i], point_string);
          }
        }

        break;
      }
    case 3:
      {
        unsigned int Diagnostics_max_number_bits_tmp = (Diagnistics_max_number_bits[current_ekran.index_position] < MAX_NUMBER_DIAGN_IN_PANEL) ? MAX_NUMBER_DIAGN_IN_PANEL : Diagnistics_max_number_bits[current_ekran.index_position];
        SCROLLBAR_SetNumItems(ScrollBar_Diagnostics_Pages, Diagnostics_max_number_bits_tmp);
        SCROLLBAR_SetValue(ScrollBar_Diagnostics_Pages, current_ekran.index_position_1);
        
        char empty = '\0';
        char string[30 + 1 + 10 + 1];/*30 - zagolovok; 1 - znak; 10 - chyslo; 1 symvol kincja rjadka*/
        TEXT_SetTextAlign(Diagnostics_Info[0], TEXT_CF_LEFT | TEXT_CF_BOTTOM);

        for (unsigned int i = 0; i < MAX_NUMBER_DIAGN_IN_PANEL; i++)
        {
          char *point_string;
          string[0] = '\0';
          
          char string_digit[1 + 10 + 1];
          switch (current_ekran.index_position_1 + i)
          {
          case 0:
            {
              strcat_mal(string, "  uiAmtSpiGoodPacket          ");
              
              extern unsigned long uiAmtSpiGoodPacket;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              unsigned long temp_value = uiAmtSpiGoodPacket;
              string_digit[0] = ' ';
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 1:
            {
              strcat_mal(string, "  uiAmtSpiBadPacket           ");
              
              extern unsigned long uiAmtSpiBadPacket;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              unsigned long temp_value = uiAmtSpiBadPacket;
              string_digit[0] = ' ';
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 2:
            {
              strcat_mal(string, "  lAmtCallReInitDmaSpi        ");
              
              extern long lAmtCallReInitDmaSpi;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              long temp_value = lAmtCallReInitDmaSpi;
              if (temp_value >= 0)
              {
                string_digit[0] = ' ';
              }
              else
              {
                string_digit[0] = '-';
                temp_value = -temp_value;
              }
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 3:
            {
              strcat_mal(string, "  uiAmtU2BadPacket            ");
              
              extern unsigned long uiAmtU2BadPacket;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              unsigned long temp_value = uiAmtU2BadPacket;
              string_digit[0] = ' ';
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 4:
            {
              strcat_mal(string, "  uiAmtU2GoodPacket           ");
              
              extern unsigned long uiAmtU2GoodPacket;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              unsigned long temp_value = uiAmtU2GoodPacket;
              string_digit[0] = ' ';
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 5:
            {
              strcat_mal(string, "  ulCtrTransmitLpduHSU2       ");
              
              extern unsigned long ulCtrTransmitLpduHSU2;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              unsigned long temp_value = ulCtrTransmitLpduHSU2;
              string_digit[0] = ' ';
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 6:
            {
              strcat_mal(string, "  lCtrCallsTrLpduHSU2         ");
              
              extern long lCtrCallsTrLpduHSU2;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              long temp_value = lCtrCallsTrLpduHSU2;
              if (temp_value >= 0)
              {
                string_digit[0] = ' ';
              }
              else
              {
                string_digit[0] = '-';
                temp_value = -temp_value;
              }
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 7:
            {
              strcat_mal(string, "  lTcr_Tncr_Set               ");
              
              extern long lTcr_Tncr_Set;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              long temp_value = lTcr_Tncr_Set;
              if (temp_value >= 0)
              {
                string_digit[0] = ' ';
              }
              else
              {
                string_digit[0] = '-';
                temp_value = -temp_value;
              }
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          case 8:
            {
              strcat_mal(string, "  ulAmountReinitU2            ");
              
              extern long ulAmountReinitU2;
              
              unsigned int digits_tmp[10];
              unsigned int number_digits = 0;
              long temp_value = ulAmountReinitU2;
              if (temp_value >= 0)
              {
                string_digit[0] = ' ';
              }
              else
              {
                string_digit[0] = '-';
                temp_value = -temp_value;
              }
              do
              {
                digits_tmp[number_digits++] = temp_value % 10;
                temp_value /= 10;
              }
              while (temp_value > 0);
              
              for (unsigned int j = 0; j < number_digits; j++) string_digit[1 + j] = 0x30 + digits_tmp[number_digits - 1 - j];
              string_digit[1 + number_digits] = '\0';
              strcat_mal(string, string_digit);
              
              point_string = string;
              break;
            }
          default:
            {
              point_string = &empty;
            }
          }
//          if ((current_ekran.index_position_1 + i) < number_rows)
//          {
//
//            char interrogatory[]  = "???";
//            point_string = ((bit != 0) && (continue_index < All_NUMB_RANK_ELEM)) ? target_name[eeprom_bs_settings_tbl.chLngGUIText][continue_index++] : interrogatory;
//            
//          }
//          else point_string = &empty;
              
          TEXT_SetText(Diagnostics_Info[i], point_string);
        }

        break;
      }
    default:
      {
        while(1);
      }
    }
  }
  
  
  
  WM_HWIN FocussedWindow = *Info_n_MultiPage_type_info;

  WM_SetFocus(FocussedWindow);
}
/*****************************/

#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
