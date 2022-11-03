/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** Copy string to another string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    int s = 0;

    while (str[n] != '\0') {
        n++;
    }
    n--;

    while (i < n) {
        s = str[i];
        str[i] = str[n];
        str[n] = s;

        i++;
        n--;
    }
    return (str);
}
