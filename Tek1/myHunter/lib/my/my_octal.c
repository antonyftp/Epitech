/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Convert base 10 int to base 8 int
*/

#include "../../include/my.h"

int my_octal(int n)
{
    int octalNumber = 0;
    int i = 1;

    while (n != 0)
    {
        octalNumber += (n % 8) * i;
        n /= 8;
        i *= 10;
    }
    my_put_nbr(octalNumber);

    return (octalNumber);
}
