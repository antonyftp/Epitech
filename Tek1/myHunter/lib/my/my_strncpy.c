/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** Copy string to another string
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] != '\0' && n != 0) {
        dest[i] = src[i];
        i++;
        n--;
    }
    dest[i] = '\0';
    return (dest);
}
