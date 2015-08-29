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
* File Name       : hve_df.c
* Description     : Definitions and structures for dstp protection
                    BM BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/11/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Dr Earth    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DrErthMngStoreDsc hldrDrErthMngStore = {
0,//unsigned char  state_Tznp;
//.   Состояние
//.   1 -вкл
//.   0 - выкл
0,//unsigned char  direction_Tznp1;
//.Состояние
//.1 -вперёд
//.0 - назад
0,//unsigned char  state_Tznp_3U0;
//.   Состояние
//.   1 -вкл
//.   0 - выкл
0,//unsigned char  state_Tznp_3I0;
//.   Состояние
//.   1 -вкл
//.   0 - выкл
0,//unsigned char  state_aclt_Tznp;//Состояние ключя ТЗH ускоренная
//.	1 -вкл
//.	0 - выкл
0,//unsigned char  state_over_wk_aclt_Tznp;//Оперативное ускорение ТЗНП
//.	1 -вкл
//.	0 - выкл
0,//unsigned char   aclt_Tznp_sw;//ускорение ТЗНП
//.	1 -вкл
//.	0 - выкл





};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr Earth   protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DrErthPickupStoreDsc hldrDrErthPickupStore = {


//~~~~~~~~~~~~~~~~~~~~        Angle Tznp    ~~~~~~~~~~~~~~~~~~~~~
0,//unsigned int   AngleRotation_3I0_Tznp;
//. угол поворота 3I0_1 в градусах
//~~~~~~~~~~~~~~~~~~~~          Angle Tznp    ~~~~~~~~~~~~~~~~~~~~~

250,//unsigned int   ov_range_3Io_Tznp;
//. уставка по 3Io
//. 1 ед = 1 мA
10000,//unsigned int   ov_range_3Uo_Tznp;
//. уставка по 3Uo
//. 1 ед = 10 мВ



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Dr Earth   protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DrErthStageParamStoreDsc hldrDrErthStageParamStore = {


100,//unsigned int   time_Tznp;
//.выдержка Tznp1
//.1 ед =10мсе
100,//unsigned short Tznp_time_stage_Aclt;   //- выдержка ускорения ступени ТЗНП   
100,//unsigned short Tznp_time_stage_3U0;    //- выдержка T 3U0 ЗНП1 
100,//unsigned short Tznp_time_stage_3I0;    //- выдержка T 3I0 ЗНП1 
100,//unsigned short Tznp3I0_time_stage_Aclt;//T ускор ЗНП1 3I0
100,//unsigned short Tznp_Tau_AcltImp;       //- длительность формирования импульса ускорения  ступени ТЗНП   





};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   TZNP   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct TznpStoreDsc_TagIn
//{
//DrErthPrtDsc ownrTznp1;
//DrErthPrtDsc ownrTznp2;
//DrErthPrtDsc ownrTznp3;
//DrErthPrtDsc ownrTznp4;
//DrErthPrtDsc ownrTznp5;
////One store/complect PickUP
//
//
//}TznpStoreDsc;
//~~~   
//..................................................................................

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант  3U0                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   U3U0Prt   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//-typedef struct U3UoPrtDsc_TagIn
//-{
//-long sizeAr;      //Размер считанного массива
//-long *pTenPerData;//Указатель на начало данных
//-
//-}U3UoPrtDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//ZOP ANSI -
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       List of  ZOP                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   ZOP   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  NSP    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
NspMngStoreDsc hldrNspMngStore = {
0,//unsigned char select_prt_zop;//Селектор зоп
//меню  выбор рабоы защиты ЗОП Пуск(Работа) 
//по направленности Пуск(Работа) по напряжению
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности

0,//unsigned char state_dir_zop;
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0//unsigned char select_dir_zop;
//.	Состояние
//.	1 - прямая
//.	0 - обратная



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   NSP   protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
NspPickupStoreDsc hldrNspPickupStore = {
0,//unsigned int ov_range_Zop;
//. уставка по току ПО ЗОП1
//. 1 ед = 1 мA

250,//unsigned int ov_range_Zop_s_I2;
//. уставка по току ПО НЗОП прям
//. 1 ед = 1 мA
10000,//unsigned int ov_range_Zop_s_U2;
//. уставка по напряжению ПО НЗОП  прям
//. 1 ед = 1 мA

250,//unsigned int ov_range_Zop_b_I2;
//. уставка по току ПО НЗОП обр
//. 1 ед = 1 мA
10000//unsigned int ov_range_Zop_b_U2;
//. уставка по напряжению ПО НЗОП  обр
//. 1 ед = 1 мB
//unsigned int   time_Tzop;


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   NSP   protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
NspStageParamStoreDsc hldrNspStageParamStore = {


//unsigned int   time_Tzop;
//.выдержка Tznp1
//.1 ед =10мсе
0,//unsigned short time_stage_Zop;   //- выдержка ЗОП
0,//unsigned short time_stage_Zop_s;    //- выдержка T вперед ЗOП 
0//unsigned short time_stage_Zop_b;    //- выдержка T назад ЗOП 





};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   NSP   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct NspStoreDsc_TagIn
//{
//NspDsc ownrNsp1;
//NspDsc ownrNsp2;
//
////One store/complect PickUP
//}NspStoreDsc;
//~~~   
//..................................................................................




//Umin ANSI -
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       List of  Umin                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Umin   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//typedef struct UminDsc_TagIn
//{
//////////////////////////////////////////////////////////////////////////
/////Umin
//////////////////////////////////////////////////////////////////////////
//
//
//}UminDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Umin    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UminMngStoreDsc hldrUminMngStoren = {
0,//unsigned char state_Umin;       //Меню Состояние Umin
0,//unsigned char state_SDEV_Umin;  //Меню Состояние ПО Umin И\ИЛИ 
0,//unsigned char state_Umin_Ublk;  //Состояние ПО блокировки по напряжению
0,//unsigned char state_Umin_Iblk;  //Состояние ПО блокировки по току
//unsigned char state_SDEV_Phase; //Меню Состояние ПО фазные/линейные 
//.Состояние
//.1 -вкл
//.0 - выкл



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Umin  protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UminPickupStoreDsc hldrUminPickupStore = {


//. уставки по Напряжению
//. 1 ед = 1 мB

25000,//unsigned int ov_range_Umin;//Уставки ЗНмин

//unsigned int ov_range_Umin_blk;

//. уставки по Напряжению
//. 1 ед = 1 мB


//. уставка по току
//. 1 ед = 1 мA

250//unsigned int ov_range_IblkUmin;//ПО I блокировки ЗНмин2 



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    Umin   protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UminStageParamStoreDsc hldrUminStageParamStore = {

100//unsigned short	 time_stage_Umin;//Выдержка ЗНмин
//.	выдержка 1- ступени Umin
//.	1 ед =10мсе






};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//Umax ANSI -
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       List of  Umax                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Umax    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UmaxMngStoreDsc hldrUmaxMngStore = {
//-Umax
0,//unsigned char state_Umax;     //Меню Состояние Umax1
0,//unsigned char state_SDEV_Umax;//Меню Состояние ПО Umax1 И\ИЛИ 
//unsigned char state_SDEV_Phase;//Меню Состояние ПО фазные/линейные 
//.Состояние
//.1 -вкл
//.0 - выкл



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Umax  protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UmaxPickupStoreDsc hldrUmaxPickupStore = {

//. уставки по Напряжению
//. 1 ед = 1 мB

40000//unsigned int ov_range_Umax;//уставка 



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Umax protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
UmaxStageParamStoreDsc hldrUmaxStageParamStore = {


100//unsigned short	 time_stage_Umax;//выдержка 1- ступени Umax 0.1 с до 32.0 с

//.выдержка 1- ступени Umax
//.1 ед =10мсе



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Reclosing Relay    protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
RclrMngStoreDsc hldrRclrMngStore = {
////////////////////////////////////////////////////////////////////////
///АПВ`
////////////////////////////////////////////////////////////////////////
0,//unsigned char  state_Rclr;//АПВ
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0,//unsigned char  state_Rclr2;//АПВ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
//Массив битовых переключателей команд пуска АПВ 
//Значения бит см enum ENMEpr_StpRclr epr_f.h
//unsigned char ar_Rclr_Stp_Cmd_state[AMOUNT_BYTE_FOR_RCLR_STP]; 
{0},
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0,//unsigned char select_Mode_Rclr;//Селектор АПВ
//меню  выбор рабоы АПВ Пуск(Работа) 
//
//.	Состояние
//.	0 - Без контроля
//.	1 - Контроль отсутствия напряжения на линии и наличия напряжения на шинах
//.	2 - Контроль наличия напряжения на линии и отсутствия напряжения на шинах
//.	3 - Контроль наличия напряжения на линии и наличия напряжения на шинах
//       и без синхронизма..
//.	4 - Контроль наличия напряжения на линии и наличия напряжения на шинах
//     и синхронизма..
0//unsigned char selectPhase;//Селектор выбранной фазы шины из шкафа отбора напряжения
//.	Состояние
//.	0 - Фаза A
//.	1 - Фаза B
//.	2 - Фаза C


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Reclosing Relay   protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
RclrPickupStoreDsc hldrRclrPickupStore = {

40000,//unsigned int   Rclr_U_ov_range1;
//.ПО АПВ 1 Контроль наявності уставка по по напряжению Uн шон 40 140 В шаг 0.01
//.	 уставка по по напряжению
//.	 1 ед = 1 мB
1000,//unsigned int   Rclr_U_ov_range2;
//.ПО АПВ 2 контроль відсутності
//.	 уставка по по напряжению 1  - 20 В 
//.	 1 ед = 1 мB
18000*3,//unsigned int   Rclr_U_ov_range3;
//.ПО АПВ 3 уставка по по напряжению Uн шон 40 140 В шаг 0.01
//.	 уставка по по напряжению
//.	 1 ед = 1 мB
450*5,//unsigned int   Rclr_U_ov_range4;
//.ПО АПВ 4 1  - 20 В 
//.	 
//.	 1 ед = 1 мB

//syncro1
450*5,//unsigned long Rclr_DeltaU;
//Разница напряжений Шаг 0.01
//1  - 20 В 
//syncro2
5*5,//unsigned long Rclr_DeltaPhi;
//угол рассогласования
//5 до (+-)50 град Шаг 1 град

//Syncro3
5*1000//unsigned long Rclr_DeltaPhi_Dt;
//Скорость скольжения
//5 - 30 град\с Шаг 0.01



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Reclosing Relay  protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
RclrStageParamStoreDsc hldrRclrStageParamStore = {
20,//unsigned short  Rclr1_T_wait_U ;
//.Длительность ож U АПВ1 
//.1 ед =10мсе
0,//unsigned short  Rclr1_T_wait_sycro ;
//.Длительность ож синхронизма АПВ1 
//.1 ед =10мсе
500,//unsigned short  Rclr1_T_blk;
//.Длительность блокировки  АПВ1 
//.1 ед =10мсе

20,//unsigned short  Rclr1_T;
//.Длительность   АПВ1 
//.1 ед =10мсе

0,//unsigned short  Rclr_T_forbid;
//.Длительность запрета  АПВ1 
//.1 ед =10мсе

0,//unsigned short  Rclr_T_blk_HSW;
//.Длительность блокировки  АПВ от ВВ 
//.1 ед =10мсе

0,//unsigned short  Rclr2_T_wait_U ;
//.Длительность ож U АПВ2 
//.1 ед =10мсе
0,//unsigned short  Rclr2_T_wait_syncro ;
//.Длительность ож синхронизма АПВ2 
//.1 ед =10мсе
0,//unsigned short  Rclr2_T_blk;
//.Длительность блокировки  АПВ2 
//.1 ед =10мсе
20//unsigned short  Rclr2_T;
//.Длительность   АПВ2 
//.1 ед =10мсе




};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   50BF     protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BrfMngStoreDsc hldrBrfMngStore  = {
////////////////////////////////////////////////////////////////////////
///УРОВ
////////////////////////////////////////////////////////////////////////
0,//unsigned char state_Urov;//Состояние УРОВ
//Массив битовых переключателей команд пуска УРОВ 
//Значения бит см enum ENMEpr_StpBrf epr_f.h
0//unsigned char ar_Brf_Stp_Cmd_state[AMOUNT_BYTE_FOR_BRF_STP]; 
//.	Состояние
//.	1 -вкл
//.	0 - выкл

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    50BF    protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BrfPickupStoreDsc hldrBrfPickupStore = {
250//unsigned int ov_range_Urov;
//. уставка по току
//. 1 ед = 1 мA

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    50BF   StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BrfStageParamStoreDsc hldrBrfStageParamStore = {

0,//unsigned short	 time_stage_Urov1;//Выдержка 1 Ступени УРОВ
0//unsigned short	 time_stage_Urov2;//Выдержка 2 Ступени УРОВ

//.	выдержка 1- ступени 
//.	1 ед =10мсе

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~  Breaker Unit   protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BruMngStoreDsc hldrBruMngStore = {

//////////////////////////////////////////////////////////////////////////////////////////
0, //unsigned char state_Delay_ON_Unit;//Задержка вкл.
0, //unsigned char state_Blk_SetON;    //Блокировка вкл ВВ общ   
//
0,//unsigned char state_CheckHVS;     //Контроль ВВ
0//unsigned char state_ResourceHVS; //Ресурс   ВВ


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Breaker Unit  protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BruDsc hldrBruDsc = {
0,//unsigned short time_stageOFFUnit;  //выдержка формирователя Блока отключения
0,//unsigned short time_stageONUnit;   //выдержка формирователя Блока включения
0,//unsigned short time_stageONCtrl;   //выдержка формирователя блокировки Блока включения
0,//unsigned short time_stageONUnitBlk;//выдержка формирователя удлинения блокировки Блока включения
0,//unsigned short time_ActuatorHVS;   //T привод ВВ
//////////////////////////////////////////////////////////////////////////////////////////
0,//unsigned char state_Delay_ON_Unit;//Задержка вкл.
0 //unsigned char state_Blk_SetON;    //Блокировка вкл ВВ общ   

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Breaker Unit  protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
BruStageParamStoreDsc hldrBruStageParamStore = {
0, //unsigned short time_stageOFFUnit;  //выдержка формирователя Блока отключения
0, //unsigned short time_stageONUnit;   //выдержка формирователя Блока включения
0, //unsigned short time_stageONCtrl;   //выдержка формирователя блокировки Блока включения
0, //unsigned short time_stageONUnitBlk;//выдержка формирователя удлинения блокировки Блока включения
0 //unsigned short time_ActuatorHVS;   //T привод ВВ



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Breaker Unit  protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
CalcHvpBrOnDsc hldrCalcHvpBrOn = {

5000,//unsigned int  Inom;//Номінальний струм (Iном.)
// Мін.значення 5 (А) 
// Макс.значення 5×(Max.коефіцієнт трансформації трансформатора струму) (А)
// Крок 1 (А)
//---------------------------------------------------------------------------
//Ресурс по ком стійкості при номінальному струмі
1000, //unsigned int  RBR_Inom; //Resource_Breaking_resistance
// Мін.значення          1000 (вимкнень)
// Макс.значення         100000 (вимкнень)
// Крок 1 
//---------------------------------------------------------------------------
//Номінальний струм вимкнення (Iоткл.ном.)
100,//unsigned int  Ioff_nom;
// Мін.значення          0,1 (кА)
// Макс.значення         50 (кА)
// Крок                  0,001 (кА)
//---------------------------------------------------------------------------
//Ресурс по ком стійкості при струмах короткого замикання I=(60-100)% від Iоткл.ном.
10, // unsigned int  RBR_off_nom;
// Мін.значення          10 (вимкнень)
// Макс.значення         999 (вимкнень)
// Крок 1 
//---------------------------------------------------------------------------
//Початкове значення ресурсу
1, //unsigned int  BegRscVal;   //StartingResourceVal;
// Мін.значення    2*(RBR_Inom/RBR_off_nom)
// Макс.значення   RBR_Inom
// Крок 1 ()
//---------------------------------------------------------------------------
//Критичний ресурс
1,//unsigned int  CriticalRsc;
// Мін.значення    (RBR_Inom/RBR_off_nom)
// Макс.значення   2*(RBR_Inom/RBR_off_nom)
// Крок 1 ()
//---------------------------------------------------------------------------
//Початкове значення кількості вимкнень
0 //unsigned int AmtSwTripping;
// Мін.значення      0
// Макс.значення     значення уставки «Ресурс по ком стійкості при номінальному струмі»
// Крок 1 ()



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



extern CfgTblDsc currnet_settings, eeprom_prt_tbl;







