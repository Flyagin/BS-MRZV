/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : docp_df.c
* Description     : Definitions and structures for docp protection
                    BM BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  23/04/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/



//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DrOcp1MngStoreDsc hldrDrOcp1MngStore = {

0,//unsigned char state_mcp1;//меню  Состояние МТЗ1

//.	Состояние
//.	1 -вкл
//.	0 - выкл

0,//unsigned char select_prt_mcp1;//Селектор МТЗ1
//меню  выбор рабоы защиты МТЗ1 Пуск(Работа) 
//по направленности Пуск(Работа) по напряжению

//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению


//unsigned char startU_mcp1;//меню  Состояние Пуска по Напряжению
//.	Состояние
//.	1 -вкл
//.	0 - выкл

//прямой· Adj  direct; straight; through; frank; real
0,//unsigned char DirectionStraight_mcp1;//меню  МТЗ1 Напрвление Вперед Состояние 

//.	Состояние
//.	1 -вкл
//.	0 - выкл


0//unsigned char DirectionBack_mcp1;//меню  МТЗ1 Напрвление Назад Состояние 

//.	Состояние
//.	1 -вкл
//.	0 - выкл

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct DrOcp1PickupStoreDsc_TagIn
DrOcp1PickupStoreDsc hldrDrOcp1PickupMinValStg0_G0 =  {
0,//--unsigned int   mcp1_AngleRotation_linear_voltage;
//.	 угол поворота в радианах

//~~~~~~~~~~~~~~~~~~~~          Angle Staight    ~~~~~~~~~~~~~~~~~~~~~

1250,//--unsigned int   mcp1_s1_Ias_ov_range;
//.ПО МТЗН1 прям
//.	 уставка по току
//.	 1 ед = 1 мA



//~~~~~~~~~~~~~~~~~~~~        Angle Back        ~~~~~~~~~~~~~~~~~~~~~~~


1250,//--unsigned int   mcp1_s2_Iabk_ov_range;
//.ПО МТЗН1 обр
//.	 уставка по току
//.	 1 ед = 1 мA


//~~~~~~~~~~~~~~~~~~~~        Start Voltage        ~~~~~~~~~~~~~~~~~~~~
1250,//--unsigned int   mcp1_IstpU_ov_range;
//.ПО МТЗПН1
//.	 уставка по току
//.	 1 ед = 1 мA

2000,//--unsigned int   mcp1_Ustp_ov_range;
//.ПО U МТЗПН1
//.	 уставка по пуска по напряжению
//.	 1 ед = 1 мB



//~~~~~~~~~~~~~~~~~~~~        Boring MCP        ~~~~~~~~~~~~~~~~~~~~
1250,//--unsigned int   mcp1_I_ov_range;
//.ПО МТЗ1
//.	 уставка по току
//.	 1 ед = 1 мA





};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct DrOcp1StageParamStoreDsc_TagIn
DrOcp1StageParamStoreDsc hldrDrOcp1TmrStageParamMinValStg0_G0 =  {


//~~~~~~~~~~~~~~~~~~~~          Angle Staight    ~~~~~~~~~~~~~~~~~~~~~
0,//--unsigned short   mcp1_s1_time_stage;
//. Т МТЗН1 вперед
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе

//~~~~~~~~~~~~~~~~~~~~        Angle Back        ~~~~~~~~~~~~~~~~~~~~~~~
0,//--unsigned short   mcp1_s2_time_stage;
//.Т МТЗН1 пазад
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе


//~~~~~~~~~~~~~~~~~~~~        Start Voltage        ~~~~~~~~~~~~~~~~~~~~

0,//--unsigned short   mcp1_Ustp_time_stage;
//.T МТЗПН1
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе

//~~~~~~~~~~~~~~~~~~~~        Boring MCP        ~~~~~~~~~~~~~~~~~~~~

0//--unsigned short   mcp1_time_stage;
//.Т мтз1
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе



};
//
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct DrOcp2MngStoreDsc_TagIn
DrOcp2MngStoreDsc hldrDrOcpMinVal = {
0,//--unsigned char  aclt_mcp_sw;
//.	МТЗ2 Ускорение выключателя
//.	1 -вкл
//.	0 - выкл

0,//--unsigned char  state_aclt_mcp;//Состояние ключя МТЗ ускоренная
//.	1 -вкл
//.	0 - выкл

0,//--unsigned char state_mcp;//меню  Состояние МТЗ
//.	Состояние
//.	1 -вкл
//.	0 - выкл

0,//--unsigned char select_prt_mcp;//Селектор МТЗ
//меню  выбор рабоы защиты МТЗ Пуск(Работа) 
//по направленности Пуск(Работа) по напряжению

//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению

//прямой· Adj  direct; straight; through; frank; real
0,//--unsigned char DirectionStraight_mcp;//меню  МТЗ Напрвление Вперед Состояние 

//.	Состояние
//.	1 -вкл
//.	0 - выкл

0,//--unsigned char DirectionBack_mcp;//меню  МТЗ  Напрвление Назад Состояние 

//.	Состояние
//.	1 -вкл
//.	0 - выкл


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct DrOcp2PickupStoreDsc_TagIn
DrOcp2PickupStoreDsc hldrDrOcp2PickupMinValStg0_G0 =  {
0,//--unsigned int   mcp_AngleRotation_linear_voltage;
//.	 угол поворота в радианах

//~~~~~~~~~~~~~~~~~~~~          Angle Staight    ~~~~~~~~~~~~~~~~~~~~~

1250,//--unsigned int   mcp_s1_Ias_ov_range;
//.ПО МТЗН прям
//.	 уставка по току
//.	 1 ед = 1 мA

//--unsigned int   mcp1_s1_Ublk_ov_range;
//.ПО U МТЗН1 прям
//.	 уставка блокировки по напряжению
//.	 1 ед = 1 мB

//~~~~~~~~~~~~~~~~~~~~        Angle Back        ~~~~~~~~~~~~~~~~~~~~~~~

1250,//--unsigned int   mcp_s2_Iabk_ov_range;
//.ПО МТЗН обр
//.	 уставка по току
//.	 1 ед = 1 мA

//--unsigned int   mcp1_s2_Ublk_ov_range;
//.ПО U МТЗН 1 обр
//.	 уставка блокировки по напряжению
//.	 1 ед = 1 мB

//~~~~~~~~~~~~~~~~~~~~        Start Voltage        ~~~~~~~~~~~~~~~~~~~~
1250,//--unsigned int   mcp_IstpU_ov_range;
//.ПО МТЗПН
//.	 уставка по току
//.	 1 ед = 1 мA

2000,//--unsigned int   mcp_Ustp_ov_range;
//.ПО U МТЗПН
//.	 уставка по пуска по напряжению
//.	 1 ед = 1 мB



//~~~~~~~~~~~~~~~~~~~~        Boring MCP        ~~~~~~~~~~~~~~~~~~~~
1250,//--unsigned int   mcp_I_ov_range;
//.ПО МТЗ1
//.	 уставка по току
//.	 1 ед = 1 мA







};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr overcurrent protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DrOcp2StageParamStoreDsc hldrDrOcp2TmrStageParamMinValStg0_G0 = {



//~~~~~~~~~~~~~~~~~~~~          Angle Staight    ~~~~~~~~~~~~~~~~~~~~~
0,//--unsigned short   mcp_s1_time_stage;
//. Т МТЗН1 вперед
//.	выдержка x- ступени МТЗ
//.	1 ед =10мсе
0,//unsigned short  mcp_s1_T_op_aclt;  //.Т оп.уск.  МТЗ 
0,//unsigned short  mcp_s1_T_aclt;     //.Т уск.  МТЗ 

0,//unsigned short  mcp_s1_T_tele_aclt;//.Т телеуск.   МТЗ 

//~~~~~~~~~~~~~~~~~~~~        Angle Back        ~~~~~~~~~~~~~~~~~~~~~~~
0,//--unsigned short   mcp_s2_time_stage;
//.Т МТЗН пазад
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе
0,//unsigned short  mcp_s2_T_op_aclt;  //.Т оп.уск.  МТЗ 
0,//unsigned short  mcp_s2_T_aclt;     //.Т уск.  МТЗ 

0,//unsigned short  mcp_s2_T_tele_aclt;//.Т телеуск.   МТЗ 

//~~~~~~~~~~~~~~~~~~~~        Start Voltage        ~~~~~~~~~~~~~~~~~~~~

0,//--unsigned short   mcp_Ustp_time_stage;
//.T МТЗПН
//.	выдержка X- ступени МТЗ
//.	1 ед =10мсе
0,//unsigned short  mcp_Ustp_T_op_aclt;  //.Т оп.уск.  МТЗ 
0,//unsigned short  mcp_Ustp_T_aclt;     //.Т уск.  МТЗ 

0,//unsigned short  mcp_Ustp_T_tele_aclt;//.Т телеуск.   МТЗ 

//~~~~~~~~~~~~~~~~~~~~        Boring MCP        ~~~~~~~~~~~~~~~~~~~~


0,//--unsigned short   mcp_time_stage;
//.Т мтз1
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе
0,//unsigned short   mcp_time_stage_Aclt;      //- выдержка ускорения ступени МТЗ                    ---

0,//unsigned short  mcp_T_op_aclt;  //.Т оп.уск.  МТЗ 
0,//unsigned short  mcp_T_tele_aclt;//.Т телеуск.   МТЗ 

0//unsigned short   mcp_Tau_AcltImp;          //- длительноть формирования импульса ускорения  ступени МТЗ ---

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern CfgTblDsc currnet_settings, eeprom_prt_tbl;

void SetPrtTestVal1(void* pTbl)
{
  register long i;
  register unsigned long j;
register void *pv1,*pv2;

	for (i = 0,  j =(NUM_IN>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeSignal[i] = 0;
	}
	
	for (i = 0,  j =(NUM_IN>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeInput[i] = 0;
	}
	
	for (i = 0,  j =(NUM_OUT>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeOuts[i] = 0;
	}
	for (i = 0,  j =(NUM_LED>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeLeds[i] = 0;
	}
	for (i = 0,  j =(NUM_IN); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> ushDurationDI[i] = 0;
	}
	for (i = 0,  j =(NUM_IN*AMOUNT_BYTE_FOR_IEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_di_rank_cfg[i] = 0;
	}
	for (i = 0,  j =(NUM_KEY*AMOUNT_BYTE_FOR_KEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)->  uc_ar_key_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_OUT*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_do_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_LED*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_led_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_TRG*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_trg_setPl_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_TRG*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_trg_setMn_rank_cfg[i] = 0;
	}
	
	
	for (i = 0,  j =(NUM_TRG*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_trg_rstPl_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_TRG*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_trg_rstMn_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_df1_pl_rank_cfg[i] = 0;
	}
	
	
	for (i = 0,  j =(NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_df1_mn_rank_cfg[i] = 0;
	}
	
	for (i = 0,  j =(NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_df1_blk_rank_cfg[i] = 0;
	}
		
	for (i = 0,  j =(AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_DReccfg[i] = 0;
	}
		
	for (i = 0,  j =(AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_AReccfg[i] = 0;
	}
	
	
	
	
	
	((CfgTblDsc*)pTbl)-> PckpStpm_store_selection = 1;
	//PckpStpmStoreDsc 	arPckpStpmStngStore
	pv1  = (void*) &((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[0];
	
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		pv1  = (void*) &( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i]);
		//.for (j = 0; j< ( sizeof(PckpStpmStoreDsc) );j++)
		//.	((char*)pv1)[j] = 3+i;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage1Dstp1Pickup)     = hldrDstp1PickupMinValStg0_G0;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage1Dstp1StageParam) = hldrDstp1StageParamStore;
		
		
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2Pickup)     = hldrDstp2PickupStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2StageParam) = hldrDstp2StageParamStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2Pickup)     = hldrDstp2PickupStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2StageParam) = hldrDstp2StageParamStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2Pickup)     = hldrDstp2PickupStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2StageParam) = hldrDstp2StageParamStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2Pickup)     = hldrDstp2PickupStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2StageParam) = hldrDstp2StageParamStore;
		( ((PckpStpmStoreDsc*)pv1)-> ownrDstpDriftBlkPp)        = hldrDstpDriftBlkPp;
		( ((PckpStpmStoreDsc*)pv1)-> ownrDstpDriftBlkSp)        = hldrDstpDriftBlkSp;
		    //.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup)=  hldrDrOcp1PickupMinValStg0_G0;
			//.//Define Store Set Param and assign Struct!
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1StageParam) = hldrDrOcp1TmrStageParamMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			//.( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			pv2 = (void*)&( ((PckpStpmStoreDsc*)pv1)->  ownrStage1DrOcp1Pickup);
			( ((PckpStpmStoreDsc*)pv1)->  ownrStage1DrOcp1Pickup)    = hldrDrOcp1PickupMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrOcp1StageParam) = hldrDrOcp1TmrStageParamMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc

			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspPickupStoreDsc    ) =  hldrNspPickupStore;  //NspPickupStoreDsc        
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspStageParamStoreDsc) =  hldrNspStageParamStore;  //NspStageParamStoreDsc  
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspPickupStoreDsc    ) =  hldrNspPickupStore;  //NspPickupStoreDsc        
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspStageParamStoreDsc) =  hldrNspStageParamStore;  //NspStageParamStoreDsc  

			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminPickup     )       =  hldrUminPickupStore; //UminPickupStoreDsc     
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminStageParam )       =  hldrUminStageParamStore; //UminStageParamStoreDsc 
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminPickup     )       =  hldrUminPickupStore; //UminPickupStoreDsc     
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminStageParam )       =  hldrUminStageParamStore; //UminStageParamStoreDsc 

			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxPickup     )       =  hldrUmaxPickupStore; //UmaxPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxStageParam )       =  hldrUmaxStageParamStore ; //UmaxStageParamStoreDsc  
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxPickup     )       =  hldrUmaxPickupStore; //UmaxPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxStageParam )       =  hldrUmaxStageParamStore ; //UmaxStageParamStoreDsc  

			( ((PckpStpmStoreDsc*)pv1)-> ownrRclrPickup     )             =  hldrRclrPickupStore; //RclrPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrRclrStageParam )             =  hldrRclrStageParamStore; //RclrStageParamStoreDsc  

			( ((PckpStpmStoreDsc*)pv1)-> ownrBrfPickup       )            =  hldrBrfPickupStore; //BrfPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrBrfStageParam   )            =  hldrBrfStageParamStore; //BrfStageParamStoreDsc  
			
			

		
	}
	
	((CfgTblDsc*)pTbl)->state_DstpDriftBlk     = 0;
	((CfgTblDsc*)pTbl)->state_FaultU_Dstp      = 0;
	((CfgTblDsc*)pTbl)-> Dstp_T_UI_NCN         = 0;
	((CfgTblDsc*)pTbl)-> Dstp_T_NonSymMode_NCN = 0;
	
	//,,pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1Dstp1Mng);
	//for (j = 0; j< ( sizeof(Dstp1MngStoreDsc) );j++)
	//		((char*)pv1)[j] = 1;
			
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2Dstp2Mng);
	//.for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 1;
	//.		
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3Dstp2Mng);
	//.for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 1;
	//.		
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4Dstp2Mng);
	//.for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 1;
	//.		
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5Dstp2Mng);
	//.for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 1;
			
	((CfgTblDsc*)pTbl)-> state_FaultU_Ocp = 4;
	
	((CfgTblDsc*)pTbl)->state_FaultU_Ocp = 0;
	((CfgTblDsc*)pTbl)->ownrStg1DrOcp1Mng = hldrDrOcp1MngStore;
	
	((CfgTblDsc*)pTbl)->ownrStg2DrOcp2Mng = hldrDrOcpMinVal; 
	((CfgTblDsc*)pTbl)->ownrStg3DrOcp2Mng = hldrDrOcpMinVal; 
	((CfgTblDsc*)pTbl)->ownrStg4DrOcp2Mng = hldrDrOcpMinVal; 
	((CfgTblDsc*)pTbl)->ownrStg5DrOcp2Mng = hldrDrOcpMinVal; 
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1DrOcp1Mng);
	//.for (j = 0; j< ( sizeof(DrOcp1MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 2;
	( ((CfgTblDsc*)pTbl)-> ownrStg1DrOcp1Mng) = hldrDrOcp1MngStore;
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2DrOcp2Mng);
	//.for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 2;
	( ((CfgTblDsc*)pTbl)->  ownrStg2DrOcp2Mng) = hldrDrOcpMinVal;
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3DrOcp2Mng);
	//.for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 2;
	( ((CfgTblDsc*)pTbl)-> ownrStg3DrOcp2Mng) = hldrDrOcpMinVal;
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4DrOcp2Mng);
	//.for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 2;
	( ((CfgTblDsc*)pTbl)-> ownrStg4DrOcp2Mng) = hldrDrOcpMinVal;
	//.pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5DrOcp2Mng);
	//.for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
	//.		((char*)pv1)[j] = 2;
	( ((CfgTblDsc*)pTbl)-> ownrStg5DrOcp2Mng) = hldrDrOcpMinVal;
			
			
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1DrErthMng);
	//for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 3;
	( ((CfgTblDsc*)pTbl)-> ownrStg1DrErthMng) = hldrDrErthMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2DrErthMng);
	//for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 3;
	( ((CfgTblDsc*)pTbl)-> ownrStg2DrErthMng) = hldrDrErthMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3DrErthMng);
	//for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 3;
	( ((CfgTblDsc*)pTbl)-> ownrStg3DrErthMng) = hldrDrErthMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4DrErthMng);
	//for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 3;
	( ((CfgTblDsc*)pTbl)-> ownrStg4DrErthMng) = hldrDrErthMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5DrErthMng);
	//for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 3;
	( ((CfgTblDsc*)pTbl)-> ownrStg5DrErthMng) = hldrDrErthMngStore;
	
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1NspMng);
	//for (j = 0; j< ( sizeof(NspMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 4;
	( ((CfgTblDsc*)pTbl)-> ownrStg1NspMng) = hldrNspMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2NspMng);
	//for (j = 0; j< ( sizeof(NspMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 4;
	( ((CfgTblDsc*)pTbl)-> ownrStg2NspMng) = hldrNspMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1UminMng);
	//for (j = 0; j< ( sizeof(UminMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 5;
	((CfgTblDsc*)pTbl)-> state_SDEV_Phase_Umin = 0;
	( ((CfgTblDsc*)pTbl)-> ownrStg1UminMng) = hldrUminMngStoren;		
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2UminMng);
	//for (j = 0; j< ( sizeof(UminMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 5;
	( ((CfgTblDsc*)pTbl)-> ownrStg2UminMng) =  hldrUminMngStoren;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1UmaxMng);
	//for (j = 0; j< ( sizeof(UmaxMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 7;
	((CfgTblDsc*)pTbl)-> state_SDEV_Phase_Umax = 0;
	( ((CfgTblDsc*)pTbl)-> ownrStg1UmaxMng) =  hldrUmaxMngStore; 
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStgU2maxMng);
	//for (j = 0; j< ( sizeof(UmaxMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 7;
	( ((CfgTblDsc*)pTbl)-> ownrStgU2maxMng) =  hldrUmaxMngStore; 		
			
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrRclrMng);
	//for (j = 0; j< ( sizeof(RclrMngStoreDsc) );j++)
	//		((char*)pv1)[j] = 8;
	( ((CfgTblDsc*)pTbl)-> ownrRclrMng)	 = hldrRclrMngStore;
	
	//,pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrBrfMng);
	//,for (j = 0; j< ( sizeof(BrfMngStoreDsc) );j++)
	//,		((char*)pv1)[j] = 9;
	( ((CfgTblDsc*)pTbl)-> ownrBrfMng) = hldrBrfMngStore;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrBru);
	//for (j = 0; j< ( sizeof(BruDsc ) );j++)
	//		((char*)pv1)[j] = 0;
	( ((CfgTblDsc*)pTbl)-> ownrBru) = hldrBruDsc;
	( ((CfgTblDsc*)pTbl)-> ownrBruMngStore) = hldrBruMngStore;
	( ((CfgTblDsc*)pTbl)-> ownrBruStageParamStore) = hldrBruStageParamStore;
	//,pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrFL);
	//,for (j = 0; j< ( sizeof(FLDsc) );j++)
	//,		((char*)pv1)[j] = 11;
	( ((CfgTblDsc*)pTbl)-> ownrCalcHvpBrOn) =  hldrCalcHvpBrOn;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrCalcHvpBrOn);
	//for (j = 0; j< ( sizeof(CalcHvpBrOnDsc) );j++)
	//		((char*)pv1)[j] = 12;
	
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrCalcPwr);
	//for (j = 0; j< ( sizeof(CalcPwrDsc) );j++)
	//		((char*)pv1)[j] = 13;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOFunc);
	for (j = 0; j< ( sizeof(OFuncDsc) );j++)
			((char*)pv1)[j] = 0;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOTrg);
	for (j = 0; j< ( sizeof(OTrgDsc) );j++)
			((char*)pv1)[j] = 0;
	
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOLgc);
	//for (j = 0; j< ( sizeof(OLgcDsc) );j++)
	//		((char*)pv1)[j] = 0;
	
	for (i = 0,  j =(AMOUNT_BYTE_FOR_CFG_PRT); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchCfgPrt[i] = 0;
	}
	
