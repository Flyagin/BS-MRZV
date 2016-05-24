
#ifndef __LANGUAGE_CONST_H
#define __LANGUAGE_CONST_H

/*********************************************************************
*
*       Language const
*/
enum __language_list {
  UKR_LANG = 0,
  RUS_LANG,
  ENG_LANG,
  LANG_LIST_SIZE
};

#define GUI_DEFAULT_TEXT        " "

/** ukr ******************************************************/
#define CLOCK_UKR_TXT           "Годинник"
#define MEAS_UKR_TXT            "Вимірюва.."
#define RESCOUNT_UKR_TXT        "Ліч.ресу.."
#define IO_UKR_TXT              "Вх.-Виходи"
#define REG_UKR_TXT             "Реєстрат.."
#define SETT_UKR_TXT            "Налаштув.."
#define LANG_UKR_TXT            "Мова"
#define DIAGN_UKR_TXT           "Діагност.."
#define CONF_UKR_TXT            "Конфігур.."
#define RANK_UKR_TXT            "Ранжування"

//item explanations
#define EXPL_CLOCK_IT_UKR       "Відображення годинника"
#define EXPL_MEAS_IT_UKR        "Відображення панелі вимірювань"
#define EXPL_RESCOUNT_IT_UKR    "Відображення лічильника ресурсу"
#define EXPL_IO_IT_UKR          "Відображення входів-виходів"
#define EXPL_REG_IT_UKR         "Відображення панелі реєстраторів"
#define EXPL_SETT_IT_UKR        "Відображення панелі налаштувань"
#define EXPL_LANG_IT_UKR        "Відображення діалогового вікна вибору мови"
#define EXPL_DIAGN_IT_UKR       "Відображення панелі діагностики"
#define EXPL_CONF_IT_UKR        "Відображення панелі конфігурації"
#define EXPL_RANK_IT_UKR        "Відображення панелі ранжування"

/**Confirm dialog****************************/
#define CONFIRM_RANK_MSG_UKR    "Ввести зміни налаштувань ранжування"
#define CONFIRM_CONFIG_MSG_UKR  "Ввести зміни конфігурації"
/**Confirm dialog****************************/

/**Error dialog******************************/
/**Error dialog******************************/

/**Message dialog****************************/
#define MESSAGE_RANK_UKR        "Налаштування записані успішно. ESC-вихід з реж. редаг.; ENTER-повернення в реж. редаг."
/**Message dialog****************************/

/**measurements******************************/
#define MEAS_UKR_FOURIER_UNITS  {" A"," A"," A"," B"," B"," B"," B"," A"," B"," B"," A"," B"," A"," B"," A"}
#define MEAS_UKR_SUM_EQUATION_UNITS  {" A"," A"," A"," B"," B"," B"," B"," A"," B"," B"}
#define MEAS_UKR_ANGLE_UNITS    {"°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°"}
#define MEAS_UKR_RESISTANCES_UNITS {" Ом", " Ом", " Ом", " Ом", " Ом", " Ом", " Ом", " Ом", " Ом"}
#define MEAS_UKR_SPEED_RESISTANCE_CHANGE_UNITS {" Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек", " Ом/сек"}
#define MEAS_UKR_RESISTANCE_ANGLE_UNITS    {"°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°", "°"}
#define MEAS_UKR_OTHER_UNITS    {" Гц", " Гц", " °/сек", " А", " А", " А", " B", " B", " B", " B", " B", " Bт", " Bт", " Bт", " BАр", " BАр",\
                                 " BАр", " Bт", " Bт", " Bт", " Bт", " BАр", " Bт", " ", " ", " ", " кВт*год", " кВт*год", " кВАр*год", " кВАр*год", " кВАр*год", " кВАр*год"}

#define MEAS_UKR_FOURIER        "Фур'є"
#define MEAS_UKR_SUM_EQUATION   "Сума квадратів"
#define MEAS_UKR_ANGLE          "Кути"
#define MEAS_UKR_RESISTANCES    "Опори"
#define MEAS_UKR_SPEED_RESISTANCE_CHANGE "Швидк. зміни опору"
#define MEAS_UKR_RESISTANCE_ANGLE "Кут вект. опору"
#define MEAS_UKR_OTHER          "Інші вимірювання"

#define MEAS_UKR_FOURIER_EXPL   "Вимірювання Фур'є"
#define MEAS_UKR_SUM_EQUATION_EXPL "Сума квадратів"
#define MEAS_UKR_ANGLE_EXPL     "Кути "
#define MEAS_UKR_RESISTANCES_EXPL "Опори"
#define MEAS_UKR_SPEED_RESISTANCE_CHANGE_EXPL "Швидк. зміни опору"
#define MEAS_UKR_RESISTANCES_ANGLE_EXPL "Кут вект. опору"
#define MEAS_UKR_OTHER_EXPL     "Інші вимірювання"

#define MEAS_UKR_FRM            "Вимірювання"
/**measurements******************************/

/**configurations******************************/
#define CONF_UKR_FRM            "Конфігурація "

#define MESSAGE_CONFIG_UKR      "Параметри конфігурації записані успішно. ESC-вихід з реж. редаг.; ENTER-повернення в реж. редаг."

#define CONF_UKR_EXPL           "SHIFT - зберегти"

#define RANK_UKR_CONFIG_NAME_LIST {\
  "ДЗ",\
  "МСЗ",\
  "ТЗНП",\
  "ЗЗП",\
  "ЗНмін",\
  "ЗНмакс",\
  "АПВ",\
  "ПРВВ"\
}
/**configurations******************************/

/**ranking***********************************/
#define RANK_UKR_DISCR_INPUT    "Дискр.вх."
#define RANK_UKR_DISCR_OUTPUT   "Дискр.вих."
#define RANK_UKR_LED            "Св.інд."
#define RANK_UKR_DF_PLUS        "ОФ+"
#define RANK_UKR_DF_MINUS       "ОФ-"
#define RANK_UKR_DF_BLK         "ОФблк"
#define RANK_UKR_F              "ФК"
#define RANK_UKR_TRG_SET_PL     "Уст.ОТ+"
#define RANK_UKR_TRG_SET_MN     "Уст.ОТ-"
#define RANK_UKR_TRG_RST_PL     "Скид.ОТ+"
#define RANK_UKR_TRG_RST_MN     "Скид.ОТ-"
#define RANK_UKR_AN_DIG_REC     "Реєстратори"

#define RANK_UKR_DLG_TEXT1_DI   "Допуск д.вх."
#define RANK_UKR_DLG_TEXT2_DI   "Тип вх. сигналу"
#define RANK_UKR_DLG_TEXT3_DI   "Вид входу"
#define RANK_UKR_DLG_DI         "Налаштування дискр. входу №"
#define RANK_UKR_DLG_DI_EXPL    "ESC-вихід; ENTER-перехід в реж.редаг."
#define RANK_UKR_SIGNAL_TYPE_DI0 "постійний"
#define RANK_UKR_SIGNAL_TYPE_DI1 "змінний"
#define RANK_UKR_TYPE_DI0       "інверсний"
#define RANK_UKR_TYPE_DI1       "прямий"

#define RANK_UKR_DLG_DO         "Налаштування дискр. виходу №"
#define RANK_UKR_DLG_TEXT_DO    "Вид виходу"
#define RANK_UKR_TYPE_DO0       "сигнальний"
#define RANK_UKR_TYPE_DO1       "тригерний"

#define RANK_UKR_DLG_LED        "Налаштування св. інд. №"
#define RANK_UKR_DLG_TEXT_LED   "Вид св. інд."
#define RANK_UKR_TYPE_LED0      RANK_UKR_TYPE_DO0
#define RANK_UKR_TYPE_LED1      RANK_UKR_TYPE_DO1

#define RANK_UKR_DLG_DF         "Налаштування ОФ №"
#define RANK_UKR_DLG_TEXT1_DF   "Таймер паузи"
#define RANK_UKR_DLG_TEXT2_DF   "Таймер роботи"
#define RANK_UKR_DLG_TEXT3_DF   "Тип функції"
#define RANK_UKR_TYPE_DF0       "пряма"
#define RANK_UKR_TYPE_DF1       "інверсна"

#define RANK_UKR_DLG_AN_REC     "Налаштування Ан.реєстр."
#define RANK_UKR_DLG_TEXT1_AN_REC "Доавар. массив"
#define RANK_UKR_DLG_TEXT2_AN_REC "Післяавар. массив"

