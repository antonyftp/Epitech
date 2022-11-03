/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** __DESCRIPTION__
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H
#define MY_H

int my_compute_power_rec(int nb, int p);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
int my_atoi(char *str);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_octal(int n);
void my_unsigned_put_nbr(unsigned int nb);
void my_long_put_nbr(long nb);
void my_short_put_nbr(short nb);
char *my_itoa(int nb);

#endif
