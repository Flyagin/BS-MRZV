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
* Processor       : at91sam9g45
* File Name       : DiagnG.c
* Description     : Functions and Data for Low Level Program Evt serv
                    BR BS BM

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  19/11/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
//#include "libraries_mal.h"
//#include "constants_mal.h"
//#include "hve_df.h"
//#include "hv_df.h"
#include "type_definition_mal.h"
#include "variables_external_mal.h"
//#include "functions_external_mal.h"
#include "macroses_mal.h"
#include "dFlMap.h"

#include <string.h>
//really in flash Memory write only 1(one) PrgEvtRecord_T1_Dsc hl__PrgEvtRecord;
//then scan & Calc lCheckSum_arPrgEvt
//then write lCheckSum_arPrgEvt and save in datafl arPrgEvtRecord_T1[uchIdxWrRecord]
//This is one record
//Than save lCheckSum_arPrgEvt; In EEPROM or in DataFlash;

//so in Data flash you hold totally    arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD]
//                    |
//                    V <<==== 
//#define AMOUNT_PRG_EVT_RECORD 100
//extern PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD];

//First you Should read total  arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD] in Ram
//and then check it correctnes and Modify it in Ram

PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1_WrBuf[AMOUNT_PRG_EVT_RECORD] @ "DDR2_Bank1_2_variables";
PrgEvtRecord_T1_Dsc arPrgEvtRecord_T1_RdBuf[1] @ "DDR2_Bank1_2_variables";

PrgEvtFlash_2_Dsc   hPrgEvtMangInfo;


/*



//This routine handle only Prg Evt Req
//For Readin and for Writing Routines
//Readin and for Writing Routines Calls from High Level routinegs global arbitration
void ServicePrgEvtDFlReq(void)
{
	register long i;
	void *pv;
	PrgEvtDFlServ_Dsc *pPrgEvtDFlServ = &hldPrgEvtDFlServ;
	
//Check Curr State hldPrgEvtDFlServ
	if()


//In this place Insert Check & control queue
//Look Checking Priority each Req and Create One Req for change data in hldPrgEvtDFlServ
// Do it globaly in another place for Example

//
	

}
*/



		/*
		//sLV.pDsc = (DataFlDRecEmrDescr*)&arDRecWrBuf[0];
		pvCMD32 = (void*)&dataDRecDFl;
		
		i = ((DRecDFlMemData*)pvCMD32)->IdxWRSector;
		if ( i>=(((DRecDFlMemData*)pvCMD32)->ushNumSectorPerEmr) )
		{
			((DRecDFlMemData*)pvCMD32)->IdxWRSector = 0;
			chReqActSpiDataFl &= ~1;//Clear Req
			goto ExitActivateSpiDataFlashExch;
		}
		else
			((DRecDFlMemData*)pvCMD32)->IdxWRSector = i+1;
		
		//sLV.IdxWrSectorEmrFlsh = i;
		sLV.CurrSectorAddr = (U32)((DRecDFlMemData*)pvCMD32)->PAddrCurrEmr;//Startup Addr
		sLV.CurrSectorAddr += i*SIZE_DEMR_SECTOR;
		
		pU32 = (U32*)&buffer_serial_DataFlash_read_write[0];
		pvCMD32 = (void*)&arDRecWrBuf[0];
		i *=SIZE_DEMR_SECTOR;//
		i +=(long) pvCMD32;
		pvCMD32 = (void*)i;
		pU8     = (U8*)i;
		//Move Data
		for (i = 0; i<(0x100);i+=4 )
		{
			
			sLV.U32unionbit.ul_val = *( (U32*)((U8*)pvCMD32+i) );
			//sLV.U32unionbit.ul_val = *((U32*)pU8+ 4*i);
			pU32[i+0] = sLV.U32unionbit.ar_uch[0];
			pU32[i+1] = sLV.U32unionbit.ar_uch[1];
			pU32[i+2] = sLV.U32unionbit.ar_uch[2];
			pU32[i+3] = sLV.U32unionbit.ar_uch[3];
			
		}
		address_read_write      = sLV.CurrSectorAddr;
		number_bytes_read_write = 0x100;
		_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_BIT);
		
		//goto ExitActivateSpiDataFlashExch;
*/
PrgEvtDFlServ_Dsc hldPrgEvtDFlServ;

char chbsPrgEvtRecord_T1_Buf_State;

void RdServicePrgEvtDFl(void* pv, long lV)   @ "Fast_function"
{
	register long i;
	 unsigned long   *pU32;
	 unsigned char    *pU8;
//	void *pv;
	register PrgEvtDFlServ_Dsc *pPrgEvtDFlServ = &hldPrgEvtDFlServ;
//	struct 
//	{
//		//short shErr;
//		void *pOriginDFlParam;
//	} sLV;
//	sLV.pOriginDFlParam = pv;
	((DFlParam_Dsc*)pv)->shRes = 0;
	
	i = chbsPrgEvtRecord_T1_Buf_State;
	if( (i& (BS_RD_END_PRG_EVT_RCD__MSK  )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_PRG_EVT_RCD_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			////Check if Not Wr
			if((i&(BS_PRG_EVT_RCD_RD_MSK )) == 0)
			{
				//Activate writing
				chbsPrgEvtRecord_T1_Buf_State |= BS_PRG_EVT_RCD_RD_MSK | BS_PRG_EVT_RCD_USED_MSK;
				//
				//CalC Base DflAddr
				pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_size = sizeof(PrgEvtRecord_T1_Dsc);
				pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill = 0;
			    pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_get  = 0;
				//lV = (SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR-8;
			}
		}
	}	
	//Move data from previous Operation
	lV = pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill-  pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_get;
	i = (long)&arPrgEvtRecord_T1_RdBuf[0];//Base Obj Addr
	i += pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_get;
	if(lV)
	{
		//memcpy((void*)i,(const void*)((DFlParam_Dsc*)pv)->pDRBuf,lV);//
		pU8 = (unsigned char*)i;
		pU32 = ((DFlParam_Dsc*)pv)->pDRBuf;
		for (i = 0; i<(lV);i+=4 )
		{
			pU8[i+0] = pU32[i+0];//U32unionbit.ar_uch[0];
			pU8[i+1] = pU32[i+1];//U32unionbit.ar_uch[1];
			pU8[i+2] = pU32[i+2];//U32unionbit.ar_uch[2];
			pU8[i+3] = pU32[i+3];//U32unionbit.ar_uch[3];
			
		}	
			
		pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_get = pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_get+lV;
	}

		
	//CalC Addr
	i =  pPrgEvtDFlServ ->chNumberPrgEvtRecord_T1;
	i *= sizeof(PrgEvtRecord_T1_Dsc);
	i += ADR_AREA_PREC;
	i += pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill;
	
	((DFlParam_Dsc*)pv)->ulAddrServData = i;
	//Calc 
	 i = (pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_size) - (pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill);
	if(i==0) 
	{
		//End of Reading
		//i = chbsPrgEvtRecord_T1_Buf_State;
		chbsPrgEvtRecord_T1_Buf_State &=~(BS_PRG_EVT_RCD_RD_MSK | BS_PRG_EVT_RCD_USED_MSK);
		chbsPrgEvtRecord_T1_Buf_State |= BS_RD_END_PRG_EVT_RCD__MSK;
		if(hldrRdPrgEvtInfo.state&(1<<BS_EXEC_NOW_RCD_ONB))
		{
			lV = ReadPrgEvtBmBrBs();//CallBack high Interface
		}
		return;
	}
	if( i>=(SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR) )
	((DFlParam_Dsc*)pv)->shAmtServData =  SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR-8;
	else
	((DFlParam_Dsc*)pv)->shAmtServData = i;
	
	((DFlParam_Dsc*)pv)->shRes = i;
	pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill = (pPrgEvtDFlServ ->chPrgEvtRcdT1_RD_fill)+i;
	
	

//	pPrgEvtDFlServ->chNumberPrgEvtRecord_T1
	return ;
	
}