#define RANK_UKR_DISCR_INPUT_EXPL "1-дод.налаштування для вх."
#define RANK_UKR_DISCR_OUTPUT_EXPL "1-дод.налаштування для вих."
#define RANK_UKR_LED_EXPL       "1-дод.налаштування для св.інд."
#define RANK_UKR_DF_PLUS_EXPL   "1-дод.налаштування для ОФ+"
#define RANK_UKR_DF_MINUS_EXPL  "1-дод.налаштування для ОФ-"
#define RANK_UKR_DF_BLK_EXPL    "1-дод.налаштування для ОФблк"
#define RANK_UKR_F_EXPL         " "
#define RANK_UKR_TRG_SET_PL_EXPL " "
#define RANK_UKR_TRG_SET_MN_EXPL " "
#define RANK_UKR_TRG_RST_PL_EXPL " "
#define RANK_UKR_TRG_RST_MN_EXPL " "
#define RANK_UKR_AN_DIG_REC_EXPL "1-дод.налаштування для Ан.рег."

#define RANK_UKR_DI_NAMES_LIST1 {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",\
                                 "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",\
                                 "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32"}
#define RANK_UKR_DO_NAMES_LIST1 {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",\
                                 "11", "12", "13", "14", "15", "16"}
#define RANK_UKR_LED_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_UKR_DF_PLUS_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_UKR_DF_MINUS_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_UKR_DF_BLK_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_UKR_F_NAMES_LIST1  {"1", "2", "3", "4", "5", "6"}
#define RANK_UKR_TRG_SET_PL_NAMES_LIST1 {"1", "2", "3", "4", "5", "6", "7", "8"}
#define RANK_UKR_TRG_SET_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_UKR_TRG_RST_PL_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_UKR_TRG_RST_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_UKR_AN_DIG_REC_NAMES_LIST1 {"Ан.реєстр.", "Дискр.реєстр."}
#define RANK_UKR_FUNC_NAME_LIST {\
  "Вкл. ВВ от ДВ",\
  "Откл. ВВ",\
  "Контроль Вкл",\
  "Контроль Откл",\
  "Сброс Реле",\
  "Сброс индикации",\
  "Блокировка включения ВВ",\
  "Положение ВВ (выключателя)",\
  "Разблокировка включения ВВ",\
  "Привод ВВ",\
  "Неисправность цепей напр ДистЗ",\
  "Превышене номинального тока откл ВВ",\
  "Ресурс ВВ исчерпан",\
  "Критический ресурс ВВ",\
  "Работа БО",\
  "Работа БВ",\
  "Вход Определяемой функции 01",\
  "Вход Определяемой функции 02",\
  "Вход Определяемой функции 03",\
  "Вход Определяемой функции 04",\
  "Вход Определяемой функции 05",\
  "Вход Определяемой функции 06",\
  "Вход Определяемой функции 07",\
  "Вход Определяемой функции 08",\
  "Вход Определяемой функции 09",\
  "Вход Определяемой функции 10",\
  "Вход Определяемой функции 11",\
  "Вход Определяемой функции 12",\
  "Вход Определяемой функции 13",\
  "Вход Определяемой функции 14",\
  "Вход Определяемой функции 15",\
  "Вход Определяемой функции 16",\
  "Вх Уст   От1",\
  "Вх Сброс От1",\
  "Вх   Уст От2",\
  "Вх Сброс От2",\
  "Вх   Уст От3",\
  "Вх Сброс От3",\
  "Вх   Уст От4",\
  "Вх Сброс От4",\
  "Вх Уст   От5",\
  "Вх Сброс От5",\
  "Вх Уст   От6",\
  "Вх Сброс От6",\
  "Вх   Уст От7",\
  "Вх Сброс От7",\
  "Вх   Уст От8",\
  "Вх Сброс От8",\
  "Выход Оф_01",\
  "Выход Оф_02",\
  "Выход Оф_03",\
  "Выход Оф_04",\
  "Выход Оф_05",\
  "Выход Оф_06",\
  "Выход Оф_07",\
  "Выход Оф_08",\
  "Выход Оф_09",\
  "Выход Оф_10",\
  "Выход Оф_11",\
  "Выход Оф_12",\
  "Выход Оф_13",\
  "Выход Оф_14",\
  "Выход Оф_15",\
  "Выход Оф_16",\
  "Выход ОТ1",\
  "Выход ОТ2",\
  "Выход ОТ3",\
  "Выход ОТ4",\
  "Выход ОТ5",\
  "Выход ОТ6",\
  "Выход ОТ7",\
  "Выход ОТ8",\
  "Блокировка Дист З1",\
  "ПО ДЗ1 МФ",\
  "Сраб ДЗ1 МФ",\
  "ПО МТЗ ДЗ1",\
  "Сраб МТЗ ДЗ1",\
  "ПО ДЗ1 ОФ",\
  "Сраб ДЗ1 ОФ",\
  "Блокировка Дист З2",\
  "Сраб ДЗ2 МФ",\
  "ПО ДЗ2 МФ",\
  "Сраб МТЗ ДЗ2",\
  "ПО МТЗ ДЗ2",\
  "Сраб ДЗ2 ОФ",\
  "ПО ДЗ2 ОФ",\
  "Оперативное ускорение Дист З2",\
  "Телеускорение ускорение Дист З2",\
  "Блокировка Опер ускор Дист З2",\
  "Блокировка Дист З3",\
  "Сраб ДЗ3 МФ",\
  "ПО ДЗ3 МФ",\
  "Сраб МТЗ ДЗ3",\
  "ПО МТЗ ДЗ3",\
  "Сраб ДЗ3 ОФ",\
  "ПО ДЗ3 ОФ",\
  "Оперативное ускорение Дист З3",\
  "Телеускорение ускорение Дист З3",\
  "Блокировка Опер ускор Дист З3",\
  "Блокировка Дист З4",\
  "Сраб ДЗ4 МФ",\
  "ПО ДЗ4 МФ",\
  "Сраб МТЗ ДЗ4",\
  "ПО МТЗ ДЗ4",\
  "Сраб ДЗ4 ОФ",\
  "ПО ДЗ4 ОФ",\
  "Оперативное ускорение Дист З4",\
  "Телеускорение ускорение Дист З4",\
  "Блокировка Опер ускор Дист З4",\
  "Блокировка Дист З5",\
  "Сраб ДЗ5 МФ",\
  "ПО ДЗ5 МФ",\
  "Сраб МТЗ ДЗ5",\
  "ПО МТЗ ДЗ5",\
  "Сраб ДЗ5 ОФ",\
  "ПО ДЗ5 ОФ",\
  "Оперативное ускорение Дист З5",\
  "Телеускорение ускорение Дист З5",\
  "Блокировка Опер ускор Дист З5",\
  "2группа уставок Дист",\
  "Блокировка МТЗ1",\
  "Блокировка МТЗ2",\
  "Блокировка МТЗ3",\
  "Блокировка МТЗ4",\
  "Блокировка МТЗ5",\
  "Телеускорение   МТЗ2",\
  "Оперативное ускорение МТЗ2",\
  "Блокировка Опер ускор МТЗ2",\
  "Телеускорение   МТЗ3",\
  "Оперативное ускорение МТЗ3",\
  "Блокировка Опер ускор МТЗ3",\
  "Телеускорение   МТЗ4",\
  "Оперативное ускорение МТЗ4",\
  "Блокировка Опер ускор МТЗ4",\
  "Телеускорение   МТЗ5",\
  "Оперативное ускорение МТЗ5",\
  "Блокировка Опер ускор МТЗ5",\
  "2группа уставок МТЗ",\
  "Сектор МТЗН1Впер",\
  "Сектор МТЗН1Назад",\
  "Сраб ПО МТЗ1",\
  "Сраб ПО МТЗН1Впер",\
  "Сраб ПО МТЗН1Назад",\
  "Сраб ПО МТЗ1ПН",\
  "Сраб МТЗ1",\
  "Сектор МТЗН2Впер",\
  "Сектор МТЗН2Назад",\
  "Сраб ПО МТЗ2",\
  "Сраб ПО МТЗН2Впер",\
  "Сраб ПО МТЗН2Назад",\
  "Сраб ПО МТЗ2ПН",\
  "Сраб МТЗ2",\
  "Сектор МТЗН3Впер",\
  "Сектор МТЗН3Назад",\
  "Сраб ПО МТЗ3",\
  "Сраб ПО МТЗН3Впер",\
  "Сраб ПО МТЗН3Назад",\
  "Сраб ПО МТЗ3ПН",\
  "Сраб МТЗ3",\
  "Сектор МТЗН4Впер",\
  "Сектор МТЗН4Назад",\
  "Сраб ПО МТЗ4",\
  "Сраб ПО МТЗН4Впер",\
  "Сраб ПО МТЗН4Назад",\
  "Сраб ПО МТЗ4ПН",\
  "Сраб МТЗ4",\
  "Сектор МТЗН5Впер",\
  "Сектор МТЗН5Назад",\
  "Сраб ПО МТЗ5",\
  "Сраб ПО МТЗН5Впер",\
  "Сраб ПО МТЗН5Назад",\
  "Сраб ПО МТЗ5ПН",\
  "Сраб МТЗ5",\
  "Пуск АПВ от ДВ",\
  "Блокировка АПВ ОТ ДВ",\
  "АПВ1",\
  "АПВ2",\
  "Блокировка Umin1",\
  "Пуск Umin1",\
  "Блокировка Umin2",\
  "Пуск Umin2",\
  "Сраб ПО Umin1",\
  "Сраб Umin1",\
  "Сраб ПО Umin2",\
  "Сраб Umin2",\
  "Блокировка ТЗНП1",\
  "Оперативное ускорение ТЗНП1",\
  "Блокировка Опер ускор ТЗНП1",\
  "Блокировка ТЗНП2",\
  "Оперативное ускорение ТЗНП2",\
  "Блокировка Опер ускор ТЗНП2",\
  "Блокировка ТЗНП3",\
  "Оперативное ускорение ТЗНП3",\
  "Блокировка Опер ускор ТЗНП3",\
  "Блокировка ТЗНП4",\
  "Оперативное ускорение ТЗНП4",\
  "Блокировка Опер ускор ТЗНП4",\
  "Блокировка ТЗНП5",\
  "Оперативное ускорение ТЗНП5",\
  "Блокировка Опер ускор ТЗНП5",\
  "Телеускорение ТЗНП1",\
  "Телеускорение ТЗНП2",\
  "Телеускорение ТЗНП3",\
  "Телеускорение ТЗНП4",\
  "Телеускорение ТЗНП5",\
  "Сектор ТЗНП1",\
  "Сраб ПО ТЗНП1",\
  "Сраб ТЗНП1",\
  "ПО ЗНП1(3U0)",\
  "Сраб ЗНП1(3U0)",\
  "ПО ЗНП1(3I0)",\
  "Сраб ЗНП1(3I0)",\
  "Сектор ТЗНП2",\
  "Сраб ПО ТЗНП2",\
  "Сраб ТЗНП2",\
  "ПО ЗНП2(3U0)",\
  "Сраб ЗНП2(3U0)",\
  "ПО ЗНП2(3I0)",\
  "Сраб ЗНП2(3I0)",\
  "Сектор ТЗНП3",\
  "Сраб ПО ТЗНП3",\
  "Сраб ТЗНП3",\
  "ПО ЗНП3(3U0)",\
  "Сраб ЗНП3(3U0)",\
  "ПО ЗНП3(3I0)",\
  "Сраб ЗНП3(3I0)",\
  "Сектор ТЗНП4",\
  "Сраб ПО ТЗНП4",\
  "Сраб ТЗНП4",\
  "ПО ЗНП4(3U0)",\
  "Сраб ЗНП4(3U0)",\
  "ПО ЗНП4(3I0)",\
  "Сраб ЗНП4(3I0)",\
  "Сектор ТЗНП5",\
  "Сраб ПО ТЗНП5",\
  "Сраб ТЗНП5",\
  "ПО ЗНП5(3U0)",\
  "Сраб ЗНП5(3U0)",\
  "ПО ЗНП5(3I0)",\
  "Сраб ЗНП5(3I0)",\
  "Блокировка ЗОП1",\
  "Блокировка ЗОП2",\
  "2группа уставок ЗОП",\
  "Сектор НЗОП1Впер",\
  "Сектор НЗОП1Назад",\
  "ПО ЗОП1",\
  "ПО НЗОП1Впер",\
  "ПО НЗОП1ННазад",\
  "Сраб НЗОП1",\
  "Сектор НЗОП2Впер",\
  "Сектор НЗОП2Назад",\
  "ПО ЗОП2",\
  "ПО НЗОП2Впер",\
  "ПО НЗОП2ННазад",\
  "Сраб НЗОП2",\
  "Пуск УРОВ",\
  "Сраб УРОВ1",\
  "Сраб УРОВ1",\
  "Блокировка Umax1",\
  "Блокировка Umax2",\
  "Сраб ПО UMAX1",\
  "Сраб UMAX1",\
  "Сраб ПО UMAX2",\
  "Сраб UMAX2"\
}

