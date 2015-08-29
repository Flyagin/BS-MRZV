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
* File Name       : lpu.c
* Description     : Functions and Data for Link Leyer
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "ApCn.h"
#include    "CTpu.h"
#include    "lpu.h"
#include "GU2.h"
#include "../LibG45/peripherals/usart/usart.h"
//#include "hu7lI.h"
#include "../LibG45/peripherals/irq/irq.h"

#include <intrinsics.h>
#include <string.h>
#include <stdio.h>







//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
TRStateLpuCn1Dsc holderCn1LpduUnit;
RVStateLpuCn1Dsc hldrCn1LpduUnit;

TRStateLpuHSU7Dsc hldrHSU7LpduTRUnit;
TRStateLpuHSU1Dsc hldrHSU1LpduTRUnit ;
TRStateLpuHSU2Dsc hldrHSU2LpduTRUnit;
TRStateLpuHSU2Dsc arrHSU2LpduTRUnit[200] @ "DDR2_Bank1_2_variables";
TRStateLpuU0Dsc   hldrU0LpduTRUnit;

TRStateLpuU2Dsc   hldrU2LpduTRUnit;

TRStateLpuDbguDsc hldrDbguLpduTRUnit;
#pragma data_alignment=4
TRStateLpuSpiDsc  hldrSpiLpduTRUnit;


RVStateLpuU3Dsc   hldrU3LpduUnit;
RVStateLpuHSU7Dsc hldrHSU7LpduUnit;

RVStateLpuHSU1Dsc hldrHSU1LpduUnit;

RVStateLpuHSU2Dsc hldrHSU2LpduUnit;
RVStateLpuU2Dsc arrHSU2LpduRVUnit[200] @ "DDR2_Bank1_2_variables";
RVStateLpuU0Dsc    hldrU0LpduRvUnit;

RVStateLpuU2Dsc    hldrU2LpduRvUnit;

RVStateLpuDbguDsc hldrDBGULpduRvUnit;
#pragma data_alignment=4
RVStateLpuSpiDsc  hldrSpiLpduUnit;// @ "Fast_variable";

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
unsigned long ulCtrTransmitLpduHSU2 = 0;




//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//typedef struct tag_
//{
	//.union {
    //.
	//.		unsigned char      arUch[8];//0  input Data  field
	//.		unsigned short     arUsh[4 ];//01 Key1 field
	//.		unsigned long int  arUl [2 ];//02 Key2 field 
	//.}UNFKeyField;//UNF-Union Field Bit - Total 64 bit
    //.
	//.union {
	//.		unsigned long ulReserv;  //0x Reserv fiel for future
	//.		
	//.}UNFReserv;//
	
//}StateLpuCn2Dsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

void ProcessReceiveLpdu(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&holderCn1LpduUnit;

i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
if (i==0) return;
hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;

((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;

pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
for (i = 0; i< j; i++)
pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 


}
void ProcessTransmitLpdu(void)
{
register long i,j;
register char *pSrc;//,*pDst;
register void* pv;
 pv  = (void*)&holderCn1LpduUnit;
  pSrc = (char*)&hldrTpCnState;
j =  ((StateTpLpuDsc*)pSrc)->uchTpState_CNL_1;//
 if (j==0) return;
((TRStateLpuCn1Dsc*)pv)->uchCI = HDR_MODE_CNL_1;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 1;


i = ((StateTpLpuDsc*)pSrc)->PayloadLPDU_CNL_1
 - ((StateTpLpuDsc*)pSrc)->lCapicity_CNL_1;
 ((TRStateLpuCn1Dsc*)pv)->lCapicity = i;
 
((StateTpLpuDsc*)pSrc)->lCapicity_CNL_1 =((StateTpLpuDsc*)pSrc)->PayloadLPDU_CNL_1;

}

long Eval_CS(char* pCh, long iLength )  @ "Fastest_function" //Fast_function"
{
//register long lCs;
register long i,n;
n = 1;
for (i = 0; i < iLength; i++)
{
	n +=  pCh[i];
}
n &= 0xff;

return n;
}

void ProcessReceiveLpdu_(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&holderCn1LpduUnit;

i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
if (i==0) return;
hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;

((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;

pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
for (i = 0; i< j; i++)
pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 


}


void ProcessReceiveLpduU3(void)
{
register long i,j;
//register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&hldrU3LpduUnit;

//.i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
i= ((RVStateLpuU3Dsc*)pv)->uchLpuU3State;//hldrU3LpduUnit. uchLpuU3State
if (i==0) return;
//.hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
//.hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
//.hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;
//long inU3(UNS_8 *buff, int bytes); (unsigned char*)
//---j = (long)(((RVStateLpuU3Dsc*)pv)->arUch[0]);
j = inU3(&(((RVStateLpuU3Dsc*)pv)->arUch[0]),SIZE_LPDU_CNL_U3);
sLV.ushSizeLDC = j;
//Clear LL Message income frome hardware 
if ((j ==0) || (j!=SIZE_LPDU_CNL_U3) ) goto f_exit;


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),j);
if (i!=(((RVStateLpuU3Dsc*)pv)->arUch[j])) goto f_exit;
//Check CFI 
if((((RVStateLpuU3Dsc*)pv)->arUch[0])!=(HDR_MODE_CNL_1)) goto f_exit;

//long inU7(UNS_8 *buff, int bytes);
//-dbg  ((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
//-dbg  ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
//-dbg  j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
//-dbg  ((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;


//-dbg pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
//-dbg for (i = 0; i< j; i++)
//-dbg pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 

//Activate Next Leyer.

f_exit:
return;
}

extern long hs_uart_recover(long);
extern int hs7_rxsize;
extern long hs7uartdev;
void ProcessReceiveLpduHSU7(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrHSU7LpduUnit;//holderCn1LpduUnit;
pDst = (char*)&hldrHSU7LpduUnit.arUch[0];//( ((RVStateLpuHSU7Dsc *)pv)->arUch[0]  );
//@sLV.ushSizeLDC = j = hs7_rxsize; 

//i = hs_uart_recover(hs7uartdev);

if (j<SIZE_LPDU_CNL_HSU7) 
{
//@	sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			//@i = hs7_rxsize;
			if (i > SIZE_LPDU_CNL_HSU7)
			{
				i-= SIZE_LPDU_CNL_HSU7;
				j = SIZE_LPDU_CNL_HSU7;
			}	
			else 
				j = i;
			//@sLV.uChIdxByte = inU7((unsigned char*)pDst,j);	
		}
		while(1);//@hs7_rxsize);
	
	}
//1<<24;


 
((RVStateLpuHSU7Dsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_1)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[1];

if (i>SIZE_LPDU_CNL_HSU7)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC = i;
 ((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_HSU7)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_HSU7)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuHSU7Dsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuHSU7Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU7Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU7Dsc *)pv)->lCs         = 0;
	
	((RVStateLpuHSU7Dsc *)pv)->uchLpuHSU7State = 0;
	return;
}
if (sLV.PacketGood)
{
	((RVStateLpuHSU7Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU7Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU7Dsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuHSU7Dsc *)pv)->uchLpuHSU7State = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;

}


}



