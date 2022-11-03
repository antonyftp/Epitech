/*
** EPITECH PROJECT, 2024
** myFtp
** File description:
** Created by antonyftp
*/

#ifndef MYFTP_INCLUDE_H
#define MYFTP_INCLUDE_H

#define MAIN_SOCKET server->main_socket
#define RCV_SOCKET server->receive_socket
#define S_PORT server_info->port
#define S_PATH server_info->path
#define CMD_PTR commands[i].cmd
#define IS_SPACE(c) (c == ' ')
#define HP "\tpath  is the path to the home directory for the Anonymous user\n"

#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <dirent.h>

// Structures //

typedef struct client_s {
    int fd;
    bool user_set;
    bool is_log;
    char *path;
} client_t;

typedef struct server_s {
    size_t port;
    fd_set readfds;
    client_t client_list[30];
    struct sockaddr_in addr;
    char *path;
    int main_socket;
    int receive_socket;
    int sd;
    int max_sd;
    int active;
    int max;
} server_t;

typedef struct	commands_s {
    const char *cmd;
    int	(*func_ptr)();
} commands_t;

// Fonctions //
// Error //

void print_usage();
int main_error(int ac, char **av);

// Server //

int server(int port, char path[PATH_MAX]);

void throw_error(char *error);

// Utils //

void print_info(server_t *server_info);
int get_args(char *ptr, char **argv, int max);

// Command //

void main_cmd(server_t *server);

// Commands //

int cdup(server_t *server, char *arg, int i);
int cwd(server_t *server, char *arg, int i, int ac);
int dele(server_t *server, char *arg, int i);
int help(server_t *server, char *arg, int i);
int list(server_t *server, char *arg, int i);
int noop(server_t *server, char *arg, int i);
int pass(server_t *server, char *arg, int i, int ac);
int pasv(server_t *server, char *arg, int i);
int port(server_t *server, char *arg, int i);
int pwd(server_t *server, char *arg, int i);
int quit(server_t *server, char *arg, int i);
int retr(server_t *server, char *arg, int i);
int stor(server_t *server, char *arg, int i);
int user(server_t *server, char *arg, int i, int ac);


#endif //MYFTP_INCLUDE_H