#define RANK_UKR_FRM            "Ранжування"
/**ranking***********************************/

/**common************************************/
#define COMMON_UKR_TEXT         "Загальні"

#define COMMON_STAGE_TEXT_UKR   "Ступінь"

#define MESSAGE_ERR_TITLE_UKR  "Повідомлення"

#define ENTER_BUTTON_EXPL_UKR  "ENTER - вибір"
#define ESC_BUTTON_EXPL_UKR    "ESC - вихід"

#define EDIT_MODE_EXPL_UKR     "(Реж. редакт.)"

#define RANK_UKR_MS_UNIT        "мс"
#define RANK_UKR_SEC_UNIT       "сек"
/**common************************************/
/*************************************************************/

/** rus ******************************************************/
#define CLOCK_RUS_TXT           "Часы"
#define MEAS_RUS_TXT            "Измерения"
#define RESCOUNT_RUS_TXT        "Счетч.рес."
#define IO_RUS_TXT              "Вх.-Выходы"
#define REG_RUS_TXT             "Регистра.."
#define SETT_RUS_TXT            "Настройки"
#define LANG_RUS_TXT            "Язык"
#define DIAGN_RUS_TXT           "Диагност.."
#define CONF_RUS_TXT            "Конфигур.."
#define RANK_RUS_TXT            "Ранжиров.."

//item explanations
#define EXPL_CLOCK_IT_RUS       "Отображение часов"
#define EXPL_MEAS_IT_RUS        "Отображение панели измерений"
#define EXPL_RESCOUNT_IT_RUS    "Отображение счетчика ресурса"
#define EXPL_IO_IT_RUS          "Отображение входов-выходов"
#define EXPL_REG_IT_RUS         "Отображение панели регистраторов"
#define EXPL_SETT_IT_RUS        "Отображение панели настроек"
#define EXPL_LANG_IT_RUS        "Отображение диалогового окна выбора языка"
#define EXPL_DIAGN_IT_RUS       "Отображение панели диагностики"
#define EXPL_CONF_IT_RUS        "Отображение панели конфигурации"
#define EXPL_RANK_IT_RUS        "Отображение панели ранжирования"

/**Confirm dialog****************************/
#define CONFIRM_RANK_MSG_RUS    "Ввести изменения настроек ранжирования"
#define CONFIRM_CONFIG_MSG_RUS  "Ввести изменения конфигурации"
/**Confirm dialog****************************/

/**Error dialog******************************/
/**Error dialog******************************/

/**Message dialog****************************/
#define MESSAGE_RANK_RUS        "Настройки записаны успешно. ESC-выход из реж. редакт.; ENTER-возврат в реж. редакт."
/**Message dialog****************************/

/**measurements******************************/
#define MEAS_RUS_FOURIER        "Фурье"
#define MEAS_RUS_SUM_EQUATION   "Сумма квадратов"
#define MEAS_RUS_ANGLE          "Углы"
#define MEAS_RUS_RESISTANCES    "Сопротивления"
#define MEAS_RUS_SPEED_RESISTANCE_CHANGE "Скор. изм. сопрот."
#define MEAS_RUS_RESISTANCE_ANGLE "Угол вект. сопрот."
#define MEAS_RUS_OTHER          "Др. измерения"

