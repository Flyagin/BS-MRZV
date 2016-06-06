
#include "gui_header.h"
#include "header_mal.h"

static void fill_arr(int * arr, int start_index, int length, int value) {
  for (int i = start_index; i < length; i++)
    arr[i] = value;
}

void disabling_protections() {
  
  CfgTblDsc* pConfig = &eeprom_prt_tbl;
  
  //все массивы выровнены на длину _ARR_LENGTH для минимизации кол. циклов
  int dstp_const_arr[_ARR_LENGTH] = DSTP_CONST_ARR;
  int drocp_const_arr[_ARR_LENGTH] = DROCP_CONST_ARR;
  int drerth_const_arr[_ARR_LENGTH] = DRERTH_CONST_ARR;
  int nsp_const_arr[_ARR_LENGTH] = NSP_CONST_ARR;
  int umin_const_arr[_ARR_LENGTH] = UMIN_CONST_ARR;
  int umax_const_arr[_ARR_LENGTH] = UMAX_CONST_ARR;
  int rclr_const_arr[_ARR_LENGTH] = RCLR_CONST_ARR;
  int brf_const_arr[_ARR_LENGTH] = BRF_CONST_ARR;
  
  int dstp_di_const_arr[_ARR_LENGTH_DI] = DSTP_DI_CONST_ARR;
  int drocp_di_const_arr[_ARR_LENGTH_DI] = DROCP_DI_CONST_ARR;
  int drerth_di_const_arr[_ARR_LENGTH_DI] = DRERTH_DI_CONST_ARR;
  int nsp_di_const_arr[_ARR_LENGTH_DI] = NSP_DI_CONST_ARR;
  int umin_di_const_arr[_ARR_LENGTH_DI] = UMIN_DI_CONST_ARR;
  int umax_di_const_arr[_ARR_LENGTH_DI] = UMAX_DI_CONST_ARR;
  int rclr_di_const_arr[_ARR_LENGTH_DI] = RCLR_DI_CONST_ARR;
  int brf_di_const_arr[_ARR_LENGTH_DI] = BRF_DI_CONST_ARR;
  
  //не используемые ячейки заполн. знач. -1
  fill_arr(dstp_const_arr, DSTP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(drocp_const_arr, DROCP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(drerth_const_arr, DRERTH_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(nsp_const_arr, NSP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(umin_const_arr, UMIN_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(umax_const_arr, UMAX_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(rclr_const_arr, RCLR_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  fill_arr(brf_const_arr, BRF_ARR_LENGTH, _ARR_LENGTH, _NULL_);
  
  fill_arr(dstp_di_const_arr, DSTP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(drocp_di_const_arr, DROCP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(drerth_di_const_arr, DRERTH_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(nsp_di_const_arr, NSP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(umin_di_const_arr, UMIN_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(umax_di_const_arr, UMAX_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(rclr_di_const_arr, RCLR_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  fill_arr(brf_di_const_arr, BRF_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
  
  for (int i = 0; i < NUM_OUT; i++) {
    for (int j = 0; j < _ARR_LENGTH; j++) {
      _Bool exit = 1;
      int index;
      //Сброс ранжирования для ДЗ на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DSTP_CFG_PRT_ONB) == 0
          && dstp_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + dstp_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для МТЗ на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DROCP_CFG_PRT_ONB) == 0
          && drocp_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + drocp_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для ТЗНП на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DRERTH_CFG_PRT_ONB) == 0
          && drerth_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + drerth_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для ЗОП на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, NSP_CFG_PRT_ONB) == 0
          && nsp_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + nsp_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для ЗНмин на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMIN_CFG_PRT_ONB) == 0
          && umin_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + umin_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для ЗНмакс на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMAX_CFG_PRT_ONB) == 0
          && umax_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + umax_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для АПВ на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, RCLR_CFG_PRT_ONB) == 0
          && rclr_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + rclr_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      //Сброс ранжирования для УРОВ на дискр. вых., св.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, BRF_CFG_PRT_ONB) == 0
          && brf_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_OEPRF_ONB + brf_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_do_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_led_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_pl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_mn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_df1_blk_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        if (i < NUM_TRG) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_setMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstPl_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_trg_rstMn_rank_cfg, RESERV_MAX_OEPRF_ONB, index);
        }
        if (i == 0) {
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_AReccfg, RESERV_MAX_OEPRF_ONB, index);
          _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_DReccfg, RESERV_MAX_OEPRF_ONB, index);
        }
      }
      
      if (exit) break;
    }
  }
  
  for (int i = 0; i < NUM_IN; i++) {
    for (int j = 0; j < _ARR_LENGTH_DI; j++) {
      _Bool exit = 1;
      int index;
      //Сброс ранжирования для ДЗ на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DSTP_CFG_PRT_ONB) == 0
          && dstp_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + dstp_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для МТЗ на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DROCP_CFG_PRT_ONB) == 0
          && drocp_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + drocp_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для ТЗНП на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DRERTH_CFG_PRT_ONB) == 0
          && drerth_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + drerth_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для ЗОП на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, NSP_CFG_PRT_ONB) == 0
          && nsp_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + nsp_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для ЗНмин на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMIN_CFG_PRT_ONB) == 0
          && umin_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + umin_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для ЗНмакс на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMAX_CFG_PRT_ONB) == 0
          && umax_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + umax_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для АПВ на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, RCLR_CFG_PRT_ONB) == 0
          && rclr_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + rclr_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      //Сброс ранжирования для УРОВ на дискр. вх.
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, BRF_CFG_PRT_ONB) == 0
          && brf_di_const_arr[j] != _NULL_) {
        exit = 0;
        index = i * RESERV_MAX_IEPRF_ONB + brf_di_const_arr[j];
        _CLEAR_BIT_RANK_UCHAR(pConfig -> uc_ar_di_rank_cfg, RESERV_MAX_IEPRF_ONB, index);
      }
      
      if (exit) break;
    }
  }
  
  /***************/
  //Відключення панелей параметрування захистів
  /***************/
  if (Settings_IconView != WM_UNATTACHED)
  {
    for (unsigned int i = 2; i < (2 + RESERV_CFG_PRT_ONB); i++) 
    {     
      const GUI_BITMAP *pBitmap;
      if (_CHECK_BIT_UCHAR(pConfig->arUchCfgPrt, (i - 2))) pBitmap = _aBitmapItem_settings[i].pBitmap;
      else
      {
        pBitmap = pBitmaps_prt_off[i - 2];
      }
      ICONVIEW_SetBitmapItem(Settings_IconView, i, pBitmap);
    }
    start_gui_exec = 1;
  }
  /***************/
  
}
