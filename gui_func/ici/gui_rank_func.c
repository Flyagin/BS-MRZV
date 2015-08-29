
#include "header_mal.h"

extern unsigned int doLedDfDtArDr_id_list[NUM_DO_FUNCS];

static const unsigned int di_rank_constants[NUM_DI_FUNCS] = {
  HVSW_ON_DI_IEPRF_ONB,           HVSW_OFF_DI_IEPRF_ONB,         CTRL_VKL_DI_IEPRF_ONB,
  CTRL_OTKL_DI_IEPRF_ONB,         RESET_SIGOUT_DI_IEPRF_ONB,     RESET_LED_DI_IEPRF_ONB,
  BLOCK_SWITCHOVER_DI_IEPRF_ONB,  SWITCH_STATE_DI_IEPRF_ONB,     PERMIT_BLK_SW_MCP_DI_IEPRF_ONB,
  EDF01_DI_IEPRF_ONB,             EDF02_DI_IEPRF_ONB,            EDF03_DI_IEPRF_ONB,
  EDF04_DI_IEPRF_ONB,             EDF05_DI_IEPRF_ONB,            EDF06_DI_IEPRF_ONB,
  EDF07_DI_IEPRF_ONB,             EDF08_DI_IEPRF_ONB,            EDF09_DI_IEPRF_ONB,
  EDF10_DI_IEPRF_ONB,             EDF11_DI_IEPRF_ONB,            EDF12_DI_IEPRF_ONB,
  EDF13_DI_IEPRF_ONB,             EDF14_DI_IEPRF_ONB,            EDF15_DI_IEPRF_ONB,
  EDF16_DI_IEPRF_ONB,             SET_OT1_DI_IEPRF_ONB,          RESET_OT1_DI_IEPRF_ONB,
  SET_OT2_DI_IEPRF_ONB,           RESET_OT2_DI_IEPRF_ONB,        SET_OT3_DI_IEPRF_ONB,
  RESET_OT3_DI_IEPRF_ONB,         SET_OT4_DI_IEPRF_ONB,          RESET_OT4_DI_IEPRF_ONB,
  SET_OT5_DI_IEPRF_ONB,           RESET_OT5_DI_IEPRF_ONB,        SET_OT6_DI_IEPRF_ONB,
  RESET_OT6_DI_IEPRF_ONB,         SET_OT7_DI_IEPRF_ONB,          RESET_OT7_DI_IEPRF_ONB,
  SET_OT8_DI_IEPRF_ONB,           RESET_OT8_DI_IEPRF_ONB,        BLOCK_DSTP1_DI_IEPRF_ONB,
  BLOCK_DSTP2_DI_IEPRF_ONB,       ACCLT_DSTP2_DI_IEPRF_ONB,      BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB,
  BLOCK_DSTP3_DI_IEPRF_ONB,       ACCLT_DSTP3_DI_IEPRF_ONB,      BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB,
  BLOCK_DSTP4_DI_IEPRF_ONB,       ACCLT_DSTP4_DI_IEPRF_ONB,      BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB,
  BLOCK_DSTP5_DI_IEPRF_ONB,       ACCLT_DSTP5_DI_IEPRF_ONB,      BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB,
  SEC_GR_UST_DSTP_DI_IEPRF_ONB,   BLOCK_MCP1_DI_IEPRF_ONB,       BLOCK_MCP2_DI_IEPRF_ONB,
  BLOCK_MCP3_DI_IEPRF_ONB,        BLOCK_MCP4_DI_IEPRF_ONB,       BLOCK_MCP5_DI_IEPRF_ONB,
  ACCLT_MCP2_DI_IEPRF_ONB,        BLOCK_ACCLT_MCP2_DI_IEPRF_ONB, ACCLT_MCP3_DI_IEPRF_ONB,
  BLOCK_ACCLT_MCP3_DI_IEPRF_ONB,  ACCLT_MCP4_DI_IEPRF_ONB,       BLOCK_ACCLT_MCP4_DI_IEPRF_ONB,
  ACCLT_MCP5_DI_IEPRF_ONB,        BLOCK_ACCLT_MCP5_DI_IEPRF_ONB,
  SEC_GR_UST_MCP_DI_IEPRF_ONB,    START_AFU_DI_IEPRF_ONB,        BLOCK_AFU_DI_IEPRF_ONB,
  BLOCK_UMIN1_DI_IEPRF_ONB,       START_UMIN1_DI_IEPRF_ONB,      BLOCK_UMIN2_DI_IEPRF_ONB,
  START_UMIN2_DI_IEPRF_ONB,       BLOCK_TZNP1_DI_IEPRF_ONB,      ACCLT_TZNP1_DI_IEPRF_ONB,
  BLOCK_ACCLT_TZNP1_DI_IEPRF_ONB, BLOCK_TZNP2_DI_IEPRF_ONB,      ACCLT_TZNP2_DI_IEPRF_ONB,
  BLOCK_ACCLT_TZNP2_DI_IEPRF_ONB, BLOCK_TZNP3_DI_IEPRF_ONB,      ACCLT_TZNP3_DI_IEPRF_ONB,
  BLOCK_ACCLT_TZNP3_DI_IEPRF_ONB, BLOCK_TZNP4_DI_IEPRF_ONB,      ACCLT_TZNP4_DI_IEPRF_ONB,
  BLOCK_ACCLT_TZNP4_DI_IEPRF_ONB, BLOCK_TZNP5_DI_IEPRF_ONB,      ACCLT_TZNP5_DI_IEPRF_ONB,
  BLOCK_ACCLT_TZNP5_DI_IEPRF_ONB, BLOCK_ZOP1_DI_IEPRF_ONB,       BLOCK_ZOP2_DI_IEPRF_ONB,
  SEC_GR_UST_ZOP_DI_IEPRF_ONB,    START_UROV_DI_IEPRF_ONB,       BLOCK_UMAX1_DI_IEPRF_ONB,
  BLOCK_UMAX2_DI_IEPRF_ONB
};