#define MEAS_RUS_FOURIER_UNITS          MEAS_UKR_FOURIER_UNITS
#define MEAS_RUS_SUM_EQUATION_UNITS     MEAS_UKR_SUM_EQUATION_UNITS
#define MEAS_RUS_ANGLE_UNITS            MEAS_UKR_ANGLE_UNITS
#define MEAS_RUS_RESISTANCES_UNITS      MEAS_UKR_RESISTANCES_UNITS
#define MEAS_RUS_SPEED_RESISTANCE_CHANGE_UNITS MEAS_UKR_SPEED_RESISTANCE_CHANGE_UNITS
#define MEAS_RUS_RESISTANCE_ANGLE_UNITS MEAS_UKR_RESISTANCE_ANGLE_UNITS
#define MEAS_RUS_OTHER_UNITS            {" Гц", " Гц", " °/сек", " А", " А", " А", " B", " B", " B", " B", " B", " Bт", " Bт", " Bт", " BАр", " BАр",\
                                         " BАр", " BА", " BА", " BА", " Bт", " BАр", " BА", " ", " ", " ", " кВт*ч", " кВт*ч", " кВАр*ч", " кВАр*ч", " кВАр*ч", " кВАр*ч"}

#define MEAS_RUS_FOURIER_EXPL   "Измерения Фурье"
#define MEAS_RUS_SUM_EQUATION_EXPL "Сумма квадратов"
#define MEAS_RUS_ANGLE_EXPL     "Углы"
#define MEAS_RUS_RESISTANCES_EXPL "Сопротивления"
#define MEAS_RUS_SPEED_RESISTANCE_CHANGE_EXPL "Скор. изм. сопрот."
#define MEAS_RUS_RESISTANCES_ANGLE_EXPL "Угол вект. сопрот."
#define MEAS_RUS_OTHER_EXPL     "Др. измерения"

#define MEAS_UKR_WINDING_FIRST " (перв.)"
#define MEAS_RUS_WINDING_FIRST " (перв.)"
#define MEAS_ENG_WINDING_FIRST " (prim.)"
#define MEAS_UKR_WINDING_SECOND " (втор.)"
#define MEAS_RUS_WINDING_SECOND " (втор.)"
#define MEAS_ENG_WINDING_SECOND " (second.)"




#define MEAS_RUS_FRM            "Измерения"
/**measurements******************************/

/**configurations******************************/
#define CONF_RUS_FRM            "Конфигурация "

#define MESSAGE_CONFIG_RUS      "Параметры конфигурации записаны успешно. ESC-выход из реж. редакт.; ENTER-возврат в реж. редакт."

#define CONF_RUS_EXPL           "SHIFT - сохранить"

#define RANK_RUS_CONFIG_NAME_LIST {\
  "ДЗ",\
  "МТЗ",\
  "ТЗНП",\
  "ЗОП",\
  "ЗНмин",\
  "ЗНмакс",\
  "АПВ",\
  "УРОВ"\
}
/**configurations******************************/

/**ranking***********************************/
#define RANK_RUS_DISCR_INPUT    "Дискр.вх."
#define RANK_RUS_DISCR_OUTPUT   "Дискр.вых."
#define RANK_RUS_LED            "Св.инд."
#define RANK_RUS_DF_PLUS        "ОФ+"
#define RANK_RUS_DF_MINUS       "ОФ-"
#define RANK_RUS_DF_BLK         "ОФблк"
#define RANK_RUS_F              "ФК"
#define RANK_RUS_TRG_SET_PL     "Уст.ОТ+"
#define RANK_RUS_TRG_SET_MN     "Уст.ОТ-"
#define RANK_RUS_TRG_RST_PL     "Сбр.ОТ+"
#define RANK_RUS_TRG_RST_MN     "Сбр.ОТ-"
#define RANK_RUS_AN_DIG_REC     "Регистраторы"

#define RANK_RUS_DLG_TEXT1_DI   "Допуск д.вх."
#define RANK_RUS_DLG_TEXT2_DI   "Тип вх. сигнала"
#define RANK_RUS_DLG_TEXT3_DI   "Вид входа"
#define RANK_RUS_DLG_DI         "Настройки дискр. входа №"
#define RANK_RUS_DLG_DI_EXPL    "ESC-выход; ENTER-переход в реж.редакт."
#define RANK_RUS_SIGNAL_TYPE_DI0 "постоянный"
#define RANK_RUS_SIGNAL_TYPE_DI1 "переменный"
#define RANK_RUS_TYPE_DI0       "инверсный"
#define RANK_RUS_TYPE_DI1       "прямой"

#define RANK_RUS_DLG_DO         "Настройки дискр. выхода №"
#define RANK_RUS_DLG_TEXT_DO    "Вид выхода"
#define RANK_RUS_TYPE_DO0       "сигнальный"
#define RANK_RUS_TYPE_DO1       "триггерный"

#define RANK_RUS_DLG_LED        "Настройки св. инд. №"
#define RANK_RUS_DLG_TEXT_LED   "Вид св. инд."
#define RANK_RUS_TYPE_LED0      RANK_RUS_TYPE_DO0
#define RANK_RUS_TYPE_LED1      RANK_RUS_TYPE_DO1

#define RANK_RUS_DLG_DF         "Настройки ОФ №"
#define RANK_RUS_DLG_TEXT1_DF   "Таймер паузы"
#define RANK_RUS_DLG_TEXT2_DF   "Таймер работы"
#define RANK_RUS_DLG_TEXT3_DF   "Тип функции"
#define RANK_RUS_TYPE_DF0       "прямая"
#define RANK_RUS_TYPE_DF1       "инверсная"

#define RANK_RUS_DLG_AN_REC     "Настройки Ан.регистр."
#define RANK_RUS_DLG_TEXT1_AN_REC "Доавар. массив"
#define RANK_RUS_DLG_TEXT2_AN_REC "Послеавар. массив"

#define RANK_RUS_DISCR_INPUT_EXPL "1-доп.настройки для вх."
#define RANK_RUS_DISCR_OUTPUT_EXPL "1-доп.настройки для вых."
#define RANK_RUS_LED_EXPL       "1-доп.настройки для св.инд."
#define RANK_RUS_DF_PLUS_EXPL   "1-доп.настройки для ОФ+"
#define RANK_RUS_DF_MINUS_EXPL  "1-доп.настройки для ОФ-"
#define RANK_RUS_DF_BLK_EXPL    "1-доп.настройки для ОФблк"
#define RANK_RUS_F_EXPL         " "
#define RANK_RUS_TRG_SET_PL_EXPL " "
#define RANK_RUS_TRG_SET_MN_EXPL " "
#define RANK_RUS_TRG_RST_PL_EXPL " "
#define RANK_RUS_TRG_RST_MN_EXPL " "
#define RANK_RUS_AN_DIG_REC_EXPL "1-доп.настройки для Ан.рег."