//	((PrtTblHldDsc*)pTbl)->lCheckSum = 
//	Eval_CS((char*)pTbl,
//	sizeof(PrtTblHldDsc)-sizeof(((PrtTblHldDsc*)pTbl)->lCheckSum));
	

/*	
	((CfgTblDsc*)pTbl)-> arUchTypeSignal;
	arUchTypeInput
	arUchTypeOuts
	arUchTypeLeds
	ushDurationDI
	uc_ar_di_rank_cfg
	uc_ar_do_rank_cfg
	uc_ar_led_rank_cfg
	//;    //
		    pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1StageParam);                               
			//((DrOcp1StageParamStoreDsc *)pv2)-> 
		    //;        //DrOcp2PickupStoreDsc  
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup);
			(( *)pv2)-> 
		    //;    //DrOcp2StageParamStoreDsc 
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2StageParam);
			((  *)pv2)-> 
		    //;        //DrOcp2PickupStoreDsc     
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup);
			((  *)pv2)-> 
		    //;    //DrOcp2StageParamStoreDsc 
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2StageParam);
			((  *)pv2)-> 
		    //;        //     
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup);
			((DrOcp2PickupStoreDsc  *)pv2)-> 
		    //;    // 
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2StageParam);
			((DrOcp2StageParamStoreDsc  *)pv2)-> 
		    //;        //     
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup);
			((DrOcp2PickupStoreDsc  *)pv2)-> 
		    //;    // 
			pv2  = (void*)&( ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2StageParam);
			((DrOcp2StageParamStoreDsc  *)pv2)-> 
	*/
