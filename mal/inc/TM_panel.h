#ifndef __TM_PANEL__
#define __TM_PANEL__

#if ((All_NUMB_RANK_ELEM & 0x1f) == 0)

#define NUMBER_4BYTES_WORDS_FOR_FUBCTIOBS    (All_NUMB_RANK_ELEM >> 5)   

#else

#define NUMBER_4BYTES_WORDS_FOR_FUBCTIOBS    ((All_NUMB_RANK_ELEM >> 5) + 1)  

#endif

#define MAX_NUMBER_F_IN_PANEL           10

#define TM_UKR_TXT                     "Телемеханіка"
#define TM_RUS_TXT                     "Телемеханика"
#define TM_ENG_TXT                     "Telemechanics"

#define EXPL_TM_IT_UKR                 "Відображення інф.по телемеханіці"
#define EXPL_TM_IT_RUS                 "Отображение инф. о телемеханике"
#define EXPL_TM_IT_ENG                 "Show Telemechanics info"

#define TITLE_TM_PANEL_UKR             "Телемеханіка"
#define TITLE_TM_PANEL_RUS             "Телемеханика"
#define TITLE_TM_PANEL_ENG             "Telemechanics"

#define TITLE_TM_PAGE_1_UKR             "Вх./Вих."
#define EXPL_TM_PAGE_1_UKR              "Стан входів і виходів"
#define TITLE_TM_PAGE_1_RUS             "Вх./Вых."
#define EXPL_TM_PAGE_1_RUS              "Состояние входов и выходов"
#define TITLE_TM_PAGE_1_ENG             "I/O"
#define EXPL_TM_PAGE_1_ENG              "Inputs & Outputs state"

#define TITLE_TM_PAGE_2_UKR             "Функції"
#define EXPL_TM_PAGE_2_UKR              "Стан захистів і авт."
#define TITLE_TM_PAGE_2_RUS             "Функции"
#define EXPL_TM_PAGE_2_RUS              "Состояние защит и авт."
#define TITLE_TM_PAGE_2_ENG             "Functions"
#define EXPL_TM_PAGE_2_ENG              "Protection & Aut.state"

#define TITLE_TM_IO_COLUMN_1_UKR        "Д.Входи"
#define TITLE_TM_IO_COLUMN_1_RUS        "Д.Входы"
#define TITLE_TM_IO_COLUMN_1_ENG        "D.Input"

#define TITLE_TM_IO_COLUMN_2_UKR        "Д.Виходи"
#define TITLE_TM_IO_COLUMN_2_RUS        "Д.Выходы"
#define TITLE_TM_IO_COLUMN_2_ENG        "D.Output"

#define TITLE_TM_F_COLUMN_1_UKR        "Активні фунції"
#define TITLE_TM_F_COLUMN_1_RUS        "Активные функции"
#define TITLE_TM_F_COLUMN_1_ENG        "Active functions"

#define TITLE_TM_F_COLUMN_2_UKR        "Спрацьовані фукції"
#define TITLE_TM_F_COLUMN_2_RUS        "Сработавшие функции"
#define TITLE_TM_F_COLUMN_2_ENG        "Actuated functions"

#endif