#define RANK_RUS_DI_NAMES_LIST1 RANK_UKR_DI_NAMES_LIST1
#define RANK_RUS_DO_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_RUS_LED_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_RUS_DF_PLUS_NAMES_LIST1 RANK_UKR_DF_PLUS_NAMES_LIST1
#define RANK_RUS_DF_MINUS_NAMES_LIST1 RANK_UKR_DF_MINUS_NAMES_LIST1
#define RANK_RUS_DF_BLK_NAMES_LIST1 RANK_UKR_DF_BLK_NAMES_LIST1
#define RANK_RUS_F_NAMES_LIST1  RANK_UKR_F_NAMES_LIST1
#define RANK_RUS_TRG_SET_PL_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_RUS_TRG_SET_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_RUS_TRG_RST_PL_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_RUS_TRG_RST_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_RUS_AN_DIG_REC_NAMES_LIST1 {"Ан.рег.", "Дискр.рег."}
#define RANK_RUS_FUNC_NAME_LIST {\
  "Вкл. ВВ от ДВ",\
  "Откл. ВВ",\
  "Контроль Вкл",\
  "Контроль Откл",\
  "Сброс Реле",\
  "Сброс индикации",\
  "Блокировка включения ВВ",\
  "Положение ВВ (выключателя)",\
  "Разблокировка включения ВВ",\
  "Привод ВВ",\
  "Неисправность цепей напр ДистЗ",\
  "Превышене номинального тока откл ВВ",\
  "Ресурс ВВ исчерпан",\
  "Критический ресурс ВВ",\
  "Работа БО",\
  "Работа БВ",\
  "Вход Определяемой функции 01",\
  "Вход Определяемой функции 02",\
  "Вход Определяемой функции 03",\
  "Вход Определяемой функции 04",\
  "Вход Определяемой функции 05",\
  "Вход Определяемой функции 06",\
  "Вход Определяемой функции 07",\
  "Вход Определяемой функции 08",\
  "Вход Определяемой функции 09",\
  "Вход Определяемой функции 10",\
  "Вход Определяемой функции 11",\
  "Вход Определяемой функции 12",\
  "Вход Определяемой функции 13",\
  "Вход Определяемой функции 14",\
  "Вход Определяемой функции 15",\
  "Вход Определяемой функции 16",\
  "Вх Уст   От1",\
  "Вх Сброс От1",\
  "Вх   Уст От2",\
  "Вх Сброс От2",\
  "Вх   Уст От3",\
  "Вх Сброс От3",\
  "Вх   Уст От4",\
  "Вх Сброс От4",\
  "Вх Уст   От5",\
  "Вх Сброс От5",\
  "Вх Уст   От6",\
  "Вх Сброс От6",\
  "Вх   Уст От7",\
  "Вх Сброс От7",\
  "Вх   Уст От8",\
  "Вх Сброс От8",\
  "Выход Оф_01",\
  "Выход Оф_02",\
  "Выход Оф_03",\
  "Выход Оф_04",\
  "Выход Оф_05",\
  "Выход Оф_06",\
  "Выход Оф_07",\
  "Выход Оф_08",\
  "Выход Оф_09",\
  "Выход Оф_10",\
  "Выход Оф_11",\
  "Выход Оф_12",\
  "Выход Оф_13",\
  "Выход Оф_14",\
  "Выход Оф_15",\
  "Выход Оф_16",\
  "Выход ОТ1",\
  "Выход ОТ2",\
  "Выход ОТ3",\
  "Выход ОТ4",\
  "Выход ОТ5",\
  "Выход ОТ6",\
  "Выход ОТ7",\
  "Выход ОТ8",\
  "Блокировка Дист З1",\
  "ПО ДЗ1 МФ",\
  "Сраб ДЗ1 МФ",\
  "ПО МТЗ ДЗ1",\
  "Сраб МТЗ ДЗ1",\
  "ПО ДЗ1 ОФ",\
  "Сраб ДЗ1 ОФ",\
  "Блокировка Дист З2",\
  "Сраб ДЗ2 МФ",\
  "ПО ДЗ2 МФ",\
  "Сраб МТЗ ДЗ2",\
  "ПО МТЗ ДЗ2",\
  "Сраб ДЗ2 ОФ",\
  "ПО ДЗ2 ОФ",\
  "Оперативное ускорение Дист З2",\
  "Телеускорение ускорение Дист З2",\
  "Блокировка Опер ускор Дист З2",\
  "Блокировка Дист З3",\
  "Сраб ДЗ3 МФ",\
  "ПО ДЗ3 МФ",\
  "Сраб МТЗ ДЗ3",\
  "ПО МТЗ ДЗ3",\
  "Сраб ДЗ3 ОФ",\
  "ПО ДЗ3 ОФ",\
  "Оперативное ускорение Дист З3",\
  "Телеускорение ускорение Дист З3",\
  "Блокировка Опер ускор Дист З3",\
  "Блокировка Дист З4",\
  "Сраб ДЗ4 МФ",\
  "ПО ДЗ4 МФ",\
  "Сраб МТЗ ДЗ4",\
  "ПО МТЗ ДЗ4",\
  "Сраб ДЗ4 ОФ",\
  "ПО ДЗ4 ОФ",\
  "Оперативное ускорение Дист З4",\
  "Телеускорение ускорение Дист З4",\
  "Блокировка Опер ускор Дист З4",\
  "Блокировка Дист З5",\
  "Сраб ДЗ5 МФ",\
  "ПО ДЗ5 МФ",\
  "Сраб МТЗ ДЗ5",\
  "ПО МТЗ ДЗ5",\
  "Сраб ДЗ5 ОФ",\
  "ПО ДЗ5 ОФ",\
  "Оперативное ускорение Дист З5",\
  "Телеускорение ускорение Дист З5",\
  "Блокировка Опер ускор Дист З5",\
  "2группа уставок Дист",\
  "Блокировка МТЗ1",\
  "Блокировка МТЗ2",\
  "Блокировка МТЗ3",\
  "Блокировка МТЗ4",\
  "Блокировка МТЗ5",\
  "Телеускорение   МТЗ2",\
  "Оперативное ускорение МТЗ2",\
  "Блокировка Опер ускор МТЗ2",\
  "Телеускорение   МТЗ3",\
  "Оперативное ускорение МТЗ3",\
  "Блокировка Опер ускор МТЗ3",\
  "Телеускорение   МТЗ4",\
  "Оперативное ускорение МТЗ4",\
  "Блокировка Опер ускор МТЗ4",\
  "Телеускорение   МТЗ5",\
  "Оперативное ускорение МТЗ5",\
  "Блокировка Опер ускор МТЗ5",\
  "2группа уставок МТЗ",\
  "Сектор МТЗН1Впер",\
  "Сектор МТЗН1Назад",\
  "Сраб ПО МТЗ1",\
  "Сраб ПО МТЗН1Впер",\
  "Сраб ПО МТЗН1Назад",\
  "Сраб ПО МТЗ1ПН",\
  "Сраб МТЗ1",\
  "Сектор МТЗН2Впер",\
  "Сектор МТЗН2Назад",\
  "Сраб ПО МТЗ2",\
  "Сраб ПО МТЗН2Впер",\
  "Сраб ПО МТЗН2Назад",\
  "Сраб ПО МТЗ2ПН",\
  "Сраб МТЗ2",\
  "Сектор МТЗН3Впер",\
  "Сектор МТЗН3Назад",\
  "Сраб ПО МТЗ3",\
  "Сраб ПО МТЗН3Впер",\
  "Сраб ПО МТЗН3Назад",\
  "Сраб ПО МТЗ3ПН",\
  "Сраб МТЗ3",\
  "Сектор МТЗН4Впер",\
  "Сектор МТЗН4Назад",\
  "Сраб ПО МТЗ4",\
  "Сраб ПО МТЗН4Впер",\
  "Сраб ПО МТЗН4Назад",\
  "Сраб ПО МТЗ4ПН",\
  "Сраб МТЗ4",\
  "Сектор МТЗН5Впер",\
  "Сектор МТЗН5Назад",\
  "Сраб ПО МТЗ5",\
  "Сраб ПО МТЗН5Впер",\
  "Сраб ПО МТЗН5Назад",\
  "Сраб ПО МТЗ5ПН",\
  "Сраб МТЗ5",\
  "Пуск АПВ от ДВ",\
  "Блокировка АПВ ОТ ДВ",\
  "АПВ1",\
  "АПВ2",\
  "Блокировка Umin1",\
  "Пуск Umin1",\
  "Блокировка Umin2",\
  "Пуск Umin2",\
  "Сраб ПО Umin1",\
  "Сраб Umin1",\
  "Сраб ПО Umin2",\
  "Сраб Umin2",\
  "Блокировка ТЗНП1",\
  "Оперативное ускорение ТЗНП1",\
  "Блокировка Опер ускор ТЗНП1",\
  "Блокировка ТЗНП2",\
  "Оперативное ускорение ТЗНП2",\
  "Блокировка Опер ускор ТЗНП2",\
  "Блокировка ТЗНП3",\
  "Оперативное ускорение ТЗНП3",\
  "Блокировка Опер ускор ТЗНП3",\
  "Блокировка ТЗНП4",\
  "Оперативное ускорение ТЗНП4",\
  "Блокировка Опер ускор ТЗНП4",\
  "Блокировка ТЗНП5",\
  "Оперативное ускорение ТЗНП5",\
  "Блокировка Опер ускор ТЗНП5",\
  "Телеускорение ТЗНП1",\
  "Телеускорение ТЗНП2",\
  "Телеускорение ТЗНП3",\
  "Телеускорение ТЗНП4",\
  "Телеускорение ТЗНП5",\
  "Сектор ТЗНП1",\
  "Сраб ПО ТЗНП1",\
  "Сраб ТЗНП1",\
  "ПО ЗНП1(3U0)",\
  "Сраб ЗНП1(3U0)",\
  "ПО ЗНП1(3I0)",\
  "Сраб ЗНП1(3I0)",\
  "Сектор ТЗНП2",\
  "Сраб ПО ТЗНП2",\
  "Сраб ТЗНП2",\
  "ПО ЗНП2(3U0)",\
  "Сраб ЗНП2(3U0)",\
  "ПО ЗНП2(3I0)",\
  "Сраб ЗНП2(3I0)",\
  "Сектор ТЗНП3",\
  "Сраб ПО ТЗНП3",\
  "Сраб ТЗНП3",\
  "ПО ЗНП3(3U0)",\
  "Сраб ЗНП3(3U0)",\
  "ПО ЗНП3(3I0)",\
  "Сраб ЗНП3(3I0)",\
  "Сектор ТЗНП4",\
  "Сраб ПО ТЗНП4",\
  "Сраб ТЗНП4",\
  "ПО ЗНП4(3U0)",\
  "Сраб ЗНП4(3U0)",\
  "ПО ЗНП4(3I0)",\
  "Сраб ЗНП4(3I0)",\
  "Сектор ТЗНП5",\
  "Сраб ПО ТЗНП5",\
  "Сраб ТЗНП5",\
  "ПО ЗНП5(3U0)",\
  "Сраб ЗНП5(3U0)",\
  "ПО ЗНП5(3I0)",\
  "Сраб ЗНП5(3I0)",\
  "Блокировка ЗОП1",\
  "Блокировка ЗОП2",\
  "2группа уставок ЗОП",\
  "Сектор НЗОП1Впер",\
  "Сектор НЗОП1Назад",\
  "ПО ЗОП1",\
  "ПО НЗОП1Впер",\
  "ПО НЗОП1ННазад",\
  "Сраб НЗОП1",\
  "Сектор НЗОП2Впер",\
  "Сектор НЗОП2Назад",\
  "ПО ЗОП2",\
  "ПО НЗОП2Впер",\
  "ПО НЗОП2ННазад",\
  "Сраб НЗОП2",\
  "Пуск УРОВ",\
  "Сраб УРОВ1",\
  "Сраб УРОВ1",\
  "Блокировка Umax1",\
  "Блокировка Umax2",\
  "Сраб ПО UMAX1",\
  "Сраб UMAX1",\
  "Сраб ПО UMAX2",\
  "Сраб UMAX2"\
}

