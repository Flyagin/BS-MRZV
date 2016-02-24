#ifndef __DIAGNOSTICS_PANEL__
#define __DIAGNOSTICS_PANEL__

#define ALL_NUMB_DIAGNOSTICS    50

#if ((ALL_NUMB_DIAGNOSTICS & 0x1f) == 0)

#define NUMBER_4BYTES_WORDS_FOR_DIAGNOSTICS    (ALL_NUMB_DIAGNOSTICS >> 5)   

#else

#define NUMBER_4BYTES_WORDS_FOR_DIAGNOSTICS    ((ALL_NUMB_DIAGNOSTICS >> 5) + 1)  

#endif

#define MAX_NUMBER_DIAGN_IN_PANEL           11

#define DIAGNOSTICS_UKR_TXT                     "Діагностика"
#define DIAGNOSTICS_RUS_TXT                     "Диагностика"
#define DIAGNOSTICS_ENG_TXT                     "Diagnostics"

#define EXPL_DIAGNOSTICS_IT_UKR                 "Відображення інф.по діагностиці"
#define EXPL_DIAGNOSTICS_IT_RUS                 "Отображение инф. о диагностике"
#define EXPL_DIAGNOSTICS_IT_ENG                 "Show Diagnostics info"

#define TITLE_DIAGNOSTICS_PANEL_UKR             "Діагностика"
#define TITLE_DIAGNOSTICS_PANEL_RUS             "Диагностика"
#define TITLE_DIAGNOSTICS_PANEL_ENG             "Diagnostics"

#define TITLE_DIAGNOSTICS_PAGE_1_UKR             "БС"
#define EXPL_DIAGNOSTICS_PAGE_1_UKR              "Стан діагностики БС-МРЗВ"
#define TITLE_DIAGNOSTICS_PAGE_1_RUS             "БС"
#define EXPL_DIAGNOSTICS_PAGE_1_RUS              "Состояние диагностики БС-МРЗВ"
#define TITLE_DIAGNOSTICS_PAGE_1_ENG             "BS"
#define EXPL_DIAGNOSTICS_PAGE_1_ENG              "BS-MRZV Diagnostics state"

#define TITLE_DIAGNOSTICS_PAGE_2_UKR             "БО(вим.)"
#define EXPL_DIAGNOSTICS_PAGE_2_UKR              "Стан діагностики БО-МРЗВ(вим.)"
#define TITLE_DIAGNOSTICS_PAGE_2_RUS             "БО(изм.)"
#define EXPL_DIAGNOSTICS_PAGE_2_RUS              "Состояние диагностики БО-МРЗВ(изм.)"
#define TITLE_DIAGNOSTICS_PAGE_2_ENG             "BO(meas.)"
#define EXPL_DIAGNOSTICS_PAGE_2_ENG              "BO-MRZV(meas.) Diagnostics state"

#define TITLE_DIAGNOSTICS_PAGE_3_UKR             "БО(лог.)"
#define EXPL_DIAGNOSTICS_PAGE_3_UKR              "Стан діагностики БО-МРЗВ(лог.)"
#define TITLE_DIAGNOSTICS_PAGE_3_RUS             "БО(лог.)"
#define EXPL_DIAGNOSTICS_PAGE_3_RUS              "Состояние диагностики БО-МРЗВ(лог.)"
#define TITLE_DIAGNOSTICS_PAGE_3_ENG             "BO(log.)"
#define EXPL_DIAGNOSTICS_PAGE_3_ENG              "BO-MRZV(log.) Diagnostics state"

#define TITLE_DIAGNOSTICS_PAGE_4_UKR             "Міжпроц.обмін"
#define EXPL_DIAGNOSTICS_PAGE_4_UKR              "Стан діагностики міжпроц.обміну"
#define TITLE_DIAGNOSTICS_PAGE_4_RUS             "Междупроц.обмен"
#define EXPL_DIAGNOSTICS_PAGE_4_RUS              "Состояние диагностики междупроц.обмена"
#define TITLE_DIAGNOSTICS_PAGE_4_ENG             "Interprocessor traffic"
#define EXPL_DIAGNOSTICS_PAGE_4_ENG              "Interprocessor traffic diagnostics state"


