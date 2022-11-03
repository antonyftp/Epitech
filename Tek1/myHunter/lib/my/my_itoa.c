/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_itoa
*/

#include "../../include/my.h"

char *my_itoa(int nb)
{
    int len;
    char *str;
    int tmp;
    tmp = nb;
    len = 0;

    while (tmp > 0) {
      tmp /= 10;
      len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
