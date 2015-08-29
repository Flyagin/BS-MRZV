/*------------------------------------------------------------------------------
* 
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
* File Name       : GU1.h
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    AT91SAM9G45-dependant PIOs and external components
					interfacing.
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  09/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef GU1_h
#define GU1_h

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
/*
#define SIZE_LPDU_CNL_1 200

#define SIZE_LPDU_CNL_DOUBLE_ACCESS_MEMORY  512

#define SIZE_LPDU_CNL_HSU7 100

#define SIZE_LPDU_CNL_U3   60

#define SIZE_LPDU_CNL_HSU1 100
#define SIZE_LPDU_CNL_HSU2 100

#define SIZE_LPDU_CNL_SPI  512

#define SIZE_LPDU_CNL_HSU2 100//USART


#define SIZE_LPCI_FLD_CNL_1    1
#define SIZE_LDC_FLD_CNL_1     1
#define SIZE_CS_FLD_CNL_1      1

#define SIZE_LPCI_FLD_CNL_HSU7    1
#define SIZE_LDC_FLD_CNL_HSU7     1
#define SIZE_CS_FLD_CNL_HSU7      1

#define HDR_MODE_CNL_1      ((1<<7)|(1<<1))
*/
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define ID_CNL_TEST1 0x1
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct StateXXXDsc_tag
{
	char b ;
	
}StateXXXDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//#define 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

extern unsigned char chHdwErorU1;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define SIZE_LPDU_CNL_2 248
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void u1_hdw_init(void);
long outU1(unsigned char *dat, long bytes)  @ "Fast_function";
long inU1(unsigned char *buff, long bytes)  @ "Fast_function";
void u1_send_cb(void)  ;//@ "Fast_function";
void u1_recv_cb(void)  ;//@ "Fast_function";
void u1_error_cb(void) ;//@ "Fast_function";
void u1_eof_cb(void)   ;//@ "Fast_function";
void u1_recover_cb(void) @ "Fast_function";
void ReInitInBufParam(void);
#endif 
/* GU1_h */
