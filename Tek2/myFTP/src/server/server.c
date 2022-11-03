/*
** EPITECH PROJECT, 2024
** B_NWP_400_STG_4_1_myftp_antony_fantapie
** File description:
** Created by antonyftp
*/

#include "my_ftp.h"

void set_socket(server_t *server)
{
    FD_ZERO(&server->readfds);
    FD_SET(MAIN_SOCKET, &server->readfds);
    server->max_sd = MAIN_SOCKET;
    for (int i = 0; i < server->max; i++) {
        server->sd = server->client_list[i].fd;
        if (server->sd > 0)
            FD_SET(server->sd, &server->readfds);
        if (server->sd > server->max_sd)
            server->max_sd = server->sd;
    }
}

void add_new_client(server_t *server)
{
    socklen_t addr_len = sizeof(server->addr);

    if (FD_ISSET(MAIN_SOCKET, &server->readfds)) {
        RCV_SOCKET = accept(MAIN_SOCKET, (struct sockaddr *)
            &server->addr, &addr_len);
        for (int i = 0; i < server->max; i++) {
            if (server->client_list[i].fd == 0) {
                server->client_list[i].fd = RCV_SOCKET;
                server->client_list[i].path = strdup(server->path);
                break;
            }
        }
        write(RCV_SOCKET, "220 Service ready for new user.\r\n", 33);
    }
}

static void server_loop(server_t *server)
{
    for (int i = 0; i < server->max; i++) {
        server->client_list[i].fd = 0;
        server->client_list[i].is_log = false;
    }
    while (1) {
        set_socket(server);
        server->active = select(
            server->max_sd + 1, &server->readfds, NULL, NULL, NULL);
        add_new_client(server);
        main_cmd(server);
    }
}

static void init_server(int port, char path[PATH_MAX], server_t *server)
{
    char *op = (char *)true;
    int o;
    server->max = 30;
    server->main_socket = socket(AF_INET, SOCK_STREAM, 0);
    server->port = port;
    if (MAIN_SOCKET < 0)
        throw_error("[FTP Server Err] Failed to create the main socket");
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(server->port);
    server->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    o = setsockopt(MAIN_SOCKET, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op));
    if (o < 0)
        throw_error("[FTP Server Err] setsockopt error");
    if (bind(MAIN_SOCKET, (struct sockaddr *)&server->addr,
            sizeof(server->addr)) < 0)
        throw_error("[FTP Server Err] Failed to bind the main socket");
    if (listen(server->main_socket, server->max) != 0)
        throw_error("[FTP Server Err] Failed to listen");
}

int server(int port, char path[PATH_MAX])
{
    server_t *server = malloc(sizeof(server_t));
    char *buffer = malloc(1024);
    printf("[FTP Server] Starting server.\n");
    if (!server)
        throw_error("Server malloc error");
    server->path = strdup(getcwd(buffer, 1024));
    free(buffer);
    init_server(port, path, server);
    print_info(server);
    server_loop(server);
    return (0);
}