void WrServicePrgEvtDFl(void* pv, long lV)   @ "Fast_function"
{
	register long i;
	 unsigned long   *pU32;
	 unsigned char    *pU8;

//	void *pv;
	register PrgEvtDFlServ_Dsc *pPrgEvtDFlServ = &hldPrgEvtDFlServ;
//	struct 
//	{
//		//short shErr;
//		void *pOriginDFlParam;
//	} sLV;
//	sLV.pOriginDFlParam = pv;
	((DFlParam_Dsc*)pv)->shRes = 0;
	
	i = chbsPrgEvtRecord_T1_Buf_State;
	if( (i& (BS_WR_END_PRG_EVT_RCD__MSK  )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_PRG_EVT_RCD_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			////Check if Not Wr
			if((i&(BS_PRG_EVT_RCD_WR_MSK )) == 0)
			{
				//Activate writing
				chbsPrgEvtRecord_T1_Buf_State |= BS_PRG_EVT_RCD_WR_MSK | BS_PRG_EVT_RCD_USED_MSK;
				//
				//CalC Base DflAddr
				pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_size = sizeof(PrgEvtRecord_T1_Dsc);
				pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill = 0;
			    pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_get  = 0;
				//lV = (SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR-8;
			}
		}
	}	
	//Move data for current Operation
	lV = pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_size - pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_get;//pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill;
	
	if( lV>=(SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR) )
	((DFlParam_Dsc*)pv)->shAmtServData =  SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR-8;
	else
	((DFlParam_Dsc*)pv)->shAmtServData = lV;
	
	//Calc hundled size
	 i = (pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_size) - (pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill);
	if(i==0) 
	{
		//End of Reading
		//i = chbsPrgEvtRecord_T1_Buf_State;
		chbsPrgEvtRecord_T1_Buf_State &=~(BS_PRG_EVT_RCD_WR_MSK | BS_PRG_EVT_RCD_USED_MSK);
		chbsPrgEvtRecord_T1_Buf_State |= BS_WR_END_PRG_EVT_RCD__MSK;
		if(hldrWrPrgEvtInfo.state&(1<<BS_EXEC_NOW_RCD_ONB))
		{
			lV =WritePrgEvtBmBrBs();//CallBack high Interface
		}
		return;
		
	
	}
	
	
	//i = (long)&arPrgEvtRecord_T1_WrBuf[0];//Base Obj Addr
	i = (long)hldrWrPrgEvtInfo.pDRBuf;// + hldrWrPrgEvtInfo.shCurrExchNum;
	i += pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_get;//Get from wr buf   
	if(lV)
	{
		// memcpy((void*)((DFlParam_Dsc*)pv)->pDRBuf,(const void*)i,lV);//
		pU8 = (unsigned char*)i;
		pU32 = ((DFlParam_Dsc*)pv)->pDRBuf;
		for (i = 0; i<(lV);i+=4 )
		{
			
			//sLV.U32unionbit.ul_val = *( (U32*)((pU8+i) );
			
			pU32[i+0] = pU8[i+0];//U32unionbit.ar_uch[0];
			pU32[i+1] = pU8[i+1];//U32unionbit.ar_uch[1];
			pU32[i+2] = pU8[i+2];//U32unionbit.ar_uch[2];
			pU32[i+3] = pU8[i+3];//U32unionbit.ar_uch[3];
			
		}
		pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_get = pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_get+lV;
		
	}

		
	//CalC Addr
	i =  pPrgEvtDFlServ ->chNumberPrgEvtRecord_T1;
	i *= sizeof(PrgEvtRecord_T1_Dsc);
	i += ADR_AREA_PREC;
	i += pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill;
	
	((DFlParam_Dsc*)pv)->ulAddrServData = i;
	
	
//	if( i>=(SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR) )
//	((DFlParam_Dsc*)pv)->shAmtServData =  SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR-8;
//	else
//	((DFlParam_Dsc*)pv)->shAmtServData = i;
	
	((DFlParam_Dsc*)pv)->shRes = ((DFlParam_Dsc*)pv)->shAmtServData;//i;
	pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill = (pPrgEvtDFlServ ->chPrgEvtRcdT1_WR_fill)
	+((DFlParam_Dsc*)pv)->shAmtServData;
	


//	pPrgEvtDFlServ->chNumberPrgEvtRecord_T1
	return;
	
}