//(PrtTblDsc*)

}

long CheckDstp1PickupStore(void *pv)
{
long lrVal = 0;
if (
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P1_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P1_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P1_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P1_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P2_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P2_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P2_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P2_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P3_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P3_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P3_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P3_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P4_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P4_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P4_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_OF_Dstp1_P4_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P1_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P1_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P1_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P1_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P2_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P2_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P2_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P2_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P3_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P3_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P3_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P3_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P4_R) >300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P4_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P4_X) > 300000) ||
( (((Dstp1PickupStoreDsc*)pv)->Z_MF_Dstp1_P4_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм
if(
( (((Dstp1PickupStoreDsc*)pv)->  Dstp1_Iovp_ov_range) > 100000) ||
( (((Dstp1PickupStoreDsc*)pv)->  Dstp1_Iovp_ov_range) < 2000 )
) lrVal++;
//.ПО I МТЗ ДЗ1
//.	 уставка по току
//.	 1 ед = 1 мA
if(
( (((Dstp1PickupStoreDsc*)pv)->Dstp1_Coef_Compens_IntPhaseCur  )>10) ||
( (((Dstp1PickupStoreDsc*)pv)->Dstp1_Coef_Compens_IntPhaseCur  )<0)
)
lrVal++;

return lrVal;
}

long  CheckDstp1StageParam(void *pv)
{
long lrVal = 0;
if (
( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_OF )>3200)
// ||
//( (long)( ((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_OF )<0) 
)
lrVal++;


if (
( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;

return lrVal;

}
long CheckDrOcp1PickupStore(void *pv)
{
long lrVal = 0;




if(
( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )>90) 
//||
//( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )<0)
)
lrVal++;

if(
( (((DrOcp1PickupStoreDsc*)pv)->  mcp1_s1_Ias_ov_range) > 150000 ) ||
( (((DrOcp1PickupStoreDsc*)pv)->  mcp1_s1_Ias_ov_range) < 500 )
) lrVal++;


if(
( (((DrOcp1PickupStoreDsc*)pv)->mcp1_s2_Iabk_ov_range ) > 150000  ) ||
( (((DrOcp1PickupStoreDsc*)pv)->mcp1_s2_Iabk_ov_range ) < 500 )
) lrVal++;

if(
( (((DrOcp1PickupStoreDsc*)pv)-> mcp1_IstpU_ov_range) > 150000  ) ||
( (((DrOcp1PickupStoreDsc*)pv)-> mcp1_IstpU_ov_range) < 500 )
) lrVal++;

if(
( (((DrOcp1PickupStoreDsc*)pv)->  mcp1_Ustp_ov_range) > 150000  ) ||
( (((DrOcp1PickupStoreDsc*)pv)->  mcp1_Ustp_ov_range) < 500 )
) lrVal++;

if(
( (((DrOcp1PickupStoreDsc*)pv)-> mcp1_I_ov_range) > 150000  ) ||
( (((DrOcp1PickupStoreDsc*)pv)-> mcp1_I_ov_range) < 500 )
) lrVal++;


return lrVal;
}
long  CheckDrOcp1StageParam(void *pv)
{
long lrVal = 0;
if (
( (((DrOcp1StageParamStoreDsc*)pv)-> mcp1_s1_time_stage)>3200)
// ||
//( (long)( ((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_OF )<0) 
)
lrVal++;


if (
( (((DrOcp1StageParamStoreDsc*)pv)-> mcp1_s2_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrOcp1StageParamStoreDsc*)pv)-> mcp1_Ustp_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp1StageParamStoreDsc*)pv)-> mcp1_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;

return lrVal;

}
long CheckDstp2PickupStore(void *pv)
{
long lrVal = 0;
if (
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P1_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P1_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P1_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P1_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P2_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P2_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P2_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P2_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P3_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P3_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P3_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P3_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P4_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P4_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P4_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_OF_Dstp2_P4_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P1_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P1_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P1_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P1_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P2_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P2_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P2_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P2_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P3_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P3_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P3_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P3_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

if (
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P4_R) >300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P4_R) < 50) 
)
lrVal++;//Active
if(
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P4_X) > 300000) ||
( (((Dstp2PickupStoreDsc*)pv)->Z_MF_Dstp2_P4_X) < 50) 

)
lrVal++;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм
if(
( (((Dstp2PickupStoreDsc*)pv)->  Dstp2_Iovp_ov_range) > 100000) ||
( (((Dstp2PickupStoreDsc*)pv)->  Dstp2_Iovp_ov_range) < 2000 )
) lrVal++;
//.ПО I МТЗ ДЗ1
//.	 уставка по току
//.	 1 ед = 1 мA
if(
( (((Dstp2PickupStoreDsc*)pv)->Dstp2_Coef_Compens_IntPhaseCur  )>10) ||
( (((Dstp2PickupStoreDsc*)pv)->Dstp2_Coef_Compens_IntPhaseCur  )<0)
)
lrVal++;

