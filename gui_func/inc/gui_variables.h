
#ifndef __GUI_VARIABLES_H
#define __GUI_VARIABLES_H

#include "gui_lib_header.h"
#include "gui_variables_external.h"

#include "../inc/const_BS_BL.h"
#include "../inc/type_definition_BS.h"

_Bool start_gui_exec = 0;

_Bool gui_update = 0;

_Bool change_language = 0;

WM_HWIN desctopWin;

int win_id_list[MAX_LEVEL_MENU] = {
  (GUI_ID_USER + ID_EKRAN_MAIN)         ,
  (GUI_ID_USER + ID_LANG_DLG)           ,
  (GUI_ID_USER + ID_MAIN_MENU)          ,
  (GUI_ID_USER + ID_CONFIG_PG)          ,
  (GUI_ID_USER + ID_MEAS_PG)            ,
  (GUI_ID_USER + ID_RANK_PG)            ,
  (GUI_ID_USER + ID_RANK_DI_DLG)        ,
  (GUI_ID_USER + ID_RANK_DO_DLG)        ,
  (GUI_ID_USER + ID_RANK_LED_DLG)       ,
  (GUI_ID_USER + ID_RANK_DF_DLG)        ,
  (GUI_ID_USER + ID_RANK_AN_REC_DLG)
};

WM_HWIN _hMenu;
MENU_Handle hMenuFunc, hMenuHelp;

BITMAP_ITEM _aBitmapItem[ICONVIEW_SIZE] = 
{
  {&bmClock         , {CLOCK_UKR_TXT, CLOCK_RUS_TXT, CLOCK_ENG_TXT}          , {EXPL_CLOCK_IT_UKR, EXPL_CLOCK_IT_RUS, EXPL_CLOCK_IT_ENG}         },
  {&bmMeasurement   , {MEAS_UKR_TXT, MEAS_RUS_TXT, MEAS_ENG_TXT}             , {EXPL_MEAS_IT_UKR, EXPL_MEAS_IT_RUS, EXPL_MEAS_IT_ENG}            },
  {&bmResCounter    , {RESCOUNT_UKR_TXT, RESCOUNT_RUS_TXT, RESCOUNT_ENG_TXT} , {EXPL_RESCOUNT_IT_UKR, EXPL_RESCOUNT_IT_RUS, EXPL_RESCOUNT_IT_ENG}},
  {&bmInputOutputs  , {IO_UKR_TXT, IO_RUS_TXT, IO_ENG_TXT}                   , {EXPL_IO_IT_UKR, EXPL_IO_IT_RUS, EXPL_IO_IT_ENG}                  },
  {&bmRegistrators  , {REG_UKR_TXT, REG_RUS_TXT, REG_ENG_TXT}                , {EXPL_REG_IT_UKR, EXPL_REG_IT_RUS, EXPL_REG_IT_ENG}               },
  {&bmLanguage      , {LANG_UKR_TXT, LANG_RUS_TXT, LANG_ENG_TXT}             , {EXPL_LANG_IT_UKR, EXPL_LANG_IT_RUS, EXPL_LANG_IT_ENG}            },
  {&bmSettings      , {SETT_UKR_TXT, SETT_RUS_TXT, SETT_ENG_TXT}             , {EXPL_SETT_IT_UKR, EXPL_SETT_IT_RUS, EXPL_SETT_IT_ENG}            },
  {&bmDiagnostic    , {DIAGN_UKR_TXT, DIAGN_RUS_TXT, DIAGN_ENG_TXT}          , {EXPL_DIAGN_IT_UKR, EXPL_DIAGN_IT_RUS, EXPL_DIAGN_IT_ENG}         },
};
WM_HWIN iconWin;
int sel_icon = 0;

EDIT_Handle hEdit;

WM_HWIN langWin = WM_UNATTACHED;
WM_HWIN langRadioButton;
WM_HWIN langButtonOK;
WM_HWIN langButtonCancel;

WM_HWIN windingWin = WM_UNATTACHED;
WM_HWIN windingRadioButton;
WM_HWIN windingButtonOK;
WM_HWIN windingButtonCancel;

