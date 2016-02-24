
#include "ici_ef.h"

#include "../inc/const_BS_BL.h"
#include "../inc/type_definition_BS.h"

extern _Bool change_language;

extern _Bool start_gui_exec;
extern _Bool start_time_gui_exec;

extern _Bool gui_update;

extern WM_HWIN desctopWin;

extern int win_id_list[MAX_LEVEL_MENU];

extern GUI_CONST_STORAGE GUI_BITMAP bmClock;
extern GUI_CONST_STORAGE GUI_BITMAP bmMeasurement;
extern GUI_CONST_STORAGE GUI_BITMAP bmSettings;
extern GUI_CONST_STORAGE GUI_BITMAP bmLanguage;
extern GUI_CONST_STORAGE GUI_BITMAP bmResCounter;
extern GUI_CONST_STORAGE GUI_BITMAP bmInputOutputs;
extern GUI_CONST_STORAGE GUI_BITMAP bmRegistrators;
extern GUI_CONST_STORAGE GUI_BITMAP bmDiagnostic;
extern GUI_CONST_STORAGE GUI_BITMAP bmConfiguration;
extern GUI_CONST_STORAGE GUI_BITMAP bmRanking;
extern BITMAP_ITEM _aBitmapItem[ICONVIEW_SIZE];

extern WM_HWIN _hMenu;
extern MENU_Handle hMenuFunc, hMenuHelp;

extern WM_HWIN iconWin;
extern int sel_icon;

extern EDIT_Handle hEdit;

extern WM_HWIN langWin;
extern WM_HWIN langRadioButton;
extern WM_HWIN langButtonOK;
extern WM_HWIN langButtonCancel;
extern int lang_id_list[MAX_LEVEL_LANG_DLG];

extern WM_HWIN windingWin;
extern WM_HWIN windingRadioButton;
extern WM_HWIN windingButtonOK;
extern WM_HWIN windingButtonCancel;
extern int winding_id_list[MAX_LEVEL_WINDING_DLG];

/**Measurements**************************************/
extern __TOTAL_MEASUREMENT gui_total_measurement;

extern WM_HWIN measMultiPageWin;
extern WM_HWIN measHMultiPage;
extern char meas_index_position;
extern SCROLLBAR_Handle measPgScroll;
extern WM_HWIN measPgs[MAX_LEVEL_MEAS_PG];

extern char resistancesPosition;
extern WM_HWIN resistancesMulPg;
extern WM_HWIN commonResistancesPg;

extern TotMeasStateDsc pTotMeasStateDsc;

extern LANG_ITEM _measItem[MAX_LEVEL_MEAS_PG];

extern char * meas_item_units[MAX_LEVEL_MEAS_PG][LANG_LIST_SIZE][MAX_NUMBER_MEAS];

extern char * measFrmText[LANG_LIST_SIZE];
extern int meas_id_list[MAX_LEVEL_MEAS_PG];
/**Measurements**************************************/

/**Configuration**************************************/
extern WM_HWIN configPageWin;

extern char config_index_position;

extern unsigned char selInfConf[(NUM_CONF_ITEMS >> 3) + 1];

extern char * confFrmText[LANG_LIST_SIZE];
extern char * confExplText[LANG_LIST_SIZE];
extern char * conf_checkbox_item[LANG_LIST_SIZE][NUM_CONF_ITEMS];
/**Configuration**************************************/

/**Ranking*******************************************/
extern CfgTblDsc eeprom_prt_tbl;

extern unsigned int rank_control_bits;

extern WM_HWIN rankMultiPageWin;
extern WM_HWIN rankHMultiPage;

extern WM_HWIN rankMulPgArr[MAX_LEVEL_RANK_PG];

extern SCROLLBAR_Handle rankDIPgScroll;
extern WM_HWIN rankDIPgs;
extern SCROLLBAR_Handle rankDOLedOFDTArDrPgScroll;
extern WM_HWIN rankDOLedOFDTArDrPgs;
extern SCROLLBAR_Handle rankFPgScroll;
extern WM_HWIN rankFPgs;

extern WM_HWIN rankPgs[MAX_LEVEL_RANK_PG];

extern char rank_index_position;
extern int di_index;
extern int previous_di_rank_pg_y_val;
extern int di_checkbox_sel_index[NUM_IN][2];
extern int do_index;
extern int previous_do_rank_pg_y_val;
extern int do_checkbox_sel_index[NUM_OUT][2];
extern int led_index;
extern int led_checkbox_sel_index[NUM_LED][2];
extern int df_plus_index;
extern int df_plus_checkbox_sel_index[NUM_DEF_FUN][2];
extern int df_minus_index;
extern int df_minus_checkbox_sel_index[NUM_DEF_FUN][2];
extern int df_blk_index;
extern int df_blk_checkbox_sel_index[NUM_DEF_FUN][2];