static const unsigned int doLedTrgArDr_rank_constants[NUM_DO_FUNCS] = {
  HVSW_ON_DI_OEPRF_ONB,                 HVSW_OFF_DI_OEPRF_ONB,                CTRL_VKL_DI_OEPRF_ONB,                CTRL_OTKL_DI_OEPRF_ONB,
  RESET_SIGOUT_DI_OEPRF_ONB,            RESET_LED_DI_OEPRF_ONB,               BLOCK_SWITCHOVER_DI_OEPRF_ONB,        SWITCH_STATE_DI_OEPRF_ONB,
  PERMIT_BLK_SW_MCP_DI_OEPRF_ONB,       DRIVER_SW_DI_OEPRF_ONB,               FLT_U_DSTP_OEPRF_ONB,                 OVER_I_NOM_OFF_HSW_OEPRF_ONB,
  LIMIT_OUT_HWS,                        LIMIT_CRITICAL_HWS,                   SW_OFF_CMDF_ONB,                      SW_ON_CMDF_ONB,
  EDF01_OEPRF_ONB,                      EDF02_OEPRF_ONB,
  EDF03_OEPRF_ONB,                      EDF04_OEPRF_ONB,                      EDF05_OEPRF_ONB,                      EDF06_OEPRF_ONB,
  EDF07_OEPRF_ONB,                      EDF08_OEPRF_ONB,                      EDF09_OEPRF_ONB,                      EDF10_OEPRF_ONB,
  EDF11_OEPRF_ONB,                      EDF12_OEPRF_ONB,                      EDF13_OEPRF_ONB,                      EDF14_OEPRF_ONB,
  EDF15_OEPRF_ONB,                      EDF16_OEPRF_ONB,                      OUT_OT1_OEPRF_ONB,                    OUT_OT2_OEPRF_ONB,
  OUT_OT3_OEPRF_ONB,                    OUT_OT4_OEPRF_ONB,                    OUT_OT5_OEPRF_ONB,                    OUT_OT6_OEPRF_ONB,
  OUT_OT7_OEPRF_ONB,                    OUT_OT8_OEPRF_ONB,                    BLOCK_DSTP1_DI_OEPRF_ONB,
  
  STPDEV_DSTP1_MF_OEPRF_ONB,
  DSTP1_MF_OEPRF_ONB,
  STPDEV_MCP_DSTP1_OEPRF_ONB,
  MCP_DSTP1_OEPRF_ONB,
  STPDEV_DSTP1_OF_OEPRF_ONB,
  DSTP1_OF_OEPRF_ONB,
  
  BLOCK_DSTP2_DI_OEPRF_ONB,
  
  DSTP2_MF_OEPRF_ONB,
  STPDEV_DSTP2_MF_OEPRF_ONB,
  MCP_DSTP2_OEPRF_ONB,
  STPDEV_MCP_DSTP2_OEPRF_ONB,
  DSTP2_OF_OEPRF_ONB,
  STPDEV_DSTP2_OF_OEPRF_ONB,
  
  ACCLT_DSTP2_DI_OEPRF_ONB,             ACCLT_DSTP2_EPI_OEPRF_ONB,
  BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB,       BLOCK_DSTP3_DI_OEPRF_ONB,
  
  DSTP3_MF_OEPRF_ONB,
  STPDEV_DSTP3_MF_OEPRF_ONB,
  MCP_DSTP3_OEPRF_ONB,
  STPDEV_MCP_DSTP3_OEPRF_ONB,
  DSTP3_OF_OEPRF_ONB,
  STPDEV_DSTP3_OF_OEPRF_ONB,
  
  ACCLT_DSTP3_DI_OEPRF_ONB,             ACCLT_DSTP3_EPI_OEPRF_ONB,
  BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB,       BLOCK_DSTP4_DI_OEPRF_ONB,
  
  DSTP4_MF_OEPRF_ONB,
  STPDEV_DSTP4_MF_OEPRF_ONB,
  MCP_DSTP4_OEPRF_ONB,
  STPDEV_MCP_DSTP4_OEPRF_ONB,
  DSTP4_OF_OEPRF_ONB,
  STPDEV_DSTP4_OF_OEPRF_ONB,
  
  ACCLT_DSTP4_DI_OEPRF_ONB,             ACCLT_DSTP4_EPI_OEPRF_ONB,
  BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB,       BLOCK_DSTP5_DI_OEPRF_ONB,
  
  DSTP5_MF_OEPRF_ONB,
  STPDEV_DSTP5_MF_OEPRF_ONB,
  MCP_DSTP5_OEPRF_ONB,
  STPDEV_MCP_DSTP5_OEPRF_ONB,
  DSTP5_OF_OEPRF_ONB,
  STPDEV_DSTP5_OF_OEPRF_ONB,
  
  ACCLT_DSTP5_DI_OEPRF_ONB,             ACCLT_DSTP5_EPI_OEPRF_ONB,
  BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB,       SEC_GR_UST_DSTP_DI_OEPRF_ONB,
  BLOCK_MCP1_DI_OEPRF_ONB,              BLOCK_MCP2_DI_OEPRF_ONB,              BLOCK_MCP3_DI_OEPRF_ONB,              BLOCK_MCP4_DI_OEPRF_ONB,
  BLOCK_MCP5_DI_OEPRF_ONB,
  ACCLT_MCP2_EPI_OEPRF_ONB,             ACCLT_MCP2_DI_OEPRF_ONB,              BLOCK_ACCLT_MCP2_DI_OEPRF_ONB,        ACCLT_MCP3_EPI_OEPRF_ONB,
  ACCLT_MCP3_DI_OEPRF_ONB,              BLOCK_ACCLT_MCP3_DI_OEPRF_ONB,        ACCLT_MCP4_EPI_OEPRF_ONB,             ACCLT_MCP4_DI_OEPRF_ONB,
  BLOCK_ACCLT_MCP4_DI_OEPRF_ONB,        ACCLT_MCP5_EPI_OEPRF_ONB,             ACCLT_MCP5_DI_OEPRF_ONB,              BLOCK_ACCLT_MCP5_DI_OEPRF_ONB,
  SEC_GR_UST_MCP_DI_OEPRF_ONB,          STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB,
  STPDEV_MCP1_BORING_OEPRF_ONB,         STPDEV_MCP1_STAIGHT_OEPRF_ONB,        STPDEV_MCP1_BACK_OEPRF_ONB,           STPDEV_MCP1_VLT_OEPRF_ONB,
  MCP1_OEPRF_ONB,                       STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB,    STPDEV_MCP2_BORING_OEPRF_ONB,
  STPDEV_MCP2_STAIGHT_OEPRF_ONB,        STPDEV_MCP2_BACK_OEPRF_ONB,           STPDEV_MCP2_VLT_OEPRF_ONB,            MCP2_OEPRF_ONB,
  STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB,    STPDEV_MCP3_BORING_OEPRF_ONB,         STPDEV_MCP3_STAIGHT_OEPRF_ONB,
  STPDEV_MCP3_BACK_OEPRF_ONB,           STPDEV_MCP3_VLT_OEPRF_ONB,            MCP3_OEPRF_ONB,                       STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB,
  STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB,    STPDEV_MCP4_BORING_OEPRF_ONB,         STPDEV_MCP4_STAIGHT_OEPRF_ONB,        STPDEV_MCP4_BACK_OEPRF_ONB,
  STPDEV_MCP4_VLT_OEPRF_ONB,            MCP4_OEPRF_ONB,                       STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB,
  STPDEV_MCP5_BORING_OEPRF_ONB,         STPDEV_MCP5_STAIGHT_OEPRF_ONB,        STPDEV_MCP5_BACK_OEPRF_ONB,           STPDEV_MCP5_VLT_OEPRF_ONB,
  MCP5_OEPRF_ONB,                       START_AFU_DI_OEPRF_ONB,               BLOCK_AFU_DI_OEPRF_ONB,               ARCL1_OEPRF_ONB,
  ARCL2_OEPRF_ONB,                      BLOCK_UMIN1_DI_OEPRF_ONB,             START_UMIN1_DI_OEPRF_ONB,             BLOCK_UMIN2_DI_OEPRF_ONB,
  START_UMIN2_DI_OEPRF_ONB,             STPDEV_UMIN1_OEPRF_ONB,               UMIN1_OEPRF_ONB,                      STPDEV_UMIN2_OEPRF_ONB,
  UMIN2_OEPRF_ONB,                      BLOCK_TZNP1_DI_OEPRF_ONB,             ACCLT_TZNP1_DI_OEPRF_ONB,             BLOCK_ACCLT_TZNP1_DI_OEPRF_ONB,
  BLOCK_TZNP2_DI_OEPRF_ONB,             ACCLT_TZNP2_DI_OEPRF_ONB,             BLOCK_ACCLT_TZNP2_DI_OEPRF_ONB,       BLOCK_TZNP3_DI_OEPRF_ONB,
  ACCLT_TZNP3_DI_OEPRF_ONB,             BLOCK_ACCLT_TZNP3_DI_OEPRF_ONB,       BLOCK_TZNP4_DI_OEPRF_ONB,             ACCLT_TZNP4_DI_OEPRF_ONB,
  BLOCK_ACCLT_TZNP4_DI_OEPRF_ONB,       BLOCK_TZNP5_DI_OEPRF_ONB,             ACCLT_TZNP5_DI_OEPRF_ONB,             BLOCK_ACCLT_TZNP5_DI_OEPRF_ONB,
  ACCLT_TZNP1_EPI_OEPRF_ONB,            ACCLT_TZNP2_EPI_OEPRF_ONB,            ACCLT_TZNP3_EPI_OEPRF_ONB,            ACCLT_TZNP4_EPI_OEPRF_ONB,
  ACCLT_TZNP5_EPI_OEPRF_ONB,
  STPDEV_SECTOR_TZNP1_OEPRF_ONB,        STPDEV_TZNP1_OEPRF_ONB,               TZNP1_OEPRF_ONB,                      STPDEV_TZNP1_3U0_OEPRF_ONB,
  TZNP1__3U0_OEPRF_ONB,                 STPDEV_TZNP1_3I0_OEPRF_ONB,           TZNP1_3I0_OEPRF_ONB,                  STPDEV_SECTOR_TZNP2_OEPRF_ONB,
  STPDEV_TZNP2_OEPRF_ONB,               TZNP2_OEPRF_ONB,                      STPDEV_TZNP2_3U0_OEPRF_ONB,           TZNP2_3U0_OEPRF_ONB,
  STPDEV_TZNP2_3I0_OEPRF_ONB,           TZNP2_3I0_OEPRF_ONB,                  STPDEV_SECTOR_TZNP3_OEPRF_ONB,        STPDEV_TZNP3_OEPRF_ONB,
  TZNP3_OEPRF_ONB,                      STPDEV_TZNP3_3U0_OEPRF_ONB,           TZNP3_3U0_OEPRF_ONB,                  STPDEV_TZNP3_3I0_OEPRF_ONB,
  TZNP3_3I0_OEPRF_ONB,                  STPDEV_SECTOR_TZNP4_OEPRF_ONB,        STPDEV_TZNP4_OEPRF_ONB,               TZNP4_OEPRF_ONB,
  STPDEV_TZNP4_3U0_OEPRF_ONB,           TZNP4_3U0_OEPRF_ONB,                  STPDEV_TZNP4_3I0_OEPRF_ONB,           TZNP4_3I0_OEPRF_ONB,
  STPDEV_SECTOR_TZNP5_OEPRF_ONB,        STPDEV_TZNP5_OEPRF_ONB,               TZNP5_OEPRF_ONB,                      STPDEV_TZNP5_3U0_OEPRF_ONB,
  TZNP5_3U0_OEPRF_ONB,                  STPDEV_TZNP5_3I0_OEPRF_ONB,           TZNP5_3I0_OEPRF_ONB,                  BLOCK_ZOP1_DI_OEPRF_ONB,
  BLOCK_ZOP2_DI_OEPRF_ONB,              SEC_GR_UST_ZOP_DI_OEPRF_ONB,          STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB,
  STPDEV_ZOP1_BORING_OEPRF_ONB,         STPDEV_ZOP1_STAIGHT_OEPRF_ONB,        STPDEV_ZOP1_BACK_OEPRF_ONB,           ZOP1_OEPRF_ONB,
  STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB,    STPDEV_ZOP2_BORING_OEPRF_ONB,         STPDEV_ZOP2_STAIGHT_OEPRF_ONB,
  STPDEV_ZOP2_BACK_OEPRF_ONB,           ZOP2_OEPRF_ONB,                       START_UROV_DI_OEPRF_ONB,              UROV1_OEPRF_ONB,
  UROV2_OEPRF_ONB,                      BLOCK_UMAX1_DI_OEPRF_ONB,             BLOCK_UMAX2_DI_OEPRF_ONB,             STPDEV_UMAX1_OEPRF_ONB,
  UMAX1_OEPRF_ONB,                      STPDEV_UMAX2_OEPRF_ONB,               UMAX2_OEPRF_ONB
};

