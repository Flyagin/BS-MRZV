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
* File Name       : dstp_df.c
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
//~~~       Перечень констант которые определяют                       ~~~~~
//~~~       параметры таблиц защит и таблиц   EEPROM                     ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Line distance protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp1MngStoreDsc  hldrDstp1MngStore = {
0,//	unsigned char state_dstp1;//меню  Состояние ДЗ
	//.	Состояние
	//.	1 -вкл
	//.	0 - выкл
0,//	unsigned char state_blk_from_drift_dstp1;//Блокировка ДЗ1 от качаний
	//.	Состояние
	//.	1 -вкл
	//.	0 - выкл
0,//	unsigned char state_ocp_dstp1;// МТЗ ДЗ1
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
//                   ~~~   Line distance protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp1PickupStoreDsc hldrDstp1PickupMinValStg0_G0 =  {

50,//long Z_OF_Dstp1_P1_R;//Active
50,//long Z_OF_Dstp1_P1_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp1_P2_R;//Active
50,//long Z_OF_Dstp1_P2_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp1_P3_R;//Active
50,//long Z_OF_Dstp1_P3_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp1_P4_R;//Active
50,//long Z_OF_Dstp1_P4_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp1_P1_R;//Active
50,//long Z_MF_Dstp1_P1_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp1_P2_R;//Active
50,//long Z_MF_Dstp1_P2_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp1_P3_R;//Active
50,//long Z_MF_Dstp1_P3_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp1_P4_R;//Active
50,//long Z_MF_Dstp1_P4_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм
2000,//unsigned long   Dstp1_Iovp_ov_range;
//.ПО I МТЗ ДЗ1
//.	 уставка по току
//.	 1 ед = 1 мA

0//long Dstp1_Coef_Compens_IntPhaseCur;  

//unsigned short  Dstp1_T_OF ;//
//.Длительность Т ДЗ1 OФ 
//.1 ед =10мсе