extern int df_index;

extern int f_index;
extern int previous_f_rank_pg_y_val;
extern int f_checkbox_sel_index[NUM_KEY][2];

extern int trg_set_pl_index;
extern int trg_set_pl_checkbox_sel_index[NUM_TRG][2];
extern int trg_set_mn_index;
extern int trg_set_mn_checkbox_sel_index[NUM_TRG][2];
extern int trg_rst_pl_index;
extern int trg_rst_pl_checkbox_sel_index[NUM_TRG][2];
extern int trg_rst_mn_index;
extern int trg_rst_mn_checkbox_sel_index[NUM_TRG][2];

extern unsigned int an_dig_rec_index;
extern int an_dig_rec_checkbox_sel_index[2][2];

extern unsigned int checkbox_di_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_do_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_led_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_df_plus_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_df_minus_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_df_blk_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_f_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_trg_set_pl_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_trg_set_mn_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_trg_rst_pl_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_trg_rst_mn_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
extern unsigned int checkbox_an_dig_rec_sel_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];

extern char * rank_msg_title[LANG_LIST_SIZE];
extern char * rank_pgs_item[MAX_LEVEL_RANK_PG][LANG_LIST_SIZE][MAX_NUM_RANK_PGS];
extern char * rank_checkbox_item[LANG_LIST_SIZE][All_NUMB_RANK_ELEM];
extern LANG_ITEM _rankItem[MAX_LEVEL_RANK_PG];
extern char * editModeAdditionalText[LANG_LIST_SIZE];

extern char * rankFrmText[LANG_LIST_SIZE];

///Dialog rank variables////////////////////////
extern unsigned char diTypeSignal[(NUM_IN>>3)];
extern unsigned char diTypeInput[(NUM_IN>>3)];
extern unsigned short durationDI[NUM_IN];

extern unsigned char doTypeOutputs[(NUM_OUT>>3)];
extern unsigned char ledsType[(NUM_LED>>3)];

extern unsigned long tmrDelayDF[NUM_DEF_FUN];
extern unsigned long tmrWorkDF[NUM_DEF_FUN];
extern unsigned char typeDF[NUM_DEF_FUN];

extern unsigned long timePreFaultArrVal;
extern unsigned long timePostFaultArrVal;

extern WM_HWIN rankDlgDIPg;
extern WM_HWIN rankDlgDOPg;
extern WM_HWIN rankDlgLEDPg;
extern WM_HWIN rankDlgDFPg;
extern WM_HWIN rankDlgAnRecPg;

extern char * durationDITextLabels[LANG_LIST_SIZE];
extern char * signalTypeDITextLabels[LANG_LIST_SIZE];
extern char * typeDITextLabels[LANG_LIST_SIZE];

extern char * signalTypesDI0[LANG_LIST_SIZE];
extern char * signalTypesDI1[LANG_LIST_SIZE];
extern char * typesDI0[LANG_LIST_SIZE];
extern char * typesDI1[LANG_LIST_SIZE];

extern char * typeDOTextLabels[LANG_LIST_SIZE];
extern char * typesDO0[LANG_LIST_SIZE];
extern char * typesDO1[LANG_LIST_SIZE];

extern char * typeLEDTextLabels[LANG_LIST_SIZE];
extern char * typesLED0[LANG_LIST_SIZE];
extern char * typesLED1[LANG_LIST_SIZE];

extern char * tmrDelayDFTextLabels[LANG_LIST_SIZE];
extern char * tmrWorkDFTextLabels[LANG_LIST_SIZE];
extern char * typeDFTextLabels[LANG_LIST_SIZE];
extern char * typesDF0[LANG_LIST_SIZE];
extern char * typesDF1[LANG_LIST_SIZE];

extern char * timePreFaultArrTextLabels[LANG_LIST_SIZE];
extern char * timePostFaultArrTextLabels[LANG_LIST_SIZE];

extern LANG_ITEM _rankDlgDIItem[1];
extern LANG_ITEM _rankDlgDOItem[1];
extern LANG_ITEM _rankDlgLEDItem[1];
extern LANG_ITEM _rankDlgDFItem[1];
extern LANG_ITEM _rankDlgAnRecItem[1];
///Dialog rank variables////////////////////////

/**Ranking*******************************************/

/**Common********************************************/
extern char * commonText[LANG_LIST_SIZE];

extern char * stageText[LANG_LIST_SIZE];

extern char * enterButtonExpl[LANG_LIST_SIZE];
extern char * escButtonExpl[LANG_LIST_SIZE];

extern char * msUnits[LANG_LIST_SIZE];
extern char * secUnits[LANG_LIST_SIZE];
/**Common********************************************/
//extern WM_HWIN iconWin2;

