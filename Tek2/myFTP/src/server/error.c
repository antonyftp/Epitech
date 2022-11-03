/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"
#include <ctype.h>
#include <string.h>

void throw_error(char *error)
{
    fprintf(stderr, "%s", error);
    exit(84);
}

int check_path(char *path)
{
    DIR *dir = opendir(path);
    if (dir) {
        chdir(path);
        closedir(dir);
    }
    else
        return (84);
    if (strlen(path) > PATH_MAX + 1)
        return (84);
    return (0);
}

int check_port(char *port)
{
    for (int i = 0; port[i] != 0; i++) {
        if (!isdigit(port[i]))
            return (84);
    }
    return (0);
}

int main_error(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        print_usage();
        return (0);
    }
    if (ac != 3 || !av[1] || !av[2]) {
        print_usage();
        return (84);
    }
    if (check_port(av[1]) == 84 || check_path(av[2]) == 84) {
        print_usage();
        return (84);
    }
    return (0);
}