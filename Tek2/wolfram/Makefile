BINARY_PATH 	:=	$(shell stack path --local-install-root --allow-different-user)
NAME 			= 	wolfram

all:
	stack build --allow-different-user
	cp $(BINARY_PATH)/bin/$(NAME)-exe ./$(NAME)

clean:
	stack clean --allow-different-user

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
