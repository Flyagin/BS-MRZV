/*------------------------------------------------------------------------------
* Created (c) 2013 - Factory “KyivPrylad”
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
* Processor       : at91sam9g45
* File Name       : verInfo.c
* Description     : Functions and Data for Low Level Program description,
                    BR BS BM

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  17/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
//Description
//A string that identifies the date of compilation, which is returned in the form "Mmm dd yyyy", for example "Oct 30 2014"
//This symbol is required by Standard C.


#include <intrinsics.h>
#include <string.h>
#include <time.h>
#include    "DiagnG.h"
#include    "../inc/hs_ver.h"
#include    "dgn_vr.h"


#define VERSION         1

#define SUB_VERSION     0
#define AUX_NUM         0


__root const char arDateCompilation [] = {
__DATE__


};
//A string that identifies the time of compilation in the form "hh:mm:ss".

__root const char arTimeCompilation [] = {
__TIME__


};
//An integer that identifies the version number of the IAR compiler in use. For example, version 5.11.3 is returned as 5011003.

__root const long long llIarVersion = {
__VER__


};
//A string that identifies the name of the base source file (that is, not the header file), being compiled. 

__root const char arBaseFile [] = {
__BASE_FILE__


};
//A unique integer that identifies the build number of the compiler currently in use. 

__root  const long long llBuidNumber = {
__BUILD_NUMBER__


};

typedef struct tag_version{
char ver;//Main Number
char sub_ver;//Describe functionality change  z TU abo bez TU
char corr_num;//Nomer correkcii Vupravlennya pomulok
long Bield_num;//Compile Counter
}VerInfo ;

__root const VerInfo hlVerInfo = {
VERSION,
AUX_NUM,
SUB_VERSION,
BIELD_NUMBER 

};



RamErrEvtDsc hldrErrEvt;


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void ProcessProgramEvt(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void ProcessProgramEvt(void) @ "Fast_function"
{
  long register j,k;// i,
  register void *pv;
	//Check Time Corectness
	
	//PutExecpt((void*)&SResTestHldr,(void*)&EepromErrRecDesc); <-Insert Data In Logger
	k = 0;//Fix Fatal Error
	pv = (void*)&hldrErrEvt;
	//Check each bit in Test Conf
	
//	j = *((U8*)i+SETNGS_ERR_START_VIA_I2C_CHK_IDX_U8);
//       if(j& SETNGS_ERR_START_VIA_I2C_CHK_U8_MSK)
//	k++;
// ERROR_BM_VREF_ADC1_TEST_BIT                      
	// 
//	j = *( (char*)pv + ( TO_IDX_U8(ERROR_BM_VREF_ADC1_TEST_BIT) )   );
//	if (j& ( TO_U8_MSK(ERROR_BM_VREF_ADC1_TEST_BIT)) )
//	k++;//Fix Fatal Error
//	
//	// ERROR_BM_VDD_ADC1_TEST_BIT  
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VDD_ADC1_TEST_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VDD_ADC1_TEST_BIT)) )
//	k++;//Fix Fatal Error
//	// ERROR_BM_VREF_ADC1_TEST_COARSE_BIT               
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VREF_ADC1_TEST_COARSE_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VREF_ADC1_TEST_COARSE_BIT)) )
//	k++;//Fix Fatal Error
//	// ERROR_BM_VDD_ADC1_TEST_COARSE_BIT                
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VDD_ADC1_TEST_COARSE_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VDD_ADC1_TEST_COARSE_BIT)) )
//	k++;//Fix Fatal Error
	//                                                  
	// ERROR_BM_VREF_ADC2_TEST_BIT                      
	// ERROR_BM_VDD_ADC2_TEST_BIT                       
	// ERROR_BM_VREF_ADC2_TEST_COARSE_BIT               
	// ERROR_BM_VDD_ADC2_TEST_COARSE_BIT                
	//                                                  
	// ERROR_BM_VREF_ADC3_TEST_BIT                      
	// ERROR_BM_VDD_ADC3_TEST_BIT                       
	// ERROR_BM_VREF_ADC3_TEST_COARSE_BIT               
	// ERROR_BM_VDD_ADC3_TEST_COARSE_BIT                
	//                                                  
	// ERROR_BM_EXTERNAL_SRAM_BIT                       
	// ERROR_BM_EXTERNAL_FLASH_MEMORY_BIT               
	//                                                  
	// ERROR_BM_START_VIA_I2C_BIT                       
	// ERROR_BM_START_READING_I2C_BIT                   
	// ERROR_BM_SETTINGS_EEPROM_BIT                     
	// ERROR_BM_SETTINGS_EEPROM_EMPTY_BIT               
	// ERROR_BM_SETTINGS_EEPROM_COMPARISON_BIT          
	// ERROR_BM_SETTINGS_EEPROM_CONTROL_BIT             
	// ERROR_BM_SETTINGS_EEPROM_DEVICE_ID_FAIL_BIT      
	// ERROR_BM_USTUVANNJA_EEPROM_BIT                   
	// ERROR_BM_USTUVANNJA_EEPROM_EMPTY_BIT             
	// ERROR_BM_USTUVANNJA_EEPROM_COMPARISON_BIT        
	// ERROR_BM_USTUVANNJA_EEPROM_CONTROL_BIT           
	// ERROR_BM_USTUVANNJA_EEPROM_ADJUSTMENT_ID_FAIL_BIT
	// ERROR_BM_POWER_EEPROM_BIT                        
	// ERROR_BM_POWER_EEPROM_EMPTY_BIT                  
	// ERROR_BM_POWER_EEPROM_COMPARISON_BIT             
	// ERROR_BM_POWER_EEPROM_CONTROL_BIT 
	if(k) 
	{
		//---*((U8*)pvCMD32+FAULT_TEST_CMDF_IDX_U8)  |= (FAULT_TEST_CMDF_U8_MSK);
		((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE |= 1;//Fix Fatal Error
	}
	else
	{
		((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE &= ~1;////Fix Fatal Error
	}
	k = 0;
	j = ((RamErrEvtDsc*)pv)->ulCheck_0_FEBF;
		if(j) k++;
		j=  ((RamErrEvtDsc*)pv)->ulCheck_1_FEBF;
		if(j) k++;
	if(k) 
		{
			//---
			((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE |= 2;//Fix Diagnostic Error
		}
		else
		{
			((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE &= ~2;////Fix Diagnostic Error
		}	
	
}
//---------------------------------------------------------------------------------

int AppReqTransmitDiagnBsBr;

DiadnHldDsc holderDiagnBsBr = {
{0,0,0}

};

void ActivateServTrApCnDiagnCTpuUnitSPI(void)   @ "Fast_function"
{

register void* pv;

holderDiagnBsBr.UNN_Sdfe.muPrgEvtBmBrBs = hPrgEvtMangInfo.hldFixUNN_PrgEvt;
  //Reset Connect State
   pv  = (void*)& (holderTRDiagnBsBrSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_DIAGN_BS_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = SIZE_DIAGN_FIELD;//SIZE_DIAGN
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_DIAGN_BS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderDiagnBsBr.UNN_Sdfe.chArSDFE[0]; //
   
}

void TerminateServiceApCnDiagn(void)   @ "Fast_function"
{

   
}
//Pr
void PrepDecompouseDiagnUnitSPI(void)   @ "Fast_function"
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
	//Process
	if(AppReqTransmitDiagnBsBr)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_DIAGN_FIELD;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitDiagnBsBr==START)
			{
				ActivateServTrApCnDiagnCTpuUnitSPI();
				AppReqTransmitDiagnBsBr = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitDiagnBsBr==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRDiagnBsBrSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitDiagnBsBr = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitDiagnBsBr==TERM)
				{
					TerminateServiceApCnDiagn();
					AppReqTransmitDiagnBsBr = 0;
				}
			}
		}
		//Try another???
		
	}
	

}



int AppReqReceiveDiagnBmBs;
int AppReqReceiveDiagnBrBs;

DiadnHldDsc holderDiagnBmBs = {
{0,0,0}

};
DiadnHldDsc holderDiagnBrBs = {
{0,0,0}

};



long UpdateRVDiagnBmBsTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVDiagnBsBmSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderDiagnBmBs.UNN_Sdfe.chArSDFE[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveDiagnBmBs++; 
}


return lID;//unnV1.uchAr[3];
}

long UpdateRVDiagnBrBsTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVDiagnBsBrSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderDiagnBrBs.UNN_Sdfe.chArSDFE[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveDiagnBrBs++; 
}








return lID;//unnV1.uchAr[3];
}

TotVerInfoHldDsc hldTotVerInfoBm;

 int AppReqReceiveTotVerInfoBmBs;

TotVerInfoHldDsc hldTotVerInfoBr;

 int AppReqReceiveTotVerInfoBrBs;


long UpdateRVTotVerInfoBmTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&hldTotVerInfoBm.UNN_TotVerInfo.chArVerI[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveTotVerInfoBmBs++; 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		(unsigned char*)&holderRVTotVerInfoBmSOCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_VER_INFO))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_VER_INFO) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_VER_INFO))
			{
				//. pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				//. i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_VER_INFO))
				{
					//Activate App Func
					AppReqReceiveTotVerInfoBmBs++;
					//~i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					//~((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					hldTotVerInfoBm.UNN_TotVerInfo.mTotVerInfo = *((TotVerInfo*)(holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr.pUchRV));
			
					  
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
						//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
						//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			//. pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVTotVerInfoBmSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}
long UpdateRVTotVerInfoBrTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&hldTotVerInfoBr.UNN_TotVerInfo.chArVerI[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveTotVerInfoBrBs++; 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		(unsigned char*)&holderRVTotVerInfoBrSOCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_VER_INFO))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_VER_INFO) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_VER_INFO))
			{
				//. pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				//. i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_VER_INFO))
				{
					//Activate App Func
					AppReqReceiveTotVerInfoBrBs++;
					//~i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					//~((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo = *((TotVerInfo*)(holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr.pUchRV));
			
					  
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
						//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
						//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			//. pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			//.i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
			//.((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVTotVerInfoBrSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


TotVerInfoHldDsc hldTotVerInfoBs;

extern long SetupReadPrgEvtBmBrBs(long lNum, long lAmtPrgEvtUNN,void *pv);
extern long ReadPrgEvtBmBrBs(void);
extern char charPrgEvtRecordWasRead;
void StartUPInitTotVerInfo(void)
{
//register long i;
register void* pv;
   
   hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.chSizeDateStr = strlen(arDateCompilation);
   //((TotVerInfo*)pv)->chSizeDateStr = strlen(arDateCompilation);
   strncpy(hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.ArDateStr, arDateCompilation,16);
   
   hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.chSizeTimeStr = strlen(arTimeCompilation );
   
   strncpy(hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.ArTimeStr,arTimeCompilation,16);
   
   hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.llIarVersion = llIarVersion;
   //
   pv  = (void*)&hlVerInfo; //hldTotVerInfoBm.UNN_TotVerInfo.mTotVerInfo;
   hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo.mVerInfo = *((NumVerInfo*)pv);

   SetupReadPrgEvtBmBrBs(0,AMOUNT_PRG_EVT_RECORD,(void*)arPrgEvtRecord_T1_WrBuf);
   ReadPrgEvtBmBrBs();
   charPrgEvtRecordWasRead = 1;
}


__root TotVerInfo *pTotVerInfoBm = &hldTotVerInfoBm.UNN_TotVerInfo.mTotVerInfo ;
__root TotVerInfo *pTotVerInfoBs = &hldTotVerInfoBs.UNN_TotVerInfo.mTotVerInfo ;
__root TotVerInfo *pTotVerInfoBr = &hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo ;
PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD] @ "DDR2_Bank1_2_variables";
PrgEvtFlash_2_Dsc   hPrgEvtMangInfo  @ "DDR2_Bank1_2_variables";

#include "DiagnG.c"






/* EOF */

