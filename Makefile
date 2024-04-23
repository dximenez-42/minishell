NAME = minishell
SRCS = environment.c main.c parser.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Ilibft/include -g
CC		= clang
all:	$(NAME)

$(NAME):	deps $(OBJS)
		$(CC) $(OBJS) -o $(NAME) -Llibft/lib -lft ;

clean:
	rm -f $(OBJS)
	make -C libft fclean

fclean:	clean
	rm -f $(NAME)

re:		fclean all
deps:
	make -C libft