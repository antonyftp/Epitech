/*
** EPITECH PROJECT, 2024
** myFtp
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"
#include <stdlib.h>
#include <stdio.h>

void print_usage(void)
{
    printf("USAGE:  ./myftp port path\n");
    printf("\tport  is the port number on which the server socket listens\n");
    printf(HP);
}

int main(int ac, char **av)
{
    int port = 0;
    char path[PATH_MAX];
    if (main_error(ac, av) == 84)
        return (84);
    port = atoi(av[1]);
    strcpy((char *)path, av[2]);
    if (server(port, path) == 84)
        return (84);
    return (0);
}