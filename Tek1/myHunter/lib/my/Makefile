##
## EPITECH PROJECT, 2018
## delivery
## File description:
## __DESCRIPTION__
##

SRC     =      my_compute_power_rec.c \
               my_isneg.c             \
               my_put_nbr.c           \
               my_putchar.c           \
               my_putstr.c            \
               my_revstr.c            \
               my_show_word_array.c   \
               my_strcat.c            \
               my_strcmp.c            \
               my_strcpy.c            \
               my_strdup.c            \
               my_strlen.c            \
               my_strncat.c           \
               my_strncpy.c           \
               my_strstr.c            \
               my_swap.c              \
               my_atoi.c              \
               sum_stdarg.c           \
               disp_stdarg.c          \
               my_octal.c             \
               my_short_put_nbr.c     \
               my_long_put_nbr.c      \
			   my_itoa.c              \

OBJ   =    $(SRC:.c=.o)

NAME    =   libmy.a

NAME_H = my.h


all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