return lrVal;
}

long  CheckDstp2StageParam(void *pv)
{
long lrVal = 0;
if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T_op_aclt )>3200)
// ||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T_op_aclt )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)->Dstp2_OF_T_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T_aclt )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T_tele_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T_tele_aclt )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_OF_T )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T_op_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)->Dstp2_MF_T_op_aclt  )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)->Dstp2_MF_T_aclt  )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T_tele_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T_tele_aclt  )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_MF_T )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_op_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_op_aclt )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_aclt )<0) 
)
lrVal++;


if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_tele_aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T_tele_aclt )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_Ocp_T )<0) 
)
lrVal++;











if (
( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_HWS_Tau_Aclt )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)-> Dstp2_HWS_Tau_Aclt )<0) 
)
lrVal++;

if (
( (((Dstp2StageParamStoreDsc*)pv)->Dstp2_Ocp_HWS_Tau_Aclt  )>3200) 
//||
//( (((Dstp2StageParamStoreDsc*)pv)->Dstp2_Ocp_HWS_Tau_Aclt  )<0) 
)
lrVal++;

return lrVal;
}
long CheckDrOcp2PickupStore(void *pv)
{
long lrVal = 0;




if(
( (((DrOcp2PickupStoreDsc*)pv)->mcp_AngleRotation_linear_voltage  )>90) 
//||
//( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )<0)
)
lrVal++;

if(
( (((DrOcp2PickupStoreDsc*)pv)->  mcp_s1_Ias_ov_range) > 150000 ) ||
( (((DrOcp2PickupStoreDsc*)pv)->  mcp_s1_Ias_ov_range) < 500 )
) lrVal++;


if(
( (((DrOcp2PickupStoreDsc*)pv)->  mcp_s2_Iabk_ov_range) > 150000  ) ||
( (((DrOcp2PickupStoreDsc*)pv)->  mcp_s2_Iabk_ov_range) < 500 )
) lrVal++;

if(
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_IstpU_ov_range) > 150000  ) ||
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_IstpU_ov_range) < 500 )
) lrVal++;

