
#ifndef __GUI_MACROSES__
#define __GUI_MACROSES__

/*
  Макрос конвертирует число в массив символов.
  Для конвертации чисел без знака нужно в качестве входной переменной
  передать число unsigned int.
  Входной массив _ARR обязательно должен быть размером не меньше 11 (10 - макс.
  кол. символов в числе int, +1 - знак

  _INT_VAL - число которое нужно конвертировать
  _ARR - указатель на массив символов
*/
#pragma diag_suppress = Pe186
#define _PARSE_INT_TO_STR(                                                      \
               _INT_VAL,                                                        \
               _ARR                                                             \
              ) {                                                               \
        char * _STR_ARR = _ARR;                                                 \
        _Bool _flag = 0;                                                        \
        int _counter = 0;                                                       \
        int _div = 1000000000;                                                  \
        int _tmp = 0;                                                           \
        if (_INT_VAL < 0) *(_STR_ARR + _counter++) = '-';                       \
        while (_div >= 10) {                                                    \
          if (_div < 1000000000) {                                              \
            _tmp = (_INT_VAL % (_div * 10)) / _div;                             \
          } else {                                                              \
            _tmp = _INT_VAL / _div;                                             \
          }                                                                     \
          if (_tmp < 0) _tmp = ~_tmp + 1;                                       \
          if (!_flag) {                                                         \
            if (_tmp > 0) {                                                     \
              *(_STR_ARR + _counter++) = '0' + _tmp;                            \
              _flag = 1;                                                        \
            }                                                                   \
          } else {                                                              \
            *(_STR_ARR + _counter++) = '0' + _tmp;                              \
          }                                                                     \
          _div /= 10;                                                           \
        }                                                                       \
        if (_INT_VAL < 0 && _INT_VAL == 0x80000000) {                           \
          *(_STR_ARR + _counter) = '0' + 8;                                     \
        } else if (_INT_VAL < 0) {                                              \
          *(_STR_ARR + _counter) = '0' + (~_INT_VAL + 1) % 10;                  \
        } else {                                                                \
          *(_STR_ARR + _counter) = '0' + _INT_VAL % 10;                         \
        }                                                                       \
      }
/*
  Макрос конвертирует число в массив символов.
  Если указано число _PRECISION в диапазоне от 1..9, то число будет
  конвертировано в строковое представление с плавающей запятой.
  Все лишние нули в конце строки будут автоматически удалены.
  Для конвертации чисел без знака нужно в качестве входной переменной
  передать число unsigned int.
  Входной массив _ARR обязательно должен быть размером не меньше 12 (10 - макс.
  кол. символов в числе int, +1 - знак, +1 - точка

  _INT_VAL - число которое нужно конвертировать
  _PRECISION - кол. знаков после запятой
  _ARR - указатель на массив символов
*/
#define _PARSE_INT_TO_DOUBLE_STR(                                               \
                _INT_VAL,                                                       \
                _PRECISION,                                                     \
                _ARR                                                            \
                ) {                                                             \
        char * _STR_ARR = _ARR;                                                 \
        _Bool _flag = 0;                                                        \
        int _counter = 0;                                                       \
        int _decimal_counter = 10; /*максимальное кол. цифр в int*/             \
        if (_PRECISION < 0 || _PRECISION > 9) { /*недопустимое значение*/       \
          _PRECISION = -1; /* при сравнении decimal_counter    */               \
                           /* всегда будет не равно _PRECISION */               \
        }                                                                       \
        if (_INT_VAL < 0) *(_STR_ARR + _counter++) = '-';                       \
        int _div = 1000000000;                                                  \
        int _tmp = 0;                                                           \
        while (_div >= 10) {                                                    \
          if (_div < 1000000000) {                                              \
            _tmp = (_INT_VAL % (_div * 10)) / _div;                             \
          } else {                                                              \
            _tmp = _INT_VAL / _div;                                             \
          }                                                                     \
          if (_tmp < 0) _tmp = ~_tmp + 1;                                       \
          if (!_flag) {                                                         \
            _decimal_counter--;                                                 \
            if (_tmp > 0) {                                                     \
              *(_STR_ARR + _counter++) = '0' + _tmp;                            \
              if (_decimal_counter == _PRECISION) {                             \
                *(_STR_ARR + _counter++) = '.';                                 \
              }                                                                 \
              _decimal_counter--;                                               \
              _flag = 1;                                                        \
            } else if (_decimal_counter == _PRECISION) {                        \
              *(_STR_ARR + _counter++) = '0';                                   \
              *(_STR_ARR + _counter++) = '.';                                   \
              _decimal_counter--;                                               \
              _flag = 1;                                                        \
            }                                                                   \
          } else {                                                              \
            *(_STR_ARR + _counter++) = '0' + _tmp;                              \
            if (_decimal_counter == _PRECISION) *(_STR_ARR + _counter++) = '.'; \
            _decimal_counter--;                                                 \
          }                                                                     \
          _div /= 10;                                                           \
        }                                                                       \
        if (_INT_VAL < 0 && _INT_VAL == 0x80000000) {                           \
          *(_STR_ARR + _counter) = '0' + 8;                                     \
        } else if (_INT_VAL < 0) {                                              \
          *(_STR_ARR + _counter) = '0' + (~_INT_VAL + 1) % 10;                  \
        } else {                                                                \
          *(_STR_ARR + _counter) = '0' + _INT_VAL % 10;                         \
        }                                                                       \
                                                                                \
        /*оптимизируем строку удаляя все последние*/                            \
        /*нули после запятой (если есть)          */                            \
        if (_PRECISION > 0 && _PRECISION < 10) { /*проверка установлена    */   \
                             /*ли запятая (_PRECISION > 0 - дробное число) */   \
          for (int _i = _counter; _i >= 0; _i--) {                              \
            if (*(_STR_ARR + _i) == '0') {                                      \
              *(_STR_ARR + _i) = 0x00;                                          \
            } else if (*(_STR_ARR + _i) == '.') {                               \
              *(_STR_ARR + _i) = 0x00;                                          \
              break;                                                            \
            } else {                                                            \
              break;                                                            \
            }                                                                   \
          }                                                                     \
        }                                                                       \
      }
