#include    "kbddrv.h"
#include    "pio/pio.h"
#include    "constants_twi.h"
#include    "../inc/ici_ef.h"
#include "header_mal.h"


unsigned int SMKeyChange;
unsigned int SMScanCode;
unsigned int CurScanCode;
unsigned char SMKeyPress1 = 0;
//unsigned char chKeyPressGlb = 0;
extern unsigned int SPIOperationTable;
unsigned long arOutsAddr[6] = {
  0xFFFFF400, //PIO B 
  0xFFFFF400, //PIO B
  0xFFFFF400, //PIO B
  0xFFFFF400, //PIO B
  0xFFFFF400, //PIO B 
  0xFFFFF400 //PIO B 
};
unsigned long arInputsAddr[6] = {
  0xFFFFF400, //PIO B
  0xFFFFF400, //PIO B
  0xFFFFF400, //PIO B
  0xFFFFF400,  //PIO B
  0xFFFFF400,  //PIO B
  0xFFFFF400  //PIO B 
};

unsigned long arOutsVal[6] = {
  SW1, //
  SW2, //
  SW3, //
  SW4, //
  SW5, //
  (unsigned long)SW6
};
unsigned long  arInputsVal[6] = {
  SWA, //
  SWB, //
  SWC, //
  SWD, //
  SWE, //
  SWF //
};
#define PIN_LED_KBD_ENBL {1 << 23, AT91C_BASE_PIOD, AT91C_ID_PIOD_E, PIO_OUTPUT_0 , PIO_DEFAULT}
const Pin pinsKbdAux[] = {PIN_LED_KBD_ENBL};

//KbdUNFldHolderDsc hldKeyChange;
KbdUNFldHolderDsc hldScanCode;
KbdUNFldHolderDsc hldCurScanCode1,hldCurScanCode2;

void StartUPInitKBD(void)
{
//	PIO Init

 AT91C_BASE_PMC->PMC_PCER = 1 << (AT91C_ID_PIOB);
//INPUT
	//--PIOB_BASE->PIO_OER  = LINES_MASK ;//* Defines the PIOs as output

	AT91C_BASE_PIOB->PIO_ODR   = (unsigned long)COLUMNS_MASK;//LINES_MASK;
	AT91C_BASE_PIOB->PIO_CODR  = (unsigned long)COLUMNS_MASK;
	AT91C_BASE_PIOB->PIO_IFER  = (unsigned long)COLUMNS_MASK;

//OUTPUT
	// PIOB_BASE->PIO_ODR   = COLUMNS_MASK;
	AT91C_BASE_PIOB->PIO_OER   = (unsigned long)LINES_MASK;//COLUMNS_MASK;
	AT91C_BASE_PIOB->PIO_CODR  = (unsigned long)LINES_MASK;//COLUMNS_MASK;
	
//	PIO Init
    AT91C_BASE_PIOB->PIO_IDR   = (unsigned long)(LINES_MASK|COLUMNS_MASK);
    AT91C_BASE_PIOB->PIO_MDDR  = (unsigned long)(LINES_MASK|COLUMNS_MASK);
    AT91C_BASE_PIOB->PIO_PER   = (unsigned long)(LINES_MASK|COLUMNS_MASK);
	AT91C_BASE_PIOB->PIO_SODR      = (unsigned long)LINES_MASK;

  PIO_Configure(pinsKbdAux, PIO_LISTSIZE(pinsKbdAux));

}