if(
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_Ustp_ov_range ) > 150000  ) ||
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_Ustp_ov_range ) < 500 )
) lrVal++;

if(
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_I_ov_range) > 150000  ) ||
( (((DrOcp2PickupStoreDsc*)pv)-> mcp_I_ov_range) < 500 )
) lrVal++;


return lrVal;
}


long  CheckDrOcp2StageParam(void *pv)
{
long lrVal = 0;

if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Tau_AcltImp)>5000)
// ||
//( (long)( ((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_OF )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_time_stage_Aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_T_op_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_T_tele_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s1_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s1_T_op_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s1_T_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s1_T_tele_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s2_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s2_T_op_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)->mcp_s2_T_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_s2_T_tele_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_time_stage)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_T_op_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)->mcp_Ustp_T_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_T_tele_aclt)>500)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;



return lrVal;

}

long CheckErthPickupStore(void *pv)
{
long lrVal = 0;

if(
( (((DrErthPickupStoreDsc*)pv)->AngleRotation_3I0_Tznp  )>90) 
//||
//( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )<0)
)
lrVal++;

if(
( (((DrErthPickupStoreDsc*)pv)->  ov_range_3Io_Tznp) > 150000 ) ||
( (((DrErthPickupStoreDsc*)pv)->  ov_range_3Io_Tznp) < 250 )
) lrVal++;


if(
( (((DrErthPickupStoreDsc*)pv)->  ov_range_3Uo_Tznp) > 150000  ) ||
( (((DrErthPickupStoreDsc*)pv)->  ov_range_3Uo_Tznp) < 10000 )
) lrVal++;


return lrVal;
}


