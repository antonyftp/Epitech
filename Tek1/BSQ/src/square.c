/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** square functions
*/

#include <string.h>
#include <stdio.h>

static char **redraw_default_map(char **map) {
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '0')
                map[i][j] = 'o';
            else if (map[i][j] >= '1' && map[i][j] != 'x')
                map[i][j] = '.';
        }
    }
    return (map);
}

static char **draw_square(char **map, int x, int y, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            map[y - i][x - j] = 'x';
        }
    }
    return (map);
}

static int biggest_position(char **map, int length) {
    int position = 0;
    int biggest = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] - 48 > biggest) {
                biggest = map[i][j] - 48;
                position = (length * i) + j;
            }
        }
    }
    return (position);
}

char **draw_final_map(char **map) {
    int length = strlen(map[0]);
    int position = biggest_position(map, length);
    int biggest = map[position / length][position % length] - 48;
    map = draw_square(map, position % length, position / length, biggest);
    for(int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            printf("%c", map[i][j]);
        }
        printf("%c", '\n');
    }
    printf("------------------\n");
    map = redraw_default_map(map);
    return (map);
}