int lang_id_list[MAX_LEVEL_LANG_DLG] = {
  GUI_ID_RADIO0,
  GUI_ID_BUTTON0,
  GUI_ID_BUTTON1
};

int winding_id_list[MAX_LEVEL_WINDING_DLG] = {
  GUI_ID_RADIO0,
  GUI_ID_BUTTON0,
  GUI_ID_BUTTON1
};

/**Measurements**************************************/
__TOTAL_MEASUREMENT gui_total_measurement;

WM_HWIN measMultiPageWin = WM_UNATTACHED;
WM_HWIN measHMultiPage;
char meas_index_position = 0;
SCROLLBAR_Handle measPgScroll;
WM_HWIN measPgs[MAX_LEVEL_MEAS_PG];

char resistancesPosition = 0;
WM_HWIN resistancesMulPg;
WM_HWIN commonResistancesPg;

LANG_ITEM _measItem[MAX_LEVEL_MEAS_PG] = {
  { {MEAS_UKR_FOURIER, MEAS_RUS_FOURIER, MEAS_ENG_FOURIER}                                                 , {MEAS_UKR_FOURIER_EXPL, MEAS_RUS_FOURIER_EXPL, MEAS_ENG_FOURIER_EXPL}                                                 },
  { {MEAS_UKR_SUM_EQUATION, MEAS_RUS_SUM_EQUATION, MEAS_ENG_SUM_EQUATION}                                  , {MEAS_UKR_SUM_EQUATION_EXPL, MEAS_RUS_SUM_EQUATION_EXPL, MEAS_ENG_SUM_EQUATION_EXPL}                                  },
  { {MEAS_UKR_ANGLE, MEAS_RUS_ANGLE, MEAS_ENG_ANGLE}                                                       , {MEAS_UKR_ANGLE_EXPL, MEAS_RUS_ANGLE_EXPL, MEAS_ENG_ANGLE_EXPL}                                                       },
  { {MEAS_UKR_RESISTANCES, MEAS_RUS_RESISTANCES, MEAS_ENG_RESISTANCES}                                     , {MEAS_UKR_RESISTANCES_EXPL, MEAS_RUS_RESISTANCES_EXPL, MEAS_ENG_RESISTANCES_EXPL}                                     },
  { {MEAS_UKR_SPEED_RESISTANCE_CHANGE, MEAS_RUS_SPEED_RESISTANCE_CHANGE, MEAS_ENG_SPEED_RESISTANCE_CHANGE} , {MEAS_UKR_SPEED_RESISTANCE_CHANGE_EXPL, MEAS_RUS_SPEED_RESISTANCE_CHANGE_EXPL, MEAS_ENG_SPEED_RESISTANCE_CHANGE_EXPL} },
  { {MEAS_UKR_RESISTANCE_ANGLE, MEAS_RUS_RESISTANCE_ANGLE, MEAS_ENG_RESISTANCE_ANGLE}                      , {MEAS_UKR_RESISTANCES_ANGLE_EXPL, MEAS_RUS_RESISTANCES_ANGLE_EXPL, MEAS_ENG_RESISTANCES_ANGLE_EXPL} },
  { {MEAS_UKR_OTHER, MEAS_RUS_OTHER, MEAS_ENG_OTHER}                                                       , {MEAS_UKR_OTHER_EXPL, MEAS_RUS_OTHER_EXPL, MEAS_ENG_OTHER_EXPL} }
};