long  CheckErthStageParam(void *pv)
{
long lrVal = 0;



//`if (
//`( (((DrErthStageParamStoreDsc*)pv)-> mcp_time_stage)>3200)
//`// ||
//`//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
//`)
//`lrVal++;


if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_time_stage_Aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_T_op_aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_T_tele_aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;


if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_time_stage_3I0)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp3I0_time_stage_Aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp3I0_T_op_aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;
if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp3I0_T_tele_aclt)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;


if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_time_stage_3U0)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;


if (
( (((DrErthStageParamStoreDsc*)pv)-> Tznp_Tau_AcltImp)>1000)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
)
lrVal++;

//nnnif (
//nnn( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_T_tele_aclt)>500)
//nnn// ||
//nnn//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
//nnn)
//nnnlrVal++;

return lrVal;

}


long CheckNspPickupStore(void *pv)
{
long lrVal = 0;

if(
( (((NspPickupStoreDsc*)pv)-> AngleRotation_U_Nsmp  )>90) 
//||
//( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )<0)
)
lrVal++;

if(
( (((NspPickupStoreDsc*)pv)->  ov_range_Zop_s_I2) > 50000 ) ||
( (((NspPickupStoreDsc*)pv)->  ov_range_Zop_s_I2) < 250 )
) lrVal++;

if(
( (((NspPickupStoreDsc*)pv)->  ov_range_Zop_s_U2) > 150000 ) ||
( (((NspPickupStoreDsc*)pv)->  ov_range_Zop_s_U2) < 10000 )
) lrVal++;


if(
( (((NspPickupStoreDsc*)pv)-> ov_range_Zop_b_I2) > 50000  ) ||
( (((NspPickupStoreDsc*)pv)-> ov_range_Zop_b_I2) < 250 )
) lrVal++;



if(
( (((NspPickupStoreDsc*)pv)-> ov_range_Zop_b_U2) > 150000  ) ||
( (((NspPickupStoreDsc*)pv)-> ov_range_Zop_b_U2) < 10000 )
) lrVal++;


return lrVal;
}


