/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it.c
** File description:
** Calculate the power of a number (recursive)
*/

#include "../../include/my.h"

int my_compute_power_rec(int nb, int p) {
    int result = nb;
    if (p < 0 || nb < 0) {
        return (0);
    }
    for (int i = 0; i < p - 1; i++) {
        result = nb * my_compute_power_rec(nb ,p - 1);
    }
    return (result);
}
