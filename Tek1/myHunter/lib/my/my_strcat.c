/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** man strcat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int n = 0;
    while (src[n] != '\0') {
        my_putchar(src[n]);
        n++;
    }

    int i = 0;
    while (dest[i] != '\0') {
        my_putchar(dest[i]);
        i++;
    }
}
