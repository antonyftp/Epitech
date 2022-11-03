/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int pwd(server_t *server, char *arg, int i)
{
    char *message = malloc(sizeof(char) * 1040);
    if (server->client_list[i].is_log == false) {
        write(server->sd, "530 Not logged in.\r\n", 20);
        return (0);
    }
    sprintf(message, "257 %s created.\r\n", server->client_list[i].path);
    write(server->sd, message, strlen(message));
    return (0);
}