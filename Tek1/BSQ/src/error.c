/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** error management file
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int check_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        printf("Error: file not found.\n");
        close(fd);
        return (84);
    }
    close(fd);
    return (0);
}

int error(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Wrong number of args \nUsage: ./bsq map.txt\n");
        return (84);
    }
    if (check_file(av[1]) == 84)
        return (84);
    return (0);
}