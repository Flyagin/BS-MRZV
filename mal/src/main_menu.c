#include "header_mal.h"

/***
_AddMenuItem
***/
static void _AddMenuItem(MENU_Handle hMenu, MENU_Handle hSubmenu, const char* pText, U16 Id, U16 Flags) 
{
  MENU_ITEM_DATA Item;
  Item.pText    = pText;
  Item.hSubmenu = hSubmenu;
  Item.Flags    = Flags;
  Item.Id       = Id;
  MENU_AddItem(hMenu, &Item);
}
/***/

/***
Golovne menu
***/
void desctop_menu_init_mal()
{
  MENU_SetDefaultEffect(&WIDGET_Effect_3D1L);
  MENU_SetDefaultFont(&GUI_FontArialStandard14_8_Unicode);
  
  // Create main menu
  hMenu_main = MENU_CreateEx(0, 0, GUI_X_MAX, 20, WM_HBKWIN,  WM_CF_SHOW, MENU_CF_HORIZONTAL, ID_MENU_MAIN);

  // Create sub menus
  hMin_settings = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);
  hOption       = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);
  hPasswords    = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);
  hPickup_Group = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);
  hCommands     = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);
  hAbout        = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED,  0, MENU_CF_VERTICAL, 0);

  // Add menu items to main menu
  _AddMenuItem(hMenu_main, hMin_settings, menu_option_title[0].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[0], 0);
  // Add menu items to menu 'Min.settings'
  _AddMenuItem(hMin_settings, 0, menu_option_title[1].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[1], MENU_IF_DISABLED);
  _AddMenuItem(hMin_settings, 0, menu_option_title[2].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[2], MENU_IF_DISABLED);

  // Add menu items to main menu
  _AddMenuItem(hMenu_main, hOption, menu_option_title[3].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[3], 0);
  // Add menu items to menu 'Option'
  _AddMenuItem(hOption, 0, menu_option_title[4].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[4], 0);
  _AddMenuItem(hOption, 0, menu_option_title[5].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[5], 0);
  _AddMenuItem(hOption, hPasswords, menu_option_title[6].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[6], 0);
  // Add menu items to menu 'Passwords'
  _AddMenuItem(hPasswords, 0, menu_option_title[7].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[7], 0);
  _AddMenuItem(hPasswords, 0, menu_option_title[8].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[8], 0);

  // Add menu items to main menu
  _AddMenuItem(hMenu_main, hPickup_Group, menu_option_title[9].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[9], 0);
  // Add menu items to menu 'Min.settings'
  _AddMenuItem(hPickup_Group, 0, menu_option_title[10].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[10], 0);
  _AddMenuItem(hPickup_Group, 0, menu_option_title[11].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[11], 0);
  _AddMenuItem(hPickup_Group, 0, menu_option_title[12].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[12], 0);
  _AddMenuItem(hPickup_Group, 0, menu_option_title[13].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[13], 0);

  // Add menu items to main menu
  _AddMenuItem(hMenu_main, hCommands, menu_option_title[14].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[14], 0);
  // Add menu items to menu 'Commands'
  _AddMenuItem(hCommands, 0, menu_option_title[15].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[15], 0);
  _AddMenuItem(hCommands, 0, menu_option_title[16].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[16], 0);
  _AddMenuItem(hCommands, 0, menu_option_title[17].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[17], 0);
  _AddMenuItem(hCommands, 0, menu_option_title[18].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[18], 0);
  _AddMenuItem(hCommands, 0, menu_option_title[19].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[19], 0);

  // Add menu items to main menu
  _AddMenuItem(hMenu_main, hAbout, menu_option_title[20].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[20], 0);
  // Add menu items to menu 'About'
  _AddMenuItem(hAbout, 0, menu_option_title[21].ptitle[eeprom_bs_settings_tbl.chLngGUIText], id_menu[21], 0);
}
/***/
