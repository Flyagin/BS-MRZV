#include "header_mal.h"

/**********
Дії по зміні значення уставки в функції _cbPickups_Protection
**********/

int* DZ_pickups_notification_value_changed (
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
  case ID_ED_DZ_PICKUP_VALUE_0:
    {
      *p_min = DZ1_PICKUP0_MIN;
      *p_max = DZ1_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_1:
    {
      *p_min = DZ1_PICKUP1_MIN;
      *p_max = DZ1_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_2:
    {
      *p_min = DZ1_PICKUP2_MIN;
      *p_max = DZ1_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_3:
    {
      *p_min = DZ1_PICKUP3_MIN;
      *p_max = DZ1_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_4:
    {
      *p_min = DZ1_PICKUP4_MIN;
      *p_max = DZ1_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_5:
    {
      *p_min = DZ1_PICKUP5_MIN;
      *p_max = DZ1_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_6:
    {
      *p_min = DZ1_PICKUP6_MIN;
      *p_max = DZ1_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_7:
    {
      *p_min = DZ1_PICKUP7_MIN;
      *p_max = DZ1_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_8:
    {
      *p_min = DZ1_PICKUP8_MIN;
      *p_max = DZ1_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_9:
    {
      *p_min = DZ1_PICKUP9_MIN;
      *p_max = DZ1_PICKUP9_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_10:
    {
      *p_min = DZ1_PICKUP10_MIN;
      *p_max = DZ1_PICKUP10_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_11:
    {
      *p_min = DZ1_PICKUP11_MIN;
      *p_max = DZ1_PICKUP11_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_12:
    {
      *p_min = DZ1_PICKUP12_MIN;
      *p_max = DZ1_PICKUP12_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_13:
    {
      *p_min = DZ1_PICKUP13_MIN;
      *p_max = DZ1_PICKUP13_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_14:
    {
      *p_min = DZ1_PICKUP14_MIN;
      *p_max = DZ1_PICKUP14_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_15:
    {
      *p_min = DZ1_PICKUP15_MIN;
      *p_max = DZ1_PICKUP15_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_16:
    {
      *p_min = DZ1_PICKUP16_MIN;
      *p_max = DZ1_PICKUP16_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_17:
    {
      *p_min = DZ1_PICKUP17_MIN;
      *p_max = DZ1_PICKUP17_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Dstp1_Iovp_ov_range;

      break;
    }

  case ID_ED_DZ_PICKUP_VALUE_18:
    {
      *p_min = DZ2_PICKUP0_MIN;
      *p_max = DZ2_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_19:
    {
      *p_min = DZ2_PICKUP1_MIN;
      *p_max = DZ2_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_20:
    {
      *p_min = DZ2_PICKUP2_MIN;
      *p_max = DZ2_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_21:
    {
      *p_min = DZ2_PICKUP3_MIN;
      *p_max = DZ2_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_22:
    {
      *p_min = DZ2_PICKUP4_MIN;
      *p_max = DZ2_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_23:
    {
      *p_min = DZ2_PICKUP5_MIN;
      *p_max = DZ2_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_24:
    {
      *p_min = DZ2_PICKUP6_MIN;
      *p_max = DZ2_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_25:
    {
      *p_min = DZ2_PICKUP7_MIN;
      *p_max = DZ2_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_26:
    {
      *p_min = DZ2_PICKUP8_MIN;
      *p_max = DZ2_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_27:
    {
      *p_min = DZ2_PICKUP9_MIN;
      *p_max = DZ2_PICKUP9_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_28:
    {
      *p_min = DZ2_PICKUP10_MIN;
      *p_max = DZ2_PICKUP10_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_29:
    {
      *p_min = DZ2_PICKUP11_MIN;
      *p_max = DZ2_PICKUP11_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_30:
    {
      *p_min = DZ2_PICKUP12_MIN;
      *p_max = DZ2_PICKUP12_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_31:
    {
      *p_min = DZ2_PICKUP13_MIN;
      *p_max = DZ2_PICKUP13_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_32:
    {
      *p_min = DZ2_PICKUP14_MIN;
      *p_max = DZ2_PICKUP14_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_33:
    {
      *p_min = DZ2_PICKUP15_MIN;
      *p_max = DZ2_PICKUP15_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_34:
    {
      *p_min = DZ2_PICKUP16_MIN;
      *p_max = DZ2_PICKUP16_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_35:
    {
      *p_min = DZ2_PICKUP17_MIN;
      *p_max = DZ2_PICKUP17_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Dstp2_Iovp_ov_range;

      break;
    }

  case ID_ED_DZ_PICKUP_VALUE_36:
    {
      *p_min = DZ3_PICKUP0_MIN;
      *p_max = DZ3_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_37:
    {
      *p_min = DZ3_PICKUP1_MIN;
      *p_max = DZ3_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_38:
    {
      *p_min = DZ3_PICKUP2_MIN;
      *p_max = DZ3_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_39:
    {
      *p_min = DZ3_PICKUP3_MIN;
      *p_max = DZ3_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_40:
    {
      *p_min = DZ3_PICKUP4_MIN;
      *p_max = DZ3_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_41:
    {
      *p_min = DZ3_PICKUP5_MIN;
      *p_max = DZ3_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_42:
    {
      *p_min = DZ3_PICKUP6_MIN;
      *p_max = DZ3_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_43:
    {
      *p_min = DZ3_PICKUP7_MIN;
      *p_max = DZ3_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_44:
    {
      *p_min = DZ3_PICKUP8_MIN;
      *p_max = DZ3_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_45:
    {
      *p_min = DZ3_PICKUP9_MIN;
      *p_max = DZ3_PICKUP9_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_46:
    {
      *p_min = DZ3_PICKUP10_MIN;
      *p_max = DZ3_PICKUP10_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_47:
    {
      *p_min = DZ3_PICKUP11_MIN;
      *p_max = DZ3_PICKUP11_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_48:
    {
      *p_min = DZ3_PICKUP12_MIN;
      *p_max = DZ3_PICKUP12_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_49:
    {
      *p_min = DZ3_PICKUP13_MIN;
      *p_max = DZ3_PICKUP13_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_50:
    {
      *p_min = DZ3_PICKUP14_MIN;
      *p_max = DZ3_PICKUP14_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_51:
    {
      *p_min = DZ3_PICKUP15_MIN;
      *p_max = DZ3_PICKUP15_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_52:
    {
      *p_min = DZ3_PICKUP16_MIN;
      *p_max = DZ3_PICKUP16_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_53:
    {
      *p_min = DZ3_PICKUP17_MIN;
      *p_max = DZ3_PICKUP17_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Dstp2_Iovp_ov_range;

      break;
    }

  case ID_ED_DZ_PICKUP_VALUE_54:
    {
      *p_min = DZ4_PICKUP0_MIN;
      *p_max = DZ4_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_55:
    {
      *p_min = DZ4_PICKUP1_MIN;
      *p_max = DZ4_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_56:
    {
      *p_min = DZ4_PICKUP2_MIN;
      *p_max = DZ4_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_57:
    {
      *p_min = DZ4_PICKUP3_MIN;
      *p_max = DZ4_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_58:
    {
      *p_min = DZ4_PICKUP4_MIN;
      *p_max = DZ4_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_59:
    {
      *p_min = DZ4_PICKUP5_MIN;
      *p_max = DZ4_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_60:
    {
      *p_min = DZ4_PICKUP6_MIN;
      *p_max = DZ4_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_61:
    {
      *p_min = DZ4_PICKUP7_MIN;
      *p_max = DZ4_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_62:
    {
      *p_min = DZ4_PICKUP8_MIN;
      *p_max = DZ4_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_63:
    {
      *p_min = DZ4_PICKUP9_MIN;
      *p_max = DZ4_PICKUP9_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_64:
    {
      *p_min = DZ4_PICKUP10_MIN;
      *p_max = DZ4_PICKUP10_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_65:
    {
      *p_min = DZ4_PICKUP11_MIN;
      *p_max = DZ4_PICKUP11_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_66:
    {
      *p_min = DZ4_PICKUP12_MIN;
      *p_max = DZ4_PICKUP12_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_67:
    {
      *p_min = DZ4_PICKUP13_MIN;
      *p_max = DZ4_PICKUP13_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_68:
    {
      *p_min = DZ4_PICKUP14_MIN;
      *p_max = DZ4_PICKUP14_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_69:
    {
      *p_min = DZ4_PICKUP15_MIN;
      *p_max = DZ4_PICKUP15_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_70:
    {
      *p_min = DZ4_PICKUP16_MIN;
      *p_max = DZ4_PICKUP16_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_71:
    {
      *p_min = DZ4_PICKUP17_MIN;
      *p_max = DZ4_PICKUP17_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Dstp2_Iovp_ov_range;

      break;
    }

  case ID_ED_DZ_PICKUP_VALUE_72:
    {
      *p_min = DZ5_PICKUP0_MIN;
      *p_max = DZ5_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_73:
    {
      *p_min = DZ5_PICKUP1_MIN;
      *p_max = DZ5_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_74:
    {
      *p_min = DZ5_PICKUP2_MIN;
      *p_max = DZ5_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_75:
    {
      *p_min = DZ5_PICKUP3_MIN;
      *p_max = DZ5_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_76:
    {
      *p_min = DZ5_PICKUP4_MIN;
      *p_max = DZ5_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_77:
    {
      *p_min = DZ5_PICKUP5_MIN;
      *p_max = DZ5_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_78:
    {
      *p_min = DZ5_PICKUP6_MIN;
      *p_max = DZ5_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_79:
    {
      *p_min = DZ5_PICKUP7_MIN;
      *p_max = DZ5_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_80:
    {
      *p_min = DZ5_PICKUP8_MIN;
      *p_max = DZ5_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_81:
    {
      *p_min = DZ5_PICKUP9_MIN;
      *p_max = DZ5_PICKUP9_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_82:
    {
      *p_min = DZ5_PICKUP10_MIN;
      *p_max = DZ5_PICKUP10_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_83:
    {
      *p_min = DZ5_PICKUP11_MIN;
      *p_max = DZ5_PICKUP11_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_84:
    {
      *p_min = DZ5_PICKUP12_MIN;
      *p_max = DZ5_PICKUP12_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_85:
    {
      *p_min = DZ5_PICKUP13_MIN;
      *p_max = DZ5_PICKUP13_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_86:
    {
      *p_min = DZ5_PICKUP14_MIN;
      *p_max = DZ5_PICKUP14_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_R;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_87:
    {
      *p_min = DZ5_PICKUP15_MIN;
      *p_max = DZ5_PICKUP15_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_X;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_88:
    {
      *p_min = DZ5_PICKUP16_MIN;
      *p_max = DZ5_PICKUP16_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_89:
    {
      *p_min = DZ5_PICKUP17_MIN;
      *p_max = DZ5_PICKUP17_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Dstp2_Iovp_ov_range;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_90:
    {
      *p_min = KOL_MF_DZ_PICKUP0_MIN;
      *p_max = KOL_MF_DZ_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zab_MF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_91:
    {
      *p_min = KOL_MF_DZ_PICKUP1_MIN;
      *p_max = KOL_MF_DZ_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zab_MF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_92:
    {
      *p_min = KOL_MF_DZ_PICKUP2_MIN;
      *p_max = KOL_MF_DZ_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_93:
    {
      *p_min = KOL_MF_DZ_PICKUP3_MIN;
      *p_max = KOL_MF_DZ_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_94:
    {
      *p_min = KOL_MF_DZ_PICKUP4_MIN;
      *p_max = KOL_MF_DZ_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zca_MF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_95:
    {
      *p_min = KOL_MF_DZ_PICKUP5_MIN;
      *p_max = KOL_MF_DZ_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zca_MF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_96:
    {
      *p_min = KOL_MF_DZ_PICKUP6_MIN;
      *p_max = KOL_MF_DZ_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZab_dt;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_97:
    {
      *p_min = KOL_MF_DZ_PICKUP7_MIN;
      *p_max = KOL_MF_DZ_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZbc_dt;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_98:
    {
      *p_min = KOL_MF_DZ_PICKUP8_MIN;
      *p_max = KOL_MF_DZ_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZca_dt;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_99:
    {
      *p_min = KOL_OF_DZ_PICKUP0_MIN;
      *p_max = KOL_OF_DZ_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Za_OF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_100:
    {
      *p_min = KOL_OF_DZ_PICKUP1_MIN;
      *p_max = KOL_OF_DZ_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Za_OF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_101:
    {
      *p_min = KOL_OF_DZ_PICKUP2_MIN;
      *p_max = KOL_OF_DZ_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zb_OF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_102:
    {
      *p_min = KOL_OF_DZ_PICKUP3_MIN;
      *p_max = KOL_OF_DZ_PICKUP3_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zb_OF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_103:
    {
      *p_min = KOL_OF_DZ_PICKUP4_MIN;
      *p_max = KOL_OF_DZ_PICKUP4_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zc_OF_Dstp_UpBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_104:
    {
      *p_min = KOL_OF_DZ_PICKUP5_MIN;
      *p_max = KOL_OF_DZ_PICKUP5_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zc_OF_Dstp_LowBoundDrift;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_105:
    {
      *p_min = KOL_OF_DZ_PICKUP6_MIN;
      *p_max = KOL_OF_DZ_PICKUP6_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZa_dt;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_106:
    {
      *p_min = KOL_OF_DZ_PICKUP7_MIN;
      *p_max = KOL_OF_DZ_PICKUP7_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZb_dt;

      break;
    }
  case ID_ED_DZ_PICKUP_VALUE_107:
    {
      *p_min = KOL_OF_DZ_PICKUP8_MIN;
      *p_max = KOL_OF_DZ_PICKUP8_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZc_dt;

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

unsigned short int* DZ_delays_notification_value_changed (
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
  case ID_ED_DZ_DELAY_VALUE_0:
    {
      *p_min = DZ1_DELAY0_MIN;
      *p_max = DZ1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_MF;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_1:
    {
      *p_min = DZ1_DELAY1_MIN;
      *p_max = DZ1_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_OF;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_2:
    {
      *p_min = DZ1_DELAY2_MIN;
      *p_max = DZ1_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_Ocp;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_3:
    {
      *p_min = DZ2_DELAY0_MIN;
      *p_max = DZ2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_4:
    {
      *p_min = DZ2_DELAY1_MIN;
      *p_max = DZ2_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_5:
    {
      *p_min = DZ2_DELAY2_MIN;
      *p_max = DZ2_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_6:
    {
      *p_min = DZ2_DELAY3_MIN;
      *p_max = DZ2_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_7:
    {
      *p_min = DZ2_DELAY4_MIN;
      *p_max = DZ2_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_8:
    {
      *p_min = DZ2_DELAY5_MIN;
      *p_max = DZ2_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_9:
    {
      *p_min = DZ2_DELAY6_MIN;
      *p_max = DZ2_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_10:
    {
      *p_min = DZ2_DELAY7_MIN;
      *p_max = DZ2_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_11:
    {
      *p_min = DZ2_DELAY8_MIN;
      *p_max = DZ2_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_12:
    {
      *p_min = DZ2_DELAY9_MIN;
      *p_max = DZ2_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_13:
    {
      *p_min = DZ2_DELAY10_MIN;
      *p_max = DZ2_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_14:
    {
      *p_min = DZ2_DELAY11_MIN;
      *p_max = DZ2_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_15:
    {
      *p_min = DZ2_DELAY12_MIN;
      *p_max = DZ2_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_16:
    {
      *p_min = DZ2_DELAY13_MIN;
      *p_max = DZ2_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_17:
    {
      *p_min = DZ3_DELAY0_MIN;
      *p_max = DZ3_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_18:
    {
      *p_min = DZ3_DELAY1_MIN;
      *p_max = DZ3_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_19:
    {
      *p_min = DZ3_DELAY2_MIN;
      *p_max = DZ3_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_20:
    {
      *p_min = DZ3_DELAY3_MIN;
      *p_max = DZ3_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_21:
    {
      *p_min = DZ3_DELAY4_MIN;
      *p_max = DZ3_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_22:
    {
      *p_min = DZ3_DELAY5_MIN;
      *p_max = DZ3_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_23:
    {
      *p_min = DZ3_DELAY6_MIN;
      *p_max = DZ3_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_24:
    {
      *p_min = DZ3_DELAY7_MIN;
      *p_max = DZ3_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_25:
    {
      *p_min = DZ3_DELAY8_MIN;
      *p_max = DZ3_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_26:
    {
      *p_min = DZ3_DELAY9_MIN;
      *p_max = DZ3_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_27:
    {
      *p_min = DZ3_DELAY10_MIN;
      *p_max = DZ3_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_28:
    {
      *p_min = DZ3_DELAY11_MIN;
      *p_max = DZ3_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_29:
    {
      *p_min = DZ3_DELAY12_MIN;
      *p_max = DZ3_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_30:
    {
      *p_min = DZ3_DELAY13_MIN;
      *p_max = DZ3_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_31:
    {
      *p_min = DZ4_DELAY0_MIN;
      *p_max = DZ4_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_32:
    {
      *p_min = DZ4_DELAY1_MIN;
      *p_max = DZ4_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_33:
    {
      *p_min = DZ4_DELAY2_MIN;
      *p_max = DZ4_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_34:
    {
      *p_min = DZ4_DELAY3_MIN;
      *p_max = DZ4_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_35:
    {
      *p_min = DZ4_DELAY4_MIN;
      *p_max = DZ4_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_36:
    {
      *p_min = DZ4_DELAY5_MIN;
      *p_max = DZ4_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_37:
    {
      *p_min = DZ4_DELAY6_MIN;
      *p_max = DZ4_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_38:
    {
      *p_min = DZ4_DELAY7_MIN;
      *p_max = DZ4_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_39:
    {
      *p_min = DZ4_DELAY8_MIN;
      *p_max = DZ4_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_40:
    {
      *p_min = DZ4_DELAY9_MIN;
      *p_max = DZ4_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_41:
    {
      *p_min = DZ4_DELAY10_MIN;
      *p_max = DZ4_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_42:
    {
      *p_min = DZ4_DELAY11_MIN;
      *p_max = DZ4_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_43:
    {
      *p_min = DZ4_DELAY12_MIN;
      *p_max = DZ4_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_44:
    {
      *p_min = DZ4_DELAY13_MIN;
      *p_max = DZ4_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_45:
    {
      *p_min = DZ5_DELAY0_MIN;
      *p_max = DZ5_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_46:
    {
      *p_min = DZ5_DELAY1_MIN;
      *p_max = DZ5_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_47:
    {
      *p_min = DZ5_DELAY2_MIN;
      *p_max = DZ5_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_48:
    {
      *p_min = DZ5_DELAY3_MIN;
      *p_max = DZ5_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_49:
    {
      *p_min = DZ5_DELAY4_MIN;
      *p_max = DZ5_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_50:
    {
      *p_min = DZ5_DELAY5_MIN;
      *p_max = DZ5_DELAY5_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_51:
    {
      *p_min = DZ5_DELAY6_MIN;
      *p_max = DZ5_DELAY6_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_52:
    {
      *p_min = DZ5_DELAY7_MIN;
      *p_max = DZ5_DELAY7_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_53:
    {
      *p_min = DZ5_DELAY8_MIN;
      *p_max = DZ5_DELAY8_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_54:
    {
      *p_min = DZ5_DELAY9_MIN;
      *p_max = DZ5_DELAY9_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_55:
    {
      *p_min = DZ5_DELAY10_MIN;
      *p_max = DZ5_DELAY10_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_56:
    {
      *p_min = DZ5_DELAY11_MIN;
      *p_max = DZ5_DELAY11_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_57:
    {
      *p_min = DZ5_DELAY12_MIN;
      *p_max = DZ5_DELAY12_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_58:
    {
      *p_min = DZ5_DELAY13_MIN;
      *p_max = DZ5_DELAY13_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_59:
    {
      *p_min = KOL_MF_DZ_DELAY0_MIN;
      *p_max = KOL_MF_DZ_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_T_counter_Dstp;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_60:
    {
      *p_min = KOL_MF_DZ_DELAY1_MIN;
      *p_max = KOL_MF_DZ_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tab;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_61:
    {
      *p_min = KOL_MF_DZ_DELAY2_MIN;
      *p_max = KOL_MF_DZ_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tbc;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_62:
    {
      *p_min = KOL_MF_DZ_DELAY3_MIN;
      *p_max = KOL_MF_DZ_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tca;

      break;
    }

  case ID_ED_DZ_DELAY_VALUE_63:
    {
      *p_min = KOL_OF_DZ_DELAY0_MIN;
      *p_max = KOL_OF_DZ_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_T_counter_Dstp;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_64:
    {
      *p_min = KOL_OF_DZ_DELAY1_MIN;
      *p_max = KOL_OF_DZ_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Ta;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_65:
    {
      *p_min = KOL_OF_DZ_DELAY2_MIN;
      *p_max = KOL_OF_DZ_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Tb;

      break;
    }
  case ID_ED_DZ_DELAY_VALUE_66:
    {
      *p_min = KOL_OF_DZ_DELAY3_MIN;
      *p_max = KOL_OF_DZ_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Tc;

      break;
    }

  case ID_ED_DZ_DELAY_G_VALUE_0:
    {
      *p_min = DZ_G_DELAY0_MIN;
      *p_max = DZ_G_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->Dstp_T_UI_NCN;

      break;
    }
  case ID_ED_DZ_DELAY_G_VALUE_1:
    {
      *p_min = DZ_G_DELAY1_MIN;
      *p_max = DZ_G_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->Dstp_T_NonSymMode_NCN;

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
void DZ_pickup_info(
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
      *p_min = DZ1_PICKUP0_MIN;
      *p_max = DZ1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 1:
    {
      *p_min = DZ1_PICKUP1_MIN;
      *p_max = DZ1_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 2:
    {
      *p_min = DZ1_PICKUP2_MIN;
      *p_max = DZ1_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 3:
    {
      *p_min = DZ1_PICKUP3_MIN;
      *p_max = DZ1_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 4:
    {
      *p_min = DZ1_PICKUP4_MIN;
      *p_max = DZ1_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 5:
    {
      *p_min = DZ1_PICKUP5_MIN;
      *p_max = DZ1_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 6:
    {
      *p_min = DZ1_PICKUP6_MIN;
      *p_max = DZ1_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 7:
    {
      *p_min = DZ1_PICKUP7_MIN;
      *p_max = DZ1_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 8:
    {
      *p_min = DZ1_PICKUP8_MIN;
      *p_max = DZ1_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 9:
    {
      *p_min = DZ1_PICKUP9_MIN;
      *p_max = DZ1_PICKUP9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 10:
    {
      *p_min = DZ1_PICKUP10_MIN;
      *p_max = DZ1_PICKUP10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 11:
    {
      *p_min = DZ1_PICKUP11_MIN;
      *p_max = DZ1_PICKUP11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 12:
    {
      *p_min = DZ1_PICKUP12_MIN;
      *p_max = DZ1_PICKUP12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 13:
    {
      *p_min = DZ1_PICKUP13_MIN;
      *p_max = DZ1_PICKUP13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 14:
    {
      *p_min = DZ1_PICKUP14_MIN;
      *p_max = DZ1_PICKUP14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 15:
    {
      *p_min = DZ1_PICKUP15_MIN;
      *p_max = DZ1_PICKUP15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 16:
    {
      *p_min = DZ1_PICKUP16_MIN;
      *p_max = DZ1_PICKUP16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 17:
    {
      *p_min = DZ1_PICKUP17_MIN;
      *p_max = DZ1_PICKUP17_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1Pickup.Dstp1_Iovp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + 0:
    {
      *p_min = DZ2_PICKUP0_MIN;
      *p_max = DZ2_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 1:
    {
      *p_min = DZ2_PICKUP1_MIN;
      *p_max = DZ2_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 2:
    {
      *p_min = DZ2_PICKUP2_MIN;
      *p_max = DZ2_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 3:
    {
      *p_min = DZ2_PICKUP3_MIN;
      *p_max = DZ2_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 4:
    {
      *p_min = DZ2_PICKUP4_MIN;
      *p_max = DZ2_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 5:
    {
      *p_min = DZ2_PICKUP5_MIN;
      *p_max = DZ2_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 6:
    {
      *p_min = DZ2_PICKUP6_MIN;
      *p_max = DZ2_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 7:
    {
      *p_min = DZ2_PICKUP7_MIN;
      *p_max = DZ2_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 8:
    {
      *p_min = DZ2_PICKUP8_MIN;
      *p_max = DZ2_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 9:
    {
      *p_min = DZ2_PICKUP9_MIN;
      *p_max = DZ2_PICKUP9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 10:
    {
      *p_min = DZ2_PICKUP10_MIN;
      *p_max = DZ2_PICKUP10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 11:
    {
      *p_min = DZ2_PICKUP11_MIN;
      *p_max = DZ2_PICKUP11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 12:
    {
      *p_min = DZ2_PICKUP12_MIN;
      *p_max = DZ2_PICKUP12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 13:
    {
      *p_min = DZ2_PICKUP13_MIN;
      *p_max = DZ2_PICKUP13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 14:
    {
      *p_min = DZ2_PICKUP14_MIN;
      *p_max = DZ2_PICKUP14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 15:
    {
      *p_min = DZ2_PICKUP15_MIN;
      *p_max = DZ2_PICKUP15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 16:
    {
      *p_min = DZ2_PICKUP16_MIN;
      *p_max = DZ2_PICKUP16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 17:
    {
      *p_min = DZ2_PICKUP17_MIN;
      *p_max = DZ2_PICKUP17_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2Pickup.Dstp2_Iovp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 0:
    {
      *p_min = DZ3_PICKUP0_MIN;
      *p_max = DZ3_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 1:
    {
      *p_min = DZ3_PICKUP1_MIN;
      *p_max = DZ3_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 2:
    {
      *p_min = DZ3_PICKUP2_MIN;
      *p_max = DZ3_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 3:
    {
      *p_min = DZ3_PICKUP3_MIN;
      *p_max = DZ3_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 4:
    {
      *p_min = DZ3_PICKUP4_MIN;
      *p_max = DZ3_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 5:
    {
      *p_min = DZ3_PICKUP5_MIN;
      *p_max = DZ3_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 6:
    {
      *p_min = DZ3_PICKUP6_MIN;
      *p_max = DZ3_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 7:
    {
      *p_min = DZ3_PICKUP7_MIN;
      *p_max = DZ3_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 8:
    {
      *p_min = DZ3_PICKUP8_MIN;
      *p_max = DZ3_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 9:
    {
      *p_min = DZ3_PICKUP9_MIN;
      *p_max = DZ3_PICKUP9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 10:
    {
      *p_min = DZ3_PICKUP10_MIN;
      *p_max = DZ3_PICKUP10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 11:
    {
      *p_min = DZ3_PICKUP11_MIN;
      *p_max = DZ3_PICKUP11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 12:
    {
      *p_min = DZ3_PICKUP12_MIN;
      *p_max = DZ3_PICKUP12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 13:
    {
      *p_min = DZ3_PICKUP13_MIN;
      *p_max = DZ3_PICKUP13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 14:
    {
      *p_min = DZ3_PICKUP14_MIN;
      *p_max = DZ3_PICKUP14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 15:
    {
      *p_min = DZ3_PICKUP15_MIN;
      *p_max = DZ3_PICKUP15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 16:
    {
      *p_min = DZ3_PICKUP16_MIN;
      *p_max = DZ3_PICKUP16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 17:
    {
      *p_min = DZ3_PICKUP17_MIN;
      *p_max = DZ3_PICKUP17_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2Pickup.Dstp2_Iovp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 0:
    {
      *p_min = DZ4_PICKUP0_MIN;
      *p_max = DZ4_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 1:
    {
      *p_min = DZ4_PICKUP1_MIN;
      *p_max = DZ4_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 2:
    {
      *p_min = DZ4_PICKUP2_MIN;
      *p_max = DZ4_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 3:
    {
      *p_min = DZ4_PICKUP3_MIN;
      *p_max = DZ4_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 4:
    {
      *p_min = DZ4_PICKUP4_MIN;
      *p_max = DZ4_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 5:
    {
      *p_min = DZ4_PICKUP5_MIN;
      *p_max = DZ4_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 6:
    {
      *p_min = DZ4_PICKUP6_MIN;
      *p_max = DZ4_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 7:
    {
      *p_min = DZ4_PICKUP7_MIN;
      *p_max = DZ4_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 8:
    {
      *p_min = DZ4_PICKUP8_MIN;
      *p_max = DZ4_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 9:
    {
      *p_min = DZ4_PICKUP9_MIN;
      *p_max = DZ4_PICKUP9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 10:
    {
      *p_min = DZ4_PICKUP10_MIN;
      *p_max = DZ4_PICKUP10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 11:
    {
      *p_min = DZ4_PICKUP11_MIN;
      *p_max = DZ4_PICKUP11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 12:
    {
      *p_min = DZ4_PICKUP12_MIN;
      *p_max = DZ4_PICKUP12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 13:
    {
      *p_min = DZ4_PICKUP13_MIN;
      *p_max = DZ4_PICKUP13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 14:
    {
      *p_min = DZ4_PICKUP14_MIN;
      *p_max = DZ4_PICKUP14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 15:
    {
      *p_min = DZ4_PICKUP15_MIN;
      *p_max = DZ4_PICKUP15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 16:
    {
      *p_min = DZ4_PICKUP16_MIN;
      *p_max = DZ4_PICKUP16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 17:
    {
      *p_min = DZ4_PICKUP17_MIN;
      *p_max = DZ4_PICKUP17_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2Pickup.Dstp2_Iovp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 0:
    {
      *p_min = DZ5_PICKUP0_MIN;
      *p_max = DZ5_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 1:
    {
      *p_min = DZ5_PICKUP1_MIN;
      *p_max = DZ5_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 2:
    {
      *p_min = DZ5_PICKUP2_MIN;
      *p_max = DZ5_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 3:
    {
      *p_min = DZ5_PICKUP3_MIN;
      *p_max = DZ5_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 4:
    {
      *p_min = DZ5_PICKUP4_MIN;
      *p_max = DZ5_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 5:
    {
      *p_min = DZ5_PICKUP5_MIN;
      *p_max = DZ5_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 6:
    {
      *p_min = DZ5_PICKUP6_MIN;
      *p_max = DZ5_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 7:
    {
      *p_min = DZ5_PICKUP7_MIN;
      *p_max = DZ5_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 8:
    {
      *p_min = DZ5_PICKUP8_MIN;
      *p_max = DZ5_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 9:
    {
      *p_min = DZ5_PICKUP9_MIN;
      *p_max = DZ5_PICKUP9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 10:
    {
      *p_min = DZ5_PICKUP10_MIN;
      *p_max = DZ5_PICKUP10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 11:
    { 
      *p_min = DZ5_PICKUP11_MIN;
      *p_max = DZ5_PICKUP11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 12:
    {
      *p_min = DZ5_PICKUP12_MIN;
      *p_max = DZ5_PICKUP12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 13:
    {
      *p_min = DZ5_PICKUP13_MIN;
      *p_max = DZ5_PICKUP13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 14:
    {
      *p_min = DZ5_PICKUP14_MIN;
      *p_max = DZ5_PICKUP14_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_R;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 15:
    {
      *p_min = DZ5_PICKUP15_MIN;
      *p_max = DZ5_PICKUP15_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_X;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 16:
    {
      *p_min = DZ5_PICKUP16_MIN;
      *p_max = DZ5_PICKUP16_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 17:
    {
      *p_min = DZ5_PICKUP17_MIN;
      *p_max = DZ5_PICKUP17_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2Pickup.Dstp2_Iovp_ov_range;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 0:
    {
      *p_min = KOL_MF_DZ_PICKUP0_MIN;
      *p_max = KOL_MF_DZ_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zab_MF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 1:
    {
      *p_min = KOL_MF_DZ_PICKUP1_MIN;
      *p_max = KOL_MF_DZ_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zab_MF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 2:
    {
      *p_min = KOL_MF_DZ_PICKUP2_MIN;
      *p_max = KOL_MF_DZ_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 3:
    {
      *p_min = KOL_MF_DZ_PICKUP3_MIN;
      *p_max = KOL_MF_DZ_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 4:
    {
      *p_min = KOL_MF_DZ_PICKUP4_MIN;
      *p_max = KOL_MF_DZ_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zca_MF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 5:
    {
      *p_min = KOL_MF_DZ_PICKUP5_MIN;
      *p_max = KOL_MF_DZ_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.Zca_MF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 6:
    {
      *p_min = KOL_MF_DZ_PICKUP6_MIN;
      *p_max = KOL_MF_DZ_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZab_dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 7:
    {
      *p_min = KOL_MF_DZ_PICKUP7_MIN;
      *p_max = KOL_MF_DZ_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZbc_dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 8:
    {
      *p_min = KOL_MF_DZ_PICKUP8_MIN;
      *p_max = KOL_MF_DZ_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZca_dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 0:
    {
      *p_min = KOL_OF_DZ_PICKUP0_MIN;
      *p_max = KOL_OF_DZ_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Za_OF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 1:
    {
      *p_min = KOL_OF_DZ_PICKUP1_MIN;
      *p_max = KOL_OF_DZ_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Za_OF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 2:
    {
      *p_min = KOL_OF_DZ_PICKUP2_MIN;
      *p_max = KOL_OF_DZ_PICKUP2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zb_OF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 3:
    {
      *p_min = KOL_OF_DZ_PICKUP3_MIN;
      *p_max = KOL_OF_DZ_PICKUP3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zb_OF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 4:
    {
      *p_min = KOL_OF_DZ_PICKUP4_MIN;
      *p_max = KOL_OF_DZ_PICKUP4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zc_OF_Dstp_UpBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 5:
    {
      *p_min = KOL_OF_DZ_PICKUP5_MIN;
      *p_max = KOL_OF_DZ_PICKUP5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.Zc_OF_Dstp_LowBoundDrift;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 6:
    {
      *p_min = KOL_OF_DZ_PICKUP6_MIN;
      *p_max = KOL_OF_DZ_PICKUP6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZa_dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 7:
    {
      *p_min = KOL_OF_DZ_PICKUP7_MIN;
      *p_max = KOL_OF_DZ_PICKUP7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZb_dt;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 8:
    {
      *p_min = KOL_OF_DZ_PICKUP8_MIN;
      *p_max = KOL_OF_DZ_PICKUP8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZc_dt;
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
void DZ_delay_info(
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
      *p_min = DZ1_DELAY0_MIN;
      *p_max = DZ1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_MF;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = DZ1_DELAY1_MIN;
      *p_max = DZ1_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_OF;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = DZ1_DELAY2_MIN;
      *p_max = DZ1_DELAY2_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage1Dstp1StageParam.Dstp1_T_Ocp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + 0:
    {
      *p_min = DZ2_DELAY0_MIN;
      *p_max = DZ2_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 1:
    {
      *p_min = DZ2_DELAY1_MIN;
      *p_max = DZ2_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 2:
    {
      *p_min = DZ2_DELAY2_MIN;
      *p_max = DZ2_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 3:
    {
      *p_min = DZ2_DELAY3_MIN;
      *p_max = DZ2_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_MF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 4:
    {
      *p_min = DZ2_DELAY4_MIN;
      *p_max = DZ2_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 5:
    {
      *p_min = DZ2_DELAY5_MIN;
      *p_max = DZ2_DELAY5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 6:
    {
      *p_min = DZ2_DELAY6_MIN;
      *p_max = DZ2_DELAY6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 7:
    {
      *p_min = DZ2_DELAY7_MIN;
      *p_max = DZ2_DELAY7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_OF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 8:
    {
      *p_min = DZ2_DELAY8_MIN;
      *p_max = DZ2_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 9:
    {
      *p_min = DZ2_DELAY9_MIN;
      *p_max = DZ2_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 10:
    {
      *p_min = DZ2_DELAY10_MIN;
      *p_max = DZ2_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 11:
    {
      *p_min = DZ2_DELAY11_MIN;
      *p_max = DZ2_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 12:
    {
      *p_min = DZ2_DELAY12_MIN;
      *p_max = DZ2_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 13:
    {
      *p_min = DZ2_DELAY13_MIN;
      *p_max = DZ2_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage2Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 0:
    {
      *p_min = DZ3_DELAY0_MIN;
      *p_max = DZ3_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 1:
    {
      *p_min = DZ3_DELAY1_MIN;
      *p_max = DZ3_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 2:
    {
      *p_min = DZ3_DELAY2_MIN;
      *p_max = DZ3_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 3:
    {
      *p_min = DZ3_DELAY3_MIN;
      *p_max = DZ3_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_MF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 4:
    {
      *p_min = DZ3_DELAY4_MIN;
      *p_max = DZ3_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 5:
    {
      *p_min = DZ3_DELAY5_MIN;
      *p_max = DZ3_DELAY5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 6:
    {
      *p_min = DZ3_DELAY6_MIN;
      *p_max = DZ3_DELAY6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 7:
    {
      *p_min = DZ3_DELAY7_MIN;
      *p_max = DZ3_DELAY7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_OF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 8:
    {
      *p_min = DZ3_DELAY8_MIN;
      *p_max = DZ3_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 9:
    {
      *p_min = DZ3_DELAY9_MIN;
      *p_max = DZ3_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 10:
    {
      *p_min = DZ3_DELAY10_MIN;
      *p_max = DZ3_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 11:
    {
      *p_min = DZ3_DELAY11_MIN;
      *p_max = DZ3_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 12:
    {
      *p_min = DZ3_DELAY12_MIN;
      *p_max = DZ3_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 13:
    {
      *p_min = DZ3_DELAY13_MIN;
      *p_max = DZ3_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage3Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 0:
    {
      *p_min = DZ4_DELAY0_MIN;
      *p_max = DZ4_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 1:
    {
      *p_min = DZ4_DELAY1_MIN;
      *p_max = DZ4_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 2:
    {
      *p_min = DZ4_DELAY2_MIN;
      *p_max = DZ4_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 3:
    {
      *p_min = DZ4_DELAY3_MIN;
      *p_max = DZ4_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_MF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 4:
    {
      *p_min = DZ4_DELAY4_MIN;
      *p_max = DZ4_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 5:
    {
      *p_min = DZ4_DELAY5_MIN;
      *p_max = DZ4_DELAY5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 6:
    {
      *p_min = DZ4_DELAY6_MIN;
      *p_max = DZ4_DELAY6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 7:
    {
      *p_min = DZ4_DELAY7_MIN;
      *p_max = DZ4_DELAY7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_OF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 8:
    {
      *p_min = DZ4_DELAY8_MIN;
      *p_max = DZ4_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 9:
    {
      *p_min = DZ4_DELAY9_MIN;
      *p_max = DZ4_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 10:
    {
      *p_min = DZ4_DELAY10_MIN;
      *p_max = DZ4_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 11:
    {
      *p_min = DZ4_DELAY11_MIN;
      *p_max = DZ4_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 12:
    {
      *p_min = DZ4_DELAY12_MIN;
      *p_max = DZ4_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 13:
    {
      *p_min = DZ4_DELAY13_MIN;
      *p_max = DZ4_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage4Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 0:
    {
      *p_min = DZ5_DELAY0_MIN;
      *p_max = DZ5_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 1:
    {
      *p_min = DZ5_DELAY1_MIN;
      *p_max = DZ5_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 2:
    {
      *p_min = DZ5_DELAY2_MIN;
      *p_max = DZ5_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 3:
    {
      *p_min = DZ5_DELAY3_MIN;
      *p_max = DZ5_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_MF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 4:
    {
      *p_min = DZ5_DELAY4_MIN;
      *p_max = DZ5_DELAY4_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 5:
    {
      *p_min = DZ5_DELAY5_MIN;
      *p_max = DZ5_DELAY5_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 6:
    {
      *p_min = DZ5_DELAY6_MIN;
      *p_max = DZ5_DELAY6_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 7:
    {
      *p_min = DZ5_DELAY7_MIN;
      *p_max = DZ5_DELAY7_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_OF_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 8:
    {
      *p_min = DZ5_DELAY8_MIN;
      *p_max = DZ5_DELAY8_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 9:
    {
      *p_min = DZ5_DELAY9_MIN;
      *p_max = DZ5_DELAY9_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 10:
    {
      *p_min = DZ5_DELAY10_MIN;
      *p_max = DZ5_DELAY10_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_op_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 11:
    {
      *p_min = DZ5_DELAY11_MIN;
      *p_max = DZ5_DELAY11_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 12:
    {
      *p_min = DZ5_DELAY12_MIN;
      *p_max = DZ5_DELAY12_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 13:
    {
      *p_min = DZ5_DELAY13_MIN;
      *p_max = DZ5_DELAY13_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrStage5Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 0:
    {
      *p_min = KOL_MF_DZ_DELAY0_MIN;
      *p_max = KOL_MF_DZ_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_T_counter_Dstp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 1:
    {
      *p_min = KOL_MF_DZ_DELAY1_MIN;
      *p_max = KOL_MF_DZ_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tab;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 2:
    {
      *p_min = KOL_MF_DZ_DELAY2_MIN;
      *p_max = KOL_MF_DZ_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tbc;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 3:
    {
      *p_min = KOL_MF_DZ_DELAY3_MIN;
      *p_max = KOL_MF_DZ_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkPp.BlkDrift_Tca;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 0:
    {
      *p_min = KOL_OF_DZ_DELAY0_MIN;
      *p_max = KOL_OF_DZ_DELAY0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_T_counter_Dstp;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 1:
    {
      *p_min = KOL_OF_DZ_DELAY1_MIN;
      *p_max = KOL_OF_DZ_DELAY1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Ta;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 2:
    {
      *p_min = KOL_OF_DZ_DELAY2_MIN;
      *p_max = KOL_OF_DZ_DELAY2_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Tb;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 3:
    {
      *p_min = KOL_OF_DZ_DELAY3_MIN;
      *p_max = KOL_OF_DZ_DELAY3_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[DZ_select_group].ownrDstpDriftBlkSp.BlkDrift_Tc;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 0:
    {
      *p_min = DZ_G_DELAY0_MIN;
      *p_max = DZ_G_DELAY0_MAX;
                
      *p_value_int = point->Dstp_T_UI_NCN;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 1:
    {
      *p_min = DZ_G_DELAY1_MIN;
      *p_max = DZ_G_DELAY1_MAX;
                
      *p_value_int = point->Dstp_T_NonSymMode_NCN;
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
const char* DZ_pickup_info_1(
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
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP6_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP6_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP7_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP7_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP8_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP8_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 9:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP9_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP9_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 10:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP10_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP10_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 11:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP11_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP11_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 12:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP12_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP12_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 13:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP13_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP13_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 14:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP14_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP14_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 15:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP15_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ1_PICKUP15_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case 16:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = DZ1_PICKUP16_MAX/1000;
      *p_shift = DZ1_PICKUP16_SHIFT;
        
      break;
    }
  case 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = DZ1_PICKUP17_MAX/1000;
      *p_shift = DZ1_PICKUP17_SHIFT;
        
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP6_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP6_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP7_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP7_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP8_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP8_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 9:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP9_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP9_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 10:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP10_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP10_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 11:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP11_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP11_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 12:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP12_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP12_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 13:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP13_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP13_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 14:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP14_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP14_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 15:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP15_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ2_PICKUP15_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 16:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = DZ2_PICKUP16_MAX/1000;
      *p_shift = DZ2_PICKUP16_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = DZ2_PICKUP17_MAX/1000;
      *p_shift = DZ2_PICKUP17_SHIFT;
        
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP6_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP6_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP7_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP7_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP8_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP8_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 9:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP9_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP9_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 10:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP10_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP10_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 11:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP11_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP11_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 12:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP12_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP12_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 13:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP13_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP13_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 14:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP14_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP14_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 15:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP15_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ3_PICKUP15_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 16:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = DZ3_PICKUP16_MAX/1000;
      *p_shift = DZ3_PICKUP16_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = DZ3_PICKUP17_MAX/1000;
      *p_shift = DZ3_PICKUP17_SHIFT;
        
      break;
    }

  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP6_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP6_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP7_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP7_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP8_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP8_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 9:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP9_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP9_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 10:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP10_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP10_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 11:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP11_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP11_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 12:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP12_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP12_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 13:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP13_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP13_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 14:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP14_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP14_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 15:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP15_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ4_PICKUP15_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 16:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = DZ4_PICKUP16_MAX/1000;
      *p_shift = DZ4_PICKUP16_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = DZ4_PICKUP17_MAX/1000;
      *p_shift = DZ4_PICKUP17_SHIFT;
        
      break;
    }
  
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP6_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP6_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP7_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP7_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP8_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP8_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 9:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP9_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP9_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 10:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP10_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP10_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 11:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP11_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP11_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 12:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP12_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP12_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 13:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP13_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP13_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 14:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP14_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP14_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 15:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP15_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = DZ5_PICKUP15_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 16:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = DZ5_PICKUP16_MAX/1000;
      *p_shift = DZ5_PICKUP16_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = DZ5_PICKUP17_MAX/1000;
      *p_shift = DZ5_PICKUP17_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_MF_DZ_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP6_MAX/1000;
      *p_shift = KOL_MF_DZ_PICKUP6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP7_MAX/1000;
      *p_shift = KOL_MF_DZ_PICKUP7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_MF_DZ_PICKUP8_MAX/1000;
      *p_shift = KOL_MF_DZ_PICKUP8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP0_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP0_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP1_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP1_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP2_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP2_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 3:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP3_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP3_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 4:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP4_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP4_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 5:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP5_MAX/1000;
      *p_min = -(*p_max);
      *p_shift = KOL_OF_DZ_PICKUP5_SHIFT;
      *extra_param |= FLAG_SIGNED_FATA;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 6:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP6_MAX/1000;
      *p_shift = KOL_OF_DZ_PICKUP6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 7:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP7_MAX/1000;
      *p_shift = KOL_OF_DZ_PICKUP7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      
      *p_max = KOL_OF_DZ_PICKUP8_MAX/1000;
      *p_shift = KOL_OF_DZ_PICKUP8_SHIFT;
        
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
const char* DZ_delay_info_1(
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
      *p_max = DZ1_DELAY0_MAX/100;
      *p_shift = DZ1_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = DZ1_DELAY1_MAX/100;
      *p_shift = DZ1_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = DZ1_DELAY2_MAX/100;
      *p_shift = DZ1_DELAY2_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + 0:
    {
      *p_max = DZ2_DELAY0_MAX/100;
      *p_shift = DZ2_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 1:
    {
      *p_max = DZ2_DELAY1_MAX/100;
      *p_shift = DZ2_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 2:
    {
      *p_max = DZ2_DELAY2_MAX/100;
      *p_shift = DZ2_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 3:
    {
      *p_max = DZ2_DELAY3_MAX/100;
      *p_shift = DZ2_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 4:
    {
      *p_max = DZ2_DELAY4_MAX/100;
      *p_shift = DZ2_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 5:
    {
      *p_max = DZ2_DELAY5_MAX/100;
      *p_shift = DZ2_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 6:
    {
      *p_max = DZ2_DELAY6_MAX/100;
      *p_shift = DZ2_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 7:
    {
      *p_max = DZ2_DELAY7_MAX/100;
      *p_shift = DZ2_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 8:
    {
      *p_max = DZ2_DELAY8_MAX/100;
      *p_shift = DZ2_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 9:
    {
      *p_max = DZ2_DELAY9_MAX/100;
      *p_shift = DZ2_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 10:
    {
      *p_max = DZ2_DELAY10_MAX/100;
      *p_shift = DZ2_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 11:
    {
      *p_max = DZ2_DELAY11_MAX/100;
      *p_shift = DZ2_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 12:
    {
      *p_max = DZ2_DELAY12_MAX/100;
      *p_shift = DZ2_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + 13:
    {
      *p_max = DZ2_DELAY13_MAX/100;
      *p_shift = DZ2_DELAY13_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 0:
    {
      *p_max = DZ3_DELAY0_MAX/100;
      *p_shift = DZ3_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 1:
    {
      *p_max = DZ3_DELAY1_MAX/100;
      *p_shift = DZ3_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 2:
    {
      *p_max = DZ3_DELAY2_MAX/100;
      *p_shift = DZ3_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 3:
    {
      *p_max = DZ3_DELAY3_MAX/100;
      *p_shift = DZ3_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 4:
    {
      *p_max = DZ3_DELAY4_MAX/100;
      *p_shift = DZ3_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 5:
    {
      *p_max = DZ3_DELAY5_MAX/100;
      *p_shift = DZ3_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 6:
    {
      *p_max = DZ3_DELAY6_MAX/100;
      *p_shift = DZ3_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 7:
    {
      *p_max = DZ3_DELAY7_MAX/100;
      *p_shift = DZ3_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 8:
    {
      *p_max = DZ3_DELAY8_MAX/100;
      *p_shift = DZ3_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 9:
    {
      *p_max = DZ3_DELAY9_MAX/100;
      *p_shift = DZ3_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 10:
    {
      *p_max = DZ3_DELAY10_MAX/100;
      *p_shift = DZ3_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 11:
    {
      *p_max = DZ3_DELAY11_MAX/100;
      *p_shift = DZ3_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 12:
    {
      *p_max = DZ3_DELAY12_MAX/100;
      *p_shift = DZ3_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 13:
    {
      *p_max = DZ3_DELAY13_MAX/100;
      *p_shift = DZ3_DELAY13_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 0:
    {
      *p_max = DZ4_DELAY0_MAX/100;
      *p_shift = DZ4_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 1:
    {
      *p_max = DZ4_DELAY1_MAX/100;
      *p_shift = DZ4_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 2:
    {
      *p_max = DZ4_DELAY2_MAX/100;
      *p_shift = DZ4_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 3:
    {
      *p_max = DZ4_DELAY3_MAX/100;
      *p_shift = DZ4_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 4:
    {
      *p_max = DZ4_DELAY4_MAX/100;
      *p_shift = DZ4_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 5:
    {
      *p_max = DZ4_DELAY5_MAX/100;
      *p_shift = DZ4_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 6:
    {
      *p_max = DZ4_DELAY6_MAX/100;
      *p_shift = DZ4_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 7:
    {
      *p_max = DZ4_DELAY7_MAX/100;
      *p_shift = DZ4_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 8:
    {
      *p_max = DZ4_DELAY8_MAX/100;
      *p_shift = DZ4_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 9:
    {
      *p_max = DZ4_DELAY9_MAX/100;
      *p_shift = DZ4_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 10:
    {
      *p_max = DZ4_DELAY10_MAX/100;
      *p_shift = DZ4_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 11:
    {
      *p_max = DZ4_DELAY11_MAX/100;
      *p_shift = DZ4_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 12:
    {
      *p_max = DZ4_DELAY12_MAX/100;
      *p_shift = DZ4_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 13:
    {
      *p_max = DZ4_DELAY13_MAX/100;
      *p_shift = DZ4_DELAY13_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 0:
    {
      *p_max = DZ5_DELAY0_MAX/100;
      *p_shift = DZ5_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 1:
    {
      *p_max = DZ5_DELAY1_MAX/100;
      *p_shift = DZ5_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 2:
    {
      *p_max = DZ5_DELAY2_MAX/100;
      *p_shift = DZ5_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 3:
    {
      *p_max = DZ5_DELAY3_MAX/100;
      *p_shift = DZ5_DELAY3_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 4:
    {
      *p_max = DZ5_DELAY4_MAX/100;
      *p_shift = DZ5_DELAY4_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 5:
    {
      *p_max = DZ5_DELAY5_MAX/100;
      *p_shift = DZ5_DELAY5_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 6:
    {
      *p_max = DZ5_DELAY6_MAX/100;
      *p_shift = DZ5_DELAY6_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 7:
    {
      *p_max = DZ5_DELAY7_MAX/100;
      *p_shift = DZ5_DELAY7_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 8:
    {
      *p_max = DZ5_DELAY8_MAX/100;
      *p_shift = DZ5_DELAY8_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 9:
    {
      *p_max = DZ5_DELAY9_MAX/100;
      *p_shift = DZ5_DELAY9_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 10:
    {
      *p_max = DZ5_DELAY10_MAX/100;
      *p_shift = DZ5_DELAY10_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 11:
    {
      *p_max = DZ5_DELAY11_MAX/100;
      *p_shift = DZ5_DELAY11_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 12:
    {
      *p_max = DZ5_DELAY12_MAX/100;
      *p_shift = DZ5_DELAY12_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 13:
    {
      *p_max = DZ5_DELAY13_MAX/100;
      *p_shift = DZ5_DELAY13_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 0:
    {
      *p_max = KOL_MF_DZ_DELAY0_MAX/100;
      *p_shift = KOL_MF_DZ_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 1:
    {
      *p_max = KOL_MF_DZ_DELAY1_MAX/100;
      *p_shift = KOL_MF_DZ_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 2:
    {
      *p_max = KOL_MF_DZ_DELAY2_MAX/100;
      *p_shift = KOL_MF_DZ_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 3:
    {
      *p_max = KOL_MF_DZ_DELAY3_MAX/100;
      *p_shift = KOL_MF_DZ_DELAY3_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 0:
    {
      *p_max = KOL_OF_DZ_DELAY0_MAX/100;
      *p_shift = KOL_OF_DZ_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 1:
    {
      *p_max = KOL_OF_DZ_DELAY1_MAX/100;
      *p_shift = KOL_OF_DZ_DELAY1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 2:
    {
      *p_max = KOL_OF_DZ_DELAY2_MAX/100;
      *p_shift = KOL_OF_DZ_DELAY2_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 3:
    {
      *p_max = KOL_OF_DZ_DELAY3_MAX/100;
      *p_shift = KOL_OF_DZ_DELAY3_SHIFT;
        
      break;
    }

  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 0:
    {
      *p_max = DZ_G_DELAY0_MAX/100;
      *p_shift = DZ_G_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 1:
    {
      *p_max = DZ_G_DELAY1_MAX/100;
      *p_shift = DZ_G_DELAY1_SHIFT;
        
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
const char* DZ_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 16:
  case MAX_NUMBER_PICKUP_DZ1 + 16:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 16:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 16:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 16:
    {
      p_pickup_dimention = empty_string;
      break;
    }
  case 17:
  case MAX_NUMBER_PICKUP_DZ1 + 17:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 17:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 17:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 17:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      break;
    }
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 6:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 7:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 8:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 6:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 7:
  case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 8:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE_DIV_SECOND].ptitle[sel_language];
      break;
    }
  default:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_RESISTANCE].ptitle[sel_language];
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для МТЗ
**********/
const TITLE* DZ_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для МТЗ
**********/
unsigned char* DZ_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1Dstp1Mng.state_dstp1;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1Dstp1Mng.state_blk_from_drift_dstp1;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrStg1Dstp1Mng.state_ocp_dstp1;
      break;
    }

  case MAX_NUMBER_CTRL_DZ1 + 0:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + 1:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_blk_from_drift_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + 2:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_ocp_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + 3:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_Tele_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + 4:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_Auto_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + 5:
    {
      p_to_state = &point->ownrStg2Dstp2Mng.state_aclt_dstp2_hws;
      break;
    }

  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 0:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 1:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_blk_from_drift_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 2:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_ocp_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 3:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_Tele_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 4:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_Auto_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + 5:
    {
      p_to_state = &point->ownrStg3Dstp2Mng.state_aclt_dstp2_hws;
      break;
    }

  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 0:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 1:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_blk_from_drift_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 2:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_ocp_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 3:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_Tele_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 4:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_Auto_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + 5:
    {
      p_to_state = &point->ownrStg4Dstp2Mng.state_aclt_dstp2_hws;
      break;
    }

  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 0:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 1:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_blk_from_drift_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 2:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_ocp_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 3:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_Tele_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 4:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_Auto_aclt_dstp2;
      break;
    }
  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + 5:
    {
      p_to_state = &point->ownrStg5Dstp2Mng.state_aclt_dstp2_hws;
      break;
    }

  case MAX_NUMBER_CTRL_DZ1 + MAX_NUMBER_CTRL_DZ2 + MAX_NUMBER_CTRL_DZ3 + MAX_NUMBER_CTRL_DZ4 + MAX_NUMBER_CTRL_DZ5 + 0:
    {
      p_to_state = &point->state_FaultU_Dstp;
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
void DZ_change_state_callback(
                               unsigned int number,
                               CfgTblDsc *point
                              )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_DZ(CfgTblDsc *point)
{
  unsigned int  ok = true;

  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_DZ) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = DZ1_PICKUP0_MIN;
          max = DZ1_PICKUP0_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_R);

          break;
        }
      case 1:
        {
          min = DZ1_PICKUP1_MIN;
          max = DZ1_PICKUP1_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_X);

          break;
        }
      case 2:
        {
          min = DZ1_PICKUP2_MIN;
          max = DZ1_PICKUP2_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_R);

          break;
        }
      case 3:
        {
          min = DZ1_PICKUP3_MIN;
          max = DZ1_PICKUP3_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_X);

          break;
        }
      case 4:
        {
          min = DZ1_PICKUP4_MIN;
          max = DZ1_PICKUP4_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_R);

          break;
        }
      case 5:
        {
          min = DZ1_PICKUP5_MIN;
          max = DZ1_PICKUP5_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_X);

          break;
        }
      case 6:
        {
          min = DZ1_PICKUP6_MIN;
          max = DZ1_PICKUP6_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_R);

          break;
        }
      case 7:
        {
          min = DZ1_PICKUP7_MIN;
          max = DZ1_PICKUP7_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_X);

          break;
        }
      case 8:
        {
          min = DZ1_PICKUP8_MIN;
          max = DZ1_PICKUP8_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_R);

          break;
        }
      case 9:
        {
          min = DZ1_PICKUP9_MIN;
          max = DZ1_PICKUP9_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_X);

          break;
        }
      case 10:
        {
          min = DZ1_PICKUP10_MIN;
          max = DZ1_PICKUP10_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_R);

          break;
        }
      case 11:
        {
          min = DZ1_PICKUP11_MIN;
          max = DZ1_PICKUP11_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_X);

          break;
        }
      case 12:
        {
          min = DZ1_PICKUP12_MIN;
          max = DZ1_PICKUP12_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_R);

          break;
        }
      case 13:
        {
          min = DZ1_PICKUP13_MIN;
          max = DZ1_PICKUP13_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_X);

          break;
        }
      case 14:
        {
          min = DZ1_PICKUP14_MIN;
          max = DZ1_PICKUP14_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_R);

          break;
        }
      case 15:
        {
          min = DZ1_PICKUP15_MIN;
          max = DZ1_PICKUP15_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_X);

          break;
        }
      case 16:
        {
          min = DZ1_PICKUP16_MIN;
          max = DZ1_PICKUP16_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur);

          break;
        }
      case 17:
        {
          min = DZ1_PICKUP17_MIN;
          max = DZ1_PICKUP17_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1Dstp1Pickup.Dstp1_Iovp_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + 0:
        {
          min = DZ2_PICKUP0_MIN;
          max = DZ2_PICKUP0_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 1:
        {
          min = DZ2_PICKUP1_MIN;
          max = DZ2_PICKUP1_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 2:
        {
          min = DZ2_PICKUP2_MIN;
          max = DZ2_PICKUP2_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 3:
        {
          min = DZ2_PICKUP3_MIN;
          max = DZ2_PICKUP3_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 4:
        {
          min = DZ2_PICKUP4_MIN;
          max = DZ2_PICKUP4_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 5:
        {
          min = DZ2_PICKUP5_MIN;
          max = DZ2_PICKUP5_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 6:
        {
          min = DZ2_PICKUP6_MIN;
          max = DZ2_PICKUP6_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 7:
        {
          min = DZ2_PICKUP7_MIN;
          max = DZ2_PICKUP7_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 8:
        {
          min = DZ2_PICKUP8_MIN;
          max = DZ2_PICKUP8_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 9:
        {
          min = DZ2_PICKUP9_MIN;
          max = DZ2_PICKUP9_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 10:
        {
          min = DZ2_PICKUP10_MIN;
          max = DZ2_PICKUP10_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 11:
        {
          min = DZ2_PICKUP11_MIN;
          max = DZ2_PICKUP11_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 12:
        {
          min = DZ2_PICKUP12_MIN;
          max = DZ2_PICKUP12_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 13:
        {
          min = DZ2_PICKUP13_MIN;
          max = DZ2_PICKUP13_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 14:
        {
          min = DZ2_PICKUP14_MIN;
          max = DZ2_PICKUP14_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 15:
        {
          min = DZ2_PICKUP15_MIN;
          max = DZ2_PICKUP15_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 16:
        {
          min = DZ2_PICKUP16_MIN;
          max = DZ2_PICKUP16_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + 17:
        {
          min = DZ2_PICKUP17_MIN;
          max = DZ2_PICKUP17_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2Pickup.Dstp2_Iovp_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 0:
        {
          min = DZ3_PICKUP0_MIN;
          max = DZ3_PICKUP0_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 1:
        {
          min = DZ3_PICKUP1_MIN;
          max = DZ3_PICKUP1_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 2:
        {
          min = DZ3_PICKUP2_MIN;
          max = DZ3_PICKUP2_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 3:
        {
          min = DZ3_PICKUP3_MIN;
          max = DZ3_PICKUP3_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 4:
        {
          min = DZ3_PICKUP4_MIN;
          max = DZ3_PICKUP4_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 5:
        {
          min = DZ3_PICKUP5_MIN;
          max = DZ3_PICKUP5_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 6:
        {
          min = DZ3_PICKUP6_MIN;
          max = DZ3_PICKUP6_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 7:
        {
          min = DZ3_PICKUP7_MIN;
          max = DZ3_PICKUP7_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 8:
        {
          min = DZ3_PICKUP8_MIN;
          max = DZ3_PICKUP8_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 9:
        {
          min = DZ3_PICKUP9_MIN;
          max = DZ3_PICKUP9_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 10:
        {
          min = DZ3_PICKUP10_MIN;
          max = DZ3_PICKUP10_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 11:
        {
          min = DZ3_PICKUP11_MIN;
          max = DZ3_PICKUP11_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 12:
        {
          min = DZ3_PICKUP12_MIN;
          max = DZ3_PICKUP12_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 13:
        {
          min = DZ3_PICKUP13_MIN;
          max = DZ3_PICKUP13_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 14:
        {
          min = DZ3_PICKUP14_MIN;
          max = DZ3_PICKUP14_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 15:
        {
          min = DZ3_PICKUP15_MIN;
          max = DZ3_PICKUP15_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 16:
        {
          min = DZ3_PICKUP16_MIN;
          max = DZ3_PICKUP16_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + 17:
        {
          min = DZ3_PICKUP17_MIN;
          max = DZ3_PICKUP17_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2Pickup.Dstp2_Iovp_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 0:
        {
          min = DZ4_PICKUP0_MIN;
          max = DZ4_PICKUP0_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 1:
        {
          min = DZ4_PICKUP1_MIN;
          max = DZ4_PICKUP1_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 2:
        {
          min = DZ4_PICKUP2_MIN;
          max = DZ4_PICKUP2_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 3:
        {
          min = DZ4_PICKUP3_MIN;
          max = DZ4_PICKUP3_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 4:
        {
          min = DZ4_PICKUP4_MIN;
          max = DZ4_PICKUP4_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 5:
        {
          min = DZ4_PICKUP5_MIN;
          max = DZ4_PICKUP5_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 6:
        {
          min = DZ4_PICKUP6_MIN;
          max = DZ4_PICKUP6_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 7:
        {
          min = DZ4_PICKUP7_MIN;
          max = DZ4_PICKUP7_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 8:
        {
          min = DZ4_PICKUP8_MIN;
          max = DZ4_PICKUP8_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 9:
        {
          min = DZ4_PICKUP9_MIN;
          max = DZ4_PICKUP9_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 10:
        {
          min = DZ4_PICKUP10_MIN;
          max = DZ4_PICKUP10_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 11:
        {
          min = DZ4_PICKUP11_MIN;
          max = DZ4_PICKUP11_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 12:
        {
          min = DZ4_PICKUP12_MIN;
          max = DZ4_PICKUP12_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 13:
        {
          min = DZ4_PICKUP13_MIN;
          max = DZ4_PICKUP13_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 14:
        {
          min = DZ4_PICKUP14_MIN;
          max = DZ4_PICKUP14_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 15:
        {
          min = DZ4_PICKUP15_MIN;
          max = DZ4_PICKUP15_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 16:
        {
          min = DZ4_PICKUP16_MIN;
          max = DZ4_PICKUP16_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + 17:
        {
          min = DZ4_PICKUP17_MIN;
          max = DZ4_PICKUP17_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2Pickup.Dstp2_Iovp_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 0:
        {
          min = DZ5_PICKUP0_MIN;
          max = DZ5_PICKUP0_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 1:
        {
          min = DZ5_PICKUP1_MIN;
          max = DZ5_PICKUP1_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 2:
        {
          min = DZ5_PICKUP2_MIN;
          max = DZ5_PICKUP2_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 3:
        {
          min = DZ5_PICKUP3_MIN;
          max = DZ5_PICKUP3_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 4:
        {
          min = DZ5_PICKUP4_MIN;
          max = DZ5_PICKUP4_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 5:
        {
          min = DZ5_PICKUP5_MIN;
          max = DZ5_PICKUP5_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 6:
        {
          min = DZ5_PICKUP6_MIN;
          max = DZ5_PICKUP6_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 7:
        {
          min = DZ5_PICKUP7_MIN;
          max = DZ5_PICKUP7_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 8:
        {
          min = DZ5_PICKUP8_MIN;
          max = DZ5_PICKUP8_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 9:
        {
          min = DZ5_PICKUP9_MIN;
          max = DZ5_PICKUP9_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 10:
        {
          min = DZ5_PICKUP10_MIN;
          max = DZ5_PICKUP10_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 11:
        {
          min = DZ5_PICKUP11_MIN;
          max = DZ5_PICKUP11_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 12:
        {
          min = DZ5_PICKUP12_MIN;
          max = DZ5_PICKUP12_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 13:
        {
          min = DZ5_PICKUP13_MIN;
          max = DZ5_PICKUP13_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 14:
        {
          min = DZ5_PICKUP14_MIN;
          max = DZ5_PICKUP14_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_R);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 15:
        {
          min = DZ5_PICKUP15_MIN;
          max = DZ5_PICKUP15_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_X);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 16:
        {
          min = DZ5_PICKUP16_MIN;
          max = DZ5_PICKUP16_MAX;
          value_int = abs(point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur);

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + 17:
        {
          min = DZ5_PICKUP17_MIN;
          max = DZ5_PICKUP17_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2Pickup.Dstp2_Iovp_ov_range;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 0:
        {
          min = KOL_MF_DZ_PICKUP0_MIN;
          max = KOL_MF_DZ_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zab_MF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 1:
        {
          min = KOL_MF_DZ_PICKUP1_MIN;
          max = KOL_MF_DZ_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zab_MF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 2:
        {
          min = KOL_MF_DZ_PICKUP2_MIN;
          max = KOL_MF_DZ_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 3:
        {
          min = KOL_MF_DZ_PICKUP3_MIN;
          max = KOL_MF_DZ_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zbc_MF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 4:
        {
          min = KOL_MF_DZ_PICKUP4_MIN;
          max = KOL_MF_DZ_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zca_MF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 5:
        {
          min = KOL_MF_DZ_PICKUP5_MIN;
          max = KOL_MF_DZ_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.Zca_MF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 6:
        {
          min = KOL_MF_DZ_PICKUP6_MIN;
          max = KOL_MF_DZ_PICKUP6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZab_dt;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 7:
        {
          min = KOL_MF_DZ_PICKUP7_MIN;
          max = KOL_MF_DZ_PICKUP7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZbc_dt;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + 8:
        {
          min = KOL_MF_DZ_PICKUP8_MIN;
          max = KOL_MF_DZ_PICKUP8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_PickUp_DeltaZca_dt;

          break;
        }

      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 0:
        {
          min = KOL_OF_DZ_PICKUP0_MIN;
          max = KOL_OF_DZ_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Za_OF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 1:
        {
          min = KOL_OF_DZ_PICKUP1_MIN;
          max = KOL_OF_DZ_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Za_OF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 2:
        {
          min = KOL_OF_DZ_PICKUP2_MIN;
          max = KOL_OF_DZ_PICKUP2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Zb_OF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 3:
        {
          min = KOL_OF_DZ_PICKUP3_MIN;
          max = KOL_OF_DZ_PICKUP3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Zb_OF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 4:
        {
          min = KOL_OF_DZ_PICKUP4_MIN;
          max = KOL_OF_DZ_PICKUP4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Zc_OF_Dstp_UpBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 5:
        {
          min = KOL_OF_DZ_PICKUP5_MIN;
          max = KOL_OF_DZ_PICKUP5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.Zc_OF_Dstp_LowBoundDrift;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 6:
        {
          min = KOL_OF_DZ_PICKUP6_MIN;
          max = KOL_OF_DZ_PICKUP6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZa_dt;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 7:
        {
          min = KOL_OF_DZ_PICKUP7_MIN;
          max = KOL_OF_DZ_PICKUP7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZb_dt;

          break;
        }
      case MAX_NUMBER_PICKUP_DZ1 + MAX_NUMBER_PICKUP_DZ2 + MAX_NUMBER_PICKUP_DZ3 + MAX_NUMBER_PICKUP_DZ4 + MAX_NUMBER_PICKUP_DZ5 + MAX_NUMBER_PICKUP_KOL_MF_DZ + 8:
        {
          min = KOL_OF_DZ_PICKUP8_MIN;
          max = KOL_OF_DZ_PICKUP8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_PickUp_DeltaZc_dt;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = DZ1_DELAY0_MIN;
          max = DZ1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1Dstp1StageParam.Dstp1_T_MF;

          break;
        }
      case 1:
        {
          min = DZ1_DELAY1_MIN;
          max = DZ1_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1Dstp1StageParam.Dstp1_T_OF;

          break;
        }
      case 2:
        {
          min = DZ1_DELAY2_MIN;
          max = DZ1_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1Dstp1StageParam.Dstp1_T_Ocp;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + 0:
        {
          min = DZ2_DELAY0_MIN;
          max = DZ2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_MF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 1:
        {
          min = DZ2_DELAY1_MIN;
          max = DZ2_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_MF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 2:
        {
          min = DZ2_DELAY2_MIN;
          max = DZ2_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_MF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 3:
        {
          min = DZ2_DELAY3_MIN;
          max = DZ2_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_MF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 4:
        {
          min = DZ2_DELAY4_MIN;
          max = DZ2_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_OF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 5:
        {
          min = DZ2_DELAY5_MIN;
          max = DZ2_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_OF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 6:
        {
          min = DZ2_DELAY6_MIN;
          max = DZ2_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_OF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 7:
        {
          min = DZ2_DELAY7_MIN;
          max = DZ2_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_OF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 8:
        {
          min = DZ2_DELAY8_MIN;
          max = DZ2_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 9:
        {
          min = DZ2_DELAY9_MIN;
          max = DZ2_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 10:
        {
          min = DZ2_DELAY10_MIN;
          max = DZ2_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 11:
        {
          min = DZ2_DELAY11_MIN;
          max = DZ2_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 12:
        {
          min = DZ2_DELAY12_MIN;
          max = DZ2_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + 13:
        {
          min = DZ2_DELAY13_MIN;
          max = DZ2_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 0:
        {
          min = DZ3_DELAY0_MIN;
          max = DZ3_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_MF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 1:
        {
          min = DZ3_DELAY1_MIN;
          max = DZ3_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_MF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 2:
        {
          min = DZ3_DELAY2_MIN;
          max = DZ3_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_MF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 3:
        {
          min = DZ3_DELAY3_MIN;
          max = DZ3_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_MF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 4:
        {
          min = DZ3_DELAY4_MIN;
          max = DZ3_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_OF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 5:
        {
          min = DZ3_DELAY5_MIN;
          max = DZ3_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_OF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 6:
        {
          min = DZ3_DELAY6_MIN;
          max = DZ3_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_OF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 7:
        {
          min = DZ3_DELAY7_MIN;
          max = DZ3_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_OF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 8:
        {
          min = DZ3_DELAY8_MIN;
          max = DZ3_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 9:
        {
          min = DZ3_DELAY9_MIN;
          max = DZ3_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 10:
        {
          min = DZ3_DELAY10_MIN;
          max = DZ3_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 11:
        {
          min = DZ3_DELAY11_MIN;
          max = DZ3_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 12:
        {
          min = DZ3_DELAY12_MIN;
          max = DZ3_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + 13:
        {
          min = DZ3_DELAY13_MIN;
          max = DZ3_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage3Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 0:
        {
          min = DZ4_DELAY0_MIN;
          max = DZ4_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_MF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 1:
        {
          min = DZ4_DELAY1_MIN;
          max = DZ4_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_MF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 2:
        {
          min = DZ4_DELAY2_MIN;
          max = DZ4_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_MF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 3:
        {
          min = DZ4_DELAY3_MIN;
          max = DZ4_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_MF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 4:
        {
          min = DZ4_DELAY4_MIN;
          max = DZ4_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_OF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 5:
        {
          min = DZ4_DELAY5_MIN;
          max = DZ4_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_OF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 6:
        {
          min = DZ4_DELAY6_MIN;
          max = DZ4_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_OF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 7:
        {
          min = DZ4_DELAY7_MIN;
          max = DZ4_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_OF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 8:
        {
          min = DZ4_DELAY8_MIN;
          max = DZ4_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 9:
        {
          min = DZ4_DELAY9_MIN;
          max = DZ4_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 10:
        {
          min = DZ4_DELAY10_MIN;
          max = DZ4_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 11:
        {
          min = DZ4_DELAY11_MIN;
          max = DZ4_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 12:
        {
          min = DZ4_DELAY12_MIN;
          max = DZ4_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + 13:
        {
          min = DZ4_DELAY13_MIN;
          max = DZ4_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage4Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 0:
        {
          min = DZ5_DELAY0_MIN;
          max = DZ5_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_MF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 1:
        {
          min = DZ5_DELAY1_MIN;
          max = DZ5_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_MF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 2:
        {
          min = DZ5_DELAY2_MIN;
          max = DZ5_DELAY2_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_MF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 3:
        {
          min = DZ5_DELAY3_MIN;
          max = DZ5_DELAY3_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_MF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 4:
        {
          min = DZ5_DELAY4_MIN;
          max = DZ5_DELAY4_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_OF_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 5:
        {
          min = DZ5_DELAY5_MIN;
          max = DZ5_DELAY5_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_OF_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 6:
        {
          min = DZ5_DELAY6_MIN;
          max = DZ5_DELAY6_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_OF_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 7:
        {
          min = DZ5_DELAY7_MIN;
          max = DZ5_DELAY7_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_OF_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 8:
        {
          min = DZ5_DELAY8_MIN;
          max = DZ5_DELAY8_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 9:
        {
          min = DZ5_DELAY9_MIN;
          max = DZ5_DELAY9_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 10:
        {
          min = DZ5_DELAY10_MIN;
          max = DZ5_DELAY10_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 11:
        {
          min = DZ5_DELAY11_MIN;
          max = DZ5_DELAY11_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 12:
        {
          min = DZ5_DELAY12_MIN;
          max = DZ5_DELAY12_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + 13:
        {
          min = DZ5_DELAY13_MIN;
          max = DZ5_DELAY13_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage5Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 0:
        {
          min = KOL_MF_DZ_DELAY0_MIN;
          max = KOL_MF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_T_counter_Dstp;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 1:
        {
          min = KOL_MF_DZ_DELAY0_MIN;
          max = KOL_MF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_Tab;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 2:
        {
          min = KOL_MF_DZ_DELAY0_MIN;
          max = KOL_MF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_Tbc;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + 3:
        {
          min = KOL_MF_DZ_DELAY0_MIN;
          max = KOL_MF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkPp.BlkDrift_Tca;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 0:
        {
          min = KOL_OF_DZ_DELAY0_MIN;
          max = KOL_OF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_T_counter_Dstp;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 1:
        {
          min = KOL_OF_DZ_DELAY0_MIN;
          max = KOL_OF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_Ta;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 2:
        {
          min = KOL_OF_DZ_DELAY0_MIN;
          max = KOL_OF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_Tb;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + 3:
        {
          min = KOL_OF_DZ_DELAY0_MIN;
          max = KOL_OF_DZ_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrDstpDriftBlkSp.BlkDrift_Tc;

          break;
        }

      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 0:
        {
          min = DZ_G_DELAY0_MIN;
          max = DZ_G_DELAY0_MAX;
          value_int = point->Dstp_T_UI_NCN;

          break;
        }
      case MAX_NUMBER_DELAY_DZ1 + MAX_NUMBER_DELAY_DZ2 + MAX_NUMBER_DELAY_DZ3 + MAX_NUMBER_DELAY_DZ4 + MAX_NUMBER_DELAY_DZ5 + MAX_NUMBER_DELAY_KOL_MF_DZ + MAX_NUMBER_DELAY_KOL_OF_DZ + 1:
        {
          min = DZ_G_DELAY1_MIN;
          max = DZ_G_DELAY1_MAX;
          value_int = point->Dstp_T_NonSymMode_NCN;

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
Копіювання змінених даних з структури для редагування у робочу структуру
*****************************/
void copy_data_DZ(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1Dstp1Pickup = 
    source->arPckpStpmStngStore[i].ownrStage1Dstp1Pickup; 

    target->arPckpStpmStngStore[i].ownrStage1Dstp1StageParam = 
    source->arPckpStpmStngStore[i].ownrStage1Dstp1StageParam; 

    target->arPckpStpmStngStore[i].ownrStage2Dstp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage2Dstp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage2Dstp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage2Dstp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage3Dstp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage3Dstp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage3Dstp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage3Dstp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage4Dstp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage4Dstp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage4Dstp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage4Dstp2StageParam; 

    target->arPckpStpmStngStore[i].ownrStage5Dstp2Pickup = 
    source->arPckpStpmStngStore[i].ownrStage5Dstp2Pickup; 

    target->arPckpStpmStngStore[i].ownrStage5Dstp2StageParam = 
    source->arPckpStpmStngStore[i].ownrStage5Dstp2StageParam; 

    target->arPckpStpmStngStore[i].ownrDstpDriftBlkPp = 
    source->arPckpStpmStngStore[i].ownrDstpDriftBlkPp; 

    target->arPckpStpmStngStore[i].ownrDstpDriftBlkSp = 
    source->arPckpStpmStngStore[i].ownrDstpDriftBlkSp; 
  }

  target->Dstp_T_UI_NCN = source->Dstp_T_UI_NCN;
  target->Dstp_T_NonSymMode_NCN = source->Dstp_T_NonSymMode_NCN;
  
  target->ownrStg1Dstp1Mng = source->ownrStg1Dstp1Mng;
  target->ownrStg2Dstp2Mng = source->ownrStg2Dstp2Mng;
  target->ownrStg3Dstp2Mng = source->ownrStg3Dstp2Mng;
  target->ownrStg4Dstp2Mng = source->ownrStg4Dstp2Mng;
  target->ownrStg5Dstp2Mng = source->ownrStg5Dstp2Mng;
  target->state_FaultU_Dstp  = source->state_FaultU_Dstp;
}
/*****************************/
