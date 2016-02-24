#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* TZNP_pickups_notification_value_changed (
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
  case ID_ED_TZNP_PICKUP_VALUE_0:
    {
      *p_min = TZNP1_PICKUP0_MIN;
      *p_max = TZNP1_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;

      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_1:
    {
      *p_min = TZNP1_PICKUP1_MIN;
      *p_max = TZNP1_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.ov_range_3Io_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_2:
    {
      *p_min = TZNP1_PICKUP2_MIN;
      *p_max = TZNP1_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.ov_range_3Uo_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_3:
    {
      *p_min = TZNP2_PICKUP0_MIN;
      *p_max = TZNP2_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;

      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_4:
    {
      *p_min = TZNP2_PICKUP1_MIN;
      *p_max = TZNP2_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.ov_range_3Io_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_5:
    {
      *p_min = TZNP2_PICKUP2_MIN;
      *p_max = TZNP2_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.ov_range_3Uo_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_6:
    {
      *p_min = TZNP3_PICKUP0_MIN;
      *p_max = TZNP3_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;

      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_7:
    {
      *p_min = TZNP3_PICKUP1_MIN;
      *p_max = TZNP3_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.ov_range_3Io_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_8:
    {
      *p_min = TZNP3_PICKUP2_MIN;
      *p_max = TZNP3_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.ov_range_3Uo_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_9:
    {
      *p_min = TZNP4_PICKUP0_MIN;
      *p_max = TZNP4_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;

      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_10:
    {
      *p_min = TZNP4_PICKUP1_MIN;
      *p_max = TZNP4_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.ov_range_3Io_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_11:
    {
      *p_min = TZNP4_PICKUP2_MIN;
      *p_max = TZNP4_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.ov_range_3Uo_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_12:
    {
      *p_min = TZNP5_PICKUP0_MIN;
      *p_max = TZNP5_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;

      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_13:
    {
      *p_min = TZNP5_PICKUP1_MIN;
      *p_max = TZNP5_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.ov_range_3Io_Tznp;
      break;
    }
  case ID_ED_TZNP_PICKUP_VALUE_14:
    {
      *p_min = TZNP5_PICKUP2_MIN;
      *p_max = TZNP5_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.ov_range_3Uo_Tznp;
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

unsigned short int* TZNP_delays_notification_value_changed (
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
  case ID_ED_TZNP_DELAY_VALUE_0:
    {
      *p_min = TZNP1_DELAY0_MIN;
      *p_max = TZNP1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.time_Tznp;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_1:
    {
      *p_min = TZNP1_DELAY1_MIN;
      *p_max = TZNP1_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_2:
    {
      *p_min = TZNP1_DELAY2_MIN;
      *p_max = TZNP1_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_3:
    {
      *p_min = TZNP1_DELAY3_MIN;
      *p_max = TZNP1_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_4:
    {
      *p_min = TZNP1_DELAY4_MIN;
      *p_max = TZNP1_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_3I0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_5:
    {
      *p_min = TZNP1_DELAY5_MIN;
      *p_max = TZNP1_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_6:
    {
      *p_min = TZNP1_DELAY6_MIN;
      *p_max = TZNP1_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_7:
    {
      *p_min = TZNP1_DELAY7_MIN;
      *p_max = TZNP1_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_8:
    {
      *p_min = TZNP1_DELAY8_MIN;
      *p_max = TZNP1_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_3U0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_9:
    {
      *p_min = TZNP1_DELAY9_MIN;
      *p_max = TZNP1_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_Tau_AcltImp;

      break;
    }

  case ID_ED_TZNP_DELAY_VALUE_10:
    {
      *p_min = TZNP2_DELAY0_MIN;
      *p_max = TZNP2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.time_Tznp;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_11:
    {
      *p_min = TZNP2_DELAY1_MIN;
      *p_max = TZNP2_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_12:
    {
      *p_min = TZNP2_DELAY2_MIN;
      *p_max = TZNP2_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_13:
    {
      *p_min = TZNP2_DELAY3_MIN;
      *p_max = TZNP2_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_14:
    {
      *p_min = TZNP2_DELAY4_MIN;
      *p_max = TZNP2_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_3I0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_15:
    {
      *p_min = TZNP2_DELAY5_MIN;
      *p_max = TZNP2_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_16:
    {
      *p_min = TZNP2_DELAY6_MIN;
      *p_max = TZNP2_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_17:
    {
      *p_min = TZNP2_DELAY7_MIN;
      *p_max = TZNP2_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_18:
    {
      *p_min = TZNP2_DELAY8_MIN;
      *p_max = TZNP2_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_3U0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_19:
    {
      *p_min = TZNP2_DELAY9_MIN;
      *p_max = TZNP2_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_Tau_AcltImp;

      break;
    }

  case ID_ED_TZNP_DELAY_VALUE_20:
    {
      *p_min = TZNP3_DELAY0_MIN;
      *p_max = TZNP3_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.time_Tznp;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_21:
    {
      *p_min = TZNP3_DELAY1_MIN;
      *p_max = TZNP3_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_22:
    {
      *p_min = TZNP3_DELAY2_MIN;
      *p_max = TZNP3_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_23:
    {
      *p_min = TZNP3_DELAY3_MIN;
      *p_max = TZNP3_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_24:
    {
      *p_min = TZNP3_DELAY4_MIN;
      *p_max = TZNP3_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_3I0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_25:
    {
      *p_min = TZNP3_DELAY5_MIN;
      *p_max = TZNP3_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_26:
    {
      *p_min = TZNP3_DELAY6_MIN;
      *p_max = TZNP3_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_27:
    {
      *p_min = TZNP3_DELAY7_MIN;
      *p_max = TZNP3_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_28:
    {
      *p_min = TZNP3_DELAY8_MIN;
      *p_max = TZNP3_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_3U0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_29:
    {
      *p_min = TZNP3_DELAY9_MIN;
      *p_max = TZNP3_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_Tau_AcltImp;

      break;
    }

  case ID_ED_TZNP_DELAY_VALUE_30:
    {
      *p_min = TZNP4_DELAY0_MIN;
      *p_max = TZNP4_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.time_Tznp;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_31:
    {
      *p_min = TZNP4_DELAY1_MIN;
      *p_max = TZNP4_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_32:
    {
      *p_min = TZNP4_DELAY2_MIN;
      *p_max = TZNP4_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_33:
    {
      *p_min = TZNP4_DELAY3_MIN;
      *p_max = TZNP4_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_34:
    {
      *p_min = TZNP4_DELAY4_MIN;
      *p_max = TZNP4_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_3I0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_35:
    {
      *p_min = TZNP4_DELAY5_MIN;
      *p_max = TZNP4_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_36:
    {
      *p_min = TZNP4_DELAY6_MIN;
      *p_max = TZNP4_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_37:
    {
      *p_min = TZNP4_DELAY7_MIN;
      *p_max = TZNP4_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_38:
    {
      *p_min = TZNP4_DELAY8_MIN;
      *p_max = TZNP4_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_3U0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_39:
    {
      *p_min = TZNP4_DELAY9_MIN;
      *p_max = TZNP4_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_Tau_AcltImp;

      break;
    }

  case ID_ED_TZNP_DELAY_VALUE_40:
    {
      *p_min = TZNP5_DELAY0_MIN;
      *p_max = TZNP5_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.time_Tznp;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_41:
    {
      *p_min = TZNP5_DELAY1_MIN;
      *p_max = TZNP5_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_42:
    {
      *p_min = TZNP5_DELAY2_MIN;
      *p_max = TZNP5_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_43:
    {
      *p_min = TZNP5_DELAY3_MIN;
      *p_max = TZNP5_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_44:
    {
      *p_min = TZNP5_DELAY4_MIN;
      *p_max = TZNP5_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_3I0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_45:
    {
      *p_min = TZNP5_DELAY5_MIN;
      *p_max = TZNP5_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_time_stage_Aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_46:
    {
      *p_min = TZNP5_DELAY6_MIN;
      *p_max = TZNP5_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_T_op_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_47:
    {
      *p_min = TZNP5_DELAY7_MIN;
      *p_max = TZNP5_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_T_tele_aclt;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_48:
    {
      *p_min = TZNP5_DELAY8_MIN;
      *p_max = TZNP5_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_3U0;

      break;
    }
  case ID_ED_TZNP_DELAY_VALUE_49:
    {
      *p_min = TZNP5_DELAY9_MIN;
      *p_max = TZNP5_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_Tau_AcltImp;

      break;
    }
    
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки TZNP
**********/
void TZNP_pickup_info(
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
      *p_min = TZNP1_PICKUP0_MIN;
      *p_max = TZNP1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;
      *value = (float)(*p_value_int);
      break;
    }
  case 1:
    {
      *p_min = TZNP1_PICKUP1_MIN;
      *p_max = TZNP1_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.ov_range_3Io_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 2:
    {
      *p_min = TZNP1_PICKUP2_MIN;
      *p_max = TZNP1_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthPickup.ov_range_3Uo_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 0:
    {
      *p_min = TZNP2_PICKUP0_MIN;
      *p_max = TZNP2_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 1:
    {
      *p_min = TZNP2_PICKUP1_MIN;
      *p_max = TZNP2_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.ov_range_3Io_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 2:
    {
      *p_min = TZNP2_PICKUP2_MIN;
      *p_max = TZNP2_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthPickup.ov_range_3Uo_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 0:
    {
      *p_min = TZNP3_PICKUP0_MIN;
      *p_max = TZNP3_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 1:
    {
      *p_min = TZNP3_PICKUP1_MIN;
      *p_max = TZNP3_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.ov_range_3Io_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 2:
    {
      *p_min = TZNP3_PICKUP2_MIN;
      *p_max = TZNP3_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthPickup.ov_range_3Uo_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 0:
    {
      *p_min = TZNP4_PICKUP0_MIN;
      *p_max = TZNP4_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 1:
    {
      *p_min = TZNP4_PICKUP1_MIN;
      *p_max = TZNP4_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.ov_range_3Io_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 2:
    {
      *p_min = TZNP4_PICKUP2_MIN;
      *p_max = TZNP4_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthPickup.ov_range_3Uo_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 0:
    {
      *p_min = TZNP5_PICKUP0_MIN;
      *p_max = TZNP5_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 1:
    {
      *p_min = TZNP5_PICKUP1_MIN;
      *p_max = TZNP5_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.ov_range_3Io_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 2:
    {
      *p_min = TZNP5_PICKUP2_MIN;
      *p_max = TZNP5_PICKUP2_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthPickup.ov_range_3Uo_Tznp;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки TZNP
**********/
void TZNP_delay_info(
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
      *p_min = TZNP1_DELAY0_MIN;
      *p_max = TZNP1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.time_Tznp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = TZNP1_DELAY1_MIN;
      *p_max = TZNP1_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = TZNP1_DELAY2_MIN;
      *p_max = TZNP1_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 3:
    {
      *p_min = TZNP1_DELAY3_MIN;
      *p_max = TZNP1_DELAY3_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 4:
    {
      *p_min = TZNP1_DELAY4_MIN;
      *p_max = TZNP1_DELAY4_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_3I0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 5:
    {
      *p_min = TZNP1_DELAY5_MIN;
      *p_max = TZNP1_DELAY5_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 6:
    {
      *p_min = TZNP1_DELAY6_MIN;
      *p_max = TZNP1_DELAY6_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 7:
    {
      *p_min = TZNP1_DELAY7_MIN;
      *p_max = TZNP1_DELAY7_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp3I0_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 8:
    {
      *p_min = TZNP1_DELAY8_MIN;
      *p_max = TZNP1_DELAY8_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_time_stage_3U0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 9:
    {
      *p_min = TZNP1_DELAY9_MIN;
      *p_max = TZNP1_DELAY9_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage1DrErthStageParam.Tznp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + 0:
    {
      *p_min = TZNP2_DELAY0_MIN;
      *p_max = TZNP2_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.time_Tznp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 1:
    {
      *p_min = TZNP2_DELAY1_MIN;
      *p_max = TZNP2_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 2:
    {
      *p_min = TZNP2_DELAY2_MIN;
      *p_max = TZNP2_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 3:
    {
      *p_min = TZNP2_DELAY3_MIN;
      *p_max = TZNP2_DELAY3_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 4:
    {
      *p_min = TZNP2_DELAY4_MIN;
      *p_max = TZNP2_DELAY4_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_3I0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 5:
    {
      *p_min = TZNP2_DELAY5_MIN;
      *p_max = TZNP2_DELAY5_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 6:
    {
      *p_min = TZNP2_DELAY6_MIN;
      *p_max = TZNP2_DELAY6_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 7:
    {
      *p_min = TZNP2_DELAY7_MIN;
      *p_max = TZNP2_DELAY7_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp3I0_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 8:
    {
      *p_min = TZNP2_DELAY8_MIN;
      *p_max = TZNP2_DELAY8_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_time_stage_3U0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 9:
    {
      *p_min = TZNP2_DELAY9_MIN;
      *p_max = TZNP2_DELAY9_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage2DrErthStageParam.Tznp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 0:
    {
      *p_min = TZNP3_DELAY0_MIN;
      *p_max = TZNP3_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.time_Tznp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 1:
    {
      *p_min = TZNP3_DELAY1_MIN;
      *p_max = TZNP3_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 2:
    {
      *p_min = TZNP3_DELAY2_MIN;
      *p_max = TZNP3_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 3:
    {
      *p_min = TZNP3_DELAY3_MIN;
      *p_max = TZNP3_DELAY3_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 4:
    {
      *p_min = TZNP3_DELAY4_MIN;
      *p_max = TZNP3_DELAY4_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_3I0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 5:
    {
      *p_min = TZNP3_DELAY5_MIN;
      *p_max = TZNP3_DELAY5_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 6:
    {
      *p_min = TZNP3_DELAY6_MIN;
      *p_max = TZNP3_DELAY6_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 7:
    {
      *p_min = TZNP3_DELAY7_MIN;
      *p_max = TZNP3_DELAY7_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp3I0_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 8:
    {
      *p_min = TZNP3_DELAY8_MIN;
      *p_max = TZNP3_DELAY8_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_time_stage_3U0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 9:
    {
      *p_min = TZNP3_DELAY9_MIN;
      *p_max = TZNP3_DELAY9_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage3DrErthStageParam.Tznp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 0:
    {
      *p_min = TZNP4_DELAY0_MIN;
      *p_max = TZNP4_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.time_Tznp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 1:
    {
      *p_min = TZNP4_DELAY1_MIN;
      *p_max = TZNP4_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 2:
    {
      *p_min = TZNP4_DELAY2_MIN;
      *p_max = TZNP4_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 3:
    {
      *p_min = TZNP4_DELAY3_MIN;
      *p_max = TZNP4_DELAY3_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 4:
    {
      *p_min = TZNP4_DELAY4_MIN;
      *p_max = TZNP4_DELAY4_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_3I0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 5:
    {
      *p_min = TZNP4_DELAY5_MIN;
      *p_max = TZNP4_DELAY5_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 6:
    {
      *p_min = TZNP4_DELAY6_MIN;
      *p_max = TZNP4_DELAY6_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 7:
    {
      *p_min = TZNP4_DELAY7_MIN;
      *p_max = TZNP4_DELAY7_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp3I0_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 8:
    {
      *p_min = TZNP4_DELAY8_MIN;
      *p_max = TZNP4_DELAY8_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_time_stage_3U0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 9:
    {
      *p_min = TZNP4_DELAY9_MIN;
      *p_max = TZNP4_DELAY9_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage4DrErthStageParam.Tznp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 0:
    {
      *p_min = TZNP5_DELAY0_MIN;
      *p_max = TZNP5_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.time_Tznp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 1:
    {
      *p_min = TZNP5_DELAY1_MIN;
      *p_max = TZNP5_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 2:
    {
      *p_min = TZNP5_DELAY2_MIN;
      *p_max = TZNP5_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 3:
    {
      *p_min = TZNP5_DELAY3_MIN;
      *p_max = TZNP5_DELAY3_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 4:
    {
      *p_min = TZNP5_DELAY4_MIN;
      *p_max = TZNP5_DELAY4_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_3I0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 5:
    {
      *p_min = TZNP5_DELAY5_MIN;
      *p_max = TZNP5_DELAY5_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 6:
    {
      *p_min = TZNP5_DELAY6_MIN;
      *p_max = TZNP5_DELAY6_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 7:
    {
      *p_min = TZNP5_DELAY7_MIN;
      *p_max = TZNP5_DELAY7_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp3I0_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 8:
    {
      *p_min = TZNP5_DELAY8_MIN;
      *p_max = TZNP5_DELAY8_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_time_stage_3U0;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 9:
    {
      *p_min = TZNP5_DELAY9_MIN;
      *p_max = TZNP5_DELAY9_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[TZNP_select_group].ownrStage5DrErthStageParam.Tznp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки TZNP
**********/
const char* TZNP_pickup_info_1(
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
      
      *p_max = TZNP1_PICKUP0_MAX;
      *p_shift = TZNP1_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP1_PICKUP1_MAX/1000;
      *p_shift = TZNP1_PICKUP1_SHIFT;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP1_PICKUP2_MAX/1000;
      *p_shift = TZNP1_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 0:
    {
      p_pickup_dimention = gradus;
      
      *p_max = TZNP2_PICKUP0_MAX;
      *p_shift = TZNP2_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP2_PICKUP1_MAX/1000;
      *p_shift = TZNP2_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP2_PICKUP2_MAX/1000;
      *p_shift = TZNP2_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 0:
    {
      p_pickup_dimention = gradus;
      
      *p_max = TZNP3_PICKUP0_MAX;
      *p_shift = TZNP3_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP3_PICKUP1_MAX/1000;
      *p_shift = TZNP3_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP3_PICKUP2_MAX/1000;
      *p_shift = TZNP3_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 0:
    {
      p_pickup_dimention = gradus;
      
      *p_max = TZNP4_PICKUP0_MAX;
      *p_shift = TZNP4_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP4_PICKUP1_MAX/1000;
      *p_shift = TZNP4_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP4_PICKUP2_MAX/1000;
      *p_shift = TZNP4_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 +MAX_NUMBER_PICKUP_TZNP4 + 0:
    {
      p_pickup_dimention = gradus;
      
      *p_max = TZNP5_PICKUP0_MAX;
      *p_shift = TZNP5_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 +MAX_NUMBER_PICKUP_TZNP4 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP5_PICKUP1_MAX/1000;
      *p_shift = TZNP5_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 +MAX_NUMBER_PICKUP_TZNP4 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = TZNP5_PICKUP2_MAX/1000;
      *p_shift = TZNP5_PICKUP2_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки TZNP
**********/
const char* TZNP_delay_info_1(
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
      *p_max = TZNP1_DELAY0_MAX/100;
      *p_shift = TZNP1_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = TZNP1_DELAY1_MAX/100;
      *p_shift = TZNP1_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = TZNP1_DELAY2_MAX/100;
      *p_shift = TZNP1_DELAY2_SHIFT;
        
      break;
    }
  case 3:
    {
      *p_max = TZNP1_DELAY3_MAX/100;
      *p_shift = TZNP1_DELAY3_SHIFT;
        
      break;
    }
  case 4:
    {
      *p_max = TZNP1_DELAY4_MAX/100;
      *p_shift = TZNP1_DELAY4_SHIFT;
        
      break;
    }
  case 5:
    {
      *p_max = TZNP1_DELAY5_MAX/100;
      *p_shift = TZNP1_DELAY5_SHIFT;
        
      break;
    }
  case 6:
    {
      *p_max = TZNP1_DELAY6_MAX/100;
      *p_shift = TZNP1_DELAY6_SHIFT;
        
      break;
    }
  case 7:
    {
      *p_max = TZNP1_DELAY7_MAX/100;
      *p_shift = TZNP1_DELAY7_SHIFT;
        
      break;
    }
  case 8:
    {
      *p_max = TZNP1_DELAY8_MAX/100;
      *p_shift = TZNP1_DELAY8_SHIFT;
        
      break;
    }
  case 9:
    {
      *p_max = TZNP1_DELAY9_MAX/100;
      *p_shift = TZNP1_DELAY9_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + 0:
    {
      *p_max = TZNP2_DELAY0_MAX/100;
      *p_shift = TZNP2_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 1:
    {
      *p_max = TZNP2_DELAY1_MAX/100;
      *p_shift = TZNP2_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 2:
    {
      *p_max = TZNP2_DELAY2_MAX/100;
      *p_shift = TZNP2_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 3:
    {
      *p_max = TZNP2_DELAY3_MAX/100;
      *p_shift = TZNP2_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 4:
    {
      *p_max = TZNP2_DELAY4_MAX/100;
      *p_shift = TZNP2_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 5:
    {
      *p_max = TZNP2_DELAY5_MAX/100;
      *p_shift = TZNP2_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 6:
    {
      *p_max = TZNP2_DELAY6_MAX/100;
      *p_shift = TZNP2_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 7:
    {
      *p_max = TZNP2_DELAY7_MAX/100;
      *p_shift = TZNP2_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 8:
    {
      *p_max = TZNP2_DELAY8_MAX/100;
      *p_shift = TZNP2_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + 9:
    {
      *p_max = TZNP2_DELAY9_MAX/100;
      *p_shift = TZNP2_DELAY9_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 0:
    {
      *p_max = TZNP3_DELAY0_MAX/100;
      *p_shift = TZNP3_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 1:
    {
      *p_max = TZNP3_DELAY1_MAX/100;
      *p_shift = TZNP3_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 2:
    {
      *p_max = TZNP3_DELAY2_MAX/100;
      *p_shift = TZNP3_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 3:
    {
      *p_max = TZNP3_DELAY3_MAX/100;
      *p_shift = TZNP3_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 4:
    {
      *p_max = TZNP3_DELAY4_MAX/100;
      *p_shift = TZNP3_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 5:
    {
      *p_max = TZNP3_DELAY5_MAX/100;
      *p_shift = TZNP3_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 6:
    {
      *p_max = TZNP3_DELAY6_MAX/100;
      *p_shift = TZNP3_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 7:
    {
      *p_max = TZNP3_DELAY7_MAX/100;
      *p_shift = TZNP3_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 8:
    {
      *p_max = TZNP3_DELAY8_MAX/100;
      *p_shift = TZNP3_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 9:
    {
      *p_max = TZNP3_DELAY9_MAX/100;
      *p_shift = TZNP3_DELAY9_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 0:
    {
      *p_max = TZNP4_DELAY0_MAX/100;
      *p_shift = TZNP4_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 1:
    {
      *p_max = TZNP4_DELAY1_MAX/100;
      *p_shift = TZNP4_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 2:
    {
      *p_max = TZNP4_DELAY2_MAX/100;
      *p_shift = TZNP4_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 3:
    {
      *p_max = TZNP4_DELAY3_MAX/100;
      *p_shift = TZNP4_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 4:
    {
      *p_max = TZNP4_DELAY4_MAX/100;
      *p_shift = TZNP4_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 5:
    {
      *p_max = TZNP4_DELAY5_MAX/100;
      *p_shift = TZNP4_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 6:
    {
      *p_max = TZNP4_DELAY6_MAX/100;
      *p_shift = TZNP4_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 7:
    {
      *p_max = TZNP4_DELAY7_MAX/100;
      *p_shift = TZNP4_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 8:
    {
      *p_max = TZNP4_DELAY8_MAX/100;
      *p_shift = TZNP4_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 9:
    {
      *p_max = TZNP4_DELAY9_MAX/100;
      *p_shift = TZNP4_DELAY9_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 0:
    {
      *p_max = TZNP5_DELAY0_MAX/100;
      *p_shift = TZNP5_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 1:
    {
      *p_max = TZNP5_DELAY1_MAX/100;
      *p_shift = TZNP5_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 2:
    {
      *p_max = TZNP5_DELAY2_MAX/100;
      *p_shift = TZNP5_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 3:
    {
      *p_max = TZNP5_DELAY3_MAX/100;
      *p_shift = TZNP5_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 4:
    {
      *p_max = TZNP5_DELAY4_MAX/100;
      *p_shift = TZNP5_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 5:
    {
      *p_max = TZNP5_DELAY5_MAX/100;
      *p_shift = TZNP5_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 6:
    {
      *p_max = TZNP5_DELAY6_MAX/100;
      *p_shift = TZNP5_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 7:
    {
      *p_max = TZNP5_DELAY7_MAX/100;
      *p_shift = TZNP5_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 8:
    {
      *p_max = TZNP5_DELAY8_MAX/100;
      *p_shift = TZNP5_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 9:
    {
      *p_max = TZNP5_DELAY9_MAX/100;
      *p_shift = TZNP5_DELAY9_SHIFT;
        
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
const char* TZNP_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 0:
  case MAX_NUMBER_PICKUP_TZNP1 + 0:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 0:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 0:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 0:
    {
      p_pickup_dimention = gradus;
      break;
    }
  case 1:
  case MAX_NUMBER_PICKUP_TZNP1 + 1:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 1:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 1:
  case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 1:
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
Отримання інформації для формувнні назв станів для TZNP
**********/
const TITLE* TZNP_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (
      (number == 1) ||
      (number == (MAX_NUMBER_CTRL_TZNP1+1)) ||
      (number == (MAX_NUMBER_CTRL_TZNP1+MAX_NUMBER_CTRL_TZNP2+1)) ||
      (number == (MAX_NUMBER_CTRL_TZNP1+MAX_NUMBER_CTRL_TZNP2+MAX_NUMBER_CTRL_TZNP3+1)) ||
      (number == (MAX_NUMBER_CTRL_TZNP1+MAX_NUMBER_CTRL_TZNP2+MAX_NUMBER_CTRL_TZNP3+MAX_NUMBER_CTRL_TZNP4+1))
     )   
  {
    p_control_list_name = NAPRJAMOK;
  }
  else
  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для TZNP
**********/
unsigned char* TZNP_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1DrErthMng.state_Tznp;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1DrErthMng.direction_Tznp1;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrStg1DrErthMng.state_Tznp_3U0;
      break;
    }
  case 3:
    {
      p_to_state = &point->ownrStg1DrErthMng.state_Tznp_3I0;
      break;
    }
  case 4:
    {
      p_to_state = &point->ownrStg1DrErthMng.state_Tele_aclt_Tznp;
      break;
    }
  case 5:
    {
      p_to_state = &point->ownrStg1DrErthMng.state_Auto_aclt_Tznp;
      break;
    }
  case 6:
    {
      p_to_state = &point->ownrStg1DrErthMng.aclt_Tznp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 0:
    {
      p_to_state = &point->ownrStg2DrErthMng.state_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 1:
    {
      p_to_state = &point->ownrStg2DrErthMng.direction_Tznp1;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 2:
    {
      p_to_state = &point->ownrStg2DrErthMng.state_Tznp_3U0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 3:
    {
      p_to_state = &point->ownrStg2DrErthMng.state_Tznp_3I0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 4:
    {
      p_to_state = &point->ownrStg2DrErthMng.state_Tele_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 5:
    {
      p_to_state = &point->ownrStg2DrErthMng.state_Auto_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + 6:
    {
      p_to_state = &point->ownrStg2DrErthMng.aclt_Tznp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 0:
    {
      p_to_state = &point->ownrStg3DrErthMng.state_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 1:
    {
      p_to_state = &point->ownrStg3DrErthMng.direction_Tznp1;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 2:
    {
      p_to_state = &point->ownrStg3DrErthMng.state_Tznp_3U0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 3:
    {
      p_to_state = &point->ownrStg3DrErthMng.state_Tznp_3I0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 4:
    {
      p_to_state = &point->ownrStg3DrErthMng.state_Tele_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 5:
    {
      p_to_state = &point->ownrStg3DrErthMng.state_Auto_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + 6:
    {
      p_to_state = &point->ownrStg3DrErthMng.aclt_Tznp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 0:
    {
      p_to_state = &point->ownrStg4DrErthMng.state_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 1:
    {
      p_to_state = &point->ownrStg4DrErthMng.direction_Tznp1;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 2:
    {
      p_to_state = &point->ownrStg4DrErthMng.state_Tznp_3U0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 3:
    {
      p_to_state = &point->ownrStg4DrErthMng.state_Tznp_3I0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 4:
    {
      p_to_state = &point->ownrStg4DrErthMng.state_Tele_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 5:
    {
      p_to_state = &point->ownrStg4DrErthMng.state_Auto_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + 6:
    {
      p_to_state = &point->ownrStg4DrErthMng.aclt_Tznp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 0:
    {
      p_to_state = &point->ownrStg5DrErthMng.state_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 1:
    {
      p_to_state = &point->ownrStg5DrErthMng.direction_Tznp1;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 2:
    {
      p_to_state = &point->ownrStg5DrErthMng.state_Tznp_3U0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 3:
    {
      p_to_state = &point->ownrStg5DrErthMng.state_Tznp_3I0;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 4:
    {
      p_to_state = &point->ownrStg5DrErthMng.state_Tele_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 5:
    {
      p_to_state = &point->ownrStg5DrErthMng.state_Auto_aclt_Tznp;
      break;
    }
  case MAX_NUMBER_CTRL_TZNP1 + MAX_NUMBER_CTRL_TZNP2 + MAX_NUMBER_CTRL_TZNP3 + MAX_NUMBER_CTRL_TZNP4 + 6:
    {
      p_to_state = &point->ownrStg5DrErthMng.aclt_Tznp_sw;
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
void TZNP_change_state_callback(
                                unsigned int number,
                                CfgTblDsc *point
                               )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_TZNP(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_TZNP) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = TZNP1_PICKUP0_MIN;
          max = TZNP1_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;

          break;
        }
      case 1:
        {
          min = TZNP1_PICKUP1_MIN;
          max = TZNP1_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthPickup.ov_range_3Io_Tznp;

          break;
        }
      case 2:
        {
          min = TZNP1_PICKUP2_MIN;
          max = TZNP1_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthPickup.ov_range_3Uo_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + 0:
        {
          min = TZNP2_PICKUP0_MIN;
          max = TZNP2_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + 1:
        {
          min = TZNP2_PICKUP1_MIN;
          max = TZNP2_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthPickup.ov_range_3Io_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + 2:
        {
          min = TZNP2_PICKUP2_MIN;
          max = TZNP2_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthPickup.ov_range_3Uo_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 0:
        {
          min = TZNP3_PICKUP0_MIN;
          max = TZNP3_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 1:
        {
          min = TZNP3_PICKUP1_MIN;
          max = TZNP3_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthPickup.ov_range_3Io_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + 2:
        {
          min = TZNP3_PICKUP2_MIN;
          max = TZNP3_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthPickup.ov_range_3Uo_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 0:
        {
          min = TZNP4_PICKUP0_MIN;
          max = TZNP4_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 1:
        {
          min = TZNP4_PICKUP1_MIN;
          max = TZNP4_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthPickup.ov_range_3Io_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + 2:
        {
          min = TZNP4_PICKUP2_MIN;
          max = TZNP4_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthPickup.ov_range_3Uo_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 0:
        {
          min = TZNP5_PICKUP0_MIN;
          max = TZNP5_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 1:
        {
          min = TZNP5_PICKUP1_MIN;
          max = TZNP5_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthPickup.ov_range_3Io_Tznp;

          break;
        }
      case MAX_NUMBER_PICKUP_TZNP1 + MAX_NUMBER_PICKUP_TZNP2 + MAX_NUMBER_PICKUP_TZNP3 + MAX_NUMBER_PICKUP_TZNP4 + 2:
        {
          min = TZNP5_PICKUP2_MIN;
          max = TZNP5_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthPickup.ov_range_3Uo_Tznp;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_TZNP) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = TZNP1_DELAY0_MIN;
          max = TZNP1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.time_Tznp;

          break;
        }
      case 1:
        {
          min = TZNP1_DELAY1_MIN;
          max = TZNP1_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_time_stage_Aclt;

          break;
        }
      case 2:
        {
          min = TZNP1_DELAY2_MIN;
          max = TZNP1_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_T_op_aclt;

          break;
        }
      case 3:
        {
          min = TZNP1_DELAY3_MIN;
          max = TZNP1_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_T_tele_aclt;

          break;
        }
      case 4:
        {
          min = TZNP1_DELAY4_MIN;
          max = TZNP1_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_time_stage_3I0;

          break;
        }
      case 5:
        {
          min = TZNP1_DELAY5_MIN;
          max = TZNP1_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp3I0_time_stage_Aclt;

          break;
        }
      case 6:
        {
          min = TZNP1_DELAY6_MIN;
          max = TZNP1_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp3I0_T_op_aclt;

          break;
        }
      case 7:
        {
          min = TZNP1_DELAY7_MIN;
          max = TZNP1_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp3I0_T_tele_aclt;

          break;
        }
      case 8:
        {
          min = TZNP1_DELAY8_MIN;
          max = TZNP1_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_time_stage_3U0;

          break;
        }
      case 9:
        {
          min = TZNP1_DELAY9_MIN;
          max = TZNP1_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrErthStageParam.Tznp_Tau_AcltImp;

          break;
        }
        
      case MAX_NUMBER_DELAY_TZNP1 + 0:
        {
          min = TZNP2_DELAY0_MIN;
          max = TZNP2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.time_Tznp;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 1:
        {
          min = TZNP2_DELAY1_MIN;
          max = TZNP2_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 2:
        {
          min = TZNP2_DELAY2_MIN;
          max = TZNP2_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 3:
        {
          min = TZNP2_DELAY3_MIN;
          max = TZNP2_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 4:
        {
          min = TZNP2_DELAY4_MIN;
          max = TZNP2_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_time_stage_3I0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 5:
        {
          min = TZNP2_DELAY5_MIN;
          max = TZNP2_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp3I0_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 6:
        {
          min = TZNP2_DELAY6_MIN;
          max = TZNP2_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp3I0_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 7:
        {
          min = TZNP2_DELAY7_MIN;
          max = TZNP2_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp3I0_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 8:
        {
          min = TZNP2_DELAY8_MIN;
          max = TZNP2_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_time_stage_3U0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + 9:
        {
          min = TZNP2_DELAY9_MIN;
          max = TZNP2_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrErthStageParam.Tznp_Tau_AcltImp;

          break;
        }
        
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 0:
        {
          min = TZNP3_DELAY0_MIN;
          max = TZNP3_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.time_Tznp;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 1:
        {
          min = TZNP3_DELAY1_MIN;
          max = TZNP3_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 2:
        {
          min = TZNP3_DELAY2_MIN;
          max = TZNP3_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 3:
        {
          min = TZNP3_DELAY3_MIN;
          max = TZNP3_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 4:
        {
          min = TZNP3_DELAY4_MIN;
          max = TZNP3_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_time_stage_3I0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 5:
        {
          min = TZNP3_DELAY5_MIN;
          max = TZNP3_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp3I0_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 6:
        {
          min = TZNP3_DELAY6_MIN;
          max = TZNP3_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp3I0_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 7:
        {
          min = TZNP3_DELAY7_MIN;
          max = TZNP3_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp3I0_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 8:
        {
          min = TZNP3_DELAY8_MIN;
          max = TZNP3_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_time_stage_3U0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + 9:
        {
          min = TZNP3_DELAY9_MIN;
          max = TZNP3_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrErthStageParam.Tznp_Tau_AcltImp;

          break;
        }
        
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 0:
        {
          min = TZNP4_DELAY0_MIN;
          max = TZNP4_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.time_Tznp;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 1:
        {
          min = TZNP4_DELAY1_MIN;
          max = TZNP4_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 2:
        {
          min = TZNP4_DELAY2_MIN;
          max = TZNP4_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 3:
        {
          min = TZNP4_DELAY3_MIN;
          max = TZNP4_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 4:
        {
          min = TZNP4_DELAY4_MIN;
          max = TZNP4_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_time_stage_3I0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 5:
        {
          min = TZNP4_DELAY5_MIN;
          max = TZNP4_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp3I0_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 6:
        {
          min = TZNP4_DELAY6_MIN;
          max = TZNP4_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp3I0_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 7:
        {
          min = TZNP4_DELAY7_MIN;
          max = TZNP4_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp3I0_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 8:
        {
          min = TZNP4_DELAY8_MIN;
          max = TZNP4_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_time_stage_3U0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + 9:
        {
          min = TZNP4_DELAY9_MIN;
          max = TZNP4_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrErthStageParam.Tznp_Tau_AcltImp;

          break;
        }
        
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 0:
        {
          min = TZNP5_DELAY0_MIN;
          max = TZNP5_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.time_Tznp;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 1:
        {
          min = TZNP5_DELAY1_MIN;
          max = TZNP5_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 2:
        {
          min = TZNP5_DELAY2_MIN;
          max = TZNP5_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 3:
        {
          min = TZNP5_DELAY3_MIN;
          max = TZNP5_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 4:
        {
          min = TZNP5_DELAY4_MIN;
          max = TZNP5_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_time_stage_3I0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 5:
        {
          min = TZNP5_DELAY5_MIN;
          max = TZNP5_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp3I0_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 6:
        {
          min = TZNP5_DELAY6_MIN;
          max = TZNP5_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp3I0_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 7:
        {
          min = TZNP5_DELAY7_MIN;
          max = TZNP5_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp3I0_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 8:
        {
          min = TZNP5_DELAY8_MIN;
          max = TZNP5_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_time_stage_3U0;

          break;
        }
      case MAX_NUMBER_DELAY_TZNP1 + MAX_NUMBER_DELAY_TZNP2 + MAX_NUMBER_DELAY_TZNP3 + MAX_NUMBER_DELAY_TZNP4 + 9:
        {
          min = TZNP5_DELAY9_MIN;
          max = TZNP5_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrErthStageParam.Tznp_Tau_AcltImp;

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
void copy_data_TZNP(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1DrErthPickup = 
    source->arPckpStpmStngStore[i].ownrStage1DrErthPickup; 

    target->arPckpStpmStngStore[i].ownrStage1DrErthStageParam = 
    source->arPckpStpmStngStore[i].ownrStage1DrErthStageParam; 

    target->arPckpStpmStngStore[i].ownrStage2DrErthPickup = 
    source->arPckpStpmStngStore[i].ownrStage2DrErthPickup; 

    target->arPckpStpmStngStore[i].ownrStage2DrErthStageParam = 
    source->arPckpStpmStngStore[i].ownrStage2DrErthStageParam; 

    target->arPckpStpmStngStore[i].ownrStage3DrErthPickup = 
    source->arPckpStpmStngStore[i].ownrStage3DrErthPickup; 

    target->arPckpStpmStngStore[i].ownrStage3DrErthStageParam = 
    source->arPckpStpmStngStore[i].ownrStage3DrErthStageParam; 

    target->arPckpStpmStngStore[i].ownrStage4DrErthPickup = 
    source->arPckpStpmStngStore[i].ownrStage4DrErthPickup; 

    target->arPckpStpmStngStore[i].ownrStage4DrErthStageParam = 
    source->arPckpStpmStngStore[i].ownrStage4DrErthStageParam; 

    target->arPckpStpmStngStore[i].ownrStage5DrErthPickup = 
    source->arPckpStpmStngStore[i].ownrStage5DrErthPickup; 

    target->arPckpStpmStngStore[i].ownrStage5DrErthStageParam = 
    source->arPckpStpmStngStore[i].ownrStage5DrErthStageParam; 
  }
  target->ownrStg1DrErthMng = source->ownrStg1DrErthMng;
  target->ownrStg2DrErthMng = source->ownrStg2DrErthMng;
  target->ownrStg3DrErthMng = source->ownrStg3DrErthMng;
  target->ownrStg4DrErthMng = source->ownrStg4DrErthMng;
  target->ownrStg5DrErthMng = source->ownrStg5DrErthMng;
}
/*****************************/
