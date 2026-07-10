NAME		=		ft_ping

SRC			=		*.c libft/*.c 

CC			=		gcc

CFLAGS		=		-Werror -Wextra -Wall

LIBFTDIR	=		libft/

LIBFTA		=		libft.a


all:		$(NAME)

$(NAME):	$(LIBFTA)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFTA) -o $(NAME)
	@rm -f $(LIBFTA)
	@echo "$(NAME) created"

$(LIBFTA):
	@cd ./$(LIBFTDIR) && make all
	@cp libft/libft.a .

clean:
		@cd $(LIBFTDIR) && make fclean

fclean: clean
		@rm -f $(NAME)

re: fclean all