void kbd_scan(void*pv)
{
  register long i,j;
  register unsigned long lrVal;
  struct
  {
    //short         shCountCmd;
    unsigned char uChIdxByte;
    unsigned char uChIdxBit;
    short shVal;
    //unsigned short ushBeg,ushEnd;
    unsigned long scancode;
    void *pvOr;
    unsigned long long ullResRead;
  } sLV;
  //.KbdUNFldHolderDsc lhResRead;//,lhV
  //lhResRead.arUl[0]  = 0;lhResRead.arUl[1]  = 0;
  ((KbdUNFldHolderDsc*)pv)->UNFKeyField.arUl[0] = ((KbdUNFldHolderDsc*)pv)->UNFKeyField.arUl[1] = 0;
  sLV.pvOr = pv;
  for (i = 0; i < 6; i++)
  {
    //shift  scan code
    sLV.scancode = 0x3F ^ (1 << i);
    //Set Out Codes
    for (j = 0; j < 6; j++)
    {
      lrVal = arOutsVal[j];
      pv  = (void*) arOutsAddr[j];
      if( sLV.scancode & (1<<j) ) {
        ((AT91S_PIO*)pv)->PIO_SODR = lrVal;
        //GPIO_SetBits(arOutsPort[j], arOutsVal[j]);
      } else {
        //Clear out
        ((AT91S_PIO*)pv)->PIO_CODR = lrVal;
        //GPIO_ResetBits(arOutsPort[j], arOutsVal[j]);//
      }
    }
    
    for (sLV.scancode = 0; sLV.scancode < 100; sLV.scancode++)
    {
      j ^= sLV.scancode;
    }
    
    sLV.scancode = 0;
    
    for (j = 0; j < 6; j++)
    {
      //~~~ pCSP_GPT_T = (CSP_GPT_T*)arInputsAddr[j];
      //val = arInputsVal[j];
      //~~~ val = pCSP_GPT_T->GPT_PDSR;
      pv  = (void*)arInputsAddr[j];
      lrVal = ((AT91S_PIO*)pv)->PIO_PDSR;
      //. val =  GPIO_ReadInputDataBit(arInputsPort[j],arInputsVal[j]);
      if (lrVal) {
        //Select Correctness
        if ( lrVal & arInputsVal[j] ) {
          sLV.scancode |= 1 << j;//val & arInputsVal[j]
          sLV.shVal     = (i * 6) + j;
          sLV.uChIdxByte = sLV.shVal >> 3;
          sLV.uChIdxBit  = sLV.shVal - (8*sLV.uChIdxByte);
          //,sh1 = (RESET_SIGOUT_DI_IEPRF_ONB)>>3;sh2 =(RESET_SIGOUT_DI_IEPRF_ONB) - sh1*8;
          //,k = pUch[sh1];
          //,if (k & (1<<sh2))
          ((unsigned char*)sLV.pvOr)[sLV.uChIdxByte] |= 1 << sLV.uChIdxBit;
        }
      }
    }
    
    sLV.ullResRead = (unsigned long long)(sLV.scancode << (i * 6));
  }
}

extern void ActivateTransmittionOnBR(void); 
extern void ActivateTransmittion_StngAndPrt(void);
extern void ForceSetMinParamCfgTbl(void);


