#ifndef DIAGNOSTICS_h
#define DIAGNOSTICS_h
#include "../inc/diagBsEn.h"
#include "../inc/diagBmEn.h"
#include "../inc/diagBrEn.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//==================================================================================
//--- 			 INTERNAL  diagnostik  CONSTANT BIT     -----------
//==================================================================================
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~   diagBmEn En -enumms not English        ~~
//~~~           ~~ 
//~~~           ~~
//~~~           ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct RamErrRec_TAG 
{
	unsigned long ulCheck_0_FEBF;//0  Fix Error Bit Field
	unsigned long ulCheck_1_FEBF;//01 
	//unsigned long ul__2_FEBF;//02 
	//unsigned long ulRes___3_FEBF;//03 
	union 
	    {
	    	unsigned char uchStateSDFE;//1<<0 -BIT-Fault Error 1<<1-Diagnostic Error
			unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;//Bound Word
	    }UNNStateSDFE;
	//

	
}RamErrEvtDsc;

extern RamErrEvtDsc hldrErrEvt;
extern char chGErorLedInfo;


#ifndef VER_INFO_h
#define VER_INFO_h
typedef struct tag_NumVerInfo{
char ver;//Main Number
char sub_ver;//Describe functionality change  z TU abo bez TU
char corr_num;//Nomer correkcii Vupravlennya pomulok
long Bield_num;//Compile Counter
}NumVerInfo ;


typedef struct TotVerInfoDsc_TagIn
{

    char ArDateStr [16];      //
    char ArTimeStr [16];      //
	char chSizeDateStr;       //
    char chSizeTimeStr;       //
	short sh;
	long long llIarVersion;  //
    NumVerInfo mVerInfo;


}TotVerInfo;
#endif 


///////////////////////DEFINE////////////////////////////////////////

#define SIZE_DIAGN_FIELD ( sizeof(BmRamPrgEvtDsc ) \
+ sizeof(BrRamPrgEvtDsc ) + sizeof(BsRamPrgEvtDsc) )


typedef union 
{
#ifndef DIAGNOSTICS_h	    	
//			char   chArSDFE [SIZE_DIAGN_FIELD];
//	    	long   lArSDFE  [SIZE_DIAGN_FIELD>>2];
#else
			char   chArRamPrgEvt [SIZE_DIAGN_FIELD];
	    	long    lArRamPrgEvt [SIZE_DIAGN_FIELD>>2];
#endif 			
#ifdef DIAGNOSTICS_h
			//Obj xxx_
			struct
			{
				BmRamPrgEvtDsc hldrPrgEvtBm;
				BrRamPrgEvtDsc hldrPrgEvtBr; 
				BsRamPrgEvtDsc hldrPrgEvtBs;
			}RamPrgEvtFld;	
#else			
			;
			
#endif
            
}UNN_PrgEvtBmBrBs;

typedef struct PrgEvtRecord_T1_tag
{
UNN_PrgEvtBmBrBs hld_UNN_PrgEvt;
//long lTimeLabSysU32;
//long lCompresDataTime;
unsigned char BCDdt[8]; 
}PrgEvtRecord_T1_Dsc;


extern char charPrgEvtRecordWasRead;
extern char ch_arRcdT1_WrBuf_WR_fill;
extern char ch_arRcdT1_WrBuf_WR_get; 
extern char ch_arRcdT1_WrBuf_WR_size; 

#define AMOUNT_PRG_EVT_RECORD 100
extern PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD];
extern PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1_WrBuf[AMOUNT_PRG_EVT_RECORD];
extern PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1_RdBuf[1];
//extern long lCheckSum_arPrgEvt;

typedef struct PrgEvtDFlService_Dsc_TAG 
{

//PrgEvtRecord_T1_Dsc pPrgEvtRecord_T1;
char chPrgEvtRcdT1_WR_fill;
char chPrgEvtRcdT1_WR_get; 
char chPrgEvtRcdT1_WR_size;  

char chPrgEvtRcdT1_RD_fill; 
char chPrgEvtRcdT1_RD_get;  
char chPrgEvtRcdT1_RD_size;  
char chNumberPrgEvtRecord_T1;


unsigned long ulCheckSum_arPrgEvt;
//void *p

}PrgEvtDFlServ_Dsc;

extern PrgEvtDFlServ_Dsc hldPrgEvtDFlServ;

