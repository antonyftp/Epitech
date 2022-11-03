/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

static commands_t commands[] = {
    {"USER", &user},
    {"PASS", &pass},
    {"PWD", &pwd},
    {"CWD", &cwd},
    {"CDUP", &cdup},
    {"PASV", &pasv},
    {"PORT", &port},
    {"LIST", &list},
    {"RETR", &retr},
    {"STOR", &stor},
    {"DELE", &dele},
    {"NOOP", &noop},
    {"HELP", &help},
    {"QUIT", &quit},
    {NULL, NULL}
};

static int cmp_command(const char *cmd, const char *text)
{
    int	i = 0;
    int	j = 0;
    while (cmd && text && cmd[i] && text[j] && cmd[i] == text[j]) {
        i += 1;
        j += 1;
    }
    if (cmd && cmd[i] == '\0')
        return (1);
    return (0);
}

static int dispatch_command(server_t *server, char **av, int x, int ac)
{
    int	i = 0;
    while (av[0] && CMD_PTR && cmp_command(CMD_PTR, av[0]) == 0)
        i += 1;
    if (commands[i].cmd)
        return (commands[i].func_ptr(server, av[1], x, ac));
    write(server->sd, "500 Command not implemented.\r\n", 30);
    return (0);
}

void main_cmd(server_t *server)
{
    int ac;
    size_t len;
    char *av[4];
    char buffer[1024];
    for (int i = 0; i < server->max; i++) {
        server->sd = server->client_list[i].fd;
        if (FD_ISSET(server->sd, &server->readfds)) {
            bzero(buffer, 1024);
            len = read(server->sd, buffer, 1024);
            buffer[len] = 0;
            ac = get_args(buffer, av, 4);
            dispatch_command(server, av, i, ac);
        }
    }
}