/*
** EPITECH PROJECT, 2018
** PSU_my_printf_bootstrap_2018
** File description:
** Display a stdarg
*/

#include <stdarg.h>
#include "../../include/my.h"

int disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'c') {
            my_putchar(va_arg(list, int));
            my_putchar('\n');
        }
        if (s[i] == 's') {
            my_putstr(va_arg(list, char *));
            my_putchar('\n');
        }
        if (s[i] == 'i') {
            my_put_nbr(va_arg(list, int));
            my_putchar('\n');
        }
    }
}
