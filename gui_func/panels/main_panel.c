
#include "gui_header.h"
#include "header_mal.h"

/*********************************************************************
*
*       _cbWinHandler
*/
static void _cbWinHandler(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
    case WM_PAINT:
      GUI_SetBkColor(GUI_BLACK);
      GUI_Clear();
      break;
      
    case WM_MENU:
      {
        MENU_MSG_DATA *pData = (MENU_MSG_DATA*)pMsg->Data.p;
        switch (pData->MsgType) 
        {
//        case MENU_ON_ITEMPRESSED:
//          {
//            //
//            // This message is send regardless of the item state is disabled or not
//            //
//            MENU_ITEM_DATA Data;
//            MENU_GetItem(pMsg->hWinSrc, pData->ItemId, &Data);
//            if (Data.Flags & MENU_IF_DISABLED) 
//            {
//              _MessageBox("The pressed item was disabled", "Message");
//            }
//            break;
//          }
        case MENU_ON_ITEMACTIVATE:
          {
            //
            // This message is send on highlighting a menu item
            //
            int Index = pData->ItemId - ID_MENU_MIN_SETTINGS;
            if (Index >= 0) 
            {
              EDIT_SetText(hEdit, menu_option_explanation[Index].ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
            }
            else 
            {
              EDIT_SetText(hEdit,  "???");
            }
            break;
          }
        case MENU_ON_ITEMSELECT:
          {
            //
            // This message is send only if an enabled item has been selected
            //
             switch (pData->ItemId)
             {
             case ID_MENU_MIN_SETTINGS_PRT:
               {
                 min_settings = true;

                 previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                 previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                 current_modal_form = true;
                 
                 break;
               }
             case ID_MENU_MIN_SETTINGS_1:
               {
                 min_settings_1 = true;

                 previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                 previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                 current_modal_form = true;
                 
                 break;
               }
             case ID_MENU_OPTION_LANGUAGE:
               {
                 if (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_LANG_DLG)
                 {
                   previous_level_in_current_level_menu[ID_LANG_DLG] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                   previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_LANG_DLG;
                   current_modal_form = true;
                 }
                 break;
               }
             case ID_MENU_OPTION_LCD:
               {
                 if (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_LCD_SETTINGS)
                 {
                   unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);

                   if (error_data_1 == 0)
                   {
                     previous_level_in_current_level_menu[ID_LCD_SETTINGS] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_LCD_SETTINGS;
                   }
                   else
                   {
                     previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_UNRELIABLE_ERROR_LEVEL_2;
                   }
                   current_modal_form = true;
                 }
                 break;
               }
             case ID_MENU_OPTION_PASSWORD1:
               {
                 if (
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_LEVEL_2) &&
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_OLD_1  ) &&
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_NEW_1  )
                    )   
                 {
                   unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
                   
                   if (error_data_1 == 0)
                   {
                     previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_1] = previous_level_in_current_level_menu[ID_MAIN_MENU];
                     if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                     {
                       previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_OLD_1] = ID_DIALOG_PASSWORD_NEW_1;
                       previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_OLD_1;
                     }
                     else
                     {
                       previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_NEW_1;
                     }
                     typed_password_level_2[0] = '\0';
                     cursor_position_dp_level_2 = 0;
                   }
                   else
                   {
                     previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_UNRELIABLE_ERROR_LEVEL_2;
                   }
                   current_modal_form = true;
                 }
                 break;
               }
             case ID_MENU_OPTION_PASSWORD2:
               {
                 if (
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_LEVEL_2) &&
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_OLD_2  ) &&
                     (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_DIALOG_PASSWORD_NEW_2  )
                    )   
                 {
                   unsigned int error_data_1 = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);

                   if (error_data_1 == 0)
                   {
                     previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_NEW_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     if (eeprom_bs_settings_tbl.arPsw2[0] != '\0')
                     {
                       previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_OLD_2] = ID_DIALOG_PASSWORD_NEW_2;
                       previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_OLD_2;
                     }
                     else
                     {
                       previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_NEW_2;
                     }
                     typed_password_level_2[0] = '\0';
                     cursor_position_dp_level_2 = 0;
                   }
                   else
                   {
                     previous_level_in_current_level_menu[ID_UNRELIABLE_ERROR_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_UNRELIABLE_ERROR_LEVEL_2;
                   }
                   current_modal_form = true;
                 }
                 break;
               }
             case ID_MENU_GROUPS_1:
             case ID_MENU_GROUPS_2:
             case ID_MENU_GROUPS_3:
             case ID_MENU_GROUPS_4:
               {
                 edit_Pick_up_Set = pData->ItemId - ID_MENU_GROUPS_1;
                 if (set_new_Pick_up_Set = (edit_Pick_up_Set != eeprom_prt_tbl.PckpStpm_store_selection))
                 {
                   if (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                   {
                     previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_LEVEL_2;
                     typed_password_level_2[0] = '\0';
                     cursor_position_dp_level_2 = 0;
                   }
                   else
                   {
                     previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                     previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                   }
                   current_modal_form = true;
                 }
                 break;
               }
             case ID_MENU_COMMANDS_1:
             case ID_MENU_COMMANDS_2:
             case ID_MENU_COMMANDS_3:
             case ID_MENU_COMMANDS_4:
             case ID_MENU_COMMANDS_5:
               {
                 if (pData->ItemId == ID_MENU_COMMANDS_1) command_from_menu = 1 << BIT_CLEAR_ACTUATED_FUNCTIONS;
                 else if (pData->ItemId == ID_MENU_COMMANDS_2) command_from_menu = 1 << BIT_CLEAR_AR;
                 else if (pData->ItemId == ID_MENU_COMMANDS_3) command_from_menu = 1 << BIT_CLEAR_DR;
                 else if (pData->ItemId == ID_MENU_COMMANDS_4) command_from_menu = 1 << BIT_CLEAR_RPP;
                 else if (pData->ItemId == ID_MENU_COMMANDS_5) command_from_menu = 1 << BIT_CLEAR_RESOURCE_COUNTER;
                 
                 if (
                     (pData->ItemId == ID_MENU_COMMANDS_5) ||
                     (eeprom_bs_settings_tbl.arPsw1[0] != '\0')
                    )   
                 {
                   previous_level_in_current_level_menu[ID_DIALOG_PASSWORD_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                   previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_PASSWORD_LEVEL_2;
                   typed_password_level_2[0] = '\0';
                   cursor_position_dp_level_2 = 0;
                 }
                 else
                 {
                   previous_level_in_current_level_menu[ID_DIALOG_CONFIRMATION_LEVEL_2] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                   previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_DIALOG_CONFIRMATION_LEVEL_2;
                 }
                 current_modal_form = true;

                 break;
               }
             case ID_MENU_ABOUT_1:
               {
                 if (previous_level_in_current_level_menu[ID_MAIN_MENU] != ID_ABOUT_PG)
                 {
                   previous_level_in_current_level_menu[ID_ABOUT_PG] = previous_level_in_current_level_menu[ID_MAIN_MENU];						                 
                   previous_level_in_current_level_menu[ID_MAIN_MENU] = ID_ABOUT_PG;
                   current_modal_form = true;
                 }
                 break;
               }
             }
            break;
          }
        default:
          {
            WM_DefaultProc(pMsg);
            break;
          }
        }
        
        break;
      }
    default:
      WM_DefaultProc(pMsg);
  }
}

