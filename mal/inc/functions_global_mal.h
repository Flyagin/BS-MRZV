#ifndef __GLOBAL_FUNCTIONS_MAL_H
#define __GLOBAL_FUNCTIONS_MAL_H

extern void JLINKDCC_Process(void);
extern void* LCD_BOARD_SetFrameBufferAddress(void *address);

void ConfigureSPI1(void);
void start_exchange_via_SPI1(unsigned int, unsigned int);
void main_routines_for_spi1(void);

void strcat_mal(char*, char*);
int strlen_mal(char*);
int strinsert_mal(char*, int, char*);
int strdel_mal(char*, int, int);
int strcmp_mal(char*, char*);

void ConfigurePIT(void);
void Sys_IrqHandler(void);

void LCD_IrqHandler(void);

void global_variables_installation(void);

void start_tasks_mal(void);
void periodical_tasks_mal(void);

void main_menu_function(void);

void StartUPInitKBD(void);
void StartUPInitLCD(void);
void handle_kbd(void);

void _cbEmpty(WM_MESSAGE*);

int int_to_str (unsigned int, char*);

void select_multipage_general(WM_HWIN, int);
void select_multipage_groups(WM_HWIN, WM_HWIN*, int, int, int);
void redraw_panel_protection(__index_level_menu);
void calc_number_gaps_ctrl_protection(unsigned int*, int*, unsigned int, const unsigned short int*, unsigned int);

void select_multipage_info_n(WM_HWIN, int, unsigned int);
void redraw_panel_info_n(__index_level_menu);

void repaint_actions(__index_level_menu);
void redraw_panel_settings(void);
void redraw_panel_Comm(void);
void redraw_panel_Modbus(void);
void redraw_panel_Net(void);
void redraw_panel_transformer(void);
void redraw_panel_resurs(void);
void redraw_panel_clock(void);
void redraw_panel_lcd_settings(void);

void dialog_password_show(int, unsigned int);
void dialog_confirmation_show(int);
void dialog_error_show(int);
void unreliable_error_show(int);
void protection_settings_panel_show(unsigned int);
void settings_panel_show(void);
void transformer_panel_show(void);
void Comm_panel_show(void);
void Modbus_panel_show(void);
void Net_panel_show(void);
void resurs_panel_show(void);
void clock_panel_show(void);
void lcd_settings_show(void);
void info_n_panel_show(unsigned int);
void About_show(void);
void registrators_panel_show(void);
void redraw_panel_registrators(void);

void Set_Test_and_cursor_into_EDIT(WM_HWIN, char*, int, int, char);

int* DZ_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* MTZ_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* Umin_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* Umax_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* TZNP_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* ZOP_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* APV_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* UROV_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
int* CB_pickups_notification_value_changed(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);

unsigned short int* DZ_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* MTZ_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* Umin_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* Umax_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* TZNP_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* ZOP_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* APV_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* UROV_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
unsigned short int* CB_delays_notification_value_changed(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);

void DZ_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void MTZ_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void Umin_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void Umax_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void TZNP_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void ZOP_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void APV_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void UROV_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
void CB_pickup_info(unsigned int, CfgTblDsc*, int*, int*, float*, int*);

void DZ_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void MTZ_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void Umin_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void Umax_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void TZNP_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void ZOP_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void APV_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void UROV_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
void CB_delay_info(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);

const char* DZ_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* MTZ_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* Umin_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* Umax_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* TZNP_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* ZOP_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* APV_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* UROV_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);
const char* CB_pickup_info_1(unsigned int, int*, int*, int*, unsigned int*);

const char* DZ_delay_info_1(unsigned int, int*, int*, int*);
const char* MTZ_delay_info_1(unsigned int, int*, int*, int*);
const char* Umin_delay_info_1(unsigned int, int*, int*, int*);
const char* Umax_delay_info_1(unsigned int, int*, int*, int*);
const char* TZNP_delay_info_1(unsigned int, int*, int*, int*);
const char* ZOP_delay_info_1(unsigned int, int*, int*, int*);
const char* APV_delay_info_1(unsigned int, int*, int*, int*);
const char* UROV_delay_info_1(unsigned int, int*, int*, int*);
const char* CB_delay_info_1(unsigned int, int*, int*, int*);