extern char chbsPrgEvtRecord_T1_Buf_State;
#define BS_PRG_EVT_RCD_USED_ONB         (1)
//-Бит указывающий что ресурс занят и меняется
#define BS_PRG_EVT_RCD_ICI_MF_ONB       (2)
//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
#define BS_WR_END_PRG_EVT_RCD_ONB       (3)
//-Бит указывающий что ресурс был XX системой обслуживания 
#define BS_RD_END_PRG_EVT_RCD_ONB       (4)
//-Бит указывающий что ресурс был XX системой обслуживания 
//PRG_EVT_RCD -- PRG _ EVT _RECORD    about RCD
#define BS_PRG_EVT_RCD_WR_ONB       (5)
//-Бит запроса на запись к  системе обслуживания ICI
#define BS_PRG_EVT_RCD_RD_ONB       (6)
//--Бит запроса на чтение к  системе обслуживания ICI


#define BS_PRG_EVT_RCD_USED_MSK     (1<< BS_PRG_EVT_RCD_USED_ONB  )
//#define BS_PRG_EVT_RCD_ICI_MF_MSK   (1<< BS_PRG_EVT_RCD_ICI_MF_ONB)
#define BS_WR_END_PRG_EVT_RCD__MSK        (1<< BS_WR_END_PRG_EVT_RCD_ONB  )
#define BS_RD_END_PRG_EVT_RCD__MSK        (1<< BS_RD_END_PRG_EVT_RCD_ONB  )
#define BS_PRG_EVT_RCD_WR_MSK       (1<< BS_PRG_EVT_RCD_WR_ONB     )
#define BS_PRG_EVT_RCD_RD_MSK       (1<< BS_PRG_EVT_RCD_RD_ONB     )



typedef struct PrgEvtFlash_2_Dsc_TAG             // <-to EEPROM
{
	UNN_PrgEvtBmBrBs hldFixUNN_PrgEvt;//Previous   
//	UNN_PrgEvtBmBrBs hldUNN_PrgEvt;//Current       <-
	unsigned char	chAmountRecords;//Register AmountRecords
	unsigned char	uchIdxWrRecord;//index Wr Rec
	unsigned long ulCheckSum_arPrgEvt;

	
	//-unsigned char	arErrorEvents[50*( sizeof(long)+2*sizeof(char) )]; 
	unsigned long	ulCheckSum;                   //<-to EEPROM
}PrgEvtFlash_2_Dsc;
extern PrgEvtFlash_2_Dsc   hPrgEvtMangInfo;
extern UNN_PrgEvtBmBrBs hldUNN_PrgEvt;

extern void DiagnProcess100msEvt(void);

#ifndef ApCn_h
typedef long(*PFL_VL)(void* pv, long lV);
typedef void(*PFV_VL)(void* pv, long lV);
#endif

typedef struct DFlParam_Dsc_TAG       
{
	short 			shRes;
	short 			shAmtServData; //number_bytes_read_write_dr
	unsigned long	ulAddrServData;//address_read_write_dr;
	void 			*pDRBuf;       //buffer_serial_DataFlash_read_write_dr <- Base Buf
	    
}DFlParam_Dsc;

#define BS_RCD_USED_ONB              (1)
#define BS_EXEC_NOW_RCD_ONB          (2)
#define BS_END_EXCH_RCD_ONB          (3)

typedef struct tag_StateExchInfo{
short state;//
short shStartNum;//Describe 
short shAmount;  //Nomer 
short shCurrExchNum;//
short shIdxExchNum;
void  *pDRBuf;
}StateExchInfo ;


typedef struct tag_QueueEU   //ExecUnit
{
struct tag_QueueEU* pNext;
struct tag_QueueEU* pPrev;
PFV_VL pfv_vl;

}QueueEU;

extern QueueEU arQueueEU[8];



extern StateExchInfo hldrRdPrgEvtInfo;
extern StateExchInfo hldrWrPrgEvtInfo;

extern long ReadPrgEvtBmBrBs(void);
extern long WritePrgEvtBmBrBs(void);


extern void FindException(void);
extern long DetectException(void *pFixPrgEvt, void *pCurrPrgEvt);
extern void PutException(void);
extern void ClearPrgEvtMangInfo(void);

extern  void CheckU2State(void);

extern unsigned char rtc_time[8]; 
extern unsigned char rtc_time_copy[8];
extern unsigned int copying_time;









#endif 
         

