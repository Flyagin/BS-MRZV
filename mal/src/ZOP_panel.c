#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* ZOP_pickups_notification_value_changed (
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
  case ID_ED_ZOP_PICKUP_VALUE_0:
    {
      *p_min = ZOP1_PICKUP0_MIN;
      *p_max = ZOP1_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;

      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_1:
    {
      *p_min = ZOP1_PICKUP1_MIN;
      *p_max = ZOP1_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_I2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_2:
    {
      *p_min = ZOP1_PICKUP2_MIN;
      *p_max = ZOP1_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_U2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_3:
    {
      *p_min = ZOP1_PICKUP3_MIN;
      *p_max = ZOP1_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_I2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_4:
    {
      *p_min = ZOP1_PICKUP4_MIN;
      *p_max = ZOP1_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_U2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_5:
    {
      *p_min = ZOP1_PICKUP5_MIN;
      *p_max = ZOP1_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_I2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_6:
    {
      *p_min = ZOP2_PICKUP0_MIN;
      *p_max = ZOP2_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;

      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_7:
    {
      *p_min = ZOP2_PICKUP1_MIN;
      *p_max = ZOP2_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_I2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_8:
    {
      *p_min = ZOP2_PICKUP2_MIN;
      *p_max = ZOP2_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_U2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_9:
    {
      *p_min = ZOP2_PICKUP3_MIN;
      *p_max = ZOP2_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_I2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_10:
    {
      *p_min = ZOP2_PICKUP4_MIN;
      *p_max = ZOP2_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_U2;
      break;
    }
  case ID_ED_ZOP_PICKUP_VALUE_11:
    {
      *p_min = ZOP2_PICKUP5_MIN;
      *p_max = ZOP2_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_I2;
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

unsigned short int* ZOP_delays_notification_value_changed (
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
  case ID_ED_ZOP_DELAY_VALUE_0:
    {
      *p_min = ZOP1_DELAY0_MIN;
      *p_max = ZOP1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop;

      break;
    }
  case ID_ED_ZOP_DELAY_VALUE_1:
    {
      *p_min = ZOP1_DELAY1_MIN;
      *p_max = ZOP1_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_s;

      break;
    }
  case ID_ED_ZOP_DELAY_VALUE_2:
    {
      *p_min = ZOP1_DELAY2_MIN;
      *p_max = ZOP1_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_b;

      break;
    }
  case ID_ED_ZOP_DELAY_VALUE_3:
    {
      *p_min = ZOP2_DELAY0_MIN;
      *p_max = ZOP2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop;

      break;
    }
  case ID_ED_ZOP_DELAY_VALUE_4:
    {
      *p_min = ZOP2_DELAY1_MIN;
      *p_max = ZOP2_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_s;

      break;
    }
  case ID_ED_ZOP_DELAY_VALUE_5:
    {
      *p_min = ZOP2_DELAY2_MIN;
      *p_max = ZOP2_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_b;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки ZOP
**********/
void ZOP_pickup_info(
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
      *p_min = ZOP1_PICKUP0_MIN;
      *p_max = ZOP1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;
      *value = (float)(*p_value_int);
      break;
    }
  case 1:
    {
      *p_min = ZOP1_PICKUP1_MIN;
      *p_max = ZOP1_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 2:
    {
      *p_min = ZOP1_PICKUP2_MIN;
      *p_max = ZOP1_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_U2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 3:
    {
      *p_min = ZOP1_PICKUP3_MIN;
      *p_max = ZOP1_PICKUP3_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 4:
    {
      *p_min = ZOP1_PICKUP4_MIN;
      *p_max = ZOP1_PICKUP4_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_U2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 5:
    {
      *p_min = ZOP1_PICKUP5_MIN;
      *p_max = ZOP1_PICKUP5_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspPickupStoreDsc.ov_range_Zop_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 0:
    {
      *p_min = ZOP2_PICKUP0_MIN;
      *p_max = ZOP2_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 1:
    {
      *p_min = ZOP2_PICKUP1_MIN;
      *p_max = ZOP2_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 2:
    {
      *p_min = ZOP2_PICKUP2_MIN;
      *p_max = ZOP2_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_U2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 3:
    {
      *p_min = ZOP2_PICKUP3_MIN;
      *p_max = ZOP2_PICKUP3_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 4:
    {
      *p_min = ZOP2_PICKUP4_MIN;
      *p_max = ZOP2_PICKUP4_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_U2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 5:
    {
      *p_min = ZOP2_PICKUP5_MIN;
      *p_max = ZOP2_PICKUP5_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspPickupStoreDsc.ov_range_Zop_I2;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки ZOP
**********/
void ZOP_delay_info(
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
      *p_min = ZOP1_DELAY0_MIN;
      *p_max = ZOP1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = ZOP1_DELAY1_MIN;
      *p_max = ZOP1_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_s;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = ZOP1_DELAY2_MIN;
      *p_max = ZOP1_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_b;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 0:
    {
      *p_min = ZOP2_DELAY0_MIN;
      *p_max = ZOP2_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 1:
    {
      *p_min = ZOP2_DELAY1_MIN;
      *p_max = ZOP2_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_s;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 2:
    {
      *p_min = ZOP2_DELAY2_MIN;
      *p_max = ZOP2_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[ZOP_select_group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_b;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки ZOP
**********/
const char* ZOP_pickup_info_1(
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
      p_pickup_dimention = gradus;
      
      *p_max = ZOP1_PICKUP0_MAX;
      *p_shift = ZOP1_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP1_PICKUP1_MAX/1000;
      *p_shift = ZOP1_PICKUP1_SHIFT;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP1_PICKUP2_MAX/1000;
      *p_shift = ZOP1_PICKUP2_SHIFT;
        
      break;
    }
  case 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP1_PICKUP3_MAX/1000;
      *p_shift = ZOP1_PICKUP3_SHIFT;
        
      break;
    }
  case 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP1_PICKUP4_MAX/1000;
      *p_shift = ZOP1_PICKUP4_SHIFT;
        
      break;
    }
  case 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP1_PICKUP5_MAX/1000;
      *p_shift = ZOP1_PICKUP5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 0:
    {
      p_pickup_dimention = gradus;
      
      *p_max = ZOP2_PICKUP0_MAX;
      *p_shift = ZOP2_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP2_PICKUP1_MAX/1000;
      *p_shift = ZOP2_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP2_PICKUP2_MAX/1000;
      *p_shift = ZOP2_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP2_PICKUP3_MAX/1000;
      *p_shift = ZOP2_PICKUP3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP2_PICKUP4_MAX/1000;
      *p_shift = ZOP2_PICKUP4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_ZOP1 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = ZOP2_PICKUP5_MAX/1000;
      *p_shift = ZOP2_PICKUP5_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки ZOP
**********/
const char* ZOP_delay_info_1(
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
      *p_max = ZOP1_DELAY0_MAX/100;
      *p_shift = ZOP1_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = ZOP1_DELAY1_MAX/100;
      *p_shift = ZOP1_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = ZOP1_DELAY2_MAX/100;
      *p_shift = ZOP1_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 0:
    {
      *p_max = ZOP2_DELAY0_MAX/100;
      *p_shift = ZOP2_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 1:
    {
      *p_max = ZOP2_DELAY1_MAX/100;
      *p_shift = ZOP2_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_ZOP1 + 2:
    {
      *p_max = ZOP2_DELAY2_MAX/100;
      *p_shift = ZOP2_DELAY2_SHIFT;
        
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
const char* ZOP_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 0:
  case MAX_NUMBER_PICKUP_ZOP1 + 0:
    {
      p_pickup_dimention = gradus;
      break;
    }
  case 1:
  case 3:
  case 5:
  case MAX_NUMBER_PICKUP_ZOP1 + 1:
  case MAX_NUMBER_PICKUP_ZOP1 + 3:
  case MAX_NUMBER_PICKUP_ZOP1 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
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
Отримання інформації для формувнні назв станів для ZOP
**********/
const TITLE* ZOP_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (
      (number == 1) ||
      (number == (MAX_NUMBER_CTRL_ZOP1+1))
     )   
  {
    p_control_list_name = SELECTOR;
  }
  else if (
           (number == 2) ||
           (number == (MAX_NUMBER_CTRL_ZOP1+2))
          )   
  {
    p_control_list_name = NAPRJAMOK_1;
  }
  else
  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для ZOP
**********/
unsigned char* ZOP_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1NspMng.state_dir_zop;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1NspMng.select_prt_zop;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrStg1NspMng.select_dir_zop;
      break;
    }
  case MAX_NUMBER_CTRL_ZOP1 + 0:
    {
      p_to_state = &point->ownrStg2NspMng.state_dir_zop;
      break;
    }
  case MAX_NUMBER_CTRL_ZOP1 + 1:
    {
      p_to_state = &point->ownrStg2NspMng.select_prt_zop;
      break;
    }
  case MAX_NUMBER_CTRL_ZOP1 + 2:
    {
      p_to_state = &point->ownrStg2NspMng.select_dir_zop;
      break;
    }
  default: break;
  }
  
  return p_to_state;
}
/**********/

/**********
Функція яка виконує певні дії після зміни деяких налаштувань
**********/
void ZOP_change_state_callback(
                               unsigned int number,
                               CfgTblDsc *point
                              )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_ZOP(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_ZOP) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = ZOP1_PICKUP0_MIN;
          max = ZOP1_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;

          break;
        }
      case 1:
        {
          min = ZOP1_PICKUP1_MIN;
          max = ZOP1_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_I2;

          break;
        }
      case 2:
        {
          min = ZOP1_PICKUP2_MIN;
          max = ZOP1_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_U2;

          break;
        }
      case 3:
        {
          min = ZOP1_PICKUP3_MIN;
          max = ZOP1_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_I2;

          break;
        }
      case 4:
        {
          min = ZOP1_PICKUP4_MIN;
          max = ZOP1_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_U2;

          break;
        }
      case 5:
        {
          min = ZOP1_PICKUP5_MIN;
          max = ZOP1_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspPickupStoreDsc.ov_range_Zop_I2;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 0:
        {
          min = ZOP2_PICKUP0_MIN;
          max = ZOP2_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 1:
        {
          min = ZOP2_PICKUP1_MIN;
          max = ZOP2_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_I2;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 2:
        {
          min = ZOP2_PICKUP2_MIN;
          max = ZOP2_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_U2;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 3:
        {
          min = ZOP2_PICKUP3_MIN;
          max = ZOP2_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_I2;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 4:
        {
          min = ZOP2_PICKUP4_MIN;
          max = ZOP2_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_U2;

          break;
        }
      case MAX_NUMBER_PICKUP_ZOP1 + 5:
        {
          min = ZOP2_PICKUP5_MIN;
          max = ZOP2_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspPickupStoreDsc.ov_range_Zop_I2;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_ZOP) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = ZOP1_DELAY0_MIN;
          max = ZOP1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspStageParamStoreDsc.time_stage_Zop;

          break;
        }
      case 1:
        {
          min = ZOP1_DELAY1_MIN;
          max = ZOP1_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_s;

          break;
        }
      case 2:
        {
          min = ZOP1_DELAY2_MIN;
          max = ZOP1_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1NspStageParamStoreDsc.time_stage_Zop_b;

          break;
        }
      case MAX_NUMBER_DELAY_ZOP1 + 0:
        {
          min = ZOP2_DELAY0_MIN;
          max = ZOP2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspStageParamStoreDsc.time_stage_Zop;

          break;
        }
      case MAX_NUMBER_DELAY_ZOP1 + 1:
        {
          min = ZOP2_DELAY1_MIN;
          max = ZOP2_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_s;

          break;
        }
      case MAX_NUMBER_DELAY_ZOP1 + 2:
        {
          min = ZOP2_DELAY2_MIN;
          max = ZOP2_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2NspStageParamStoreDsc.time_stage_Zop_b;

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
void copy_data_ZOP(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc = 
    source->arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc; 

    target->arPckpStpmStngStore[i].ownrStage1NspStageParamStoreDsc = 
    source->arPckpStpmStngStore[i].ownrStage1NspStageParamStoreDsc; 

    target->arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc = 
    source->arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc; 

    target->arPckpStpmStngStore[i].ownrStage2NspStageParamStoreDsc = 
    source->arPckpStpmStngStore[i].ownrStage2NspStageParamStoreDsc; 
  }
  target->ownrStg1NspMng = source->ownrStg1NspMng;
  target->ownrStg2NspMng = source->ownrStg2NspMng;
}
/*****************************/
