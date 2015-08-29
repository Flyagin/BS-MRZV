
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
* Processor       :  at91sam9g45
* File Name       : srvUO.h
* Description     : support for the srvUO.h
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  22/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef SERVICE_URGENT_OBJ_h
#define SERVICE_URGENT_OBJ_h

extern char chBsFCoilState;
extern char chBsDateTimeState;
extern char chBsCmdState;

extern  short shbsUrgObjIciCallState ;//RQ Var
extern  short shbsUrgObjIciUsedState ;//Lock Var

//Dlya obespecheniya vzaimoiscl predlagaetsya ispolzovat local copy var esli posle obrabotki 
//localnaya i globalinaya copii sovpadayut nebilo conflicta esli net to bil i  
extern   short shbsIciUrgObjIciCallState;
#define BS_URG_OBJ_ICI_CALL_VAR_USED_BIT         (0)
//-Бит указывающий что ресурс shbsUrgObjIciCallState занят и меняется
#define  RQ_WR_FCOIL_BIT                        (2)
//-Бит запроса на запись к shbsUrgObjIciCallState
#define RQ_WR_DATE_TIME_BIT                     (3)
//-Бит запроса на запись к shbsUrgObjIciCallState
#define RQ_WR_CMD_BIT                           (4)



//-#define RQ_WR_UNIT1_BIT       (3)
//-//-Бит запроса на запись к shbsUrgObjIciCallState
//-#define RQ_RD_UNI2_BIT       (4)


#define BS_USED_BIT         (1)
//-Бит указывающий что ресурс занят и меняется
#define BS_WR_END_BIT       (2)
//-Бит указывающий что ресурс был XX системой обслуживания 
//Bit succesful writing
#define BS_WR_BIT       (3)
//-Бит запроса на запись к  системе обслуживания ICI


#define BS_USED_ONB          BS_USED_BIT

#define BS_WR_END_ONB        BS_WR_END_BIT 

#define BS_WR_ONB            BS_WR_BIT 


#define BS_USED_MSK     (1<< BS_USED_ONB  )

#define BS_WR_END_MSK   (1<< BS_WR_END_ONB  )

#define  BS_WR_MSK      (1<< BS_WR_ONB     )



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//~#define BS_DATE_TIME_USED_BIT         (1)
//~//-Бит указывающий что ресурс занят и меняется
//~#define BS_WR_END_ DATE_TIME_BIT       (2)
//~//-Бит указывающий что ресурс был XX системой обслуживания 
//~//Bit succesful writing
//~#define BS_DATE_TIME_WR_BIT       (3)
//~//-Бит запроса на запись к  системе обслуживания ICI
//~
//~
//~#define BS_DATE_TIME_USED_ONB          BS_DATE_TIME_USED_BIT
//~
//~#define BS_WR_END_DATE_TIME_ONB        BS_WR_END_DATE_TIME_BIT 
//~
//~#define BS_DATE_TIME_WR_ONB            BS_DATE_TIME_WR_BIT 
//~
//~
//~#define BS_DATE_TIME_USED_MSK     (1<< BS_DATE_TIME_USED_ONB  )
//~
//~#define BS_WR_END_DATE_TIME_MSK   (1<< BS_WR_END_DATE_TIME_ONB  )
//~
//~#define  BS_DATE_TIME_WR_MSK       (1<< BS_DATE_TIME_WR_ONB     )



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef BR_SET_IN_OUT
#define  BR_SET_IN_OUT
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_IN  32
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_OUT 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````


#define AMOUNT_BYTE_FOR_IN            (((NUM_IN)>>3) ) //+1) 

#define AMOUNT_BYTE_FOR_OUT           (((NUM_OUT)>>3)) // +1) 


typedef struct BrSetInOutDsc_TagIn
{
	char  chArIn    [AMOUNT_BYTE_FOR_IN ];
	char  chArOut   [AMOUNT_BYTE_FOR_OUT];
	
	char  chAr[4];//ID_Activator -  Who generate command or it may be Adress IEC
	//char  chArWrp[SIZE_WRP_];//
	
	
}BrSetInOutDsc;

#endif
extern BrSetInOutDsc hldBrSetInOut;

extern void ServiceBsTrUrgObjStates(void);




#endif //SERVICE_URGENT_OBJ_h

