#define RANK_RUS_FRM            "Ранжирование"
/**ranking***********************************/

/**common************************************/
#define COMMON_RUS_TEXT         "Общие"

#define COMMON_STAGE_TEXT_RUS   "Ступень"

#define MESSAGE_ERR_TITLE_RUS   "Сообщение"

#define ENTER_BUTTON_EXPL_RUS   "ENTER - выбор"
#define ESC_BUTTON_EXPL_RUS     "ESC - выход"

#define EDIT_MODE_EXPL_RUS      "(Реж. редакт.)"

#define RANK_RUS_MS_UNIT        "мс"
#define RANK_RUS_SEC_UNIT       "сек"
/**common************************************/
/*************************************************************/

/** eng ******************************************************/
#define CLOCK_ENG_TXT           "Clock"
#define MEAS_ENG_TXT            "Measurem.."
#define RESCOUNT_ENG_TXT        "Res.Count."
#define IO_ENG_TXT              "In.-Outp.."
#define REG_ENG_TXT             "Recorders"
#define SETT_ENG_TXT            "Settings"
#define LANG_ENG_TXT            "Language"
#define DIAGN_ENG_TXT           "Diagnost.."
#define CONF_ENG_TXT            "Configur.."
#define RANK_ENG_TXT            "Ranking"

//item explanations
#define EXPL_CLOCK_IT_ENG       "Show clock"
#define EXPL_MEAS_IT_ENG        "Show measurements panel"
#define EXPL_RESCOUNT_IT_ENG    "Show resource counter"
#define EXPL_IO_IT_ENG          "Show inputs-outputs panel"
#define EXPL_REG_IT_ENG         "Show recorders panel"
#define EXPL_SETT_IT_ENG        "Show settings panel"
#define EXPL_LANG_IT_ENG        "Show languages dialog panel"
#define EXPL_DIAGN_IT_ENG       "Show diagnostic panel"
#define EXPL_CONF_IT_ENG        "Show configuration panel"
#define EXPL_RANK_IT_ENG        "Show ranking panel"

/**Confirm dialog****************************/
#define CONFIRM_RANK_MSG_ENG    "Enter changes of ranking settings"
#define CONFIRM_CONFIG_MSG_ENG  "Enter changes of configuration"
/**Confirm dialog****************************/

/**Error dialog******************************/
/**Error dialog******************************/

/**Message dialog****************************/
#define MESSAGE_RANK_ENG        "Settings saved successfully. ESC-exit from editing mode; ENTER-back in the editing mode"
/**Message dialog****************************/

/**measurements******************************/
#define MEAS_ENG_FOURIER        "Fourier"
#define MEAS_ENG_SUM_EQUATION   "Squares sum"
#define MEAS_ENG_ANGLE          "Angles"
#define MEAS_ENG_RESISTANCES    "Resistances"
#define MEAS_ENG_SPEED_RESISTANCE_CHANGE "Speed resist. change"
#define MEAS_ENG_RESISTANCE_ANGLE "Angle of resist. vec."
#define MEAS_ENG_OTHER          "Other meas."

#define MEAS_ENG_FOURIER_EXPL   "Fourier measurements"
#define MEAS_ENG_SUM_EQUATION_EXPL "Squares sum"
#define MEAS_ENG_ANGLE_EXPL     "Angles"
#define MEAS_ENG_RESISTANCES_EXPL "Resistances"
#define MEAS_ENG_SPEED_RESISTANCE_CHANGE_EXPL "Speed resist. change"
#define MEAS_ENG_RESISTANCES_ANGLE_EXPL "Angle of resist. vec."
#define MEAS_ENG_OTHER_EXPL     "Other meas."

#define MEAS_ENG_FRM            "Measurements"

#define MEAS_ENG_FOURIER_UNITS          {" A"," A"," A"," V"," V"," V"," V"," A"," V"," V"," A"," V"," A"," V"," A"}
#define MEAS_ENG_SUM_EQUATION_UNITS     {" A"," A"," A"," V"," V"," V"," V"," A"," V"," V"}
#define MEAS_ENG_ANGLE_UNITS            MEAS_UKR_ANGLE_UNITS
#define MEAS_ENG_RESISTANCES_UNITS      {" Ohm", " Ohm", " Ohm", " Ohm", " Ohm", " Ohm", " Ohm", " Ohm", " Ohm"}
#define MEAS_ENG_SPEED_RESISTANCE_CHANGE_UNITS {" Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s", " Ohm/s"}
#define MEAS_ENG_RESISTANCE_ANGLE_UNITS MEAS_UKR_RESISTANCE_ANGLE_UNITS
#define MEAS_ENG_OTHER_UNITS            {" Hz", " Hz", " °/s", " А", " А", " А", " V", " V", " V", " V", " V", " W", " W", " W", " VAr", " VAr",\
                                         " VAr", " VA", " VA", " VA", " W", " VAr", " VA", " ", " ", " ", " kW*h", " kW*h", " kVAr*h", " kVAr*h", " kVAr*h", " kVAr*h"}
/**measurements******************************/

/**configurations******************************/
#define CONF_ENG_FRM            "Configuration "

#define MESSAGE_CONFIG_ENG      "Configuration saved successfully. ESC-exit from editing mode; ENTER-back in the editing mode"

#define CONF_ENG_EXPL           "SHIFT - save"

#define RANK_ENG_CONFIG_NAME_LIST {\
  "DSTP",\
  "DROCP",\
  "DRERTH",\
  "NSP",\
  "UMIN",\
  "UMAX",\
  "RCLR",\
  "BRF"\
}
/**configurations******************************/