long  CheckNspStageParam(void *pv)
{
long lrVal = 0;



if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;




if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop_s)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;




if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop_b)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;

//nnnif (
//nnn( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_T_tele_aclt)>500)
//nnn// ||
//nnn//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
//nnn)
//nnnlrVal++;

return lrVal;

}
long CheckUminPickupStore(void *pv)
{
long lrVal = 0;

if(
( (((UminPickupStoreDsc*)pv)-> ov_range_IblkUmin  )>5000) 
||
( (((UminPickupStoreDsc*)pv)->ov_range_IblkUmin  )<250)
)
lrVal++;

if(
( (((UminPickupStoreDsc*)pv)->  ov_range_Umin) > 110000 ) ||
( (((UminPickupStoreDsc*)pv)->  ov_range_Umin) < 25000 )
) lrVal++;



return lrVal;
}
long  CheckUminStageParam(void *pv)
{
long lrVal = 0;



if (
( (((UminStageParamStoreDsc*)pv)->time_stage_Umin)>3200)
 ||
( (((UminStageParamStoreDsc*)pv)-> time_stage_Umin )<10) 
)
lrVal++;


return lrVal;
}
long CheckUmaxPickupStore(void *pv)
{
long lrVal = 0;



if(
( (((UmaxPickupStoreDsc*)pv)->  ov_range_Umax) > 110000 ) ||
( (((UmaxPickupStoreDsc*)pv)->  ov_range_Umax) < 25000 )
) lrVal++;



return lrVal;
}
long  CheckUmaxStageParam(void *pv)
{
long lrVal = 0;



if (
( (((UmaxStageParamStoreDsc*)pv)->time_stage_Umax)>3200)
// ||
//( (((UminStageParamStoreDsc*)pv)->time_stage_Umax )<10) 
)
lrVal++;


return lrVal;
}