unsigned char uchOwnersField;
char chQueueEUSize;
QueueEU arQueueEU[8];
QueueEU *pHeadQueue;
QueueEU *pTailQueue;



//Insert ExecUnit in Queue
long InsEU(PFV_VL pfv_vl);
//Return Back Key
QueueEU *FindFreeEU(void);

//Delete  ExecUnit from Queue
long DelEU(long lKey,PFV_VL pfv_vl);
//Take lKey for Check PFV_VL pfv_vl
//If Ok Ret 1 else Ret 0;
long InsEUAtHead(PFV_VL pfv_vl)  @ "Fast_function"
{
	register long lrV;
	register long i;
	register QueueEU* pQueueEU;
	
//	sLV.pPrev = sLV.chIdxCurr = sLV.chIdxNext = sLV.chIdxPrev = i  = 0;
	if(pHeadQueue == 0)
	{
		pQueueEU = arQueueEU;
		i = 0;
		lrV = uchOwnersField;//FindFreeEU
		while( (lrV&(1<<i))&& (i<8) )
		i++;//Hold Free
		pQueueEU = &arQueueEU[i];
		pQueueEU->pNext = 0;

		pTailQueue = pHeadQueue = pQueueEU;
		//Mofify Elem
		
	}
	else
	{
		pQueueEU = pHeadQueue;
		i = 0;
		lrV = uchOwnersField;//FindFreeEU
		while( (lrV&(1<<i))&& (i<8) )
		i++;//Hold Free
		
		//Look and Check
		pQueueEU->pNext = pHeadQueue;
		pHeadQueue = &arQueueEU[i];
	}	
	pQueueEU->pPrev = 0;
	pQueueEU->pfv_vl = pfv_vl;
	uchOwnersField |=(1<<i);
	chQueueEUSize++;
//ExitInsEU:
	
	return i;
}
long InsEUAtTail(PFV_VL pfv_vl)  @ "Fast_function"
{
	register long lrV;
	register long i;
	register QueueEU* pQueueEU;
	
//	sLV.pPrev = sLV.chIdxCurr = sLV.chIdxNext = sLV.chIdxPrev = i  = 0;
	if(pHeadQueue == 0)
	{
		pQueueEU = arQueueEU;
		i = 0;
		lrV = uchOwnersField;//FindFreeEU
		while( (lrV&(1<<i))&& (i<8) )
		i++;//Hold Free
		pQueueEU = &arQueueEU[i];
		pTailQueue = pHeadQueue = pQueueEU;
		//Mofify Elem
		pQueueEU->pNext = 0;//pHeadQueue;
	pQueueEU->pPrev = 0;
	pQueueEU->pfv_vl = pfv_vl;
	}
	else
	{
		pQueueEU = pHeadQueue;
		i = 0;
		lrV = uchOwnersField;//FindFreeEU
		while( (lrV&(1<<i))&& (i<8) )
		i++;//Hold Free
		// &arQueueEU[i];
		//Look and Check
		lrV = 0;
		while( (pQueueEU->pNext != 0) && (lrV <8 ))
		{
			pQueueEU = pQueueEU->pNext;
			lrV++;
		}	
		pQueueEU->pNext = &arQueueEU[i];
		pTailQueue = pQueueEU->pNext;
		arQueueEU[i].pPrev = pQueueEU;
	    arQueueEU[i].pfv_vl = pfv_vl;
		arQueueEU[i].pNext = 0;
	
	}	
	uchOwnersField |=(1<<i);
	chQueueEUSize++;
//ExitInsEU:
	
	return i;
}
long DelEU(long lKey,PFV_VL pfv_vl)   @ "Fast_function"
{
	register long lrV;
	register long i;
	register QueueEU *pQueueEU;//,*pQueueEU1;

	lrV = 0;
	pQueueEU = pHeadQueue;
	if(uchOwnersField&(1<<lKey))
	{
		pQueueEU = &arQueueEU[lKey];
		if(pQueueEU->pfv_vl == pfv_vl)
		{
			
		}
		else
		return 0;//Error
		
	}
	else
	{
		lrV = 0;
		while( (pQueueEU->pNext != 0) && (lrV <8 ))
		{
			if(pQueueEU->pfv_vl == pfv_vl)
		    {
		    	break;
		    }
			
			pQueueEU = pQueueEU->pNext;
			lrV++;//Traverse Counter
		}	
		lKey = lrV;
		if((uchOwnersField&(1<<lrV))==0)
		return 0;//Error
		
		
	}
	

	//Size >3
	if (chQueueEUSize>=3)
	{
		if(pQueueEU==pHeadQueue)
		{
			pHeadQueue = pQueueEU->pNext;//??
			//pHeadQueue->pPrev = 0;		
			//modify Head
			
		}
		
		if(pQueueEU==pTailQueue)
		{
			//modify Tail		
			pTailQueue  = pQueueEU->pPrev;
			//pTailQueue->pNext = 0;
		}
		
		lrV = (long) pQueueEU->pPrev;
		i   = (long) pQueueEU->pNext;
		((QueueEU *)lrV)->pNext = (QueueEU *)i;
		((QueueEU *)i  )->pPrev = (QueueEU *)lrV;  
	
	}
	if (chQueueEUSize==2)
	{
		if(pQueueEU==pHeadQueue)
			pHeadQueue = pQueueEU->pNext;//??
		if(pQueueEU==pTailQueue)
		pTailQueue  = pQueueEU->pPrev;		
	}
	else
	{
		pHeadQueue = pTailQueue = 0;
	
	}
	 

	pQueueEU->pNext = 0;
	pQueueEU->pPrev = 0;
	pQueueEU->pfv_vl = 0;
	
	uchOwnersField &=(~1<< lKey);
	if(chQueueEUSize)chQueueEUSize--;
	return lKey;


}

QueueEU *pTracePtr;	
long TraverseQueueEU(long lPos)   @ "Fast_function"
{
	register long lrV;
//	register long i;
	register QueueEU *pQueueEU;//,*pQueueEU1;

	if(lPos>chQueueEUSize)
	lPos = 0;
	lrV = 0;
	if(pTracePtr==0)
	{
		pTracePtr = pHeadQueue;
		return lrV;//Real lPos
	}	
	else
	pQueueEU = pTracePtr;
	if(pQueueEU==pTailQueue)
		pQueueEU = pHeadQueue;

	while(
	(pQueueEU->pNext != 0) && (lrV <= lPos)
	 
	)
	{
		if(pQueueEU==pTailQueue)
		pQueueEU = pHeadQueue;
		else
		pQueueEU = pQueueEU->pNext;
		
		lrV++;//Traverse Counter
	}
	pTracePtr = pQueueEU;
return 	lrV;
	

	
		
}	
	




