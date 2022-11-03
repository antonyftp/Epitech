/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

int get_args(char *ptr, char **argv, int max)
{
    int i = 0;
    char *origin;

    while (*ptr && i < max) {
        while (IS_SPACE(*ptr))
            ptr++;
        if (*ptr) {
            origin = ptr;
            while (*ptr && !IS_SPACE(*ptr))
                ptr++;
            if (*ptr)
                *ptr++ = 0;
            argv[i++] = origin;
        }
    }
    return (i);
}

void print_info(server_t *server_info)
{
    printf("[FTP Server] Port: [%ld] - Path Default: [%s]\n", S_PORT, S_PATH);
}