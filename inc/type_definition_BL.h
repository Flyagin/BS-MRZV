#ifndef __TYPE_DEFINITION_BL_H
#define __TYPE_DEFINITION_BL_H

typedef struct
{
  int measurement_bl[NUMBER_CANALS + 4];
  int ortogonal_rotate[2 * NUMBER_CANALS];
  
  int linear_voltage[3];
  
  float frequency_SPI1;
  float frequency_SPI2;
  
  float resistance_f[6*5];
  float resistance_m[INDEX_RES];
  
  
  int resistance[6*3];
  int resistance_angle[6*3];
  
    
  int sector_3I0_3U0_1;
  int sector_IA_UBC_1;
  int sector_IB_UCA_1;
  int sector_IC_UAB_1;
  int sector_I2_U2_1;
   
  int sector_3I0_3U0_2;
  int sector_IA_UBC_2;
  int sector_IB_UCA_2;
  int sector_IC_UAB_2;
  int sector_I2_U2_2;
   
  int sector_3I0_3U0_3;
  int sector_IA_UBC_3;
  int sector_IB_UCA_3;
  int sector_IC_UAB_3;
  int sector_I2_U2_3;
   
  int sector_3I0_3U0_4;
  int sector_IA_UBC_4;
  int sector_IB_UCA_4;
  int sector_IC_UAB_4;
  int sector_I2_U2_4;
   
  int sector_3I0_3U0_5;
  int sector_IA_UBC_5;
  int sector_IB_UCA_5;
  int sector_IC_UAB_5;
  int sector_I2_U2_5;
  
  int speed_angle_change;
  int angle_unbalance;
  int voltage_difference;
  
  int measurement_group;
  int measurement_group_r;
  
} __MEASUREMENT_TO_PROTECTION;
#endif
