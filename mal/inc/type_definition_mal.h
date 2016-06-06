#ifndef __TYPE_DEFINITION_MAL__
#define __TYPE_DEFINITION_MAL__

#define DDR2_B0_CODE _Pragma("location=\"DDR2_Bank0_codes\"")
#define DDR2_B1_2_DATA _Pragma("location=\"DDR2_Bank1_2_variables\"")
#define DDR2_B3_DATA _Pragma("location=\"DDR2_Bank3_variables\"")

typedef struct
{
  int current_level;                  //Текучий рівень відображуваного екрану
 
  int index_position;                 //Вказує на якій ми зараз є позиції
  int index_position_1;               //Вказує на якій ми зараз є підпозиції 1

  unsigned int edition;               //0 - вікно зараз не в режимі редагується;
                                      //1 - вікно зараз в режимі редагування;
                                      //2 - вікно зараз в режимі редагування і дані змінені
  unsigned int edition_level_2;
} __CURRENT_EKRAN;

typedef struct 
{
  const char    * ptitle[LANG_LIST_SIZE];
} TITLE;

typedef struct 
{
  float min;
  float max;
  int shift;
  unsigned int extra_param;
} __info_data;

typedef struct
{
  unsigned int next_address;
  unsigned int saving_execution;
  unsigned int number_records;
} __INFO_REJESTRATOR;

typedef struct
{
  unsigned int a[100];
  unsigned int b;
} __TEMP_STRUCTURE;

typedef struct
{
    BmRamPrgEvtDsc hldrPrgEvtBm;
    BrRamPrgEvtDsc hldrPrgEvtBr; 
    BsRamPrgEvtDsc hldrPrgEvtBs;
}__DIAGN;	


#endif