//static void _AddMenuItem(MENU_Handle hMenu, MENU_Handle hSubmenu, const char* pText, U16 Id, U16 Flags) {
//  MENU_ITEM_DATA Item;
//  Item.pText    = pText;
//  Item.hSubmenu = hSubmenu;
//  Item.Flags    = Flags;
//  Item.Id       = Id;
//  MENU_AddItem(hMenu, &Item);
//}

//static void desctop_menu_init() {
//  MENU_SetDefaultEffect(&WIDGET_Effect_3D1L);
//  
//  // Create main menu
//  _hMenu = MENU_CreateEx(MAIN_MENU_X, MAIN_MENU_Y, MAIN_MENU_WIDTH, MAIN_MENU_HEIGHT,
////                         WM_UNATTACHED,
//                         WM_HBKWIN,
//                         0, MENU_CF_HORIZONTAL, win_id_list[ID_MAIN_MENU]);
//  // Create sub menus
//  hMenuFunc = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
//  hMenuHelp = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
//  // Add menu items to menu 'Func'
//  _AddMenuItem(hMenuFunc, 0, "Language", MAIN_MENU_LANG_ID, 0);
//  _AddMenuItem(hMenuFunc, 0, 0, 0, MENU_IF_SEPARATOR);
//  _AddMenuItem(hMenuFunc, 0, "Go To Main Menu", MAIN_MENU_GO_TO_MAIN_ID, MENU_IF_DISABLED);
////  _AddMenuItem(hMenuFile,   0,           0,          0,                   MENU_IF_SEPARATOR);
////  _AddMenuItem(hMenuFile,   hMenuRecent, "Files...", ID_MENU_FILE_RECENT, 0);
////  _AddMenuItem(hMenuFile,   0,           0,          0,                   MENU_IF_SEPARATOR);
////  _AddMenuItem(hMenuFile,   0,           "Exit",     ID_MENU_FILE_EXIT,   0);
////  // Add menu items to menu 'Edit'
////  _AddMenuItem(hMenuEdit,   0,           "Undo",     ID_MENU_EDIT_UNDO,   0);
////  _AddMenuItem(hMenuEdit,   0,           "Redo",     ID_MENU_EDIT_REDO,   0);
////  _AddMenuItem(hMenuEdit,   0,           0,          0,                   MENU_IF_SEPARATOR);
////  _AddMenuItem(hMenuEdit,   0,           "Copy",     ID_MENU_EDIT_COPY,   0);
////  _AddMenuItem(hMenuEdit,   0,           "Paste",    ID_MENU_EDIT_PASTE,  0);
////  _AddMenuItem(hMenuEdit,   0,           "Delete",   ID_MENU_EDIT_DELETE, 0);
//  // Add menu items to menu 'Help'
//  _AddMenuItem(hMenuHelp, 0, "About", MAIN_MENU_ABOUT_ID, 0);
//  // Add menu items to main menu
//  _AddMenuItem(_hMenu, hMenuFunc, "Func", 0, 0);
////  _AddMenuItem(_hMenu, hMenuHelp, "Help", 0, 0);
//  // Attach menu to parent window
////  FRAMEWIN_AddMenu(WM_HBKWIN, _hMenu);
//}

