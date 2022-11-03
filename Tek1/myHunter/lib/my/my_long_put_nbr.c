/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** Print a digit
*/

#include "../../include/my.h"

void my_long_put_nbr(long nb)
{
    int y;

    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 10) {
            y = (nb % 10);
            nb = (nb - y) / 10;
            my_put_nbr(nb);
            my_putchar(48 + y);
        }
        else
          my_putchar(48 + nb % 10);
    }
}
