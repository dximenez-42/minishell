NAME = minishell
SRCS = environment.c main.c parser.c src/utils/paths.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Ilibft/include
CC		= clang
all:	$(NAME)

$(NAME):	deps $(OBJS)
	if [ $(shell uname) = Linux ]; then \
	 $(CC) $(CFLAGS) -fuse-ld=lld -Llibft/lib -lft $(OBJS) -o $(NAME); \
	else \
	 $(CC) $(CFLAGS) -Llibft/lib -lft -lreadline $(OBJS) -o $(NAME); \
	fi

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all
deps:
	make -C libft