#define DIAGN_BS_MRZV_UKR_NAME_LIST \
{\
  "Помилка 0",\
  "Помилка 1",\
  "Помилка 2",\
  "Помилка 3",\
  "Помилка 4",\
  "Помилка 5",\
  "Помилка 6",\
  "Помилка 7",\
  "Помилка 8",\
  "Помилка 9",\
  "Помилка 10",\
  "Помилка 11",\
  "Помилка 12",\
  "Помилка 13",\
  "Помилка 14",\
  "Помилка 15",\
  "Помилка 16",\
  "Помилка 17",\
  "Помилка 18",\
  "Помилка 19",\
  "Помилка 20",\
  "Помилка 21",\
  "Помилка 22",\
  "Помилка 23",\
  "Помилка 24",\
  "Помилка 25",\
  "Помилка 26",\
  "Помилка 27",\
  "Помилка 28",\
  "Помилка 29",\
  "Помилка 30",\
  "Помилка 31",\
  "Помилка 32",\
  "Помилка 33",\
  "Помилка 34",\
  "Помилка 35",\
  "Помилка 36",\
  "Помилка 37",\
  "Помилка 38",\
  "Помилка 39",\
  "Помилка 40",\
  "Помилка 41",\
  "Помилка 42",\
  "Помилка 43",\
  "Помилка 44",\
  "Помилка 45",\
  "Помилка 46",\
  "Помилка 47",\
  "Помилка 48",\
  "Помилка 49"\
}
#define DIAGN_BS_MRZV_RUS_NAME_LIST \
{\
  "Ошибка 0",\
  "Ошибка 1",\
  "Ошибка 2",\
  "Ошибка 3",\
  "Ошибка 4",\
  "Ошибка 5",\
  "Ошибка 6",\
  "Ошибка 7",\
  "Ошибка 8",\
  "Ошибка 9",\
  "Ошибка 10",\
  "Ошибка 11",\
  "Ошибка 12",\
  "Ошибка 13",\
  "Ошибка 14",\
  "Ошибка 15",\
  "Ошибка 16",\
  "Ошибка 17",\
  "Ошибка 18",\
  "Ошибка 19",\
  "Ошибка 20",\
  "Ошибка 21",\
  "Ошибка 22",\
  "Ошибка 23",\
  "Ошибка 24",\
  "Ошибка 25",\
  "Ошибка 26",\
  "Ошибка 27",\
  "Ошибка 28",\
  "Ошибка 29",\
  "Ошибка 30",\
  "Ошибка 31",\
  "Ошибка 32",\
  "Ошибка 33",\
  "Ошибка 34",\
  "Ошибка 35",\
  "Ошибка 36",\
  "Ошибка 37",\
  "Ошибка 38",\
  "Ошибка 39",\
  "Ошибка 40",\
  "Ошибка 41",\
  "Ошибка 42",\
  "Ошибка 43",\
  "Ошибка 44",\
  "Ошибка 45",\
  "Ошибка 46",\
  "Ошибка 47",\
  "Ошибка 48",\
  "Ошибка 49"\
}
#define DIAGN_BS_MRZV_ENG_NAME_LIST \
{\
  "Error 0",\
  "Error 1",\
  "Error 2",\
  "Error 3",\
  "Error 4",\
  "Error 5",\
  "Error 6",\
  "Error 7",\
  "Error 8",\
  "Error 9",\
  "Error 10",\
  "Error 11",\
  "Error 12",\
  "Error 13",\
  "Error 14",\
  "Error 15",\
  "Error 16",\
  "Error 17",\
  "Error 18",\
  "Error 19",\
  "Error 20",\
  "Error 21",\
  "Error 22",\
  "Error 23",\
  "Error 24",\
  "Error 25",\
  "Error 26",\
  "Error 27",\
  "Error 28",\
  "Error 29",\
  "Error 30",\
  "Error 31",\
  "Error 32",\
  "Error 33",\
  "Error 34",\
  "Error 35",\
  "Error 36",\
  "Error 37",\
  "Error 38",\
  "Error 39",\
  "Error 40",\
  "Error 41",\
  "Error 42",\
  "Error 43",\
  "Error 44",\
  "Error 45",\
  "Error 46",\
  "Error 47",\
  "Error 48",\
  "Error 49"\
}

