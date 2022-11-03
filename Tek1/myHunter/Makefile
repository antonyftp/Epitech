##
## EPITECH PROJECT, 2018
## MUL_my_screensaver_2018
## File description:
## Makefile
##

SRC		=	my_hunter.c			\
			window.c			\
			events.c			\
			assets.c			\
			free.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-g -Iinclude -Llib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system

all:	$(NAME)

$(NAME):	$(OBJ) libmy
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

libmy:
	cd lib/my && make

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	cd lib/my && make fclean

re:	fclean all clean

debug:	fclean $(OBJ)
	gcc -g $(OBJ) -o $(NAME) $(CFLAGS)