char * meas_item_units[MAX_LEVEL_MEAS_PG][LANG_LIST_SIZE][MAX_NUMBER_MEAS] = {
  {MEAS_UKR_FOURIER_UNITS, MEAS_RUS_FOURIER_UNITS, MEAS_ENG_FOURIER_UNITS},
  {MEAS_UKR_SUM_EQUATION_UNITS, MEAS_RUS_SUM_EQUATION_UNITS, MEAS_ENG_SUM_EQUATION_UNITS},
  {MEAS_UKR_ANGLE_UNITS, MEAS_RUS_ANGLE_UNITS, MEAS_ENG_ANGLE_UNITS},
  {MEAS_UKR_RESISTANCES_UNITS, MEAS_RUS_RESISTANCES_UNITS, MEAS_ENG_RESISTANCES_UNITS},
  {MEAS_UKR_SPEED_RESISTANCE_CHANGE_UNITS, MEAS_RUS_SPEED_RESISTANCE_CHANGE_UNITS, MEAS_ENG_SPEED_RESISTANCE_CHANGE_UNITS},
  {MEAS_UKR_RESISTANCE_ANGLE_UNITS, MEAS_RUS_RESISTANCE_ANGLE_UNITS, MEAS_ENG_RESISTANCE_ANGLE_UNITS},
  {MEAS_UKR_OTHER_UNITS, MEAS_RUS_OTHER_UNITS, MEAS_ENG_OTHER_UNITS}
};

char * measFrmText[LANG_LIST_SIZE] = {
  MEAS_UKR_FRM, MEAS_RUS_FRM, MEAS_ENG_FRM
};

char * windingText[2][LANG_LIST_SIZE] = {
  {MEAS_UKR_WINDING_FIRST, MEAS_RUS_WINDING_FIRST, MEAS_ENG_WINDING_FIRST},
  {MEAS_UKR_WINDING_SECOND, MEAS_RUS_WINDING_SECOND, MEAS_ENG_WINDING_SECOND}
};

int meas_id_list[MAX_LEVEL_MEAS_PG] = {
  0,
  0
};
/**Measurements**************************************/

/**Configuration**************************************/
WM_HWIN configPageWin = WM_UNATTACHED;

char config_index_position = 0;

unsigned char selInfConf[(NUM_CONF_ITEMS >> 3) + 1];

char * confFrmText[LANG_LIST_SIZE] = {
  CONF_UKR_FRM, CONF_RUS_FRM, CONF_ENG_FRM
};
char * confExplText[LANG_LIST_SIZE] = {
  CONF_UKR_EXPL, CONF_RUS_EXPL, CONF_ENG_EXPL
};
char * conf_checkbox_item[LANG_LIST_SIZE][NUM_CONF_ITEMS] = {
  RANK_UKR_CONFIG_NAME_LIST, RANK_RUS_CONFIG_NAME_LIST, RANK_ENG_CONFIG_NAME_LIST
};
/**Configuration**************************************/

/**Ranking*******************************************/
extern CfgTblDsc eeprom_prt_tbl;

unsigned int rank_control_bits = 0;

WM_HWIN rankMultiPageWin;
WM_HWIN rankHMultiPage;

WM_HWIN rankMulPgArr[MAX_LEVEL_RANK_PG];

SCROLLBAR_Handle rankDIPgScroll = WM_UNATTACHED;
WM_HWIN rankDIPgs = WM_UNATTACHED; //одна панель для всех вкладок д.вх.
SCROLLBAR_Handle rankDOLedOFDTArDrPgScroll = WM_UNATTACHED;
WM_HWIN rankDOLedOFDTArDrPgs = WM_UNATTACHED; //одна панель для всех вкладок д.вых. св.инд. опр.функ.
SCROLLBAR_Handle rankFPgScroll = WM_UNATTACHED;
WM_HWIN rankFPgs = WM_UNATTACHED; //одна панель для всех вкладок функ. кнопок

_Bool checkbox_pg_is_updated = 0;

WM_HWIN rankPgs[MAX_LEVEL_RANK_PG];

char rank_index_position = 0;
int di_index = 0;
int previous_di_rank_pg_y_val = 0;
int di_checkbox_sel_index[NUM_IN][2]; //[x][0] - выделенный чекбокс
                                      //[x][1] - положение панели ранжирования (координата Y)
int do_index = 0;
int previous_do_rank_pg_y_val = 0;
int do_checkbox_sel_index[NUM_OUT][2];

int led_index = 0;
int led_checkbox_sel_index[NUM_LED][2];

int df_plus_index = 0;
int df_plus_checkbox_sel_index[NUM_DEF_FUN][2];

int df_minus_index = 0;
int df_minus_checkbox_sel_index[NUM_DEF_FUN][2];

