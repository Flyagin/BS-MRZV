/*------------------------------------------------------------------------------
* Created (c) 2015 - Factory “KyivPrylad”
* 
* Permission to use, copy, modify, and distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
* 
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
* 
*------------------------------------------------------------------------------
*
* Processor       : All
* File Name       : StngIci.c
* Description     : Definitions and structures for dstp protection
                    BM  BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  05/02/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "StngIci.h"
#include    "ici_ef.h"



StngIciTblDsc hldStngIciTbl;
 long lSizeOf_StngIci = sizeof(StngIciTblDsc );
/*
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
__SETTINGS IciStng = {

//Тип пристрою
  0,// unsigned int device_id;
  // 
  // /-*
  // Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
  // *-/
  0,0,0,0,// unsigned int dz1_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz2_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz3_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz4_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz5_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для МТЗ
  // *-/
  0,0,0,0,// unsigned int mtz1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для ТЗНП
  // *-/
  0,0,0,0,// unsigned int tznp1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для ZOP
  // *-/
  0,0,0,0,// unsigned int zop1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // 
  // /-*Рассогласование углов
  // 
  // 0 - Usyn
  // 1 - Isyn
  // 0 - Ua
  // 1 - Ub
  // 2 - Uc
  // *-/
  0,// unsigned int a_Usyn_Isyn;
  0,// unsigned int a_Ua_Ub_Uc;
  // 
  // /-*
  //  Номинальный ток от шкафа отбора напряжения
  // 0 - 0,15А
  // 1 - 0,075А
  // *-/
  0// unsigned int In_type_shon;
 


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

*/
extern SettingsHldDsc holderSettings;
//SettingsStateDsc KbdSettigsState; 
void ActivateTransmittionStngOnBM(void)  @ "Fast_function"
{
register long i;//,j;
register char *pDst;//*pSrc;//,
void* pTbl;
//struct 
//	{
//		//char chNeedClrSesData;
////		void *pOriginLDC;
//	} sLV;
//.union 
//.	    {
//.	    	unsigned char   uchAr [4];
//.	    	unsigned short  ushAr [2];
//.            unsigned long   ulVal;
//.	    }unnV1;	
SettingsStateDsc locSettigsState; 
//sLV.pOriginLDC = pvLDC;
 //sLV.chNeedClrSesData = 0;


	hldStngIciTbl.lCheckSum = 0;
	//Import from CfgPrtTbl 
	pTbl = (void*)&eeprom_prt_tbl;
	pDst = (char*)&(hldStngIciTbl.UNStngIciTbl.StngIciTbl);
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		// Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
		((__SETTINGS* )pDst)->dz1_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz2_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz3_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz4_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz5_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		
		 // Угол доворота для МТЗ
		((__SETTINGS* )pDst)->mtz1_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz2_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz3_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz4_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz5_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		 // Угол доворота для ТЗНП
		((__SETTINGS* )pDst)->tznp1_angle_r[i] = 
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;
        ((__SETTINGS* )pDst)->tznp2_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp3_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp4_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp5_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;
		 // Угол доворота для ZOP
		((__SETTINGS* )pDst)->zop1_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;
	    ((__SETTINGS* )pDst)->zop2_angle_r[i] =
	    ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;
        
	}

	//Set Additional Field
	// /-*Рассогласование углов
    //    0 - Usyn
    //    1 - Isyn
    //    0 - Ua
    //    1 - Ub
    //    2 - Uc
  
	((__SETTINGS* )pDst)-> a_Usyn_Isyn_Ubc = 0;
	//((CfgTblDsc*)pTbl)-> uc_Usyn_Isyn_selection;
	if (((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase >3 )
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase = 0;
	((__SETTINGS* )pDst)-> a_Ua_Ub_Uc =
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase;
	//((__SETTINGS* )pDst)->In_type_shon = 0;//Temp
	//((CfgTblDsc*)pTbl)-> uc_Type_shon_selection;
	
	//Put check sum
		i = Eval_CS((char*)&hldStngIciTbl,
	sizeof(StngIciTblDsc)-sizeof( hldStngIciTbl.lCheckSum) );
	
	hldStngIciTbl.lCheckSum = i;
	//Activate Transmittion
	//holderSettings.UNSettings.current_settings = hldStngIciTbl.UNStngIciTbl.StngIciTbl;
	//holderSettings.lCheckSum = hldStngIciTbl.lCheckSum;
	locSettigsState.size_current_settings = SIZE_SETTINGS_ICI;
	locSettigsState.p_current_settings    = (void*)&hldStngIciTbl;
	 ReqSendSettingsBM(1,&locSettigsState);




}





/* EOF */