static const unsigned int f_rank_constants[NUM_F_FUNCS] = {
  HVSW_ON_DI_F_EPRF_ONB,
  HVSW_OFF_DI_F_EPRF_ONB,
  RESET_SIGOUT_DI_F_EPRF_ONB,
  RESET_LED_DI_F_EPRF_ONB,
  EDF01_DI_F_EPRF_ONB,
  EDF02_DI_F_EPRF_ONB,
  EDF03_DI_F_EPRF_ONB,
  EDF04_DI_F_EPRF_ONB,
  EDF05_DI_F_EPRF_ONB,
  EDF06_DI_F_EPRF_ONB,
  EDF07_DI_F_EPRF_ONB,
  EDF08_DI_F_EPRF_ONB,
  EDF09_DI_F_EPRF_ONB,
  EDF10_DI_F_EPRF_ONB,
  EDF11_DI_F_EPRF_ONB,
  EDF12_DI_F_EPRF_ONB,
  EDF13_DI_F_EPRF_ONB,
  EDF14_DI_F_EPRF_ONB,
  EDF15_DI_F_EPRF_ONB,
  EDF16_DI_F_EPRF_ONB,
  SET_OT1_DI_F_EPRF_ONB,
  RESET_OT1_DI_F_EPRF_ONB,
  SET_OT2_DI_F_EPRF_ONB,
  RESET_OT2_DI_F_EPRF_ONB,
  SET_OT3_DI_F_EPRF_ONB,
  RESET_OT3_DI_F_EPRF_ONB,
  SET_OT4_DI_F_EPRF_ONB,
  RESET_OT4_DI_F_EPRF_ONB,
  SET_OT5_DI_F_EPRF_ONB,
  RESET_OT5_DI_F_EPRF_ONB,
  SET_OT6_DI_F_EPRF_ONB,
  RESET_OT6_DI_F_EPRF_ONB,
  SET_OT7_DI_F_EPRF_ONB,
  RESET_OT7_DI_F_EPRF_ONB,
  SET_OT8_DI_F_EPRF_ONB,
  RESET_OT8_DI_F_EPRF_ONB
};

_Bool checkAllRankVal() {
  return durationDIIsCorrect()
    && timerDelayDFIsCorrect()
    && timerWorkDFIsCorrect()
    && timePreFaultAnRecIsCorrect()
    && timePostFaultAnRecIsCorrect();
}

int numToExternalRankFuncs(int index_position) {
  switch(index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      return NUM_DI_FUNCS;
    case ID_RANK_DISCRETE_OUTPUT_PG:
      return NUM_DO_FUNCS;
    case ID_RANK_LED_PG:
      return NUM_LED_FUNCS;
    case ID_RANK_DF_PLUS_PG:
    case ID_RANK_DF_MINUS_PG:
    case ID_RANK_DF_BLK_PG:
      return NUM_DF_FUNCS;
    case ID_RANK_F_PG:
      return NUM_F_FUNCS;
    case ID_RANK_TRG_SET_PL_PG:
    case ID_RANK_TRG_SET_MN_PG:
    case ID_RANK_TRG_RST_PL_PG:
    case ID_RANK_TRG_RST_MN_PG:
      return NUM_TRG_FUNCS;
    case ID_RANK_AN_DIG_REC_PG:
      return NUM_AN_DIG_REC_FUNCS;
    default:while(1);
  }
}