void ProcessTransmitLpduHSU7(void)
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		//unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
 pv  = (void*)&hldrHSU7LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_HSU7;//
 if (j==0) return;
 
 
((TRStateLpuHSU7Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuHSU7Dsc*)pv)->uchLpuHSU7State = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7
+(SIZE_LDC_FLD_CNL_HSU7)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 //.i = 20;
 ((TRStateLpuHSU7Dsc*)pv)->lCapicity = i;//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuHSU7Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC = ((TRStateLpuHSU7Dsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuHSU7Dsc*)pv)->arUch[0]) = ((TRStateLpuHSU7Dsc*)pv)->uchCI;
i = ((TRStateLpuHSU7Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]) = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]);
		*((short*)pDst) = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU7;
////////////////////////////////////////////////////////
pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]); 

//sLV.uShIdxByte += SIZE_TOTAL_LDC;

j = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
((TRStateLpuHSU7Dsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuHSU7Dsc*)pv)->arUch[j]) = i;
//@j = outU7((unsigned char *)&(((TRStateLpuHSU7Dsc*)pv)->arUch[0]),(int)j+2);

Rst_LpduHSU7_TpCnState();
}

short shIdxLpduUnit = 0;

void ProcessTransmitLpduHSU2(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
 pv  = (void*)&hldrHSU2LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;
j =   ((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State;
if (j!=0) return;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_HSU2;//
 if (j==0) return;
 
#ifdef USE_PIO_SYNC
//Detect If Bs Rdy
	if((AT91C_BASE_PIOE->PIO_PDSR) & (1<<31) )
	;
	else
#ifdef BS_G45_FL_RL 	//no BS_G45_SRAM
	return ;;//
#else
	{j++;return ;}//<-Debug Code for control busy state If Pio Hdw Interface Worked
#endif
	 AT91C_BASE_PIOD->PIO_CODR = (1 << 29);
     // GPIO->p3_outp_clr = (1<<19);   
 #endif 
 
 
((TRStateLpuHSU2Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU2
+(SIZE_LDC_FLD_CNL_HSU2)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 //.i = 20;
 ((TRStateLpuHSU2Dsc*)pv)->lCapicity = i;//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuHSU2Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC = ((TRStateLpuHSU2Dsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuHSU2Dsc*)pv)->arUch[0]) = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]) = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);
		*((short*)pDst) = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU2;
////////////////////////////////////////////////////////
pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]); 

//sLV.uShIdxByte += SIZE_TOTAL_LDC;

j = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];
if(sLV.uShIdxByte>64)//hldrTpCnState.lCapicity_CNL_HSU2 <- Max Amount byte for Transmit
sLV.uShIdxByte = 64;

//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
((TRStateLpuHSU2Dsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuHSU2Dsc*)pv)->arUch[j]) = i;
//@j = outU2((unsigned char *)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]),(int)j+2);
 arrHSU2LpduTRUnit[shIdxLpduUnit++] = hldrHSU2LpduTRUnit;
 if (shIdxLpduUnit >= 200)
shIdxLpduUnit = 0;
 
 
j = outU2((unsigned char *)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]),(int)j+2);
ulCtrTransmitLpduHSU2++;

Rst_LpduHSU2_TpCnState();
}

extern char *DemoStr; 
void TestSetup_LpduHSU7_ForTransmit(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU7  = 1;
hldrTpCnState.PayloadLPDU_HSU7     = SIZE_LPDU_CNL_HSU7;
hldrTpCnState.lCapicity_CNL_HSU7   = SIZE_LPDU_CNL_HSU7 - 8;//Now sizeof str
hldrTpCnState.pUchLpuTR_CNL_HSU7   = (unsigned char*)DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU7 = 0;



hldrHSU7LpduTRUnit.uchLpuHSU7State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU7LpduTRUnit.lCapicity  = 0;//
hldrHSU7LpduTRUnit.uchCI      = 0;
hldrHSU7LpduTRUnit.ushSizeLDC = 0;
hldrHSU7LpduTRUnit.lCs        = 0;





}
void Rst_LpduHSU7_TpCnState(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU7  = 1;
hldrTpCnState.PayloadLPDU_HSU7     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU7   = SIZE_LPDU_CNL_HSU7// - 8;//Now sizeof str
-(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_CS_FLD_CNL_HSU7+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU7   = (unsigned char*)
&hldrHSU7LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU7 = 0;


hldrHSU7LpduTRUnit.uchLpuHSU7State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU7LpduTRUnit.lCapicity  = 0;//
hldrHSU7LpduTRUnit.uchCI      = 0;
hldrHSU7LpduTRUnit.ushSizeLDC = 0;
hldrHSU7LpduTRUnit.lCs        = 0;




}
void Rst_LpduHSU2_TpCnState(void)  @ "Fast_function"
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU2  = 0;
hldrTpCnState.PayloadLPDU_HSU2     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2// - 8;//Now sizeof str
-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)
&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU2 = 0;

lBlockHSU2Ctr = 0x1fffffff;
//hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU2LpduTRUnit.lCapicity  = 0;//
hldrHSU2LpduTRUnit.uchCI      = 0;
hldrHSU2LpduTRUnit.ushSizeLDC = 0;
hldrHSU2LpduTRUnit.lCs        = 0;




}
unsigned long uiAmtU2GoodPacket = 0; 
unsigned long uiAmtU2BadPacket = 0;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveLpduU2 (void);
extern volatile long rxsize_U2,rxfill_U2,rxget_U2; 
extern unsigned char *Prxbuff_U2;
extern long inU2(unsigned char *buff, long bytes);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU2 (void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU2LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU2LpduRvUnit.arUch[0];//
    //@sLV.ushSizeLDC = j = hs7_rxsize; 	
	sLV.ushSizeLDC = j = rxsize_U2; 	
	
	if (j<SIZE_LPDU_CNL_U2) 
	{
	//@	sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
	    sLV.uChIdxByte = InU2((unsigned char*)pDst,j);//inU2
	}
	else 
	{
		i = sLV.ushSizeLDC;
		if( i > ((SIZE_LPDU_CNL_U2)<<1) )
		{
			rxsize_U2 = rxget_U2 = rxfill_U2  = 0;sLV.PacketBad++;//situation when system can`t handle all data May be lose data on other channels
		}
		do
		{
			//@i = hs7_rxsize;
			i = rxsize_U2;
			if (i > SIZE_LPDU_CNL_U2)
			{
				i-= SIZE_LPDU_CNL_U2;
				j = SIZE_LPDU_CNL_U2;
			}	
			else 
				j = i;
			//@sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
			sLV.uChIdxByte = InU2((unsigned char*)pDst,j);//inU2
		}
		while(rxsize_U2);//@hs7_rxsize);//Clear Imput Buff
	
	}
	
	((RVStateLpuU2Dsc *)pv)->uchCI = i= pDst[0];
	
	if (i != HDR_MODE_CNL_1)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	i = pDst[1];
	
	if (i>SIZE_LPDU_CNL_U2)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	sLV.ushSizeLDC = ((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_U2)+(0)); //SIZE_LDC_FLD_CNL_HSU2
	if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_U2)+( 0)])//SIZE_LDC_FLD_CNL_HSU2
	{
	 sLV.PacketBad++;
	}
	else
	 sLV.PacketGood++;
	
	((RVStateLpuU2Dsc *)pv)->lCs = j; 
	
    if (sLV.PacketBad)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;
    	uiAmtU2BadPacket++;
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 0;
    	return;
    }
	if (sLV.PacketGood)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;	
    ;//Ativate Next Leyer
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 1;
    //...Now Use as Channel Identification	
    	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
    uiAmtU2GoodPacket++;
    }
	
 
}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void Rst_LpduHSU0_TpCnState(void)  @ "Fast_function"
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU2  = 0;
hldrTpCnState.PayloadLPDU_HSU2     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2// - 8;//Now sizeof str
-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)
&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU2 = 0;


hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU2LpduTRUnit.lCapicity  = 0;//
hldrHSU2LpduTRUnit.uchCI      = 0;
hldrHSU2LpduTRUnit.ushSizeLDC = 0;
hldrHSU2LpduTRUnit.lCs        = 0;




}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void Rst_LpduSpi_TpCnState(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void Rst_LpduSpi_TpCnState(void)  @ "Fast_function"
{

hldrTpCnState.uchTpState_CNL_Spi  = 0;
//----------------------------------------------------------
hldrTpCnState.PayloadLPDU_Spi     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_Spi   = SIZE_LPDU_CNL_SPI
-(SIZE_LPCI_FLD_CNL_SPI+SIZE_LDC_FLD_CNL_SPI+SIZE_CS_FLD_CNL_SPI+SIZE_TOTAL_LDC +2);//Size of 16 bit which lost every transmittion and always shift frame on 16 bit when work as slave
hldrTpCnState.pUchLpuTR_CNL_Spi   = (unsigned char*)
&hldrSpiLpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_SPI+SIZE_LDC_FLD_CNL_SPI+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_Spi = 0;

//---Update this var after the end of transmition+ timeOut 
//hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//-----------------------------------------------------------
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrSpiLpduTRUnit.lCapicity  = 0;//
hldrSpiLpduTRUnit.uchCI      = 0;
hldrSpiLpduTRUnit.ushSizeLDC = 0;
hldrSpiLpduTRUnit.lCs        = 0;




}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void Rst_LpduU2_TpCnState(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void Rst_LpduU2_TpCnState(void)  @ "Fast_function"
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 /*
 hldrTpCnState.uchTpState_CNL_U2  = 1;
 hldrTpCnState.PayloadLPDU_U2     = //SIZE_LPDU_CNL_HSU7
 0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
 hldrTpCnState.lCapicity_CNL_U2   = SIZE_LPDU_CNL_U2// - 8;//Now sizeof str
 -(SIZE_LPCI_FLD_CNL_U2+SIZE_LDC_FLD_CNL_U2+SIZE_CS_FLD_CNL_HSU7+SIZE_TOTAL_LDC );
 hldrTpCnState.pUchLpuTR_CNL_U2   = (unsigned char*)
 &hldrU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_U2+SIZE_LDC_FLD_CNL_U2+SIZE_TOTAL_LDC];//DemoStr;
 hldrTpCnState.chTotalLDC_CNL_U2 = 0;


 hldrU2LpduTRUnit.uchLpuU2State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
 hldrU2LpduTRUnit.lCapicity  = 0;//
 hldrU2LpduTRUnit.uchCI      = 0;
 hldrU2LpduTRUnit.ushSizeLDC = 0;
 hldrU2LpduTRUnit.lCs        = 0;
*/

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessTransmitLpduU2(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessTransmitLpduU2(void)  @ "Fast_function"
{
    register long i,j;
    register char *pSrc,*pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		//unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
    pv  = (void*)&hldrU2LpduTRUnit;
    pSrc = (char*)&hldrTpCnState;
j =   ((TRStateLpuU2Dsc*)pv)->uchLpuU2State;
if (j!=0) return;
    //Start for Activating of Lpdu Units 
    j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_U2;//
    if (j==0) return;
 
 
    ((TRStateLpuU2Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
    ((TRStateLpuU2Dsc*)pv)->uchLpuU2State = 1;


    i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_U2
    +(SIZE_LDC_FLD_CNL_U2)+(SIZE_TOTAL_LDC);
    // - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
     //.i = 20;
    ((TRStateLpuU2Dsc*)pv)->lCapicity = i;//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
    ((TRStateLpuU2Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
    ((TRStateLpuU2Dsc*)pv)->ushSizeLDC = ((TRStateLpuU2Dsc*)pv)->lCapicity;

    j = 0;
    (((TRStateLpuU2Dsc*)pv)->arUch[0]) = ((TRStateLpuU2Dsc*)pv)->uchCI;
    i = ((TRStateLpuU2Dsc*)pv)->uchCI;
    i &= 0xf;
    i>>=1;
	
    switch (i)
    	{
    	case 0:
    		j = 0;
    		break;
    	case 1:
    		
    		(((TRStateLpuU2Dsc*)pv)->arUch[j+1]) = ((TRStateLpuU2Dsc*)pv)->ushSizeLDC;
    		j = 1;
    		break;
    	case 2:
    	    pDst = (char*)&(((TRStateLpuU2Dsc*)pv)->arUch[j+1]);
    		*((short*)pDst) = ((TRStateLpuU2Dsc*)pv)->ushSizeLDC;
    		j = 2;
    		break;
    	
    	default:
    	j=1;
    	} 
    

    sLV.uShIdxByte = j;
    ///////////////////PUT TOT LDC FIELD////////////////////
    pDst = (char*)&(((TRStateLpuU2Dsc*)pv)->arUch[j+1]);
    *(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_U2;
    ////////////////////////////////////////////////////////
    pSrc = (char*)&arCh[0];//Tempor Data !!!
    pDst = (char*) &(((TRStateLpuU2Dsc*)pv)->arUch[j+1]); 

//sLV.uShIdxByte += SIZE_TOTAL_LDC;

    j = ((TRStateLpuU2Dsc*)pv)->ushSizeLDC;
    sLV.uShIdxByte += j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


   //Check CS
   //@i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
   i = Eval_CS((char*)&(((TRStateLpuU2Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
   ((TRStateLpuU2Dsc*)pv)-> lCs =  i;
   j = sLV.uShIdxByte;
   //Move Data to transmit
   (((TRStateLpuU2Dsc*)pv)->arUch[j]) = i;
//@j = outU7((unsigned char *)&(((TRStateLpuHSU7Dsc*)pv)->arUch[0]),(int)j+2);

Rst_LpduU2_TpCnState();
}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern long lSpi0HdwState;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
//extern void (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessTransmitLpduSpi(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
 pv  = (void*)&hldrSpiLpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

j = lSpi0HdwState & 4;  //
if (j == 0) 
   return;
j =   ((TRStateLpuSpiDsc*)pv)->uchLpuSpiState ;
if (j!=0) return;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_Spi;//
 if (j==0) return;
 
 
((TRStateLpuSpiDsc*)pv)->uchCI = HDR_MODE_CNL_SPI;//HDR_MODE_CNL_1;
((TRStateLpuSpiDsc*)pv)->uchLpuSpiState = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_Spi
+(SIZE_LDC_FLD_CNL_SPI)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 sLV.ushSizeLDC = i;
 ((TRStateLpuSpiDsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_SPI);//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuSpiDsc*)pv)->uchCI = (HDR_MODE_CNL_SPI);
((TRStateLpuSpiDsc*)pv)->ushSizeLDC = i;//((TRStateLpuSpiDsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuSpiDsc*)pv)->arUch[0]) = ((TRStateLpuSpiDsc*)pv)->uchCI;
i = ((TRStateLpuSpiDsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuSpiDsc*)pv)->arUch[j+1]) = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_Spi;
////////////////////////////////////////////////////////
//....pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);

//sLV.uShIdxByte += SIZE FIELD _TOTAL_LDC; .iNCLUDED IN ushSizeLDC

j = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += sLV.ushSizeLDC;//j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),((TRStateLpuSpiDsc*)pv)->lCapicity);//sLV.uShIdxByte);
((TRStateLpuSpiDsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
j = ((TRStateLpuSpiDsc*)pv)->lCapicity;
//Move Data to transmit
(((TRStateLpuSpiDsc*)pv)->arUch[j]) = i;

//j = outSpi0((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)

Rst_LpduSpi_TpCnState();
}


//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


extern char chNumPacetInBuf;
extern  volatile unsigned int bytesReceived;
extern unsigned char chEntry_U2;
char chOrderService = 0;unsigned short ushOffsetinRxbuff_U2 = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveLpduU2_T1(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU2_T1(void)  @ "Fast_function"
{
	register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU2LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU2LpduRvUnit.arUch[0];//
    //@sLV.ushSizeLDC = j = hs7_rxsize; 	
	sLV.ushSizeLDC = j = rxsize_U2; 	
	
	if (j<SIZE_LPDU_CNL_U2) 
	{
	//@	sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
	    sLV.uChIdxByte = InU2((unsigned char*)pDst,j);//inU2
		//Prxbuff_U2 =
	}
	else 
	{
		i = sLV.ushSizeLDC;
		sLV.uChIdxByte = InU2((unsigned char*)pDst, SIZE_LPDU_CNL_U2);//inU2
		ReInitInBufParam(); 
		 sLV.ushSizeLDC = SIZE_LPDU_CNL_U2;
	
	}
	
	((RVStateLpuU2Dsc *)pv)->uchCI = i= pDst[0];
	
	if (i != HDR_MODE_CNL_1)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	i = pDst[1];
	
	if (i>SIZE_LPDU_CNL_U2)
	 sLV.PacketBad++;
	else
	{
	 sLV.PacketGood++;
	 if (bytesReceived>sLV.ushSizeLDC)//SIZE_LPDU_CNL_U2)
	 {
		
		sLV.pUchRV = Prxbuff_U2;
		ushOffsetinRxbuff_U2  = (i+(SIZE_LPCI_FLD_CNL_U2)+(SIZE_CS_FLD_CNL_U2));//Detect Addr Next Pac In Buf
		sLV.pUchRV += ushOffsetinRxbuff_U2;
		while((*sLV.pUchRV != 0x82)&& sLV.uChIdxByte)
		{
		sLV.uChIdxByte--;sLV.pUchRV++;
		}
		ushOffsetinRxbuff_U2  = sLV.pUchRV - Prxbuff_U2;//Offset On Start Packet
	 }
	}
	sLV.ushSizeLDC = ((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_U2)+(SIZE_LDC_FLD_CNL_U2)); 
	if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_U2)+(SIZE_LDC_FLD_CNL_U2)])
	{
	 sLV.PacketBad++;
	}
	else
	 sLV.PacketGood++;
	
	((RVStateLpuU2Dsc *)pv)->lCs = j; 
	
    if (sLV.PacketBad)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;
    	
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 0;
    	return;
    }
	if (sLV.PacketGood)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;	
    ;//Ativate Next Leyer
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 1;
    //...Now Use as Channel Identification	
    	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
    
    }
}

//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveLpduU2_T2(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU2_T2 (void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU2LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU2LpduRvUnit.arUch[0];//
    //@sLV.ushSizeLDC = j = hs7_rxsize; 	
	sLV.ushSizeLDC = j = bytesReceived; 	
	
	if (j>SIZE_LPDU_CNL_U2) 
	{
	
	    //sLV.uChIdxByte = inU2((unsigned char*)pDst,j);
		sLV.ushSizeLDC = SIZE_LPDU_CNL_U2;
		//Fix Error System 
	}
	i = 0;j = (long)&Prxbuff_U2[0];j+= ushOffsetinRxbuff_U2;
	for(i = 0;i<sLV.ushSizeLDC;i++)
	{
		pDst[i] = ((char *)j)[i];//Prxbuff_U2[i];//
		 
	}
	//else 
	//{
	//	i = sLV.ushSizeLDC;
	//	
	//	do
	//	{
	//		//@i = hs7_rxsize;
	//		i = bytesReceived;
	//		if (i > SIZE_LPDU_CNL_U2)
	//		{
	//			i-= SIZE_LPDU_CNL_U2;
	//			j = SIZE_LPDU_CNL_U2;
	//		}	
	//		else 
	//			j = i;
	//		//@sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
	//		sLV.uChIdxByte = inU2((unsigned char*)pDst,j);
	//	}
	//	while(bytesReceived);//@hs7_rxsize);//Clear Imput Buff
	//
	//}
	ushOffsetinRxbuff_U2 = 0;
	((RVStateLpuU2Dsc *)pv)->uchCI = i= pDst[0];
	
	if (i != HDR_MODE_CNL_1)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	i = pDst[1];
	
	if (i>SIZE_LPDU_CNL_U2)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	sLV.ushSizeLDC = ((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	((RVStateLpuU2Dsc *)pv)->ushSizeLDC = i;
	j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_U2)+(SIZE_LDC_FLD_CNL_U2)); 
	if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_U2)+(SIZE_LDC_FLD_CNL_U2)])
	{
	 sLV.PacketBad++;
	}
	else
	 sLV.PacketGood++;
	
	((RVStateLpuU2Dsc *)pv)->lCs = j; 
	
    if (sLV.PacketBad)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;
    	
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 0;
    	return;
    }
	if (sLV.PacketGood)
    {
    	((RVStateLpuU2Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU2Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU2Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU2Dsc *)pv)->lCs         = 0;	
    ;//Ativate Next Leyer
    	((RVStateLpuU2Dsc *)pv)->uchLpuU2State = 1;
    //...Now Use as Channel Identification	
    	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
    
    }
	
 
}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveLpduU2_T(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU2_T(void)  @ "Fast_function"
{
if ( (hldrU2LpduRvUnit.uchLpuU2State > 0) )
{ 
	bytesReceived++;return;//Data Dont Hudled
}
//else
	
	if( (chNumPacetInBuf ==0) )
	{
		ProcessReceiveLpduU2();
		chNumPacetInBuf = 0;
		chEntry_U2 = 0;
		return;//Fix Hrdw Error
	}
		//Detect One Pac Or MOre
	if( (chNumPacetInBuf ==1) )
	{
		
		ProcessReceiveLpduU2();
		chNumPacetInBuf--;
		chEntry_U2 = 0;

	}
	else
	{
		if(chOrderService==0)
		chOrderService = chNumPacetInBuf;
		if (chOrderService>2) 
		chOrderService = 2;
		//Detect Order Extraction
		switch (chOrderService)
		{
			case 2:
			ProcessReceiveLpduU2_T1();
			chOrderService--;
			break;
			case 1:
			ProcessReceiveLpduU2_T2();
			chNumPacetInBuf = 0;
			chOrderService = 0;
			chEntry_U2 = 0;
			break;
		default:
		;
		
		}
		//Extract Previous
		
	
	}

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

unsigned long uiAmtSpiGoodPacket = 0; 
unsigned long uiAmtSpiBadPacket = 0;


extern unsigned char chEntry_Spi0;
static char chTotalBadPacketCtr = 0;
static long lAmtCallReInitDmaSpi = 0;
extern long lSpi0HdwState;
extern volatile  long spi0_txsize, spi0_rxsize,spi0_rxget,spi0_rxfill;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
//extern void (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduSpi(void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrSpiLpduUnit;//hldrHSU2LpduUnit;//
pDst = (char*)&hldrSpiLpduUnit.arUch[0];//
sLV.ushSizeLDC = j = spi0_rxsize;//Cy7_rxsize; SIZE_LPDU_CNL_SPI
//goto ExitProcessReceiveLpduSpi;
if (j<SIZE_LPDU_CNL_SPI) 
{
	sLV.uChIdxByte = inSpi0((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		if( i > ((SIZE_LPDU_CNL_SPI)<<1) )
		{
			spi0_rxsize = spi0_rxget = spi0_rxfill = 0;//rxsize_U2 = rxget_U2 = rxfill_U2  = 0;
			sLV.PacketBad++;//situation when system can`t handle all data May be lose data on other channels
		}
		do
		{
			i = spi0_rxsize;//Cy7_rxsize;
			if (i > SIZE_LPDU_CNL_SPI)
			{
				i-= SIZE_LPDU_CNL_SPI;
				j = SIZE_LPDU_CNL_SPI;
			}	
			else 
				j = i;
			sLV.uChIdxByte = InSpi0((unsigned char*)pDst,j);//sLV.uChIdxByte = inSpi0((unsigned char*)pDst,j);	
		}
		while(spi0_rxsize);//Total erroneus algorithm for hundling SPI data
		 
	} 
 
 
((RVStateLpuSpiDsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_SPI)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[2];
i <<= 8;
i|= pDst[1];

if (i>SIZE_LPDU_CNL_SPI)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuSpiDsc *)pv)->ushSizeLDC = i;
// ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_SPI)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_SPI)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuSpiDsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuSpiDsc *)pv)->lCapicity   = 0;
	((RVStateLpuSpiDsc *)pv)->uchCI       = 0;
	((RVStateLpuSpiDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuSpiDsc *)pv)->lCs         = 0;
	
	((RVStateLpuSpiDsc *)pv)->uchLpuSpiState = 0;
	uiAmtSpiBadPacket++;
	
	if(sLV.PacketBad >= 2)//Need use 2 not 3 because if size 0 - this Interpret as good size
	chTotalBadPacketCtr++;
	if (chTotalBadPacketCtr > 3)//03)
	{
		//ReInit Spi Channel
		chTotalBadPacketCtr = 0;//chEntry_Spi0 = 1;
		Spi0HdwRstAndDmac();
		//```Spi0HdwRst();//..~lSpi0HdwState = 0;<-Prev Code
		//..~Spi0_Rst();
		uiAmtSpiGoodPacket = 0;
		uiAmtSpiBadPacket  = 0;
		lAmtCallReInitDmaSpi++;
		
		return;
	}
		goto ExitProcessReceiveLpduSpi;//return;
}
if (sLV.PacketGood)
{
	((RVStateLpuSpiDsc *)pv)->lCapicity   = 0;
	((RVStateLpuSpiDsc *)pv)->uchCI       = 0;
	((RVStateLpuSpiDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuSpiDsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuSpiDsc *)pv)->uchLpuSpiState = 1;
//...Now Use as Channel Identification	
	// ((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
	chTotalBadPacketCtr = 0;
	uiAmtSpiGoodPacket++;
	//GossBRvPackActivator();

}
ExitProcessReceiveLpduSpi:
	//i = outSpi0((unsigned char *)&hldrSpiLpduTRUnit.arUch[0],SIZE_LPDU_CNL_SPI);
	i = OutSpi0((unsigned char *)&hldrSpiLpduTRUnit.arUch[0],SIZE_LPDU_CNL_SPI);
	hldrSpiLpduTRUnit.uchLpuSpiState = 0;timerWaitReqSpi = 6;//10 <- This was a problem !?1
	//Clear Header
	hldrSpiLpduTRUnit.arUch[0] = 0;hldrSpiLpduTRUnit.arUch[1] = 0;
	//EnblGSpiInt();
	//Init Dma Data for Transmit
    ReInitDmacChnl01();





}

//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern long lSpi0HdwState;

void ProcessTransmitStubSeqSpi(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
//.struct 
//.	{
//.		//unsigned char uchTR_C;
//.		unsigned short uShIdxByte ;
//.		unsigned short ushSizeLDC;
//.		//unsigned char *pUchRV;
//.	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
//Control state Connect   
j = lSpi0HdwState & 4;  //
if (j == 0) 
return;
 pv  = (void*)&hldrSpiLpduTRUnit;
  pSrc = (char*)&hldrTpCnState;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_Spi;//
 if (j!=0) return;

j =   ((TRStateLpuSpiDsc*)pv)->uchLpuSpiState ;
if (j!=0) return;//Transmittion Active


if(timerWaitReqSpi>0&& timerWaitReqSpi<20)//timerWaitReq
{
	timerWaitReqSpi--;
	return;
}

((TRStateLpuSpiDsc*)pv)->uchCI = HDR_MODE_CNL_SPI;//HDR_MODE_CNL_1;
((TRStateLpuSpiDsc*)pv)->uchLpuSpiState = 1;


i = 0//((StateTpCnDsc*)pSrc)->PayloadLPDU_Spi
+(SIZE_LDC_FLD_CNL_SPI)+(SIZE_TOTAL_LDC);
// 
//. sLV.ushSizeLDC = i;
 ((TRStateLpuSpiDsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_SPI);//Real Size Pacet
 


//Create Pacet
((TRStateLpuSpiDsc*)pv)->uchCI = (HDR_MODE_CNL_SPI);
((TRStateLpuSpiDsc*)pv)->ushSizeLDC = i;//((TRStateLpuSpiDsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuSpiDsc*)pv)->arUch[0]) = ((TRStateLpuSpiDsc*)pv)->uchCI;
i = ((TRStateLpuSpiDsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuSpiDsc*)pv)->arUch[j+1]) = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
*(pDst) = 0;//((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_Spi;
////////////////////////////////////////////////////////
#ifdef  BS_G45_FL_RL
pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]);
for( i = 5; i<(510>>1); i++)
*((short*)pDst +i) = i+10;  
#endif 	
	

//Check CS
i = Eval_CS((char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),((TRStateLpuSpiDsc*)pv)->lCapicity);// sLV.uShIdxByte);
((TRStateLpuSpiDsc*)pv)-> lCs =  i;

j = ((TRStateLpuSpiDsc*)pv)->lCapicity;
//Move Data to transmit
(((TRStateLpuSpiDsc*)pv)->arUch[j]) = i;
//...j = outSPI1((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)

Rst_LpduSpi_TpCnState();
}

extern long outU0(unsigned char *dat,  long bytes);
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
//extern void (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessTransmitLpduU0(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		//unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
 pv  = (void*)&hldrU0LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)-> uchTpState_CNL_U0;//uchTpState_CNL_HSU2;//
 if (j==0) return;
 
 
((TRStateLpuU0Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuU0Dsc*)pv)->uchLpuU0State = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_U0
+(SIZE_LDC_FLD_CNL_HSU2)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 //.i = 20;
 ((TRStateLpuU0Dsc*)pv)->lCapicity = i;//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuU0Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuU0Dsc*)pv)->ushSizeLDC = ((TRStateLpuU0Dsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuU0Dsc*)pv)->arUch[0]) = ((TRStateLpuU0Dsc*)pv)->uchCI;
i = ((TRStateLpuU0Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuU0Dsc*)pv)->arUch[j+1]) = ((TRStateLpuU0Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuU0Dsc*)pv)->arUch[j+1]);
		*((short*)pDst) = ((TRStateLpuU0Dsc*)pv)->ushSizeLDC;
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuU0Dsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU2;
////////////////////////////////////////////////////////
pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuU0Dsc*)pv)->arUch[j+1]); 

