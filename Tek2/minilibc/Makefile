##
## EPITECH PROJECT, 2018
## makefile
## File description:
## palindrome makefile
##

NAME		=	libasm.so

DIR		=	src

SRCS		=	$(DIR)/strlen.asm		\
				$(DIR)/strchr.asm		\
				$(DIR)/strstr.asm		\
				$(DIR)/memcpy.asm		\
				$(DIR)/memmove.asm		\
				$(DIR)/memset.asm		\
				$(DIR)/rindex.asm		\
				$(DIR)/strcasecmp.asm	\
				$(DIR)/strcmp.asm		\
				$(DIR)/strcspn.asm		\
				$(DIR)/strpbrk.asm		\
				$(DIR)/strncmp.asm		\

ASMFLAGS	=	-f elf64

LDFLAGS		=	-fPIC -shared

ASM		=	nasm

LD		=	ld

RM		=	rm -f

OBJS		=	$(SRCS:.asm=.o)

%.o: %.asm
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(ASM) -o $@ $< $(ASMFLAGS)

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
		@$(RM) $(OBJS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re:		fclean all

.PHONY:		all clean fclean re