int df_blk_index = 0;
int df_blk_checkbox_sel_index[NUM_DEF_FUN][2];

int df_index = 0;

int f_index = 0;
int previous_f_rank_pg_y_val = 0;
int f_checkbox_sel_index[NUM_KEY][2];

int trg_set_pl_index = 0;
int trg_set_pl_checkbox_sel_index[NUM_TRG][2];

int trg_set_mn_index = 0;
int trg_set_mn_checkbox_sel_index[NUM_TRG][2];

int trg_rst_pl_index = 0;
int trg_rst_pl_checkbox_sel_index[NUM_TRG][2];

int trg_rst_mn_index = 0;
int trg_rst_mn_checkbox_sel_index[NUM_TRG][2];

unsigned int an_dig_rec_index = 0;
int an_dig_rec_checkbox_sel_index[2][2];

unsigned int checkbox_di_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS]; //для промежуточного хранения настроек ранжирования дискр. вх.
unsigned int checkbox_do_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS]; //для промежуточного хранения настроек ранжирования дискр. вых.
unsigned int checkbox_led_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS]; //для промежуточного хранения настроек ранжирования светодиодов
unsigned int checkbox_df_plus_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_df_minus_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_df_blk_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_f_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_trg_set_pl_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_trg_set_mn_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_trg_rst_pl_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_trg_rst_mn_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
unsigned int checkbox_an_dig_rec_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];

char * rank_msg_title[LANG_LIST_SIZE] = {
  MESSAGE_ERR_TITLE_UKR, MESSAGE_ERR_TITLE_RUS, MESSAGE_ERR_TITLE_ENG
};

char * rank_pgs_item[MAX_LEVEL_RANK_PG][LANG_LIST_SIZE][MAX_NUM_RANK_PGS] = {
  {RANK_UKR_DI_NAMES_LIST1, RANK_RUS_DI_NAMES_LIST1, RANK_ENG_DI_NAMES_LIST1},
  {RANK_UKR_DO_NAMES_LIST1, RANK_RUS_DO_NAMES_LIST1, RANK_ENG_DO_NAMES_LIST1},
  {RANK_UKR_LED_NAMES_LIST1, RANK_RUS_LED_NAMES_LIST1, RANK_ENG_LED_NAMES_LIST1},
  {RANK_UKR_DF_PLUS_NAMES_LIST1, RANK_RUS_DF_PLUS_NAMES_LIST1, RANK_ENG_DF_PLUS_NAMES_LIST1},
  {RANK_UKR_DF_MINUS_NAMES_LIST1, RANK_RUS_DF_MINUS_NAMES_LIST1, RANK_ENG_DF_MINUS_NAMES_LIST1},
  {RANK_UKR_DF_BLK_NAMES_LIST1, RANK_RUS_DF_MINUS_NAMES_LIST1, RANK_ENG_DF_MINUS_NAMES_LIST1},
  {RANK_UKR_F_NAMES_LIST1, RANK_RUS_F_NAMES_LIST1, RANK_ENG_F_NAMES_LIST1},
  {RANK_UKR_TRG_SET_PL_NAMES_LIST1, RANK_RUS_TRG_SET_PL_NAMES_LIST1, RANK_ENG_TRG_SET_PL_NAMES_LIST1},
  {RANK_UKR_TRG_SET_MN_NAMES_LIST1, RANK_RUS_TRG_SET_MN_NAMES_LIST1, RANK_ENG_TRG_SET_MN_NAMES_LIST1},
  {RANK_UKR_TRG_RST_PL_NAMES_LIST1, RANK_RUS_TRG_RST_PL_NAMES_LIST1, RANK_ENG_TRG_RST_PL_NAMES_LIST1},
  {RANK_UKR_TRG_RST_MN_NAMES_LIST1, RANK_RUS_TRG_RST_MN_NAMES_LIST1, RANK_ENG_TRG_RST_MN_NAMES_LIST1},
  {RANK_UKR_AN_DIG_REC_NAMES_LIST1, RANK_RUS_AN_DIG_REC_NAMES_LIST1, RANK_ENG_AN_DIG_REC_NAMES_LIST1}
};

