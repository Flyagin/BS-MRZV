#include "gui_header.h"
#include "header_mal.h"
#include "MULTIPAGE_Private.h"

/*********************************************************************
*
*       Macroses
*
*/

#ifndef __GUI_RANK_FUNC
  #define MASK_MULTI_PG_VAL                     0x7fffffff;
  #define _SEL_ID(_index,_id) {                                         \
            switch(current_ekran.index_position) {                      \
              case ID_RANK_DISCRETE_INPUT_PG:                           \
                {                                                       \
                  _id = di_id_list[_index];                             \
                  break;                                                \
                }                                                       \
              case ID_RANK_DISCRETE_OUTPUT_PG:                          \
              case ID_RANK_LED_PG:                                      \
              case ID_RANK_DF_PLUS_PG:                                  \
              case ID_RANK_DF_MINUS_PG:                                 \
              case ID_RANK_DF_BLK_PG:                                   \
              case ID_RANK_TRG_SET_PL_PG:                               \
              case ID_RANK_TRG_SET_MN_PG:                               \
              case ID_RANK_TRG_RST_PL_PG:                               \
              case ID_RANK_TRG_RST_MN_PG:                               \
              case ID_RANK_AN_DIG_REC_PG:                               \
                {                                                       \
                  _id = doLedDfDtArDr_id_list[_index];                  \
                  break;                                                \
                }                                                       \
              case ID_RANK_F_PG:                                        \
                {                                                       \
                  _id = f_id_list[_index];                              \
                  break;                                                \
                }                                                       \
              default:                                                  \
                {                                                       \
                  _id = di_id_list[_index];                             \
                  break;                                                \
                }                                                       \
            }                                                           \
          }
  #define _CHECK_HIGHEST_BIT(_v,_r) {                                   \
            _r = ((_v & 0x80000000) > 0);                               \
          }
  #define _SET_HIGHEST_BIT(_val,_bit) {                                 \
            if (_bit) {                                                 \
              _val |= (1 << 31);                                        \
            } else {                                                    \
              _val &= 0x7fffffff;                                       \
            }                                                           \
          }

  #pragma diag_suppress = Pe550
  #define _INIT_MULTI_PG_VALUES(                                                                        \
              _m_pg_val,                                                                                \
              _checkbox_val,                                                                            \
              _rank_pg_y_val,                                                                           \
              _f_pg,                                                                                    \
              _scr_pg,                                                                                  \
              _num_pgs,                                                                                 \
              _num_checkbox,                                                                            \
              _prev_rank_pg_y_val,                                                                      \
              _sel_inf_arr_                                                                             \
              ) {                                                                                       \
            switch(current_ekran.index_position) {                                                      \
              case ID_RANK_DISCRETE_INPUT_PG:                                                           \
                {                                                                                       \
                  _f_pg = rankDIPgs;                                                                    \
                  _scr_pg = rankDIPgScroll;                                                             \
                  _num_pgs = NUM_IN;                                                                    \
                  _num_checkbox = NUM_DI_FUNCS;                                                         \
                  _m_pg_val = di_index;                                                                 \
                  _checkbox_val = di_checkbox_sel_index[ignore_hbit(di_index)][0];                      \
                  _rank_pg_y_val = di_checkbox_sel_index[ignore_hbit(di_index)][1];                     \
                  _prev_rank_pg_y_val = &previous_di_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_di_sel_inf_arr;                                             \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_DISCRETE_OUTPUT_PG:                                                          \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_OUT;                                                                   \
                  _num_checkbox = NUM_DO_FUNCS;                                                         \
                  _m_pg_val = do_index;                                                                 \
                  _checkbox_val = do_checkbox_sel_index[ignore_hbit(do_index)][0];                      \
                  _rank_pg_y_val = do_checkbox_sel_index[ignore_hbit(do_index)][1];                     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_do_sel_inf_arr;                                             \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_LED_PG:                                                                      \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_LED;                                                                   \
                  _num_checkbox = NUM_LED_FUNCS;                                                        \
                  _m_pg_val = led_index;                                                                \
                  _checkbox_val = led_checkbox_sel_index[ignore_hbit(led_index)][0];                    \
                  _rank_pg_y_val = led_checkbox_sel_index[ignore_hbit(led_index)][1];                   \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_led_sel_inf_arr;                                            \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_DF_PLUS_PG:                                                                  \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_DEF_FUN;                                                               \
                  _num_checkbox = NUM_DF_FUNCS;                                                         \
                  _m_pg_val = df_plus_index;                                                            \
                  _checkbox_val =                                                                       \
                    df_plus_checkbox_sel_index[ignore_hbit(df_plus_index)][0];                          \
                  _rank_pg_y_val =                                                                      \
                    df_plus_checkbox_sel_index[ignore_hbit(df_plus_index)][1];                          \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_df_plus_sel_inf_arr;                                        \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_DF_MINUS_PG:                                                                 \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_DEF_FUN;                                                               \
                  _num_checkbox = NUM_DF_FUNCS;                                                         \
                  _m_pg_val = df_minus_index;                                                           \
                  _checkbox_val =                                                                       \
                    df_minus_checkbox_sel_index[ignore_hbit(df_minus_index)][0];                        \
                  _rank_pg_y_val =                                                                      \
                    df_minus_checkbox_sel_index[ignore_hbit(df_minus_index)][1];                        \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_df_minus_sel_inf_arr;                                       \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_DF_BLK_PG:                                                                   \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_DEF_FUN;                                                               \
                  _num_checkbox = NUM_DF_FUNCS;                                                         \
                  _m_pg_val = df_blk_index;                                                             \
                  _checkbox_val =                                                                       \
                    df_blk_checkbox_sel_index[ignore_hbit(df_blk_index)][0];                            \
                  _rank_pg_y_val =                                                                      \
                    df_blk_checkbox_sel_index[ignore_hbit(df_blk_index)][1];                            \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_df_blk_sel_inf_arr;                                         \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_F_PG:                                                                        \
                {                                                                                       \
                  _f_pg = rankFPgs;                                                                     \
                  _scr_pg = rankFPgScroll;                                                              \
                  _num_pgs = NUM_KEY;                                                                   \
                  _num_checkbox = NUM_F_FUNCS;                                                          \
                  _m_pg_val = f_index;                                                                  \
                  _checkbox_val = f_checkbox_sel_index[ignore_hbit(f_index)][0];                        \
                  _rank_pg_y_val = f_checkbox_sel_index[ignore_hbit(f_index)][1];                       \
                  _prev_rank_pg_y_val = &previous_f_rank_pg_y_val;                                      \
                  _sel_inf_arr_ = &checkbox_f_sel_inf_arr;                                              \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_TRG_SET_PL_PG:                                                               \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_TRG;                                                                   \
                  _num_checkbox = NUM_TRG_FUNCS;                                                        \
                  _m_pg_val = trg_set_pl_index;                                                         \
                  _checkbox_val = trg_set_pl_checkbox_sel_index[ignore_hbit(trg_set_pl_index)][0];      \
                  _rank_pg_y_val = trg_set_pl_checkbox_sel_index[ignore_hbit(trg_set_pl_index)][1];     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_trg_set_pl_sel_inf_arr;                                     \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_TRG_SET_MN_PG:                                                               \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_TRG;                                                                   \
                  _num_checkbox = NUM_TRG_FUNCS;                                                        \
                  _m_pg_val = trg_set_mn_index;                                                         \
                  _checkbox_val = trg_set_mn_checkbox_sel_index[ignore_hbit(trg_set_mn_index)][0];      \
                  _rank_pg_y_val = trg_set_mn_checkbox_sel_index[ignore_hbit(trg_set_mn_index)][1];     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_trg_set_mn_sel_inf_arr;                                     \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_TRG_RST_PL_PG:                                                               \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_TRG;                                                                   \
                  _num_checkbox = NUM_TRG_FUNCS;                                                        \
                  _m_pg_val = trg_rst_pl_index;                                                         \
                  _checkbox_val = trg_rst_pl_checkbox_sel_index[ignore_hbit(trg_rst_pl_index)][0];      \
                  _rank_pg_y_val = trg_rst_pl_checkbox_sel_index[ignore_hbit(trg_rst_pl_index)][1];     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_trg_rst_pl_sel_inf_arr;                                     \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_TRG_RST_MN_PG:                                                               \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = NUM_TRG;                                                                   \
                  _num_checkbox = NUM_TRG_FUNCS;                                                        \
                  _m_pg_val = trg_rst_mn_index;                                                         \
                  _checkbox_val = trg_rst_mn_checkbox_sel_index[ignore_hbit(trg_rst_mn_index)][0];      \
                  _rank_pg_y_val = trg_rst_mn_checkbox_sel_index[ignore_hbit(trg_rst_mn_index)][1];     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_trg_rst_mn_sel_inf_arr;                                     \
                  break;                                                                                \
                }                                                                                       \
              case ID_RANK_AN_DIG_REC_PG:                                                               \
                {                                                                                       \
                  _f_pg = rankDOLedOFDTArDrPgs;                                                         \
                  _scr_pg = rankDOLedOFDTArDrPgScroll;                                                  \
                  _num_pgs = 2;                                                                         \
                  _num_checkbox = NUM_AN_DIG_REC_FUNCS;                                                 \
                  _m_pg_val = an_dig_rec_index;                                                         \
                  _checkbox_val = an_dig_rec_checkbox_sel_index[ignore_hbit(an_dig_rec_index)][0];      \
                  _rank_pg_y_val = an_dig_rec_checkbox_sel_index[ignore_hbit(an_dig_rec_index)][1];     \
                  _prev_rank_pg_y_val = &previous_do_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_an_dig_rec_sel_inf_arr;                                     \
                  break;                                                                                \
                }                                                                                       \
              default:                                                                                  \
                {                                                                                       \
                  _f_pg = rankDIPgs;                                                                    \
                  _scr_pg = rankDIPgScroll;                                                             \
                  _num_pgs = NUM_IN;                                                                    \
                  _num_checkbox = NUM_DI_FUNCS;                                                         \
                  _m_pg_val = di_index;                                                                 \
                  _checkbox_val = di_checkbox_sel_index[ignore_hbit(di_index)][0];                      \
                  _rank_pg_y_val = di_checkbox_sel_index[ignore_hbit(di_index)][1];                     \
                  _prev_rank_pg_y_val = &previous_di_rank_pg_y_val;                                     \
                  _sel_inf_arr_ = &checkbox_di_sel_inf_arr;                                             \
                  break;                                                                                \
                }                                                                                       \
            }                                                                                           \
          }
  #pragma diag_suppress = Pe550

  #define _SET_MULTI_PG_INDEX(_INDEX) {                                 \
            switch(current_ekran.index_position) {                      \
              case ID_RANK_DISCRETE_INPUT_PG:                           \
                {                                                       \
                  di_index = _INDEX;                                    \
                  break;                                                \
                }                                                       \
              case ID_RANK_DISCRETE_OUTPUT_PG:                          \
                {                                                       \
                  do_index = _INDEX;                                    \
                  break;                                                \
                }                                                       \
              case ID_RANK_LED_PG:                                      \
                {                                                       \
                  led_index = _INDEX;                                   \
                  break;                                                \
                }                                                       \
              case ID_RANK_DF_PLUS_PG:                                  \
                {                                                       \
                  df_plus_index = _INDEX;                               \
                  break;                                                \
                }                                                       \
              case ID_RANK_DF_MINUS_PG:                                 \
                {                                                       \
                  df_minus_index = _INDEX;                              \
                  break;                                                \
                }                                                       \
              case ID_RANK_DF_BLK_PG:                                   \
                {                                                       \
                  df_blk_index = _INDEX;                                \
                  break;                                                \
                }                                                       \
              case ID_RANK_F_PG:                                        \
                {                                                       \
                  f_index = _INDEX;                                     \
                  break;                                                \
                }                                                       \
              case ID_RANK_TRG_SET_PL_PG:                               \
                {                                                       \
                  trg_set_pl_index = _INDEX;                            \
                  break;                                                \
                }                                                       \
              case ID_RANK_TRG_SET_MN_PG:                               \
                {                                                       \
                  trg_set_mn_index = _INDEX;                            \
                  break;                                                \
                }                                                       \
              case ID_RANK_TRG_RST_PL_PG:                               \
                {                                                       \
                  trg_rst_pl_index = _INDEX;                            \
                  break;                                                \
                }                                                       \
              case ID_RANK_TRG_RST_MN_PG:                               \
                {                                                       \
                  trg_rst_mn_index = _INDEX;                            \
                  break;                                                \
                }                                                       \
              case ID_RANK_AN_DIG_REC_PG:                               \
                {                                                       \
                  an_dig_rec_index = _INDEX;                            \
                  break;                                                \
                }                                                       \
              default:                                                  \
                {                                                       \
                  di_index = _INDEX;                                    \
                  break;                                                \
                }                                                       \
            }                                                           \
          }
  
  #define _SET_CHECKBOX_VAL(                                                    \
              _mulpg_val,                                                       \
              _chkbx_val,                                                       \
              _rankpg_y_val                                                     \
              ) {                                                               \
            switch(current_ekran.index_position) {                              \
              case ID_RANK_DISCRETE_INPUT_PG:                                   \
                {                                                               \
                  di_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;            \
                  di_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val;         \
                  break;                                                        \
                }                                                               \
              case ID_RANK_DISCRETE_OUTPUT_PG:                                  \
                {                                                               \
                  do_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;            \
                  do_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val;         \
                  break;                                                        \
                }                                                               \
              case ID_RANK_LED_PG:                                              \
                {                                                               \
                  led_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;           \
                  led_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val;        \
                  break;                                                        \
                }                                                               \
              case ID_RANK_DF_PLUS_PG:                                          \
                {                                                               \
                  df_plus_checkbox_sel_index[_mulpg_val][0] =                   \
                    _chkbx_val;                                                 \
                  df_plus_checkbox_sel_index[_mulpg_val][1] =                   \
                    _rankpg_y_val;                                              \
                  break;                                                        \
                }                                                               \
              case ID_RANK_DF_MINUS_PG:                                         \
                {                                                               \
                  df_minus_checkbox_sel_index[_mulpg_val][0] =                  \
                    _chkbx_val;                                                 \
                  df_minus_checkbox_sel_index[_mulpg_val][1] =                  \
                    _rankpg_y_val;                                              \
                  break;                                                        \
                }                                                               \
              case ID_RANK_DF_BLK_PG:                                           \
                {                                                               \
                  df_blk_checkbox_sel_index[_mulpg_val][0] =                    \
                    _chkbx_val;                                                 \
                  df_blk_checkbox_sel_index[_mulpg_val][1] =                    \
                    _rankpg_y_val;                                              \
                  break;                                                        \
                }                                                               \
              case ID_RANK_F_PG:                                                \
                {                                                               \
                  f_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;             \
                  f_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val;          \
                  break;                                                        \
                }                                                               \
              case ID_RANK_TRG_SET_PL_PG:                                       \
                {                                                               \
                  trg_set_pl_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;    \
                  trg_set_pl_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val; \
                  break;                                                        \
                }                                                               \
              case ID_RANK_TRG_SET_MN_PG:                                       \
                {                                                               \
                  trg_set_mn_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;    \
                  trg_set_mn_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val; \
                  break;                                                        \
                }                                                               \
              case ID_RANK_TRG_RST_PL_PG:                                       \
                {                                                               \
                  trg_rst_pl_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;    \
                  trg_rst_pl_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val; \
                  break;                                                        \
                }                                                               \
              case ID_RANK_TRG_RST_MN_PG:                                       \
                {                                                               \
                  trg_rst_mn_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;    \
                  trg_rst_mn_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val; \
                  break;                                                        \
                }                                                               \
              case ID_RANK_AN_DIG_REC_PG:                                       \
                {                                                               \
                  an_dig_rec_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;    \
                  an_dig_rec_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val; \
                  break;                                                        \
                }                                                               \
              default:                                                          \
                {                                                               \
                  di_checkbox_sel_index[_mulpg_val][0] = _chkbx_val;            \
                  di_checkbox_sel_index[_mulpg_val][1] = _rankpg_y_val;         \
                  break;                                                        \
                }                                                               \
            }                                                                   \
          }

  #define _UPDATE_CHECKBOX(                                             \
            _index_,                                                    \
            _smul_pg_val_,                                              \
            _checkbox_val_,                                             \
            _id_,                                                       \
            _disabling_inf_arr_,                                        \
            _sel_inf_arr_,                                              \
            _checkbox_pg_,                                              \
            _COLOR_                                                     \
            ) {                                                         \
          if (_index_ == _checkbox_val_) {                              \
            CHECKBOX_SetBkColor(_checkbox_pg_, GUI_BLUE);               \
            CHECKBOX_SetFocusColor(_checkbox_pg_, GUI_BLUE);            \
            if (                                                        \
                  _CHECK_RANK_SET_BIT(                                  \
                    _disabling_inf_arr_,                                \
                    _smul_pg_val_,                                      \
                    _index_                                             \
                  ) != 0                                                \
               )                                                        \
            {                                                           \
              if (!WM_IsEnabled(_checkbox_pg_)) {                       \
                WM_EnableWindow(_checkbox_pg_);                         \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_YELLOW);       \
              } else {                                                  \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_YELLOW);       \
              }                                                         \
              if (                                                      \
                   _CHECK_RANK_SET_BIT_P(                               \
                     _sel_inf_arr_,                                     \
                     _smul_pg_val_,                                     \
                     _index_                                            \
                   ) != 0                                               \
                 )                                                      \
              {                                                         \
                if (CHECKBOX_GetState(_checkbox_pg_) == 0) {            \
                  CHECKBOX_SetState(_checkbox_pg_, 1);                  \
                }                                                       \
              } else {                                                  \
                if (CHECKBOX_GetState(_checkbox_pg_) != 0) {            \
                  CHECKBOX_SetState(_checkbox_pg_, 0);                  \
                }                                                       \
              }                                                         \
            } else {                                                    \
              if (WM_IsEnabled(_checkbox_pg_)) {                        \
                WM_DisableWindow(_checkbox_pg_);                        \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_GRAY);         \
              } else {                                                  \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_GRAY);         \
              }                                                         \
              if (CHECKBOX_GetState(_checkbox_pg_) != 0) {              \
                CHECKBOX_SetState(_checkbox_pg_, 0);                    \
              }                                                         \
            }                                                           \
          } else {                                                      \
            CHECKBOX_SetBkColor(_checkbox_pg_, _COLOR_);                \
            CHECKBOX_SetFocusColor(_checkbox_pg_, _COLOR_);             \
            if (                                                        \
                  _CHECK_RANK_SET_BIT(                                  \
                    _disabling_inf_arr_,                                \
                    _smul_pg_val_,                                      \
                    _index_                                             \
                  ) != 0                                                \
               )                                                        \
            {                                                           \
              if (!WM_IsEnabled(_checkbox_pg_)) {                       \
                WM_EnableWindow(_checkbox_pg_);                         \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_BLACK);        \
              } else {                                                  \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_BLACK);        \
              }                                                         \
              if (                                                      \
                   _CHECK_RANK_SET_BIT_P(                               \
                     _sel_inf_arr_,                                     \
                     _smul_pg_val_,                                     \
                     _index_                                            \
                   ) != 0                                               \
                 )                                                      \
              {                                                         \
                if (CHECKBOX_GetState(_checkbox_pg_) == 0) {            \
                  CHECKBOX_SetState(_checkbox_pg_, 1);                  \
                }                                                       \
              } else {                                                  \
                if (CHECKBOX_GetState(_checkbox_pg_) != 0) {            \
                  CHECKBOX_SetState(_checkbox_pg_, 0);                  \
                }                                                       \
              }                                                         \
            } else {                                                    \
              if (WM_IsEnabled(_checkbox_pg_)) {                        \
                WM_DisableWindow(_checkbox_pg_);                        \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_GRAY);         \
              } else {                                                  \
                CHECKBOX_SetTextColor(_checkbox_pg_, GUI_GRAY);         \
              }                                                         \
              if (CHECKBOX_GetState(_checkbox_pg_) != 0) {              \
                CHECKBOX_SetState(_checkbox_pg_, 0);                    \
              }                                                         \
            }                                                           \
          }                                                             \
        }
