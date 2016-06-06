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
* Processor       : at91sam9g45
* File Name       : MnPrStng.h
* Description     :  support for the MnPrStng.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef MNR_PR_STNG_h
#define MNR_PR_STNG_h
//Common Command for detect State Proxy partner
#define CMD_REQ_REMOUT_RST          1
#define CMD_REQ_CUR_TASK_PHASE		CMD_REQ_REMOUT_RST     +1
#define CMD_REQ_SELECT_TASK_PHASE   CMD_REQ_CUR_TASK_PHASE +1

// //Command for Requst Exec T1
#define CMD_REQ_T1_TR_DATA          CMD_REQ_SELECT_TASK_PHASE  +1
#define CMD_REQ_T1_TANSPORT_RESULT  CMD_REQ_T1_TR_DATA         +1
#define CMD_REQ_T1_GET_STATE_PHASE  CMD_REQ_T1_TANSPORT_RESULT +1
//Load in Esec array for select type Task for Exec
#define TASK_TR_DATA_T1             1
#define TASK_REQ_REMOUTE_WR_EEPROM   TASK_TR_DATA_T1           	 +1
#define TASK_REQ_REMOUTE_CMP_TABLE   TASK_REQ_REMOUTE_WR_EEPROM  +1
#define TASK_REQ_SEND_DATA_T1        TASK_REQ_REMOUTE_CMP_TABLE  +1
//#define TASK_
//#define TASK

//Phases TASK_TR_DATA_T1
//Send Cmd CMD_REQ_SELECT_TASK_TR_DATA_T1
//Wait answer Ready Receive Data CMD_REQ_SELECT_TASK_TR_DATA_T1RDY_RV_DATA_TASK_TR_DATA_T1 echo CMD_REQ_SELECT_TASK_TR_DATA_T1
//Send Cmd CMD_REQ_GET_RESULT oK or Error
//Wait answer CMD_ANSW_T1_TRANSPORT_RESULT echo CMD_REQ_T1_RESULT
//
#define T1_PHASE_REQ_TR_DATA                              10
#define T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1                T1_PHASE_REQ_TR_DATA                 +1
#define T1_PHASE_REQ_T1_TANSPORT_RESULT                    T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1 +1
#define T1_PHASE_WAIT_ANSW_T1_TRANSPORT_RESULT             T1_PHASE_REQ_T1_TANSPORT_RESULT     +1

#define T1_PHASE_OVERRUN_LIMIT_INIT_T1_PHASE_REQ_TR_DATA  2
#define T1_PHASE_OVERRUN_LIMIT_INIT                         T1_PHASE_OVERRUN_LIMIT_INIT_T1_PHASE_REQ_TR_DATA +1


//Order Selectors
#define ORD_SEL_T1_PHASE_REQ_TR_DATA                    1
#define ORD_SEL_T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1      ORD_SEL_T1_PHASE_REQ_TR_DATA                +1
#define ORD_SEL_T1_PHASE_REQ_T1_TANSPORT_RESULT          ORD_SEL_T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1 +1
#define ORD_SEL_T1_PHASE_WAIT_ANSW_T1_TRANSPORT_RESULT   ORD_SEL_T1_PHASE_REQ_T1_TANSPORT_RESULT     +1

#define ANSW_RDY_RV_DATA_TASK_TR_DATA_T1 1 


#ifndef ApCn_h
typedef long(*PFL_VL)(void* pv, long lV);
#endif
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define PM_STT_USING_OCS_ONB      0

//#define RST_OCS_ONB        3 PM - proxy Manager STT state 

#define PM_STT_START_OCS_ONB  2
#define PM_STT_WORK_OCS_ONB   3
#define PM_STT_STOP_OCS_ONB   4
#define PM_STT_ERROR_OCS_ONB  5
#define PM_STT_SUCCESS_OCS_ONB  6

#define PM_STT_USING_OCS_MSK     (1<< PM_STT_USING_OCS_ONB)
#define PM_STT_START_OCS_MSK     (1<< PM_STT_START_OCS_ONB)
#define PM_STT_WORK_OCS_MSK      (1<< PM_STT_WORK_OCS_ONB )
#define PM_STT_STOP_OCS_MSK      (1<< PM_STT_STOP_OCS_ONB )
#define PM_STT_ERROR_OCS_MSK     (1<< PM_STT_ERROR_OCS_ONB)


