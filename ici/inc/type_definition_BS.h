#ifndef __TYPE_DEFINITION_BS_H
#define __TYPE_DEFINITION_BS_H

typedef struct
{
  //Тип пристрою
  unsigned int device_id;

  /*
  Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
  */
  unsigned int dz1_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int dz2_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int dz3_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int dz4_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int dz5_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  /*
  Угол доворота для МТЗ
  */
  unsigned int mtz1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int mtz2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int mtz3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int mtz4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int mtz5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  /*
  Угол доворота для ТЗНП
  */
  unsigned int tznp1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int tznp2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int tznp3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int tznp4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int tznp5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  /*
  Угол доворота для ZOP
  */
  unsigned int zop1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int zop2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int zop3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int zop4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  unsigned int zop5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  
  /*Рассогласование углов
  
  0 - Usyn
  1 - Isyn
  2 - Ubc-TN2
  0 - Ua
  1 - Ub
  2 - Uc
  */
  unsigned int a_Usyn_Isyn_Ubc;
  unsigned int a_Ua_Ub_Uc;

  /*
   Номинальный ток от шкафа отбора напряжения
  0 - 0,15А
  1 - 0,075А
  */
  unsigned int In_type_shon;
 
} __SETTINGS;  

typedef struct
{
  int measurement[NUMBER_CANALS + 4 + 1];
  int measurement_i[NUMBER_CANALS];
  
  float frequency_SPI1;
  float frequency_SPI2;
  
  int linear_current[3];
  int linear_voltage[3];
  
  float resistance_f[6*5];
  float resistance_m[INDEX_RES];
  int resistance[6*3];
  
  int angle_3I0_3U0;
  int angle_IA_UBC;
  int angle_IB_UCA;
  int angle_IC_UAB;
  int angle_I2_U2;
  
       
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
  
  int speed_resistance_change[6*3];
  int resistance_angle[6*3];
  
  int U_line;
  int voltage_difference;

  unsigned int diagnostyka;
  
  long long active_power[3];
  long long reactive_power[3];
  long long full_power[3];
  long long sum_power[3];
  
  float power_coefficient[3];
  
  float active_power_plus;
  float active_power_minus;
  
  float reactive_power_1q;
  float reactive_power_2q;
  float reactive_power_3q;
  float reactive_power_4q;
  
  int angle[10];
  
} __TOTAL_MEASUREMENT; 

#endif
