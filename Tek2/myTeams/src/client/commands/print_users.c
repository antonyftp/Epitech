/*
** EPITECH PROJECT, 2021
** B-NWP-400-STG-4-1-myteams-antony.fantapie
** File description:
** client_print_users_handler.c
*/

#include "client.h"

void client_print_users_handler(char **args, client_t *client)
{
    if (tab_len(args) == 4)
        client_print_users(args[1], args[2], atoi(args[3]));
}