#endif

/*********************************************************************
*
*       Ranking pages resources
*
*/
static unsigned int di_id_list[NUM_DI_FUNCS] = {
  GUI_ID_BIT_HVSW_ON,                   GUI_ID_BIT_HVSW_OFF,                  GUI_ID_BIT_CTRL_VKL,
  GUI_ID_BIT_CTRL_OTKL,                 GUI_ID_BIT_RESET_SIGOUT,              GUI_ID_BIT_RESET_LED,
  GUI_ID_BIT_BLOCK_SWITCHOVER,          GUI_ID_BIT_SWITCH_STATE,              GUI_ID_BIT_PERMIT_BLK_SW_MCP,
  GUI_ID_BIT_EDF01_DI_IEPRF_ONB,        GUI_ID_BIT_EDF02_DI_IEPRF_ONB,        GUI_ID_BIT_EDF03_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF04_DI_IEPRF_ONB,        GUI_ID_BIT_EDF05_DI_IEPRF_ONB,        GUI_ID_BIT_EDF06_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF07_DI_IEPRF_ONB,        GUI_ID_BIT_EDF08_DI_IEPRF_ONB,        GUI_ID_BIT_EDF09_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF10_DI_IEPRF_ONB,        GUI_ID_BIT_EDF11_DI_IEPRF_ONB,        GUI_ID_BIT_EDF12_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF13_DI_IEPRF_ONB,        GUI_ID_BIT_EDF14_DI_IEPRF_ONB,        GUI_ID_BIT_EDF15_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF16_DI_IEPRF_ONB,        GUI_ID_ADDR_SET_OT1,                  GUI_ID_ADDR_RESET_OT1,
  GUI_ID_ADDR_SET_OT2,                  GUI_ID_ADDR_RESET_OT2,                GUI_ID_ADDR_SET_OT3,
  GUI_ID_ADDR_RESET_OT3,                GUI_ID_ADDR_SET_OT4,                  GUI_ID_ADDR_RESET_OT4,
  GUI_ID_ADDR_SET_OT5,                  GUI_ID_ADDR_RESET_OT5,                GUI_ID_ADDR_SET_OT6,
  GUI_ID_ADDR_RESET_OT6,                GUI_ID_ADDR_SET_OT7,                  GUI_ID_ADDR_RESET_OT7,
  GUI_ID_ADDR_SET_OT8,                  GUI_ID_ADDR_RESET_OT8,                GUI_ID_BIT_BLOCK_DSTP1,
  GUI_ID_BIT_BLOCK_DSTP2,               GUI_ID_BIT_ACCLT_DSTP2,               GUI_ID_BIT_BLOCK_ACCLT_DSTP2,
  GUI_ID_BIT_BLOCK_DSTP3,               GUI_ID_BIT_ACCLT_DSTP3,               GUI_ID_BIT_BLOCK_ACCLT_DSTP3,
  GUI_ID_BIT_BLOCK_DSTP4,               GUI_ID_BIT_ACCLT_DSTP4,               GUI_ID_BIT_BLOCK_ACCLT_DSTP4,
  GUI_ID_BIT_BLOCK_DSTP5,               GUI_ID_BIT_ACCLT_DSTP5,               GUI_ID_BIT_BLOCK_ACCLT_DSTP5,
  GUI_ID_BIT_SEC_GR_UST_DSTP,           GUI_ID_BIT_BLOCK_MCP1,                GUI_ID_BIT_BLOCK_MCP2,
  GUI_ID_BIT_BLOCK_MCP3,                GUI_ID_BIT_BLOCK_MCP4,                GUI_ID_BIT_BLOCK_MCP5,
  GUI_ID_ACCLT_MCP2_DI_IEPRF_ONB,       GUI_ID_BLOCK_ACCLT_MCP2_DI_IEPRF_ONB, GUI_ID_ACCLT_MCP3_DI_IEPRF_ONB,
  GUI_ID_BLOCK_ACCLT_MCP3_DI_IEPRF_ONB, GUI_ID_ACCLT_MCP4_DI_IEPRF_ONB,       GUI_ID_BLOCK_ACCLT_MCP4_DI_IEPRF_ONB,
  GUI_ID_ACCLT_MCP5_DI_IEPRF_ONB,       GUI_ID_BLOCK_ACCLT_MCP5_DI_IEPRF_ONB,
  GUI_ID_BIT_SEC_GR_UST_MCP,            GUI_ID_BIT_START_AFU,                 GUI_ID_BIT_BLOCK_AFU,
  GUI_ID_BIT_BLOCK_UMIN1,               GUI_ID_BIT_START_UMIN1,               GUI_ID_BIT_BLOCK_UMIN2,
  GUI_ID_BIT_START_UMIN2,               GUI_ID_BIT_BLOCK_TZNP1,               GUI_ID_BIT_ACCLT_TZNP1,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP1,         GUI_ID_BIT_BLOCK_TZNP2,               GUI_ID_BIT_ACCLT_TZNP2,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP2,         GUI_ID_BIT_BLOCK_TZNP3,               GUI_ID_BIT_ACCLT_TZNP3,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP3,         GUI_ID_BIT_BLOCK_TZNP4,               GUI_ID_BIT_ACCLT_TZNP4,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP4,         GUI_ID_BIT_BLOCK_TZNP5,               GUI_ID_BIT_ACCLT_TZNP5,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP5,         GUI_ID_BIT_BLOCK_ZOP1,                GUI_ID_BIT_BLOCK_ZOP2,
  GUI_ID_BIT_SEC_GR_UST_ZOP,            GUI_ID_BIT_START_UROV,                GUI_ID_BIT_BLOCK_UMAX1,
  GUI_ID_BIT_BLOCK_UMAX2
};