//#define AUX_OCS_MSK        (1<< AUX_OCS_ONB      )
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                            Proxy Manager                                 ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define MAX_VARIANT 10
#define MAX_CMD     10
typedef struct ProxyMangerState_TagIn
{
short shIDPrMng;
short shPrMngConState;//Describe Obj Self Service
//Connection State 
//0 - Obj Active
//1 - Reserv
//2 - 1 - State Start
//3 - 1 - State Work
//4 - 1 - State Stop 
//5 - 1- Error State
PFL_VL pf_Work;
PFL_VL pf_ExecCmd;
//unsigned char arUchExecCmd[MAX_VARIANT];
unsigned char arUchStateCmd[MAX_CMD];//This is communicate command data
unsigned char arUchCounterChangeStateCmd[MAX_CMD];//counter for prevent DeadLocking
//unsigned char chIdxStateCmd,chSelectorStateCmd;

char chCmdAnswer;//Receive communication command from proxy partner
char chCmdReq;
unsigned long   ulStateProxyManger;//
//b3 - Target b2 -Phase b1- Error Code b0 - bit Flags
unsigned long   ulLifeCtrEct;//

}ProxyMangerStateDsc;

#define EXEC_RECIVE_FILL_DATA         2
#define EXEC_TRANSMIT_FILL_DATA       3
#define EXEC_FREE_FILL_DATA           4
#define EXEC_TOTAL_CMD                (FREE_FILL_DATA+1)

#define CTR_TRANSPORT_WAITING_DATA   1
#define CTR_TRANSPORT_TRANSMITTING   2
#define CTR_TRANSPORT_REPEAT         3
#define VAL_TRANSPORT_WAIT           0x10000
#define VAL_TRANSPORT_TRANSMIT       0x100000
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                            Proxy Manager                                 ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct tag_ProxyTransportStateDsc
{
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	unsigned char arUchExecCmd[4];
	unsigned long arU32LifeCtr[4];
	unsigned char arUchResultExecCmd[4];//Hold result exec command
}ProxyTransportStateDsc;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Data  REQUEST STATE STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef ApCn_h
typedef struct ObjParamDsc_TagIn
{
long size_Obj ;      //Размер считанного массива
void *p_ObjEntity ;//Указатель на начало данных

}ObjParamDsc;
#endif
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Input STATE STRUCTS  ~~~For Transport description
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct ProxyRvInParamDsc_TagIn
{
//void* pRVCTpuUnit;
RVBaseCTpuUnitDsc  *pRvCnHldr;
unsigned char      *arUchRV;//Addr Aux Obj for control correctnes whith pAppObj
//void* pProxyUnit; ;;pProxyUnitDsc;
BaseAcpuCMUnitDsc *pHldrAcpuCMUnitState;//Base Proxy Addr
unsigned long *pLifeCtr_WAITING_DATA;//arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
ObjParamDsc* pAppObj;
//Any additional Param
//short sh
//short sh

}ProxyRvInParamDsc;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  OutPut STATE STRUCTS  ~~~For Transport description
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct ProxyTrParamDsc_TagIn
{
//void* pRVCTpuUnit;
TRBaseCTpuUnitDsc  *pTrCnHldr;
unsigned char      *arUchTR;//
//void* pProxyUnit; ;;pProxyUnitDsc;
BaseAcpuCMUnitDsc *pHldrAcpuCMUnitState;//Base Proxy Addr
unsigned long *pLifeCtr_WAITING_DATA;//arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
ObjParamDsc* pAppObj;
//Any additional Param
//short sh
//short sh

}ProxyTrParamDsc;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    Msg STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

typedef struct CmmMsDsc_TagIn
{
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulAr  [1];
	}UNNHdrMsg;
long size_Obj;     //Размер считанного массива	
void *p_ObjEntity ;//Указатель на начало данных

}CmmMsgDsc;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Data  Settings Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct tag_UnitedProxyUnitDsc
{
    
	
	ProxyMangerStateDsc hldPrMng;
	ObjParamDsc hldObjParam;//Param Input Data from External World
	ProxyRvInParamDsc hldPrTransptRvInParam;
	ProxyTrParamDsc   hldPrTransptTRParam;


} UnitedProxyUnitDsc;
//extern int TestReqTransmitSettings;
//extern int TestReqReceiveSettings;
#define ID_SETTINGS_UNIT 0x7
extern int  ReqTransmitSettingsPrMng;
extern int  ReqReceiveSettingsPrMng;

extern long lPhsLifeCtr;
extern unsigned long ulCtrDecompouseStngTptUnitHSU2;
//extern long lStngOrderNumFragment;
extern long lStngOrderNumTrFragment;
extern long lStngOrderNumRvFragment;