/**ranking***********************************/
#define RANK_ENG_DISCR_INPUT    "Discr.inp."
#define RANK_ENG_DISCR_OUTPUT   "Discr.outp."
#define RANK_ENG_LED            "LEDs"
#define RANK_ENG_DF_PLUS        "DF+"
#define RANK_ENG_DF_MINUS       "DF-"
#define RANK_ENG_DF_BLK         "DFblk"
#define RANK_ENG_F              "FB"
#define RANK_ENG_TRG_SET_PL     "Set DT+"
#define RANK_ENG_TRG_SET_MN     "Set DT-"
#define RANK_ENG_TRG_RST_PL     "Rst.DT+"
#define RANK_ENG_TRG_RST_MN     "Rst.DT-"
#define RANK_ENG_AN_DIG_REC     "Recorders"

#define RANK_ENG_DLG_TEXT1_DI   "Duration d.inp."
#define RANK_ENG_DLG_TEXT2_DI   "Type inp.signal"
#define RANK_ENG_DLG_TEXT3_DI   "Type input"
#define RANK_ENG_DLG_DI         "Settings of discr. input №"
#define RANK_ENG_DLG_DI_EXPL    "ESC-exit; ENTER-set edit mode"
#define RANK_ENG_SIGNAL_TYPE_DI0 "direct"
#define RANK_ENG_SIGNAL_TYPE_DI1 "alternating"
#define RANK_ENG_TYPE_DI0       "inverse"
#define RANK_ENG_TYPE_DI1       "forward"

#define RANK_ENG_DLG_DO         "Settings of discr. output №"
#define RANK_ENG_DLG_TEXT_DO    "Type output"
#define RANK_ENG_TYPE_DO0       "signal"
#define RANK_ENG_TYPE_DO1       "trigger"

#define RANK_ENG_DLG_LED        "Settings of LED №"
#define RANK_ENG_DLG_TEXT_LED   "Type LED"
#define RANK_ENG_TYPE_LED0      RANK_ENG_TYPE_DO0
#define RANK_ENG_TYPE_LED1      RANK_ENG_TYPE_DO1

#define RANK_ENG_DLG_DF         "Settings of DF №"
#define RANK_ENG_DLG_TEXT1_DF   "Delay timer"
#define RANK_ENG_DLG_TEXT2_DF   "Work timer"
#define RANK_ENG_DLG_TEXT3_DF   "Function type"
#define RANK_ENG_TYPE_DF0       "forward"
#define RANK_ENG_TYPE_DF1       "inverse"

#define RANK_ENG_DLG_AN_REC     "Settings of An.rec."
#define RANK_ENG_DLG_TEXT1_AN_REC "Pre-Fault array"
#define RANK_ENG_DLG_TEXT2_AN_REC "Post-Fault array"

#define RANK_ENG_DISCR_INPUT_EXPL "1-add.settings for inp."
#define RANK_ENG_DISCR_OUTPUT_EXPL "1-add.settings for outp."
#define RANK_ENG_LED_EXPL       "1-add.settings for LEDs"
#define RANK_ENG_DF_PLUS_EXPL   "1-add.settings for DF+"
#define RANK_ENG_DF_MINUS_EXPL  "1-add.settings for DF-"
#define RANK_ENG_DF_BLK_EXPL    "1-add.settings for DFblk"
#define RANK_ENG_F_EXPL         " "
#define RANK_ENG_TRG_SET_PL_EXPL " "
#define RANK_ENG_TRG_SET_MN_EXPL " "
#define RANK_ENG_TRG_RST_PL_EXPL " "
#define RANK_ENG_TRG_RST_MN_EXPL " "
#define RANK_ENG_AN_DIG_REC_EXPL "1-add.settings for An.rec."