unsigned int doLedDfDtArDr_id_list[NUM_DO_FUNCS] = {
  GUI_ID_BIT_HVSW_ON,                              GUI_ID_BIT_HVSW_OFF,                             GUI_ID_BIT_CTRL_VKL,                             GUI_ID_BIT_CTRL_OTKL,
  GUI_ID_BIT_RESET_SIGOUT,                         GUI_ID_BIT_RESET_LED,                            GUI_ID_BIT_BLOCK_SWITCHOVER,                     GUI_ID_BIT_SWITCH_STATE,
  GUI_ID_BIT_PERMIT_BLK_SW_MCP,                    GUI_ID_BIT_DRIVER_SW,                            GUI_ID_BIT_FLT_U_DSTP,                           GUI_ID_BIT_OVER_I_NOM_OFF_HSW,
  GUI_ID_BIT_LIMIT_OUT_HWS,                        GUI_ID_BIT_LIMIT_CRITICAL_HWS,                   GUI_ID_BIT_SW_OFF_CMDF_ONB,                      GUI_ID_BIT_SW_ON_CMDF_ONB,
  GUI_ID_BIT_EDF01_OEPRF_ONB,                      GUI_ID_BIT_EDF02_OEPRF_ONB,
  GUI_ID_BIT_EDF03_OEPRF_ONB,                      GUI_ID_BIT_EDF04_OEPRF_ONB,                      GUI_ID_BIT_EDF05_OEPRF_ONB,                      GUI_ID_BIT_EDF06_OEPRF_ONB,
  GUI_ID_BIT_EDF07_OEPRF_ONB,                      GUI_ID_BIT_EDF08_OEPRF_ONB,                      GUI_ID_BIT_EDF09_OEPRF_ONB,                      GUI_ID_BIT_EDF10_OEPRF_ONB,
  GUI_ID_BIT_EDF11_OEPRF_ONB,                      GUI_ID_BIT_EDF12_OEPRF_ONB,                      GUI_ID_BIT_EDF13_OEPRF_ONB,                      GUI_ID_BIT_EDF14_OEPRF_ONB,
  GUI_ID_BIT_EDF15_OEPRF_ONB,                      GUI_ID_BIT_EDF16_OEPRF_ONB,                      GUI_ID_BIT_OUT_OT1,                              GUI_ID_BIT_OUT_OT2,
  GUI_ID_BIT_OUT_OT3,                              GUI_ID_BIT_OUT_OT4,                              GUI_ID_BIT_OUT_OT5,                              GUI_ID_BIT_OUT_OT6,
  GUI_ID_BIT_OUT_OT7,                              GUI_ID_BIT_OUT_OT8,                              GUI_ID_BIT_BLOCK_DSTP1,
  
  GUI_ID_BIT_STPDEV_DSTP1_MF,
  GUI_ID_BIT_DSTP1_MF,
  GUI_ID_BIT_STPDEV_MCP_DSTP1,
  GUI_ID_BIT_MCP_DSTP1,
  GUI_ID_BIT_STPDEV_DSTP1_OF,
  GUI_ID_BIT_DSTP1_OF,
  
  GUI_ID_BIT_BLOCK_DSTP2,
  
  GUI_ID_BIT_DSTP2_MF,
  GUI_ID_BIT_STPDEV_DSTP2_MF,
  GUI_ID_BIT_MCP_DSTP2,
  GUI_ID_BIT_STPDEV_MCP_DSTP2,
  GUI_ID_BIT_DSTP2_OF,
  GUI_ID_BIT_STPDEV_DSTP2_OF,
  
  GUI_ID_BIT_ACCLT_DSTP2,                          GUI_ID_ACCLT_DSTP2_EPI_OEPRF_ONB,
  GUI_ID_BIT_BLOCK_ACCLT_DSTP2,                    GUI_ID_BIT_BLOCK_DSTP3,
  
  GUI_ID_BIT_DSTP3_MF,
  GUI_ID_BIT_STPDEV_DSTP3_MF,
  GUI_ID_BIT_MCP_DSTP3,
  GUI_ID_BIT_STPDEV_MCP_DSTP3,
  GUI_ID_BIT_DSTP3_OF,
  GUI_ID_BIT_STPDEV_DSTP3_OF,
  
  GUI_ID_BIT_ACCLT_DSTP3,                          GUI_ID_ACCLT_DSTP3_EPI_OEPRF_ONB,
  GUI_ID_BIT_BLOCK_ACCLT_DSTP3,                    GUI_ID_BIT_BLOCK_DSTP4,
  
  GUI_ID_BIT_DSTP4_MF,
  GUI_ID_BIT_STPDEV_DSTP4_MF,
  GUI_ID_BIT_MCP_DSTP4,
  GUI_ID_BIT_STPDEV_MCP_DSTP4,
  GUI_ID_BIT_DSTP4_OF,
  GUI_ID_BIT_STPDEV_DSTP4_OF,
  
  GUI_ID_BIT_ACCLT_DSTP4,                          GUI_ID_ACCLT_DSTP4_EPI_OEPRF_ONB,
  GUI_ID_BIT_BLOCK_ACCLT_DSTP4,                    GUI_ID_BIT_BLOCK_DSTP5,
  
  GUI_ID_BIT_DSTP5_MF,
  GUI_ID_BIT_STPDEV_DSTP5_MF,
  GUI_ID_BIT_MCP_DSTP5,
  GUI_ID_BIT_STPDEV_MCP_DSTP5,
  GUI_ID_BIT_DSTP5_OF,
  GUI_ID_BIT_STPDEV_DSTP5_OF,
  
  GUI_ID_BIT_ACCLT_DSTP5,                          GUI_ID_ACCLT_DSTP5_EPI_OEPRF_ONB,
  GUI_ID_BIT_BLOCK_ACCLT_DSTP5,                    GUI_ID_BIT_SEC_GR_UST_DSTP,
  GUI_ID_BIT_BLOCK_MCP1,                           GUI_ID_BIT_BLOCK_MCP2,                           GUI_ID_BIT_BLOCK_MCP3,                           GUI_ID_BIT_BLOCK_MCP4,
  GUI_ID_BIT_BLOCK_MCP5,
  GUI_ID_ACCLT_MCP2_EPI_OEPRF_ONB,                 GUI_ID_ACCLT_MCP2_DI_IEPRF_ONB,                  GUI_ID_BLOCK_ACCLT_MCP2_DI_IEPRF_ONB,            GUI_ID_ACCLT_MCP3_EPI_OEPRF_ONB,
  GUI_ID_ACCLT_MCP3_DI_IEPRF_ONB,                  GUI_ID_BLOCK_ACCLT_MCP3_DI_IEPRF_ONB,            GUI_ID_ACCLT_MCP4_EPI_OEPRF_ONB,                 GUI_ID_ACCLT_MCP4_DI_IEPRF_ONB,
  GUI_ID_BLOCK_ACCLT_MCP4_DI_IEPRF_ONB,            GUI_ID_ACCLT_MCP5_EPI_OEPRF_ONB,                 GUI_ID_ACCLT_MCP5_DI_IEPRF_ONB,                  GUI_ID_BLOCK_ACCLT_MCP5_DI_IEPRF_ONB,
  GUI_ID_BIT_SEC_GR_UST_MCP,                       GUI_ID_BIT_STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB, GUI_ID_BIT_STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_MCP1_BORING_OEPRF_ONB,         GUI_ID_BIT_STPDEV_MCP1_STAIGHT_OEPRF_ONB,        GUI_ID_BIT_STPDEV_MCP1_BACK_OEPRF_ONB,           GUI_ID_BIT_STPDEV_MCP1_VLT_OEPRF_ONB,
  GUI_ID_BIT_MCP1_OEPRF_ONB,                       GUI_ID_BIT_STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB, GUI_ID_BIT_STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB,    GUI_ID_BIT_STPDEV_MCP2_BORING_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_MCP2_STAIGHT_OEPRF_ONB,        GUI_ID_BIT_STPDEV_MCP2_BACK_OEPRF_ONB,           GUI_ID_BIT_STPDEV_MCP2_VLT_OEPRF_ONB,            GUI_ID_BIT_MCP2_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB, GUI_ID_BIT_STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB,    GUI_ID_BIT_STPDEV_MCP3_BORING_OEPRF_ONB,         GUI_ID_BIT_STPDEV_MCP3_STAIGHT_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_MCP3_BACK_OEPRF_ONB,           GUI_ID_BIT_STPDEV_MCP3_VLT_OEPRF_ONB,            GUI_ID_BIT_MCP3_OEPRF_ONB,                       GUI_ID_BIT_STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB,    GUI_ID_BIT_STPDEV_MCP4_BORING_OEPRF_ONB,         GUI_ID_BIT_STPDEV_MCP4_STAIGHT_OEPRF_ONB,        GUI_ID_BIT_STPDEV_MCP4_BACK_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_MCP4_VLT_OEPRF_ONB,            GUI_ID_BIT_MCP4_OEPRF_ONB,                       GUI_ID_BIT_STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB, GUI_ID_BIT_STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_MCP5_BORING_OEPRF_ONB,         GUI_ID_BIT_STPDEV_MCP5_STAIGHT_OEPRF_ONB,        GUI_ID_BIT_STPDEV_MCP5_BACK_OEPRF_ONB,           GUI_ID_BIT_STPDEV_MCP5_VLT_OEPRF_ONB,
  GUI_ID_BIT_MCP5_OEPRF_ONB,                       GUI_ID_BIT_START_AFU,                            GUI_ID_BIT_BLOCK_AFU,                            GUI_ID_BIT_ARCL1,
  GUI_ID_BIT_ARCL2,                                GUI_ID_BIT_BLOCK_UMIN1,                          GUI_ID_BIT_START_UMIN1,                          GUI_ID_BIT_BLOCK_UMIN2,
  GUI_ID_BIT_START_UMIN2,                          GUI_ID_BIT_STPDEV_UMIN1_OEPRF_ONB,               GUI_ID_BIT_UMIN1_OEPRF_ONB,                      GUI_ID_BIT_STPDEV_UMIN2_OEPRF_ONB,
  GUI_ID_BIT_UMIN2_OEPRF_ONB,                      GUI_ID_BIT_BLOCK_TZNP1,                          GUI_ID_BIT_ACCLT_TZNP1,                          GUI_ID_BIT_BLOCK_ACCLT_TZNP1,
  GUI_ID_BIT_BLOCK_TZNP2,                          GUI_ID_BIT_ACCLT_TZNP2,                          GUI_ID_BIT_BLOCK_ACCLT_TZNP2,                    GUI_ID_BIT_BLOCK_TZNP3,
  GUI_ID_BIT_ACCLT_TZNP3,                          GUI_ID_BIT_BLOCK_ACCLT_TZNP3,                    GUI_ID_BIT_BLOCK_TZNP4,                          GUI_ID_BIT_ACCLT_TZNP4,
  GUI_ID_BIT_BLOCK_ACCLT_TZNP4,                    GUI_ID_BIT_BLOCK_TZNP5,                          GUI_ID_BIT_ACCLT_TZNP5,                          GUI_ID_BIT_BLOCK_ACCLT_TZNP5,
  GUI_ID_ACCLT_TZNP1_EPI_OEPRF_ONB,                GUI_ID_ACCLT_TZNP2_EPI_OEPRF_ONB,                GUI_ID_ACCLT_TZNP3_EPI_OEPRF_ONB,                GUI_ID_ACCLT_TZNP4_EPI_OEPRF_ONB,
  GUI_ID_ACCLT_TZNP5_EPI_OEPRF_ONB,
  GUI_ID_BIT_STPDEV_SECTOR_TZNP1,                  GUI_ID_BIT_STPDEV_TZNP1,                         GUI_ID_BIT_TZNP1,                                GUI_ID_BIT_STPDEV_TZNP1_3U0,
  GUI_ID_BIT_TZNP1__3U0,                           GUI_ID_BIT_STPDEV_TZNP1_3I0,                     GUI_ID_BIT_TZNP1_3I0,                            GUI_ID_BIT_STPDEV_SECTOR_TZNP2,
  GUI_ID_BIT_STPDEV_TZNP2,                         GUI_ID_BIT_TZNP2,                                GUI_ID_BIT_STPDEV_TZNP2_3U0,                     GUI_ID_BIT_TZNP2_3U0,
  GUI_ID_BIT_STPDEV_TZNP2_3I0,                     GUI_ID_BIT_TZNP2_3I0,                            GUI_ID_BIT_STPDEV_SECTOR_TZNP3,                  GUI_ID_BIT_STPDEV_TZNP3,
  GUI_ID_BIT_TZNP3,                                GUI_ID_BIT_STPDEV_TZNP3_3U0,                     GUI_ID_BIT_TZNP3_3U0,                            GUI_ID_BIT_STPDEV_TZNP3_3I0,
  GUI_ID_BIT_TZNP3_3I0,                            GUI_ID_BIT_STPDEV_SECTOR_TZNP4,                  GUI_ID_BIT_STPDEV_TZNP4,                         GUI_ID_BIT_TZNP4,
  GUI_ID_BIT_STPDEV_TZNP4_3U0,                     GUI_ID_BIT_TZNP4_3U0,                            GUI_ID_BIT_STPDEV_TZNP4_3I0,                     GUI_ID_BIT_TZNP4_3I0,
  GUI_ID_BIT_STPDEV_SECTOR_TZNP5,                  GUI_ID_BIT_STPDEV_TZNP5,                         GUI_ID_BIT_TZNP5,                                GUI_ID_BIT_STPDEV_TZNP5_3U0,
  GUI_ID_BIT_TZNP5_3U0,                            GUI_ID_BIT_STPDEV_TZNP5_3I0,                     GUI_ID_BIT_TZNP5_3I0,                            GUI_ID_BIT_BLOCK_ZOP1,
  GUI_ID_BIT_BLOCK_ZOP2,                           GUI_ID_BIT_SEC_GR_UST_ZOP,                       GUI_ID_BIT_STPDEV_SECTOR_ZOP1_STAIGHT,           GUI_ID_BIT_STPDEV_SECTOR_ZOP1_BACK,
  GUI_ID_BIT_STPDEV_ZOP1_BORING,                   GUI_ID_BIT_STPDEV_ZOP1_STAIGHT,                  GUI_ID_BIT_STPDEV_ZOP1_BACK,                     GUI_ID_BIT_ZOP1,
  GUI_ID_BIT_STPDEV_SECTOR_ZOP2_STAIGHT,           GUI_ID_BIT_STPDEV_SECTOR_ZOP2_BACK,              GUI_ID_BIT_STPDEV_ZOP2_BORING,                   GUI_ID_BIT_STPDEV_ZOP2_STAIGHT,
  GUI_ID_BIT_STPDEV_ZOP2_BACK,                     GUI_ID_BIT_ZOP2,                                 GUI_ID_BIT_START_UROV,                           GUI_ID_BIT_UROV1,
  GUI_ID_BIT_UROV2,                                GUI_ID_BIT_BLOCK_UMAX1,                          GUI_ID_BIT_BLOCK_UMAX2,                          GUI_ID_BIT_STPDEV_UMAX1_OEPRF_ONB,
  GUI_ID_BIT_UMAX1_OEPRF_ONB,                      GUI_ID_BIT_STPDEV_UMAX2_OEPRF_ONB,               GUI_ID_BIT_UMAX2_OEPRF_ONB
};