char * rank_checkbox_item[LANG_LIST_SIZE][All_NUMB_RANK_ELEM] = {
  RANK_UKR_FUNC_NAME_LIST, RANK_RUS_FUNC_NAME_LIST, RANK_ENG_FUNC_NAME_LIST
};

LANG_ITEM _rankItem[MAX_LEVEL_RANK_PG] = {
  { {RANK_UKR_DISCR_INPUT, RANK_RUS_DISCR_INPUT, RANK_ENG_DISCR_INPUT}    , {RANK_UKR_DISCR_INPUT_EXPL, RANK_RUS_DISCR_INPUT_EXPL, RANK_ENG_DISCR_INPUT_EXPL}    },
  { {RANK_UKR_DISCR_OUTPUT, RANK_RUS_DISCR_OUTPUT, RANK_ENG_DISCR_OUTPUT} , {RANK_UKR_DISCR_OUTPUT_EXPL, RANK_RUS_DISCR_OUTPUT_EXPL, RANK_ENG_DISCR_OUTPUT_EXPL} },
  { {RANK_UKR_LED, RANK_RUS_LED, RANK_ENG_LED}                            , {RANK_UKR_LED_EXPL, RANK_RUS_LED_EXPL, RANK_ENG_LED_EXPL}                            },
  { {RANK_UKR_DF_PLUS, RANK_RUS_DF_PLUS, RANK_ENG_DF_PLUS}                , {RANK_UKR_DF_PLUS_EXPL, RANK_RUS_DF_PLUS_EXPL, RANK_ENG_DF_PLUS_EXPL}                },
  { {RANK_UKR_DF_MINUS, RANK_RUS_DF_MINUS, RANK_ENG_DF_MINUS}             , {RANK_UKR_DF_MINUS_EXPL, RANK_RUS_DF_MINUS_EXPL, RANK_ENG_DF_MINUS_EXPL}             },
  { {RANK_UKR_DF_BLK, RANK_RUS_DF_BLK, RANK_ENG_DF_BLK}                   , {RANK_UKR_DF_BLK_EXPL, RANK_RUS_DF_BLK_EXPL, RANK_ENG_DF_BLK_EXPL}                   },
  { {RANK_UKR_F, RANK_RUS_F, RANK_ENG_F}                                  , {RANK_UKR_F_EXPL, RANK_RUS_F_EXPL, RANK_ENG_F_EXPL}                                  },
  { {RANK_UKR_TRG_SET_PL, RANK_RUS_TRG_SET_PL, RANK_ENG_TRG_SET_PL}       , {RANK_UKR_TRG_SET_PL_EXPL, RANK_RUS_TRG_SET_PL_EXPL, RANK_ENG_TRG_SET_PL_EXPL}       },
  { {RANK_UKR_TRG_SET_MN, RANK_RUS_TRG_SET_MN, RANK_ENG_TRG_SET_MN}       , {RANK_UKR_TRG_SET_MN_EXPL, RANK_RUS_TRG_SET_MN_EXPL, RANK_ENG_TRG_SET_MN_EXPL}       },
  { {RANK_UKR_TRG_RST_PL, RANK_RUS_TRG_RST_PL, RANK_ENG_TRG_RST_PL}       , {RANK_UKR_TRG_RST_PL_EXPL, RANK_RUS_TRG_RST_PL_EXPL, RANK_ENG_TRG_RST_PL_EXPL}       },
  { {RANK_UKR_TRG_RST_MN, RANK_RUS_TRG_RST_MN, RANK_ENG_TRG_RST_MN}       , {RANK_UKR_TRG_RST_MN_EXPL, RANK_RUS_TRG_RST_MN_EXPL, RANK_ENG_TRG_RST_MN_EXPL}       },
  { {RANK_UKR_AN_DIG_REC, RANK_RUS_AN_DIG_REC, RANK_ENG_AN_DIG_REC}       , {RANK_UKR_AN_DIG_REC_EXPL, RANK_RUS_AN_DIG_REC_EXPL, RANK_ENG_AN_DIG_REC_EXPL}       }
};
char * editModeAdditionalText[LANG_LIST_SIZE] = {
  EDIT_MODE_EXPL_UKR, EDIT_MODE_EXPL_RUS, EDIT_MODE_EXPL_ENG
};

