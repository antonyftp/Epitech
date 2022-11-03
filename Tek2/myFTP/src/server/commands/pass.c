/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int pass(server_t *server, char *arg, int i, int ac)
{
    if (strcmp(arg, "\r\n") == 0 && server->client_list[i].user_set == false) {
        write(server->sd, "332 Need account for login.\r\n", 29);
        return (84);
    }
    if (strcmp(arg, "\r\n") == 0 && server->client_list[i].user_set == true) {
        write(server->sd, "230 User logged in, proceed.\r\n", 30);
        server->client_list[i].is_log = true;
        return (0);
    } else {
        write(server->sd, "530 Wrong password.\r\n", 21);
        return (84);
    }
}