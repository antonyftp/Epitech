##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC		=	gcc

LD		=	$(CC)

RM		=	rm -f

NAME		=	bsq

PATH_INCLUDE	=	./include/

PATH_SRC	=	./src/

PATH_TESTS	=	./tests/

RWILDCARD	=	$(foreach d,$(wildcard $1*),$(call RWILDCARD,$d/,$2)\
$(filter $(subst *,%,$2),$d))

INCLUDE		=	-I$(PATH_INCLUDE)

LIBRARY		=	-L$(PATH_LIBRARY) -l$(NAME_LIBRARY)

CFLAGS		+=	$(INCLUDE) -g3

#CFLAGS		+=	-W -Wall -Wextra -Werror -Wpedantic

#CFLAGS		+=	-Wno-long-long -pedantic -g3

SRC		=	$(call RWILDCARD,$(PATH_SRC),*.c)

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:	fclean all

unit-tests:
	make -C $(PATH_TESTS)