static unsigned int f_id_list[NUM_F_FUNCS] = {
  GUI_ID_BIT_HVSW_ON,                              GUI_ID_BIT_HVSW_OFF,                             GUI_ID_BIT_RESET_SIGOUT,                         GUI_ID_BIT_RESET_LED,
  GUI_ID_BIT_EDF01_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF02_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF03_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF04_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF05_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF06_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF07_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF08_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF09_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF10_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF11_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF12_DI_IEPRF_ONB,
  GUI_ID_BIT_EDF13_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF14_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF15_DI_IEPRF_ONB,                   GUI_ID_BIT_EDF16_DI_IEPRF_ONB,
  GUI_ID_ADDR_SET_OT1,                             GUI_ID_ADDR_RESET_OT1,                           GUI_ID_ADDR_SET_OT2,                             GUI_ID_ADDR_RESET_OT2,
  GUI_ID_ADDR_SET_OT3,                             GUI_ID_ADDR_RESET_OT3,                           GUI_ID_ADDR_SET_OT4,                             GUI_ID_ADDR_RESET_OT4,
  GUI_ID_ADDR_SET_OT5,                             GUI_ID_ADDR_RESET_OT5,                           GUI_ID_ADDR_SET_OT6,                             GUI_ID_ADDR_RESET_OT6,
  GUI_ID_ADDR_SET_OT7,                             GUI_ID_ADDR_RESET_OT7,                           GUI_ID_ADDR_SET_OT8,                             GUI_ID_ADDR_RESET_OT8
};

static const GUI_WIDGET_CREATE_INFO _aRankDiPgCreate[] = {
  { WINDOW_CreateIndirect, "", ID_RANK_DI_PG, RANK_PG_X, RANK_PG_Y, RANK_PG_WIDTH, RANK_PG_HEIGHT, 0 },
  
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_ON,                   10, 5-2,    RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_OFF,                  10, 20-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_CTRL_VKL,                  10, 35-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_CTRL_OTKL,                 10, 50-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_SIGOUT,              10, 65-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_LED,                 10, 80-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_SWITCHOVER,          10, 95-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SWITCH_STATE,              10, 110-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_PERMIT_BLK_SW_MCP,         10, 125-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF01_DI_IEPRF_ONB,        10, 140-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF02_DI_IEPRF_ONB,        10, 155-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF03_DI_IEPRF_ONB,        10, 170-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF04_DI_IEPRF_ONB,        10, 185-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF05_DI_IEPRF_ONB,        10, 200-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF06_DI_IEPRF_ONB,        10, 215-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF07_DI_IEPRF_ONB,        10, 230-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF08_DI_IEPRF_ONB,        10, 245-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF09_DI_IEPRF_ONB,        10, 260-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF10_DI_IEPRF_ONB,        10, 275-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF11_DI_IEPRF_ONB,        10, 290-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF12_DI_IEPRF_ONB,        10, 305-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF13_DI_IEPRF_ONB,        10, 320-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF14_DI_IEPRF_ONB,        10, 335-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF15_DI_IEPRF_ONB,        10, 350-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF16_DI_IEPRF_ONB,        10, 365-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT1,                  10, 380-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT1,                10, 395-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT2,                  10, 410-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT2,                10, 425-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT3,                  10, 440-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT3,                10, 455-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT4,                  10, 470-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT4,                10, 485-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT5,                  10, 500-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT5,                10, 515-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT6,                  10, 530-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT6,                10, 545-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT7,                  10, 560-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT7,                10, 575-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT8,                  10, 590-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT8,                10, 605-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP1,               10, 620-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP2,               10, 635-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP2,               10, 650-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP2,         10, 665-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP3,               10, 680-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP3,               10, 695-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP3,         10, 710-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP4,               10, 725-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP4,               10, 740-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP4,         10, 755-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP5,               10, 770-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP5,               10, 785-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP5,         10, 800-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_DSTP,           10, 815-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP1,                10, 830-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP2,                10, 845-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP3,                10, 860-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP4,                10, 875-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP5,                10, 890-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP2_DI_IEPRF_ONB,       10, 905-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP2_DI_IEPRF_ONB, 10, 920-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP3_DI_IEPRF_ONB,       10, 935-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP3_DI_IEPRF_ONB, 10, 950-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP4_DI_IEPRF_ONB,       10, 965-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP4_DI_IEPRF_ONB, 10, 980-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP5_DI_IEPRF_ONB,       10, 995-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP5_DI_IEPRF_ONB, 10, 1010-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_MCP,            10, 1025-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_AFU,                 10, 1040-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_AFU,                 10, 1055-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMIN1,               10, 1070-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UMIN1,               10, 1085-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMIN2,               10, 1100-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UMIN2,               10, 1115-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP1,               10, 1130-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP1,               10, 1145-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP1,         10, 1160-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP2,               10, 1175-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP2,               10, 1190-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP2,         10, 1205-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP3,               10, 1220-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP3,               10, 1235-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP3,         10, 1250-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP4,               10, 1265-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP4,               10, 1280-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP4,         10, 1295-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP5,               10, 1310-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP5,               10, 1325-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP5,         10, 1340-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ZOP1,                10, 1355-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ZOP2,                10, 1370-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_ZOP,            10, 1385-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UROV,                10, 1400-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMAX1,               10, 1415-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMAX2,               10, 1430-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT }
};
  
