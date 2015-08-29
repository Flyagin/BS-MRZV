
#include "gui_header.h"

#include "header_mal.h"

/**
* 
* @param win_id - идентификатор окна которое нужно отобразить.
*                 Если id == GUI_NULL (-1) или для другого некорректного значения
*                 операция не должна выполняться.
*/
void show_window(int win_id) {
  switch (win_id) {
    case ID_EKRAN_MAIN:
      {
        WM_ShowWindow(iconWin);
        WM_SetFocus(iconWin);
        break;
      }
    case ID_LANG_DLG:
      {
        if (langWin == WM_UNATTACHED) {
          lang_dlg_init();
        }
        break;
      }
    case ID_MEAS_PG:
      {
        measurement_panel_init();
        break;
      }
    case ID_CONFIG_PG:
      {
        configuration_panel_init();
        break;
      }
    case ID_RANK_PG:
      {
        WM_ShowWindow(rankMultiPageWin);
        break;
      }
    case ID_RANK_DI_DLG:
      {
        rank_dlg_di_init();
        break;
      }
    case ID_RANK_DO_DLG:
      {
        rank_dlg_do_init();
        break;
      }
    case ID_RANK_LED_DLG:
      {
        rank_dlg_led_init();
        break;
      }
    case ID_RANK_DF_DLG:
      {
        rank_dlg_df_init();
        break;
      }
    case ID_RANK_AN_REC_DLG:
      {
        rank_dlg_an_rec_init();
        break;
      }
      
    case ID_DIALOG_PASSWORD:
      {
        dialog_password_show(ID_DIALOG_PASSWORD, 0);
        break;
      }
    case ID_DIALOG_PASSWORD_LEVEL_2:
    case ID_DIALOG_PASSWORD_OLD_1:
    case ID_DIALOG_PASSWORD_OLD_2:
    case ID_DIALOG_PASSWORD_NEW_1:
    case ID_DIALOG_PASSWORD_NEW_2:
      {
        dialog_password_show(win_id, win_id - ID_DIALOG_PASSWORD_LEVEL_2);
        break;
      }
    case ID_DIALOG_CONFIRMATION:
    case ID_DIALOG_CONFIRMATION_LEVEL_2:
      {
        dialog_confirmation_show(win_id);
        break;
      }
    case ID_DIALOG_ERROR:
      {
        switch (previous_level_in_current_level_menu[ID_DIALOG_ERROR])
        {
        case ID_RANK_PG:
          {
            if (checkAllRankVal()) {
              Dialog_error_message.ptitle[0] = MESSAGE_RANK_UKR;
              Dialog_error_message.ptitle[1] = MESSAGE_RANK_RUS;
              Dialog_error_message.ptitle[2] = MESSAGE_RANK_ENG;
            } else {
              Dialog_error_message.ptitle[0] = ERROR_PARAMS_MSG_UKR;
              Dialog_error_message.ptitle[1] = ERROR_PARAMS_MSG_RUS;
              Dialog_error_message.ptitle[2] = ERROR_PARAMS_MSG_ENG;
            }
            break;
          }
        case ID_CONFIG_PG:
          {
            Dialog_error_message.ptitle[0] = MESSAGE_CONFIG_UKR;
            Dialog_error_message.ptitle[1] = MESSAGE_CONFIG_RUS;
            Dialog_error_message.ptitle[2] = MESSAGE_CONFIG_ENG;
            break;
          }
        case ID_SETTINGS_PG:
          {
            Dialog_error_message.ptitle[0] = ERROR_SETTINGS_MSG_UKR;
            Dialog_error_message.ptitle[1] = ERROR_SETTINGS_MSG_RUS;
            Dialog_error_message.ptitle[2] = ERROR_SETTINGS_MSG_ENG;
            break;
          }
        default:
          {
            Dialog_error_message.ptitle[0] = ERROR_PARAMS_MSG_UKR;
            Dialog_error_message.ptitle[1] = ERROR_PARAMS_MSG_RUS;
            Dialog_error_message.ptitle[2] = ERROR_PARAMS_MSG_ENG;
            break;
          }
        }

        dialog_error_show(ID_DIALOG_ERROR);
        break;
      }
    case ID_DIALOG_ERROR_LEVEL_2:
      {
        switch (previous_level_in_current_level_menu[ID_DIALOG_ERROR_LEVEL_2])
        {
        case ID_DIALOG_PASSWORD_NEW_2:
          {
            Dialog_error_level_2_message.ptitle[0] = ERROR_PASSWORD_2_MSG_UKR;
            Dialog_error_level_2_message.ptitle[1] = ERROR_PASSWORD_2_MSG_RUS;
            Dialog_error_level_2_message.ptitle[2] = ERROR_PASSWORD_2_MSG_ENG;
            
            break;
          }
        default:
          {
            Dialog_error_level_2_message.ptitle[0] = ERROR_PARAMS_MSG_UKR;
            Dialog_error_level_2_message.ptitle[1] = ERROR_PARAMS_MSG_RUS;
            Dialog_error_level_2_message.ptitle[2] = ERROR_PARAMS_MSG_ENG;
            break;
          }
        }
        dialog_error_show(ID_DIALOG_ERROR_LEVEL_2);
        break;
      }
    case ID_UNRELIABLE_ERROR:
    case ID_UNRELIABLE_ERROR_LEVEL_2:
      {
        unreliable_error_show(win_id);
        break;
      }
    case ID_LCD_SETTINGS:
      {
        lcd_settings_show();
        break;
      }
    case ID_ABOUT_PG:
      {
        About_show();
        break;
      }
    case ID_DZ_PG:
    case ID_MTZ_PG:
    case ID_UMIN_PG:
    case ID_UMAX_PG:
    case ID_TZNP_PG:
    case ID_ZOP_PG:
    case ID_APV_PG:
    case ID_UROV_PG:
    case ID_CB_PG:
      {
        protection_settings_panel_show(win_id);
        break;
      }
    case ID_SETTINGS_PG:
      {
        settings_panel_show();
        break;
      }
    case ID_TRANSFORMER_PG:
      {
        transformer_panel_show();
        break;
      }
    case ID_RESURS_PG:
      {
        resurs_panel_show();
        break;
      }
    case ID_COMM_PG:
      {
        Comm_panel_show();
        break;
      }
    case ID_MODBUS_PG:
      {
        Modbus_panel_show();
        break;
      }
    case ID_NET_PG:
      {
        Net_panel_show();
        break;
      }
    case ID_CLOCK_PG:
      {
        clock_panel_show();
        break;
      }
    case ID_TM_PG:
    case ID_DIAGNOSTICS_PG:
      {
        info_n_panel_show(win_id);
        break;
      }
    case ID_REGISTRATORS_PG:
      {
        registrators_panel_show();
        break;
      }
    
    default:
      //do nothing
      break;
  }
}

