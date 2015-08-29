#include "header_mal.h"

/**********
Дії по зміні значення уставки в функції _cbPickups_Protection
**********/

int* MTZ_pickups_notification_value_changed (
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
  case ID_ED_MTZ_PICKUP_VALUE_0:
    {
      *p_min = MTZ1_PICKUP0_MIN;
      *p_max = MTZ1_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_1:
    {
      *p_min = MTZ1_PICKUP1_MIN;
      *p_max = MTZ1_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_2:
    {
      *p_min = MTZ1_PICKUP2_MIN;
      *p_max = MTZ1_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_3:
    {
      *p_min = MTZ1_PICKUP3_MIN;
      *p_max = MTZ1_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_4:
    {
      *p_min = MTZ1_PICKUP4_MIN;
      *p_max = MTZ1_PICKUP4_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_5:
    {
      *p_min = MTZ1_PICKUP5_MIN;
      *p_max = MTZ1_PICKUP5_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_6:
    {
      *p_min = MTZ2_PICKUP0_MIN;
      *p_max = MTZ2_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_7:
    {
      *p_min = MTZ2_PICKUP1_MIN;
      *p_max = MTZ2_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_8:
    {
      *p_min = MTZ2_PICKUP2_MIN;
      *p_max = MTZ2_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_9:
    {
      *p_min = MTZ2_PICKUP3_MIN;
      *p_max = MTZ2_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_10:
    {
      *p_min = MTZ2_PICKUP4_MIN;
      *p_max = MTZ2_PICKUP4_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_11:
    {
      *p_min = MTZ2_PICKUP5_MIN;
      *p_max = MTZ2_PICKUP5_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_I_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_12:
    {
      *p_min = MTZ3_PICKUP0_MIN;
      *p_max = MTZ3_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_13:
    {
      *p_min = MTZ3_PICKUP1_MIN;
      *p_max = MTZ3_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_14:
    {
      *p_min = MTZ3_PICKUP2_MIN;
      *p_max = MTZ3_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_15:
    {
      *p_min = MTZ3_PICKUP3_MIN;
      *p_max = MTZ3_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_16:
    {
      *p_min = MTZ3_PICKUP4_MIN;
      *p_max = MTZ3_PICKUP4_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_17:
    {
      *p_min = MTZ3_PICKUP5_MIN;
      *p_max = MTZ3_PICKUP5_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_I_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_18:
    {
      *p_min = MTZ4_PICKUP0_MIN;
      *p_max = MTZ4_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_19:
    {
      *p_min = MTZ4_PICKUP1_MIN;
      *p_max = MTZ4_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_20:
    {
      *p_min = MTZ4_PICKUP2_MIN;
      *p_max = MTZ4_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_21:
    {
      *p_min = MTZ4_PICKUP3_MIN;
      *p_max = MTZ4_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_22:
    {
      *p_min = MTZ4_PICKUP4_MIN;
      *p_max = MTZ4_PICKUP4_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;
  
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_23:
    {
      *p_min = MTZ4_PICKUP5_MIN;
      *p_max = MTZ4_PICKUP5_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_I_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_24:
    {
      *p_min = MTZ5_PICKUP0_MIN;
      *p_max = MTZ5_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_25:
    {
      *p_min = MTZ5_PICKUP1_MIN;
      *p_max = MTZ5_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;
      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_26:
    {
      *p_min = MTZ5_PICKUP2_MIN;
      *p_max = MTZ5_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_27:
    {
      *p_min = MTZ5_PICKUP3_MIN;
      *p_max = MTZ5_PICKUP3_MAX;
     
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_28:
    {
      *p_min = MTZ5_PICKUP4_MIN;        
      *p_max = MTZ5_PICKUP4_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;

      break;
    }
  case ID_ED_MTZ_PICKUP_VALUE_29:
    {
      *p_min = MTZ5_PICKUP5_MIN;
      *p_max = MTZ5_PICKUP5_MAX;

      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_I_ov_range;

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

unsigned short int* MTZ_delays_notification_value_changed (
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
  case ID_ED_MTZ_DELAY_VALUE_0:
    {
      *p_min = MTZ1_DELAY0_MIN;
      *p_max = MTZ1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_1:
    {
      *p_min = MTZ1_DELAY1_MIN;
      *p_max = MTZ1_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_2:
    {
      *p_min = MTZ1_DELAY2_MIN;
      *p_max = MTZ1_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_3:
    {
      *p_min = MTZ1_DELAY3_MIN;
      *p_max = MTZ1_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_time_stage;

      break;
    }

  case ID_ED_MTZ_DELAY_VALUE_4:
    {
      *p_min = MTZ2_DELAY0_MIN;
      *p_max = MTZ2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_5:
    {
      *p_min = MTZ2_DELAY1_MIN;
      *p_max = MTZ2_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_6:
    {
      *p_min = MTZ2_DELAY2_MIN;
      *p_max = MTZ2_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_7:
    {
      *p_min = MTZ2_DELAY3_MIN;
      *p_max = MTZ2_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_8:
    {
      *p_min = MTZ2_DELAY4_MIN;
      *p_max = MTZ2_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_9:
    {
      *p_min = MTZ2_DELAY5_MIN;
      *p_max = MTZ2_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_10:
    {
      *p_min = MTZ2_DELAY6_MIN;
      *p_max = MTZ2_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_11:
    {
      *p_min = MTZ2_DELAY7_MIN;
      *p_max = MTZ2_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_12:
    {
      *p_min = MTZ2_DELAY8_MIN;
      *p_max = MTZ2_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_13:
    {
      *p_min = MTZ2_DELAY9_MIN;
      *p_max = MTZ2_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_14:
    {
      *p_min = MTZ2_DELAY10_MIN;
      *p_max = MTZ2_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_15:
    {
      *p_min = MTZ2_DELAY11_MIN;
      *p_max = MTZ2_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_16:
    {
      *p_min = MTZ2_DELAY12_MIN;
      *p_max = MTZ2_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_17:
    {
      *p_min = MTZ2_DELAY13_MIN;
      *p_max = MTZ2_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_18:
    {
      *p_min = MTZ2_DELAY14_MIN;
      *p_max = MTZ2_DELAY14_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_19:
    {
      *p_min = MTZ2_DELAY15_MIN;
      *p_max = MTZ2_DELAY15_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_20:
    {
      *p_min = MTZ2_DELAY16_MIN;
      *p_max = MTZ2_DELAY16_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;

      break;
    }

  case ID_ED_MTZ_DELAY_VALUE_21:
    {
      *p_min = MTZ3_DELAY0_MIN;
      *p_max = MTZ3_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_22:
    {
      *p_min = MTZ3_DELAY1_MIN;
      *p_max = MTZ3_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_23:
    {
      *p_min = MTZ3_DELAY2_MIN;
      *p_max = MTZ3_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_24:
    {
      *p_min = MTZ3_DELAY3_MIN;
      *p_max = MTZ3_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_25:
    {
      *p_min = MTZ3_DELAY4_MIN;
      *p_max = MTZ3_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_26:
    {
      *p_min = MTZ3_DELAY5_MIN;
      *p_max = MTZ3_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_27:
    {
      *p_min = MTZ3_DELAY6_MIN;
      *p_max = MTZ3_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_28:
    {
      *p_min = MTZ3_DELAY7_MIN;
      *p_max = MTZ3_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_29:
    {
      *p_min = MTZ3_DELAY8_MIN;
      *p_max = MTZ3_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_30:
    {
      *p_min = MTZ3_DELAY9_MIN;
      *p_max = MTZ3_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_31:
    {
      *p_min = MTZ3_DELAY10_MIN;
      *p_max = MTZ3_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_32:
    {
      *p_min = MTZ3_DELAY11_MIN;
      *p_max = MTZ3_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_33:
    {
      *p_min = MTZ3_DELAY12_MIN;
      *p_max = MTZ3_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_34:
    {
      *p_min = MTZ3_DELAY13_MIN;
      *p_max = MTZ3_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_35:
    {
      *p_min = MTZ3_DELAY14_MIN;
      *p_max = MTZ3_DELAY14_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_36:
    {
      *p_min = MTZ3_DELAY15_MIN;
      *p_max = MTZ3_DELAY15_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_37:
    {
      *p_min = MTZ3_DELAY16_MIN;
      *p_max = MTZ3_DELAY16_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;

      break;
    }

  case ID_ED_MTZ_DELAY_VALUE_38:
    {
      *p_min = MTZ4_DELAY0_MIN;
      *p_max = MTZ4_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_39:
    {
      *p_min = MTZ4_DELAY1_MIN;
      *p_max = MTZ4_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_40:
    {
      *p_min = MTZ4_DELAY2_MIN;
      *p_max = MTZ4_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_41:
    {
      *p_min = MTZ4_DELAY3_MIN;
      *p_max = MTZ4_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_42:
    {
      *p_min = MTZ4_DELAY4_MIN;
      *p_max = MTZ4_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_43:
    {
      *p_min = MTZ4_DELAY5_MIN;
      *p_max = MTZ4_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_44:
    {
      *p_min = MTZ4_DELAY6_MIN;
      *p_max = MTZ4_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_45:
    {
      *p_min = MTZ4_DELAY7_MIN;
      *p_max = MTZ4_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_46:
    {
      *p_min = MTZ4_DELAY8_MIN;
      *p_max = MTZ4_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_47:
    {
      *p_min = MTZ4_DELAY9_MIN;
      *p_max = MTZ4_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_48:
    {
      *p_min = MTZ4_DELAY10_MIN;
      *p_max = MTZ4_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_49:
    {
      *p_min = MTZ4_DELAY11_MIN;
      *p_max = MTZ4_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_50:
    {
      *p_min = MTZ4_DELAY12_MIN;
      *p_max = MTZ4_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_51:
    {
      *p_min = MTZ4_DELAY13_MIN;
      *p_max = MTZ4_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_52:
    {
      *p_min = MTZ4_DELAY14_MIN;
      *p_max = MTZ4_DELAY14_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_53:
    {
      *p_min = MTZ4_DELAY15_MIN;
      *p_max = MTZ4_DELAY15_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_54:
    {
      *p_min = MTZ4_DELAY16_MIN;
      *p_max = MTZ4_DELAY16_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;

      break;
    }

  case ID_ED_MTZ_DELAY_VALUE_55:
    {
      *p_min = MTZ5_DELAY0_MIN;
      *p_max = MTZ5_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_56:
    {
      *p_min = MTZ5_DELAY1_MIN;
      *p_max = MTZ5_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_57:
    {
      *p_min = MTZ5_DELAY2_MIN;
      *p_max = MTZ5_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_58:
    {
      *p_min = MTZ5_DELAY3_MIN;
      *p_max = MTZ5_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_59:
    {
      *p_min = MTZ5_DELAY4_MIN;
      *p_max = MTZ5_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_60:
    {
      *p_min = MTZ5_DELAY5_MIN;
      *p_max = MTZ5_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_61:
    {
      *p_min = MTZ5_DELAY6_MIN;
      *p_max = MTZ5_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_62:
    {
      *p_min = MTZ5_DELAY7_MIN;
      *p_max = MTZ5_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_63:
    {
      *p_min = MTZ5_DELAY8_MIN;
      *p_max = MTZ5_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_64:
    {
      *p_min = MTZ5_DELAY9_MIN;
      *p_max = MTZ5_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_65:
    {
      *p_min = MTZ5_DELAY10_MIN;
      *p_max = MTZ5_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_66:
    {
      *p_min = MTZ5_DELAY11_MIN;
      *p_max = MTZ5_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_67:
    {
      *p_min = MTZ5_DELAY12_MIN;
      *p_max = MTZ5_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_time_stage;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_68:
    {
      *p_min = MTZ5_DELAY13_MIN;
      *p_max = MTZ5_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_69:
    {
      *p_min = MTZ5_DELAY14_MIN;
      *p_max = MTZ5_DELAY14_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_70:
    {
      *p_min = MTZ5_DELAY15_MIN;
      *p_max = MTZ5_DELAY15_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;

      break;
    }
  case ID_ED_MTZ_DELAY_VALUE_71:
    {
      *p_min = MTZ5_DELAY16_MIN;
      *p_max = MTZ5_DELAY16_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;

      break;
    }

  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки МТЗ
**********/
void MTZ_pickup_info(
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
      *p_min = MTZ1_PICKUP0_MIN;
      *p_max = MTZ1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;
      *value = (float)(*p_value_int);
      break;
    }
  case 1:
    {
      *p_min = MTZ1_PICKUP1_MIN;
      *p_max = MTZ1_PICKUP1_MAX;
              
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 2:
    {
      *p_min = MTZ1_PICKUP2_MIN;
      *p_max = MTZ1_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 3:
    {
      *p_min = MTZ1_PICKUP3_MIN;
      *p_max = MTZ1_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 4:
    {
      *p_min = MTZ1_PICKUP4_MIN;
      *p_max = MTZ1_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 5:
    {
      *p_min = MTZ1_PICKUP5_MIN;
      *p_max = MTZ1_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 0:
    {
      *p_min = MTZ2_PICKUP0_MIN;
      *p_max = MTZ2_PICKUP0_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 1:
    {
      *p_min = MTZ2_PICKUP1_MIN;
      *p_max = MTZ2_PICKUP1_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 2:
    {
      *p_min = MTZ2_PICKUP2_MIN;
      *p_max = MTZ2_PICKUP2_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 3:
    {
      *p_min = MTZ2_PICKUP3_MIN;
      *p_max = MTZ2_PICKUP3_MAX;
             
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 4:
    {
      *p_min = MTZ2_PICKUP4_MIN;
      *p_max = MTZ2_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 5:
    {
      *p_min = MTZ2_PICKUP5_MIN;
      *p_max = MTZ2_PICKUP5_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2Pickup.mcp_I_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 0:
    {
      *p_min = MTZ3_PICKUP0_MIN;
      *p_max = MTZ3_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 1:
    {
      *p_min = MTZ3_PICKUP1_MIN;
      *p_max = MTZ3_PICKUP1_MAX;
             
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 2:
    {
      *p_min = MTZ3_PICKUP2_MIN;
      *p_max = MTZ3_PICKUP2_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 3:
    {
      *p_min = MTZ3_PICKUP3_MIN;
      *p_max = MTZ3_PICKUP3_MAX;
            
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 4:
    {
      *p_min = MTZ3_PICKUP4_MIN;
      *p_max = MTZ3_PICKUP4_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 5:
    {
      *p_min = MTZ3_PICKUP5_MIN;
      *p_max = MTZ3_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2Pickup.mcp_I_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  0:
    {
      *p_min = MTZ4_PICKUP0_MIN;
      *p_max = MTZ4_PICKUP0_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  1:
    {
      *p_min = MTZ4_PICKUP1_MIN;
      *p_max = MTZ4_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  2:
    {
      *p_min = MTZ4_PICKUP2_MIN;
      *p_max = MTZ4_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  3:
    {
      *p_min = MTZ4_PICKUP3_MIN;
      *p_max = MTZ4_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  4:
    {
      *p_min = MTZ4_PICKUP4_MIN;
      *p_max = MTZ4_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 +  5:
    {
      *p_min = MTZ4_PICKUP5_MIN;
      *p_max = MTZ4_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2Pickup.mcp_I_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 0:
    {
      *p_min = MTZ5_PICKUP0_MIN;
      *p_max = MTZ5_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
      *value = (float)(*p_value_int);
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 1:
    {
      *p_min = MTZ5_PICKUP1_MIN;
      *p_max = MTZ5_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 2:
    {
      *p_min = MTZ5_PICKUP2_MIN;
      *p_max = MTZ5_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 3:
    {
      *p_min = MTZ5_PICKUP3_MIN;
      *p_max = MTZ5_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 4:
    {
      *p_min = MTZ5_PICKUP4_MIN;
      *p_max = MTZ5_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 5:
    {
      *p_min = MTZ5_PICKUP5_MIN;
      *p_max = MTZ5_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2Pickup.mcp_I_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки МТЗ
**********/
void MTZ_delay_info(
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
      *p_min = MTZ1_DELAY0_MIN;
      *p_max = MTZ1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = MTZ1_DELAY1_MIN;
      *p_max = MTZ1_DELAY1_MAX;
    
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = MTZ1_DELAY2_MIN;
      *p_max = MTZ1_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 3:
    {
      *p_min = MTZ1_DELAY3_MIN;
      *p_max = MTZ1_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage1DrOcp1StageParam.mcp1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + 0:
    {
      *p_min = MTZ2_DELAY0_MIN;
      *p_max = MTZ2_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 1:
    {
      *p_min = MTZ2_DELAY1_MIN;
      *p_max = MTZ2_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 2:
    {
      *p_min = MTZ2_DELAY2_MIN;
      *p_max = MTZ2_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 3:
    {
      *p_min = MTZ2_DELAY3_MIN;
      *p_max = MTZ2_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 4:
    {
      *p_min = MTZ2_DELAY4_MIN;
      *p_max = MTZ2_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 5:
    {
      *p_min = MTZ2_DELAY5_MIN;
      *p_max = MTZ2_DELAY5_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 6:
    {
      *p_min = MTZ2_DELAY6_MIN;
      *p_max = MTZ2_DELAY6_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 7:
    {
      *p_min = MTZ2_DELAY7_MIN;
      *p_max = MTZ2_DELAY7_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 8:
    {
      *p_min = MTZ2_DELAY8_MIN;
      *p_max = MTZ2_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 9:
    {
      *p_min = MTZ2_DELAY9_MIN;
      *p_max = MTZ2_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 10:
    {
      *p_min = MTZ2_DELAY10_MIN;
      *p_max = MTZ2_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 11:
    {
      *p_min = MTZ2_DELAY11_MIN;
      *p_max = MTZ2_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 12:
    {
      *p_min = MTZ2_DELAY12_MIN;
      *p_max = MTZ2_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 13:
    {
      *p_min = MTZ2_DELAY13_MIN;
      *p_max = MTZ2_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 14:
    {
      *p_min = MTZ2_DELAY14_MIN;
      *p_max = MTZ2_DELAY14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 15:
    {
      *p_min = MTZ2_DELAY15_MIN;
      *p_max = MTZ2_DELAY15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 16:
    {
      *p_min = MTZ2_DELAY16_MIN;
      *p_max = MTZ2_DELAY16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 0:
    {
      *p_min = MTZ3_DELAY0_MIN;
      *p_max = MTZ3_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 1:
    {
      *p_min = MTZ3_DELAY1_MIN;
      *p_max = MTZ3_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 2:
    {
      *p_min = MTZ3_DELAY2_MIN;
      *p_max = MTZ3_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 3:
    {
      *p_min = MTZ3_DELAY3_MIN;
      *p_max = MTZ3_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 4:
    {
      *p_min = MTZ3_DELAY4_MIN;
      *p_max = MTZ3_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 5:
    {
      *p_min = MTZ3_DELAY5_MIN;
      *p_max = MTZ3_DELAY5_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 6:
    {
      *p_min = MTZ3_DELAY6_MIN;
      *p_max = MTZ3_DELAY6_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 7:
    {
      *p_min = MTZ3_DELAY7_MIN;
      *p_max = MTZ3_DELAY7_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 8:
    {
      *p_min = MTZ3_DELAY8_MIN;
      *p_max = MTZ3_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 9:
    {
      *p_min = MTZ3_DELAY9_MIN;
      *p_max = MTZ3_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 10:
    {
      *p_min = MTZ3_DELAY10_MIN;
      *p_max = MTZ3_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 11:
    {
      *p_min = MTZ3_DELAY11_MIN;
      *p_max = MTZ3_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 12:
    {
      *p_min = MTZ3_DELAY12_MIN;
      *p_max = MTZ3_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 13:
    {
      *p_min = MTZ3_DELAY13_MIN;
      *p_max = MTZ3_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 14:
    {
      *p_min = MTZ3_DELAY14_MIN;
      *p_max = MTZ3_DELAY14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 15:
    {
      *p_min = MTZ3_DELAY15_MIN;
      *p_max = MTZ3_DELAY15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 16:
    {
      *p_min = MTZ3_DELAY16_MIN;
      *p_max = MTZ3_DELAY16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 +  MAX_NUMBER_DELAY_MTZ3 + 0:
    {
      *p_min = MTZ4_DELAY0_MIN;
      *p_max = MTZ4_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 1:
    {
      *p_min = MTZ4_DELAY1_MIN;
      *p_max = MTZ4_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 2:
    {
      *p_min = MTZ4_DELAY2_MIN;
      *p_max = MTZ4_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 3:
    {
      *p_min = MTZ4_DELAY3_MIN;
      *p_max = MTZ4_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 4:
    {
      *p_min = MTZ4_DELAY4_MIN;
      *p_max = MTZ4_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 5:
    {
      *p_min = MTZ4_DELAY5_MIN;
      *p_max = MTZ4_DELAY5_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 6:
    {
      *p_min = MTZ4_DELAY6_MIN;
      *p_max = MTZ4_DELAY6_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 7:
    {
      *p_min = MTZ4_DELAY7_MIN;
      *p_max = MTZ4_DELAY7_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 8:
    {
      *p_min = MTZ4_DELAY8_MIN;
      *p_max = MTZ4_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 9:
    {
      *p_min = MTZ4_DELAY9_MIN;
      *p_max = MTZ4_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 10:
    {
      *p_min = MTZ4_DELAY10_MIN;
      *p_max = MTZ4_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 11:
    {
      *p_min = MTZ4_DELAY11_MIN;
      *p_max = MTZ4_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 12:
    {
      *p_min = MTZ4_DELAY12_MIN;
      *p_max = MTZ4_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 13:
    {
      *p_min = MTZ4_DELAY13_MIN;
      *p_max = MTZ4_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 14:
    {
      *p_min = MTZ4_DELAY14_MIN;
      *p_max = MTZ4_DELAY14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 15:
    {
      *p_min = MTZ4_DELAY15_MIN;
      *p_max = MTZ4_DELAY15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 16:
    {
      *p_min = MTZ4_DELAY16_MIN;
      *p_max = MTZ4_DELAY16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 0:
    {
      *p_min = MTZ5_DELAY0_MIN;
      *p_max = MTZ5_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 1:
    {
      *p_min = MTZ5_DELAY1_MIN;
      *p_max = MTZ5_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 2:
    {
      *p_min = MTZ5_DELAY2_MIN;
      *p_max = MTZ5_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 3:
    {
      *p_min = MTZ5_DELAY3_MIN;
      *p_max = MTZ5_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 4:
    {
      *p_min = MTZ5_DELAY4_MIN;
      *p_max = MTZ5_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 5:
    {
      *p_min = MTZ5_DELAY5_MIN;
      *p_max = MTZ5_DELAY5_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 6:
    {
      *p_min = MTZ5_DELAY6_MIN;
      *p_max = MTZ5_DELAY6_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 7:
    {
      *p_min = MTZ5_DELAY7_MIN;
      *p_max = MTZ5_DELAY7_MAX;
               
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 8:
    {
      *p_min = MTZ5_DELAY8_MIN;
      *p_max = MTZ5_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 9:
    {
      *p_min = MTZ5_DELAY9_MIN;
      *p_max = MTZ5_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 10:
    {
      *p_min = MTZ5_DELAY10_MIN;
      *p_max = MTZ5_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 11:
    {
      *p_min = MTZ5_DELAY11_MIN;
      *p_max = MTZ5_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 12:
    {
      *p_min = MTZ5_DELAY12_MIN;
      *p_max = MTZ5_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_time_stage;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 13:
    {
      *p_min = MTZ5_DELAY13_MIN;
      *p_max = MTZ5_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 14:
    {
      *p_min = MTZ5_DELAY14_MIN;
      *p_max = MTZ5_DELAY14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 15:
    {
      *p_min = MTZ5_DELAY15_MIN;
      *p_max = MTZ5_DELAY15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 16:
    {
      *p_min = MTZ5_DELAY16_MIN;
      *p_max = MTZ5_DELAY16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[MTZ_select_group].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
    
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки МТЗ 
**********/
const char* MTZ_pickup_info_1(
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
      
      *p_max = MTZ1_PICKUP0_MAX;
      *p_shift = MTZ1_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ1_PICKUP1_MAX/1000;
      *p_shift = MTZ1_PICKUP1_SHIFT;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ1_PICKUP2_MAX/1000;
      *p_shift = MTZ1_PICKUP2_SHIFT;
        
      break;
    }
  case 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ1_PICKUP3_MAX/1000;
      *p_shift = MTZ1_PICKUP3_SHIFT;
        
      break;
    }
  case 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
        
      *p_max = MTZ1_PICKUP4_MAX/1000;
      *p_shift = MTZ1_PICKUP4_SHIFT;
        
      break;
    }
  case 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ1_PICKUP5_MAX/1000;
      *p_shift = MTZ1_PICKUP5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 0:
    {
      p_pickup_dimention = gradus;
        
      *p_max = MTZ2_PICKUP0_MAX;
      *p_shift = MTZ2_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ2_PICKUP1_MAX/1000;
      *p_shift = MTZ2_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ2_PICKUP2_MAX/1000;
      *p_shift = MTZ2_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ2_PICKUP3_MAX/1000;
      *p_shift = MTZ2_PICKUP3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
        
      *p_max = MTZ2_PICKUP4_MAX/1000;
      *p_shift = MTZ2_PICKUP4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ2_PICKUP5_MAX/1000;
      *p_shift = MTZ2_PICKUP5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 0:
    {
      p_pickup_dimention = gradus;
        
      *p_max = MTZ3_PICKUP0_MAX;
      *p_shift = MTZ3_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ3_PICKUP1_MAX/1000;
      *p_shift = MTZ3_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ3_PICKUP2_MAX/1000;
      *p_shift = MTZ3_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ3_PICKUP3_MAX/1000;
      *p_shift = MTZ3_PICKUP3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
        
      *p_max = MTZ3_PICKUP4_MAX/1000;
      *p_shift = MTZ3_PICKUP4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ3_PICKUP5_MAX/1000;
      *p_shift = MTZ3_PICKUP5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 0:
    {
      p_pickup_dimention = gradus;
        
      *p_max = MTZ4_PICKUP0_MAX;
      *p_shift = MTZ4_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ4_PICKUP1_MAX/1000;
      *p_shift = MTZ4_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ4_PICKUP2_MAX/1000;
      *p_shift = MTZ4_PICKUP2_SHIFT;
      
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ4_PICKUP3_MAX/1000;
      *p_shift = MTZ4_PICKUP3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
        
      *p_max = MTZ4_PICKUP4_MAX/1000;
      *p_shift = MTZ4_PICKUP4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ4_PICKUP5_MAX/1000;
      *p_shift = MTZ4_PICKUP5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 0:
    {
      p_pickup_dimention = gradus;
        
      *p_max = MTZ5_PICKUP0_MAX;
      *p_shift = MTZ5_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ5_PICKUP1_MAX/1000;
      *p_shift = MTZ5_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ5_PICKUP2_MAX/1000;
      *p_shift = MTZ5_PICKUP2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ5_PICKUP3_MAX/1000;
      *p_shift = MTZ5_PICKUP3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
        
      *p_max = MTZ5_PICKUP4_MAX/1000;
      *p_shift = MTZ5_PICKUP4_SHIFT;
      
      break;
    }
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
        
      *p_max = MTZ5_PICKUP5_MAX/1000;
      *p_shift = MTZ5_PICKUP5_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки МТЗ
**********/
const char* MTZ_delay_info_1(
                             unsigned int number,
                             int *p_min,
                             int *p_max,
                             int *p_shift
                            )
{
  const char *p_pickup_dimention = MEASURES[MEASURES_OF_SECOND].ptitle[sel_language];
 *p_min = 0;
 
  switch (number)
  {
  case 0:
    {
      *p_max = MTZ1_DELAY0_MAX/100;
      *p_shift = MTZ1_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = MTZ1_DELAY1_MAX/100;
      *p_shift = MTZ1_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = MTZ1_DELAY2_MAX/100;
      *p_shift = MTZ1_DELAY2_SHIFT;
        
      break;
    }
  case 3:
    {
      *p_max = MTZ1_DELAY3_MAX/100;
      *p_shift = MTZ1_DELAY3_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + 0:
    {
      *p_max = MTZ2_DELAY0_MAX/100;
      *p_shift = MTZ2_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 1:
    {
      *p_max = MTZ2_DELAY1_MAX/100;
      *p_shift = MTZ2_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 2:
    {
      *p_max = MTZ2_DELAY2_MAX/100;
      *p_shift = MTZ2_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 3:
    {
      *p_max = MTZ2_DELAY3_MAX/100;
      *p_shift = MTZ2_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 4:
    {
      *p_max = MTZ2_DELAY4_MAX/100;
      *p_shift = MTZ2_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 5:
    {
      *p_max = MTZ2_DELAY5_MAX/100;
      *p_shift = MTZ2_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 6:
    {
      *p_max = MTZ2_DELAY6_MAX/100;
      *p_shift = MTZ2_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 7:
    {
      *p_max = MTZ2_DELAY7_MAX/100;
      *p_shift = MTZ2_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 8:
    {
      *p_max = MTZ2_DELAY8_MAX/100;
      *p_shift = MTZ2_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 9:
    {
      *p_max = MTZ2_DELAY9_MAX/100;
      *p_shift = MTZ2_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 10:
    {
      *p_max = MTZ2_DELAY10_MAX/100;
      *p_shift = MTZ2_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 11:
    {
      *p_max = MTZ2_DELAY11_MAX/100;
      *p_shift = MTZ2_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 12:
    {
      *p_max = MTZ2_DELAY12_MAX/100;
      *p_shift = MTZ2_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 13:
    {
      *p_max = MTZ2_DELAY13_MAX/100;
      *p_shift = MTZ2_DELAY13_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 14:
    {
      *p_max = MTZ2_DELAY14_MAX/100;
      *p_shift = MTZ2_DELAY14_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 15:
    {
      *p_max = MTZ2_DELAY15_MAX/100;
      *p_shift = MTZ2_DELAY15_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + 16:
    {
      *p_max = MTZ2_DELAY16_MAX/100;
      *p_shift = MTZ2_DELAY16_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 0:
    {
      *p_max = MTZ3_DELAY0_MAX/100;
      *p_shift = MTZ3_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 1:
    {
      *p_max = MTZ3_DELAY1_MAX/100;
      *p_shift = MTZ3_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 2:
    {
      *p_max = MTZ3_DELAY2_MAX/100;
      *p_shift = MTZ3_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 3:
    {
      *p_max = MTZ3_DELAY3_MAX/100;
      *p_shift = MTZ3_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 4:
    {
      *p_max = MTZ3_DELAY4_MAX/100;
      *p_shift = MTZ3_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 5:
    {
      *p_max = MTZ3_DELAY5_MAX/100;
      *p_shift = MTZ3_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 6:
    {
      *p_max = MTZ3_DELAY6_MAX/100;
      *p_shift = MTZ3_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 7:
    {
      *p_max = MTZ3_DELAY7_MAX/100;
      *p_shift = MTZ3_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 8:
    {
      *p_max = MTZ3_DELAY8_MAX/100;
      *p_shift = MTZ3_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 9:
    {
      *p_max = MTZ3_DELAY9_MAX/100;
      *p_shift = MTZ3_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 10:
    {
      *p_max = MTZ3_DELAY10_MAX/100;
      *p_shift = MTZ3_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 11:
    {
      *p_max = MTZ3_DELAY11_MAX/100;
      *p_shift = MTZ3_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 12:
    {
      *p_max = MTZ3_DELAY12_MAX/100;
      *p_shift = MTZ3_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 13:
    {
      *p_max = MTZ3_DELAY13_MAX/100;
      *p_shift = MTZ3_DELAY13_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 14:
    {
      *p_max = MTZ3_DELAY14_MAX/100;
      *p_shift = MTZ3_DELAY14_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 15:
    {
      *p_max = MTZ3_DELAY15_MAX/100;
      *p_shift = MTZ3_DELAY15_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 16:
    {
      *p_max = MTZ3_DELAY16_MAX/100;
      *p_shift = MTZ3_DELAY16_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 0:
    {
      *p_max = MTZ4_DELAY0_MAX/100;
      *p_shift = MTZ4_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 1:
    {
      *p_max = MTZ4_DELAY1_MAX/100;
      *p_shift = MTZ4_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 2:
    {
      *p_max = MTZ4_DELAY2_MAX/100;
      *p_shift = MTZ4_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 3:
    {
      *p_max = MTZ4_DELAY3_MAX/100;
      *p_shift = MTZ4_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 4:
    {
      *p_max = MTZ4_DELAY4_MAX/100;
      *p_shift = MTZ4_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 5:
    {
      *p_max = MTZ4_DELAY5_MAX/100;
      *p_shift = MTZ4_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 6:
    {
      *p_max = MTZ4_DELAY6_MAX/100;
      *p_shift = MTZ4_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 7:
    {
      *p_max = MTZ4_DELAY7_MAX/100;
      *p_shift = MTZ4_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 8:
    {
      *p_max = MTZ4_DELAY8_MAX/100;
      *p_shift = MTZ4_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 9:
    {
      *p_max = MTZ4_DELAY9_MAX/100;
      *p_shift = MTZ4_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 10:
    {
      *p_max = MTZ4_DELAY10_MAX/100;
      *p_shift = MTZ4_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 11:
    {
      *p_max = MTZ4_DELAY11_MAX/100;
      *p_shift = MTZ4_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 12:
    {
      *p_max = MTZ4_DELAY12_MAX/100;
      *p_shift = MTZ4_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 13:
    {
      *p_max = MTZ4_DELAY13_MAX/100;
      *p_shift = MTZ4_DELAY13_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 14:
    {
      *p_max = MTZ4_DELAY14_MAX/100;
      *p_shift = MTZ4_DELAY14_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 15:
    {
      *p_max = MTZ4_DELAY15_MAX/100;
      *p_shift = MTZ4_DELAY15_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 16:
    {
      *p_max = MTZ4_DELAY16_MAX/100;
      *p_shift = MTZ4_DELAY16_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 0:
    {
      *p_max = MTZ5_DELAY0_MAX/100;
      *p_shift = MTZ5_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 1:
    {
      *p_max = MTZ5_DELAY1_MAX/100;
      *p_shift = MTZ5_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 2:
    {
      *p_max = MTZ5_DELAY2_MAX/100;
      *p_shift = MTZ5_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 3:
    {
      *p_max = MTZ5_DELAY3_MAX/100;
      *p_shift = MTZ5_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 4:
    {
      *p_max = MTZ5_DELAY4_MAX/100;
      *p_shift = MTZ5_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 5:
    {
      *p_max = MTZ5_DELAY5_MAX/100;
      *p_shift = MTZ5_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 6:
    {
      *p_max = MTZ5_DELAY6_MAX/100;
      *p_shift = MTZ5_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 7:
    {
      *p_max = MTZ5_DELAY7_MAX/100;
      *p_shift = MTZ5_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 8:
    {
      *p_max = MTZ5_DELAY8_MAX/100;
      *p_shift = MTZ5_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 9:
    {
      *p_max = MTZ5_DELAY9_MAX/100;
      *p_shift = MTZ5_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 10:
    {
      *p_max = MTZ5_DELAY10_MAX/100;
      *p_shift = MTZ5_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 11:
    {
      *p_max = MTZ5_DELAY11_MAX/100;
      *p_shift = MTZ5_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 12:
    {
      *p_max = MTZ5_DELAY12_MAX/100;
      *p_shift = MTZ5_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 13:
    {
      *p_max = MTZ5_DELAY13_MAX/100;
      *p_shift = MTZ5_DELAY13_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 14:
    {
      *p_max = MTZ5_DELAY14_MAX/100;
      *p_shift = MTZ5_DELAY14_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 15:
    {
      *p_max = MTZ5_DELAY15_MAX/100;
      *p_shift = MTZ5_DELAY15_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 16:
    {
      *p_max = MTZ5_DELAY16_MAX/100;
      *p_shift = MTZ5_DELAY16_SHIFT;
        
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
const char* MTZ_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 0:
  case MAX_NUMBER_PICKUP_MTZ1 + 0:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 0:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 0:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 0:
    {
      p_pickup_dimention = gradus;
      break;
    }
  case 4:
  case MAX_NUMBER_PICKUP_MTZ1 + 4:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 4:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 4:
  case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[sel_language];
      break;
    }
  default:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для МТЗ
**********/
const TITLE* MTZ_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (
      (number == 1) ||
      (number == (MAX_NUMBER_CTRL_MTZ1+1)) ||
      (number == (MAX_NUMBER_CTRL_MTZ1+MAX_NUMBER_CTRL_MTZ2+1)) ||
      (number == (MAX_NUMBER_CTRL_MTZ1+MAX_NUMBER_CTRL_MTZ2+MAX_NUMBER_CTRL_MTZ3+1)) ||
      (number == (MAX_NUMBER_CTRL_MTZ1+MAX_NUMBER_CTRL_MTZ2+MAX_NUMBER_CTRL_MTZ3+MAX_NUMBER_CTRL_MTZ4+1))
     )   
  {
    *p_j_max = 3;
    p_control_list_name = SELECTOR;
  }
  else
  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для МТЗ
**********/
unsigned char* MTZ_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1DrOcp1Mng.state_mcp1;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1DrOcp1Mng.select_prt_mcp1;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrStg1DrOcp1Mng.DirectionStraight_mcp1;
      break;
    }
  case 3:
    {
      p_to_state = &point->ownrStg1DrOcp1Mng.DirectionBack_mcp1;
      break;
    }
  
  case MAX_NUMBER_CTRL_MTZ1 + 0:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.state_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 1:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.select_prt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 2:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.DirectionStraight_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 3:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.DirectionBack_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 4:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.aclt_mcp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 5:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.state_Auto_aclt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + 6:
    {
      p_to_state = &point->ownrStg2DrOcp2Mng.state_Tele_aclt_mcp;
      break;
    }
  
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 0:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.state_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 1:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.select_prt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 2:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.DirectionStraight_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 3:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.DirectionBack_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 4:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.aclt_mcp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 5:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.state_Auto_aclt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + 6:
    {
      p_to_state = &point->ownrStg3DrOcp2Mng.state_Tele_aclt_mcp;
      break;
    }
  
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 0:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.state_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 1:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.select_prt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 2:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.DirectionStraight_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 3:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.DirectionBack_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 4:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.aclt_mcp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 5:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.state_Auto_aclt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + 6:
    {
      p_to_state = &point->ownrStg4DrOcp2Mng.state_Tele_aclt_mcp;
      break;
    }
  
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 0:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.state_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 1:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.select_prt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 2:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.DirectionStraight_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 3:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.DirectionBack_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 4:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.aclt_mcp_sw;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 5:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.state_Auto_aclt_mcp;
      break;
    }
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + 6:
    {
      p_to_state = &point->ownrStg5DrOcp2Mng.state_Tele_aclt_mcp;
      break;
    }
  
  case MAX_NUMBER_CTRL_MTZ1 + MAX_NUMBER_CTRL_MTZ2 + MAX_NUMBER_CTRL_MTZ3 + MAX_NUMBER_CTRL_MTZ4 + MAX_NUMBER_CTRL_MTZ5 + 0:
    {
      p_to_state = &point->state_FaultU_Ocp;
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
void MTZ_change_state_callback(
                               unsigned int number,
                               CfgTblDsc *point
                              )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_MTZ(CfgTblDsc *point)
{
  unsigned int  ok = true;

  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_MTZ) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = MTZ1_PICKUP0_MIN;
          max = MTZ1_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;

          break;
        }
      case 1:
        {
          min = MTZ1_PICKUP1_MIN;
          max = MTZ1_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;

          break;
        }
      case 2:
        {
          min = MTZ1_PICKUP2_MIN;
          max = MTZ1_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;

          break;
        }
      case 3:
        {
          min = MTZ1_PICKUP3_MIN;
          max = MTZ1_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;

          break;
        }
      case 4:
        {
          min = MTZ1_PICKUP4_MIN;
          max = MTZ1_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;

          break;
        }
      case 5:
        {
          min = MTZ1_PICKUP5_MIN;
          max = MTZ1_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_MTZ1 + 0:
        {
          min = MTZ2_PICKUP0_MIN;
          max = MTZ2_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + 1:
        {
          min = MTZ2_PICKUP1_MIN;
          max = MTZ2_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + 2:
        {
          min = MTZ2_PICKUP2_MIN;
          max = MTZ2_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + 3:
        {
          min = MTZ2_PICKUP3_MIN;
          max = MTZ2_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + 4:
        {
          min = MTZ2_PICKUP4_MIN;
          max = MTZ2_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + 5:
        {
          min = MTZ2_PICKUP5_MIN;
          max = MTZ2_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2Pickup.mcp_I_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 0:
        {
          min = MTZ3_PICKUP0_MIN;
          max = MTZ3_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 1:
        {
          min = MTZ3_PICKUP1_MIN;
          max = MTZ3_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 2:
        {
          min = MTZ3_PICKUP2_MIN;
          max = MTZ3_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 3:
        {
          min = MTZ3_PICKUP3_MIN;
          max = MTZ3_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 4:
        {
          min = MTZ3_PICKUP4_MIN;
          max = MTZ3_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + 5:
        {
          min = MTZ3_PICKUP5_MIN;
          max = MTZ3_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2Pickup.mcp_I_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 0:
        {
          min = MTZ4_PICKUP0_MIN;
          max = MTZ4_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 1:
        {
          min = MTZ4_PICKUP1_MIN;
          max = MTZ4_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 2:
        {
          min = MTZ4_PICKUP2_MIN;
          max = MTZ4_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 3:
        {
          min = MTZ4_PICKUP3_MIN;
          max = MTZ4_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 4:
        {
          min = MTZ4_PICKUP4_MIN;
          max = MTZ4_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + 5:
        {
          min = MTZ4_PICKUP5_MIN;
          max = MTZ4_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2Pickup.mcp_I_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 0:
        {
          min = MTZ5_PICKUP0_MIN;
          max = MTZ5_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 1:
        {
          min = MTZ5_PICKUP1_MIN;
          max = MTZ5_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 2:
        {
          min = MTZ5_PICKUP2_MIN;
          max = MTZ5_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 3:
        {
          min = MTZ5_PICKUP3_MIN;
          max = MTZ5_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 4:
        {
          min = MTZ5_PICKUP4_MIN;
          max = MTZ5_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;

          break;
        }
      case MAX_NUMBER_PICKUP_MTZ1 + MAX_NUMBER_PICKUP_MTZ2 + MAX_NUMBER_PICKUP_MTZ3 + MAX_NUMBER_PICKUP_MTZ4 + 5:
        {
          min = MTZ5_PICKUP5_MIN;
          max = MTZ5_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2Pickup.mcp_I_ov_range;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_MTZ) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = MTZ1_DELAY0_MIN;
          max = MTZ1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;

          break;
        }
      case 1:
        {
          min = MTZ1_DELAY1_MIN;
          max = MTZ1_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;

          break;
        }
      case 2:
        {
          min = MTZ1_DELAY2_MIN;
          max = MTZ1_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;

          break;
        }
      case 3:
        {
          min = MTZ1_DELAY3_MIN;
          max = MTZ1_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1DrOcp1StageParam.mcp1_time_stage;

          break;
        }

      case MAX_NUMBER_DELAY_MTZ1 + 0:
        {
          min = MTZ2_DELAY0_MIN;
          max = MTZ2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 1:
        {
          min = MTZ2_DELAY1_MIN;
          max = MTZ2_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 2:
        {
          min = MTZ2_DELAY2_MIN;
          max = MTZ2_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 3:
        {
          min = MTZ2_DELAY3_MIN;
          max = MTZ2_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 4:
        {
          min = MTZ2_DELAY4_MIN;
          max = MTZ2_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 5:
        {
          min = MTZ2_DELAY5_MIN;
          max = MTZ2_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 6:
        {
          min = MTZ2_DELAY6_MIN;
          max = MTZ2_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 7:
        {
          min = MTZ2_DELAY7_MIN;
          max = MTZ2_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 8:
        {
          min = MTZ2_DELAY8_MIN;
          max = MTZ2_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 9:
        {
          min = MTZ2_DELAY9_MIN;
          max = MTZ2_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 10:
        {
          min = MTZ2_DELAY10_MIN;
          max = MTZ2_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 11:
        {
          min = MTZ2_DELAY11_MIN;
          max = MTZ2_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 12:
        {
          min = MTZ2_DELAY12_MIN;
          max = MTZ2_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 13:
        {
          min = MTZ2_DELAY13_MIN;
          max = MTZ2_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 14:
        {
          min = MTZ2_DELAY14_MIN;
          max = MTZ2_DELAY14_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 15:
        {
          min = MTZ2_DELAY15_MIN;
          max = MTZ2_DELAY15_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + 16:
        {
          min = MTZ2_DELAY16_MIN;
          max = MTZ2_DELAY16_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;

          break;
        }

      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 0:
        {
          min = MTZ3_DELAY0_MIN;
          max = MTZ3_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 1:
        {
          min = MTZ3_DELAY1_MIN;
          max = MTZ3_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 2:
        {
          min = MTZ3_DELAY2_MIN;
          max = MTZ3_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 3:
        {
          min = MTZ3_DELAY3_MIN;
          max = MTZ3_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 4:
        {
          min = MTZ3_DELAY4_MIN;
          max = MTZ3_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 5:
        {
          min = MTZ3_DELAY5_MIN;
          max = MTZ3_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 6:
        {
          min = MTZ3_DELAY6_MIN;
          max = MTZ3_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 7:
        {
          min = MTZ3_DELAY7_MIN;
          max = MTZ3_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 8:
        {
          min = MTZ3_DELAY8_MIN;
          max = MTZ3_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 9:
        {
          min = MTZ3_DELAY9_MIN;
          max = MTZ3_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 10:
        {
          min = MTZ3_DELAY10_MIN;
          max = MTZ3_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 11:
        {
          min = MTZ3_DELAY11_MIN;
          max = MTZ3_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 12:
        {
          min = MTZ3_DELAY12_MIN;
          max = MTZ3_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 13:
        {
          min = MTZ3_DELAY13_MIN;
          max = MTZ3_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 14:
        {
          min = MTZ3_DELAY14_MIN;
          max = MTZ3_DELAY14_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 15:
        {
          min = MTZ3_DELAY15_MIN;
          max = MTZ3_DELAY15_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + 16:
        {
          min = MTZ3_DELAY16_MIN;
          max = MTZ3_DELAY16_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;

          break;
        }

      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 0:
        {
          min = MTZ4_DELAY0_MIN;
          max = MTZ4_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 1:
        {
          min = MTZ4_DELAY1_MIN;
          max = MTZ4_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 2:
        {
          min = MTZ4_DELAY2_MIN;
          max = MTZ4_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 3:
        {
          min = MTZ4_DELAY3_MIN;
          max = MTZ4_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 4:
        {
          min = MTZ4_DELAY4_MIN;
          max = MTZ4_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 5:
        {
          min = MTZ4_DELAY5_MIN;
          max = MTZ4_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 6:
        {
          min = MTZ4_DELAY6_MIN;
          max = MTZ4_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 7:
        {
          min = MTZ4_DELAY7_MIN;
          max = MTZ4_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 8:
        {
          min = MTZ4_DELAY8_MIN;
          max = MTZ4_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 9:
        {
          min = MTZ4_DELAY9_MIN;
          max = MTZ4_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 10:
        {
          min = MTZ4_DELAY10_MIN;
          max = MTZ4_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 11:
        {
          min = MTZ4_DELAY11_MIN;
          max = MTZ4_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 12:
        {
          min = MTZ4_DELAY12_MIN;
          max = MTZ4_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 13:
        {
          min = MTZ4_DELAY13_MIN;
          max = MTZ4_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 14:
        {
          min = MTZ4_DELAY14_MIN;
          max = MTZ4_DELAY14_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 15:
        {
          min = MTZ4_DELAY15_MIN;
          max = MTZ4_DELAY15_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + 16:
        {
          min = MTZ4_DELAY16_MIN;
          max = MTZ4_DELAY16_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;

          break;
        }

      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 0:
        {
          min = MTZ5_DELAY0_MIN;
          max = MTZ5_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 1:
        {
          min = MTZ5_DELAY1_MIN;
          max = MTZ5_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 2:
        {
          min = MTZ5_DELAY2_MIN;
          max = MTZ5_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 3:
        {
          min = MTZ5_DELAY3_MIN;
          max = MTZ5_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 4:
        {
          min = MTZ5_DELAY4_MIN;
          max = MTZ5_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 5:
        {
          min = MTZ5_DELAY5_MIN;
          max = MTZ5_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 6:
        {
          min = MTZ5_DELAY6_MIN;
          max = MTZ5_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 7:
        {
          min = MTZ5_DELAY7_MIN;
          max = MTZ5_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 8:
        {
          min = MTZ5_DELAY8_MIN;
          max = MTZ5_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 9:
        {
          min = MTZ5_DELAY9_MIN;
          max = MTZ5_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 10:
        {
          min = MTZ5_DELAY10_MIN;
          max = MTZ5_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 11:
        {
          min = MTZ5_DELAY11_MIN;
          max = MTZ5_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 12:
        {
          min = MTZ5_DELAY12_MIN;
          max = MTZ5_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_time_stage;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 13:
        {
          min = MTZ5_DELAY13_MIN;
          max = MTZ5_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 14:
        {
          min = MTZ5_DELAY14_MIN;
          max = MTZ5_DELAY14_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 15:
        {
          min = MTZ5_DELAY15_MIN;
          max = MTZ5_DELAY15_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_MTZ1 + MAX_NUMBER_DELAY_MTZ2 + MAX_NUMBER_DELAY_MTZ3 + MAX_NUMBER_DELAY_MTZ4 + 16:
        {
          min = MTZ5_DELAY16_MIN;
          max = MTZ5_DELAY16_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;

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
void copy_data_MTZ(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup = 
    source->arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup; 

    target->arPckpStpmStngStore[i].ownrStage1DrOcp1StageParam = 
    source->arPckpStpmStngStore[i].ownrStage1DrOcp1StageParam; 

    target->arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage2DrOcp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage2DrOcp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage3DrOcp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage3DrOcp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage4DrOcp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage4DrOcp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage5DrOcp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage5DrOcp2StageParam; 
  }
  target->ownrStg1DrOcp1Mng = source->ownrStg1DrOcp1Mng;
  target->ownrStg2DrOcp2Mng = source->ownrStg2DrOcp2Mng;
  target->ownrStg3DrOcp2Mng = source->ownrStg3DrOcp2Mng;
  target->ownrStg4DrOcp2Mng = source->ownrStg4DrOcp2Mng;
  target->ownrStg5DrOcp2Mng = source->ownrStg5DrOcp2Mng;
  target->state_FaultU_Ocp  = source->state_FaultU_Ocp;
}
/*****************************/
