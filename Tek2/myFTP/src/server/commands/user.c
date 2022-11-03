/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int user(server_t *server, char *arg, int i, int ac)
{
    if (ac != 2) {
        write(server->sd, "530 Wrong user name.\r\n", 22);
        return (84);
    }
    if (server->client_list[i].is_log == true) {
        write(server->sd, "230 User logged in, proceed.\r\n", 30);
        return (0);
    }
    if (strcmp(arg, "Anonymous\r\n") == 0 ) {
        write(server->sd, "331 User name okay, need password.\r\n", 36);
        server->client_list[i].user_set = true;
    } else
        write(server->sd, "331 Wrong user name.\r\n", 22);
    return (0);
}