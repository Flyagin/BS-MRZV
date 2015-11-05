extern void JLINKDCC_Process(void);
extern void* LCD_BOARD_SetFrameBufferAddress(void *address);

extern void ConfigureSPI1(void);
extern void start_exchange_via_SPI1(unsigned int, unsigned int);
extern void main_routines_for_spi1(void);

extern void strcat_mal(char*, char*);
extern int strlen_mal(char*);
extern int strinsert_mal(char*, int, char*);
extern int strdel_mal(char*, int, int);
extern int strcmp_mal(char*, char*);

extern void ConfigurePIT(void);
extern void Sys_IrqHandler(void);

extern void LCD_IrqHandler(void);

extern void global_variables_installation(void);

extern void start_tasks_mal(void);
extern void periodical_tasks_mal(void);

extern void main_menu_function(void);

extern void StartUPInitKBD(void);
extern void StartUPInitLCD(void);
extern void handle_kbd(void);

extern void _cbEmpty(WM_MESSAGE*);

extern int int_to_str (unsigned int, char*);

extern void select_multipage_general(WM_HWIN, int);
extern void select_multipage_groups(WM_HWIN, WM_HWIN*, int, int, int);
extern void redraw_panel_protection(__index_level_menu);
extern void calc_number_gaps_ctrl_protection(unsigned int*, int*, unsigned int, const unsigned short int*, unsigned int);

extern void select_multipage_info_n(WM_HWIN, int, unsigned int);
extern void redraw_panel_info_n(__index_level_menu);

extern void repaint_actions(__index_level_menu);

extern void redraw_panel_settings(void);
extern void redraw_panel_Comm(void);
extern void redraw_panel_Modbus(void);
extern void redraw_panel_Net(void);
extern void redraw_panel_transformer(void);
extern void redraw_panel_resurs(void);
extern void redraw_panel_clock(void);
extern void redraw_panel_lcd_settings(void);

extern void dialog_password_show(int, unsigned int);
extern void dialog_confirmation_show(int);
extern void dialog_error_show(int);
extern void unreliable_error_show(int);
extern void protection_settings_panel_show(unsigned int);
extern void settings_panel_show(void);
extern void transformer_panel_show(void);
extern void Comm_panel_show(void);
extern void Modbus_panel_show(void);
extern void Net_panel_show(void);
extern void resurs_panel_show(void);
extern void clock_panel_show(void);
extern void lcd_settings_show(void);
extern void info_n_panel_show(unsigned int);
extern void About_show(void);
extern void registrators_panel_show(void);
extern void redraw_panel_registrators(void);

extern void Set_Test_and_cursor_into_EDIT(WM_HWIN, char*, int, int, char);

extern int* DZ_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* MTZ_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* Umin_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* Umax_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* TZNP_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* ZOP_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* APV_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* UROV_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
extern int* CB_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);

extern unsigned short int* DZ_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* MTZ_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* Umin_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* Umax_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* TZNP_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* ZOP_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* APV_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* UROV_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern unsigned short int* CB_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);

extern void DZ_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void MTZ_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void Umin_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void Umax_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void TZNP_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void ZOP_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void APV_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void UROV_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
extern void CB_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);

extern void DZ_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void MTZ_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void Umin_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void Umax_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void TZNP_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void ZOP_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void APV_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void UROV_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
extern void CB_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);

extern const char* DZ_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* MTZ_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* Umin_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* Umax_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* TZNP_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* ZOP_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* APV_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* UROV_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
extern const char* CB_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);

extern const char* DZ_delay_info_1(unsigned int, int*, int*, int*);
extern const char* MTZ_delay_info_1(unsigned int, int*, int*, int*);
extern const char* Umin_delay_info_1(unsigned int, int*, int*, int*);
extern const char* Umax_delay_info_1(unsigned int, int*, int*, int*);
extern const char* TZNP_delay_info_1(unsigned int, int*, int*, int*);
extern const char* ZOP_delay_info_1(unsigned int, int*, int*, int*);
extern const char* APV_delay_info_1(unsigned int, int*, int*, int*);
extern const char* UROV_delay_info_1(unsigned int, int*, int*, int*);
extern const char* CB_delay_info_1(unsigned int, int*, int*, int*);

