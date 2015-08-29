/*------------------------------------------------------------------------------
* 
* 
*------------------------------------------------------------------------------
*
* Processor       : All
* File Name       : CmmConst.h
* Description     : Settings Proxy Const App Definition
                    BS,BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef CMM_CONST_MNR_PR_STNG_h
#define CMM_CONST_MNR_PR_STNG_h

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
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~   Targets(Tasks)  Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//Transmitter
#define TGT_TR_DATA_T1_COBJ_HM_HS                1//Transmit  DATA_T1_COBJ ICI FROM HS ON hm
#define TGT_HM_DATA_T1_COBJ_OOBJ_HM_HS   (TGT_TR_DATA_T1_COBJ_HM_HS      +1) // WR_EEPROM
#define TGT_HM_CMP_DATA_T1_COBJ_OOBJ_HS  (TGT_HM_DATA_T1_COBJ_OOBJ_HM_HS +1)
#define TGT_ICI_RV_DATA_T1_HM_OOBJ_HS    (TGT_HM_CMP_DATA_T1_COBJ_OOBJ_HS+1)
//Receiver
#define TGT_RV_DATA_T1_HS_COBJ_HM        (TGT_ICI_RV_DATA_T1_HM_OOBJ_HS  +1)//cobj -copy object on HM
#define TGT_WR_DATA_T1_COBJ_OOBJ_HM      (TGT_RV_DATA_T1_HS_COBJ_HM      +1)//OOBJ Original Object in EEPROM 
#define TGT_CMP_DATA_T1_COBJ_OOBJ_HM     (TGT_WR_DATA_T1_COBJ_OOBJ_HM    +1)//OOBJ Original Object uses HM EEPROM 
#define TGT_TR_DATA_T1_OOBJ_HS_HM        (TGT_CMP_DATA_T1_COBJ_OOBJ_HM   +1)//
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    PHases Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define TGT_T1_PHS_REQ_TR_DATA                              10
#define TGT_T1_PHS_WAIT_ANSW_RDY_TRANSPORT_T1             +1
#define TGT_T1_PHS_REQ_T1_TANSPORT_RESULT                 +1
#define TGT_T1_PHS_WAIT_ANSW_T1_TRANSPORT_RESULT          +1

//--------------------------------------------------------------------
#define TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS                2//   +1 //RQ_TGT1_TR_DATA
#define TGT_T1_PHS_WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS     (TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS                 +1)
#define TGT_T1_PHS__RQ_TRANSPORT_RESULT_TR__OBJ_HS        (TGT_T1_PHS_WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS     +1)
#define TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS              (TGT_T1_PHS__RQ_TRANSPORT_RESULT_TR__OBJ_HS        +1)
#define TGT_T1_PHS_WAIT_ANSW__TRANSPORT_RESULT_TR__OBJ_HS (TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS              +1)
#define TGT_T1_PHS_WAIT_CMM_MSG                           (TGT_T1_PHS_WAIT_ANSW__TRANSPORT_RESULT_TR__OBJ_HS +1)


#define TGT_T2_PHS_TR__RQ_WRITE_COBJ_OOBJ__HS       (7  +1)
#define TGT_T2_PHS_WAIT_ANSW_CMP_COBJ_OOBJ__HS      (TGT_T2_PHS_TR__RQ_WRITE_COBJ_OOBJ__HS       +1)
#define TGT_T2_PHS__RQ_CMP_COBJ_OOBJ__HS            (TGT_T2_PHS_WAIT_ANSW_CMP_COBJ_OOBJ__HS      +1)

#define TGT_T3_PHS_TR__RQ_RV_STNG_OBJ__HS               (15              +1)
#define TGT_T3_PHS_WAIT_ANSW__RSP_RDY_TR_STNG_OBJ_HS    (TGT_T3_PHS_TR__RQ_RV_STNG_OBJ__HS             +1)
#define TGT_T3_PHS_TR_TRANSPORT_RV_STNG_OBJ_OK_HS       (TGT_T3_PHS_WAIT_ANSW__RSP_RDY_TR_STNG_OBJ_HS  +1)
#define TGT_T3_PHS_TR_TRANSPORT_RV_STNG_OBJ_ERR_HS      (TGT_T3_PHS_TR_TRANSPORT_RV_STNG_OBJ_OK_HS     +1)

//```````````````````````````````````````
#define TGT_T1_HS_PHS_1      TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS            
#define TGT_T1_HS_PHS_2      TGT_T1_PHS_WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS
#define TGT_T1_HS_PHS_3      TGT_T1_PHS__RQ_TRANSPORT_RESULT_TR__OBJ_HS   
#define TGT_T1_HS_PHS_4   TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS 
 

#define TGT_T2_HS_PHS_1      TGT_T2_PHS_TR__RQ_WRITE_COBJ_OOBJ__HS        
#define TGT_T2_HS_PHS_2      TGT_T2_PHS_WAIT_ANSW_CMP_COBJ_OOBJ__HS       
#define TGT_T2_HS_PHS_3      TGT_T2_PHS__RQ_CMP_COBJ_OOBJ__HS             
                          
#define TGT_T3_HS_PHS_1      TGT_T3_PHS_TR__RQ_RV_STNG_OBJ__HS            
#define TGT_T3_HS_PHS_2      TGT_T3_PHS_WAIT_ANSW__RSP_RDY_TR_STNG_OBJ_HS 
#define TGT_T3_HS_PHS_3      TGT_T3_PHS_TR_TRANSPORT_RV_STNG_OBJ_OK_HS    
#define TGT_T3_HS_PHS_4      TGT_T3_PHS_TR_TRANSPORT_RV_STNG_OBJ_ERR_HS   

//-------------------------------------------------------------------
#define TGT_T1_PHS_WAIT_CMD_HM                               30//+1  //Wait any cmd type T1
#define TGT_T1_PHS_TGT_T1_PHS__RDY_RV_STNG_OBJ__HM           (TGT_T1_PHS_WAIT_CMD_HM                            +1)
#define TGT_T1_PHS_TGT_T1_PHS_TRANSPORT_RV_STNG_OBJ_OK__HM   (TGT_T1_PHS_TGT_T1_PHS__RDY_RV_STNG_OBJ__HM        +1)
#define TGT_T1_PHS_TRANSPORT_RV_STNG_OBJ_ERR__HM             (TGT_T1_PHS_TGT_T1_PHS_TRANSPORT_RV_STNG_OBJ_OK__HM+1)
//#define TGT_T1_PHS_ _HM
#define TGT_T2_PHS_WRITE_COBJ_OOBJ_HM                       (TGT_T1_PHS_TRANSPORT_RV_STNG_OBJ_ERR__HM +1) 
#define TGT_T2_PHS_CMP_COBJ_OOBJ_HM                         (TGT_T2_PHS_WRITE_COBJ_OOBJ_HM            +1)
#define TGT_T3_PHS_TGT_T1_PHS__RDY_RV_STNG_OBJ__HM          (TGT_T2_PHS_CMP_COBJ_OOBJ_HM              +1)

//```````````````````````````````````````


//-------------------------------------------------------------------
//Order Selectors


#define ORD_SEL_TGT_T1_HS_PHS_1   (         1                ) //TR__RQ_TR_STNG_OBJ__HS            
#define ORD_SEL_TGT_T1_HS_PHS_2   (ORD_SEL_TGT_T1_HS_PHS_1 +1) //WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS
#define ORD_SEL_TGT_T1_HS_PHS_3   (ORD_SEL_TGT_T1_HS_PHS_2 +1) //_RQ_TRANSPORT_RESULT_TR__OBJ_HS   
                                                               //
#define ORD_SEL_TGT_T2_HS_PHS_1   (0+1)                        //TR__RQ_WRITE_COBJ_OOBJ__HS        
#define ORD_SEL_TGT_T2_HS_PHS_2   (0+1)                        //WAIT_ANSW_CMP_COBJ_OOBJ__HS       
#define ORD_SEL_TGT_T2_HS_PHS_3   (0+1)                        //_RQ_CMP_COBJ_OOBJ__HS             
                                                               //
#define ORD_SEL_TGT_T3_HS_PHS_1   (0+1)                        //TR__RQ_RV_STNG_OBJ__HS            
#define ORD_SEL_TGT_T3_HS_PHS_2   (0+1)                        //WAIT_ANSW__RSP_RDY_TR_STNG_OBJ_HS 
#define ORD_SEL_TGT_T3_HS_PHS_3   (0+1)                        //TR_TRANSPORT_RV_STNG_OBJ_OK_HS    
#define ORD_SEL_TGT_T3_HS_PHS_4   (0+1)                        //TR_TRANSPORT_RV_STNG_OBJ_ERR_HS   



//-------------------------------------------------------------------
#define ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS            0X20
#define ERR__BAD_TGT_CODE                              (ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS + 1)
#define ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS1           (ERR__BAD_TGT_CODE + 1)
#define ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS2           (ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS1 + 1)
#define ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS3           (ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS2 + 1)
#define ERR__TIMEOUT__TGT_T1_PHS2                      (ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS3  +1)
#define ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS4           (ERR__TIMEOUT__TGT_T1_PHS2             +1)
#define ERR__OVERRUN_FAIL_TRANSPORT__TGT_T1_PHS4       (ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS4   +1)


//#define ERR_TGT_T2_PHS_
//#define ERR_TGT_T3_PHS_
//#define ERR_TGT_T3_PHS_




//. #define T1_PHASE_OVERRUN_LIMIT_INIT_T1_PHASE_REQ_TR_DATA  2
//. #define T1_PHASE_OVERRUN_LIMIT_INIT                        ( T1_PHASE_OVERRUN_LIMIT_INIT_T1_PHASE_REQ_TR_DATA +1)

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""







//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~ ICI cmm Cmd Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define RQ_REMOUTE_RST_HM_HS
//#define RQ_TGT_PHASE_HM_HS
//#define RQ_SET_PHASE_X_HM_HS
//#define RQ_SET_TGT_Y_HM_HS
//
//#define RQ_TGT_T1
//
//#define RQ_TGT1_TR_DATA        
//#define RQ_TGT1_TANSPORT_RESULT
//#define RQ_TGT1_GET_STATE_PHASE

#define CMM_REMOUTE_RST                         11
#define CMM_GET_TGT_PHASE                       12  
#define CMM_SET_PHASE_X_HM_HS                   13
#define CMM_SET_TGT_Y_HM_HS                     14
#define CMM_TR_OBJ_HS                           15

#define CMM_TR_COBJ_HS_TO_HM                    16
#define CMM_GET_TRANSPORT_TR_COBJ_HS_FROM_HM    17
#define CMM_WRITE_COBJ_OOBJ_HS_TO_HM            18
#define CMM_                                    19


#define CMM_RDY_RV_OBJ_HM                       31 
#define CMM_TRANSPORT_RV_OBJ_OK_HM              32
#define CMM_TRANSPORT_RV_OBJ_ERR_HM             33
#define CMM_TR_COBJ_HM_TO_HS                    34 


#define RSP//RESPOUNCE /???	
#define RDY_RV_OBJ//RDY_RV_STNG_OBJ STNG - Codes in TGT_T! name
#define TRANSPORT_RV_OBJ_OK

#define ANSW_

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~ ICI cmm Cmd Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//

#define ERR_TRANSPORT_WAITING_DATA 0x81
#define ERR_OBJECT_RECEIVE_SIZE    (ERR_TRANSPORT_WAITING_DATA +1)
//#define ERR_
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define CMM_GET_STNG_OBJ_FROM_HS 22
#define CMM_GET_YUST_OBJ_FROM_HS (CMM_GET_STNG_OBJ_FROM_HS+1)



#define ECT_WAIT_CMD_HS               0x10
#define ECT_SEND_STNG_FROM_HS         (ECT_WAIT_CMD_HS       +1)
#define ECT_REQ_ACTIVATE_RV           (ECT_SEND_STNG_FROM_HS +1)
#define ECT_SEND_REQ_TR_STNG_FROM_HS   (ECT_REQ_ACTIVATE_RV  +1) //SetSendReqTrStngEct
#define ECT_CREATE_CMM_TR_COBJ_HM_TO_HS (ECT_SEND_REQ_TR_STNG_FROM_HS)
#define ECT_SEND_YUST_FROM_HS           (ECT_CREATE_CMM_TR_COBJ_HM_TO_HS +1)
#define ECT_SEND_REQ_TR_YUST_FROM_HS     (ECT_SEND_YUST_FROM_HS+1)
//#define ECT_WR
//#define ECT_CM
#define ECT_SEND_REQ_TR_PRT_TBL_FROM_HS   (ECT_SEND_REQ_TR_YUST_FROM_HS    +1)
#define ECT_CREATE_CMM_TR_COBJ_HR_TO_HS   (ECT_SEND_REQ_TR_PRT_TBL_FROM_HS +1)
#define ECT_SEND_PRT_TBL_FROM_HS          (ECT_CREATE_CMM_TR_COBJ_HR_TO_HS +1)


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~ ICI cmm Cmd Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//Settings HM Constants

#define CMM_GET_STNG_OBJ_FROM_HM 12
#define CMM_GET_YUST_OBJ_FROM_HM 13

#define ECT_WAIT_CMD_HM           0x10
#define ECT_WRITE_COBJ_OOBJ_HM    (ECT_WAIT_CMD_HM         +1)
#define ECT_CMP_COBJ_OOBJ_HM      (ECT_WRITE_COBJ_OOBJ_HM  +1)
#define ECT_SEND_STNG_FROM_HM     (ECT_CMP_COBJ_OOBJ_HM    +1)

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~ ICI cmm Cmd Definition Proxy Manager+Transport ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//Settings HM Constants

//#define CMM_GET_STNG_OBJ_FROM_HM 12
//#define CMM_GET_YUST_OBJ_FROM_HM 13
#define  CMM_GET_PRT_TBL_OBJ_FROM_HR 12





#define ECT_WAIT_CMD_HR           0x10
#define ECT_WRITE_COBJ_OOBJ_HR    (ECT_WAIT_CMD_HM         +1)
#define ECT_CMP_COBJ_OOBJ_HR      (ECT_WRITE_COBJ_OOBJ_HM  +1)
#define ECT_SEND_STNG_FROM_HR     (ECT_CMP_COBJ_OOBJ_HM    +1)





//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""




#endif