unsigned int key_pressed[RANG_KEY] = {0, 0};
unsigned int key_released[RANG_KEY] = {0, 0};
int time_key_pressed[NR_KEY_ITEMS];
void handle_kbd(void)
{
  register long i;//,j;
  register void *pv1,*pv2 ;
  
  struct {
    unsigned char uChIdxByte;
    unsigned char uChIdxBit;
    short shVal;
    
    //unsigned long scancode;  
    void *pvOrCurSC1;
    void *pvOrCurSC2;
    void *pvOrSC;  
  } sLV;
  
  sLV.pvOrCurSC1 = (void*) &hldCurScanCode1;
  sLV.pvOrCurSC2 = (void*) &hldCurScanCode2;
  sLV.pvOrSC     = (void*) &hldScanCode;
  pv1 = sLV.pvOrCurSC1;
  pv2 = sLV.pvOrCurSC2;
  
  kbd_scan(sLV.pvOrCurSC1);
  
  if (
    (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]) != (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[0])
      ||                                                  
    (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]) != (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1])
  ) {
    pv2	= sLV.pvOrCurSC2;
    kbd_scan(sLV.pvOrCurSC2);
    if(
       (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]) == (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[0])
         &&
       (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]) == (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1])
    ) {
      pv2 = sLV.pvOrSC;
      (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[0]) =~ (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]);
      (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1]) =~ (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]);
      (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1]) &= 0xf;//Mask Clear not used Hi bit
      
      //Clear Key 5D,5F,6F
      sLV.shVal     = (4*6) + 3;
      sLV.uChIdxByte = sLV.shVal >> 3;
      sLV.uChIdxBit  = sLV.shVal - (8*sLV.uChIdxByte);
      ((unsigned char*)pv2)[sLV.uChIdxByte] &=(unsigned char) ~(1 << sLV.uChIdxBit);
      sLV.shVal     = (4*6) + 5;
      sLV.uChIdxByte = sLV.shVal >> 3;
      sLV.uChIdxBit  = sLV.shVal - (8*sLV.uChIdxByte);
      ((unsigned char*)pv2)[sLV.uChIdxByte] &=(unsigned char) ~(1 << sLV.uChIdxBit);
      sLV.shVal     = (5*6) + 5;
      sLV.uChIdxByte = sLV.shVal >> 3;
      sLV.uChIdxBit  = sLV.shVal - (8*sLV.uChIdxByte);
      ((unsigned char*)pv2)[sLV.uChIdxByte] &=(unsigned char) ~(1 << sLV.uChIdxBit);
      
      i = (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[0]);
      i |= (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1]);
      
      unsigned int key[RANG_KEY] = {
        ~((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0],
        ~(((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1] | _KEY_MASK_)
      };
      unsigned int key_offset_code = 0;
      if ( i ) {
        for(; key_offset_code < NR_KEY_ITEMS; key_offset_code++) {
          if (_CHECK_KEY_SET_BIT(key, key_offset_code)) 
          {
            time_key_pressed[key_offset_code] = 0;
          }
        }
      } else {
        for(; key_offset_code < NR_KEY_ITEMS; key_offset_code++) 
        {
          time_key_pressed[key_offset_code] = -1;
          if (
              (_CHECK_KEY_SET_BIT(key_pressed, key_offset_code) != 0) &&
              (_CHECK_KEY_SET_BIT(key        , key_offset_code) == 0) 
             )   
          {
            _SET_KEY_BIT(key_released, key_offset_code);
          }
        }
      }
    }
  } else {
    //pv2 = sLV.pvOrSC;
    (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]) = (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[0]);
    (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]) = (((KbdUNFldHolderDsc*)pv2)->UNFKeyField.arUl[1]);
    
    //pv1 = sLV.pvOrCurSC2;
    //(((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]) = (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[0]);
    //(((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]) = (((KbdUNFldHolderDsc*)pv1)->UNFKeyField.arUl[1]);
  }
  
  for (unsigned int key_tmp = 0; key_tmp < NR_KEY_ITEMS; key_tmp++)
  {
    if (time_key_pressed[key_tmp] >=0 )
    {
      if (++time_key_pressed[key_tmp] > KEY_KEYBOARD_PERIOD)
      {
        _SET_KEY_BIT(key_pressed, key_tmp);
        time_key_pressed[key_tmp] = -1;
      }
    }
  }

if(key_pressed[0] &(1<<(VK_OFFSET_F3) ) )
  {
	//ActivateTransmittion_StngAndPrt();//
    //    SPIOperationTable |= EEPROM_WRITE_SETTINGS;
		shbsRQChangeCfgTablesState |= 1<< BS_RQ_WR_CFG_TBL_BIT;
		
  }
  if(key_pressed[0] &(1<<(VK_OFFSET_F2)))
  {
	key_pressed[1] |= (1<<(VK_OFFSET_CTRL>>5));
	//ForceSetMinParamCfgTbl();
	shbsRQChangeCfgTablesState |= 1<< BS_RQ_SET_MIN_CFG_TBL_BIT;
  }
  //for(i = 0; i< 10; i++ )
  //{
  //  kbd_scan(sLV.pvOrCurSC1);???????Why Keyboard have stoped ICI???
  //  
  //}
}

//unsigned int uiCtrHideScr = 0x100000;

/*
void handle_kbd1(void)
{
    register u_int i;
    CurScanCode = kbd_scan();
    if ( CurScanCode ==	kbd_scan() )
    {    //
        //i = SMScanCode ^ CurScanCode;
        i = ~CurScanCode;
        i &= KEY_MASK;
        i &= (u_int)~((1 << 4) |(1 << 8)|(1 <<  19)|(1 <<  24) );//(1 <<  3) | (1 <<  7));//Clear Reserved Keys
		SMScanCode = CurScanCode;
		SMKeyChange = i ;// Zeroed Reserv Bits???
    	//OS_ENTER_CRITICAL();
		if  ( i  )
		{
 			SMKeyPress1 = 1;
			//PIOA_BASE->PIO_SODR = (1<<4);//show_i_red_led();
		}
		else
		{
			SMKeyPress1 = 0;
			//PIOA_BASE->PIO_CODR = (1<<4);		//show_i_red_led();
		}
		SMScanCode  |= EV_KEYBOARD;//;
		//
		//
		//


	}
	else //
	{
		CurScanCode = SMScanCode;//back

	}

}
*/
