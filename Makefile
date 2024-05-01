NAME = minishell

SRCS = environment.c main.c parser.c \
		cleaners.c \
		src/utils/paths.c src/exec/exec.c src/utils/commands.c
OBJS = $(SRCS:.c=.o)
LIBFT_PATH	= libft
LIBFT_INC_PATH = $(LIBFT_PATH)/include
LIBFT_LIB_PATH	= $(LIBFT_PATH)/lib
LIBFT_LIB_FILE	= $(LIBFT_LIB_PATH)/libft.a
LIBFT_INC_FLAGS = -I$(LIBFT_INC_PATH)
LIBFT_LINK_FLAGS = -L$(LIBFT_LIB_PATH) -lft
CFLAGS = $(LIBFT_INC_FLAGS) -g3 -lreadline
CC		= gcc

all:	$(NAME)


$(NAME):	$(LIBFT_LIB_FILE) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LINK_FLAGS)

clean:
	rm -f $(OBJS)
	make -C libft fclean

fclean:	clean
	rm -f $(NAME)

re:		fclean all

deps: $(LIBFT)

$(LIBFT_LIB_FILE):
	make -C libft