//unsigned short  Dstp1_T_MF ;//
//.Длительность Т ДЗ1 МФ 
//.1 ед =10мсе
//unsigned short  Dstp1_T_Ocp ;//
//.Длительность Т МТЗ ДЗ1  
//.1 ед =10мсе

} ;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Line distance protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp1StageParamStoreDsc hldrDstp1StageParamStore = {


0,//unsigned short  Dstp1_T_OF ;//
//.Длительность Т ДЗ1 OФ 
//.1 ед =10мсе


0,//unsigned short  Dstp1_T_MF ;//
//.Длительность Т ДЗ1 МФ 
//.1 ед =10мсе
0//unsigned short  Dstp1_T_Ocp ;//
//.Длительность Т МТЗ ДЗ1  
//.1 ед =10мсе

};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Line distance protection Manage Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp2MngStoreDsc hldrDstp2MngStore = {
0,//unsigned char state_dstp2;//меню  Состояние ДЗ
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0,//unsigned char state_blk_from_drift_dstp2;//Блокировка ДЗ2 от качаний
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0,//unsigned char state_ocp_dstp2;// МТЗ ДЗ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл


0,//unsigned char state_Auto_aclt_dstp2;// Автоматическое ускорение ДЗ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
0,//unsigned char  state_aclt_dstp2_hws;
//.	ДЗ2 Ускорение ДЗ2 при включении ВВ
//.	1 -вкл
//.	0 - выкл
0//unsigned char state_Tele_aclt_dstp2;// Телеускорение ДЗ2
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
//                   ~~~   Line distance protection PickUP Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp2PickupStoreDsc hldrDstp2PickupStore = {
//.ПО  ДЗ2 OФ
50,//long Z_OF_Dstp2_P1_R;//Active
50,//long Z_OF_Dstp2_P1_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp2_P2_R;//Active
50,//long Z_OF_Dstp2_P2_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp2_P3_R;//Active
50,//long Z_OF_Dstp2_P3_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_OF_Dstp2_P4_R;//Active
50,//long Z_OF_Dstp2_P4_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм
//.ПО  ДЗ2 МФ
50,//long Z_MF_Dstp2_P1_R;//Active
50,//long Z_MF_Dstp2_P1_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp2_P2_R;//Active
50,//long Z_MF_Dstp2_P2_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp2_P3_R;//Active
50,//long Z_MF_Dstp2_P3_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм

50,//long Z_MF_Dstp2_P4_R;//Active
50,//long Z_MF_Dstp2_P4_X;//Reactive
//. уставка по сопротивлению
//. 1 ед = 1 Oм
2000,//unsigned long   Dstp2_Iovp_ov_range;
//.ПО I МТЗ ДЗ2 
//.	 уставка по току
//.	 1 ед = 1 мA


/**********************************************************/
/* Добавлено 7 июля 2014г. Хемраев А.К. по договоренности */
0,//unsigned short Dstp2_Coef_Compens_IntPhaseCur;
/**********************************************************/


};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Line distance protection StageParam Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
Dstp2StageParamStoreDsc hldrDstp2StageParamStore = {

0,//unsigned short  Dstp2_OF_T_op_aclt;  //.Т оп.уск. ДЗ2 ОФ
//0,//unsigned short  Dstp2_OF_T_auto_aclt;//.Т авт.уск. ДЗ2 ОФ
0,//unsigned short  Dstp2_OF_T_aclt;     //.Т уск. ДЗ2 ОФ
0,//unsigned short  Dstp2_OF_T_tele_aclt;//.Т телеуск.  ДЗ2 ОФ
0,//unsigned short  Dstp2_OF_T;          //.Т  ДЗ2 ОФ
//.ПО  ДЗ2 ОФ

0,//unsigned short  Dstp2_MF_T_op_aclt;  //.Т оп.уск ДЗ2 МФ
//0,//unsigned short  Dstp2_MF_T_auto_aclt;//.Т авт.уск. ДЗ2 МФ
0,//unsigned short  Dstp2_MF_T_aclt;     //.Т уск. ДЗ2 МФ при вкл ВВ
0,//unsigned short  Dstp2_MF_T_tele_aclt;//.Т телеуск.  ДЗ2 МФ
0,//unsigned short  Dstp2_MF_T;          //.Т  ДЗ2 МФ

0,//unsigned short  Dstp2_Ocp_T_op_aclt;  //.Т оп.уск МТЗ ДЗ2 
//0,//unsigned short  Dstp2_Ocp_T_auto_aclt;//.Т авт.уск. МТЗ ДЗ2 
0,//unsigned short  Dstp2_Ocp_T_aclt;     //.Т уск.МТЗ ДЗ2  при вкл ВВ
0,//unsigned short  Dstp2_Ocp_T_tele_aclt;//.Т телеуск. МТЗ ДЗ2 
0,//unsigned short  Dstp2_Ocp_T;          //.Т МТЗ ДЗ2 

0,//unsigned short  Dstp2_HWS_Tau_Aclt;    //.T ввода уск. ДЗ2 при вкл ВВ
0,//unsigned short  Dstp2_Ocp_HWS_Tau_Aclt;//.T ввода уск.МТЗ ДЗ2 при вкл. ВВ



};
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DstpDriftBlkPpStoreDsc hldrDstpDriftBlkPp =  //DstpDriftBlkPpStoreDsc_TagIn
{
//по Zab
50,//long Zab_MF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Zab_MF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний
//. уставка по сопротивлению
//. 1 ед = 1 Oм
//по Zab

//по Zbc
//по Zbc
50,//long Zbc_MF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Zbc_MF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний

//по Zca
//по Zca
50,//long Zca_MF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Zca_MF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний

//по DeltaZab_dt
//по DeltaZbc_dt
//по DeltaZca_dt
5,//long BlkDrift_PickUp_DeltaZab_dt;//Ом\с
5,//long BlkDrift_PickUp_DeltaZbc_dt;//Ом\с
5,//long BlkDrift_PickUp_DeltaZca_dt;//Ом\с

//по T БК АВ ДЗ AB уставка по времени счетчика 0-32C
//по T БК АВ ДЗ BC уставка по времени счетчика 0-32C
//по T БК АВ ДЗ CA уставка по времени счетчика 0-32C
0,//unsigned short BlkDrift_T_counter_Dstp;//??

//по T БК AB выдержка по времени   0-32c 
//по T БК BC выдержка по времени   0-32c
//по T БК CA выдержка по времени   0-32c
0,//unsigned short BlkDrift_Tab;
0,//unsigned short BlkDrift_Tbc;
0//unsigned short BlkDrift_Tca;

};
//~~~   Single Phase ->Sp Phase phase-> Pp
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    Stngs ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
DstpDriftBlkSpStoreDsc hldrDstpDriftBlkSp = //DstpDriftBlkSpStoreDsc_TagIn
{
50,//long Za_OF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Za_OF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний
//. уставка по сопротивлению
//. 1 ед = 1 Oм
50,//long Zb_OF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Zb_OF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний
//. уставка по сопротивлению
//. 1 ед = 1 Oм
50,//long Zc_OF_Dstp_UpBoundDrift;//верхняя граница зоны колебаний
50,//long Zc_OF_Dstp_LowBoundDrift;//нижняя граница зоны колебаний
//. уставка по сопротивлению
//. 1 ед = 1 Oм

5,//long BlkDrift_PickUp_DeltaZa_dt;//Ом\с
5,//long BlkDrift_PickUp_DeltaZb_dt;//Ом\с
5,//long BlkDrift_PickUp_DeltaZc_dt;//Ом\с

//по T БК АВ ДЗ A уставка по времени счетчика
//по T БК АВ ДЗ B уставка по времени счетчика
//по T БК АВ ДЗ C уставка по времени счетчика
0,//unsigned short BlkDrift_T_counter_Dstp;//?? May shadow in Phase-Phase part
//по T БК A выдержка по времени   0-32c 
//по T БК B выдержка по времени   0-32c
//по T БК C выдержка по времени   0-32c
0,//unsigned short BlkDrift_Ta;
0,//unsigned short BlkDrift_Tb;
0//unsigned short BlkDrift_Tc;


};
//~~~   Single Phase ->Sp Phase phase-> Pp
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



extern CfgTblDsc currnet_settings, eeprom_prt_tbl;







