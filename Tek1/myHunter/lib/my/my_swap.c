/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** Swap the content of two integers
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{

    int c;

    c = *a;
    *a = *b;
    *b = c;
}
