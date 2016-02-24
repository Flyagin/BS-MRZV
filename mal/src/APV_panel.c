#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* APV_pickups_notification_value_changed (
                                                _id_user_widget Id, 
                                                CfgTblDsc *point,
                                                int *p_min,
                                                int *p_max,
                                                float *value,
                                                int *p_value_int
                                              )
{
  int *p_value_int_edit;
  
  switch (Id)
  {
  case ID_ED_APV_PICKUP_VALUE_0:
    {
      *p_min = APV_PICKUP0_MIN;
      *p_max = APV_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range1;

      break;
    }
  case ID_ED_APV_PICKUP_VALUE_1:
    {
      *p_min = APV_PICKUP1_MIN;
      *p_max = APV_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range2;
      break;
    }
  case ID_ED_APV_PICKUP_VALUE_2:
    {
      *p_min = APV_PICKUP2_MIN;
      *p_max = APV_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range3;
      break;
    }
  case ID_ED_APV_PICKUP_VALUE_3:
    {
      *p_min = APV_PICKUP3_MIN;
      *p_max = APV_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range4;
      break;
    }
  case ID_ED_APV_PICKUP_VALUE_4:
    {
      *p_min = APV_PICKUP4_MIN;
      *p_max = APV_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaU;
      break;
    }
  case ID_ED_APV_PICKUP_VALUE_5:
    {
      *p_min = APV_PICKUP5_MIN;
      *p_max = APV_PICKUP5_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaPhi;

      break;
    }
  case ID_ED_APV_PICKUP_VALUE_6:
    {
      *p_min = APV_PICKUP6_MIN;
      *p_max = APV_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaPhi_Dt;
      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Дії по зміні значення витримок в функції _cbDelays_Protection
**********/

unsigned short int* APV_delays_notification_value_changed (
                                                            _id_user_widget Id, 
                                                            CfgTblDsc *point,
                                                            unsigned int *p_min,
                                                            unsigned int *p_max,
                                                            float *value,
                                                            unsigned int *p_value_int
                                                           )
{
  unsigned short int *p_value_int_edit;
  
  switch (Id)
  {
  case ID_ED_APV_DELAY_VALUE_0:
    {
      *p_min = APV_DELAY0_MIN;
      *p_max = APV_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_wait_U;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_1:
    {
      *p_min = APV_DELAY1_MIN;
      *p_max = APV_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_wait_sycro;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_2:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_blk;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_3:
    {
      *p_min = APV_DELAY3_MIN;
      *p_max = APV_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_4:
    {
      *p_min = APV_DELAY4_MIN;
      *p_max = APV_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr_T_forbid;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_5:
    {
      *p_min = APV_DELAY5_MIN;
      *p_max = APV_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr_T_blk_HSW;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_6:
    {
      *p_min = APV_DELAY6_MIN;
      *p_max = APV_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_wait_U;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_7:
    {
      *p_min = APV_DELAY7_MIN;
      *p_max = APV_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_wait_syncro;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_8:
    {
      *p_min = APV_DELAY8_MIN;
      *p_max = APV_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_blk;

      break;
    }
  case ID_ED_APV_DELAY_VALUE_9:
    {
      *p_min = APV_DELAY9_MIN;
      *p_max = APV_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки APV
**********/
void APV_pickup_info(
                      unsigned int number,
                      CfgTblDsc *point,
                      int *p_min,
                      int *p_max,
                      float *value,
                      int *p_value_int
                     )
{
  switch (number)
  {
  case 0:
    {
      *p_min = APV_PICKUP0_MIN;
      *p_max = APV_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range1;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 1:
    {
      *p_min = APV_PICKUP1_MIN;
      *p_max = APV_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 2:
    {
      *p_min = APV_PICKUP2_MIN;
      *p_max = APV_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range3;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 3:
    {
      *p_min = APV_PICKUP3_MIN;
      *p_max = APV_PICKUP3_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_U_ov_range4;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 4:
    {
      *p_min = APV_PICKUP4_MIN;
      *p_max = APV_PICKUP4_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaU;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 5:
    {
      *p_min = APV_PICKUP5_MIN;
      *p_max = APV_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaPhi;
      *value = (float)(*p_value_int);
      break;
    }
  case 6:
    {
      *p_min = APV_PICKUP6_MIN;
      *p_max = APV_PICKUP6_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrPickup.Rclr_DeltaPhi_Dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки APV
**********/
void APV_delay_info(
                     unsigned int number,
                     CfgTblDsc *point,
                     unsigned int *p_min,
                     unsigned int *p_max,
                     float *value,
                     unsigned int *p_value_int
                    )
{
  switch (number)
  {
  case 0:
    {
      *p_min = APV_DELAY0_MIN;
      *p_max = APV_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_wait_U;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = APV_DELAY1_MIN;
      *p_max = APV_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_wait_sycro;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T_blk;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 3:
    {
      *p_min = APV_DELAY0_MIN;
      *p_max = APV_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr1_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 4:
    {
      *p_min = APV_DELAY1_MIN;
      *p_max = APV_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr_T_forbid;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 5:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr_T_blk_HSW;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 6:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_wait_U;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 7:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_wait_syncro;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 8:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T_blk;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 9:
    {
      *p_min = APV_DELAY2_MIN;
      *p_max = APV_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[APV_select_group].ownrRclrStageParam.Rclr2_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки APV
**********/
const char* APV_pickup_info_1(
                               unsigned int number,
                               int *p_min,
                               int *p_max,
                               int *p_shift,
                               unsigned int *extra_param
                              )
{
  const char *p_pickup_dimention;
  *p_min = 0;
  *extra_param = 0;

  switch (number)
  {
  case 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      
      *p_max = APV_PICKUP0_MAX/1000;
      *p_shift = APV_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = APV_PICKUP1_MAX/1000;
      *p_shift = APV_PICKUP1_SHIFT;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = APV_PICKUP2_MAX/1000;
      *p_shift = APV_PICKUP2_SHIFT;
        
      break;
    }
  case 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = APV_PICKUP3_MAX/1000;
      *p_shift = APV_PICKUP3_SHIFT;
        
      break;
    }
  case 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = APV_PICKUP4_MAX/1000;
      *p_shift = APV_PICKUP4_SHIFT;
        
      break;
    }
  case 5:
    {
      p_pickup_dimention = gradus;
      
      *p_max = APV_PICKUP5_MAX;
      *p_shift = APV_PICKUP5_SHIFT;
        
      break;
    }
  case 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_DEGREE_DIV_SECOND].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = APV_PICKUP6_MAX/1000;
      *p_shift = APV_PICKUP6_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки APV
**********/
const char* APV_delay_info_1(
                              unsigned int number,
                              int *p_min,
                              int *p_max,
                              int *p_shift
                             )
{
  const char *p_pickup_dimention = MEASURES[MEASURES_OF_SECOND].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  *p_min = 0;

  switch (number)
  {
  case 0:
    {
      *p_max = APV_DELAY0_MAX/100;
      *p_shift = APV_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = APV_DELAY1_MAX/100;
      *p_shift = APV_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = APV_DELAY2_MAX/100;
      *p_shift = APV_DELAY2_SHIFT;
        
      break;
    }
  case 3:
    {
      *p_max = APV_DELAY3_MAX/100;
      *p_shift = APV_DELAY3_SHIFT;
        
      break;
    }
  case 4:
    {
      *p_max = APV_DELAY4_MAX/100;
      *p_shift = APV_DELAY4_SHIFT;
        
      break;
    }
  case 5:
    {
      *p_max = APV_DELAY5_MAX/100;
      *p_shift = APV_DELAY5_SHIFT;
        
      break;
    }
  case 6:
    {
      *p_max = APV_DELAY6_MAX/100;
      *p_shift = APV_DELAY6_SHIFT;
        
      break;
    }
  case 7:
    {
      *p_max = APV_DELAY7_MAX/100;
      *p_shift = APV_DELAY7_SHIFT;
        
      break;
    }
  case 8:
    {
      *p_max = APV_DELAY8_MAX/100;
      *p_shift = APV_DELAY8_SHIFT;
        
      break;
    }
  case 9:
    {
      *p_max = APV_DELAY9_MAX/100;
      *p_shift = APV_DELAY9_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання вказівника на розмірність уставок
**********/
const char* APV_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 5:
    {
      p_pickup_dimention = gradus;
      break;
    }
  case 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_DEGREE_DIV_SECOND].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      break;
    }
  default:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для APV
**********/
const TITLE* APV_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (number == 2)
  {
    *p_j_max = 5;
    p_control_list_name = REGYM_APV;
  }
  else if (number == 3)
  {
    *p_j_max = 3;
    p_control_list_name = PHASES;
  }
  else
  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для APV
**********/
unsigned char* APV_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrRclrMng.state_Rclr;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrRclrMng.state_Rclr2;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrRclrMng.select_Mode_Rclr;
      break;
    }
  case 3:
    {
      p_to_state = &point->ownrRclrMng.selectPhase;
      break;
    }
  default:
    {
      unsigned int number_func = number - 4;
      unsigned int number_byte = number_func >> 3;
      unsigned int number_bit  = number_func & 0x7;
      temp_data_for_APV = (point->ownrRclrMng.ar_Rclr_Stp_Cmd_state[number_byte] >> number_bit) & 0x1;
      p_to_state = &temp_data_for_APV;
      break;
    }
  }
  
  return p_to_state;
}
/**********/

/**********
Функція яка виконує певні дії після зміни деяких налаштувань
**********/
void APV_change_state_callback(
                               unsigned int number,
                               CfgTblDsc *point
                              )
{
  if (number > 3)
  {
    unsigned int number_func = number - 4;
    unsigned int number_byte = number_func >> 3;
    unsigned int number_bit  = number_func & 0x7;
    
    if (temp_data_for_APV == 0)
    {
      point->ownrRclrMng.ar_Rclr_Stp_Cmd_state[number_byte] &= (unsigned char)(~(1 << number_bit));
    }
    else
    {
      point->ownrRclrMng.ar_Rclr_Stp_Cmd_state[number_byte] |= (unsigned char)( (1 << number_bit));
    }
  }
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_APV(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_APV) && (ok == true); i++)
    { 
      int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = APV_PICKUP0_MIN;
          max = APV_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_U_ov_range1;

          break;
        }
      case 1:
        {
          min = APV_PICKUP1_MIN;
          max = APV_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_U_ov_range2;

          break;
        }
      case 2:
        {
          min = APV_PICKUP2_MIN;
          max = APV_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_U_ov_range3;

          break;
        }
      case 3:
        {
          min = APV_PICKUP3_MIN;
          max = APV_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_U_ov_range4;

          break;
        }
      case 4:
        {
          min = APV_PICKUP4_MIN;
          max = APV_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_DeltaU;

          break;
        }
      case 5:
        {
          min = APV_PICKUP5_MIN;
          max = APV_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_DeltaPhi;

          break;
        }
      case 6:
        {
          min = APV_PICKUP6_MIN;
          max = APV_PICKUP6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrPickup.Rclr_DeltaPhi_Dt;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_APV) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = APV_DELAY0_MIN;
          max = APV_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr1_T_wait_U;

          break;
        }
      case 1:
        {
          min = APV_DELAY1_MIN;
          max = APV_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr1_T_wait_sycro;

          break;
        }
      case 2:
        {
          min = APV_DELAY2_MIN;
          max = APV_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr1_T_blk;

          break;
        }
      case 3:
        {
          min = APV_DELAY3_MIN;
          max = APV_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr1_T;

          break;
        }
      case 4:
        {
          min = APV_DELAY4_MIN;
          max = APV_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr_T_forbid;

          break;
        }
      case 5:
        {
          min = APV_DELAY5_MIN;
          max = APV_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr_T_blk_HSW;

          break;
        }
      case 6:
        {
          min = APV_DELAY6_MIN;
          max = APV_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr2_T_wait_U;

          break;
        }
      case 7:
        {
          min = APV_DELAY7_MIN;
          max = APV_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr2_T_wait_syncro;

          break;
        }
      case 8:
        {
          min = APV_DELAY8_MIN;
          max = APV_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr2_T_blk;

          break;
        }
      case 9:
        {
          min = APV_DELAY9_MIN;
          max = APV_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrRclrStageParam.Rclr2_T;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }
  }
  
  return ok;
}
/*****************************/

/*****************************
Копіювання змінених данихз структури для редагування у робочу структуру
*****************************/
void copy_data_APV(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrRclrPickup = 
    source->arPckpStpmStngStore[i].ownrRclrPickup; 

    target->arPckpStpmStngStore[i].ownrRclrStageParam = 
    source->arPckpStpmStngStore[i].ownrRclrStageParam; 
  }
  target->ownrRclrMng = source->ownrRclrMng;
}
/*****************************/