char * rankFrmText[LANG_LIST_SIZE] = {
  RANK_UKR_FRM, RANK_RUS_FRM, RANK_ENG_FRM
};

///Dialog rank variables////////////////////////
unsigned char diTypeSignal[(NUM_IN>>3)]; //тип сигнала (0-постоянный, 1-переменный)
unsigned char diTypeInput[(NUM_IN>>3)]; //режима работы дискретных входов (0-инверсный, 1-прямой)
unsigned short durationDI[NUM_IN]; //допуск дискр. входов

unsigned char doTypeOutputs[(NUM_OUT>>3)]; //тип выхода (0-сигнальный, 1-триггерный)
unsigned char ledsType[(NUM_LED>>3)]; //тип светоиндикатора (0-сигнальный, 1-триггерный)

unsigned long tmrDelayDF[NUM_DEF_FUN]; //Таймер паузы
unsigned long tmrWorkDF[NUM_DEF_FUN]; //Таймер работы
unsigned char typeDF[NUM_DEF_FUN]; //Тип функции

unsigned long timePreFaultArrVal = 100; //промежуточная переменная для хранения значения доаварийного массива
unsigned long timePostFaultArrVal = 1000; //промежуточная переменная для хранения значения послеаварийного массива

WM_HWIN rankDlgDIPg = WM_UNATTACHED;
WM_HWIN rankDlgDOPg = WM_UNATTACHED;
WM_HWIN rankDlgLEDPg = WM_UNATTACHED;
WM_HWIN rankDlgDFPg = WM_UNATTACHED;
WM_HWIN rankDlgAnRecPg = WM_UNATTACHED;

char * durationDITextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT1_DI, RANK_RUS_DLG_TEXT1_DI, RANK_ENG_DLG_TEXT1_DI
};
char * signalTypeDITextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT2_DI, RANK_RUS_DLG_TEXT2_DI, RANK_ENG_DLG_TEXT2_DI
};
char * typeDITextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT3_DI, RANK_RUS_DLG_TEXT3_DI, RANK_ENG_DLG_TEXT3_DI
};
char * signalTypesDI0[LANG_LIST_SIZE] = {
  RANK_UKR_SIGNAL_TYPE_DI0, RANK_RUS_SIGNAL_TYPE_DI0, RANK_ENG_SIGNAL_TYPE_DI0
};
char * signalTypesDI1[LANG_LIST_SIZE] = {
  RANK_UKR_SIGNAL_TYPE_DI1, RANK_RUS_SIGNAL_TYPE_DI1, RANK_ENG_SIGNAL_TYPE_DI1
};
char * typesDI0[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DI0, RANK_RUS_TYPE_DI0, RANK_ENG_TYPE_DI0
};
char * typesDI1[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DI1, RANK_RUS_TYPE_DI1, RANK_ENG_TYPE_DI1
};

char * typeDOTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT_DO, RANK_RUS_DLG_TEXT_DO, RANK_ENG_DLG_TEXT_DO
};
char * typesDO0[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DO0, RANK_RUS_TYPE_DO0, RANK_ENG_TYPE_DO0
};
char * typesDO1[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DO1, RANK_RUS_TYPE_DO1, RANK_ENG_TYPE_DO1
};

char * typeLEDTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT_LED, RANK_RUS_DLG_TEXT_LED, RANK_ENG_DLG_TEXT_LED
};
char * typesLED0[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_LED0, RANK_RUS_TYPE_LED0, RANK_ENG_TYPE_LED0
};
char * typesLED1[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_LED1, RANK_RUS_TYPE_LED1, RANK_ENG_TYPE_LED1
};

char * tmrDelayDFTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT1_DF, RANK_RUS_DLG_TEXT1_DF, RANK_ENG_DLG_TEXT1_DF
};
char * tmrWorkDFTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT2_DF, RANK_RUS_DLG_TEXT2_DF, RANK_ENG_DLG_TEXT2_DF
};
char * typeDFTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT3_DF, RANK_RUS_DLG_TEXT3_DF, RANK_ENG_DLG_TEXT3_DF
};
char * typesDF0[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DF0, RANK_RUS_TYPE_DF0, RANK_ENG_TYPE_DF0
};
char * typesDF1[LANG_LIST_SIZE] = {
  RANK_UKR_TYPE_DF1, RANK_RUS_TYPE_DF1, RANK_ENG_TYPE_DF1
};

char * timePreFaultArrTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT1_AN_REC, RANK_RUS_DLG_TEXT1_AN_REC, RANK_ENG_DLG_TEXT1_AN_REC
};
char * timePostFaultArrTextLabels[LANG_LIST_SIZE] = {
  RANK_UKR_DLG_TEXT2_AN_REC, RANK_RUS_DLG_TEXT2_AN_REC, RANK_ENG_DLG_TEXT2_AN_REC
};

LANG_ITEM _rankDlgDIItem[1] = {
  { {RANK_UKR_DLG_DI, RANK_RUS_DLG_DI, RANK_ENG_DLG_DI} , {RANK_UKR_DLG_DI_EXPL, RANK_RUS_DLG_DI_EXPL, RANK_ENG_DLG_DI_EXPL} }
};
LANG_ITEM _rankDlgDOItem[1] = {
  { {RANK_UKR_DLG_DO, RANK_RUS_DLG_DO, RANK_ENG_DLG_DO} , {RANK_UKR_DLG_DI_EXPL, RANK_RUS_DLG_DI_EXPL, RANK_ENG_DLG_DI_EXPL} }
};
LANG_ITEM _rankDlgLEDItem[1] = {
  { {RANK_UKR_DLG_LED, RANK_RUS_DLG_LED, RANK_ENG_DLG_LED} , {RANK_UKR_DLG_DI_EXPL, RANK_RUS_DLG_DI_EXPL, RANK_ENG_DLG_DI_EXPL} }
};
LANG_ITEM _rankDlgDFItem[1] = {
  { {RANK_UKR_DLG_DF, RANK_RUS_DLG_DF, RANK_ENG_DLG_DF} , {RANK_UKR_DLG_DI_EXPL, RANK_RUS_DLG_DI_EXPL, RANK_ENG_DLG_DI_EXPL} }
};
LANG_ITEM _rankDlgAnRecItem[1] = {
  { {RANK_UKR_DLG_AN_REC, RANK_RUS_DLG_AN_REC, RANK_ENG_DLG_AN_REC} , {RANK_UKR_DLG_DI_EXPL, RANK_RUS_DLG_DI_EXPL, RANK_ENG_DLG_DI_EXPL} }
};
///Dialog rank variables////////////////////////

/**Ranking*******************************************/

/**Common********************************************/
char * commonText[LANG_LIST_SIZE] = {
  COMMON_UKR_TEXT, COMMON_RUS_TEXT, COMMON_ENG_TEXT
};

char * stageText[LANG_LIST_SIZE] = {
  COMMON_STAGE_TEXT_UKR, COMMON_STAGE_TEXT_RUS, COMMON_STAGE_TEXT_ENG
};

char * enterButtonExpl[LANG_LIST_SIZE] = {
  ENTER_BUTTON_EXPL_UKR, ENTER_BUTTON_EXPL_RUS, ENTER_BUTTON_EXPL_ENG
};
char * escButtonExpl[LANG_LIST_SIZE] = {
  ESC_BUTTON_EXPL_UKR, ESC_BUTTON_EXPL_RUS, ESC_BUTTON_EXPL_ENG
};

char * msUnits[LANG_LIST_SIZE] = {
  RANK_UKR_MS_UNIT, RANK_RUS_MS_UNIT, RANK_ENG_MS_UNIT
};

char * secUnits[LANG_LIST_SIZE] = {
  RANK_UKR_SEC_UNIT, RANK_RUS_SEC_UNIT, RANK_ENG_SEC_UNIT
};
/**Common********************************************/

#endif