const char* DZ_pickup_dimention(unsigned int);
const char* MTZ_pickup_dimention(unsigned int);
const char* Umin_pickup_dimention(unsigned int);
const char* Umax_pickup_dimention(unsigned int);
const char* TZNP_pickup_dimention(unsigned int);
const char* ZOP_pickup_dimention(unsigned int);
const char* APV_pickup_dimention(unsigned int);
const char* UROV_pickup_dimention(unsigned int);
const char* CB_pickup_dimention(unsigned int);

const TITLE* DZ_control_info(unsigned int, int*);
const TITLE* MTZ_control_info(unsigned int, int*);
const TITLE* Umin_control_info(unsigned int, int*);
const TITLE* Umax_control_info(unsigned int, int*);
const TITLE* TZNP_control_info(unsigned int, int*);
const TITLE* ZOP_control_info(unsigned int, int*);
const TITLE* APV_control_info(unsigned int, int*);
const TITLE* UROV_control_info(unsigned int, int*);
const TITLE* CB_control_info(unsigned int, int*);

unsigned char* DZ_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* MTZ_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* Umin_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* Umax_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* TZNP_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* ZOP_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* APV_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* UROV_pointer_to_state(unsigned int, CfgTblDsc*);
unsigned char* CB_pointer_to_state(unsigned int, CfgTblDsc*);

void DZ_change_state_callback(unsigned int, CfgTblDsc*);
void MTZ_change_state_callback(unsigned int, CfgTblDsc*);
void Umin_change_state_callback(unsigned int, CfgTblDsc*);
void Umax_change_state_callback(unsigned int, CfgTblDsc*);
void TZNP_change_state_callback(unsigned int, CfgTblDsc*);
void ZOP_change_state_callback(unsigned int, CfgTblDsc*);
void APV_change_state_callback(unsigned int, CfgTblDsc*);
void UROV_change_state_callback(unsigned int, CfgTblDsc*);
void CB_change_state_callback(unsigned int, CfgTblDsc*);

unsigned int check_pickup_delay_DZ(CfgTblDsc*);
unsigned int check_pickup_delay_MTZ(CfgTblDsc*);
unsigned int check_pickup_delay_Umin(CfgTblDsc*);
unsigned int check_pickup_delay_Umax(CfgTblDsc*);
unsigned int check_pickup_delay_TZNP(CfgTblDsc*);
unsigned int check_pickup_delay_ZOP(CfgTblDsc*);
unsigned int check_pickup_delay_APV(CfgTblDsc*);
unsigned int check_pickup_delay_UROV(CfgTblDsc*);
unsigned int check_pickup_delay_CB(CfgTblDsc*);
unsigned int check_pickup_delay_Transformer(CfgTblDsc*);
unsigned int check_pickup_delay_Modbus(AuxCfgTbl1Dsc*);
unsigned int check_Date_Time_clock(unsigned char*, unsigned char*);
unsigned int check_pickup_delay_LCD_Settings(unsigned int timeout_tmp);


void copy_data_DZ(CfgTblDsc*, CfgTblDsc*);
void copy_data_MTZ(CfgTblDsc*, CfgTblDsc*);
void copy_data_Umin(CfgTblDsc*, CfgTblDsc*);
void copy_data_Umax(CfgTblDsc*, CfgTblDsc*);
void copy_data_TZNP(CfgTblDsc*, CfgTblDsc*);
void copy_data_ZOP(CfgTblDsc*, CfgTblDsc*);
void copy_data_APV(CfgTblDsc*, CfgTblDsc*);
void copy_data_UROV(CfgTblDsc*, CfgTblDsc*);
void copy_data_CB(CfgTblDsc*, CfgTblDsc*);
void copy_data_Modbus(AuxCfgTbl1Dsc*, AuxCfgTbl1Dsc*);
extern void copy_data_Transformer(CfgTblDsc*, CfgTblDsc*);

void selection_for_Clock (WM_HWIN);

void make_min_settings_1(AuxCfgTbl1Dsc*);

void desctop_menu_init_mal(void);

void settings_for_ZigBee(void);
void restart_monitoring_ZigBee(void);
void ZigBee_scaner(void);
void ZigBee_transmit(void);

void control_settings_prt(void);
void control_settings_bs(void);
void control_ustuvannja(void);

void clean_table_data_dr(void);
void main_routines_for_ar(void);

#endif