int numToInternalRankFuncs(int index_position) {
  switch(index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      return RESERV_MAX_IEPRF_ONB;
    case ID_RANK_DISCRETE_OUTPUT_PG:
    case ID_RANK_LED_PG:
    case ID_RANK_DF_PLUS_PG:
    case ID_RANK_DF_MINUS_PG:
    case ID_RANK_DF_BLK_PG:
    case ID_RANK_TRG_SET_PL_PG:
    case ID_RANK_TRG_SET_MN_PG:
    case ID_RANK_TRG_RST_PL_PG:
    case ID_RANK_TRG_RST_MN_PG:
    case ID_RANK_AN_DIG_REC_PG:
      return RESERV_MAX_OEPRF_ONB;
    case ID_RANK_F_PG:
      return RESERV_MAX_F_EPRF_ONB;
    default:while(1);
  }
}

static void fill_arr(int * arr, int start_index, int length, int value) {
  for (int i = start_index; i < length; i++)
    arr[i] = value;
}

static void cleanTwoDimensionalArr(
  unsigned int (*arr_p)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      (*arr_p)[i][j] = 0;
    }
  }
}

//сдвигает массив на указанное кол. бит вправо
static void bitShiftR(unsigned char * resArr, unsigned char * sourceArr, int bit, int size) {
  unsigned char mask = 0;
  unsigned char tmp = 0;
  for (int i = 0; i < bit; i++) mask |= (1 << i);
  for (int i = size - 1; i >= 0; i--) {
    resArr[i] = (sourceArr[i] >> bit) | tmp;
    tmp = (sourceArr[i] & mask) << (8 - bit);
  }
}