PFV_VL arReadPfl_vl[8];
PFV_VL arWritePfl_vl[8];

char arChRdQueueId[8];
char chRD_fill;
char chRD_get; 
char chRD_size;

char arChWrQueueId[8];
char chWR_fill;
char chWR_get; 
char chWR_size;


//-Obsolete char chReadReqField;//Obj Requst shoul be Fixed
//-Obsolete char chWrReqField;
//-Obsolete char chAmtReadRequst;
//-Obsolete char chAmtWrRequst;

char chRdSelector;
char chWrSelector;
char chRdActivator;

void ServiceLLDFlQuery(void)   @ "Fast_function"
{
register long i,j;	
register PFV_VL pfl_vl;	
DFlParam_Dsc  locHldDFlParam;
	if (

    (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT) == 0) &&
    (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) == 0) &&
    (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT) == 0) &&
    (_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) == 0) &&
    (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) == 0) &&
    (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_DR_BIT) == 0) 
  
   )
		{
		//Можна змінювати змінні address_read_write і number_bytes_read_write і вмістиме буферу buffer_serial_DataFlash_read_write
			//
			pfl_vl = (PFV_VL) 0;
			//First Detect Read Or Write
			
			chRdActivator++;
			if(chWR_size==0)
			chRdActivator = 4;//Try Reading
			if(chRdActivator >= 4)//Reading Permittion
			{
				chRdActivator = 0;//Select Reading Operation
				if(chQueueEUSize) //chRD_size)
				{
					j = 0;i = chRdSelector;i++;
					/*
					do
					{
					//Select Current Service Obj
					
					i++;
					if(i >= 8)
					i = 0;
					if(i > chRD_fill) 
					i = chRD_get;
					if(i < chRD_get) 
					i = chRD_get;	
					j++;
					//Look In Table Hundler Obj And Exec It
					pfl_vl = arReadPfl_vl[i];
					}while((j<=(chRD_size)) && (pfl_vl == 0 ));
					
					chRdSelector = i;//???
					*/
					chRdSelector = TraverseQueueEU(i);
					if(pTracePtr)
					pfl_vl =  pTracePtr->pfv_vl;
					//Activate Reading
					if(pfl_vl)
					{
						locHldDFlParam.shRes  = 0;
						locHldDFlParam.pDRBuf = buffer_serial_DataFlash_read_write_dr;
						pfl_vl((void*)&locHldDFlParam,i);
						if(locHldDFlParam.shRes)
						{
							address_read_write_dr      = (unsigned int)locHldDFlParam.ulAddrServData;
							number_bytes_read_write_dr = (unsigned int)locHldDFlParam.shAmtServData;
							_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT );
						}
						
					}
					
				
				}
				else
				{
					//Check Writing Requst
					goto CheckWriteReq;
				}
			
			
			}
			else
			{
CheckWriteReq:
				if(chWR_size)
				{
					//Select Current Service Obj
					i = chWrSelector;
					j = 0;
					do{
					i++;j++;
					if(i >= 1)//Now only two adresats for writing 0-Prec 1-Drec
					i = 0;
					//.if(i > chWR_fill) 
					//.i = chWR_get;
					//.if(i < chWR_get) 
					//.i = chWR_get;
					
					//Look In Table Hundler Obj And Exec It
					pfl_vl = arWritePfl_vl[i];
					}while( (pfl_vl==0) && (j<2));//Now 0-Fix Prec 1-Fix Drec If More do Queue
					chWrSelector = i;//???
					
					//Activate Writing
					if(pfl_vl)
					{
						locHldDFlParam.shRes  = 0;
						locHldDFlParam.pDRBuf = buffer_serial_DataFlash_read_write_dr;
						pfl_vl((void*)&locHldDFlParam,i);
						if(locHldDFlParam.shRes)
						{
							address_read_write_dr      = (unsigned int)locHldDFlParam.ulAddrServData;
							number_bytes_read_write_dr = (unsigned int)locHldDFlParam.shAmtServData;
							_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT );
						}
						
					}	
				
				
				}
			
				goto ExitServiceLLDFlQuery;
			}
			
			
			
		}
		else
		{
			//ще не можна змінювати змінні address_read_write і number_bytes_read_write і вмістиме буферу buffer_serial_DataFlash_read_write – бо не завершена попередня операція роботи з мікросхемою DataFlash
			//
			
		}

ExitServiceLLDFlQuery: 	
	return;


}

//long lWritingDiapazon = 0;

char charPrgEvtRecordWasRead = 0;
StateExchInfo hldrClrPrgEvtInfo = {
0,0,0,0
};