static const GUI_WIDGET_CREATE_INFO _aRankDoLedDfPgCreate[] = {
  { WINDOW_CreateIndirect, "", ID_RANK_DO_PG, RANK_PG_X, RANK_PG_Y, RANK_PG_WIDTH, RANK_PG_HEIGHT, 0 },
  
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_ON,                              10, 5-2,    RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_OFF,                             10, 20-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_CTRL_VKL,                             10, 35-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_CTRL_OTKL,                            10, 50-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_SIGOUT,                         10, 65-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_LED,                            10, 80-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_SWITCHOVER,                     10, 95-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SWITCH_STATE,                         10, 110-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_PERMIT_BLK_SW_MCP,                    10, 125-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DRIVER_SW,                            10, 140-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_FLT_U_DSTP,                           10, 155-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OVER_I_NOM_OFF_HSW,                   10, 170-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_LIMIT_OUT_HWS,                        10, 185-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_LIMIT_CRITICAL_HWS,                   10, 200-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SW_OFF_CMDF_ONB,                      10, 215-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SW_ON_CMDF_ONB,                       10, 230-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF01_OEPRF_ONB,                      10, 245-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF02_OEPRF_ONB,                      10, 260-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF03_OEPRF_ONB,                      10, 275-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF04_OEPRF_ONB,                      10, 290-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF05_OEPRF_ONB,                      10, 305-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF06_OEPRF_ONB,                      10, 320-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF07_OEPRF_ONB,                      10, 335-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF08_OEPRF_ONB,                      10, 350-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF09_OEPRF_ONB,                      10, 365-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF10_OEPRF_ONB,                      10, 380-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF11_OEPRF_ONB,                      10, 395-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF12_OEPRF_ONB,                      10, 410-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF13_OEPRF_ONB,                      10, 425-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF14_OEPRF_ONB,                      10, 440-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF15_OEPRF_ONB,                      10, 455-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF16_OEPRF_ONB,                      10, 470-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT1,                              10, 485-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT2,                              10, 500-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT3,                              10, 515-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT4,                              10, 530-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT5,                              10, 545-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT6,                              10, 560-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT7,                              10, 575-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_OUT_OT8,                              10, 590-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP1,                          10, 605-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP1_MF,                      10, 620-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP1_MF,                             10, 635-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP_DSTP1,                     10, 650-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP_DSTP1,                            10, 665-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP1_OF,                      10, 680-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP1_OF,                             10, 695-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP2,                          10, 710-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP2_MF,                             10, 725-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP2_MF,                      10, 740-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP_DSTP2,                            10, 755-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP_DSTP2,                     10, 770-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP2_OF,                             10, 785-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP2_OF,                      10, 800-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP2,                          10, 815-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_DSTP2_EPI_OEPRF_ONB,                10, 830-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP2,                    10, 845-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP3,                          10, 860-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP3_MF,                             10, 875-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP3_MF,                      10, 890-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP_DSTP3,                            10, 905-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP_DSTP3,                     10, 920-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP3_OF,                             10, 935-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP3_OF,                      10, 950-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP3,                          10, 965-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_DSTP3_EPI_OEPRF_ONB,                10, 980-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP3,                    10, 995-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP4,                          10, 1010-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP4_MF,                             10, 1025-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP4_MF,                      10, 1040-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP_DSTP4,                            10, 1055-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP_DSTP4,                     10, 1070-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP4_OF,                             10, 1085-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP4_OF,                      10, 1100-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP4,                          10, 1115-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_DSTP4_EPI_OEPRF_ONB,                10, 1130-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP4,                    10, 1145-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_DSTP5,                          10, 1160-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP5_MF,                             10, 1175-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP5_MF,                      10, 1190-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP_DSTP5,                            10, 1205-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP_DSTP5,                     10, 1220-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_DSTP5_OF,                             10, 1235-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_DSTP5_OF,                      10, 1250-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_DSTP5,                          10, 1265-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_DSTP5_EPI_OEPRF_ONB,                10, 1280-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_DSTP5,                    10, 1295-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_DSTP,                      10, 1310-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP1,                           10, 1325-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP2,                           10, 1340-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP3,                           10, 1355-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP4,                           10, 1370-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_MCP5,                           10, 1385-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP2_EPI_OEPRF_ONB,                 10, 1400-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP2_DI_IEPRF_ONB,                  10, 1415-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP2_DI_IEPRF_ONB,            10, 1430-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP3_EPI_OEPRF_ONB,                 10, 1445-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP3_DI_IEPRF_ONB,                  10, 1460-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP3_DI_IEPRF_ONB,            10, 1475-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP4_EPI_OEPRF_ONB,                 10, 1490-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP4_DI_IEPRF_ONB,                  10, 1505-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP4_DI_IEPRF_ONB,            10, 1520-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP5_EPI_OEPRF_ONB,                 10, 1535-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_MCP5_DI_IEPRF_ONB,                  10, 1550-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BLOCK_ACCLT_MCP5_DI_IEPRF_ONB,            10, 1565-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_MCP,                       10, 1580-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB, 10, 1595-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB,    10, 1610-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP1_BORING_OEPRF_ONB,         10, 1625-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP1_STAIGHT_OEPRF_ONB,        10, 1640-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP1_BACK_OEPRF_ONB,           10, 1655-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP1_VLT_OEPRF_ONB,            10, 1670-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP1_OEPRF_ONB,                       10, 1685-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB, 10, 1700-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB,    10, 1715-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP2_BORING_OEPRF_ONB,         10, 1730-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP2_STAIGHT_OEPRF_ONB,        10, 1745-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP2_BACK_OEPRF_ONB,           10, 1760-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP2_VLT_OEPRF_ONB,            10, 1775-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP2_OEPRF_ONB,                       10, 1790-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB, 10, 1805-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB,    10, 1820-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP3_BORING_OEPRF_ONB,         10, 1835-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP3_STAIGHT_OEPRF_ONB,        10, 1850-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP3_BACK_OEPRF_ONB,           10, 1865-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP3_VLT_OEPRF_ONB,            10, 1880-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP3_OEPRF_ONB,                       10, 1895-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB, 10, 1910-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB,    10, 1925-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP4_BORING_OEPRF_ONB,         10, 1940-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP4_STAIGHT_OEPRF_ONB,        10, 1955-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP4_BACK_OEPRF_ONB,           10, 1970-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP4_VLT_OEPRF_ONB,            10, 1985-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP4_OEPRF_ONB,                       10, 2000-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB, 10, 2015-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB,    10, 2030-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP5_BORING_OEPRF_ONB,         10, 2045-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP5_STAIGHT_OEPRF_ONB,        10, 2060-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP5_BACK_OEPRF_ONB,           10, 2075-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_MCP5_VLT_OEPRF_ONB,            10, 2090-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_MCP5_OEPRF_ONB,                       10, 2105-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_AFU,                            10, 2120-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_AFU,                            10, 2135-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ARCL1,                                10, 2150-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ARCL2,                                10, 2165-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMIN1,                          10, 2180-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UMIN1,                          10, 2195-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMIN2,                          10, 2210-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UMIN2,                          10, 2225-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_UMIN1_OEPRF_ONB,               10, 2240-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UMIN1_OEPRF_ONB,                      10, 2255-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_UMIN2_OEPRF_ONB,               10, 2270-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UMIN2_OEPRF_ONB,                      10, 2285-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP1,                          10, 2300-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP1,                          10, 2315-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP1,                    10, 2330-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP2,                          10, 2345-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP2,                          10, 2360-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP2,                    10, 2375-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP3,                          10, 2390-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP3,                          10, 2405-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP3,                    10, 2420-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP4,                          10, 2435-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP4,                          10, 2450-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP4,                    10, 2465-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_TZNP5,                          10, 2480-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ACCLT_TZNP5,                          10, 2495-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ACCLT_TZNP5,                    10, 2510-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_TZNP1_EPI_OEPRF_ONB,                10, 2525-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_TZNP2_EPI_OEPRF_ONB,                10, 2540-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_TZNP3_EPI_OEPRF_ONB,                10, 2555-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_TZNP4_EPI_OEPRF_ONB,                10, 2570-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ACCLT_TZNP5_EPI_OEPRF_ONB,                10, 2585-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_TZNP1,                  10, 2600-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP1,                         10, 2615-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP1,                                10, 2630-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP1_3U0,                     10, 2645-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP1__3U0,                           10, 2660-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP1_3I0,                     10, 2675-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP1_3I0,                            10, 2690-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_TZNP2,                  10, 2705-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP2,                         10, 2720-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP2,                                10, 2735-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP2_3U0,                     10, 2750-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP2_3U0,                            10, 2765-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP2_3I0,                     10, 2780-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP2_3I0,                            10, 2795-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_TZNP3,                  10, 2810-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP3,                         10, 2825-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP3,                                10, 2840-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP3_3U0,                     10, 2855-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP3_3U0,                            10, 2870-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP3_3I0,                     10, 2885-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP3_3I0,                            10, 2900-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_TZNP4,                  10, 2915-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP4,                         10, 2930-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP4,                                10, 2945-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP4_3U0,                     10, 2960-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP4_3U0,                            10, 2975-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP4_3I0,                     10, 2990-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP4_3I0,                            10, 3005-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_TZNP5,                  10, 3020-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP5,                         10, 3035-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP5,                                10, 3050-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP5_3U0,                     10, 3065-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP5_3U0,                            10, 3080-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_TZNP5_3I0,                     10, 3095-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_TZNP5_3I0,                            10, 3110-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ZOP1,                           10, 3125-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_ZOP2,                           10, 3140-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_SEC_GR_UST_ZOP,                       10, 3155-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_ZOP1_STAIGHT,           10, 3170-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_ZOP1_BACK,              10, 3185-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP1_BORING,                   10, 3200-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP1_STAIGHT,                  10, 3215-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP1_BACK,                     10, 3230-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ZOP1,                                 10, 3245-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_ZOP2_STAIGHT,           10, 3260-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_SECTOR_ZOP2_BACK,              10, 3275-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP2_BORING,                   10, 3290-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP2_STAIGHT,                  10, 3305-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_ZOP2_BACK,                     10, 3320-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_ZOP2,                                 10, 3335-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_START_UROV,                           10, 3350-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UROV1,                                10, 3365-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UROV2,                                10, 3380-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMAX1,                          10, 3395-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_BLOCK_UMAX2,                          10, 3410-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_UMAX1_OEPRF_ONB,               10, 3425-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UMAX1_OEPRF_ONB,                      10, 3440-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_STPDEV_UMAX2_OEPRF_ONB,               10, 3455-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_UMAX2_OEPRF_ONB,                      10, 3470-2, RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT }
};

static const GUI_WIDGET_CREATE_INFO _aRankFPgCreate[] = {
  { WINDOW_CreateIndirect, "", ID_RANK_DO_PG, RANK_PG_X, RANK_PG_Y, RANK_PG_WIDTH, RANK_PG_HEIGHT, 0 },
  
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_ON,                              10, 5-2,    RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_HVSW_OFF,                             10, 20-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_SIGOUT,                         10, 35-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_RESET_LED,                            10, 50-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF01_DI_IEPRF_ONB,                   10, 65-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF02_DI_IEPRF_ONB,                   10, 80-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF03_DI_IEPRF_ONB,                   10, 95-2,   RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF04_DI_IEPRF_ONB,                   10, 110-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF05_DI_IEPRF_ONB,                   10, 125-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF06_DI_IEPRF_ONB,                   10, 140-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF07_DI_IEPRF_ONB,                   10, 155-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF08_DI_IEPRF_ONB,                   10, 170-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF09_DI_IEPRF_ONB,                   10, 185-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF10_DI_IEPRF_ONB,                   10, 200-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF11_DI_IEPRF_ONB,                   10, 215-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF12_DI_IEPRF_ONB,                   10, 230-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF13_DI_IEPRF_ONB,                   10, 245-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF14_DI_IEPRF_ONB,                   10, 260-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF15_DI_IEPRF_ONB,                   10, 275-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_BIT_EDF16_DI_IEPRF_ONB,                   10, 290-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT1,                             10, 305-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT1,                           10, 320-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT2,                             10, 335-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT2,                           10, 350-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT3,                             10, 365-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT3,                           10, 380-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT4,                             10, 395-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT4,                           10, 410-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT5,                             10, 425-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT5,                           10, 440-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT6,                             10, 455-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT6,                           10, 470-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT7,                             10, 485-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT7,                           10, 500-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_SET_OT8,                             10, 515-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT },
  { CHECKBOX_CreateIndirect, NULL, GUI_ID_ADDR_RESET_OT8,                           10, 530-2,  RANK_CHECKBOX_WIDTH, RANK_CHECKBOX_HEIGHT }
};

static unsigned char sel_rank_di_language = 0xff;
static unsigned char sel_rank_do_language = 0xff;
static unsigned char sel_rank_led_language = 0xff;
static unsigned char sel_rank_df_plus_language = 0xff;
static unsigned char sel_rank_df_minus_language = 0xff;
static unsigned char sel_rank_df_blk_language = 0xff;
static unsigned char sel_rank_f_language = 0xff;
static unsigned char sel_rank_trg_set_pl_language = 0xff;
static unsigned char sel_rank_trg_set_mn_language = 0xff;
static unsigned char sel_rank_trg_rst_pl_language = 0xff;
static unsigned char sel_rank_trg_rst_mn_language = 0xff;
static unsigned char sel_rank_an_dig_rec_language = 0xff;

/*********************************************************************
*
*       Ranking pg functions
*/
static int set_sign(int val) {
  return (val < 0) ? val : -val;
}

int ignore_hbit(int val) {
  return val & 0x7fffffff;
}

