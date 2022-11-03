/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** strcat but only for a number given
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int n = 0;
    while (src[n] != '\0' && nb != 0) {
        my_putchar(src[n]);
        n++;
        nb--;
    }

    int i = 0;
    while (dest[i] != '\0') {
        my_putchar(dest[i]);
        i++;
    }
}
