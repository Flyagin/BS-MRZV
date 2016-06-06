
extern void gui_tmr_routines(); //функция будет вызываться раз в 1с по таймеру
extern void gui_routines();

extern void gui_init();
extern void desctop_init();
extern void lang_dlg_init();
extern void winding_dlg_init();
extern void measurement_panel_init();
extern void configuration_panel_init();
extern void rank_panel_init();
extern void rank_dlg_di_init();
extern void rank_dlg_do_init();
extern void rank_dlg_led_init();
extern void rank_dlg_df_init();
extern void rank_dlg_an_rec_init();

extern int get_main_panel_id();
extern int get_settings_panel_id();

extern void show_window(int win_id);
extern void hide_window(int win_id);
extern void win_handler();

extern void copy_settings_from_buff(int id);

extern void change_language_next();
extern void change_language_previous();
extern void set_current_language(int index_position);

//**Измерения*******************//
extern long GetTotMeas(void *pvMeasAddr);

extern void update_measurement_pg();
extern void update_measurement_i_pg();
extern void update_angles_pg();
extern void update_sectors_pg();
extern void update_resistances_pg();
extern void update_speed_resistance_change_pg();
extern void update_resistance_angle_pg();
extern void update_other_meas_pg();
extern void meas_scrolling_direction(int direction);
extern void meas_scrolling();
extern void select_meas_multipage(int index);
extern void select_meas_multipage_up_down();
//**Измерения*******************//

//**Конфигурация****************//
extern void copy_config_settings_to_buff();
extern void copy_config_settings_from_buff();

extern void conf_enter_handler();

extern void update_conf_item();
//**Конфигурация****************//

//**Ранжирование****************//
extern _Bool checkAllRankVal();
extern int numToExternalRankFuncs(int index_position);
extern int numToInternalRankFuncs(int index_position);

extern int ignore_hbit(int val);

extern void init_sub_pg();

extern _Bool rank_vk_esc_handler();
extern void rank_vk_enter_handler();
extern void select_rank_multipage(int index);
extern void select_rank_sub_multipage(char _direction, _Bool pgJump, int jumpPgPosition, int jumpCheckboxPosition);
extern _Bool checkbox_is_enabled();

extern _Bool di_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
extern _Bool durationDIIsCorrect();
extern void update_di_settings();
extern void update_di_status_panel();
extern void update_di_title();
extern void update_di_labels();

extern _Bool do_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
extern void update_do_settings();
extern void update_do_status_panel();
extern void update_do_title();
extern void update_do_labels();

extern _Bool led_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
extern void update_led_settings();
extern void update_led_status_panel();
extern void update_led_title();
extern void update_led_labels();

extern _Bool df_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
extern _Bool timerDelayDFIsCorrect();
extern _Bool timerWorkDFIsCorrect();
extern void update_df_settings();
extern void update_df_status_panel();
extern void update_df_title();
extern void update_df_labels();

extern _Bool an_rec_dlg_event_listener(unsigned int * key, unsigned int * command_state, unsigned int error_fixed);
extern _Bool timePreFaultAnRecIsCorrect();
extern _Bool timePostFaultAnRecIsCorrect();
extern void update_an_rec_settings();
extern void update_an_rec_status_panel();
extern void update_an_rec_title();
extern void update_an_rec_labels();

extern void copy_rank_settings_to_buff();
extern void copy_rank_settings_from_buff();

extern void create_disabling_rank_inf(int index_position, unsigned int (*pArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS], int height, int width);
//**Ранжирование****************//