static void bitShiftL(
  unsigned int (*resArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  unsigned int (*sourceArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  int numPgs, int numBytes, int bit) {
  unsigned int mask = 0;
  unsigned int mask_tmp = 0;
  unsigned int tmp = 0;
  int numInts = ((numBytes - 1) >> 2) + 1;
  for (int i = 32 - 1; i >= 32 - bit; i--) mask |= (1 << i);
  for (int i = 0; i < bit; i++) mask_tmp |= (1 << i);
  for (int i = 0; i < numPgs; i++) {
    for (int j = 0; j < numInts; j++) {
      if (j == 0) {
        //(resArr[i] & mask_tmp) - чтобы не задеть зарезервированные биты
        (*resArr)[i][j] = ((*resArr)[i][j] & mask_tmp) | ((*sourceArr)[i][j] << bit);
      } else {
        (*resArr)[i][j] = ((*sourceArr)[i][j] << bit) | tmp;
      }
      tmp = ((*sourceArr)[i][j] & mask) >> (32 - bit);
    }
  }
}

static int convert_rank_index(int index, int current_ekran_index_position) {
  switch (current_ekran_index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      return di_rank_constants[index] - RANK_DI_OFFSET;
    case ID_RANK_LED_PG:
    case ID_RANK_DISCRETE_OUTPUT_PG:
    case ID_RANK_DF_PLUS_PG:
    case ID_RANK_DF_MINUS_PG:
    case ID_RANK_DF_BLK_PG:
    case ID_RANK_TRG_SET_PL_PG:
    case ID_RANK_TRG_SET_MN_PG:
    case ID_RANK_TRG_RST_PL_PG:
    case ID_RANK_TRG_RST_MN_PG:
    case ID_RANK_AN_DIG_REC_PG:
      return doLedTrgArDr_rank_constants[index] - RANK_DO_OFFSET;
    case ID_RANK_F_PG:
      return f_rank_constants[index] - RANK_F_OFFSET;
    default:
      return -1;
  }
}

static void convert_from_external_rank_arr(
  unsigned int (*destArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  unsigned int (*srcArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  int num_pgs, int num_func, int current_ekran_index_position) {
  for (int i = 0; i < num_pgs; i++) {
    for (int j = 0; j < num_func; j++) {
      int convert_index = convert_rank_index(j, current_ekran_index_position);
      if (_CHECK_RANK_SET_BIT_P(srcArr, i, convert_index) != 0) {
        _SET_RANK_BIT_P(destArr, i, j);
      } else {
        _CLEAR_RANK_BIT_P(destArr, i, j);
      }
    }
  }
}

static void convert_to_external_rank_arr(
  unsigned int (*destArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  unsigned int (*srcArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS],
  int num_pgs, int num_func, int current_ekran_index_position) {
  for (int i = 0; i < num_pgs; i++) {
    for (int j = 0; j < num_func; j++) {
      int convert_index = convert_rank_index(j, current_ekran_index_position);
      if (_CHECK_RANK_SET_BIT_P(srcArr, i, j) != 0) {
        _SET_RANK_BIT_P(destArr, i, convert_index);
      } else {
        _CLEAR_RANK_BIT_P(destArr, i, convert_index);
      }
    }
  }
}

static void copy_additional_rank_settings_to_buff(CfgTblDsc * pConfig, int current_ekran_index_position) {
  switch (current_ekran_index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      {
        for (int i = 0; i < (NUM_IN >> 3); i++) {
          diTypeSignal[i] = pConfig -> arUchTypeSignal[i];
          diTypeInput[i] = pConfig -> arUchTypeInput[i];
        }
        for (int i = 0; i < NUM_IN; i++) {
          durationDI[i] = pConfig -> ushDurationDI[i];
        }
        break;
      }
    case ID_RANK_DISCRETE_OUTPUT_PG:
      {
        for (int i = 0; i < (NUM_OUT >> 3); i++) {
          doTypeOutputs[i] = pConfig -> arUchTypeOuts[i];
        }
        break;
      }
    case ID_RANK_LED_PG:
      {
        for (int i = 0; i < (NUM_LED >> 3); i++) {
          ledsType[i] = pConfig -> arUchTypeLeds[i];
        }
        break;
      }
    case ID_RANK_DF_PLUS_PG:
    case ID_RANK_DF_MINUS_PG:
    case ID_RANK_DF_BLK_PG:
      {
        for (int i = 0; i < NUM_DEF_FUN; i++) {
          tmrDelayDF[i] = pConfig -> ownrOFunc.ul_ar_time_delay_df[i];
          tmrWorkDF[i] = pConfig -> ownrOFunc.ul_ar_duration_df[i];
          typeDF[i] = pConfig -> ownrOFunc.uch_ar_type_df[i];
        }
        break;
      }
    case ID_RANK_AN_DIG_REC_PG:
      {
//        timePreFaultArrVal = ;
//        timePostFaultArrVal = ;
        break;
      }
    case ID_RANK_F_PG:
    case ID_RANK_TRG_SET_PL_PG:
    case ID_RANK_TRG_SET_MN_PG:
    case ID_RANK_TRG_RST_PL_PG:
    case ID_RANK_TRG_RST_MN_PG:
    default: break;
  }
}

static void copy_additional_rank_settings_from_buff(CfgTblDsc * pConfig, int current_ekran_index_position) {
  switch (current_ekran_index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      {
        for (int i = 0; i < (NUM_IN >> 3); i++) {
          pConfig -> arUchTypeSignal[i] = diTypeSignal[i];
          pConfig -> arUchTypeInput[i] = diTypeInput[i];
        }
        for (int i = 0; i < NUM_IN; i++) {
          pConfig -> ushDurationDI[i] = durationDI[i];
        }
        break;
      }
    case ID_RANK_DISCRETE_OUTPUT_PG:
      {
        for (int i = 0; i < (NUM_OUT >> 3); i++) {
          pConfig -> arUchTypeOuts[i] = doTypeOutputs[i];
        }
        break;
      }
    case ID_RANK_LED_PG:
      {
        for (int i = 0; i < (NUM_OUT >> 3); i++) {
          pConfig -> arUchTypeLeds[i] = ledsType[i];
        }
        break;
      }
    case ID_RANK_DF_PLUS_PG:
    case ID_RANK_DF_MINUS_PG:
    case ID_RANK_DF_BLK_PG:
      {
        for (int i = 0; i < NUM_DEF_FUN; i++) {
          pConfig -> ownrOFunc.ul_ar_time_delay_df[i] = tmrDelayDF[i];
          pConfig -> ownrOFunc.ul_ar_duration_df[i] = tmrWorkDF[i];
          pConfig -> ownrOFunc.uch_ar_type_df[i] = typeDF[i];
        }
        break;
      }
    case ID_RANK_AN_DIG_REC_PG:
      {
//        = timePreFaultArrVal;
//        = timePostFaultArrVal;
        break;
      }
    case ID_RANK_F_PG:
    case ID_RANK_TRG_SET_PL_PG:
    case ID_RANK_TRG_SET_MN_PG:
    case ID_RANK_TRG_RST_PL_PG:
    case ID_RANK_TRG_RST_MN_PG:
    default: break;
  }
}

void create_disabling_rank_inf(int index_position, unsigned int (*pArr)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS], int height, int width) {
  
  unsigned int fill_value = 0xffffffff;
  
  _Bool workBO = 0;
  _Bool workBV = 0;
  int indexPosWorkBO = 0;
  int indexPosWorkBV = 0;
  
  int numBitWorkBO;
  CONVERT_RANK_INDEX(doLedDfDtArDr_id_list, NUM_DO_FUNCS, GUI_ID_BIT_SW_OFF_CMDF_ONB, numBitWorkBO);
  int numBitWorkBV;
  CONVERT_RANK_INDEX(doLedDfDtArDr_id_list, NUM_DO_FUNCS, GUI_ID_BIT_SW_ON_CMDF_ONB, numBitWorkBV);
  
  int num_pg;
  
  unsigned int (*pBuff)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  
  switch (current_ekran.index_position) {
    case ID_RANK_DISCRETE_INPUT_PG:
      {
        num_pg = ignore_hbit(di_index);
        break;
      }
    case ID_RANK_DISCRETE_OUTPUT_PG:
      {
        pBuff = &checkbox_do_sel_inf_arr;
        num_pg = ignore_hbit(do_index);
        break;
      }
    case ID_RANK_LED_PG:
      {
        pBuff = &checkbox_led_sel_inf_arr;
        num_pg = ignore_hbit(led_index);
        break;
      }
    case ID_RANK_DF_PLUS_PG:
      {
        pBuff = &checkbox_df_plus_sel_inf_arr;
        num_pg = ignore_hbit(df_plus_index);
        break;
      }
    case ID_RANK_DF_MINUS_PG:
      {
        pBuff = &checkbox_df_minus_sel_inf_arr;
        num_pg = ignore_hbit(df_minus_index);
        break;
      }
    case ID_RANK_DF_BLK_PG:
      {
        pBuff = &checkbox_df_blk_sel_inf_arr;
        num_pg = ignore_hbit(df_blk_index);
        break;
      }
    case ID_RANK_TRG_SET_PL_PG:
      {
        pBuff = &checkbox_trg_set_pl_sel_inf_arr;
        num_pg = ignore_hbit(trg_set_pl_index);
        break;
      }
    case ID_RANK_TRG_SET_MN_PG:
      {
        pBuff = &checkbox_trg_set_mn_sel_inf_arr;
        num_pg = ignore_hbit(trg_set_mn_index);
        break;
      }
    case ID_RANK_TRG_RST_PL_PG:
      {
        pBuff = &checkbox_trg_rst_pl_sel_inf_arr;
        num_pg = ignore_hbit(trg_rst_pl_index);
        break;
      }
    case ID_RANK_TRG_RST_MN_PG:
      {
        pBuff = &checkbox_trg_rst_mn_sel_inf_arr;
        num_pg = ignore_hbit(trg_rst_mn_index);
        break;
      }
    case ID_RANK_AN_DIG_REC_PG:
      {
        pBuff = &checkbox_an_dig_rec_sel_inf_arr;
        num_pg = ignore_hbit(an_dig_rec_index);
        break;
      }
    case ID_RANK_F_PG:
    default: break;
  }
  
  /**Активация всех функций*******************/
  for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      (*pArr)[i][j] = fill_value;
    }
  }
  /*********************************************/
  
  /**Проверка активации работы бо и работы бв и снятие активации если нужно*******************/
  for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      (*pArr)[i][j] = fill_value;
      if (current_ekran.index_position != ID_RANK_DISCRETE_INPUT_PG && current_ekran.index_position != ID_RANK_F_PG) {
        if (_CHECK_RANK_SET_BIT_P(pBuff, i, numBitWorkBO) != 0 && !workBO) {
          workBO = 1;
          indexPosWorkBO = i;
        }
        if (_CHECK_RANK_SET_BIT_P(pBuff, i, numBitWorkBV) != 0 && !workBV) {
          workBV = 1;
          indexPosWorkBV = i;
        }
      }
    }
  }
  
  if (workBO || workBV) {
    for (int i = 0; i < height; i++) {
      if (workBO && indexPosWorkBO != i) {
        _CLEAR_RANK_BIT_P(pArr, i, numBitWorkBO);
      }
      if (workBV && indexPosWorkBV != i) {
        _CLEAR_RANK_BIT_P(pArr, i, numBitWorkBV);
      }
    }
  }
  /********************************************************************************************/
  
  /*
    Проверка активации функций относящихся к защитам
    в соответствии с массивом конфигурации
    и снятие активации если нужно
  */
  CfgTblDsc* pConfig = &eeprom_prt_tbl;
  
  if (current_ekran.index_position == ID_RANK_DISCRETE_INPUT_PG) {
    int dstp_di_const_arr[_ARR_LENGTH_DI] = DSTP_DI_CONST_ARR;
    int drocp_di_const_arr[_ARR_LENGTH_DI] = DROCP_DI_CONST_ARR;
    int drerth_di_const_arr[_ARR_LENGTH_DI] = DRERTH_DI_CONST_ARR;
    int nsp_di_const_arr[_ARR_LENGTH_DI] = NSP_DI_CONST_ARR;
    int umin_di_const_arr[_ARR_LENGTH_DI] = UMIN_DI_CONST_ARR;
    int umax_di_const_arr[_ARR_LENGTH_DI] = UMAX_DI_CONST_ARR;
    int rclr_di_const_arr[_ARR_LENGTH_DI] = RCLR_DI_CONST_ARR;
    int brf_di_const_arr[_ARR_LENGTH_DI] = BRF_DI_CONST_ARR;
    
    fill_arr(dstp_di_const_arr, DSTP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(drocp_di_const_arr, DROCP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(drerth_di_const_arr, DRERTH_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(nsp_di_const_arr, NSP_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(umin_di_const_arr, UMIN_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(umax_di_const_arr, UMAX_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(rclr_di_const_arr, RCLR_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    fill_arr(brf_di_const_arr, BRF_DI_ARR_LENGTH, _ARR_LENGTH_DI, _NULL_);
    
    for (int i = 0; i < _ARR_LENGTH_DI; i++) {
      _Bool exit = 1;
      int convert_index;
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DSTP_CFG_PRT_ONB) == 0
          && dstp_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, dstp_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DROCP_CFG_PRT_ONB) == 0
          && drocp_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, drocp_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DRERTH_CFG_PRT_ONB) == 0
          && drerth_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, drerth_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, NSP_CFG_PRT_ONB) == 0
          && nsp_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, nsp_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMIN_CFG_PRT_ONB) == 0
          && umin_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, umin_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMAX_CFG_PRT_ONB) == 0
          && umax_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, umax_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, RCLR_CFG_PRT_ONB) == 0
          && rclr_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, rclr_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, BRF_CFG_PRT_ONB) == 0
          && brf_di_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(di_rank_constants, NUM_DI_FUNCS, brf_di_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      
      if (exit) break;
    }
  } else if (current_ekran.index_position != ID_RANK_F_PG) {
    //все массивы выровнены на длину _ARR_LENGTH для минимизации кол. циклов
    int dstp_const_arr[_ARR_LENGTH] = DSTP_CONST_ARR;
    int drocp_const_arr[_ARR_LENGTH] = DROCP_CONST_ARR;
    int drerth_const_arr[_ARR_LENGTH] = DRERTH_CONST_ARR;
    int nsp_const_arr[_ARR_LENGTH] = NSP_CONST_ARR;
    int umin_const_arr[_ARR_LENGTH] = UMIN_CONST_ARR;
    int umax_const_arr[_ARR_LENGTH] = UMAX_CONST_ARR;
    int rclr_const_arr[_ARR_LENGTH] = RCLR_CONST_ARR;
    int brf_const_arr[_ARR_LENGTH] = BRF_CONST_ARR;
    
    //не используемые ячейки заполн. знач. -1
    fill_arr(dstp_const_arr, DSTP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(drocp_const_arr, DROCP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(drerth_const_arr, DRERTH_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(nsp_const_arr, NSP_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(umin_const_arr, UMIN_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(umax_const_arr, UMAX_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(rclr_const_arr, RCLR_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    fill_arr(brf_const_arr, BRF_ARR_LENGTH, _ARR_LENGTH, _NULL_);
    
    for (int i = 0; i < _ARR_LENGTH; i++) {
      _Bool exit = 1;
      int convert_index;
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DSTP_CFG_PRT_ONB) == 0
          && dstp_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, dstp_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DROCP_CFG_PRT_ONB) == 0
          && drocp_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, drocp_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, DRERTH_CFG_PRT_ONB) == 0
          && drerth_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, drerth_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, NSP_CFG_PRT_ONB) == 0
          && nsp_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, nsp_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMIN_CFG_PRT_ONB) == 0
          && umin_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, umin_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, UMAX_CFG_PRT_ONB) == 0
          && umax_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, umax_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, RCLR_CFG_PRT_ONB) == 0
          && rclr_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, rclr_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      if (_CHECK_BIT_UCHAR(pConfig -> arUchCfgPrt, BRF_CFG_PRT_ONB) == 0
          && brf_const_arr[i] != _NULL_) {
        exit = 0;
        CONVERT_RANK_INDEX(doLedTrgArDr_rank_constants, NUM_DO_FUNCS, brf_const_arr[i], convert_index);
        _CLEAR_RANK_BIT_P(pArr, num_pg, convert_index);
      }
      
      if (exit) break;
    }
  }
  /********************************************************************************************/
  
  /********************************************************************************************/
  /*
    Для Опред. функций отключается возможность ранжирования на самих себя
  */
  if (current_ekran.index_position == ID_RANK_DF_PLUS_PG
      || current_ekran.index_position == ID_RANK_DF_MINUS_PG
      || current_ekran.index_position == ID_RANK_DF_BLK_PG) {
    int df_func_const_id_arr[NUM_DEF_FUN] = {
      GUI_ID_BIT_EDF01_OEPRF_ONB,
      GUI_ID_BIT_EDF02_OEPRF_ONB,
      GUI_ID_BIT_EDF03_OEPRF_ONB,
      GUI_ID_BIT_EDF04_OEPRF_ONB,
      GUI_ID_BIT_EDF05_OEPRF_ONB,
      GUI_ID_BIT_EDF06_OEPRF_ONB,
      GUI_ID_BIT_EDF07_OEPRF_ONB,
      GUI_ID_BIT_EDF08_OEPRF_ONB,
      GUI_ID_BIT_EDF09_OEPRF_ONB,
      GUI_ID_BIT_EDF10_OEPRF_ONB,
      GUI_ID_BIT_EDF11_OEPRF_ONB,
      GUI_ID_BIT_EDF12_OEPRF_ONB,
      GUI_ID_BIT_EDF13_OEPRF_ONB,
      GUI_ID_BIT_EDF14_OEPRF_ONB,
      GUI_ID_BIT_EDF15_OEPRF_ONB,
      GUI_ID_BIT_EDF16_OEPRF_ONB
    };
    
    int convertIndex;
    CONVERT_RANK_INDEX(doLedDfDtArDr_id_list, NUM_DO_FUNCS, df_func_const_id_arr[num_pg], convertIndex);
    _CLEAR_RANK_BIT_P(pArr, num_pg, convertIndex);
  }
  /********************************************************************************************/
  
  /********************************************************************************************/
  /*
    Для Опред. триггеров отключается возможность ранжирования на самих себя
  */
  if (current_ekran.index_position == ID_RANK_TRG_SET_PL_PG
      || current_ekran.index_position == ID_RANK_TRG_SET_MN_PG
      || current_ekran.index_position == ID_RANK_TRG_RST_PL_PG
      || current_ekran.index_position == ID_RANK_TRG_RST_MN_PG) {
    int dt_out_const_id_arr[NUM_TRG] = {
      GUI_ID_BIT_OUT_OT1,
      GUI_ID_BIT_OUT_OT2,
      GUI_ID_BIT_OUT_OT3,
      GUI_ID_BIT_OUT_OT4,
      GUI_ID_BIT_OUT_OT5,
      GUI_ID_BIT_OUT_OT6,
      GUI_ID_BIT_OUT_OT7,
      GUI_ID_BIT_OUT_OT8
    };
    
    int convertIndex;
    CONVERT_RANK_INDEX(doLedDfDtArDr_id_list, NUM_DO_FUNCS, dt_out_const_id_arr[num_pg], convertIndex);
    _CLEAR_RANK_BIT_P(pArr, num_pg, convertIndex);
  }
  /********************************************************************************************/
}

