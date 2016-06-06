
#ifndef __GUI_RANK_CONST_H
#define __GUI_RANK_CONST_H

#define _NULL_                -1
  
/* 
  Макс. длина массива не должна быть меньше макс. кол.
  ранжируемых функций для одной из защит.

  Пока что макс. для ТЗНП для двх. 15 и поэтому взято знач. 20 __ARR_LENGTH_DI
  Для двых., св., оф. и др. ТЗНП=55 __ARR_LENGTH = 60
*/
#define _ARR_LENGTH_DI        20
#define _ARR_LENGTH           60

//ниже списки номеров битов для массивов ранжирования

//ДЗ
#define DSTP_ARR_LENGTH    48
#define DSTP_CONST_ARR {              \
  BLOCK_DSTP1_DI_OEPRF_ONB,           \
  STPDEV_DSTP1_MF_OEPRF_ONB,          \
  DSTP1_MF_OEPRF_ONB,                 \
  STPDEV_MCP_DSTP1_OEPRF_ONB,         \
  MCP_DSTP1_OEPRF_ONB,                \
  STPDEV_DSTP1_OF_OEPRF_ONB,          \
  DSTP1_OF_OEPRF_ONB,                 \
  BLOCK_DSTP2_DI_OEPRF_ONB,           \
  DSTP2_MF_OEPRF_ONB,                 \
  STPDEV_DSTP2_MF_OEPRF_ONB,          \
  MCP_DSTP2_OEPRF_ONB,                \
  STPDEV_MCP_DSTP2_OEPRF_ONB,         \
  DSTP2_OF_OEPRF_ONB,                 \
  STPDEV_DSTP2_OF_OEPRF_ONB,          \
  ACCLT_DSTP2_DI_OEPRF_ONB,           \
  ACCLT_DSTP2_EPI_OEPRF_ONB,          \
  BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB,     \
  BLOCK_DSTP3_DI_OEPRF_ONB,           \
  DSTP3_MF_OEPRF_ONB,                 \
  STPDEV_DSTP3_MF_OEPRF_ONB,          \
  MCP_DSTP3_OEPRF_ONB,                \
  STPDEV_MCP_DSTP3_OEPRF_ONB,         \
  DSTP3_OF_OEPRF_ONB,                 \
  STPDEV_DSTP3_OF_OEPRF_ONB,          \
  ACCLT_DSTP3_DI_OEPRF_ONB,           \
  ACCLT_DSTP3_EPI_OEPRF_ONB,          \
  BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB,     \
  BLOCK_DSTP4_DI_OEPRF_ONB,           \
  DSTP4_MF_OEPRF_ONB,                 \
  STPDEV_DSTP4_MF_OEPRF_ONB,          \
  MCP_DSTP4_OEPRF_ONB,                \
  STPDEV_MCP_DSTP4_OEPRF_ONB,         \
  DSTP4_OF_OEPRF_ONB,                 \
  STPDEV_DSTP4_OF_OEPRF_ONB,          \
  ACCLT_DSTP4_DI_OEPRF_ONB,           \
  ACCLT_DSTP4_EPI_OEPRF_ONB,          \
  BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB,     \
  BLOCK_DSTP5_DI_OEPRF_ONB,           \
  DSTP5_MF_OEPRF_ONB,                 \
  STPDEV_DSTP5_MF_OEPRF_ONB,          \
  MCP_DSTP5_OEPRF_ONB,                \
  STPDEV_MCP_DSTP5_OEPRF_ONB,         \
  DSTP5_OF_OEPRF_ONB,                 \
  STPDEV_DSTP5_OF_OEPRF_ONB,          \
  ACCLT_DSTP5_DI_OEPRF_ONB,           \
  ACCLT_DSTP5_EPI_OEPRF_ONB,          \
  BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB,     \
  SEC_GR_UST_DSTP_DI_OEPRF_ONB        \
};

#define DSTP_DI_ARR_LENGTH    14
#define DSTP_DI_CONST_ARR {           \
  BLOCK_DSTP1_DI_IEPRF_ONB,           \
  BLOCK_DSTP2_DI_IEPRF_ONB,           \
  ACCLT_DSTP2_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB,     \
  BLOCK_DSTP3_DI_IEPRF_ONB,           \
  ACCLT_DSTP3_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB,     \
  BLOCK_DSTP4_DI_IEPRF_ONB,           \
  ACCLT_DSTP4_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB,     \
  BLOCK_DSTP5_DI_IEPRF_ONB,           \
  ACCLT_DSTP5_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB,     \
  SEC_GR_UST_DSTP_DI_IEPRF_ONB        \
};