//extern ProxySettingsUnitDsc  holderProxySettingsUnit;
extern ProxyTransportStateDsc hldPrTrptSettings;
extern ProxyMangerStateDsc    hldPrMngSettings;
extern ProxyMangerStateDsc    hldPrMngYust;
extern ProxyTransportStateDsc hldPrTrptYust;


extern int  ReqTransmitStngPrTpt;
extern int  ReqReceiveStngPrTpt;
extern long WorkProxyManager (void* pv, long lV);
extern long ExecTargetProxyManager (void* pv, long lV);

long ExecTgtTrDataT1 (void* pv, long lV);
long ExecT1PhaseReqTrData (void* pv, long lV);

long ExecTgtTrDataT1_1 (void* pv, long lV);
long ExecT1HsPhs1 (void* pv, long lV);
long ExecT1HsPhs2 (void* pv, long lV);
long ExecT1HsPhs3 (void* pv, long lV);
long ExecT1HsPhs4 (void* pv, long lV);
long ExecT1HsPhsWaitCmmMsg(void* pv, long lV);
long DPTgtT1PhsWaitCmmMsg  (void* pv, long lV);


long ResetProxyTransport (void* pv, long lV);
long ActivateTrStngPrTpt(void* pObjParam, long lV);
long ActivateRvStngPrTpt(void* pObjParam, long lV);


long ExecCmdProxyTransport (void* pv, long lV);
long WorkProxyTransport (void* pv, long lV);

extern long ActivatePrMngSettings(void);
extern long ChangeState (void* pv, long lV);
extern long ActivateTRStngPrTpt(void* pObjParam, long lID);

extern long ActivateTransmitStngObj(void);
extern long ActivateTransmitYustObj(void);
extern long ActivateReceiveStngObj(void);
extern long ActivateReceiveYustObj(void);
extern long CreateTRFragment(void* pvTRFrgDsc);


extern SettingsStateDsc testSettigsState;

long TrySetSendStngEct  (void* pv, long lV);
long DpcsPrMngMsg  (void* pv, long lV);
long ExecCmdPrMng (void* pv, long lV);
long SetSendStngEct(void* pv, long lV);
long  WaitCmdHmEct(void* pv, long lV);
long SetSendReqTrStngEct(void* pv, long lV);



long ActivatePrMngSettings(void);
long PassSettingsPrMngRvMsgOrigin(void);
long SendYustTbl(void);
long GetYustTbl (void);

long ReqGetSettingsBMExample(void);  
long ReqSendSettingsBMExample(void); 
long ReqSendYustBMExample(void) ;
long ReqGetYustBMExample(void) ;
extern long ReqSendPrtTblBRExample(void); 
extern long ReqGetPrtTblBRExample (void);
#define ID_EXEC_CMD_PR_MNG_CALL         1
#define ID_UPDATE_RV_PR_TPT_STNG_CALL   2




#define ID__ACTIVATEPRMNGSETTINGS                                  1
#define ID_PASSSETTINGSPRMNGRVMSGORIGIN ID__ACTIVATEPRMNGSETTINGS +1
#define ID__ACTIVATE_TRANSMIT_SETTINGS  ID_PASSSETTINGSPRMNGRVMSGORIGIN +1
#define ID_ACTIVATE_TRANSMIT_YUST       ID__ACTIVATE_TRANSMIT_SETTINGS  +1
#define ID__ACTIVATE_RECEIVE_SETTINGS   ID_ACTIVATE_TRANSMIT_YUST       +1
#define ID__ACTIVATE_RECEIVE_YUST       ID__ACTIVATE_RECEIVE_SETTINGS   +1

#define ID__GET_STNG_TBL                ID__ACTIVATE_RECEIVE_YUST       +1
#define ID__SEND_STNG_TBL               ID__GET_STNG_TBL                +1

#define ID__GET_STNG_TBL_EXAMPLE        ID__SEND_STNG_TBL                 +1
#define ID__SEND_STNG_TBL_EXAMPLE       ID__GET_STNG_TBL_EXAMPLE          +1
#define ID__GET_YUST_TBL_EXAMPLE        ID__SEND_STNG_TBL_EXAMPLE         +1
#define ID__SEND_YUST_TBL_EXAMPLE       ID__GET_YUST_TBL_EXAMPLE          +1
#define ID__GET_PRT_TBL_EXAMPLE         ID__SEND_YUST_TBL_EXAMPLE         +1
#define ID__SEND_PRT_TBL_EXAMPLE        ID__GET_PRT_TBL_EXAMPLE           +1



#define SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1 40

	




#include    "CmmConst.h"
#endif
