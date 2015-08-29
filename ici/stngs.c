/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* Processor       : All
* File Name       : stngs.c
* Description     : Definitions and structures for dstp protection
                    BM  BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  05/02/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "../inc/const_BS_BL.h" 
#include    "../inc/type_definition_BS.h"
#include    "../inc/type_definition_BL.h" 

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Dr Earth    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
__SETTINGS IciStng = {

//Тип пристрою
  0,// unsigned int device_id;
  // 
  // /-*
  // Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
  // *-/
  0,0,0,0,// unsigned int dz1_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz2_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz3_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz4_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int dz5_K[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для МТЗ
  // *-/
  0,0,0,0,// unsigned int mtz1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int mtz5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для ТЗНП
  // *-/
  0,0,0,0,// unsigned int tznp1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int tznp5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // /-*
  // Угол доворота для ZOP
  // *-/
  0,0,0,0,// unsigned int zop1_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop2_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop3_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop4_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  0,0,0,0,// unsigned int zop5_angle_r[AMOUNT_SERIES_PPSPM_SETTINGS];
  // 
  // /-*Рассогласование углов
  // 
  // 0 - Usyn
  // 1 - Isyn
  // 0 - Ua
  // 1 - Ub
  // 2 - Uc
  // *-/
  0,// unsigned int a_Usyn_Isyn;
  0,// unsigned int a_Ua_Ub_Uc;
  // 
  // /-*
  //  Номинальный ток от шкафа отбора напряжения
  // 0 - 0,15А
  // 1 - 0,075А
  // *-/
  0// unsigned int In_type_shon;
 


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