long CheckCorrectnesPrtTbl(void* pCfgTbl)
{
 register long i;
 // register unsigned long j;
register void *pv1,*pv2;
volatile long lRes = 0;

i = ((CfgTblDsc*)pCfgTbl)-> PckpStpm_store_selection ;
if (i>3) lRes++;

pv1  = (void*) &((CfgTblDsc*)pCfgTbl)-> arPckpStpmStngStore[0];

for (i = 0; (i < AMOUNT_SERIES_PPSPM_SETTINGS)&&(lRes==0); i++)
	{
		pv1  = (void*) &( ((CfgTblDsc*)pCfgTbl)-> arPckpStpmStngStore[i]);
		//.for (j = 0; j< ( sizeof(PckpStpmStoreDsc) );j++)
		//.	((char*)pv1)[j] = 3+i;
		pv2  = (void*) &( ( ((PckpStpmStoreDsc*)pv1)-> ownrStage1Dstp1Pickup) );//    = hldrDstp1PickupMinValStg0_G0;
		if( CheckDstp1PickupStore( pv2 ) )
		lRes++;  
		  
		if( CheckDstp1StageParam( ((void*) &((PckpStpmStoreDsc*)pv1)-> ownrStage1Dstp1StageParam)))
		lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1Dstp1StageParam) = hldrDstp1StageParamStore;
		
		
		if( CheckDstp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2Pickup)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2Pickup)     = hldrDstp2PickupStore;
		if( CheckDstp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2StageParam)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2StageParam) = hldrDstp2StageParamStore;
		if( CheckDstp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2Pickup)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2Pickup)     = hldrDstp2PickupStore;
		if( CheckDstp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2StageParam)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage3Dstp2StageParam) = hldrDstp2StageParamStore;
		if( CheckDstp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2Pickup)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2Pickup)     = hldrDstp2PickupStore;
		if( CheckDstp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2StageParam)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage4Dstp2StageParam) = hldrDstp2StageParamStore;
		if( CheckDstp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2Pickup)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2Pickup)     = hldrDstp2PickupStore;
		if( CheckDstp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2StageParam)))
		lRes++;//`( ((PckpStpmStoreDsc*)pv1)-> ownrStage5Dstp2StageParam) = hldrDstp2StageParamStore;
		//`( ((PckpStpmStoreDsc*)pv1)-> ownrDstpDriftBlkPp)        = hldrDstpDriftBlkPp;
		//`( ((PckpStpmStoreDsc*)pv1)-> ownrDstpDriftBlkSp)        = hldrDstpDriftBlkSp;
		
		  
			pv2 = (void*)&( ((PckpStpmStoreDsc*)pv1)->  ownrStage1DrOcp1Pickup);
			if( CheckDrOcp1PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)->  ownrStage1DrOcp1Pickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)->  ownrStage1DrOcp1Pickup)    = hldrDrOcp1PickupMinValStg0_G0;
			if( CheckDrOcp1StageParam( (void*) &(((PckpStpmStoreDsc*)pv1)-> ownrStage1DrOcp1StageParam )))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrOcp1StageParam) = hldrDrOcp1TmrStageParamMinValStg0_G0;
			if( CheckDrOcp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrOcp2Pickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			if( CheckDrOcp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2Dstp2StageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			if( CheckDrOcp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2Pickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			if( CheckDrOcp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2StageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			if( CheckDrOcp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2Pickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			if( CheckDrOcp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2StageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			if( CheckDrOcp2PickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2Pickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2Pickup)     = hldrDrOcp2PickupMinValStg0_G0;
			if( CheckDrOcp2StageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2StageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrOcp2StageParam) = hldrDrOcp2TmrStageParamMinValStg0_G0;
			
			if( CheckErthPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			if( CheckErthStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			if( CheckErthPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			if( CheckErthStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			if( CheckErthPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			if( CheckErthStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage3DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			if( CheckErthPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			if( CheckErthStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage4DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc
			if( CheckErthPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthPickup    ) =  hldrDrErthPickupStore; //DrErthPickupStoreDsc    
			if( CheckErthStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage5DrErthStageParam) =  hldrDrErthStageParamStore; //DrErthStageParamStoreDsc

			if( CheckNspPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspPickupStoreDsc )))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspPickupStoreDsc    ) =  hldrNspPickupStore;  //NspPickupStoreDsc        
			if( CheckNspStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspStageParamStoreDsc)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1NspStageParamStoreDsc) =  hldrNspStageParamStore;  //NspStageParamStoreDsc  
			if( CheckNspPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspPickupStoreDsc )))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspPickupStoreDsc    ) =  hldrNspPickupStore;  //NspPickupStoreDsc        
			if( CheckNspStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspStageParamStoreDsc)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2NspStageParamStoreDsc) =  hldrNspStageParamStore;  //NspStageParamStoreDsc  

			if( CheckUminPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminPickup     )       =  hldrUminPickupStore; //UminPickupStoreDsc     
			if( CheckUminStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UminStageParam )       =  hldrUminStageParamStore; //UminStageParamStoreDsc 
			if( CheckUminPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminPickup     )       =  hldrUminPickupStore; //UminPickupStoreDsc     
			if( CheckUminStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UminStageParam )       =  hldrUminStageParamStore; //UminStageParamStoreDsc 

			if( CheckUmaxPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxPickup     )       =  hldrUmaxPickupStore; //UmaxPickupStoreDsc      
			if( CheckUmaxStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage1UmaxStageParam )       =  hldrUmaxStageParamStore ; //UmaxStageParamStoreDsc  
			if( CheckUmaxPickupStore( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxPickup)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxPickup     )       =  hldrUmaxPickupStore; //UmaxPickupStoreDsc      
			if( CheckUmaxStageParam( (void*) &( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxStageParam)))
			lRes++;//( ((PckpStpmStoreDsc*)pv1)-> ownrStage2UmaxStageParam )       =  hldrUmaxStageParamStore ; //UmaxStageParamStoreDsc  

		/*	( ((PckpStpmStoreDsc*)pv1)-> ownrRclrPickup     )             =  hldrRclrPickupStore; //RclrPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrRclrStageParam )             =  hldrRclrStageParamStore; //RclrStageParamStoreDsc  

			( ((PckpStpmStoreDsc*)pv1)-> ownrBrfPickup       )            =  hldrBrfPickupStore; //BrfPickupStoreDsc      
			( ((PckpStpmStoreDsc*)pv1)-> ownrBrfStageParam   )            =  hldrBrfStageParamStore; //BrfStageParamStoreDsc  
			*/
			

		
	}

pv1  = (void*) &( ((CfgTblDsc*)pCfgTbl)-> arPckpStpmStngStore[i]);


	return lRes;
}

long CheckCfgData(void* pCfgTbl)
{

//Call Reading Data From Another Processor and Check Res Whith BS Data
return 0;
}
long ExchangeCfgData(void* pCfgTbl)
{

//Call Send Data On BR
//Call Send Data On BM
//If Send OK Call Read Data From BR
//If Send OK Call Read Data From BM

return 0; 
}


/*
long Check UminPickupStore(void *pv)
{
long lrVal = 0;

if(
( (((UminPickupStoreDsc*)pv)-> ov_range_IblkUmin  )>90) 
//||
//( (((DrOcp1PickupStoreDsc*)pv)->mcp1_AngleRotation_linear_voltage  )<0)
)
lrVal++;

if(
( (((UminPickupStoreDsc*)pv)->  ov_range_Umin) > 50000 ) ||
( (((UminPickupStoreDsc*)pv)->  v_range_Umin) < 250 )
) lrVal++;



return lrVal;
}


long  CheckNspStageParam(void *pv)
{
long lrVal = 0;



if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;




if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop_s)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;




if (
( (((NspStageParamStoreDsc*)pv)-> time_stage_Zop_b)>3200)
// ||
//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_MF )<0) 
)
lrVal++;

//nnnif (
//nnn( (((DrOcp2StageParamStoreDsc*)pv)-> mcp_Ustp_T_tele_aclt)>500)
//nnn// ||
//nnn//( (((Dstp1StageParamStoreDsc*)pv)-> Dstp1_T_Ocp )<0) 
//nnn)
//nnnlrVal++;


}

long CheckRclrPickupStore(void *pv)
{
long lrVal = 0;



if(
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range1) > 140000 ) ||
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range1) < 40000 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range2) > 20000 ) ||
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range2) < 1000 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range3) > 63000 ) ||
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range3) < 18000 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range4) > 9000 ) ||
( (((RclrPickupStoreDsc*)pv)->  Rclr_U_ov_range4) < 450 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaU) > 110000 ) ||
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaU) < 25000 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaPhi) > 110000 ) ||
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaPhi) < 25000 )
) lrVal++;


if(
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaPhi_Dt) > 110000 ) ||
( (((RclrPickupStoreDsc*)pv)->   Rclr_DeltaPhi_Dt) < 25000 )
) lrVal++;



return lrVal;
}
long  CheckUmaxStageParam(void *pv)
{
long lrVal = 0;



if (
( (((UmaxStageParamStoreDsc*)pv)->time_stage_Umax)>3200)
// ||
//( (((UminStageParamStoreDsc*)pv)->time_stage_Umax )<10) 
)
lrVal++;


return lrVal;
}

	*/
	



