
#ifndef __GUI_FUNCTIONS_H
#define __GUI_FUNCTIONS_H

void gui_init();
void desctop_init();
void lang_dlg_init();
void measurement_panel_init();
void configuration_panel_init();
void rank_panel_init();
void rank_dlg_di_init();
void rank_dlg_do_init();
void rank_dlg_led_init();
void rank_dlg_df_init();
void rank_dlg_an_rec_init();

int get_main_panel_id();
int get_settings_panel_id();

void gui_tmr_routines(); //функция будет вызываться раз в 1с по таймеру
void gui_routines();

void show_window(int win_id);
void hide_window(int win_id);
void win_handler();

void copy_settings_from_buff(int id);

void change_language_next();
void change_language_previous();
void set_current_language(int index_position);

//**Измерения*******************//
void update_measurement_pg();
void update_measurement_i_pg();
void update_angles_pg();
void update_sectors_pg();
void update_resistances_pg();
void update_speed_resistance_change_pg();
void update_resistance_angle_pg();
void update_other_meas_pg();
void meas_scrolling_direction(int direction);
void meas_scrolling();
void select_meas_multipage(int index);
void select_meas_multipage_up_down();
//**Измерения*******************//

//**Конфигурация****************//
void copy_config_settings_to_buff();
void copy_config_settings_from_buff();

void conf_enter_handler();

void update_conf_item();
//**Конфигурация****************//

//**Ранжирование****************//
_Bool checkAllRankVal();
int numToExternalRankFuncs(int index_position);
int numToInternalRankFuncs(int index_position);

int ignore_hbit(int val);

void init_sub_pg();

_Bool rank_vk_esc_handler();
void rank_vk_enter_handler();
void select_rank_multipage(int index);
void select_rank_sub_multipage(char _direction, _Bool pgJump, int jumpPgPosition, int jumpCheckboxPosition);
_Bool checkbox_is_enabled();

_Bool di_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
_Bool durationDIIsCorrect();
void update_di_settings();
void update_di_status_panel();
void update_di_title();
void update_di_labels();

_Bool do_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
void update_do_settings();
void update_do_status_panel();
void update_do_title();
void update_do_labels();

_Bool led_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
void update_led_settings();
void update_led_status_panel();
void update_led_title();
void update_led_labels();

_Bool df_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
_Bool timerDelayDFIsCorrect();
_Bool timerWorkDFIsCorrect();
void update_df_settings();
void update_df_status_panel();
void update_df_title();
void update_df_labels();

_Bool an_rec_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
_Bool timePreFaultAnRecIsCorrect();
_Bool timePostFaultAnRecIsCorrect();
void update_an_rec_settings();
void update_an_rec_status_panel();
void update_an_rec_title();
void update_an_rec_labels();

void copy_rank_settings_to_buff();
void copy_rank_settings_from_buff();

void create_disabling_rank_inf(int index_position, unsigned int (*pArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS], int height, int width);
//**Ранжирование****************//

int GUI_Exec(void);

#endif