/**
* 
* @param win_id - идентификатор окна которое нужно скрыть функцией WM_HideWindow().
*                 Если id == GUI_NULL (-1) функция WM_HideWindow() не будет вызываться.
*/
void hide_window(int win_id) {
  switch (win_id) {
    case ID_LANG_DLG:
      {
        WM_HideWindow(langWin);
        WM_DeleteWindow(langWin);
        langWin = WM_UNATTACHED;
        break;
      }
    case ID_MEAS_PG:
      {
        WM_HideWindow(measMultiPageWin);
        WM_DeleteWindow(measMultiPageWin);
        measMultiPageWin = WM_UNATTACHED;
        break;
      }
    case ID_CONFIG_PG:
      {
        WM_HideWindow(configPageWin);
        WM_DeleteWindow(configPageWin);
        configPageWin = WM_UNATTACHED;
        break;
      }
    case ID_RANK_PG:
      {
        WM_HideWindow(rankMultiPageWin);
        break;
      }
    case ID_RANK_DI_DLG:
      {
        WM_HideWindow(rankDlgDIPg);
        WM_BringToBottom(rankDlgDIPg);
        rankDlgDIPg = WM_UNATTACHED;
        break;
      }
    case ID_RANK_DO_DLG:
      {
        WM_HideWindow(rankDlgDOPg);
        WM_BringToBottom(rankDlgDOPg);
        rankDlgDOPg = WM_UNATTACHED;
        break;
      }
    case ID_RANK_LED_DLG:
      {
        WM_HideWindow(rankDlgLEDPg);
        WM_BringToBottom(rankDlgLEDPg);
        rankDlgLEDPg = WM_UNATTACHED;
        break;
      }
    case ID_RANK_DF_DLG:
      {
        WM_HideWindow(rankDlgDFPg);
        WM_BringToBottom(rankDlgDFPg);
        rankDlgDFPg = WM_UNATTACHED;
        break;
      }
    case ID_RANK_AN_REC_DLG:
      {
        WM_HideWindow(rankDlgAnRecPg);
        WM_BringToBottom(rankDlgAnRecPg);
        rankDlgAnRecPg = WM_UNATTACHED;
        break;
      }
    default:
      //do nothing
      break;
  }
}