StateExchInfo hldrRdPrgEvtInfo;
long  lCtrWait;//Wait Answer
//long  lCs;
long SetupReadPrgEvtBmBrBs(long lNum, long lAmtPrgEvtUNN,void *pv)  @ "Fast_function"
{
register long i;
register StateExchInfo *pStateExchInfo = &hldrRdPrgEvtInfo; 
	i = pStateExchInfo->state;


if( (i& (1<<(BS_RCD_USED_ONB)) ) == 0)
	{
		//Start State
		pStateExchInfo->state        |= (1<<(BS_RCD_USED_ONB));
		
		pStateExchInfo->shStartNum   = lNum;
		pStateExchInfo->shAmount     = lAmtPrgEvtUNN;
		pStateExchInfo->shCurrExchNum =(short)~(i); 
		pStateExchInfo->pDRBuf        = pv;
		lCtrWait = 0x2000000;
		i = 1;
	}
	else 
	i = 0;
return i;


}
char chClrDfl_arPrgEvtRecord_T1;
char chQueOrdNum;
long ReadPrgEvtBmBrBs(void)  @ "Fast_function"
{
register long i;
register StateExchInfo *pStateExchInfo = &hldrRdPrgEvtInfo; 
	i = pStateExchInfo->state;

    if( (i& (1<<(BS_EXEC_NOW_RCD_ONB)  )) == 0)
    {
    	//Init Cycle
    	chQueOrdNum = InsEUAtTail((PFV_VL) RdServicePrgEvtDFl);
    	/*---01-12-15
    	i = chRD_size+1;
    	if(i>=8)
    	goto ExitReadPrgEvtBmBrBs;
    	chRD_size = i;
    	i = chRD_fill;
    	i++;
    	if(i>=8)
    	i = 0;
    	chRD_fill = i;
    	arReadPfl_vl[i] =(PFV_VL) RdServicePrgEvtDFl;
		chQueOrdNum = i;
		*/
    	//hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = pStateExchInfo->shStartNum;
    	pStateExchInfo->state       |= (1<<(BS_EXEC_NOW_RCD_ONB ));
    	//chbsPrgEvtRecord_T1_Buf_State
		pStateExchInfo->shIdxExchNum= 0;
   
    }
	//else
	{
		//Exch Cycle
		
		//End Cycle
		if(
		(chbsPrgEvtRecord_T1_Buf_State & BS_RD_END_PRG_EVT_RCD__MSK)//?
		||(pStateExchInfo->state&(1<<(BS_EXEC_NOW_RCD_ONB )))
		)
		{
			
			
			if(pStateExchInfo->shCurrExchNum== hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1)
			{
				//arPrgEvtRecord_T1[lPrgEvtRecFirstIdx] =  arPrgEvtRecord_T1_RdBuf[0];
				i =(long) pStateExchInfo->pDRBuf;
				i += (pStateExchInfo->shStartNum +pStateExchInfo->shIdxExchNum)
				*sizeof(PrgEvtRecord_T1_Dsc);
				memcpy((void*)i,(const void*)arPrgEvtRecord_T1_RdBuf,sizeof(PrgEvtRecord_T1_Dsc) );//
				pStateExchInfo->shIdxExchNum += 1;
				if(pStateExchInfo->shIdxExchNum >= pStateExchInfo->shAmount)
				{
				//End of Exec
				pStateExchInfo->state       &= ~(1<<(BS_EXEC_NOW_RCD_ONB ))|(1<<(BS_RCD_USED_ONB));
				pStateExchInfo->state       |= (1<<( BS_END_EXCH_RCD_ONB));
				hldrRdPrgEvtInfo = hldrClrPrgEvtInfo;
				//Data Read Success
				//Exclude from Queue
				i = DelEU(chQueOrdNum,(PFV_VL) RdServicePrgEvtDFl);
				if(charPrgEvtRecordWasRead == 1 )
				{
					 charPrgEvtRecordWasRead = 2;
					i = Eval_CS((char*)arPrgEvtRecord_T1_WrBuf,sizeof(PrgEvtRecord_T1_Dsc)*AMOUNT_PRG_EVT_RECORD);
					if(i != hPrgEvtMangInfo.ulCheckSum_arPrgEvt)
					{
						ClearPrgEvtMangInfo();
						charPrgEvtRecordWasRead++;
						i = ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT>>3;
						hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBs.UNBsRamPrgEvts.chArBsPrgEvts[i] = 
						(1<<(( ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT )-(8*(ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT   >>3)))  );
						//(1<<(( SETNGS_EPR_SDFE_ONB             )-(8*(SETNGS_EPR_SDFE_ONB                      >>3)))  )
						hPrgEvtMangInfo.ulCheckSum_arPrgEvt = Eval_CS((char*)arPrgEvtRecord_T1,sizeof(PrgEvtRecord_T1_Dsc)*AMOUNT_PRG_EVT_RECORD);
						//Wr to EEPROM
						_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
						//hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBs.UNBsRamPrgEvts.chArBsPrgEvts[ TO_IDX_U8(ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT)] |= TO_U8_MSK(ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT);
						
					
					}
					else{
						i = hPrgEvtMangInfo.uchIdxWrRecord;
						ch_arRcdT1_WrBuf_WR_fill = i;
						ch_arRcdT1_WrBuf_WR_get  = i;
						for(i = 0; i<AMOUNT_PRG_EVT_RECORD;i++ )
						arPrgEvtRecord_T1[i] = arPrgEvtRecord_T1_WrBuf[i];
						//memcpy((void*)&un,	(const void*)&(),							4);
					}
					
				}
				/*
				arReadPfl_vl[chQueOrdNum] =(PFV_VL)0;
				if(chRD_size)
				chRD_size--;
				i = chRD_get +1;
				if((i)==chQueOrdNum)
				chRD_get =i;
				*/
				goto ExitReadPrgEvtBmBrBs;
				}
				
				
			}
			//Prepea Exec
			
			i = pStateExchInfo->shStartNum ;
			i += pStateExchInfo->shIdxExchNum;
			hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = i;
			pStateExchInfo->shCurrExchNum= i;
			 lCtrWait = 0x2000000;
			chbsPrgEvtRecord_T1_Buf_State &=~( BS_RD_END_PRG_EVT_RCD__MSK);
		
		}
		//goto ExitReadPrgEvtBmBrBs;
	}
	
		if(lCtrWait)
		lCtrWait--;
		else
		{
			pStateExchInfo->state = 1;
			//Stop Exec
		
		}
	
	
	
	
	
	
ExitReadPrgEvtBmBrBs:
i = pStateExchInfo->state;

	return i;


}

StateExchInfo hldrWrPrgEvtInfo;

long SetupWritePrgEvtBmBrBs(long lNum, long lAmtPrgEvtUNN,void *pv)  @ "Fast_function"
{
register long i;
register StateExchInfo *pStateExchInfo = &hldrWrPrgEvtInfo; 
	i = pStateExchInfo->state;


if( (i& (1<<(BS_RCD_USED_ONB)) ) == 0)
	{
		//Start State
		pStateExchInfo->state        |= (1<<(BS_RCD_USED_ONB));
		
		pStateExchInfo->shStartNum   = lNum;
		pStateExchInfo->shAmount     = lAmtPrgEvtUNN;
		pStateExchInfo->shCurrExchNum =(short)~(i); 
		pStateExchInfo->pDRBuf        = pv;
		lCtrWait = 0x2000000;
		i = 1;
	}
	else 
	i = 0;
return i;


}

