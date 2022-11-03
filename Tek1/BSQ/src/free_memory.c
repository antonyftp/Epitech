/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** free functions
*/

#include <stdlib.h>

static int map_length(char **map) {
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            j++;
        }
        i++;
    }
    return (i);
}

void free_map(char **map)
{
    int length = map_length(map);
    for(int i = 0; i < length; i++)
        free(map[i]);
    free(map);
}