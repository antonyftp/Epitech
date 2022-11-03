/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int cdup(server_t *server, char *arg, int i)
{
    char *buff = malloc(1024);
    char *temp = malloc(1024);
    if (server->client_list[i].is_log == false) {
        write(server->sd, "530 Not logged in.\r\n", 20);
        return (0);
    }
    strcpy(temp, server->client_list[i].path);
    strcat(temp, "/..");
    if (chdir(temp) != 0) {
        write(server->sd, "501 Syntax error in parameters.\r\n", 46);
        free(temp);
        free(buff);
        return (0);
    }
    free(server->client_list[i].path);
    server->client_list[i].path = strdup(getcwd(buff, 1024));
    write(server->sd, "200 Command okay.\r\n", 19);
    return (0);
}