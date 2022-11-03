/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** main file
*/

#include <stdio.h>
#include "error.h"
#include "map.h"
#include "free_memory.h"
#include "compute.h"
#include "square.h"

static void print_map(char **map) {
    for(int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            printf("%c", map[i][j]);
        }
        printf("%c", '\n');
    }
}

int main(int ac, char **av)
{
    int error_code = error(ac, av);
    char **map = NULL;

    if (error_code == 84)
        return (error_code);
    map = extract_map(av[1]);
    map = find_square(map);
    map = draw_final_map(map);
    print_map(map);
    free_map(map);
    return (0);
}