//МТЗ
#define DROCP_ARR_LENGTH      53
#define DROCP_CONST_ARR {                     \
  BLOCK_MCP1_DI_OEPRF_ONB,                    \
  BLOCK_MCP2_DI_OEPRF_ONB,                    \
  BLOCK_MCP3_DI_OEPRF_ONB,                    \
  BLOCK_MCP4_DI_OEPRF_ONB,                    \
  BLOCK_MCP5_DI_OEPRF_ONB,                    \
  ACCLT_MCP2_EPI_OEPRF_ONB,                   \
  ACCLT_MCP2_DI_OEPRF_ONB,                    \
  BLOCK_ACCLT_MCP2_DI_OEPRF_ONB,              \
  ACCLT_MCP3_EPI_OEPRF_ONB,                   \
  ACCLT_MCP3_DI_OEPRF_ONB,                    \
  BLOCK_ACCLT_MCP3_DI_OEPRF_ONB,              \
  ACCLT_MCP4_EPI_OEPRF_ONB,                   \
  ACCLT_MCP4_DI_OEPRF_ONB,                    \
  BLOCK_ACCLT_MCP4_DI_OEPRF_ONB,              \
  ACCLT_MCP5_EPI_OEPRF_ONB,                   \
  ACCLT_MCP5_DI_OEPRF_ONB,                    \
  BLOCK_ACCLT_MCP5_DI_OEPRF_ONB,              \
  SEC_GR_UST_MCP_DI_OEPRF_ONB,                \
  STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB,          \
  STPDEV_MCP1_BORING_OEPRF_ONB,               \
  STPDEV_MCP1_STAIGHT_OEPRF_ONB,              \
  STPDEV_MCP1_BACK_OEPRF_ONB,                 \
  STPDEV_MCP1_VLT_OEPRF_ONB,                  \
  MCP1_OEPRF_ONB,                             \
  STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB,          \
  STPDEV_MCP2_BORING_OEPRF_ONB,               \
  STPDEV_MCP2_STAIGHT_OEPRF_ONB,              \
  STPDEV_MCP2_BACK_OEPRF_ONB,                 \
  STPDEV_MCP2_VLT_OEPRF_ONB,                  \
  MCP2_OEPRF_ONB,                             \
  STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB,          \
  STPDEV_MCP3_BORING_OEPRF_ONB,               \
  STPDEV_MCP3_STAIGHT_OEPRF_ONB,              \
  STPDEV_MCP3_BACK_OEPRF_ONB,                 \
  STPDEV_MCP3_VLT_OEPRF_ONB,                  \
  MCP3_OEPRF_ONB,                             \
  STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB,          \
  STPDEV_MCP4_BORING_OEPRF_ONB,               \
  STPDEV_MCP4_STAIGHT_OEPRF_ONB,              \
  STPDEV_MCP4_BACK_OEPRF_ONB,                 \
  STPDEV_MCP4_VLT_OEPRF_ONB,                  \
  MCP4_OEPRF_ONB,                             \
  STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB,          \
  STPDEV_MCP5_BORING_OEPRF_ONB,               \
  STPDEV_MCP5_STAIGHT_OEPRF_ONB,              \
  STPDEV_MCP5_BACK_OEPRF_ONB,                 \
  STPDEV_MCP5_VLT_OEPRF_ONB,                  \
  MCP5_OEPRF_ONB                              \
};

#define DROCP_DI_ARR_LENGTH   14
#define DROCP_DI_CONST_ARR {          \
  BLOCK_MCP1_DI_IEPRF_ONB,            \
  BLOCK_MCP2_DI_IEPRF_ONB,            \
  BLOCK_MCP3_DI_IEPRF_ONB,            \
  BLOCK_MCP4_DI_IEPRF_ONB,            \
  BLOCK_MCP5_DI_IEPRF_ONB,            \
  ACCLT_MCP2_DI_IEPRF_ONB,            \
  BLOCK_ACCLT_MCP2_DI_IEPRF_ONB,      \
  ACCLT_MCP3_DI_IEPRF_ONB,            \
  BLOCK_ACCLT_MCP3_DI_IEPRF_ONB,      \
  ACCLT_MCP4_DI_IEPRF_ONB,            \
  BLOCK_ACCLT_MCP4_DI_IEPRF_ONB,      \
  ACCLT_MCP5_DI_IEPRF_ONB,            \
  BLOCK_ACCLT_MCP5_DI_IEPRF_ONB,      \
  SEC_GR_UST_MCP_DI_IEPRF_ONB         \
};

