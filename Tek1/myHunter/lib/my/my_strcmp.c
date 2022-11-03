/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** Copy string to another string
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int less = 0;
    int more = 1;
    int equal = 2;
    int n = 0;
    int i = 0;

    while (s1[n] != '\0')
        n++;
    while (s2[i] != '\0')
        i++;
    if (n < i)
        return (less);
    if (n > i)
        return (more);
    if (n = i)
        return (equal);
}
