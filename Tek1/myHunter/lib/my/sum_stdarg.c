/*
** EPITECH PROJECT, 2018
** PSU_my_printf_bootstrap_2018
** File description:
** Sum of stdarg arguments given as parameter
*/

#include <stdarg.h>
#include "../../include/my.h"

int sum_stdarg(int i, int nb, ...)
{
    int result = 0;
    va_list list;

    va_start(list, nb);
    if (i == 0) {
        while (nb > 0) {
            result = va_arg(list, int) + result;
            nb = nb - 1;
        }
    }
    if (i == 1) {
        while (nb > 0) {
            result = my_strlen(va_arg(list, char *)) + result,
            nb = nb -1;
        }
    }
    va_end(list);
    return (result);
}
