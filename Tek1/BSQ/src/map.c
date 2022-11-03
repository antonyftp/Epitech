/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** map functions
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

static int skip_map_length(const char *buffer) {
    int ptr = 0;
    while (buffer[ptr] != '\n')
        ptr++;
    ptr++;
    return (ptr);
}

static void copy_line(char **map, char const *buffer, int tmp_ptr, int i) {
    for (int y = 0; buffer[tmp_ptr] != '\n'; y++) {
        map[i][y] = buffer[tmp_ptr];
        tmp_ptr++;
    }
}

static char **malloc_map(int length, const char *buffer) {
    int ptr;
    int line_size;
    int tmp_ptr;
    char **map = malloc(sizeof(char *) * (length + 1));

    ptr = skip_map_length(buffer);
    for (int i = 0; i < length; i++) {
        line_size = 0;
        tmp_ptr = ptr;
        while (buffer[ptr] != '\n') {
            ptr++;
            line_size++;
        }
        map[i] = malloc(sizeof(char) * (line_size + 1));
        copy_line(map, buffer, tmp_ptr, i);
        map[i][line_size] = '\0';
        ptr++;
    }
    map[length] = NULL;
    return (map);
}

char **extract_map(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int length = 0;
    char *buffer = NULL;

    stat(path, &st);
    buffer = malloc(sizeof(char) * st.st_size);
    read(fd, buffer, st.st_size);
    close(fd);
    length = atoi(buffer);
    char **map = malloc_map(length, buffer);
    free(buffer);
    return (map);
}