char chWrQueOrdNum;
long WritePrgEvtBmBrBs(void)  @ "Fast_function"
{
register long i;
register StateExchInfo *pStateExchInfo = &hldrWrPrgEvtInfo; 
	i = pStateExchInfo->state;

if( (i& (1<<(BS_EXEC_NOW_RCD_ONB)  )) == 0)
    {
    	//Init Cycle
    	//..chWrQueOrdNum = InsEUAtTail((PFV_VL) WrServicePrgEvtDFl);
		chWR_size++;arWritePfl_vl[0] = (PFV_VL) WrServicePrgEvtDFl;
		//hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = pStateExchInfo->shStartNum;
    	pStateExchInfo->state       |= (1<<(BS_EXEC_NOW_RCD_ONB ));
    	//chbsPrgEvtRecord_T1_Buf_State
		pStateExchInfo->shIdxExchNum= 0;
	}
	
	if(
		(chbsPrgEvtRecord_T1_Buf_State & BS_WR_END_PRG_EVT_RCD__MSK)//?
		||(pStateExchInfo->state&(1<<(BS_EXEC_NOW_RCD_ONB )))
		)
		{	
			
			if(pStateExchInfo->shCurrExchNum== hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1)
			{
				;
				pStateExchInfo->shIdxExchNum += 1;//If Need Change More then 1
				if(pStateExchInfo->shIdxExchNum >= pStateExchInfo->shAmount)
				{
				//End of Exec
				pStateExchInfo->state       &= ~(1<<(BS_EXEC_NOW_RCD_ONB ))|(1<<(BS_RCD_USED_ONB));
				pStateExchInfo->state       |= (1<<( BS_END_EXCH_RCD_ONB));
				if (charPrgEvtRecordWasRead == 3)charPrgEvtRecordWasRead++;
				
				hldrWrPrgEvtInfo = hldrClrPrgEvtInfo;
				//Data Write Success
				//Exclude from Queue
				//..i = DelEU(chWrQueOrdNum,(PFV_VL) WrServicePrgEvtDFl);
				if(chWR_size)
				chWR_size--;arWritePfl_vl[0] = (PFV_VL) 0;
				
				goto ExitWritePrgEvtBmBrBs;
				}
				
			}
			i = pStateExchInfo->shStartNum ;
			i += pStateExchInfo->shIdxExchNum;
			hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = i;
			pStateExchInfo->shCurrExchNum= i;
			 lCtrWait = 0x2000000;
			chbsPrgEvtRecord_T1_Buf_State &=~( BS_WR_END_PRG_EVT_RCD__MSK);
			
		}
ExitWritePrgEvtBmBrBs:
i = pStateExchInfo->state;

	return i;


}
char ch1SecCounter = 0;
char ch100MsCounter = 0;
char chTstVal;
char chTstVal1;

void DiagnProcess100msEvt(void)   @ "Fast_function"
{
register long i,j;
	ch100MsCounter++;
	if(ch100MsCounter >= 10)
	{
		ch100MsCounter = 0;
		ProcessProgramEvt();
		if(chTstVal)
		{
			SetupWritePrgEvtBmBrBs(0,1,(void*)arPrgEvtRecord_T1_WrBuf);
			WritePrgEvtBmBrBs();
			
		}
		if(chTstVal1)
		{
			//.`SetupWritePrgEvtBmBrBs(0,1,(void*)arPrgEvtRecord_T1_WrBuf);
			//.`WritePrgEvtBmBrBs();
			SetupReadPrgEvtBmBrBs(0,1,(void*)&arPrgEvtRecord_T1_WrBuf[9]);
			ReadPrgEvtBmBrBs();
			
		}
		if(charPrgEvtRecordWasRead == 3)//Need Clr DataFlashTable
			{
				//Check Writing
				i = hldrWrPrgEvtInfo.state& ( (1<<(BS_EXEC_NOW_RCD_ONB)) | (1<<(BS_RCD_USED_ONB)) ) ;
				j = hldrRdPrgEvtInfo.state& ( (1<<(BS_EXEC_NOW_RCD_ONB)) | (1<<(BS_RCD_USED_ONB)) ) ;
				if(
				(i==0)
				&&
				(j==0)
				)
				{
					SetupWritePrgEvtBmBrBs(0,AMOUNT_PRG_EVT_RECORD,(void*)arPrgEvtRecord_T1);
					WritePrgEvtBmBrBs();
					;
				}
					return;
			}
		FindException();
		if(
		(hldrRdPrgEvtInfo.state& ( (1<<(BS_EXEC_NOW_RCD_ONB)) | (1<<(BS_RCD_USED_ONB)) )) == 0//Start Reading
		)
		{
			//hPrgEvtMangInfo.ulCheckSum_arPrgEvt = Eval_CS((char*)arPrgEvtRecord_T1,sizeof(arPrgEvtRecord_T1[AMOUNT_PRG_EVT_RECORD]));
			
			i =  DetectException((void*)&(hPrgEvtMangInfo.hldFixUNN_PrgEvt),(void*)&hldUNN_PrgEvt);
			if(i)
			PutException();
		}
		
		
		
		if(ch_arRcdT1_WrBuf_WR_size)
		{
			//Check Writing
			i = hldrWrPrgEvtInfo.state& ( (1<<(BS_EXEC_NOW_RCD_ONB)) | (1<<(BS_RCD_USED_ONB)) ) ;
			j = hldrRdPrgEvtInfo.state& ( (1<<(BS_EXEC_NOW_RCD_ONB)) | (1<<(BS_RCD_USED_ONB)) ) ;
			if(
			(i==0)
			&&
			(j==0)
			)
			{
				SetupWritePrgEvtBmBrBs(ch_arRcdT1_WrBuf_WR_get,1,(void*)&arPrgEvtRecord_T1_WrBuf[ch_arRcdT1_WrBuf_WR_get]);
				WritePrgEvtBmBrBs();
				
			ch_arRcdT1_WrBuf_WR_size--;
			ch_arRcdT1_WrBuf_WR_get++;
			if(ch_arRcdT1_WrBuf_WR_get>= AMOUNT_PRG_EVT_RECORD)
			ch_arRcdT1_WrBuf_WR_get = 0;
			
			}
		}
		if(AppReqReceiveDiagnBrBs)
		{
			AppReqReceiveDiagnBrBs = 0;
			AppReqTransmitDiagnBsBr = 1;
		
		}
		ch1SecCounter++;
		if(ch1SecCounter  >= 10){
			ch1SecCounter = 0;
			CheckU2State();//Ctr Sec
			
		}
	
	}

}