//ТЗНП
#define DRERTH_ARR_LENGTH     55
#define DRERTH_CONST_ARR {            \
  BLOCK_TZNP1_DI_OEPRF_ONB,           \
  ACCLT_TZNP1_DI_OEPRF_ONB,           \
  BLOCK_ACCLT_TZNP1_DI_OEPRF_ONB,     \
  BLOCK_TZNP2_DI_OEPRF_ONB,           \
  ACCLT_TZNP2_DI_OEPRF_ONB,           \
  BLOCK_ACCLT_TZNP2_DI_OEPRF_ONB,     \
  BLOCK_TZNP3_DI_OEPRF_ONB,           \
  ACCLT_TZNP3_DI_OEPRF_ONB,           \
  BLOCK_ACCLT_TZNP3_DI_OEPRF_ONB,     \
  BLOCK_TZNP4_DI_OEPRF_ONB,           \
  ACCLT_TZNP4_DI_OEPRF_ONB,           \
  BLOCK_ACCLT_TZNP4_DI_OEPRF_ONB,     \
  BLOCK_TZNP5_DI_OEPRF_ONB,           \
  ACCLT_TZNP5_DI_OEPRF_ONB,           \
  BLOCK_ACCLT_TZNP5_DI_OEPRF_ONB,     \
  ACCLT_TZNP1_EPI_OEPRF_ONB,          \
  ACCLT_TZNP2_EPI_OEPRF_ONB,          \
  ACCLT_TZNP3_EPI_OEPRF_ONB,          \
  ACCLT_TZNP4_EPI_OEPRF_ONB,          \
  ACCLT_TZNP5_EPI_OEPRF_ONB,          \
  STPDEV_SECTOR_TZNP1_OEPRF_ONB,      \
  STPDEV_TZNP1_OEPRF_ONB,             \
  TZNP1_OEPRF_ONB,                    \
  STPDEV_TZNP1_3U0_OEPRF_ONB,         \
  TZNP1__3U0_OEPRF_ONB,               \
  STPDEV_TZNP1_3I0_OEPRF_ONB,         \
  TZNP1_3I0_OEPRF_ONB,                \
  STPDEV_SECTOR_TZNP2_OEPRF_ONB,      \
  STPDEV_TZNP2_OEPRF_ONB,             \
  TZNP2_OEPRF_ONB,                    \
  STPDEV_TZNP2_3U0_OEPRF_ONB,         \
  TZNP2_3U0_OEPRF_ONB,                \
  STPDEV_TZNP2_3I0_OEPRF_ONB,         \
  TZNP2_3I0_OEPRF_ONB,                \
  STPDEV_SECTOR_TZNP3_OEPRF_ONB,      \
  STPDEV_TZNP3_OEPRF_ONB,             \
  TZNP3_OEPRF_ONB,                    \
  STPDEV_TZNP3_3U0_OEPRF_ONB,         \
  TZNP3_3U0_OEPRF_ONB,                \
  STPDEV_TZNP3_3I0_OEPRF_ONB,         \
  TZNP3_3I0_OEPRF_ONB,                \
  STPDEV_SECTOR_TZNP4_OEPRF_ONB,      \
  STPDEV_TZNP4_OEPRF_ONB,             \
  TZNP4_OEPRF_ONB,                    \
  STPDEV_TZNP4_3U0_OEPRF_ONB,         \
  TZNP4_3U0_OEPRF_ONB,                \
  STPDEV_TZNP4_3I0_OEPRF_ONB,         \
  TZNP4_3I0_OEPRF_ONB,                \
  STPDEV_SECTOR_TZNP5_OEPRF_ONB,      \
  STPDEV_TZNP5_OEPRF_ONB,             \
  TZNP5_OEPRF_ONB,                    \
  STPDEV_TZNP5_3U0_OEPRF_ONB,         \
  TZNP5_3U0_OEPRF_ONB,                \
  STPDEV_TZNP5_3I0_OEPRF_ONB,         \
  TZNP5_3I0_OEPRF_ONB                 \
};

#define DRERTH_DI_ARR_LENGTH  15
#define DRERTH_DI_CONST_ARR {         \
  BLOCK_TZNP1_DI_IEPRF_ONB,           \
  ACCLT_TZNP1_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_TZNP1_DI_IEPRF_ONB,     \
  BLOCK_TZNP2_DI_IEPRF_ONB,           \
  ACCLT_TZNP2_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_TZNP2_DI_IEPRF_ONB,     \
  BLOCK_TZNP3_DI_IEPRF_ONB,           \
  ACCLT_TZNP3_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_TZNP3_DI_IEPRF_ONB,     \
  BLOCK_TZNP4_DI_IEPRF_ONB,           \
  ACCLT_TZNP4_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_TZNP4_DI_IEPRF_ONB,     \
  BLOCK_TZNP5_DI_IEPRF_ONB,           \
  ACCLT_TZNP5_DI_IEPRF_ONB,           \
  BLOCK_ACCLT_TZNP5_DI_IEPRF_ONB      \
};