void copy_rank_settings_to_buff() {
  CfgTblDsc* pConfig = &eeprom_prt_tbl;
  unsigned char uc_ar_di_rank_cfg_tmp[NUM_IN * AMOUNT_BYTE_FOR_IEPRF];
  unsigned char uc_ar_do_rank_cfg_tmp[NUM_OUT * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_led_rank_cfg_tmp[NUM_LED * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_df_plus_rank_cfg_tmp[NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_df_minus_rank_cfg_tmp[NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_df_blk_rank_cfg_tmp[NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_trg_setPl_rank_cfg_tmp[NUM_TRG * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_trg_setMn_rank_cfg_tmp[NUM_TRG * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_trg_rstPl_rank_cfg_tmp[NUM_TRG * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_trg_rstMn_rank_cfg_tmp[NUM_TRG * AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_AReccfg_tmp[AMOUNT_BYTE_FOR_OEPRF];
  unsigned char uc_ar_DReccfg_tmp[AMOUNT_BYTE_FOR_OEPRF];
  
  int num_pgs;
  unsigned char * p;
  unsigned char * p2;
  unsigned int (*pBuff)[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  
  unsigned int checkbox_sel_inf_arr_tmp[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
  
  for (int current_ekran_index_position = 0; current_ekran_index_position < MAX_LEVEL_RANK_PG; current_ekran_index_position++) {
    switch (current_ekran_index_position) {
      case ID_RANK_DISCRETE_INPUT_PG:
        {
          //сдвигаем массив знач. дискр. вх. на два бита вправо и записываем результат в uc_ar_di_rank_cfg_tmp
          bitShiftR(uc_ar_di_rank_cfg_tmp, pConfig -> uc_ar_di_rank_cfg, RANK_DI_OFFSET, NUM_IN * AMOUNT_BYTE_FOR_IEPRF); //2 - кол. бит на которые надо сдвинуть массив
          p = uc_ar_di_rank_cfg_tmp;
          pBuff = &checkbox_di_sel_inf_arr;
          num_pgs = NUM_IN;
          break;
        }
      case ID_RANK_DISCRETE_OUTPUT_PG:
        {
          //сдвигаем массив знач. дискр. вых. на два бита вправо и записываем результат в uc_ar_do_rank_cfg_tmp
          bitShiftR(uc_ar_do_rank_cfg_tmp, pConfig -> uc_ar_do_rank_cfg, RANK_DO_OFFSET, NUM_OUT * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_do_rank_cfg_tmp;
          pBuff = &checkbox_do_sel_inf_arr;
          num_pgs = NUM_OUT;
          break;
        }
      case ID_RANK_LED_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_led_rank_cfg_tmp, pConfig -> uc_ar_led_rank_cfg, RANK_LED_OFFSET, NUM_LED * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_led_rank_cfg_tmp;
          pBuff = &checkbox_led_sel_inf_arr;
          num_pgs = NUM_LED;
          break;
        }
      case ID_RANK_DF_PLUS_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_df_plus_rank_cfg_tmp, pConfig -> uc_ar_df1_pl_rank_cfg, RANK_DF_OFFSET, NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_df_plus_rank_cfg_tmp;
          pBuff = &checkbox_df_plus_sel_inf_arr;
          num_pgs = NUM_DEF_FUN;
          break;
        }
      case ID_RANK_DF_MINUS_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_df_minus_rank_cfg_tmp, pConfig -> uc_ar_df1_mn_rank_cfg, RANK_DF_OFFSET, NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_df_minus_rank_cfg_tmp;
          pBuff = &checkbox_df_minus_sel_inf_arr;
          num_pgs = NUM_DEF_FUN;
          break;
        }
      case ID_RANK_DF_BLK_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_df_blk_rank_cfg_tmp, pConfig -> uc_ar_df1_blk_rank_cfg, RANK_DF_OFFSET, NUM_DEF_FUN * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_df_blk_rank_cfg_tmp;
          pBuff = &checkbox_df_blk_sel_inf_arr;
          num_pgs = NUM_DEF_FUN;
          break;
        }
      case ID_RANK_F_PG:
        {
          p = pConfig -> uc_ar_key_rank_cfg;
          pBuff = &checkbox_f_sel_inf_arr;
          num_pgs = NUM_KEY;
          break;
        }
      case ID_RANK_TRG_SET_PL_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_trg_setPl_rank_cfg_tmp, pConfig -> uc_ar_trg_setPl_rank_cfg, RANK_TRG_OFFSET, NUM_TRG * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_trg_setPl_rank_cfg_tmp;
          pBuff = &checkbox_trg_set_pl_sel_inf_arr;
          num_pgs = NUM_TRG;
          break;
        }
      case ID_RANK_TRG_SET_MN_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_trg_setMn_rank_cfg_tmp, pConfig -> uc_ar_trg_setMn_rank_cfg, RANK_TRG_OFFSET, NUM_TRG * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_trg_setMn_rank_cfg_tmp;
          pBuff = &checkbox_trg_set_mn_sel_inf_arr;
          num_pgs = NUM_TRG;
          break;
        }
      case ID_RANK_TRG_RST_PL_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_trg_rstPl_rank_cfg_tmp, pConfig -> uc_ar_trg_rstPl_rank_cfg, RANK_TRG_OFFSET, NUM_TRG * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_trg_rstPl_rank_cfg_tmp;
          pBuff = &checkbox_trg_rst_pl_sel_inf_arr;
          num_pgs = NUM_TRG;
          break;
        }
      case ID_RANK_TRG_RST_MN_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_trg_rstMn_rank_cfg_tmp, pConfig -> uc_ar_trg_rstMn_rank_cfg, RANK_TRG_OFFSET, NUM_TRG * AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_trg_rstMn_rank_cfg_tmp;
          pBuff = &checkbox_trg_rst_mn_sel_inf_arr;
          num_pgs = NUM_TRG;
          break;
        }
      case ID_RANK_AN_DIG_REC_PG:
        {
          //сдвигаем массив знач. светоиндикаторов на два бита вправо и записываем результат в uc_ar_led_rank_cfg_tmp
          bitShiftR(uc_ar_AReccfg_tmp, pConfig -> uc_ar_AReccfg, RANK_AN_DIG_REG_OFFSET, AMOUNT_BYTE_FOR_OEPRF);
          bitShiftR(uc_ar_DReccfg_tmp, pConfig -> uc_ar_DReccfg, RANK_AN_DIG_REG_OFFSET, AMOUNT_BYTE_FOR_OEPRF);
          p = uc_ar_AReccfg_tmp;
          p2 = uc_ar_DReccfg_tmp;
          pBuff = &checkbox_an_dig_rec_sel_inf_arr;
          num_pgs = 2;
          break;
        }
      default:while(1);
    }
    
    //копирование настр. ранжирования
    if (current_ekran_index_position != ID_RANK_AN_DIG_REC_PG) {
      int columnIndex = 0;
      int step = ((numToInternalRankFuncs(current_ekran_index_position) - 1) >> 3) + 1;//кол. байт на одном срезе
      for (int i = 0; i < num_pgs; i++) {
        int k = 0;
        unsigned int shiftVal = 0;
        unsigned int tmp_val = 0;
        for (int j = i * step; j < step * (i + 1); j++) {
          if (k++ < 3) {
            if (j == step * (i + 1) - 1) {
    //          (*pBuff)[i][columnIndex++] = (tmp_val | (p[j] << shiftVal));
              checkbox_sel_inf_arr_tmp[i][columnIndex++] = (tmp_val | (p[j] << shiftVal));
              k = 0;
              shiftVal = 0;
              tmp_val = 0;
            } else {
              tmp_val |= (p[j] << shiftVal);
              shiftVal += 8;
            }
          } else {
    //        (*pBuff)[i][columnIndex++] = (tmp_val | (p[j] << shiftVal));
            checkbox_sel_inf_arr_tmp[i][columnIndex++] = (tmp_val | (p[j] << shiftVal));
            k = 0;
            shiftVal = 0;
            tmp_val = 0;
          }
        }
        columnIndex = 0;
      }
    } else {
      int columnIndex = 0;
      int step = ((numToInternalRankFuncs(current_ekran_index_position) - 1) >> 3) + 1;//кол. байт на одном срезе
      for (int i = 0; i < num_pgs; i++) {
        int k = 0;
        unsigned int shiftVal = 0;
        unsigned int tmp_val = 0;
        for (int j = 0; j < step; j++) {
          if (k++ < 3) {
            if (j == step - 1) {
              checkbox_sel_inf_arr_tmp[i][columnIndex++] = ((i == 0) ? (tmp_val | (p[j] << shiftVal)) : (tmp_val | (p2[j] << shiftVal)));
              k = 0;
              shiftVal = 0;
              tmp_val = 0;
            } else {
              tmp_val |= ((i == 0) ? (p[j] << shiftVal) : (p2[j] << shiftVal));
              shiftVal += 8;
            }
          } else {
            checkbox_sel_inf_arr_tmp[i][columnIndex++] = ((i == 0) ? (tmp_val | (p[j] << shiftVal)) : (tmp_val | (p2[j] << shiftVal)));
            k = 0;
            shiftVal = 0;
            tmp_val = 0;
          }
        }
        columnIndex = 0;
      }
    }
    
    convert_from_external_rank_arr(pBuff, &checkbox_sel_inf_arr_tmp, num_pgs, numToExternalRankFuncs(current_ekran_index_position), current_ekran_index_position);
    
    copy_additional_rank_settings_to_buff(pConfig, current_ekran_index_position);
  }
}

void copy_rank_settings_from_buff() {
  if (checkAllRankVal()) {
    CfgTblDsc* pConfig = &eeprom_prt_tbl;
    
    unsigned int checkbox_sel_inf_arr_tmp[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
    unsigned int checkbox_sel_inf_arr_shiftL_tmp[MAX_NUM_RANK_PGS][NUM_FUNC_TO_INT_BITS];
    
    //копирование настр. ранжирования для дискр. вх. из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_di_sel_inf_arr, NUM_IN, NUM_DI_FUNCS, ID_RANK_DISCRETE_INPUT_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_IN, (((RESERV_MAX_IEPRF_ONB - 1) >> 3) + 1), RANK_DI_OFFSET);
    int columnIndex = 0;
    unsigned char * p = pConfig -> uc_ar_di_rank_cfg;
    int step = ((RESERV_MAX_IEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_IN; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для дискр. вых. из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_do_sel_inf_arr, NUM_OUT, NUM_DO_FUNCS, ID_RANK_DISCRETE_OUTPUT_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_OUT, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_DO_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_do_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_OUT; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для светоиндикаторов из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_led_sel_inf_arr, NUM_LED, NUM_LED_FUNCS, ID_RANK_LED_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_LED, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_LED_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_led_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_LED; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. функ. плюс из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_df_plus_sel_inf_arr, NUM_DEF_FUN, NUM_DF_FUNCS, ID_RANK_DF_PLUS_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_DEF_FUN, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_DF_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_df1_pl_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_DEF_FUN; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. функ. минус из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_df_minus_sel_inf_arr, NUM_DEF_FUN, NUM_DF_FUNCS, ID_RANK_DF_MINUS_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_DEF_FUN, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_DF_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_df1_mn_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_DEF_FUN; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. функ. блок. из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_df_blk_sel_inf_arr, NUM_DEF_FUN, NUM_DF_FUNCS, ID_RANK_DF_BLK_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_DEF_FUN, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_DF_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_df1_blk_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_DEF_FUN; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для функциональных кнопок
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_f_sel_inf_arr, NUM_KEY, NUM_F_FUNCS, ID_RANK_F_PG);
    columnIndex = 0;
    p = pConfig -> uc_ar_key_rank_cfg;
    step = ((RESERV_MAX_F_EPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_KEY; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. тригг. уст. плюс из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_trg_set_pl_sel_inf_arr, NUM_TRG, NUM_TRG_FUNCS, ID_RANK_TRG_SET_PL_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_TRG, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_TRG_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_trg_setPl_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_TRG; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. тригг. уст. минус из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_trg_set_mn_sel_inf_arr, NUM_TRG, NUM_TRG_FUNCS, ID_RANK_TRG_SET_MN_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_TRG, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_TRG_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_trg_setMn_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_TRG; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. тригг. сбр. плюс из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_trg_rst_pl_sel_inf_arr, NUM_TRG, NUM_TRG_FUNCS, ID_RANK_TRG_SET_PL_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_TRG, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_TRG_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_trg_rstPl_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_TRG; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для опред. тригг. сбр. минус из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_trg_rst_mn_sel_inf_arr, NUM_TRG, NUM_TRG_FUNCS, ID_RANK_TRG_SET_MN_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, NUM_TRG, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_TRG_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_trg_rstMn_rank_cfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < NUM_TRG; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = i * step; j < step * (i + 1); j++) {
        if (k++ < 3) {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          shiftVal += 8;
        } else {
          p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          if (j < (step * (i + 1) - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    //копирование настр. ранжирования для Ан. рег. из буффера
    //копирование настр. ранжирования для опред. тригг. сбр. минус из буффера
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    cleanTwoDimensionalArr(&checkbox_sel_inf_arr_shiftL_tmp, MAX_NUM_RANK_PGS, NUM_FUNC_TO_INT_BITS);
    convert_to_external_rank_arr(&checkbox_sel_inf_arr_tmp, &checkbox_an_dig_rec_sel_inf_arr, 2, NUM_AN_DIG_REC_FUNCS, ID_RANK_AN_DIG_REC_PG);
    bitShiftL(&checkbox_sel_inf_arr_shiftL_tmp, &checkbox_sel_inf_arr_tmp, 2, (((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1), RANK_AN_DIG_REG_OFFSET);
    columnIndex = 0;
    p = pConfig -> uc_ar_AReccfg;
    unsigned char * p2 = pConfig -> uc_ar_DReccfg;
    step = ((RESERV_MAX_OEPRF_ONB - 1) >> 3) + 1;//кол. байт на одном срезе
    for (int i = 0; i < 2; i++) {
      int k = 0;
      unsigned int shiftVal = 0;
      unsigned int tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
      for (int j = 0; j < step; j++) {
        if (k++ < 3) {
          if (i == 0) {
            p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          } else {
            p2[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          }
          shiftVal += 8;
        } else {
          if (i == 0) {
            p[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          } else {
            p2[j] = (tmp_val & (0xff << shiftVal)) >> shiftVal;
          }
          if (j < (step - 1)) {
            tmp_val = checkbox_sel_inf_arr_shiftL_tmp[i][columnIndex++];
          }
          k = 0;
          shiftVal = 0;
        }
      }
      columnIndex = 0;
    }
    
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_DISCRETE_INPUT_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_DISCRETE_OUTPUT_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_LED_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_DF_PLUS_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_DF_MINUS_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_DF_BLK_PG);
    copy_additional_rank_settings_from_buff(pConfig, ID_RANK_AN_DIG_REC_PG);
    
    //-Бит запроса на запись к  системе Ici
    shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
  }
}