/*********************************************************************
*
*       _cbDI
*/
static void _cbDI(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDO
*/
static void _cbDO(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbLED
*/
static void _cbLED(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDFPlus
*/
static void _cbDFPlus(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDFMinus
*/
static void _cbDFMinus(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDFBlk
*/
static void _cbDFBlk(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbF
*/
static void _cbF(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDTSetPl
*/
static void _cbDTSetPl(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDTSetMn
*/
static void _cbDTSetMn(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDTRstPl
*/
static void _cbDTRstPl(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDTRstMn
*/
static void _cbDTRstMn(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbAnDigRec
*/
static void _cbAnDigRec(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbRankWin
*/
static void _cbRankWin(WM_MESSAGE * pMsg) {
//  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case (GUI_ID_USER + 3): // Notifications sent by 'Multipage'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        Id    = WM_GetId(pMsg->hWinSrc);
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  case WM_PAINT:
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

static void rPaintRankPanel() {
  if (current_ekran.edition != 0) {
    if (current_ekran.index_position == ID_RANK_AN_DIG_REC_PG && ignore_hbit(an_dig_rec_index) != 0) {
      char explanationText[100] = {0};
      explanationText[0] = ' ';
      _CONCAT_STR(explanationText, confExplText[eeprom_bs_settings_tbl.chLngGUIText]);
      _CONCAT_STR(explanationText, editModeAdditionalText[eeprom_bs_settings_tbl.chLngGUIText]);
      EDIT_SetText(hEdit, explanationText);
    } else {
      char explanationText[100] = {0};
      unsigned int i = 0;
      for (; _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
        explanationText[i] = _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i];
      }
      if (current_ekran.index_position != ID_RANK_F_PG
          && current_ekran.index_position != ID_RANK_TRG_SET_PL_PG
          && current_ekran.index_position != ID_RANK_TRG_SET_MN_PG
          && current_ekran.index_position != ID_RANK_TRG_RST_PL_PG
          && current_ekran.index_position != ID_RANK_TRG_RST_MN_PG
      ) {
        _CONCAT_STR(explanationText, "; ");
      }
      _CONCAT_STR(explanationText, confExplText[eeprom_bs_settings_tbl.chLngGUIText]);
      _CONCAT_STR(explanationText, editModeAdditionalText[eeprom_bs_settings_tbl.chLngGUIText]);
      EDIT_SetText(hEdit, explanationText);
    }
  } else {
    EDIT_SetText(hEdit, _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  }
  
  FRAMEWIN_SetText(rankMultiPageWin, rankFrmText[eeprom_bs_settings_tbl.chLngGUIText]);
  
  for (int _id = ID_RANK_DISCRETE_INPUT_PG; _id < MAX_LEVEL_RANK_PG; _id++) {
    MULTIPAGE_SetText(rankHMultiPage, _rankItem[_id].pText[eeprom_bs_settings_tbl.chLngGUIText], _id);
  }
  
  switch(current_ekran.index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      {
        if (sel_rank_di_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_di_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_DI_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDIPgs, di_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][di_id_list[i] - GUI_ID_BIT_HVSW_ON/*первый идентификатор для ранж.*/]);
          }
        }
        break;
      }
    case ID_RANK_DISCRETE_OUTPUT_PG:
      {
        if (sel_rank_do_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_do_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_DO_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_LED_PG:
      {
        if (sel_rank_led_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_led_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_LED_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_DF_PLUS_PG:
      {
        if (sel_rank_df_plus_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_df_plus_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_DF_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_DF_MINUS_PG:
      {
        if (sel_rank_df_minus_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_df_minus_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_DF_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_DF_BLK_PG:
      {
        if (sel_rank_df_blk_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_df_blk_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_DF_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_F_PG:
      {
        if (sel_rank_f_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_f_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_F_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankFPgs, f_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][f_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_TRG_SET_PL_PG:
      {
        if (sel_rank_trg_set_pl_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_trg_set_pl_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_TRG_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_TRG_SET_MN_PG:
      {
        if (sel_rank_trg_set_mn_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_trg_set_mn_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_TRG_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_TRG_RST_PL_PG:
      {
        if (sel_rank_trg_rst_pl_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_trg_rst_pl_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_TRG_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_TRG_RST_MN_PG:
      {
        if (sel_rank_trg_rst_mn_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_trg_rst_mn_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_TRG_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    case ID_RANK_AN_DIG_REC_PG:
      {
        if (sel_rank_an_dig_rec_language != eeprom_bs_settings_tbl.chLngGUIText) {
          sel_rank_an_dig_rec_language = eeprom_bs_settings_tbl.chLngGUIText;
          for (int i = 0; i < NUM_AN_DIG_REC_FUNCS; i++) {
            CHECKBOX_SetText(WM_GetDialogItem(rankDOLedOFDTArDrPgs, doLedDfDtArDr_id_list[i]), rank_checkbox_item[eeprom_bs_settings_tbl.chLngGUIText][doLedDfDtArDr_id_list[i] - GUI_ID_BIT_HVSW_ON]);
          }
        }
        break;
      }
    default: break;
  }
}

void init_sub_pg(int _pg_index) {
  unsigned int pgCountArr[] = {
    NUM_IN,
    NUM_OUT,
    NUM_LED,
    NUM_DEF_FUN,
    NUM_DEF_FUN,
    NUM_DEF_FUN,
    NUM_KEY,
    NUM_TRG,
    NUM_TRG,
    NUM_TRG,
    NUM_TRG,
    2
  };
  WM_HWIN * pMultiPg = &rankMulPgArr[_pg_index];
  WM_HWIN * pFuncPg;
  void (*pCallbackFunc)();
  unsigned int num_funcs;
  unsigned int * id_list;
  WM_HWIN * pScrollPg;
  switch(_pg_index) {
    case ID_RANK_DISCRETE_INPUT_PG:
      {
        pFuncPg = &rankDIPgs;
        pCallbackFunc = _cbDI;
        num_funcs = NUM_DI_FUNCS;
        id_list = di_id_list;
        pScrollPg = &rankDIPgScroll;
        break;
      }
    case ID_RANK_DISCRETE_OUTPUT_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDO;
        num_funcs = NUM_DO_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_LED_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbLED;
        num_funcs = NUM_LED_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_DF_PLUS_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDFPlus;
        num_funcs = NUM_DF_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_DF_MINUS_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDFMinus;
        num_funcs = NUM_DF_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_DF_BLK_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDFBlk;
        num_funcs = NUM_DF_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_F_PG:
      {
        pFuncPg = &rankFPgs;
        pCallbackFunc = _cbF;
        num_funcs = NUM_F_FUNCS;
        id_list = f_id_list;
        pScrollPg = &rankFPgScroll;
        break;
      }
    case ID_RANK_TRG_SET_PL_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDTSetPl;
        num_funcs = NUM_TRG_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_TRG_SET_MN_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDTSetMn;
        num_funcs = NUM_TRG_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_TRG_RST_PL_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDTRstPl;
        num_funcs = NUM_TRG_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_TRG_RST_MN_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbDTRstMn;
        num_funcs = NUM_TRG_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    case ID_RANK_AN_DIG_REC_PG:
      {
        pFuncPg = &rankDOLedOFDTArDrPgs;
        pCallbackFunc = _cbAnDigRec;
        num_funcs = NUM_AN_DIG_REC_FUNCS;
        id_list = doLedDfDtArDr_id_list;
        pScrollPg = &rankDOLedOFDTArDrPgScroll;
        break;
      }
    default:
      {
        pFuncPg = &rankDIPgs;
        pCallbackFunc = _cbDI;
        num_funcs = NUM_DI_FUNCS;
        id_list = di_id_list;
        pScrollPg = &rankDIPgScroll;
        break;
      }
  }
  
  _Bool wm_unattached = 0;
  if (*pMultiPg == WM_UNATTACHED) {
    wm_unattached = 1;
    *pMultiPg = MULTIPAGE_CreateEx(
        RANK_PG_X, RANK_PG_Y,
        RANK_MULTI_PG_WIDTH, RANK_MULTI_PG_HEIGHT,
        WM_GetClientWindow(rankPgs[_pg_index]),
        WM_CF_SHOW, 0, 0
    );
    MULTIPAGE_SetFont(*pMultiPg, &GUI_FontArialBold14_8_Unicode);
    MULTIPAGE_SetRotation(*pMultiPg, MULTIPAGE_CF_ROTATE_CW);
  }
  if (*pFuncPg == WM_UNATTACHED) {
    if (_pg_index == ID_RANK_DISCRETE_INPUT_PG) {
      *pFuncPg = GUI_CreateDialogBox(
        _aRankDiPgCreate,
        GUI_COUNTOF(_aRankDiPgCreate),
        pCallbackFunc, WM_UNATTACHED, 0, 0
      );
    } else if (_pg_index == ID_RANK_F_PG) {
      *pFuncPg = GUI_CreateDialogBox(
        _aRankFPgCreate,
        GUI_COUNTOF(_aRankFPgCreate),
        pCallbackFunc, WM_UNATTACHED, 0, 0
      );
    } else {
      *pFuncPg = GUI_CreateDialogBox(
        _aRankDoLedDfPgCreate,
        GUI_COUNTOF(_aRankDoLedDfPgCreate),
        pCallbackFunc, WM_UNATTACHED, 0, 0
      );
    }
    WINDOW_SetBkColor(*pFuncPg, GUI_LIGHTGRAY);
    for (unsigned int i = 0; i < num_funcs; i++) {
      CHECKBOX_SetFont(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          &GUI_FontArialStandard14_8_Unicode
      );
      if (i == 0) {
        CHECKBOX_SetBkColor(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          GUI_BLUE
        );
        CHECKBOX_SetFocusColor(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          GUI_BLUE
        );
        CHECKBOX_SetTextColor(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          GUI_YELLOW
        );
      } else {
        CHECKBOX_SetBkColor(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          GUI_LIGHTGRAY
        );
        CHECKBOX_SetFocusColor(
          WM_GetDialogItem(*pFuncPg, id_list[i]),
          GUI_LIGHTGRAY
        );
      }
      CHECKBOX_SetBoxBkColor(
        WM_GetDialogItem(*pFuncPg, id_list[i]),
        GUI_YELLOW,
        CHECKBOX_CI_ENABLED
      );
      CHECKBOX_SetBoxBkColor(
        WM_GetDialogItem(*pFuncPg, id_list[i]),
        GUI_GRAY,
        CHECKBOX_CI_DISABLED
      );
    }
  }
  
  if (wm_unattached) {
    for (unsigned int i = 0; i < pgCountArr[_pg_index]; i++) {
      MULTIPAGE_AddPage(
        *pMultiPg,
        *pFuncPg,
        rank_pgs_item[_pg_index][eeprom_bs_settings_tbl.chLngGUIText][i]
      );
      if (i > 0) MULTIPAGE_DisablePage(*pMultiPg, i);
    }
    MULTIPAGE_SelectPage(*pMultiPg, 0);
    MULTIPAGE_SetBkColor(*pMultiPg, GUI_USER_LIGHTGRAY, MULTIPAGE_CI_DISABLED);
    MULTIPAGE_SetBkColor(*pMultiPg, GUI_BLACK, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetTextColor(*pMultiPg, GUI_BLACK, MULTIPAGE_CI_DISABLED);
    MULTIPAGE_SetTextColor(*pMultiPg, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
  } else {
    MULTIPAGE_Obj * pObj;
    WM_HWIN hClient;
    WM_LOCK();
    pObj = MULTIPAGE_LOCK_H(*pMultiPg);
    hClient = pObj->hClient;
    WM_AttachWindowAt(*pFuncPg, hClient, 0, 0);
    WM_UNLOCK();
  }
  
  if (*pScrollPg == WM_UNATTACHED) {
    *pScrollPg = SCROLLBAR_CreateAttached(WM_GetClientWindow(*pFuncPg), SCROLLBAR_CF_VERTICAL);
    SCROLLBAR_SetNumItems(*pScrollPg, num_funcs * RANK_CHECKBOX_HEIGHT);
    SCROLLBAR_SetPageSize(*pScrollPg, NUMBER_SHOWING_RANK_ITEMS * RANK_CHECKBOX_HEIGHT);
  }
}

void rank_panel_init() {
  rankMultiPageWin = FRAMEWIN_Create(
      rankFrmText[eeprom_bs_settings_tbl.chLngGUIText],
      _cbRankWin,
      WM_CF_HIDE,
      RANK_PG_X2, RANK_PG_Y2,
      RANK_PG_WIDTH2, RANK_PG_HEIGHT2
  );
  FRAMEWIN_SetFont(rankMultiPageWin, &GUI_FontArialBold14_8_Unicode);
  FRAMEWIN_SetTitleVis(rankMultiPageWin, 0/*hidden*/);
  
  //Главная панель вкладокgit
  rankHMultiPage = MULTIPAGE_CreateEx(
      RANK_PG_X, RANK_PG_Y,
      RANK_PG_WIDTH2, RANK_PG_HEIGHT2,
      WM_GetClientWindow(rankMultiPageWin),
      WM_CF_SHOW, 0, 0
  );
  MULTIPAGE_SetFont(rankHMultiPage, &GUI_FontArialBold14_8_Unicode);
  
  for (int i = 0; i < MAX_LEVEL_RANK_PG; i++) {
    rankMulPgArr[i] = WM_UNATTACHED;
  }
  
  void (*pCallbackArr[])() = {
    _cbDI,
    _cbDO,
    _cbLED,
    _cbDFPlus,
    _cbDFMinus,
    _cbDFBlk,
    _cbF,
    _cbDTSetPl,
    _cbDTSetMn,
    _cbDTRstPl,
    _cbDTRstMn,
    _cbAnDigRec
  };
  int pg_id_arr[] = {
    ID_RANK_DI_PG,
    ID_RANK_DO_PG,
    ID_RANK_LED_PG,
    ID_RANK_DF_PLUS_PG,
    ID_RANK_DF_MINUS_PG,
    ID_RANK_DF_BLK_PG,
    ID_RANK_F_PG,
    ID_RANK_TRG_SET_PL_PG,
    ID_RANK_TRG_SET_MN_PG,
    ID_RANK_TRG_RST_PL_PG,
    ID_RANK_TRG_RST_MN_PG,
    ID_RANK_AN_DIG_REC_PG
  };
  
  for (int _pg_index = ID_RANK_DISCRETE_INPUT_PG; _pg_index < MAX_LEVEL_RANK_PG; _pg_index++) {
    rankPgs[_pg_index] = WINDOW_CreateEx(
      RANK_PG_X2, RANK_PG_Y2,
      RANK_PG_WIDTH2, RANK_PG_HEIGHT2,
      rankHMultiPage, WM_CF_SHOW,
      NULL, pg_id_arr[_pg_index],
      pCallbackArr[_pg_index]
    );
    MULTIPAGE_AddPage(
      rankHMultiPage,
      rankPgs[_pg_index],
      _rankItem[_pg_index].pText[eeprom_bs_settings_tbl.chLngGUIText]
    );
    //панели подвкладок
    init_sub_pg(_pg_index);
  }
  
  MULTIPAGE_SetBkColor(rankHMultiPage, GUI_USER_LIGHTGRAY, MULTIPAGE_CI_DISABLED);
  MULTIPAGE_SetBkColor(rankHMultiPage, GUI_BLACK, MULTIPAGE_CI_ENABLED);
  MULTIPAGE_SetTextColor(rankHMultiPage, GUI_BLACK, MULTIPAGE_CI_DISABLED);
  MULTIPAGE_SetTextColor(rankHMultiPage, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
  
  for (int i = 1; i < MAX_LEVEL_RANK_PG; i++)
    MULTIPAGE_DisablePage(rankHMultiPage, i);
}

_Bool rank_vk_esc_handler() {
  WM_HWIN multi_pg = rankMulPgArr[current_ekran.index_position];
  WM_HWIN func_pg;
  WM_HWIN scroll_pg;
  unsigned int number_pgs;
  unsigned int number_checkbox;
  int multi_pg_val;
  int checkbox_val;
  int rank_pg_y_val;
  int * prev_rank_pg_y_val;
  unsigned int (*sel_inf_arr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  _INIT_MULTI_PG_VALUES(
    multi_pg_val,
    checkbox_val,
    rank_pg_y_val,
    func_pg,
    scroll_pg,
    number_pgs,
    number_checkbox,
    prev_rank_pg_y_val,
    sel_inf_arr
  );
  
  _Bool h_bit;
  _CHECK_HIGHEST_BIT(multi_pg_val, h_bit);
  
  unsigned int disabling_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  create_disabling_rank_inf(
    current_ekran.index_position,
    &disabling_inf_arr,
    MAX_NUM_RANK_PGS,
    NUM_FUNC_TO_INT_BITS
  );
  
  unsigned int id;
  
  if (!h_bit) {
    return 0;
  } else {
    _SET_HIGHEST_BIT(multi_pg_val, 0);
    WINDOW_SetBkColor(func_pg, GUI_LIGHTGRAY);
    for (unsigned int i = 0; i < number_checkbox; i++) {
      _SEL_ID(i, id);
      WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
      _UPDATE_CHECKBOX(
        i,
        multi_pg_val,
        checkbox_val,
        id,
        disabling_inf_arr,
        sel_inf_arr,
        checkbox_pg,
        GUI_LIGHTGRAY
      );
//      update_checkbox(
//        i,
//        multi_pg_val,
//        checkbox_val,
//        id,
//        &disabling_inf_arr,
//        sel_inf_arr,
//        checkbox_pg,
//        GUI_LIGHTGRAY
//      );
    }
    _SET_MULTI_PG_INDEX(multi_pg_val);
  }
  rank_control_bits |= CHECKBOX_IS_UPDATED_MASK;
  
  rPaintRankPanel();
  return 1;
}

void rank_vk_enter_handler() {
  WM_HWIN multi_pg = rankMulPgArr[current_ekran.index_position];
  WM_HWIN func_pg;
  WM_HWIN scroll_pg;
  unsigned int number_pgs;
  unsigned int number_checkbox;
  int multi_pg_val;
  int checkbox_val;
  int rank_pg_y_val;
  int * prev_rank_pg_y_val;
  unsigned int (*sel_inf_arr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  _INIT_MULTI_PG_VALUES(
    multi_pg_val,
    checkbox_val,
    rank_pg_y_val,
    func_pg,
    scroll_pg,
    number_pgs,
    number_checkbox,
    prev_rank_pg_y_val,
    sel_inf_arr
  );
  
  _Bool h_bit;
  _CHECK_HIGHEST_BIT(multi_pg_val, h_bit);
  
  unsigned int disabling_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  create_disabling_rank_inf(
    current_ekran.index_position,
    &disabling_inf_arr,
    MAX_NUM_RANK_PGS,
    NUM_FUNC_TO_INT_BITS
  );
  
  unsigned int id;
  
  int multi_pg_val_tmp = multi_pg_val & MASK_MULTI_PG_VAL;
  if (!h_bit) {
    _SET_HIGHEST_BIT(multi_pg_val, 1);
    WINDOW_SetBkColor(func_pg, GUI_WHITE);
    for (unsigned int i = 0; i < number_checkbox; i++) {
      _SEL_ID(i, id);
      WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
      _UPDATE_CHECKBOX(
        i,
        multi_pg_val_tmp,
        checkbox_val,
        id,
        disabling_inf_arr,
        sel_inf_arr,
        checkbox_pg,
        GUI_WHITE
      );
//      update_checkbox(
//        i,
//        multi_pg_val,
//        checkbox_val,
//        id,
//        &disabling_inf_arr,
//        sel_inf_arr,
//        checkbox_pg,
//        GUI_WHITE
//      );
    }
    _SET_MULTI_PG_INDEX(multi_pg_val);
  } else {
    if (current_ekran.edition != 0) {
      current_ekran.edition = 2;
      if (
           _CHECK_RANK_SET_BIT_P(
             sel_inf_arr,
             multi_pg_val_tmp,
             checkbox_val
           ) != 0
         )
      {
        _CLEAR_RANK_BIT_P(sel_inf_arr, multi_pg_val_tmp, checkbox_val);
      } else {
        _SET_RANK_BIT_P(sel_inf_arr, multi_pg_val_tmp, checkbox_val);
      }
      
      for (unsigned int i = 0; i < number_checkbox; i++) {
        _SEL_ID(i, id);
        WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
        _UPDATE_CHECKBOX(
          i,
          multi_pg_val_tmp,
          checkbox_val,
          id,
          disabling_inf_arr,
          sel_inf_arr,
          checkbox_pg,
          GUI_WHITE
        );
//        update_checkbox(
//          i,
//          multi_pg_val,
//          checkbox_val,
//          id,
//          &disabling_inf_arr,
//          sel_inf_arr,
//          checkbox_pg,
//          GUI_WHITE
//        );
      }
    }
    
  }
  rank_control_bits |= CHECKBOX_IS_UPDATED_MASK;
  
  rPaintRankPanel();
}

void select_rank_multipage(int index) {
  if (current_ekran.edition != 0) {
    char explanationText[100] = {0};
    unsigned int i = 0;
    for (; _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i] != '\0'; i++) {
      explanationText[i] = _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText][i];
    }
    if (current_ekran.index_position != ID_RANK_F_PG) {
      _CONCAT_STR(explanationText, "; ");
    }
    _CONCAT_STR(explanationText, confExplText[eeprom_bs_settings_tbl.chLngGUIText]);
    _CONCAT_STR(explanationText, editModeAdditionalText[eeprom_bs_settings_tbl.chLngGUIText]);
    EDIT_SetText(hEdit, explanationText);
  } else {
    EDIT_SetText(hEdit, _rankItem[current_ekran.index_position].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  }
  for (int i = 0; i < MAX_LEVEL_RANK_PG; i++) {
    if (MULTIPAGE_IsPageEnabled(rankHMultiPage, i)) {
      MULTIPAGE_DisablePage(rankHMultiPage, i);
      break;
    }
  }
  
  WM_HWIN multi_pg = rankMulPgArr[current_ekran.index_position];
  WM_HWIN func_pg;
  WM_HWIN scroll_pg;
  unsigned int number_pgs;
  unsigned int number_checkbox;
  int multi_pg_val;
  int checkbox_val;
  int rank_pg_y_val;
  int * prev_rank_pg_y_val;
  unsigned int (*sel_inf_arr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  _INIT_MULTI_PG_VALUES(
    multi_pg_val,
    checkbox_val,
    rank_pg_y_val,
    func_pg,
    scroll_pg,
    number_pgs,
    number_checkbox,
    prev_rank_pg_y_val,
    sel_inf_arr
  );
  
  unsigned int disabling_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  create_disabling_rank_inf(
    current_ekran.index_position,
    &disabling_inf_arr,
    MAX_NUM_RANK_PGS,
    NUM_FUNC_TO_INT_BITS
  );
  
  _Bool check_box_is_updated = 0;
  if (rank_control_bits & CHECKBOX_IS_UPDATED_MASK) {
    rank_control_bits &= ~CHECKBOX_IS_UPDATED_MASK;
    check_box_is_updated = 1;
  }
  
  if (rank_control_bits & RIGHT_OR_LEFT_MOVING_MASK) {
    rank_control_bits &= ~RIGHT_OR_LEFT_MOVING_MASK;
    //Обновление скрола на основной панели вкладок ранжирования
    WM_HWIN hScroll = 0;
    WM_Obj * pWin = WM_LOCK_H(rankHMultiPage);
    WM_HWIN hi = pWin->hFirstChild;
    GUI_UNLOCK_H(pWin);
    while (hi) {
      if (WM_GetId(hi) == GUI_ID_HSCROLL) {
        hScroll = hi;
        break;
      }
      pWin = WM_LOCK_H(hi);
      hi = pWin->hNext;
      GUI_UNLOCK_H(pWin);
    }
    SCROLLBAR_SetValue(hScroll, current_ekran.index_position);
  }
  
  //Обновление скрола на панели ранжирования
  unsigned int id;
  int _direction;
  
  _SEL_ID(checkbox_val, id);
  WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
  
  WM_SCROLL_STATE ScrollState;
  WM_GetScrollState(scroll_pg, &ScrollState);
  
  //если равно, то не имеет значения
  if (abs(*prev_rank_pg_y_val) < abs(rank_pg_y_val)) {
    //поднять вверьх коорд. всех чекбоксов (не скролла (скролл опуск. вниз))
    _direction = UP;
  } else {
    //опустить вниз координаты всех чекбоксов
    _direction = DOWN;
  }
  
  int y_tmp = abs(rank_pg_y_val) - abs(*prev_rank_pg_y_val);
  int v_scroll;
  v_scroll = y_tmp / ScrollState.PageSize;
  v_scroll *= ScrollState.PageSize;
  
  if (abs(v_scroll) >= ScrollState.PageSize) {
    SCROLLBAR_SetValue(scroll_pg, ScrollState.v + v_scroll);
  }
  
  for (unsigned int i = 0; i < number_checkbox; i++) {
    _SEL_ID(i, id);
    checkbox_pg = WM_GetDialogItem(multi_pg, id);
    if (abs(v_scroll) >= ScrollState.PageSize) {
      switch (_direction) {
        case UP:
          {
            WM_MoveWindow(checkbox_pg, 0, set_sign(v_scroll));
            break;
          }
        case DOWN:
          {
            WM_MoveWindow(checkbox_pg, 0, abs(v_scroll));
            break;
          }
        default:break;
      }
    }
    if (!check_box_is_updated) {
      _UPDATE_CHECKBOX(
        i,
        multi_pg_val,
        checkbox_val,
        id,
        disabling_inf_arr,
        sel_inf_arr,
        checkbox_pg,
        GUI_LIGHTGRAY
      );
    }
//      update_checkbox(
//        i,
//        multi_pg_val,
//        checkbox_val,
//        id,
//        &disabling_inf_arr,
//        sel_inf_arr,
//        checkbox_pg,
//        GUI_LIGHTGRAY
//      );
  }
  *prev_rank_pg_y_val = rank_pg_y_val;
  
  MULTIPAGE_EnablePage(rankHMultiPage, index);
  MULTIPAGE_SelectPage(rankHMultiPage, index);
  
  rPaintRankPanel();
}

void select_rank_sub_multipage(
    char _direction,
    _Bool pgJump,
    int jumpPgPosition,
    int jumpCheckboxPosition
  ) {
  WM_HWIN multi_pg = rankMulPgArr[current_ekran.index_position];
  WM_HWIN func_pg;
  WM_HWIN scroll_pg;
  unsigned int number_pgs;
  unsigned int number_checkbox;
  int multi_pg_val;
  int checkbox_val;
  int rank_pg_y_val;
  int * prev_rank_pg_y_val;
  unsigned int (*sel_inf_arr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  _INIT_MULTI_PG_VALUES(
    multi_pg_val,
    checkbox_val,
    rank_pg_y_val,
    func_pg,
    scroll_pg,
    number_pgs,
    number_checkbox,
    prev_rank_pg_y_val,
    sel_inf_arr
  );
  
  _Bool h_bit;
  _CHECK_HIGHEST_BIT(multi_pg_val, h_bit);
  
  unsigned int disabling_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  create_disabling_rank_inf(
    current_ekran.index_position,
    &disabling_inf_arr,
    MAX_NUM_RANK_PGS,
    NUM_FUNC_TO_INT_BITS
  );
  
  if (!h_bit) {
    //если фокус перемещается по вкладкам на панели ранжирования
    switch (_direction) {
      case UP:
        {
          if (pgJump) {
            if (multi_pg_val - jumpPgPosition < 0) {
              multi_pg_val = 0;
            } else {
              multi_pg_val -= jumpPgPosition;
            }
          } else {
            if (multi_pg_val == 0) {
              multi_pg_val = number_pgs - 1;
            } else {
              multi_pg_val--;
            }
          }
          break;
        }
      case DOWN:
        {
          if (pgJump) {
            if ((unsigned int)(multi_pg_val + jumpPgPosition) >= number_pgs) {
              multi_pg_val = number_pgs - 1;
            } else {
              multi_pg_val += jumpPgPosition;
            }
          } else {
            if (multi_pg_val == number_pgs - 1) {
              multi_pg_val = 0;
            } else {
              multi_pg_val++;
            }
          }
          break;
        }
      default:break;
    }
    
    _SET_MULTI_PG_INDEX(multi_pg_val);
    int * null_p;
    unsigned int (*pNullArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
    _INIT_MULTI_PG_VALUES(
      multi_pg_val,
      checkbox_val,
      rank_pg_y_val,
      func_pg,
      scroll_pg,
      number_pgs,
      number_checkbox,
      null_p,
      pNullArr
    );
    
    create_disabling_rank_inf(
      current_ekran.index_position,
      &disabling_inf_arr,
      MAX_NUM_RANK_PGS,
      NUM_FUNC_TO_INT_BITS
    );
    
    for (unsigned int i = 0; i < number_pgs; i++) {
      if (MULTIPAGE_IsPageEnabled(multi_pg, i)) {
        MULTIPAGE_DisablePage(multi_pg, i);
        break;
      }
    }
    
    //Обновление скрола на подпанели вкладок
    MULTIPAGE_EnablePage(multi_pg, multi_pg_val);
    MULTIPAGE_SelectPage(multi_pg, multi_pg_val);
    WM_HWIN hScroll = 0;
    WM_Obj * pWin = WM_LOCK_H(multi_pg);
    WM_HWIN hi = pWin->hFirstChild;
    GUI_UNLOCK_H(pWin);
    while (hi) {
      if (WM_GetId(hi) == GUI_ID_HSCROLL) {
        hScroll = hi;
        break;
      }
      pWin = WM_LOCK_H(hi);
      hi = pWin->hNext;
      GUI_UNLOCK_H(pWin);
    }
    SCROLLBAR_SetValue(hScroll, multi_pg_val);
    _SET_MULTI_PG_INDEX(multi_pg_val);
    
    //Обновление скрола на панели ранжирования
    unsigned int id;
    _SEL_ID(checkbox_val, id);
    WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
    
    //при перемещении по вкладкам надо правильно задать переменную _direction
    //потому что в этом случае эта переменная отвечает только за движение
    //вверх вниз по вкладкам а не по чекбоксам
    //Для опред. куда двигаться надо сравнить пред. и текущее состояние чекбокса
    WM_SCROLL_STATE ScrollState;
    WM_GetScrollState(scroll_pg, &ScrollState);
    
    //если равно, то не имеет значения
    if (abs(*prev_rank_pg_y_val) < abs(rank_pg_y_val)) {
      //поднять вверьх коорд. всех чекбоксов (не скролла (скролл опуск. вниз))
      _direction = UP;
    } else {
      _direction = DOWN; //опустить вниз координаты всех чекбоксов
    }
    
    int y_tmp = abs(rank_pg_y_val) - abs(*prev_rank_pg_y_val);
    int v_scroll;
    v_scroll = y_tmp / ScrollState.PageSize;
    v_scroll *= ScrollState.PageSize;
    
    if (abs(v_scroll) >= ScrollState.PageSize) {
      SCROLLBAR_SetValue(scroll_pg, ScrollState.v + v_scroll);
    }
    
    for (unsigned int i = 0; i < number_checkbox; i++) {
      _SEL_ID(i, id);
      checkbox_pg = WM_GetDialogItem(multi_pg, id);
      if (abs(v_scroll) >= ScrollState.PageSize) {
        switch (_direction) {
          case UP:
            {
              WM_MoveWindow(checkbox_pg, 0, set_sign(v_scroll));
              break;
            }
          case DOWN:
            {
              WM_MoveWindow(checkbox_pg, 0, abs(v_scroll));
              break;
            }
          default:break;
        }
      }
      _UPDATE_CHECKBOX(
        i,
        multi_pg_val,
        checkbox_val,
        id,
        disabling_inf_arr,
        sel_inf_arr,
        checkbox_pg,
        GUI_LIGHTGRAY
      );
//      update_checkbox(
//        i,
//        multi_pg_val,
//        checkbox_val,
//        id,
//        &disabling_inf_arr,
//        sel_inf_arr,
//        checkbox_pg,
//        GUI_LIGHTGRAY
//      );
    }
  } else {
    //если фокус перемещается по чекбоксам
    switch (_direction) {
      case UP:
        {
          if (pgJump) {
            if (checkbox_val - jumpCheckboxPosition < 0) {
              checkbox_val = 0;
            } else {
              checkbox_val -= jumpCheckboxPosition;
            }
          } else if (checkbox_val != 0) {
            checkbox_val--;
          }
          break;
        }
      case DOWN:
        {
          if (pgJump) {
            if ((unsigned int)(checkbox_val + jumpCheckboxPosition)
                >= number_checkbox) {
              checkbox_val = number_checkbox - 1;
            } else {
              checkbox_val += jumpCheckboxPosition;
            }
          } else if (checkbox_val < (int) number_checkbox - 1) {
            checkbox_val++;
          }
          break;
        }
      default:break;
    }
    
    unsigned int id;
    _SEL_ID(checkbox_val, id);
    WM_HWIN checkbox_pg = WM_GetDialogItem(multi_pg, id);
    
    WM_SCROLL_STATE ScrollState;
    WM_GetScrollState(scroll_pg, &ScrollState);
    
    int y_hWinSrc = rank_pg_y_val + WM_GetWindowOrgY(rankDIPgs)
      + ((*prev_rank_pg_y_val > rank_pg_y_val) ? 3 : -2);
    int y_hWin = WM_GetWindowOrgY(checkbox_pg);
    int y_tmp = y_hWinSrc - y_hWin;
    int v_scroll;
    v_scroll = y_tmp / ScrollState.PageSize;
    v_scroll *= ScrollState.PageSize;
    
    int dy;
    if (rank_pg_y_val != v_scroll) {
      dy = rank_pg_y_val - v_scroll;
      switch (_direction) {
        case UP:
          {
            if (jumpCheckboxPosition == MAX_CHECKBOX_JUMP_VAL) {
              SCROLLBAR_SetValue(scroll_pg, 0);
            } else {
              SCROLLBAR_SetValue(scroll_pg, ScrollState.v - ScrollState.PageSize);
            }
            break;
          }
        case DOWN:
          {
            if (jumpCheckboxPosition == MAX_CHECKBOX_JUMP_VAL) {
              SCROLLBAR_SetValue(scroll_pg, number_checkbox * RANK_CHECKBOX_HEIGHT);
            } else {
              SCROLLBAR_SetValue(scroll_pg, ScrollState.v + ScrollState.PageSize);
            }
            break;
          }
        default:break;
      }
    }
    
    for (unsigned int i = 0; i < number_checkbox; i++) {
      _SEL_ID(i, id);
      checkbox_pg = WM_GetDialogItem(multi_pg, id);
      if (rank_pg_y_val != v_scroll) {
        switch (_direction) {
          case UP:
            {
              WM_MoveWindow(checkbox_pg, 0, abs(dy));
              break;
            }
          case DOWN:
            {
              WM_MoveWindow(checkbox_pg, 0, set_sign(dy));
              break;
            }
          default:break;
        }
      }
      _UPDATE_CHECKBOX(
        i,
        multi_pg_val,
        checkbox_val,
        id,
        disabling_inf_arr,
        sel_inf_arr,
        checkbox_pg,
        GUI_WHITE
      );
//      update_checkbox(
//        i,
//        multi_pg_val,
//        checkbox_val,
//        id,
//        &disabling_inf_arr,
//        sel_inf_arr,
//        checkbox_pg,
//        GUI_WHITE
//      );
    }
    
    rank_pg_y_val = v_scroll;
    _SET_CHECKBOX_VAL(
      multi_pg_val,
      checkbox_val,
      rank_pg_y_val
    );
  }
  *prev_rank_pg_y_val = rank_pg_y_val;
  rank_control_bits |= CHECKBOX_IS_UPDATED_MASK;
  
  rPaintRankPanel();
}

_Bool checkbox_is_enabled() {
  WM_HWIN func_pg;
  WM_HWIN scroll_pg;
  unsigned int number_pgs;
  unsigned int number_checkbox;
  int multi_pg_val;
  int checkbox_val;
  int rank_pg_y_val;
  int * prev_rank_pg_y_val;
  unsigned int (*sel_inf_arr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  _INIT_MULTI_PG_VALUES(
    multi_pg_val,
    checkbox_val,
    rank_pg_y_val,
    func_pg,
    scroll_pg,
    number_pgs,
    number_checkbox,
    prev_rank_pg_y_val,
    sel_inf_arr
  );
  
  unsigned int disabling_inf_arr[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  create_disabling_rank_inf(
    current_ekran.index_position,
    &disabling_inf_arr,
    MAX_NUM_RANK_PGS,
    NUM_FUNC_TO_INT_BITS
  );
  
  unsigned int multi_pg_val_tmp = multi_pg_val & MASK_MULTI_PG_VAL;
  if (
       _CHECK_RANK_SET_BIT(
         disabling_inf_arr,
         multi_pg_val_tmp,
         checkbox_val
       ) != 0
     )
  {
    return 1;
  } else {
    rank_control_bits |= CHECKBOX_IS_UPDATED_MASK;
    return 0;
  }
}