/*
//, long lAmtPrgEvtUNN,char *pCh
long ReadPrgEvtBmBrBs(long lNum)//?Now Read Only One?
{
register long i;
register StateExchInfo *pStateExchInfo = &hldrRdPrgEvtInfo; 
	i = pStateExchInfo->state;
	if( (i& (1<<(BS_RCD_USED_ONB)) ) == 0)
	{
		//Start State
		pStateExchInfo->state        |= (1<<(BS_RCD_USED_ONB));
		pStateExchInfo->shStartNum   = lNum;
		pStateExchInfo->shAmount     = 1;
		pStateExchInfo->shCurrExchNum=(short)~lNum; 
		lCtrWait = 0x2000000;
		goto ExitReadPrgEvtBmBrBs;
	}
	else
	{
		if( (i& (1<<(BS_EXEC_NOW_RCD_ONB)  )) == 0)
		{
			//Init Cycle
			
			
			i = chRD_size+1;
			if(i>=8)
			goto ExitReadPrgEvtBmBrBs;
			chRD_size = i;
			i = chRD_fill;
			i++;
			if(i>=8)
			i = 0;
			chRD_fill = i;
			arChRdQueueId[i] = RdServicePrgEvtDFl;
			//hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = pStateExchInfo->shStartNum;
			pStateExchInfo->state       |= (1<<(BS_EXEC_NOW_RCD_ONB ));
			//chbsPrgEvtRecord_T1_Buf_State
			
			//goto ExitReadPrgEvtBmBrBs;
		
		}
		//else
		{
			//Exch Cycle
			
			//End Cycle
			if(
			(chbsPrgEvtRecord_T1_Buf_State & BS_RD_END_PRG_EVT_RCD__MSK)
			
			)
			{
				if(pStateExchInfo->shCurrExchNum== hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1)
				{
					//End of Exec
					pStateExchInfo->state       &= (1<<(BS_EXEC_NOW_RCD_ONB ))|(1<<(BS_RCD_USED_ONB));
					pStateExchInfo->state       |= (1<<( BS_END_EXCH_RCD_ONB));
					hldrRdPrgEvtInfo = hldrClrPrgEvtInfo;
				
				}
				//Prepea Exec
				
				i = pStateExchInfo->shStartNum ;
				hldPrgEvtDFlServ.chNumberPrgEvtRecord_T1 = i;
				pStateExchInfo->shCurrExchNum= i;
				//pStateExchInfo->shCurrExchNum=
				
			
			}
			goto ExitReadPrgEvtBmBrBs;
		}
		if(lCtrWait)
		lCtrWait--;
		else
		{
			pStateExchInfo->state = 1;
		
		}
	
	
	
	
	}
	
ExitReadPrgEvtBmBrBs:
i = pStateExchInfo->state;

	return i;


}

//first Read Data from Eeeprom then Ckeck Is Ok
//second Read Data from DataFlash and Check Is Ok
//then mix Data in Buf and Readed in Buf 


long lPrgEvtRecFirstStartIdx , lPrgEvtRecFirstIdx, lPrgEvtRecFirstSize;
//lPrgEvtRecFirstStartIdx = 0;
lPrgEvtRecFirstIdx      = 0;

void Read__arPrgEvtRecord_T1(void)
{
register long j;
	
	if(hldPrgEvtDFlServ.ulCheckSum_arPrgEvt != hPrgEvtMangInfo.ulCheckSum_arPrgEvt)
	{
		//Activate Start Reading
		j = ReadPrgEvtBmBrBs(lPrgEvtRecFirstIdx);
		if(j&1)
		{
			//Error Prepea Clr All Info
		
		}
		else
		{
			if(j&(1<<BS_END_EXCH_RCD_ONB))
			{
				arPrgEvtRecord_T1[lPrgEvtRecFirstIdx] =  arPrgEvtRecord_T1_RdBuf[0];
				lPrgEvtRecFirstIdx++;
				if(lPrgEvtRecFirstIdx >= AMOUNT_PRG_EVT_RECORD) 
				{
					//End Reading
					//
				}
				//else
				
				
			}
		
		}
	
	}



}
*/
UNN_PrgEvtBmBrBs hldUNN_PrgEvt @ "DDR2_Bank1_2_variables";
void FindException(void)  @ "Fast_function"
{
hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBs.UNBsRamPrgEvts.chArBsPrgEvts[0] = 1<< ERROR_BS_TEST1_BIT;
hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBr  = holderDiagnBrBs.UNN_Sdfe.muPrgEvtBmBrBs.RamPrgEvtFld.hldrPrgEvtBr;
hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBm  = holderDiagnBrBs.UNN_Sdfe.muPrgEvtBmBrBs.RamPrgEvtFld.hldrPrgEvtBm;
//hPrgEvtMangInfo.hldFixUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBr 
}




