/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

static void free_tmp(char *buffer, char *temp)
{
    free(buffer);
    free(temp);
}

static int check_dir(char *path)
{
    DIR *dir = opendir(path);

    if (!dir) {
        return (84);
    }
    closedir(dir);
    chdir(path);
    return (0);
}

int cwd(server_t *server, char *arg, int i, int ac)
{
    char *buffer = malloc(sizeof(char) * 1024);
    char *temp = malloc(sizeof(char) * 1024);
    if (server->client_list[i].is_log == false) {
        write(server->sd, "530 Not logged in.\r\n", 20);
        return (0);
    } else if (ac != 2) {
        write(server->sd, "550 Syntax error in arguments.\r\n", 32);
        return (84);
    }
    bzero(temp, 1024);
    memcpy(temp, arg, strlen(arg) - 2);
    if (check_dir(temp) == 84) {
        write(server->sd, "550 Requested file action not taken.\r\n", 38);
        free_tmp(buffer, temp);
        return (84);
    }
    free(server->client_list[i].path);
    server->client_list[i].path = strdup(getcwd(buffer, 1024));
    free_tmp(buffer, temp);
    write(server->sd, "250 Requested file action okay, completed.\r\n", 44);
    return (0);
}