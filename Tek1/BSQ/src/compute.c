/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** compute functions
*/

#include <stdio.h>

static char compute_neighbour(char **map, int i, int j)
{
    char min;
    if (map[i][j] == '0')
        return ('0');
    if (i == 0 || j == 0) {
        return (map[i][j]);
    }
    if (map[i - 1][j - 1] == '0' || map[i - 1][j] == '0' || map[i][j - 1] == '0') {
        return ('1');
    }
    min = map[i - 1][j - 1];
    if (map[i - 1][j] < min)
        min = map[i - 1][j];
    if (map[i][j - 1] < min)
        min = map[i][j - 1];
    return (min + 1);
}

static char **compute_position(char **map) {
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] != '0')
                map[i][j] = compute_neighbour(map, i, j);
        }
    }
    return (map);
}

static char **numerize_map(char **map) {
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '.')
                map[i][j] = '1';
            else
                map[i][j] = '0';
        }
    }
    return (map);
}

char **find_square(char **map) {
    map = numerize_map(map);
    map = compute_position(map);
    return (map);
}
