/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** Display P if the number is positive and N if the number is negative
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (n);
}
