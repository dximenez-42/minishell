SRCS = environment.c main.c parser.c

all:
	clang -fuse-ld=lld -Ilibft/include -Llibft/lib -lft $(SRCS) -o minishell