#define RANK_ENG_DI_NAMES_LIST1 RANK_UKR_DI_NAMES_LIST1
#define RANK_ENG_DO_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_ENG_LED_NAMES_LIST1 RANK_UKR_DO_NAMES_LIST1
#define RANK_ENG_DF_PLUS_NAMES_LIST1 RANK_UKR_DF_PLUS_NAMES_LIST1
#define RANK_ENG_DF_MINUS_NAMES_LIST1 RANK_UKR_DF_MINUS_NAMES_LIST1
#define RANK_ENG_DF_BLK_NAMES_LIST1 RANK_UKR_DF_BLK_NAMES_LIST1
#define RANK_ENG_F_NAMES_LIST1  RANK_UKR_F_NAMES_LIST1
#define RANK_ENG_TRG_SET_PL_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_ENG_TRG_SET_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_ENG_TRG_RST_PL_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_ENG_TRG_RST_MN_NAMES_LIST1 RANK_UKR_TRG_SET_PL_NAMES_LIST1
#define RANK_ENG_AN_DIG_REC_NAMES_LIST1 {"An.rec.", "Discr.rec."}
#define RANK_ENG_FUNC_NAME_LIST {\
  "Вкл. ВВ от ДВ",\
  "Откл. ВВ",\
  "Контроль Вкл",\
  "Контроль Откл",\
  "Сброс Реле",\
  "Сброс индикации",\
  "Блокировка включения ВВ",\
  "Положение ВВ (выключателя)",\
  "Разблокировка включения ВВ",\
  "Привод ВВ",\
  "Неисправность цепей напр ДистЗ",\
  "Превышене номинального тока откл ВВ",\
  "Ресурс ВВ исчерпан",\
  "Критический ресурс ВВ",\
  "Работа БО",\
  "Работа БВ",\
  "Вход Определяемой функции 01",\
  "Вход Определяемой функции 02",\
  "Вход Определяемой функции 03",\
  "Вход Определяемой функции 04",\
  "Вход Определяемой функции 05",\
  "Вход Определяемой функции 06",\
  "Вход Определяемой функции 07",\
  "Вход Определяемой функции 08",\
  "Вход Определяемой функции 09",\
  "Вход Определяемой функции 10",\
  "Вход Определяемой функции 11",\
  "Вход Определяемой функции 12",\
  "Вход Определяемой функции 13",\
  "Вход Определяемой функции 14",\
  "Вход Определяемой функции 15",\
  "Вход Определяемой функции 16",\
  "Вх Уст   От1",\
  "Вх Сброс От1",\
  "Вх   Уст От2",\
  "Вх Сброс От2",\
  "Вх   Уст От3",\
  "Вх Сброс От3",\
  "Вх   Уст От4",\
  "Вх Сброс От4",\
  "Вх Уст   От5",\
  "Вх Сброс От5",\
  "Вх Уст   От6",\
  "Вх Сброс От6",\
  "Вх   Уст От7",\
  "Вх Сброс От7",\
  "Вх   Уст От8",\
  "Вх Сброс От8",\
  "Выход Оф_01",\
  "Выход Оф_02",\
  "Выход Оф_03",\
  "Выход Оф_04",\
  "Выход Оф_05",\
  "Выход Оф_06",\
  "Выход Оф_07",\
  "Выход Оф_08",\
  "Выход Оф_09",\
  "Выход Оф_10",\
  "Выход Оф_11",\
  "Выход Оф_12",\
  "Выход Оф_13",\
  "Выход Оф_14",\
  "Выход Оф_15",\
  "Выход Оф_16",\
  "Выход ОТ1",\
  "Выход ОТ2",\
  "Выход ОТ3",\
  "Выход ОТ4",\
  "Выход ОТ5",\
  "Выход ОТ6",\
  "Выход ОТ7",\
  "Выход ОТ8",\
  "Блокировка Дист З1",\
  "ПО ДЗ1 МФ",\
  "Сраб ДЗ1 МФ",\
  "ПО МТЗ ДЗ1",\
  "Сраб МТЗ ДЗ1",\
  "ПО ДЗ1 ОФ",\
  "Сраб ДЗ1 ОФ",\
  "Блокировка Дист З2",\
  "Сраб ДЗ2 МФ",\
  "ПО ДЗ2 МФ",\
  "Сраб МТЗ ДЗ2",\
  "ПО МТЗ ДЗ2",\
  "Сраб ДЗ2 ОФ",\
  "ПО ДЗ2 ОФ",\
  "Оперативное ускорение Дист З2",\
  "Телеускорение ускорение Дист З2",\
  "Блокировка Опер ускор Дист З2",\
  "Блокировка Дист З3",\
  "Сраб ДЗ3 МФ",\
  "ПО ДЗ3 МФ",\
  "Сраб МТЗ ДЗ3",\
  "ПО МТЗ ДЗ3",\
  "Сраб ДЗ3 ОФ",\
  "ПО ДЗ3 ОФ",\
  "Оперативное ускорение Дист З3",\
  "Телеускорение ускорение Дист З3",\
  "Блокировка Опер ускор Дист З3",\
  "Блокировка Дист З4",\
  "Сраб ДЗ4 МФ",\
  "ПО ДЗ4 МФ",\
  "Сраб МТЗ ДЗ4",\
  "ПО МТЗ ДЗ4",\
  "Сраб ДЗ4 ОФ",\
  "ПО ДЗ4 ОФ",\
  "Оперативное ускорение Дист З4",\
  "Телеускорение ускорение Дист З4",\
  "Блокировка Опер ускор Дист З4",\
  "Блокировка Дист З5",\
  "Сраб ДЗ5 МФ",\
  "ПО ДЗ5 МФ",\
  "Сраб МТЗ ДЗ5",\
  "ПО МТЗ ДЗ5",\
  "Сраб ДЗ5 ОФ",\
  "ПО ДЗ5 ОФ",\
  "Оперативное ускорение Дист З5",\
  "Телеускорение ускорение Дист З5",\
  "Блокировка Опер ускор Дист З5",\
  "2группа уставок Дист",\
  "Блокировка МТЗ1",\
  "Блокировка МТЗ2",\
  "Блокировка МТЗ3",\
  "Блокировка МТЗ4",\
  "Блокировка МТЗ5",\
  "Телеускорение   МТЗ2",\
  "Оперативное ускорение МТЗ2",\
  "Блокировка Опер ускор МТЗ2",\
  "Телеускорение   МТЗ3",\
  "Оперативное ускорение МТЗ3",\
  "Блокировка Опер ускор МТЗ3",\
  "Телеускорение   МТЗ4",\
  "Оперативное ускорение МТЗ4",\
  "Блокировка Опер ускор МТЗ4",\
  "Телеускорение   МТЗ5",\
  "Оперативное ускорение МТЗ5",\
  "Блокировка Опер ускор МТЗ5",\
  "2группа уставок МТЗ",\
  "Сектор МТЗН1Впер",\
  "Сектор МТЗН1Назад",\
  "Сраб ПО МТЗ1",\
  "Сраб ПО МТЗН1Впер",\
  "Сраб ПО МТЗН1Назад",\
  "Сраб ПО МТЗ1ПН",\
  "Сраб МТЗ1",\
  "Сектор МТЗН2Впер",\
  "Сектор МТЗН2Назад",\
  "Сраб ПО МТЗ2",\
  "Сраб ПО МТЗН2Впер",\
  "Сраб ПО МТЗН2Назад",\
  "Сраб ПО МТЗ2ПН",\
  "Сраб МТЗ2",\
  "Сектор МТЗН3Впер",\
  "Сектор МТЗН3Назад",\
  "Сраб ПО МТЗ3",\
  "Сраб ПО МТЗН3Впер",\
  "Сраб ПО МТЗН3Назад",\
  "Сраб ПО МТЗ3ПН",\
  "Сраб МТЗ3",\
  "Сектор МТЗН4Впер",\
  "Сектор МТЗН4Назад",\
  "Сраб ПО МТЗ4",\
  "Сраб ПО МТЗН4Впер",\
  "Сраб ПО МТЗН4Назад",\
  "Сраб ПО МТЗ4ПН",\
  "Сраб МТЗ4",\
  "Сектор МТЗН5Впер",\
  "Сектор МТЗН5Назад",\
  "Сраб ПО МТЗ5",\
  "Сраб ПО МТЗН5Впер",\
  "Сраб ПО МТЗН5Назад",\
  "Сраб ПО МТЗ5ПН",\
  "Сраб МТЗ5",\
  "Пуск АПВ от ДВ",\
  "Блокировка АПВ ОТ ДВ",\
  "АПВ1",\
  "АПВ2",\
  "Блокировка Umin1",\
  "Пуск Umin1",\
  "Блокировка Umin2",\
  "Пуск Umin2",\
  "Сраб ПО Umin1",\
  "Сраб Umin1",\
  "Сраб ПО Umin2",\
  "Сраб Umin2",\
  "Блокировка ТЗНП1",\
  "Оперативное ускорение ТЗНП1",\
  "Блокировка Опер ускор ТЗНП1",\
  "Блокировка ТЗНП2",\
  "Оперативное ускорение ТЗНП2",\
  "Блокировка Опер ускор ТЗНП2",\
  "Блокировка ТЗНП3",\
  "Оперативное ускорение ТЗНП3",\
  "Блокировка Опер ускор ТЗНП3",\
  "Блокировка ТЗНП4",\
  "Оперативное ускорение ТЗНП4",\
  "Блокировка Опер ускор ТЗНП4",\
  "Блокировка ТЗНП5",\
  "Оперативное ускорение ТЗНП5",\
  "Блокировка Опер ускор ТЗНП5",\
  "Телеускорение ТЗНП1",\
  "Телеускорение ТЗНП2",\
  "Телеускорение ТЗНП3",\
  "Телеускорение ТЗНП4",\
  "Телеускорение ТЗНП5",\
  "Сектор ТЗНП1",\
  "Сраб ПО ТЗНП1",\
  "Сраб ТЗНП1",\
  "ПО ЗНП1(3U0)",\
  "Сраб ЗНП1(3U0)",\
  "ПО ЗНП1(3I0)",\
  "Сраб ЗНП1(3I0)",\
  "Сектор ТЗНП2",\
  "Сраб ПО ТЗНП2",\
  "Сраб ТЗНП2",\
  "ПО ЗНП2(3U0)",\
  "Сраб ЗНП2(3U0)",\
  "ПО ЗНП2(3I0)",\
  "Сраб ЗНП2(3I0)",\
  "Сектор ТЗНП3",\
  "Сраб ПО ТЗНП3",\
  "Сраб ТЗНП3",\
  "ПО ЗНП3(3U0)",\
  "Сраб ЗНП3(3U0)",\
  "ПО ЗНП3(3I0)",\
  "Сраб ЗНП3(3I0)",\
  "Сектор ТЗНП4",\
  "Сраб ПО ТЗНП4",\
  "Сраб ТЗНП4",\
  "ПО ЗНП4(3U0)",\
  "Сраб ЗНП4(3U0)",\
  "ПО ЗНП4(3I0)",\
  "Сраб ЗНП4(3I0)",\
  "Сектор ТЗНП5",\
  "Сраб ПО ТЗНП5",\
  "Сраб ТЗНП5",\
  "ПО ЗНП5(3U0)",\
  "Сраб ЗНП5(3U0)",\
  "ПО ЗНП5(3I0)",\
  "Сраб ЗНП5(3I0)",\
  "Блокировка ЗОП1",\
  "Блокировка ЗОП2",\
  "2группа уставок ЗОП",\
  "Сектор НЗОП1Впер",\
  "Сектор НЗОП1Назад",\
  "ПО ЗОП1",\
  "ПО НЗОП1Впер",\
  "ПО НЗОП1ННазад",\
  "Сраб НЗОП1",\
  "Сектор НЗОП2Впер",\
  "Сектор НЗОП2Назад",\
  "ПО ЗОП2",\
  "ПО НЗОП2Впер",\
  "ПО НЗОП2ННазад",\
  "Сраб НЗОП2",\
  "Пуск УРОВ",\
  "Сраб УРОВ1",\
  "Сраб УРОВ1",\
  "Блокировка Umax1",\
  "Блокировка Umax2",\
  "Сраб ПО UMAX1",\
  "Сраб UMAX1",\
  "Сраб ПО UMAX2",\
  "Сраб UMAX2"\
}

#define RANK_ENG_FRM            "Ranking"
/**ranking***********************************/

/**common************************************/
#define COMMON_ENG_TEXT         "Common"

#define COMMON_STAGE_TEXT_ENG   "Stage"

#define MESSAGE_ERR_TITLE_ENG   "Message"

#define ENTER_BUTTON_EXPL_ENG   "ENTER - select"
#define ESC_BUTTON_EXPL_ENG     "ESC - exit"

#define EDIT_MODE_EXPL_ENG     "(Editing mode)"

#define RANK_ENG_MS_UNIT        "ms"
#define RANK_ENG_SEC_UNIT       "sec"
/**common************************************/
/*************************************************************/

//общие
#define N_A                     "N/A"

typedef struct {
  const char    * pText[LANG_LIST_SIZE];
  const char    * pExplanation[LANG_LIST_SIZE];
} LANG_ITEM;

#endif