static void desctop_iconViewer_init() {
  WM_SetCallback(WM_HBKWIN, _cbWinHandler);
  
  //Create iconview widget
  iconWin = ICONVIEW_CreateEx(ICONVIEW_X, ICONVIEW_Y, ICONVIEW_WIDTH, ICONVIEW_HEIGHT,
                           WM_HBKWIN, WM_CF_SHOW | WM_CF_HASTRANS, 
                           ICONVIEW_CF_AUTOSCROLLBAR_V, ID_ICONVIEW0, 64 + 7, 64 + 12); //55, 60
  
  for (unsigned int i = 0; i < ICONVIEW_SIZE; i++) {
    ICONVIEW_AddBitmapItem(iconWin, _aBitmapItem[i].pBitmap, _aBitmapItem[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
  }
  ICONVIEW_SetBkColor(iconWin, ICONVIEW_CI_SEL, GUI_BLUE | 0x50000000);
  ICONVIEW_SetTextColor(iconWin, ICONVIEW_CI_UNSEL, GUI_RED);
  ICONVIEW_SetTextColor(iconWin, ICONVIEW_CI_SEL, GUI_YELLOW);
  ICONVIEW_SetFont(iconWin, &GUI_CourierNewBold14_8_Unicode);
  WM_SetFocus(iconWin);
}

static void desctop_edit_init() {
  int x0 = EDIT_X, width = 2*EDIT_WIDTH/3;
  hEdit = EDIT_CreateEx(x0, EDIT_Y, width, EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT0, EDIT_TEXT_MAX_LEN);
  x0 += width;
  EDIT_SetBkColor(hEdit, EDIT_CI_DISABLED, GUI_LIGHTGRAY);
  EDIT_SetBkColor(hEdit, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(hEdit, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetText(hEdit, _aBitmapItem[sel_icon].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);

  width = 3*EDIT_HEIGHT/4;
  Edit_groups = EDIT_CreateEx(x0, EDIT_Y, width, EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT_GROUP, 1);
  x0 += width;
  EDIT_SetBkColor(Edit_groups, EDIT_CI_DISABLED, GUI_YELLOW);
  EDIT_SetBkColor(Edit_groups, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(Edit_groups, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetTextAlign(Edit_groups, GUI_TA_HCENTER | GUI_TA_VCENTER);
  EDIT_SetText(Edit_groups, "");

  Edit_saving_EERPOM = EDIT_CreateEx(x0, EDIT_Y, width, EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT_SAVING_EEPROM, 1);
  x0 += width;
  EDIT_SetBkColor(Edit_saving_EERPOM, EDIT_CI_DISABLED, GUI_YELLOW);
  EDIT_SetBkColor(Edit_saving_EERPOM, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(Edit_saving_EERPOM, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetTextAlign(Edit_saving_EERPOM, GUI_TA_HCENTER | GUI_TA_VCENTER);
  EDIT_SetText(Edit_saving_EERPOM, "E");

  Edit_transmit_settings_L = EDIT_CreateEx(x0, EDIT_Y, width, EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT_TRANSMIT_SETTINGS, 1);
  x0 += width;
  EDIT_SetBkColor(Edit_transmit_settings_L, EDIT_CI_DISABLED, GUI_YELLOW);
  EDIT_SetBkColor(Edit_transmit_settings_L, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(Edit_transmit_settings_L, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetTextAlign(Edit_transmit_settings_L, GUI_TA_HCENTER | GUI_TA_VCENTER);
  EDIT_SetText(Edit_transmit_settings_L, "L");

  Edit_transmit_settings_M = EDIT_CreateEx(x0, EDIT_Y, width, EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT_TRANSMIT_SETTINGS, 1);
  x0 += width;
  EDIT_SetBkColor(Edit_transmit_settings_M, EDIT_CI_DISABLED, GUI_YELLOW);
  EDIT_SetBkColor(Edit_transmit_settings_M, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(Edit_transmit_settings_M, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetTextAlign(Edit_transmit_settings_M, GUI_TA_HCENTER | GUI_TA_VCENTER);
  EDIT_SetText(Edit_transmit_settings_M, "M");

  Edit_clock = EDIT_CreateEx(x0, EDIT_Y, (EDIT_WIDTH - x0), EDIT_HEIGHT, WM_HBKWIN, WM_CF_SHOW, 0, ID_EDIT_CLOCK, 8);
  EDIT_SetBkColor(Edit_clock, EDIT_CI_DISABLED, GUI_YELLOW);
  EDIT_SetBkColor(Edit_clock, EDIT_CI_ENABLED, GUI_WHITE);
  EDIT_SetFont(Edit_clock, &GUI_FontArialNarrow15_8_Unicode);
  EDIT_SetTextAlign(Edit_clock, GUI_TA_HCENTER | GUI_TA_VCENTER);
  EDIT_SetText(Edit_clock, "");
}

/*********************************************************************
*
*       Public routines
*
**********************************************************************
*/
void desctop_init() {
  desctop_menu_init_mal();
  desctop_iconViewer_init();
  desctop_edit_init();
}

int get_main_panel_id() {
  switch (current_ekran.index_position) {
    case ICONVIEW_LANGUAGE_ID:
      return ID_LANG_DLG;
    case ICONVIEW_MEAS_ID:
      return ID_MEAS_PG;
    default: while(1);
  }
}

int get_settings_panel_id() {
  switch (current_ekran.index_position) {
    case SETTINGS_CONFIG_ID:
      return ID_CONFIG_PG;
    case SETTINGS_RANK_ID:
      return ID_RANK_PG;
    default: while(1);
  }
}