#define DIAGN_BO_MRZV_M_UKR_NAME_LIST \
{\
  "Помилка 0",\
  "Помилка 1",\
  "Помилка 2",\
  "Помилка 3",\
  "Помилка 4",\
  "Помилка 5",\
  "Помилка 6",\
  "Помилка 7",\
  "Помилка 8",\
  "Помилка 9",\
  "Помилка 10",\
  "Помилка 11",\
  "Помилка 12",\
  "Помилка 13",\
  "Помилка 14",\
  "Помилка 15",\
  "Помилка 16",\
  "Помилка 17",\
  "Помилка 18",\
  "Помилка 19",\
  "Помилка 20",\
  "Помилка 21",\
  "Помилка 22",\
  "Помилка 23",\
  "Помилка 24",\
  "Помилка 25",\
  "Помилка 26",\
  "Помилка 27",\
  "Помилка 28",\
  "Помилка 29",\
  "Помилка 30",\
  "Помилка 31",\
  "Помилка 32",\
  "Помилка 33",\
  "Помилка 34",\
  "Помилка 35",\
  "Помилка 36",\
  "Помилка 37",\
  "Помилка 38",\
  "Помилка 39",\
  "Помилка 40",\
  "Помилка 41",\
  "Помилка 42",\
  "Помилка 43",\
  "Помилка 44",\
  "Помилка 45",\
  "Помилка 46",\
  "Помилка 47",\
  "Помилка 48",\
  "Помилка 49"\
}
#define DIAGN_BO_MRZV_M_RUS_NAME_LIST \
{\
  "Ошибка 0",\
  "Ошибка 1",\
  "Ошибка 2",\
  "Ошибка 3",\
  "Ошибка 4",\
  "Ошибка 5",\
  "Ошибка 6",\
  "Ошибка 7",\
  "Ошибка 8",\
  "Ошибка 9",\
  "Ошибка 10",\
  "Ошибка 11",\
  "Ошибка 12",\
  "Ошибка 13",\
  "Ошибка 14",\
  "Ошибка 15",\
  "Ошибка 16",\
  "Ошибка 17",\
  "Ошибка 18",\
  "Ошибка 19",\
  "Ошибка 20",\
  "Ошибка 21",\
  "Ошибка 22",\
  "Ошибка 23",\
  "Ошибка 24",\
  "Ошибка 25",\
  "Ошибка 26",\
  "Ошибка 27",\
  "Ошибка 28",\
  "Ошибка 29",\
  "Ошибка 30",\
  "Ошибка 31",\
  "Ошибка 32",\
  "Ошибка 33",\
  "Ошибка 34",\
  "Ошибка 35",\
  "Ошибка 36",\
  "Ошибка 37",\
  "Ошибка 38",\
  "Ошибка 39",\
  "Ошибка 40",\
  "Ошибка 41",\
  "Ошибка 42",\
  "Ошибка 43",\
  "Ошибка 44",\
  "Ошибка 45",\
  "Ошибка 46",\
  "Ошибка 47",\
  "Ошибка 48",\
  "Ошибка 49"\
}
#define DIAGN_BO_MRZV_M_ENG_NAME_LIST \
{\
  "Error 0",\
  "Error 1",\
  "Error 2",\
  "Error 3",\
  "Error 4",\
  "Error 5",\
  "Error 6",\
  "Error 7",\
  "Error 8",\
  "Error 9",\
  "Error 10",\
  "Error 11",\
  "Error 12",\
  "Error 13",\
  "Error 14",\
  "Error 15",\
  "Error 16",\
  "Error 17",\
  "Error 18",\
  "Error 19",\
  "Error 20",\
  "Error 21",\
  "Error 22",\
  "Error 23",\
  "Error 24",\
  "Error 25",\
  "Error 26",\
  "Error 27",\
  "Error 28",\
  "Error 29",\
  "Error 30",\
  "Error 31",\
  "Error 32",\
  "Error 33",\
  "Error 34",\
  "Error 35",\
  "Error 36",\
  "Error 37",\
  "Error 38",\
  "Error 39",\
  "Error 40",\
  "Error 41",\
  "Error 42",\
  "Error 43",\
  "Error 44",\
  "Error 45",\
  "Error 46",\
  "Error 47",\
  "Error 48",\
  "Error 49"\
}


