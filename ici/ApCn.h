/*------------------------------------------------------------------------------
* Copyright (c) 2013 - Factory “KyivPrylad”
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
* Processor       : Lpc_3240
* File Name       : AppCn.h
* Description     : support for the AppCn.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ApCn_h
#define ApCn_h

#define START 1
#define EXEC  2
#define TERM  3
//Pointer function return long param void and long
typedef long(*PFL_VL)(void* pv, long lV);
typedef void(*PFV_VL)(void* pv, long lV);
//.#define KEY_MASK ((unsigned long long)0xFFFFFFFFF) //
//Aplication Connect Def Module CPU_CM CPU connect Module
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//...typedef struct tag_KbdU32
//...{
//...	union {
//...
//...			unsigned char      arUch[8];//0  input Data  field
//...			unsigned short     arUsh[4 ];//01 Key1 field
//...			unsigned long int  arUl [2 ];//02 Key2 field 
//...	}UNFKeyField;//UNF-Union Field Bit - Total 64 bit
//...
//...	union {
//...			unsigned long ulReserv;  //0x Reserv fiel for future
//...			
//...	}UNFReserv;//
//...	
//...}KbdUNFldHolderDsc; OCS -Obj Connection State
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define USING_OCS_ONB      0
#define TR_MODE_OCS_ONB    1
#define RV_MODE_OCS_ONB    2
#define RST_OCS_ONB        3

#define STT_START_OCS_ONB  5
#define STT_WORK_OCS_ONB   6
#define STT_STOP_OCS_ONB   7
#define AUX_OCS_ONB        8

#define USING_OCS_MSK      (1<< USING_OCS_ONB    )
#define TR_MODE_OCS_MSK    (1<< TR_MODE_OCS_ONB  )
#define RV_MODE_OCS_MSK    (1<< RV_MODE_OCS_ONB  )
#define STT_START_OCS_MSK  (1<< STT_START_OCS_ONB)
#define STT_WORK_OCS_MSK   (1<< STT_WORK_OCS_ONB )
#define STT_STOP_OCS_MSK   (1<< STT_STOP_OCS_ONB )
#define RST_OCS_MSK        (1<< RST_OCS_ONB      )


#define AUX_OCS_MSK        (1<< AUX_OCS_ONB      )


//Aplication Connect Def Module CPU_CM CPU connect Module
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~   ACPU_CM for BigObject Exeception   ~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_BaseAcpuCMUnitDsc
{


	short shIDObj;
	unsigned short AppObjConState;//12 bit Id Conection 
	//Bits
	//0 - Obj Active
	//1 - 1 - Transmit Mode
	//2 - 1 - Recieve  Mode
	//3 - 1 - Reserv1 Field 
	//4 - 1 - Reserv Field
	//5 - 1 - State Start
	//6 - 1 - State Work
	//7 - 1 - State Stop 
	unsigned long ulRvCount;
	unsigned long ulTrCount;
	unsigned long ulRvTotal;
	unsigned long ulTrTotal;
	unsigned char      *pUchRV;//Base
	unsigned char      *pUchTR;//Base
	////////////////////////////////
	//void* pvQ;//Activator Req
	//void* pvQ;//Activator ExecReq
	//void* pvQ;//Activator answerReq
	//void* pvQ;//Activator changeState
	PFL_VL pf_Init;
	PFL_VL pf_Rst;
	PFL_VL pf_Work;
	PFL_VL pf_ExecCmd;
	
} BaseAcpuCMUnitDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//Aplication Connect Def Module CPU_CM CPU connect Module
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~   ACPU_CM for BigObject  ~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ who must have oun Copy 
typedef struct tag_BigObjCMUnitDsc
{


//	short shIDObj;
	unsigned short AppObjConState;//12 bit Id Conection 
	//Bits
	//0 - Obj Active
	//1 - 1 - Transmit Mode
	//2 - 1 - Recieve  Mode
	//3 - 1 - Reserv1 Field 
	//4 - 1 - Reserv Field
	//5 - 1 - State Start
	//6 - 1 - State Work
	//7 - 1 - State Stop 
//	unsigned long ulRvCount;
//	unsigned long ulTrCount;
//	unsigned long ulRvTotal;
//	unsigned long ulTrTotal;
//	unsigned char      *pUchRV;//Base
//	unsigned char      *pUchTR;//Base
	long lCsAppObj;
	////////////////////////////////
	//void* pvQ;//Activator Req
	//void* pvQ;//Activator ExecReq
	//void* pvQ;//Activator answerReq
	//void* pvQ;//Activator changeState
	//PFL_VL pf_Init;
	//PFL_VL pf_Duplicate;//CopyOriginalObj;
	//PFL_VL pf_DeCompose;//Cut into chunk OriginalObj;
	//PFL_VL pf_Replicate;//Restore chunk of OriginalObj
	//PFL_VL pf_Update;//Final Control and Inform System then Obj Update
	
} BigObjCMUnitDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Digital samples Unit    ~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcSamplesUnitDsc
{

	unsigned char      arUch[40];//0   Data  field

} SrcSamplesUnitDsc;
extern int TestReqTransmitT1;
extern int TestReqReceiveT1;
#define ID_SRC_SAMPLES_UNIT 0x1
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcAPCSUnitDsc
{
	unsigned char      arUch[80];//0   Data  field

}SrcAPCSUnitDsc;
#define ID_SRC_APCS_UNIT 0x2
extern int TestReqTransmitT2;
extern int TestReqReceiveT2;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ACTIVATE_FILL_DATA       1
#define RECIVE_FILL_DATA         2
#define ACTIVATE_TRANSMIT_DATA   3
#define TRANSMIT_FILL_DATA       4
#define FREE_FILL_DATA           5
#define TOTAL_CMD                (FREE_FILL_DATA+1)


#define ACTIVATE_TRANSMIT_RQ_DATA   1
#define TRANSMIT_RQ_DATA            2
#define CONTROL_RV_FILL_DATA        3
#define FREE_RQ_DATA                4


#define TOTAL_CMD                (FREE_FILL_DATA+1)


#define CTR_WAITING_DATA_SAMPLES   1
#define CTR_TRANSMITTING           2
#define CTR_AAA   3
#define VAL_WAITING_DATA_SAMPLES   0x100000
#define VAL_TRANSMITTING           0x100000
#define VAL_AAA                    0x100000

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_TenPerSamplesUnitDsc
{
    
	
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	//long current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT];
	unsigned char arUchExecCmd[8]; //
	unsigned char arUchRvParamCmd[32]; //Additional Input Param If Need
	unsigned long arU32LifeCtr[4];    //Activity Counters

} ProxyTenPerSamplesUnitDsc;
extern int TestReqTransmitTenPerSamples;
extern int TestReqReceiveTenPerSamples;
#define ID_TEN_PERIOD_SAMPLES_UNIT 0x4
extern ProxyTenPerSamplesUnitDsc  holderProxyTenPerSamplesUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_TotMeasUnitDsc
{
    
	
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	//,,extern __TOTAL_MEASUREMENT total_measurement;
	unsigned char arUchExecCmd[8]; //
	unsigned char arUchRvParamCmd[32]; //Additional Input Param If Need
	unsigned long arU32LifeCtr[4];    //Activity Counters

} ProxyTotMeasUnitDsc;
extern int TestReqTransmitTotMeas;
extern int TestReqReceiveTotMeas;
#define ID_TOTAL_MEAS_UNIT 0x5
extern ProxyTotMeasUnitDsc  holderProxyTotMeasUnit;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Data  REQUEST STATE STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct ObjParamDsc_TagIn
{
long size_Obj ;      //Размер считанного массива
void *p_ObjEntity ;//Указатель на начало данных

}ObjParamDsc;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_SettingsUnitDsc
{
    
	
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	ObjParamDsc hldObjParam;
	unsigned char arUchExecCmd[8]; //
	unsigned char arUchRvParamCmd[32]; //Additional Input Param If Need
	unsigned long arU32LifeCtr[4];    //Activity Counters

} ProxySettingsUnitDsc;
extern int TestReqTransmitSettings;
extern int TestReqReceiveSettings;
#define ID_SETTINGS_UNIT 0x7
extern ProxySettingsUnitDsc  holderProxySettingsUnit;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcTest1UnitDsc
{
	unsigned char      arUch[800];//0   Data  field

}SrcTest1UnitDsc;
#define ID_SRC_TEST1_UNIT 0x3
extern int TestReqTransmitT3;
extern int TestReqReceiveT3;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_PrepDecompouseTrEvtDsc
{

	unsigned short IdSelObj;
	//char *pSrc,*pDst;

} PrepDcpTrEvtDsc;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define NUMBER_CANALS_ADC1              3
#define NUMBER_CANALS_ADC2              4
#define NUMBER_CANALS_ADC3              3
#define NUMBER_CANALS_SPI1              (NUMBER_CANALS_ADC1 + NUMBER_CANALS_ADC2)
#define NUMBER_CANALS_SPI2              (NUMBER_CANALS_ADC3)
#define NUMBER_CANALS                   (NUMBER_CANALS_SPI1 + NUMBER_CANALS_SPI2)

#define NUMBER_PERIOD_TRANSMIT           10
#define NUMBER_POINT                     40
typedef struct tag_ArTenPerSamplesUnitDsc
{

	long current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT];
	
} ArTenPerSamplesUnitDsc;
extern char chStateAr10PerData;
extern int TestReqTransmitArTenPerSamples;
extern int TestReqReceiveArTenPerSamples;
#define ID_TEN_PERIOD_SAMPLES_UNIT 0x4
//#define SIZE_OF_AR_TPS (sizeof(current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]))
#define SIZE_OF_AR_TPS_CALC \
((NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT)<<2)
#define SIZE_OF_AR_TPS (sizeof(holderArTenPerSamplesUnit.current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]))

extern ArTenPerSamplesUnitDsc   holderArTenPerSamplesUnit;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_TOTAL_MEASUREMENT 0X1000
#endif 
#ifdef __TYPE_DEFINITION_BS_H
		#define SIZE_TOTAL_MEASUREMENT ( ((sizeof(__TOTAL_MEASUREMENT )>>2)<<2) + 4*(1&&(sizeof(__TOTAL_MEASUREMENT ))&3) )
#endif
typedef struct tag_
{
	union 
	{
	    	char   chArTotMeas [SIZE_TOTAL_MEASUREMENT];
	    	long   lArTotMeas  [SIZE_TOTAL_MEASUREMENT>>2];
#ifdef __TYPE_DEFINITION_BS_H
			__TOTAL_MEASUREMENT total_measurement;
#endif
            
	}UNTotMeas;
	
}TotMeasHldDsc;
extern long lSizeOf_total_measurement;
//extern TotMeasStructholder holderTotMeas;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
extern int AppReqReceiveTotMeasG;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ID_TOTAL_MEASG_UNIT 0x6
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_SETTINGS_UNN 0X100
#endif 
#ifdef __TYPE_DEFINITION_BS_H
#define SIZE_SETTINGS_UNN ( ((sizeof(__SETTINGS )>>2)<<2) + 4*(1&&(sizeof(__SETTINGS ))&3) )
#endif
typedef struct tag_SettingsHldDsc
{
	union 
	{
	    	char   chArSettings  [ SIZE_SETTINGS_UNN];
	    	long    lArSettings  [ SIZE_SETTINGS_UNN>>2];
#ifdef __TYPE_DEFINITION_BS_H
			__SETTINGS current_settings ;
#endif
            
	}UNSettings;
	long lCheckSum;
}SettingsHldDsc;
extern SettingsHldDsc holderSettings;
extern long lSizeOf_Settings;
#define SIZE_SETTINGS_ICI sizeof(SettingsHldDsc )
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_YUST 0X100
#endif 
#ifdef __TYPE_DEFINITION_BS_H
#define SIZE_YUST (NUMBER_CANALS<<2)
//( ((sizeof(__YUST )>>2)<<2) + 4*(1&&(sizeof(__YUST ))&3) )
#endif
typedef struct tag_YustHldDsc
{
	union 
	{
	    	char   chArYUST  [ SIZE_YUST];
	    	long    lArYUST  [ SIZE_YUST>>2];

#ifdef 	__TYPE_DEFINITION_BS_H
			unsigned int ustuvannja_BS[NUMBER_CANALS];
#else			
			unsigned int ustuvannja_BS[SIZE_YUST>>2];
#endif
            
	}UNYust;
	long lCheckSum;
}YustHldDsc;
extern long lSizeOf_Yust;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_SETTING_PR_MNG 0X10
#define ID_SETTING_PR_TRANSPORT 0X11
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_YUST_PR_MNG 0X12
#define ID_YUST_PR_TRANSPORT 0X13
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_APCS_UNIT  0x14
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_PRT_PR_MNG 0X15
#define ID_PRT_PR_TRANSPORT 0X16

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_GOOS_A_UNIT  0x17
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_GOOS_B_UNIT  0x18
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_TELE_MECHS_UNIT  0x19
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_FCOIL_UNIT  0x1A
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DATE_TIME_UNIT  0x1B
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_ATR_CMD_UNIT  0x1C
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BM_UNIT  0x1D
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BR_UNIT  0x1E
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BS_UNIT  0x1F
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BM_UNIT  0x20
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BR_UNIT  0x21
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BS_UNIT  0x22
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_AUX_STNG_UNIT  0x23
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_UNN_ABS_NUMERTRS_UNIT  0x24
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_ANL_RECORD_UNIT  0x25
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_MAIN_ANL_RECORD_UNIT  0x26
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_COPY_MEAS_STNG_UNIT  0x27
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""







//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


extern void ProcessTransmitEvt(void);
extern void ProcessReceiveEvt(void);
extern void UpdateAppData(void);
extern void Ici10msRing(void);



extern long SelectObj(void);
extern long PrepareDecompouseTrEvt(long lIdObj);

void PrepDecompouseSrcSamplesUnit(void);
void PrepDecompouseSrcSamplesUnitHSU2(void);
void PrepDecompouse10PeriodUnitHSU2(void);
void PrepDecompouseTotMeasUnitHSU2(void);
void PrepDecompouseSettingsUnitHSU2(void);
void PrepDecompouseSettingsPrMngHSU2(void);
void PrepDecompouseStngTptUnitHSU2(void);
void PrepDecompouseYustTptUnitHSU2(void);
void PrepDecompouseYustPrMngHSU2(void);
void PrepDecompousePrtTblPrMngSpi(void);
void PrepDecompousePrtTblTptUnitSpi(void);
void PrepDecompouseGoosBUnitSpi(void);
void PrepDecompouseSrcSamplesUnitHSU0(void);
void PrepDecompouseFCoilUnitSpi(void);
void PrepDecompouseDateTimeUnitSpi(void);
void PrepDecompouseAtrCmdUnitSpi(void);
 void PrepDecompouseAbsNumeratorsUnitSPI(void); 
void PrepDecompouseDiagnUnitSPI(void) ;
void PrepDecompouseAtrCmdUnitSpiSecure(void);

void PrepDecompouseSrcTest1Unit(void);
//void PrepDecompouse Unit(void)
extern long ActivateRVProxyTenPerSamplesCTpuUnit(void* pvLDC, long lID);
extern long ActivateTRProxyTenPerSamplesCTpuUnit(void* pvLDC, long lID);
extern void TenPerSamplesRvServCTpuApCnUnit(void);
extern void TotMeasRvServCTpuApCnUnit(void);
extern void TotMeasGRvServCTpuApCnUnit(void);

long ActivateTRProxyTotMeasCTpuUnit(void* pvLDC, long lID);
long ActivateRVProxyTotMeasCTpuUnit(void* pvLDC, long lID);

long ActivateTRProxySettingsCTpuUnit(void* pvLDC, long lID);
long ActivateRVProxySettingsCTpuUnit(void* pvLDC, long lID);


extern void ExecProxy(void);
extern void UpdateAppData(void);

extern long InitProxyTenPerSamples (void* pv, long lV);
extern long WorkProxyTenPerSamples (void* pv, long lV);
extern long ResetProxyTenPerSamples (void* pv, long lV);
extern long ExecCmdProxyTenPerSamples (void* pv, long lV);

extern long InitProxyTotMeas (void* pv, long lV);
extern long WorkProxyTotMeas (void* pv, long lV);
extern long ResetProxyTotMeas (void* pv, long lV);
extern long ExecCmdProxyTotMeas (void* pv, long lV);

extern long InitProxySettings (void* pv, long lV);
extern long WorkProxySettings (void* pv, long lV);
extern long ResetProxySettings (void* pv, long lV);
extern long ExecCmdProxySettings (void* pv, long lV);

extern long InitProxyYust (void* pv, long lV);
extern long WorkProxyYust (void* pv, long lV);
extern long ResetProxyYust (void* pv, long lV);
extern long ExecCmdProxyYust (void* pv, long lV);
extern void RefreshCfgTables(void);

extern long lBlockHSU2Ctr;
extern void HSU2StallHundler(void);

extern void TeleMechsRvServCTpuApCnUnit(void);
extern int AppReqReceiveTeleMechs ;
extern void TestCopyTeleMechsData(void);

extern void DiagnProcess100msEvt(void);
extern void ProcessTransmitStubSeqSpi(void);

#endif /* ApCn_h */
