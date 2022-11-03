##
## EPITECH PROJECT, 2018
## makefile
## File description:
## palindrome makefile
##

server		= myftp

SRC_DIR		= ./src

SERVER_DIR	= $(SRC_DIR)/server

SRC_SERVER	= 	$(SERVER_DIR)/main.c 					\
				$(SERVER_DIR)/server.c 					\
				$(SERVER_DIR)/error.c 					\
				$(SERVER_DIR)/commands.c 					\
				$(SERVER_DIR)/utils.c 					\
				$(SERVER_DIR)/commands/cdup.c 			\
				$(SERVER_DIR)/commands/cwd.c 			\
				$(SERVER_DIR)/commands/dele.c 			\
				$(SERVER_DIR)/commands/help.c 			\
				$(SERVER_DIR)/commands/list.c 			\
				$(SERVER_DIR)/commands/noop.c 			\
				$(SERVER_DIR)/commands/pass.c 			\
				$(SERVER_DIR)/commands/pasv.c 			\
				$(SERVER_DIR)/commands/port.c 			\
				$(SERVER_DIR)/commands/pwd.c 			\
				$(SERVER_DIR)/commands/quit.c 			\
				$(SERVER_DIR)/commands/retr.c 			\
				$(SERVER_DIR)/commands/stor.c 			\
				$(SERVER_DIR)/commands/user.c 			\

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

INCLUDE_DIR	= -I ./includes

CFLAGS		= -Wall $(INCLUDE_DIR) -g

CC		= gcc

RM		= rm -f

all:		$(server)

$(server):	$(OBJ_SERVER)
		$(CC) $(CFLAGS) -o $(server) $(OBJ_SERVER)

clean:
		$(RM) $(OBJ_SERVER)

fclean:		clean
		$(RM) $(server)

re:		fclean all

.PHONY:		all clean fclean re