long DetectException(void *pFixPrgEvt, void *pCurrPrgEvt)  @ "Fast_function"
{
register long i,j,k;
j = (SIZE_DIAGN_FIELD>>2);
	for(i = 0; i<j ; i++)
	{
		k = *((unsigned long*)pFixPrgEvt  + i );
		k^= *((unsigned long*)pCurrPrgEvt + i );
		if(k)
		return k;
		
	}
	j = SIZE_DIAGN_FIELD - ((SIZE_DIAGN_FIELD>>2)<<2);
	for(i = ((SIZE_DIAGN_FIELD>>2)<<2); i<j ; i++)
	{
		k = *((unsigned char*)pFixPrgEvt  +i );
		k^= *((unsigned char*)pCurrPrgEvt +i );
		if(k)
		return k;
	}
	return 0;
}
void CompresDt(char* pCompressDt, char* pDt )
{
register int i,j,k;
volatile union dt_tag_tmp
	{
		char ch_dtt[4];
		unsigned int n_dtt;
	} dt;
volatile unsigned long temp_dt;

	pCompressDt[0] = pDt[0];
	pDt++;//pDt[1]
	temp_dt = 0;k = 0;
	do
	{

		i = *pDt++;
		j = i&0xf;
		j += 10*(i>>4);
		switch (k)
		{
		case 0:
			//struct_dtime.ss = j;
			//dt.dtt = j;
			temp_dt  = j;
			break;
		case 1:
			// struct_dtime.mn = j;
			//dt.dtt |= (j<< 6);
			temp_dt  |= (j<< 6);
			break;
		case 2:
			//struct_dtime.hh = j;
			//dt.dtt |= (j<< (6+6));
			temp_dt |= (j<< (6+6));//12
			break;
		case 4:
			//struct_dtime.dd = j;
			//dt.dtt |= (j<< (6+6+5));
			temp_dt |= (j<< (6+6+5));//17
			break;
		case 5:
			//struct_dtime.mh = j;
			//dt.dtt |= (j<< (6+6+5+5));
			temp_dt |= (j<< (6+6+5+5));//22
			break;
		case 6:
			//struct_dtime.yy = j;
			//dt.dtt |= (j<< (6+6+5+5+4));
			//temp_dt |= (j<< (6+6+5+5+4));	//	26<- Now comment for stop jaming
			break;
		default:
		i=0;
		}
		k++;
	}while (k < 6);
	i = *pDt++;
	j = i&0xf;
	temp_dt |= (j<< (6+6+5+5+4));//part of hours
	for (i = 0; i< 4;i++)
	{
		pCompressDt[i] =  dt.ch_dtt[i];
	}
	

}

char ch_arRcdT1_WrBuf_WR_fill;
char ch_arRcdT1_WrBuf_WR_get; 
char ch_arRcdT1_WrBuf_WR_size; 
char TstDt [8] = {0x30,0x12,0x15,3,0x14,0x06,0x37,77};
void PutException(void)  @ "Fast_function"
{
register long i,j;
register unsigned char *point_time;
	
	//hPrgEvtMangInfo.hldFixUNN_PrgEvt = hldUNN_PrgEvt;
	i =  hPrgEvtMangInfo.uchIdxWrRecord;
	arPrgEvtRecord_T1[i].hld_UNN_PrgEvt = hldUNN_PrgEvt;
//lTimeLabSysU32; <--- Try use interval betwen second for increase accuracy?
	//arPrgEvtRecord_T1[i].lTimeLabSysU32 = 0;//Only Now
	if (copying_time == 0) point_time = rtc_time;
    else point_time = rtc_time_copy;
	// point_time = TstDt;
	for (j = 0;j<8;j++ )
	arPrgEvtRecord_T1[i].BCDdt[j] = point_time[j];
	//arPrgEvtRecord_T1[i].lCompresDataTime = 

//arPrgEvtRecord_T1
//UNN_PrgEvtBmBrBs 
//Calc CheckSUM
	hPrgEvtMangInfo.ulCheckSum_arPrgEvt = Eval_CS((char*)arPrgEvtRecord_T1,sizeof(PrgEvtRecord_T1_Dsc)*AMOUNT_PRG_EVT_RECORD);
	
	if(ch_arRcdT1_WrBuf_WR_size<AMOUNT_PRG_EVT_RECORD)
	{
		
		
		
		i = hPrgEvtMangInfo.uchIdxWrRecord;
		arPrgEvtRecord_T1_WrBuf[ch_arRcdT1_WrBuf_WR_fill] = 
		arPrgEvtRecord_T1[i];
		ch_arRcdT1_WrBuf_WR_fill++;
		if(ch_arRcdT1_WrBuf_WR_fill>= AMOUNT_PRG_EVT_RECORD)
		ch_arRcdT1_WrBuf_WR_fill = 0;
		ch_arRcdT1_WrBuf_WR_size++;
	}
	i = hPrgEvtMangInfo.chAmountRecords;
	i++;
	if(i< AMOUNT_PRG_EVT_RECORD)
	hPrgEvtMangInfo.chAmountRecords = i;
	 
	i =  hPrgEvtMangInfo.uchIdxWrRecord;
	i++;
	if(i< AMOUNT_PRG_EVT_RECORD)
	hPrgEvtMangInfo.uchIdxWrRecord = i;
	else
	hPrgEvtMangInfo.uchIdxWrRecord = 0;
hPrgEvtMangInfo.hldFixUNN_PrgEvt = hldUNN_PrgEvt;
_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);

}



void ClearPrgEvtMangInfo(void)  @ "Fast_function"
{
register long i;
register void *pv;

pv = (void*)&hPrgEvtMangInfo;

((PrgEvtFlash_2_Dsc*)pv)->chAmountRecords      = 0;
((PrgEvtFlash_2_Dsc*)pv)->uchIdxWrRecord       = 0;
((PrgEvtFlash_2_Dsc*)pv)->ulCheckSum_arPrgEvt  = 0;
ch_arRcdT1_WrBuf_WR_fill = 0;
ch_arRcdT1_WrBuf_WR_get  = 0;
ch_arRcdT1_WrBuf_WR_size = 0;
//.pv = (void*)&hPrgEvtMangInfo.;

	for(i = 0; i< (long)sizeof(UNN_PrgEvtBmBrBs); i++)
	((long*)pv)[i] = 0;



}

void GetDiagnfield(void* pDiagn){
	if(pDiagn)
	{
          // 
         // memcpy(pDiagn,(const void*)&hldUNN_PrgEvt,sizeof(UNN_PrgEvtBmBrBs) );
         // memcpy(pDiagn,(const void*)&hldUNN_PrgEvt,sizeof(__DIAGN) );
          ((__DIAGN*)pDiagn)->hldrPrgEvtBm = hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBm;
          ((__DIAGN*)pDiagn)->hldrPrgEvtBr = hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBr;
          ((__DIAGN*)pDiagn)->hldrPrgEvtBs = hldUNN_PrgEvt.RamPrgEvtFld.hldrPrgEvtBs;
          
          
//((StateTpCnDsc*)pv)->

	}
}
/*
//exception
long GetElemExcept(long lNmExcept, char* pChOutParam)
{

}
*/

/* EOF */