#pragma diag_suppress = Pe186

/*
  _CONCAT_STR объединяет две строки в одну.
  Результат будет записан в _ARR1.
  Длина _ARR1 должна быть не меньше (длина _ARR1 + длина _ARR2)
*/
#define _CONCAT_STR(                                                            \
                _ARR1,                                                          \
                _ARR2                                                           \
                ) {                                                             \
        char * _STR_ARR1 = _ARR1;                                               \
        int _i = 0;                                                             \
                                                                                \
        /* _i contains length of string _STR_ARR1 */                            \
        for(; _STR_ARR1[_i] != '\0'; ++_i);                                     \
                                                                                \
        for(int _j = 0; _ARR2[_j] != '\0'; ++_j, ++_i) {                        \
          _STR_ARR1[_i] = _ARR2[_j];                                            \
        }                                                                       \
      }

#define _CHECK_RANK_SET_BIT(_array, _index_smul_pg, _number_bit)                \
        (                                                                       \
          _array[_index_smul_pg][_number_bit >> 5] &                            \
          ( (unsigned int)( 1 << (_number_bit & 0x1f)) )                        \
        )
          
#define _CHECK_RANK_SET_BIT_P(_array_p, _index_smul_pg, _number_bit)            \
        (                                                                       \
          (*_array_p)[_index_smul_pg][_number_bit >> 5] &                       \
          ( (unsigned int)( 1 << (_number_bit & 0x1f)) )                        \
        )

#define _SET_RANK_BIT(_array, _index_smul_pg, _number_bit)                      \
          _array[_index_smul_pg][_number_bit >> 5] |=                           \
          (unsigned int)(1 << (_number_bit & 0x1f))
            
#define _SET_RANK_BIT_P(_array_p, _index_smul_pg, _number_bit)                  \
        (*_array_p)[_index_smul_pg][_number_bit >> 5] |=                        \
        (unsigned int)(1 << (_number_bit & 0x1f))

#define _CLEAR_RANK_BIT(_array, _index_smul_pg, _number_bit)                    \
          _array[_index_smul_pg][_number_bit >> 5] &=                           \
          (unsigned int)(~(1 << (_number_bit & 0x1f)))
            
#define _CLEAR_RANK_BIT_P(_array_p, _index_smul_pg, _number_bit)                \
        (*_array_p)[_index_smul_pg][_number_bit >> 5] &=                        \
        (unsigned int)(~(1 << (_number_bit & 0x1f)))

#define _CHECK_BIT_RANK_UCHAR(_array, _number_bit, _index)                      \
        (                                                                       \
          unsigned int _num_byte = ((_number_bit - 1) >> 3) + 1;                \
          unsigned int val1 = _index / _number_bit;                             \
          unsigned int val2 = ((_index % _number_bit) >> 3);                    \
          val1 *= _num_byte;                                                    \
          unsigned int calc_index = val1 + val2;                                \
          _array[calc_index] &                                                  \
          ( (unsigned char)( 1 << ((_index % _number_bit) % 8) ) )              \
        )

#define _SET_BIT_RANK_UCHAR(_array, _number_bit, _index)                        \
        {                                                                       \
          unsigned int _num_byte = ((_number_bit - 1) >> 3) + 1;                \
          unsigned int val1 = _index / _number_bit;                             \
          unsigned int val2 = ((_index % _number_bit) >> 3);                    \
          val1 *= _num_byte;                                                    \
          unsigned int calc_index = val1 + val2;                                \
          _array[calc_index] |=                                                 \
          (unsigned char)( 1 << ((_index % _number_bit) % 8) );                 \
        }

#define _CLEAR_BIT_RANK_UCHAR(_array, _number_bit, _index)                      \
        {                                                                       \
          unsigned int _num_byte = ((_number_bit - 1) >> 3) + 1;                \
          unsigned int val1 = _index / _number_bit;                             \
          unsigned int val2 = ((_index % _number_bit) >> 3);                    \
          val1 *= _num_byte;                                                    \
          unsigned int calc_index = val1 + val2;                                \
          _array[calc_index] &=                                                 \
          (unsigned char)(~(1 << ((_index % _number_bit) % 8) ) );              \
        }

#define _CHECK_BIT_UCHAR(_array, _number_bit)                                   \
        (                                                                       \
          _array[_number_bit >> 3] &                                            \
          ( (unsigned char)( 1 << (_number_bit % 8) ) )                         \
        )

#define _SET_BIT_UCHAR(_array, _number_bit)                                     \
        {                                                                       \
          _array[_number_bit >> 3] |=                                           \
          (unsigned char)( 1 << (_number_bit % 8) );                            \
        }

#define _CLEAR_BIT_UCHAR(_array, _number_bit)                                   \
        {                                                                       \
          _array[_number_bit >> 3] &=                                           \
          (unsigned char)(~(1 << (_number_bit % 8) ) );                         \
        }

#endif

