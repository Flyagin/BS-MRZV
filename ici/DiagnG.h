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





#endif 
         