//sLV.uShIdxByte += SIZE_TOTAL_LDC;

j = ((TRStateLpuU0Dsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((TRStateLpuU0Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
((TRStateLpuU0Dsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuU0Dsc*)pv)->arUch[j]) = i;
//@j = outU2((unsigned char *)&(((TRStateLpuU0Dsc*)pv)->arUch[0]),(int)j+2);
j = outU0((unsigned char *)&(((TRStateLpuU0Dsc*)pv)->arUch[0]),(int)j+2);
Rst_LpduHSU0_TpCnState();
}

//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern void ProcessReceiveLpduU0 (void);
extern volatile long rxsize_U0; 
extern unsigned char *Prxbuff_U0;
extern long outU0(unsigned char *dat,  long bytes);
extern long inU0 (unsigned char *buff, long bytes);
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
//extern void (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU0 (void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU0LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU0LpduRvUnit.arUch[0];//
    //@sLV.ushSizeLDC = j = hs7_rxsize; 	
	sLV.ushSizeLDC = j = rxsize_U0; 	
	
	if (j<SIZE_LPDU_CNL_U0) 
	{
	//@	sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
	    sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
	}
	else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			//@i = hs7_rxsize;
			i = rxsize_U0;
			if (i > SIZE_LPDU_CNL_U0)
			{
				i-= SIZE_LPDU_CNL_U0;
				j = SIZE_LPDU_CNL_U0;
			}	
			else 
				j = i;
			//@sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
			sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
		}
		while(rxsize_U0);//@hs7_rxsize);//Clear Imput Buff
	
	}
	
	((RVStateLpuU0Dsc *)pv)->uchCI = i= pDst[0];
	
	if (i != HDR_MODE_CNL_1)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	i = pDst[1];
	
	if (i>SIZE_LPDU_CNL_U0)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	sLV.ushSizeLDC = ((RVStateLpuU0Dsc *)pv)->ushSizeLDC = i;
	((RVStateLpuU0Dsc *)pv)->ushSizeLDC = i;
	j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_U0)+(0)); //SIZE_LDC_FLD_CNL_HSU2
	if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_U0)+( 0)])//SIZE_LDC_FLD_CNL_HSU2
	{
	 sLV.PacketBad++;
	}
	else
	 sLV.PacketGood++;
	
	((RVStateLpuU0Dsc *)pv)->lCs = j; 
	
    if (sLV.PacketBad)
    {
    	((RVStateLpuU0Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU0Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU0Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU0Dsc *)pv)->lCs         = 0;
    	
    	((RVStateLpuU0Dsc *)pv)->uchLpuU0State = 0;
    	return;
    }
	if (sLV.PacketGood)
    {
    	((RVStateLpuU0Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU0Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU0Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU0Dsc *)pv)->lCs         = 0;	
    ;//Ativate Next Leyer
    	((RVStateLpuU0Dsc *)pv)->uchLpuU0State = 1;
    //...Now Use as Channel Identification	
    	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
    
    }
	
 
}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern char chNumPacetInBufU0; 
extern unsigned char *Prxbuff_U0; 
extern unsigned char chEntry_U0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveLpduU0_T(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveLpduU0_T(void)
{

if ( (hldrU0LpduRvUnit.uchLpuU0State > 0) ) 
	return;//Data Dont Hudled
	if( (chNumPacetInBufU0 ==0) )
	{
		ProcessReceiveLpduU0();
		chNumPacetInBufU0 = 0;
		chEntry_U0 = 0;
		return;//Fix Hrdw Error
	}
		//Detect One Pac Or MOre
	if( (chNumPacetInBufU0 ==1) )
	{
		
		ProcessReceiveLpduU0();
		chNumPacetInBufU0--;
		chEntry_U0 = 0;

	}
	else
	{
		/*if(chOrderService==0)
		chOrderService = chNumPacetInBufU0;
		if (chOrderService>2) 
		chOrderService = 2;
		//Detect Order Extraction
		switch (chOrderService)
		{
			case 2:
			ProcessReceiveLpduU2_T1();
			chOrderService--;
			break;
			case 1:
			ProcessReceiveLpduU2_T2();
			chNumPacetInBufU0 = 0;
			chOrderService = 0;
			chEntry_U2 = 0;
			break;
		default:
		;
		
		}
		//Extract Previous
		*/
	
	}

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
unsigned long uiAmtU0GoodPacket = 0; 
unsigned long uiAmtU0BadPacket = 0;

extern unsigned char chEntry_U0;
//extern long rxsize_U0;
extern long rxfill_U0;
extern long rxget_U0; 
#include    "SmpWrp.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
long ProcessReceiveLpduRvU0 (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
long ProcessReceiveLpduRvU0 (void)  @ "Fastest_function" //Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU0LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU0LpduRvUnit.arUch[0];//

	
	
	
	((RVStateLpuU0Dsc *)pv)->uchCI = i= pDst[0];
	
	if (i != HDR_MODE_CNL_1)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	i = pDst[1];
	
	if (i>SIZE_LPDU_CNL_U0)
	 sLV.PacketBad++;
	else
	 sLV.PacketGood++;
	
	sLV.ushSizeLDC = ((RVStateLpuU0Dsc *)pv)->ushSizeLDC = i;
	((RVStateLpuU0Dsc *)pv)->ushSizeLDC = i;
	j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_U0)+(0)); //SIZE_LDC_FLD_CNL_HSU2
	if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_U0)+( 0)])//SIZE_LDC_FLD_CNL_HSU2
	{
	 sLV.PacketBad++;
	}
	else
	 sLV.PacketGood++;
	
	((RVStateLpuU0Dsc *)pv)->lCs = j; 
	
    if (sLV.PacketBad)
    {
    	((RVStateLpuU0Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU0Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU0Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU0Dsc *)pv)->lCs         = 0;
    	uiAmtU0BadPacket++;//holderRawSampl.statistics.lTotalBadChange++;
    	((RVStateLpuU0Dsc *)pv)->uchLpuU0State = 0;
    	return 0;
    }
	if (sLV.PacketGood)
    {
    	((RVStateLpuU0Dsc *)pv)->lCapicity   = 0;
    	((RVStateLpuU0Dsc *)pv)->uchCI       = 0;
    	((RVStateLpuU0Dsc *)pv)->ushSizeLDC  = 0;
    	((RVStateLpuU0Dsc *)pv)->lCs         = 0;	
    ;//Ativate Next Leyer
    	((RVStateLpuU0Dsc *)pv)->uchLpuU0State = 1;
    //...Now Use as Channel Identification	
    	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
		sLV.ushSizeLDC += (SIZE_LPCI_FLD_CNL_U0) + ( SIZE_CS_FLD_CNL_U0 );
		uiAmtU0GoodPacket++;
    
    }
	return sLV.ushSizeLDC;
 
}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveQueueU0(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~ chEntry_U0
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveQueueU0(void)   @ "Fastest_function" //Fast_function"
{

    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		unsigned short ushByteRead, ushByteLpduU0;
		unsigned short ushByteWaitInBuf,ushRxGet;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	 sLV.ushByteRead = sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU0LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU0LpduRvUnit.arUch[0];//
	
if ( (hldrU0LpduRvUnit.uchLpuU0State > 0) ) //Attention uchLpuU0State is a signal that High Leyer hundled all his data
	return;//Data Dont Hudled 	
	
	if (rxfill_U0 > rxget_U0 )
	sLV. ushByteWaitInBuf = rxfill_U0 - rxget_U0;//Distance 1
	if (rxfill_U0 < rxget_U0 )
	 sLV.ushByteWaitInBuf = (rxfill_U0+512)- rxget_U0;//Distance 2
	 
	//Copare Distance between rxsize_U0 and i = (rxfill_U0 - rxget_U0)
	if (sLV.ushByteWaitInBuf > rxsize_U0)
	{
		//Detect Type LDC
		sLV.ushSizeLDC = j = sLV.ushByteWaitInBuf;//rxsize_U0;
	}	
	if (sLV.ushByteWaitInBuf <= rxsize_U0)
	{
	sLV.ushSizeLDC = j = rxsize_U0;
	}
	//Calc size need for extraction data whith overloading
	if (j<SIZE_LPDU_CNL_U0) 
	{
	
	    //..sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
		//Detect Differ 
		for(i = 0; i <j; i++)
		{
			pDst[i] = Prxbuff_U0[rxget_U0];		
			rxget_U0++;
			if (rxget_U0 >= 512)
			{
			rxget_U0 = 0;
			}
		}	
		IRQ_DisableIT(AT91C_ID_US0);
		if (rxsize_U0 < j)
			rxsize_U0 = 0;
		else
			rxsize_U0 -= j;
		
		if (rxfill_U0 == rxget_U0)
		rxfill_U0 = rxget_U0 = 0;//all must be Zero
		IRQ_EnableIT(AT91C_ID_US0);
		j = ProcessReceiveLpduRvU0();
		chEntry_U0 = 0;//Handle All Data
	}
	else 
	{
		//i = sLV.ushSizeLDC;
		sLV.ushByteRead = sLV.ushRxGet = 0;
		do
		{
			
			i = sLV.ushByteWaitInBuf;//rxsize_U0;
			if (i > SIZE_LPDU_CNL_U0)
			{
				//i-= SIZE_LPDU_CNL_U0;
				j = SIZE_LPDU_CNL_U0;
			}	
			else 
				j = i;
			//	
			sLV.ushRxGet = rxget_U0;
			//sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
			for(i = 0; i <j; i++)
		    {
		    	pDst[i] = Prxbuff_U0[sLV.ushRxGet];		
		    	sLV.ushRxGet++;
		    	if (sLV.ushRxGet >= 512)
		    	{
					sLV.ushRxGet = 0;
		    	}
		    }	
			//Scan Pacet If Ok Exit Else
			sLV.ushByteLpduU0 = ProcessReceiveLpduRvU0();
			if(sLV.ushByteLpduU0 )
			{
				sLV.ushByteWaitInBuf -= sLV.ushByteLpduU0;
				sLV.ushRxGet = rxget_U0 + sLV.ushByteLpduU0;
				if (sLV.ushRxGet >= 512)
				rxget_U0 = sLV.ushRxGet - 512;// Real Read Size
				else 
					rxget_U0 = sLV.ushRxGet;
				sLV.ushByteRead += sLV.ushByteLpduU0;
			}
			else
				{
				sLV.ushByteWaitInBuf -= j;
				if (sLV.ushRxGet >= 512)
					rxget_U0 = sLV.ushRxGet - 512;// Real Read Size
				else 
					rxget_U0 = sLV.ushRxGet;
				sLV.ushByteRead += j;
				}
			
		}
		while((sLV.ushByteLpduU0 == 0) && (sLV.ushByteWaitInBuf>0) );//  
		
			IRQ_DisableIT(AT91C_ID_US0);
			if (rxsize_U0 < sLV.ushByteRead)
				rxsize_U0 = 0;
			else
				rxsize_U0 -= sLV.ushByteRead;
			
			if (rxfill_U0 == rxget_U0)
			rxfill_U0 = rxget_U0 = 0;//all must be Zero
			
			IRQ_EnableIT(AT91C_ID_US0);
			if (sLV.ushByteWaitInBuf == 0) 
			chEntry_U0 = 0;
	
	}
	
	
	
	

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ProcessReceiveQueueU0_V0(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~ chEntry_U0
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessReceiveQueueU0_V0(void)   @ "Fast_function" //Fast_function"
{

    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		unsigned short ushByteRead, ushByteLpduU0;
		unsigned short ushByteWaitInBuf,ushRxGet;
		//unsigned char *pUchRV;
		
		
	} sLV;	
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	 sLV.ushByteRead = sLV.uChIdxByte = sLV.ushSizeLDC = 0;
	
    pv  = (void*)&hldrU0LpduRvUnit;//holderCn1LpduUnit;
    pDst = (char*)&hldrU0LpduRvUnit.arUch[0];//
	
if ( (hldrU0LpduRvUnit.uchLpuU0State > 0) ) //Attention uchLpuU0State is a signal that High Leyer hundled all his data
	return;//Data Dont Hudled 	
IRQ_DisableIT(AT91C_ID_US0);	
	if (rxfill_U0 > rxget_U0 )
	sLV. ushByteWaitInBuf = rxfill_U0 - rxget_U0;//Distance 1
	if (rxfill_U0 < rxget_U0 )
	 sLV.ushByteWaitInBuf = (rxfill_U0+512)- rxget_U0;//Distance 2
	 
	//Copare Distance between rxsize_U0 and i = (rxfill_U0 - rxget_U0)
	if (sLV.ushByteWaitInBuf > rxsize_U0)
	{
		//Detect Type LDC
		sLV.ushSizeLDC = j = sLV.ushByteWaitInBuf;//rxsize_U0;
	}	
	if (sLV.ushByteWaitInBuf <= rxsize_U0)
	{
	sLV.ushSizeLDC = j = rxsize_U0;
	}
	//Calc size need for extraction data whith overloading
	if (j<SIZE_LPDU_CNL_U0) 
	{
	
	    //..sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
		if((rxget_U0+j)> 512)
		{
		//Detect Differ 
		    //.for(i = 0; i <j; i++)
		    //.{
		    //.	pDst[i] = Prxbuff_U0[rxget_U0];		
		    //.	rxget_U0++;
		    //.	if (rxget_U0 >= 512)
		    //.	{
		    //.	rxget_U0 = 0;
		    //.	}
		    //.}
			sLV.uChIdxByte = (512-rxget_U0);
			memcpy((void*)pDst,(const void *)(Prxbuff_U0+ rxget_U0),(size_t)sLV.uChIdxByte);
			memcpy((void*)(pDst + sLV.uChIdxByte),(const void *)(Prxbuff_U0+ 0),(size_t)(j - sLV.uChIdxByte));
			rxget_U0 = j - sLV.uChIdxByte;
		}	
		else
		{
			memcpy((void*)pDst,(const void *)(Prxbuff_U0+ rxget_U0),(size_t)j);
			rxget_U0 += j;
		}	
		//.IRQ_DisableIT(AT91C_ID_US0);
		if (rxsize_U0 < j)
			rxsize_U0 = 0;
		else
			rxsize_U0 -= j;
		
		if (rxfill_U0 == rxget_U0)
		rxfill_U0 = rxget_U0 = 0;//all must be Zero
		IRQ_EnableIT(AT91C_ID_US0);
		j = ProcessReceiveLpduRvU0();
		chEntry_U0 = 0;//Handle All Data
	}
	else 
	{
		//i = sLV.ushSizeLDC;
		sLV.ushByteRead = sLV.ushRxGet = 0;
		do
		{
			
			i = sLV.ushByteWaitInBuf;//rxsize_U0;
			if (i > SIZE_LPDU_CNL_U0)
			{
				//i-= SIZE_LPDU_CNL_U0;
				j = SIZE_LPDU_CNL_U0;
			}	
			else 
				j = i;
			//	
			sLV.ushRxGet = rxget_U0;
			//sLV.uChIdxByte = inU0((unsigned char*)pDst,j);
			for(i = 0; i <j; i++)
		    {
		    	pDst[i] = Prxbuff_U0[sLV.ushRxGet];		
		    	sLV.ushRxGet++;
		    	if (sLV.ushRxGet >= 512)
		    	{
					sLV.ushRxGet = 0;
		    	}
		    }	
			//Scan Pacet If Ok Exit Else
			sLV.ushByteLpduU0 = ProcessReceiveLpduRvU0();
			if(sLV.ushByteLpduU0 )
			{
				sLV.ushByteWaitInBuf -= sLV.ushByteLpduU0;
				sLV.ushRxGet = rxget_U0 + sLV.ushByteLpduU0;
				if (sLV.ushRxGet >= 512)
				rxget_U0 = sLV.ushRxGet - 512;// Real Read Size
				else 
					rxget_U0 = sLV.ushRxGet;
				sLV.ushByteRead += sLV.ushByteLpduU0;
			}
			else
				{
				sLV.ushByteWaitInBuf -= j;
				if (sLV.ushRxGet >= 512)
					rxget_U0 = sLV.ushRxGet - 512;// Real Read Size
				else 
					rxget_U0 = sLV.ushRxGet;
				sLV.ushByteRead += j;
				}
			
		}
		while((sLV.ushByteLpduU0 == 0) && (sLV.ushByteWaitInBuf>0) );//  
		
			//.IRQ_DisableIT(AT91C_ID_US0);
			if (rxsize_U0 < sLV.ushByteRead)
				rxsize_U0 = 0;
			else
				rxsize_U0 -= sLV.ushByteRead;
			
			if (rxfill_U0 == rxget_U0)
			rxfill_U0 = rxget_U0 = 0;//all must be Zero
			
			IRQ_EnableIT(AT91C_ID_US0);
			if (sLV.ushByteWaitInBuf == 0) 
			chEntry_U0 = 0;
	
	}
	
	
	
	

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""





#define SIZE_LPDU_CNL_HSU2_CMM 64
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
void ProcessTransmitStubSeqUart(void)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ProcessTransmitStubSeqUart(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
//Control state Connect   

 pv  = (void*)&hldrHSU2LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;
//Start for Activating of Lpdu Units 
j =   ((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State ;
if (j!=0) return;

j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_HSU2;//
 if (j==0) return;

#ifdef USE_PIO_SYNC
//Detect If Bs Rdy
	if((AT91C_BASE_PIOE->PIO_PDSR) & (1<<31) )
	;
	else
#ifdef BS_G45_FL_RL 	//no BS_G45_SRAM
	return ;;//
#else
	{j++;return ;}//<-Debug Code for control busy state If Pio Hdw Interface Worked
#endif
	 AT91C_BASE_PIOD->PIO_CODR = (1 << 29);
     // GPIO->p3_outp_clr = (1<<19);   
 #endif 
 
 
((TRStateLpuHSU2Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State = 1;


//`i = hldrTpCnState.lCapicity_CNL_HSU2//((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU2
//`+(SIZE_LDC_FLD_CNL_HSU2)+(SIZE_TOTAL_LDC);
i = SIZE_LPDU_CNL_HSU2_CMM - (SIZE_LPCI_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2);

// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 sLV.ushSizeLDC = i;
 ((TRStateLpuHSU2Dsc*)pv)->lCapicity = 
 SIZE_LPDU_CNL_HSU2_CMM- SIZE_CS_FLD_CNL_HSU2;//Real Size Pacet
 


//Create Pacet
((TRStateLpuHSU2Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC = i;

j = 0;
(((TRStateLpuHSU2Dsc*)pv)->arUch[0]) = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]) = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	     pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);//pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;//((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 
sLV.uShIdxByte = j;	
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);//pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
*(pDst) = 0;//((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU2;
////////////////////////////////////////////////////////
pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]);// <-- Test Code for Generation Num Seq in Buff
unnV1.uchAr[2] = (SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
for( i = unnV1.uchAr[2] ; i<(SIZE_LPDU_CNL_HSU2_CMM-SIZE_CS_FLD_CNL_HSU2); i++)
  pDst[i]  =  i+41;  //*((short*)pDst +i) = i+21;    
	
sLV.uShIdxByte += sLV.ushSizeLDC;//j;
	

//Check CS
i = Eval_CS((char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]),((TRStateLpuHSU2Dsc*)pv)->lCapicity);// sLV.uShIdxByte);
((TRStateLpuHSU2Dsc*)pv)-> lCs =  i;

j = ((TRStateLpuHSU2Dsc*)pv)->lCapicity;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuHSU2Dsc*)pv)->arUch[j]) = i;
j = outU2((unsigned char *)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]),(int)j+(SIZE_CS_FLD_CNL_HSU2));
ulCtrTransmitLpduHSU2++;

Rst_LpduHSU2_TpCnState();

}
 
//----------------------------------------------------------------------------------


//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
//extern void (void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================

//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""









/* EOF */



