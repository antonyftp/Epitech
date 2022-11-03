/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int quit(server_t *server, char *arg, int i)
{
    write(server->sd, "221 Service closing control connection.\r\n", 41);
    close(server->sd);
    server->client_list[i].fd = 0;
    server->client_list[i].is_log = false;
    free(server->client_list[i].path);
    return (0);
}