#define DIAGN_BO_MRZV_L_UKR_NAME_LIST \
{\
  "Помилка 0",\
  "Помилка 1",\
  "Помилка 2",\
  "Помилка 3",\
  "Помилка 4",\
  "Помилка 5",\
  "Помилка 6",\
  "Помилка 7",\
  "Помилка 8",\
  "Помилка 9",\
  "Помилка 10",\
  "Помилка 11",\
  "Помилка 12",\
  "Помилка 13",\
  "Помилка 14",\
  "Помилка 15",\
  "Помилка 16",\
  "Помилка 17",\
  "Помилка 18",\
  "Помилка 19",\
  "Помилка 20",\
  "Помилка 21",\
  "Помилка 22",\
  "Помилка 23",\
  "Помилка 24",\
  "Помилка 25",\
  "Помилка 26",\
  "Помилка 27",\
  "Помилка 28",\
  "Помилка 29",\
  "Помилка 30",\
  "Помилка 31",\
  "Помилка 32",\
  "Помилка 33",\
  "Помилка 34",\
  "Помилка 35",\
  "Помилка 36",\
  "Помилка 37",\
  "Помилка 38",\
  "Помилка 39",\
  "Помилка 40",\
  "Помилка 41",\
  "Помилка 42",\
  "Помилка 43",\
  "Помилка 44",\
  "Помилка 45",\
  "Помилка 46",\
  "Помилка 47",\
  "Помилка 48",\
  "Помилка 49"\
}
#define DIAGN_BO_MRZV_L_RUS_NAME_LIST \
{\
  "Ошибка 0",\
  "Ошибка 1",\
  "Ошибка 2",\
  "Ошибка 3",\
  "Ошибка 4",\
  "Ошибка 5",\
  "Ошибка 6",\
  "Ошибка 7",\
  "Ошибка 8",\
  "Ошибка 9",\
  "Ошибка 10",\
  "Ошибка 11",\
  "Ошибка 12",\
  "Ошибка 13",\
  "Ошибка 14",\
  "Ошибка 15",\
  "Ошибка 16",\
  "Ошибка 17",\
  "Ошибка 18",\
  "Ошибка 19",\
  "Ошибка 20",\
  "Ошибка 21",\
  "Ошибка 22",\
  "Ошибка 23",\
  "Ошибка 24",\
  "Ошибка 25",\
  "Ошибка 26",\
  "Ошибка 27",\
  "Ошибка 28",\
  "Ошибка 29",\
  "Ошибка 30",\
  "Ошибка 31",\
  "Ошибка 32",\
  "Ошибка 33",\
  "Ошибка 34",\
  "Ошибка 35",\
  "Ошибка 36",\
  "Ошибка 37",\
  "Ошибка 38",\
  "Ошибка 39",\
  "Ошибка 40",\
  "Ошибка 41",\
  "Ошибка 42",\
  "Ошибка 43",\
  "Ошибка 44",\
  "Ошибка 45",\
  "Ошибка 46",\
  "Ошибка 47",\
  "Ошибка 48",\
  "Ошибка 49"\
}
#define DIAGN_BO_MRZV_L_ENG_NAME_LIST \
{\
  "Error 0",\
  "Error 1",\
  "Error 2",\
  "Error 3",\
  "Error 4",\
  "Error 5",\
  "Error 6",\
  "Error 7",\
  "Error 8",\
  "Error 9",\
  "Error 10",\
  "Error 11",\
  "Error 12",\
  "Error 13",\
  "Error 14",\
  "Error 15",\
  "Error 16",\
  "Error 17",\
  "Error 18",\
  "Error 19",\
  "Error 20",\
  "Error 21",\
  "Error 22",\
  "Error 23",\
  "Error 24",\
  "Error 25",\
  "Error 26",\
  "Error 27",\
  "Error 28",\
  "Error 29",\
  "Error 30",\
  "Error 31",\
  "Error 32",\
  "Error 33",\
  "Error 34",\
  "Error 35",\
  "Error 36",\
  "Error 37",\
  "Error 38",\
  "Error 39",\
  "Error 40",\
  "Error 41",\
  "Error 42",\
  "Error 43",\
  "Error 44",\
  "Error 45",\
  "Error 46",\
  "Error 47",\
  "Error 48",\
  "Error 49"\
}

#endif
