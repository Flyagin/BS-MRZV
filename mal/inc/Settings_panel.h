#ifndef __SETTINGS_PANEL__
#define __SETTINGS_PANEL__

#define ERROR_SETTINGS_MSG_UKR            "Цей захист виведений з конфігурації. ВВІД або ВИХІД для повернення" 
#define ERROR_SETTINGS_MSG_RUS            "Эта защита выведена с конфигурации.  ВВОД або ВЫХОД для возврата"
#define ERROR_SETTINGS_MSG_ENG            "This protection is switched off from the configuration. Press ENTER or ESC for returning"


enum __settings_idList {
  SETTINGS_CONFIG_ID,
  SETTINGS_RANK_ID,
  SETTINGS_DZ_ID,
  SETTINGS_MTZ_ID,
  SETTINGS_TZNP_ID,
  SETTINGS_ZOP_ID,
  SETTINGS_UMIN_ID,
  SETTINGS_UMAX_ID,
  SETTINGS_APV_ID,
  SETTINGS_UROV_ID,
  SETTINGS_CB_ID,
  TRANSFORMER_ID,
  COMM_ID,
  
  SETTINGS_SIZE
};

#endif
