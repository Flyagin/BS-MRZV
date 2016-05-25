#include "external_variables_for_global_mal.h"

extern unsigned int tick_for_1s;
extern unsigned int tick_for_2s;
extern unsigned int tick_for_3s;

//Змінні для роботи emWin у режтмі мультипортовості
extern int _PendingBuffer;

extern __CURRENT_EKRAN current_ekran;
extern int position_in_current_level_menu[MAX_LEVEL_MENU];
extern int previous_level_in_current_level_menu[MAX_LEVEL_MENU];
extern unsigned int command_menu;
extern unsigned int executed_action_after_press_ctrl;

extern int position_in_level_1_menu_DZ[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_DZ_delay[2];
extern int position_in_level_1_menu_MTZ[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_Umin[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_Umax[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_TZNP[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_ZOP[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_APV[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_UROV[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_CB[MAX_PAGES_PROTECTION_SDC];
extern int position_in_level_1_menu_Transformer;
extern int position_in_level_1_menu_Modbus;
extern int position_in_level_1_menu_Net;
extern int position_in_level_1_menu_Clock;
extern int position_in_level_1_menu_TM[2];
extern int position_in_level_1_menu_Diagnostics[4];

extern const TITLE MODE;
extern const TITLE ERROR_MES;
extern const TITLE NONE;

extern const TITLE title_from;

extern const TITLE ON_OFF[2];
extern const TITLE SELECTOR[3];
extern const TITLE UMIN_UMAX_TYPE[2]; 
extern const TITLE UMIN_UMAX_VOLTAGE[2];
extern const TITLE NAPRJAMOK[2];
extern const TITLE PHASES[3];
extern const TITLE NAPRJAMOK_1[2];

extern const TITLE ENTER_ESC[2];

extern const char empty_string[];
extern const char gradus[];
extern const TITLE MEASURES[TOTAL_AMOUNT_OF_MEASURES];

extern WM_HWIN Dialog_confirmation_FrameWin, DC_Text, DC_ENTER_Button, DC_ESC_Button;
extern const TITLE Dialog_confirmation_title;
extern TITLE Dialog_confirmation_message;

extern WM_HWIN Dialog_confirmation_level_2_FrameWin, DC_level_2_Text, DC_ENTER_level_2_Button, DC_ESC_level_2_Button;
extern TITLE Dialog_confirmation_level_2_message;

extern WM_HWIN Dialog_error_FrameWin, DE_Text, DE_ENTER_Button, DE_ESC_Button;
extern const TITLE Dialog_error_title;
extern TITLE Dialog_error_message;

extern WM_HWIN Dialog_error_level_2_FrameWin, DE_level_2_Text, DE_ENTER_level_2_Button, DE_ESC_level_2_Button;
extern TITLE Dialog_error_level_2_message;

extern WM_HWIN Unreliable_error_FrameWin, UE_Text, UE_ESC_Button;
extern WM_HWIN Unreliable_error_level_2_FrameWin, UE_level_2_Text, UE_ESC_level_2_Button;
extern TITLE Unreliable_error_title, Unreliable_error_level_2_title;
extern TITLE Unreliable_error_message, Unreliable_error_level_2_message;

extern WM_HWIN Dialog_password_FrameWin, DP_Edit, DP_ENTER_Button, DP_ESC_Button;
extern WM_HWIN Dialog_password_level_2_FrameWin, DP_level_2_Edit, DP_ENTER_level_2_Button, DP_ESC_level_2_Button;
extern const TITLE Dialog_password_title[];
extern char  typed_password[MAX_NUMBER_SYMBOLS_IN_PASSWORD + 1];
extern char  typed_password_level_2[MAX_NUMBER_SYMBOLS_IN_PASSWORD + 1];
extern int cursor_position_dp;
extern int cursor_position_dp_level_2;
extern unsigned int command_word_for_change_password;


extern const LANG_ITEM _MultiPage_groups_Items[AMOUNT_SERIES_PPSPM_SETTINGS + 1];
extern const LANG_ITEM _MultiPage_type_info_Items[MAX_PAGES_PROTECTION_SDC];

extern WM_HWIN MTZ_FrameWin, MTZ_MultiPage_groups, MTZ_Window_group, MTZ_MultiPage_type_info, MTZ_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_MTZ_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_MTZ, _y_cbDelay_MTZ, _y_cbControl_MTZ;
extern WM_HWIN MTZ_Pickup_t[MAX_NUMBER_PICKUP_MTZ], MTZ_Pickup_v[MAX_NUMBER_PICKUP_MTZ], MTZ_Pickup_m[MAX_NUMBER_PICKUP_MTZ];
extern WM_HWIN MTZ_Delay_t[MAX_NUMBER_DELAY_MTZ], MTZ_Delay_v[MAX_NUMBER_DELAY_MTZ], MTZ_Delay_m[MAX_NUMBER_DELAY_MTZ];
extern WM_HWIN MTZ_State_t[MAX_NUMBER_CTRL_MTZ], MTZ_State_v[MAX_NUMBER_CTRL_MTZ];
extern const unsigned short int nalashtuvannja_MTZ[MAX_KILKIST_STUPENIV_MTZ + 1];
extern const TITLE MTZ_panel_title;
extern const TITLE MTZ_Pickup_title[MAX_NUMBER_PICKUP_MTZ];
extern const TITLE MTZ_Delay_title[MAX_NUMBER_DELAY_MTZ];
extern const TITLE MTZ_State_title[MAX_NUMBER_CTRL_MTZ];
extern int MTZ_select_group;

extern WM_HWIN Umin_FrameWin, Umin_MultiPage_groups, Umin_Window_group, Umin_MultiPage_type_info, Umin_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_Umin_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_Umin, _y_cbDelay_Umin, _y_cbControl_Umin;
extern WM_HWIN Umin_Pickup_t[MAX_NUMBER_PICKUP_UMIN], Umin_Pickup_v[MAX_NUMBER_PICKUP_UMIN], Umin_Pickup_m[MAX_NUMBER_PICKUP_UMIN];
extern WM_HWIN Umin_Delay_t[MAX_NUMBER_DELAY_UMIN], Umin_Delay_v[MAX_NUMBER_DELAY_UMIN], Umin_Delay_m[MAX_NUMBER_DELAY_UMIN];
extern WM_HWIN Umin_State_t[MAX_NUMBER_CTRL_UMIN], Umin_State_v[MAX_NUMBER_CTRL_UMIN];
extern const unsigned short int nalashtuvannja_Umin[MAX_KILKIST_STUPENIV_UMIN];
extern const TITLE Umin_panel_title;
extern const TITLE Umin_Pickup_title[MAX_NUMBER_PICKUP_UMIN];
extern const TITLE Umin_Delay_title[MAX_NUMBER_DELAY_UMIN]; 
extern const TITLE Umin_State_title[MAX_NUMBER_CTRL_UMIN];
extern int Umin_select_group;

extern WM_HWIN Umax_FrameWin, Umax_MultiPage_groups, Umax_Window_group, Umax_MultiPage_type_info, Umax_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_Umax_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_Umax, _y_cbDelay_Umax, _y_cbControl_Umax;
extern WM_HWIN Umax_Pickup_t[MAX_NUMBER_PICKUP_UMAX], Umax_Pickup_v[MAX_NUMBER_PICKUP_UMAX], Umax_Pickup_m[MAX_NUMBER_PICKUP_UMAX];
extern WM_HWIN Umax_Delay_t[MAX_NUMBER_DELAY_UMAX], Umax_Delay_v[MAX_NUMBER_DELAY_UMAX], Umax_Delay_m[MAX_NUMBER_DELAY_UMAX];
extern WM_HWIN Umax_State_t[MAX_NUMBER_CTRL_UMAX], Umax_State_v[MAX_NUMBER_CTRL_UMAX];
extern const unsigned short int nalashtuvannja_Umax[MAX_KILKIST_STUPENIV_UMAX];
extern const TITLE Umax_panel_title;
extern const TITLE Umax_Pickup_title[MAX_NUMBER_PICKUP_UMAX];
extern const TITLE Umax_Delay_title[MAX_NUMBER_DELAY_UMAX]; 
extern const TITLE Umax_State_title[MAX_NUMBER_CTRL_UMAX];
extern int Umax_select_group;

extern WM_HWIN TZNP_FrameWin, TZNP_MultiPage_groups, TZNP_Window_group, TZNP_MultiPage_type_info, TZNP_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_TZNP_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_TZNP, _y_cbDelay_TZNP, _y_cbControl_TZNP;
extern WM_HWIN TZNP_Pickup_t[MAX_NUMBER_PICKUP_TZNP], TZNP_Pickup_v[MAX_NUMBER_PICKUP_TZNP], TZNP_Pickup_m[MAX_NUMBER_PICKUP_TZNP];
extern WM_HWIN TZNP_Delay_t[MAX_NUMBER_DELAY_TZNP], TZNP_Delay_v[MAX_NUMBER_DELAY_TZNP], TZNP_Delay_m[MAX_NUMBER_DELAY_TZNP];
extern WM_HWIN TZNP_State_t[MAX_NUMBER_CTRL_TZNP], TZNP_State_v[MAX_NUMBER_CTRL_TZNP];
extern const unsigned short int nalashtuvannja_TZNP[MAX_KILKIST_STUPENIV_TZNP];
extern const TITLE TZNP_panel_title;
extern const TITLE TZNP_Pickup_title[MAX_NUMBER_PICKUP_TZNP];
extern const TITLE TZNP_Delay_title[MAX_NUMBER_DELAY_TZNP]; 
extern const TITLE TZNP_State_title[MAX_NUMBER_CTRL_TZNP];
extern int TZNP_select_group;

extern WM_HWIN ZOP_FrameWin, ZOP_MultiPage_groups, ZOP_Window_group, ZOP_MultiPage_type_info, ZOP_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_ZOP_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_ZOP, _y_cbDelay_ZOP, _y_cbControl_ZOP;
extern WM_HWIN ZOP_Pickup_t[MAX_NUMBER_PICKUP_ZOP], ZOP_Pickup_v[MAX_NUMBER_PICKUP_ZOP], ZOP_Pickup_m[MAX_NUMBER_PICKUP_ZOP];
extern WM_HWIN ZOP_Delay_t[MAX_NUMBER_DELAY_ZOP], ZOP_Delay_v[MAX_NUMBER_DELAY_ZOP], ZOP_Delay_m[MAX_NUMBER_DELAY_ZOP];
extern WM_HWIN ZOP_State_t[MAX_NUMBER_CTRL_ZOP], ZOP_State_v[MAX_NUMBER_CTRL_ZOP];
extern const unsigned short int nalashtuvannja_ZOP[MAX_KILKIST_STUPENIV_ZOP];
extern const TITLE ZOP_panel_title;
extern const TITLE ZOP_Pickup_title[MAX_NUMBER_PICKUP_ZOP];
extern const TITLE ZOP_Delay_title[MAX_NUMBER_DELAY_ZOP]; 
extern const TITLE ZOP_State_title[MAX_NUMBER_CTRL_ZOP];
extern int ZOP_select_group;

extern WM_HWIN APV_FrameWin, APV_MultiPage_groups, APV_Window_group, APV_MultiPage_type_info, APV_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_APV_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_APV, _y_cbDelay_APV, _y_cbControl_APV;
extern WM_HWIN APV_Pickup_t[MAX_NUMBER_PICKUP_APV], APV_Pickup_v[MAX_NUMBER_PICKUP_APV], APV_Pickup_m[MAX_NUMBER_PICKUP_APV];
extern WM_HWIN APV_Delay_t[MAX_NUMBER_DELAY_APV], APV_Delay_v[MAX_NUMBER_DELAY_APV], APV_Delay_m[MAX_NUMBER_DELAY_APV];
extern WM_HWIN APV_State_t[MAX_NUMBER_CTRL_APV], APV_State_v[MAX_NUMBER_CTRL_APV];
extern const unsigned short int nalashtuvannja_APV[/*MAX_KILKIST_STUPENIV_APV + 1*/8];
extern const TITLE APV_panel_title;
extern const TITLE APV_Pickup_title[MAX_NUMBER_PICKUP_APV];
extern const TITLE APV_Delay_title[MAX_NUMBER_DELAY_APV]; 
extern const TITLE REGYM_APV[4];
extern const TITLE APV_State_title[MAX_NUMBER_CTRL_APV];
extern int APV_select_group;
extern unsigned char temp_data_for_APV;

extern WM_HWIN UROV_FrameWin, UROV_MultiPage_groups, UROV_Window_group, UROV_MultiPage_type_info, UROV_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_UROV_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_UROV, _y_cbDelay_UROV, _y_cbControl_UROV;
extern WM_HWIN UROV_Pickup_t[MAX_NUMBER_PICKUP_UROV], UROV_Pickup_v[MAX_NUMBER_PICKUP_UROV], UROV_Pickup_m[MAX_NUMBER_PICKUP_UROV];
extern WM_HWIN UROV_Delay_t[MAX_NUMBER_DELAY_UROV], UROV_Delay_v[MAX_NUMBER_DELAY_UROV], UROV_Delay_m[MAX_NUMBER_DELAY_UROV];
extern WM_HWIN UROV_State_t[MAX_NUMBER_CTRL_UROV], UROV_State_v[MAX_NUMBER_CTRL_UROV];
extern const unsigned short int nalashtuvannja_UROV[/*MAX_KILKIST_STUPENIV_UROV + 1*/8];
extern const TITLE UROV_panel_title;
extern const TITLE UROV_Pickup_title[MAX_NUMBER_PICKUP_UROV];
extern const TITLE UROV_Delay_title[MAX_NUMBER_DELAY_UROV]; 
extern const TITLE UROV_State_title[MAX_NUMBER_CTRL_UROV];
extern int UROV_select_group;
extern unsigned char temp_data_for_UROV;

extern WM_HWIN DZ_FrameWin, DZ_MultiPage_groups, DZ_Window_group, DZ_MultiPage_type_info, DZ_Pages[MAX_PAGES_PROTECTION_SDC];
extern WM_HWIN DZ_SubPages_delay[2];
extern SCROLLBAR_Handle ScrollBar_DZ_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_DZ_SubPages_delay[2];
extern int _y_cbPickup_DZ, _y_cbDelay_DZ, _y_cbDelay_DZ_g, _y_cbControl_DZ;
extern WM_HWIN DZ_Pickup_t[MAX_NUMBER_PICKUP_DZ], DZ_Pickup_v[MAX_NUMBER_PICKUP_DZ], DZ_Pickup_m[MAX_NUMBER_PICKUP_DZ];
extern WM_HWIN DZ_Delay_t[MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G], DZ_Delay_v[MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G], DZ_Delay_m[MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G];
extern WM_HWIN DZ_State_t[MAX_NUMBER_CTRL_DZ], DZ_State_v[MAX_NUMBER_CTRL_DZ];
extern const unsigned short int nalashtuvannja_DZ[MAX_KILKIST_STUPENIV_DZ + 1];
extern const TITLE DZ_panel_title;
extern const TITLE DZ_Pickup_title[MAX_NUMBER_PICKUP_DZ];
extern const TITLE DZ_Delay_title[MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G]; 
extern const TITLE DZ_State_title[MAX_NUMBER_CTRL_DZ];
extern int DZ_select_group;

extern WM_HWIN CB_FrameWin, CB_MultiPage_groups, CB_Window_group, CB_MultiPage_type_info, CB_Pages[MAX_PAGES_PROTECTION_SDC];
extern SCROLLBAR_Handle ScrollBar_CB_Pages[MAX_PAGES_PROTECTION_SDC];
extern int _y_cbPickup_CB, _y_cbDelay_CB, _y_cbDelay_CB_g, _y_cbControl_CB;
extern WM_HWIN CB_Pickup_t[MAX_NUMBER_PICKUP_CB], CB_Pickup_v[MAX_NUMBER_PICKUP_CB], CB_Pickup_m[MAX_NUMBER_PICKUP_CB];
extern WM_HWIN CB_Delay_t[MAX_NUMBER_DELAY_CB], CB_Delay_v[MAX_NUMBER_DELAY_CB], CB_Delay_m[MAX_NUMBER_DELAY_CB];
extern WM_HWIN CB_State_t[MAX_NUMBER_CTRL_CB], CB_State_v[MAX_NUMBER_CTRL_CB];
extern const unsigned short int nalashtuvannja_CB[1];
extern const TITLE CB_panel_title;
extern const TITLE CB_Pickup_title[MAX_NUMBER_PICKUP_CB];
extern const TITLE CB_Delay_title[MAX_NUMBER_DELAY_CB]; 
extern const TITLE CB_State_title[MAX_NUMBER_CTRL_CB];

extern int one_group;

extern WM_HWIN Settings_IconView;
extern BITMAP_ITEM _aBitmapItem_settings[SETTINGS_SIZE];
extern const GUI_BITMAP * pBitmaps_prt_off[SETTINGS_SIZE - 4];

extern WM_HWIN Comm_IconView;
extern BITMAP_ITEM _aBitmapItem_Comm[COMM_SIZE];

extern WM_HMEM Edit_groups, Edit_saving_EERPOM, Edit_transmit_settings_L, Edit_transmit_settings_M, Edit_clock;
extern unsigned int redraw_status_bar;

extern WM_HWIN Modbus_FrameWin;
extern const TITLE Modbus_panel_title;
extern SCROLLBAR_Handle ScrollBar_Modbus;
extern int _y_cbPickup_Modbus;
extern WM_HWIN Modbus_t[MAX_NUMBER_ITEMS_MODBUS];
extern WM_HWIN Modbus_v[MAX_NUMBER_ITEMS_MODBUS];
extern WM_HWIN Modbus_d;
extern const TITLE Modbus_title[MAX_NUMBER_ITEMS_MODBUS];
extern const char *Baud_rate_title[7];
extern const TITLE Parity_title[3];
extern const char *Stop_bits_title[2];
extern const TITLE Modbus_Timeout_dimention;

extern WM_HWIN Net_FrameWin;
extern const TITLE Net_panel_title;
extern SCROLLBAR_Handle ScrollBar_Net;
extern int _y_cbPickup_Net;

extern WM_HWIN Transformer_FrameWin;
extern const TITLE Transformer_panel_title;
extern SCROLLBAR_Handle ScrollBar_Transformer;
extern int _y_cbPickup_Transformer;
extern WM_HWIN Transformer_t[MAX_NUMBER_ITEMS_TRANSFORMER];
extern WM_HWIN Transformer_v[MAX_NUMBER_ITEMS_TRANSFORMER];
extern const TITLE Transformer_title[MAX_NUMBER_ITEMS_TRANSFORMER];
extern const TITLE Transformer_line_title[3];

extern WM_HWIN Resurs_FrameWin, Resurs_t[MAX_NUMBER_ITEMS_RESURS], Resurs_v[MAX_NUMBER_ITEMS_RESURS];
extern const TITLE Resurs_panel_title;
extern const TITLE Resurs_title[MAX_NUMBER_ITEMS_RESURS];
extern unsigned int resurs_tmp, resurs_count_tmp;

extern WM_HWIN LCD_Settings_FrameWin, LCD_Settings_Edit, LCD_Settings_t, LCD_Settings_d;
extern const TITLE LCD_Settings_title;
extern const TITLE LCD_Settings_Delay_title;
extern const TITLE LCD_Settings_Delay_dimention;

extern WM_HWIN TM_FrameWin, TM_MultiPage_type_info, TM_Pages[2], TM_IO_Header, TM_IO_Pages[2], TM_F_Header, TM_F_Pages[2];
extern const TITLE TM_panel_title;
extern const LANG_ITEM TM_Page_name[];
extern const TITLE TM_IO_columns[];
extern const TITLE TM_F_columns[];
extern SCROLLBAR_Handle ScrollBar_TM_Pages[2];
extern WM_HWIN TM_Inputs[NUM_IN];
extern WM_HWIN TM_Outputs[NUM_OUT];
extern WM_HWIN TM_F[2][MAX_NUMBER_F_IN_PANEL];
extern unsigned int TM_max_number_bits;

extern unsigned int state_active_functions[NUMBER_4BYTES_WORDS_FOR_FUBCTIOBS];
extern unsigned int state_actuated_functions[NUMBER_4BYTES_WORDS_FOR_FUBCTIOBS];

extern WM_HWIN Diagnostics_FrameWin, Diagnostics_MultiPage_type_info, Diagnostics_Pages;
extern const TITLE Diagnostics_panel_title;
extern const LANG_ITEM Diagnostics_Page_name[];
extern SCROLLBAR_Handle ScrollBar_Diagnostics_Pages;
extern WM_HWIN Diagnostics_Info[MAX_NUMBER_DIAGN_IN_PANEL];
extern unsigned int Diagnistics_max_number_bits[4];

extern char *diagnostics_bs_mrzv_str_tmp[LANG_LIST_SIZE][ERROR_BS_FATAL_EROR_LAST_BIT];
extern char *diagnostics_bo_mrzv_m_str_tmp[LANG_LIST_SIZE][ERROR_BM_FATAL_EROR_LAST_BIT];
extern char *diagnostics_bo_mrzv_l_str_tmp[LANG_LIST_SIZE][ERROR_BR_FATAL_EROR_LAST_BIT];

//extern unsigned int diagnostics_bs_mrzv_tmp[NUMBER_4BYTES_WORDS_FOR_DIAGNOSTICS];
//extern unsigned int diagnostics_bo_mrzv_m_tmp[NUMBER_4BYTES_WORDS_FOR_DIAGNOSTICS];
//extern unsigned int diagnostics_bo_mrzv_l_tmp[NUMBER_4BYTES_WORDS_FOR_DIAGNOSTICS];

extern MENU_Handle hMenu_main, hMin_settings, hOption, hPasswords, hPickup_Group, hCommands, hAbout;
extern const TITLE menu_option_title[];
extern const TITLE menu_option_explanation[];
extern const _id_user_widget id_menu[];

extern unsigned int current_modal_form;
extern unsigned int command_from_menu;
extern unsigned int min_settings, min_settings_1;

extern unsigned int timeout_LCD;
extern unsigned int state_command_power_LCD;

extern unsigned int edit_Pick_up_Set, set_new_Pick_up_Set;

extern WM_HWIN Clock_FrameWin;
extern const TITLE Clock_panel_title;
extern WM_HWIN Clock_t[5];
extern WM_HWIN Clock_v[MAX_NUMBER_ITEMS_CLOCK];
extern const char *Calibration_title[3];

extern WM_HWIN About_FrameWin, About_Line_1, About_Line_2, About_Line_3, About_Line_4, About_Line_5;
extern WM_HWIN About_Line_6, About_Line_7, About_Line_8, About_Line_9, About_Line_10, About_Line_11, About_Line_12;
extern IMAGE_Handle Image_logo;
extern const TITLE About_title;

extern WM_HWIN Registrators_FrameWin, Registrators_MultiPage_type, Registrators_Window;
extern WM_HWIN Registrators_Window_up, Registrators_Window_down, Registrators_Window_up_left, Registrators_Window_up_right;
extern WM_HWIN Registrator_number;
extern WM_HWIN Registrator_number, Registrator_number_from, Registrator_total_number;
extern WM_HWIN Registrator_date_time_prefault, Registrator_date_time_fault;
extern const TITLE Registrators_panel_title;
extern const LANG_ITEM Registrators_MultiPage_Items[3];

//Змінні для визначеня ресурсу процесора-програми
extern volatile unsigned int restart_resurs_count;
extern unsigned int resurs_temp;
extern unsigned int resurs_global;
extern unsigned int resurs_global_min;
extern unsigned int resurs_global_max;

extern unsigned int restart_timing_period;
extern volatile unsigned int time_period;
extern unsigned int time_1_period;
extern unsigned int time_2_period;
extern unsigned int time_delta_period;
extern unsigned int time_delta_period_min;
extern unsigned int time_delta_period_max;

extern unsigned int period_10ms;

//extern Pin pPins_test[1];

extern unsigned char receiving_buffer_ZigBee[SIZE_BUFFER_ZIGBEE];
extern unsigned char count_receiving_byte_ZigBee;
extern unsigned char transmiting_buffer_ZigBee[SIZE_BUFFER_ZIGBEE];
extern unsigned char count_transmiting_byte_ZigBee;
extern unsigned char data_ZigBee_received;
extern unsigned char data_ZigBee_transmiting;

extern CfgTblDsc edit_settings;
extern AuxCfgTbl1Dsc edit_settings_1;

extern _Bool change_language;

//Обмін через SPI1
extern unsigned char Temporaty_SPI1_Buffer_Tx[SIZE_BUFFER_FOR_RED];
extern unsigned char Temporaty_SPI1_Buffer_Rx[SIZE_BUFFER_FOR_RED];
extern unsigned int Temporaty_SPI1_Buffer_Tx_with_CS[SIZE_BUFFER_FOR_RED];
extern unsigned int Temporaty_SPI1_Buffer_Rx_with_CS[SIZE_BUFFER_FOR_RED];
extern unsigned int number_transmit_SPI1;
extern int state_execution_spi1;
extern unsigned int control_spi1_taskes[2];
extern unsigned int comparison_writing;
extern unsigned int state_spi1_task;
extern int etap_reset_of_bit;
extern int etap_settings_test_frequency;
extern int etap_eeprom_write_enable;
extern unsigned char temp_register_rtc[2];

extern volatile unsigned int periodical_tasks_TEST_SETTINGS_PRT;
extern volatile unsigned int periodical_tasks_TEST_SETTINGS_BS;
extern volatile unsigned int periodical_tasks_TEST_USTUVANNJA;
extern volatile unsigned int periodical_tasks_TEST_TRG_FUNC;
extern volatile unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_AR;
extern volatile unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_DR;
extern volatile unsigned int periodical_tasks_TEST_INFO_REJESTRATOR_PR_ERR;

extern unsigned int diagnostyka[2];

extern unsigned char rtc_time[8]; 
extern unsigned char rtc_time_copy[8]; 
extern unsigned char rtc_calibration;
extern unsigned char rtc_calibration_copy;
extern unsigned int copying_time;
extern unsigned char rtc_time_edit[8]; 
extern unsigned char rtc_calibration_edit;
extern unsigned int copy_register8_RTC;

extern unsigned char crc_ustuvannja;
extern unsigned int ustuvannja[NUMBER_CANALS];
extern int phi_ustuvannja[NUMBER_CANALS];
extern unsigned int ustuvannja_P[3], ustuvannja_Q[3];

extern CfgTblDsc eeprom_prt_tbl;
extern unsigned char crc_settings_prt;
extern AuxCfgTbl1Dsc eeprom_bs_settings_tbl;
extern unsigned char modbus_address;
extern unsigned char crc_settings_bs;

extern unsigned int state_signal_outputs;
extern unsigned int state_trigger_leds;

extern unsigned int trigger_active_functions[N_TMP];

extern unsigned int AR_DR;

extern unsigned int status_register_df_ar;
extern unsigned int address_read_write_ar;
extern unsigned int number_bytes_read_write_ar;
extern  unsigned int buffer_serial_DataFlash_read_write_ar[SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR];

extern unsigned int status_register_df_dr;
extern unsigned int address_read_write_dr;
extern unsigned int number_bytes_read_write_dr;
extern unsigned int buffer_serial_DataFlash_read_write_dr[SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR];

extern __INFO_REJESTRATOR info_rejestrator_ar;
extern unsigned char crc_info_rejestrator_ar;

extern __TEMP_STRUCTURE EepromDRecDesc;
extern unsigned char crc_info_rejestrator_dr;

extern PrgEvtFlash_2_Dsc hPrgEvtMangInfo;
extern unsigned char crc_info_rejestrator_pr_err;

extern unsigned int control_ar_taskes;
extern unsigned char table_data_ar[NUMBER_DATA_BLOCKS + 1];


