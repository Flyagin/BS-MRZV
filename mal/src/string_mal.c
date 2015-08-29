#include "header_mal.h"


/*****************************
Додавання одного рядка до іншого
*****************************/
void strcat_mal(char *str1, char *str2) 
{
  int index1 = 0, index2 = 0;
  while ( str1[index1] != '\0') index1++;
  while ( str2[index2] != '\0') str1[index1++] = str2[index2++];
  str1[index1] = '\0';
}
/*****************************/

/*****************************
Визначення довжини рядка
*****************************/
int strlen_mal(char *str) 
{
  int index = 0;
  while ( str[index] != '\0') index++;
  
  return index;
}
/*****************************/

/*****************************
Вставлення одного рядка у інший з вказаної позиції
*****************************/
int strinsert_mal(char *str1, int pos, char *str2) 
{
  int result = false;
  int index1 = 0;
  while ( (str1[index1] != '\0') && (index1 != pos)) index1++;
  
  if (index1 == pos)
  {
    char string_tmp[256];
    
    int index2 = 0, number_tmp = 0, fix_null = false;
    while ((str2[index2] != '\0') && (number_tmp < 256)) 
    {
      if (fix_null == false)
      {
        if (str1[index1] != '\0')
          string_tmp[number_tmp++] = str1[index1];
        else
          fix_null = true;
      }
      str1[index1++] = str2[index2++];
    }
    
    int i = 0;
    while (
           (number_tmp < 256) &&
           (i < number_tmp) &&
           (string_tmp[i] != '\0')
          ) 
    {
      if (fix_null == false)
      {
        if (str1[index1] != '\0')
          string_tmp[number_tmp++] = str1[index1];
        else
          fix_null = true;
      }
      str1[index1++] = string_tmp[i];
      
      i++;
    }
    
    if (string_tmp[i] != '\0') result = true;
    str1[index1] = '\0';
  }
  
  return result;
}
/*****************************/

/*****************************
Вставлення символів з вказаної позиції
*****************************/
int strdel_mal(char *str, int pos, int number) 
{
  int result = false;
  
  if (number > 0)
  {
    int length = 0;
    while (str[length] != '\0') length++;
  
    if (pos < length)
    {
      int i = 0, pos_tmp;
      while ((pos_tmp = (pos + i)) < length)
      {
        char symbol_tmp;
        int pos_tmp_1 = pos_tmp + number;
        if (pos_tmp_1 < length) symbol_tmp = str[pos_tmp_1];
        else symbol_tmp = '\0';
      
        str[pos_tmp] = symbol_tmp;
        i++;
      }
      str[pos_tmp] = '\0';
      result = true;
    }
  }
  
  return result;
}
/*****************************/

/*****************************
Порівняння двох рядків
*****************************/
int strcmp_mal(char *str1, char *str2) 
{
  int result = true;
  int index = 0;
  char symbol_1, symbol_2;
  do
  {
    symbol_1 = str1[index];
    symbol_2 = str2[index++];
    if (symbol_1 != symbol_2) result = false;
  }
  while (
         (result == true) &&
         (symbol_1 != '\0') &&
         (symbol_2 != '\0')
        );
  
  return result;
}
/*****************************/