//ЗОП
#define NSP_ARR_LENGTH        16
#define NSP_CONST_ARR {                       \
  BLOCK_ZOP1_DI_OEPRF_ONB,                    \
  BLOCK_ZOP2_DI_OEPRF_ONB,                    \
  SEC_GR_UST_ZOP_DI_OEPRF_ONB,                \
  STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB,          \
  STPDEV_ZOP1_BORING_OEPRF_ONB,               \
  STPDEV_ZOP1_STAIGHT_OEPRF_ONB,              \
  STPDEV_ZOP1_BACK_OEPRF_ONB,                 \
  ZOP1_OEPRF_ONB,                             \
  STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB,       \
  STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB,          \
  STPDEV_ZOP2_BORING_OEPRF_ONB,               \
  STPDEV_ZOP2_STAIGHT_OEPRF_ONB,              \
  STPDEV_ZOP2_BACK_OEPRF_ONB,                 \
  ZOP2_OEPRF_ONB                              \
};

#define NSP_DI_ARR_LENGTH     3
#define NSP_DI_CONST_ARR {            \
  BLOCK_ZOP1_DI_IEPRF_ONB,            \
  BLOCK_ZOP2_DI_IEPRF_ONB,            \
  SEC_GR_UST_ZOP_DI_IEPRF_ONB         \
};

//ЗНмин
#define UMIN_ARR_LENGTH       8
#define UMIN_CONST_ARR {              \
  BLOCK_UMIN1_DI_OEPRF_ONB,           \
  START_UMIN1_DI_OEPRF_ONB,           \
  BLOCK_UMIN2_DI_OEPRF_ONB,           \
  START_UMIN2_DI_OEPRF_ONB,           \
  STPDEV_UMIN1_OEPRF_ONB,             \
  UMIN1_OEPRF_ONB,                    \
  STPDEV_UMIN2_OEPRF_ONB,             \
  UMIN2_OEPRF_ONB                     \
};

#define UMIN_DI_ARR_LENGTH    4
#define UMIN_DI_CONST_ARR {           \
  BLOCK_UMIN1_DI_IEPRF_ONB,           \
  START_UMIN1_DI_IEPRF_ONB,           \
  BLOCK_UMIN2_DI_IEPRF_ONB,           \
  START_UMIN2_DI_IEPRF_ONB            \
};

//ЗНмакс
#define UMAX_ARR_LENGTH       6
#define UMAX_CONST_ARR {              \
  BLOCK_UMAX1_DI_OEPRF_ONB,           \
  BLOCK_UMAX2_DI_OEPRF_ONB,           \
  STPDEV_UMAX1_OEPRF_ONB,             \
  UMAX1_OEPRF_ONB,                    \
  STPDEV_UMAX2_OEPRF_ONB,             \
  UMAX2_OEPRF_ONB                     \
};

#define UMAX_DI_ARR_LENGTH    2
#define UMAX_DI_CONST_ARR {           \
  BLOCK_UMAX1_DI_IEPRF_ONB,           \
  BLOCK_UMAX2_DI_IEPRF_ONB            \
};

//АПВ
#define RCLR_ARR_LENGTH       4
#define RCLR_CONST_ARR {              \
  START_AFU_DI_OEPRF_ONB,             \
  BLOCK_AFU_DI_OEPRF_ONB,             \
  ARCL1_OEPRF_ONB,                    \
  ARCL2_OEPRF_ONB                     \
};

#define RCLR_DI_ARR_LENGTH    2
#define RCLR_DI_CONST_ARR {           \
  START_AFU_DI_IEPRF_ONB,             \
  BLOCK_AFU_DI_IEPRF_ONB              \
};

//УРОВ
#define BRF_ARR_LENGTH        3
#define BRF_CONST_ARR {               \
  START_UROV_DI_OEPRF_ONB,            \
  UROV1_OEPRF_ONB,                    \
  UROV2_OEPRF_ONB                     \
};

#define BRF_DI_ARR_LENGTH     1
#define BRF_DI_CONST_ARR {            \
  START_UROV_DI_IEPRF_ONB             \
};

/***************************************************/

#define CONVERT_RANK_INDEX(                             \
  _inp_arr, _size, _inp_index, _result                  \
) {                                                     \
  for (int _i = 0; _i < _size; _i++) {                  \
    if (_inp_index == _inp_arr[_i]) {                   \
      _result = _i;                                     \
      break;                                            \
    }                                                   \
  }                                                     \
}

#endif
