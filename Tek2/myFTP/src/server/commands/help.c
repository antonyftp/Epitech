/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int help(server_t *server, char *arg, int i)
{
    if (server->client_list[i].is_log == false) {
        write(server->sd, "530 Not logged in.\r\n", 20);
        return (0);
    }
    write(server->sd, "214 Help message.\r\n", 19);
    return (0);
}