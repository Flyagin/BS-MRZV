
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long UpdateRVPrTptYust(void* pvLDC, long lID) @ "Fast_function"
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~ Handle Data Scan Channel for free Lpdu Buff
//~~~         ReqReceiveYustPrTpt <- RVPrTptYust
//~~~                          
//~~~ Processing:
//~~~ Move data from pvLDC <- Link Data Conteiner to Ses Buf           
//~~~ Describes hldrRVYustTransportCTpuUnit.arUchRV        
//~~~  //Try activate Proxy Transport if not activated          
//~~~  ReqReceiveYustPrTpt++;Indicate Proxy move data from Ses to Obj          
//~~~ Parameters: 
//~~~ void* pvLDC addr LDC                                  ~~~
//~~~ Outputs:
//~~~            Return Amount Process data                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~  Amount hundled Data        
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long ExecYustCmdPrMng  (void* pv, long lV) @ "Fast_function"
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~ Support Exec Cmd sequence without DeadLocks
//~~~ 
//~~~                          
//~~~ Processing:
//~~~ 1)//Control Self LifeTimer And Stop Self if Need
//~~~ 2) chUsehldCmmMsgRV semfor free/busy  lV&RV_CMD_DIS_MSK<-Permit 
//~~~   proces External Input Command
//~~~   2.1.Hndl Inp Msg from queue      
//~~~   2.2. call DpcsYustPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
//~~~      //Fix Change State   
//~~~ 
//~~~         
//~~~ 
//~~~         
//~~~ Parameters: 
//~~~    pv pointer on ProxyMangerStateDsc                        
//~~~ Outputs:
//~~~                                                       
//~~~ Returns:                                                             
//~~~     sLV.chRes 0 if ...    
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long DpcsYustPrMngMsg   (void* pv, long lV) @ "Fast_function"
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~ Analis Iput Cmd & Make Decision
//~~~ Need Clear Receive Msg
//~~~                          
//~~~ Processing:
//~~~ 1)/
//~~~ 2)  
//~~~   
//~~~   2.1.
//~~~   2.2.
//~~~      /
//~~~ 
//~~~         
//~~~ 
//~~~         
//~~~ Parameters: 
//~~~    pv pointer on ProxyMangerStateDsc                        
//~~~ Outputs:
//~~~                                                       
//~~~ Returns:                                                             
//~~~     State Proxy
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,


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
//Put CmmMsgDsc iN Buf
hldYustCmmMsgRV.UNNHdrMsg.uchAr[0]; - Cmd Send Chunk
hldYustCmmMsgRV.UNNHdrMsg.ushAr[1];offset
hldYustCmmMsgRV.size_Obj          
//