void win_handler() {
  int win_id = current_ekran.current_level;
  int sel_index = current_ekran.index_position;
  sel_icon = sel_index;

  repaint_actions((__index_level_menu)win_id);
  
  switch (win_id) {
    case ID_EKRAN_MAIN:
      {
        if (change_language) {
          for (int i = 0; i < ICONVIEW_SIZE; i++) {
            ICONVIEW_SetItemText(iconWin, i, _aBitmapItem[i].pText[sel_language]);
          }
        }
        ICONVIEW_SetSel(iconWin, sel_icon);
        EDIT_SetText(hEdit, _aBitmapItem[sel_icon].pExplanation[sel_language]);
        start_gui_exec = 1;
        break;
      }
    case ID_LANG_DLG:
      {
        switch (sel_index) {
          case ID_LANG_RADIO:
            {
              WM_SetFocus(langRadioButton);
              start_gui_exec = 1;
              break;
            }
          case ID_LANG_BUTTON_OK:
            {
              WM_SetFocus(langButtonOK);
              start_gui_exec = 1;
              break;
            }
          case ID_LANG_BUTTON_CANCEL:
            {
              WM_SetFocus(langButtonCancel);
              start_gui_exec = 1;
              break;
            }
          default:
            //do nothing
            break;
        }
        break;
      }
    case ID_MEAS_PG:
      {
        switch (sel_index) {
          case ID_MEAS_FOURIER_PG:
            {
              select_meas_multipage(sel_index);
              update_measurement_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_SUM_EQUATION_PG:
            {
              select_meas_multipage(sel_index);
              update_measurement_i_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_ANGLES_PG:
            {
              select_meas_multipage(sel_index);
              update_angles_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_RESISTANCES_PG:
            {
              select_meas_multipage(sel_index);
              update_resistances_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_SPEED_RESISTANCE_CHANGE_PG:
            {
              select_meas_multipage(sel_index);
              update_speed_resistance_change_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_RESISTANCE_ANGLE_PG:
            {
              select_meas_multipage(sel_index);
              update_resistance_angle_pg();
              start_gui_exec = 1;
              break;
            }
          case ID_MEAS_OTHER_PG:
            {
              select_meas_multipage(sel_index);
              update_other_meas_pg();
              meas_scrolling();
              start_gui_exec = 1;
              break;
            }
          default:
            //do nothing
            break;
        }
        break;
      }
    case ID_CONFIG_PG:
      {
        if (current_ekran.edition == 0) {
          copy_config_settings_to_buff();
          if (eeprom_bs_settings_tbl.arPsw1[0] == '\0') {
            current_ekran.edition = 1;
          }
        }
        update_conf_item();
        start_gui_exec = 1;
        break;
      }
    case ID_RANK_PG:
      {
        switch (sel_index) {
          case ID_RANK_DISCRETE_INPUT_PG:
          case ID_RANK_DISCRETE_OUTPUT_PG:
          case ID_RANK_LED_PG:
          case ID_RANK_DF_PLUS_PG:
          case ID_RANK_DF_MINUS_PG:
          case ID_RANK_DF_BLK_PG:
          case ID_RANK_F_PG:
          case ID_RANK_TRG_SET_PL_PG:
          case ID_RANK_TRG_SET_MN_PG:
          case ID_RANK_TRG_RST_PL_PG:
          case ID_RANK_TRG_RST_MN_PG:
          case ID_RANK_AN_DIG_REC_PG:
            {
              if (current_ekran.edition == 0) {
                if (eeprom_bs_settings_tbl.arPsw1[0] == '\0') {
                  current_ekran.edition = 1;
                }
              }
              if (current_ekran.edition != 2) {
                copy_rank_settings_to_buff();
              }
              select_rank_multipage(sel_index);
              start_gui_exec = 1;
              break;
            }
          default:break;
        }
        break;
      }
    case ID_RANK_DI_DLG:
      {
        if (current_ekran.edition != 2) {
          copy_rank_settings_to_buff();
        }
        update_di_status_panel();
        update_di_title();
        update_di_labels();
        update_di_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_RANK_DO_DLG:
      {
        if (current_ekran.edition != 2) {
          copy_rank_settings_to_buff();
        }
        update_do_status_panel();
        update_do_title();
        update_do_labels();
        update_do_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_RANK_LED_DLG:
      {
        if (current_ekran.edition != 2) {
          copy_rank_settings_to_buff();
        }
        update_led_status_panel();
        update_led_title();
        update_led_labels();
        update_led_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_RANK_DF_DLG:
      {
        if (current_ekran.edition != 2) {
          copy_rank_settings_to_buff();
        }
        update_df_status_panel();
        update_df_title();
        update_df_labels();
        update_df_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_RANK_AN_REC_DLG:
      {
        if (current_ekran.edition != 2) {
          copy_rank_settings_to_buff();
        }
        update_an_rec_status_panel();
        update_an_rec_title();
        update_an_rec_labels();
        update_an_rec_settings();
        start_gui_exec = 1;
        break;
      }
      
    case ID_MAIN_MENU:
    case ID_DIALOG_PASSWORD:
    case ID_DIALOG_PASSWORD_LEVEL_2:
    case ID_DIALOG_PASSWORD_OLD_1:
    case ID_DIALOG_PASSWORD_OLD_2:
    case ID_DIALOG_PASSWORD_NEW_1:
    case ID_DIALOG_PASSWORD_NEW_2:
    case ID_DIALOG_CONFIRMATION:
    case ID_DIALOG_CONFIRMATION_LEVEL_2:
    case ID_DIALOG_ERROR:
    case ID_DIALOG_ERROR_LEVEL_2:
    case ID_UNRELIABLE_ERROR:
    case ID_UNRELIABLE_ERROR_LEVEL_2:
    case ID_ABOUT_PG:
      {
        start_gui_exec = 1;
        break;
      }
    case ID_DZ_PG:
    case ID_MTZ_PG:
    case ID_TZNP_PG:
    case ID_ZOP_PG:
    case ID_UMIN_PG:
    case ID_UMAX_PG:
    case ID_APV_PG:
    case ID_UROV_PG:
    case ID_CB_PG:
      {
        redraw_panel_protection((__index_level_menu)win_id);
        start_gui_exec = 1;
        break;
      }
    case ID_SETTINGS_PG:
      {
        redraw_panel_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_TRANSFORMER_PG:
      {
        redraw_panel_transformer();
        start_gui_exec = 1;
        break;
      }
    case ID_RESURS_PG:
      {
        redraw_panel_resurs();
        start_gui_exec = 1;
        break;
      }
    case ID_COMM_PG:
      {
        redraw_panel_Comm();
        start_gui_exec = 1;
        break;
      }
    case ID_MODBUS_PG:
      {
        redraw_panel_Modbus();
        start_gui_exec = 1;
        break;
      }
    case ID_NET_PG:
      {
        redraw_panel_Net();
        start_gui_exec = 1;
        break;
      }
    case ID_CLOCK_PG:
      {
        redraw_panel_clock();
        start_gui_exec = 1;
        break;
      }
    case ID_LCD_SETTINGS:
      {
        redraw_panel_lcd_settings();
        start_gui_exec = 1;
        break;
      }
    case ID_TM_PG:
    case ID_DIAGNOSTICS_PG:
      {
        redraw_panel_info_n((__index_level_menu)win_id);
        start_gui_exec = 1;
        break;
      }
    case ID_REGISTRATORS_PG:
      {
        redraw_panel_registrators();
        start_gui_exec = 1;
        break;
      }
      
    default:
      //do nothing
      break;
  }

  if (change_language) change_language = 0;
}

void gui_tmr_routines() {
  int win_id = current_ekran.current_level;
  switch (win_id) {
    case ID_MEAS_PG:
      {
        gui_update = 1;
        break;
      }
    default:
      gui_update = 0;
      break;
  }
}

void gui_routines() {
  if (gui_update) {
    int win_id = current_ekran.current_level;
    int sel_index = current_ekran.index_position;
    switch (win_id) {
      case ID_MEAS_PG:
        {
          switch (sel_index) {
            case ID_MEAS_FOURIER_PG:
              {
                update_measurement_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_SUM_EQUATION_PG:
              {
                update_measurement_i_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_ANGLES_PG:
              {
                update_angles_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_RESISTANCES_PG:
              {
                update_resistances_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_SPEED_RESISTANCE_CHANGE_PG:
              {
                update_speed_resistance_change_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_RESISTANCE_ANGLE_PG:
              {
                update_resistance_angle_pg();
                start_gui_exec = 1;
                break;
              }
            case ID_MEAS_OTHER_PG:
              {
                update_other_meas_pg();
                meas_scrolling();
                start_gui_exec = 1;
                break;
              }
            default:
              //do nothing
              break;
          }
          break;
        }
      case ID_RANK_PG:
        {
          switch (sel_index) {
            case ID_RANK_DISCRETE_INPUT_PG:
            case ID_RANK_DISCRETE_OUTPUT_PG:
            case ID_RANK_LED_PG:
            case ID_RANK_DF_PLUS_PG:
            case ID_RANK_DF_MINUS_PG:
            case ID_RANK_DF_BLK_PG:
            case ID_RANK_F_PG:
            case ID_RANK_TRG_SET_PL_PG:
            case ID_RANK_TRG_SET_MN_PG:
            case ID_RANK_TRG_RST_PL_PG:
            case ID_RANK_TRG_RST_MN_PG:
            case ID_RANK_AN_DIG_REC_PG:
              {
                start_gui_exec = 1;
                break;
              }
            default:
              break;
          }
          break;
        }
      case ID_RANK_DO_DLG:
      case ID_RANK_DI_DLG:
      case ID_RANK_LED_DLG:
      case ID_RANK_DF_DLG:
      case ID_RANK_AN_REC_DLG:
        {
          start_gui_exec = 1;
          break;
        }
      default:
        //do nothing
        break;
    }
  }
}

void copy_settings_from_buff(int id) {
  switch (id) {
    case ID_RANK_PG:
      copy_rank_settings_from_buff();
      break;
    case ID_CONFIG_PG:
      copy_config_settings_from_buff();
      break;
    default: break;;
  }
}