extern const char* DZ_pickup_dimention(unsigned int);
extern const char* MTZ_pickup_dimention(unsigned int);
extern const char* Umin_pickup_dimention(unsigned int);
extern const char* Umax_pickup_dimention(unsigned int);
extern const char* TZNP_pickup_dimention(unsigned int);
extern const char* ZOP_pickup_dimention(unsigned int);
extern const char* APV_pickup_dimention(unsigned int);
extern const char* UROV_pickup_dimention(unsigned int);
extern const char* CB_pickup_dimention(unsigned int);

extern const TITLE* DZ_control_info(unsigned int, int*);
extern const TITLE* MTZ_control_info(unsigned int, int*);
extern const TITLE* Umin_control_info(unsigned int, int*);
extern const TITLE* Umax_control_info(unsigned int, int*);
extern const TITLE* TZNP_control_info(unsigned int, int*);
extern const TITLE* ZOP_control_info(unsigned int, int*);
extern const TITLE* APV_control_info(unsigned int, int*);
extern const TITLE* UROV_control_info(unsigned int, int*);
extern const TITLE* CB_control_info(unsigned int, int*);

extern unsigned char* DZ_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* MTZ_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* Umin_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* Umax_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* TZNP_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* ZOP_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* APV_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* UROV_pointer_to_state(unsigned int, CfgTblDsc*);
extern unsigned char* CB_pointer_to_state(unsigned int, CfgTblDsc*);

extern void DZ_change_state_callback(unsigned int, CfgTblDsc*);
extern void MTZ_change_state_callback(unsigned int, CfgTblDsc*);
extern void Umin_change_state_callback(unsigned int, CfgTblDsc*);
extern void Umax_change_state_callback(unsigned int, CfgTblDsc*);
extern void TZNP_change_state_callback(unsigned int, CfgTblDsc*);
extern void ZOP_change_state_callback(unsigned int, CfgTblDsc*);
extern void APV_change_state_callback(unsigned int, CfgTblDsc*);
extern void UROV_change_state_callback(unsigned int, CfgTblDsc*);
extern void CB_change_state_callback(unsigned int, CfgTblDsc*);

extern unsigned int check_pickup_delay_DZ(CfgTblDsc*);
extern unsigned int check_pickup_delay_MTZ(CfgTblDsc*);
extern unsigned int check_pickup_delay_Umin(CfgTblDsc*);
extern unsigned int check_pickup_delay_Umax(CfgTblDsc*);
extern unsigned int check_pickup_delay_TZNP(CfgTblDsc*);
extern unsigned int check_pickup_delay_ZOP(CfgTblDsc*);
extern unsigned int check_pickup_delay_APV(CfgTblDsc*);
extern unsigned int check_pickup_delay_UROV(CfgTblDsc*);
extern unsigned int check_pickup_delay_CB(CfgTblDsc*);
extern unsigned int check_pickup_delay_Transformer(CfgTblDsc*);
extern unsigned int check_pickup_delay_Modbus(AuxCfgTbl1Dsc*);
extern unsigned int check_Date_Time_clock(unsigned char*, unsigned char*);
extern unsigned int check_pickup_delay_LCD_Settings(unsigned int timeout_tmp);

extern void copy_data_DZ(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_MTZ(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_Umin(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_Umax(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_TZNP(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_ZOP(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_APV(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_UROV(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_CB(CfgTblDsc*, CfgTblDsc*);
extern void copy_data_Modbus(AuxCfgTbl1Dsc*, AuxCfgTbl1Dsc*);
extern void copy_data_Transformer(CfgTblDsc*, CfgTblDsc*);

extern void selection_for_Clock (WM_HWIN);

extern void make_min_settings_1(AuxCfgTbl1Dsc*);
 
extern void desctop_menu_init_mal(void);

extern void settings_for_ZigBee(void);
extern void restart_monitoring_ZigBee(void);
extern void ZigBee_scaner(void);
extern void ZigBee_transmit(void);

extern void control_settings_prt(void);
extern void control_settings_bs(void);
extern void control_ustuvannja(void);

//Функції ,які я використовую інших програмувальників
extern void ChangeConfRS485(unsigned BaudRate, unsigned PARITY, unsigned StopBit);

extern void clean_table_data_dr(void);
extern void main_routines_for_ar(void);

