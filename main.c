#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_input *input;
	t_list	*env;
	char	*line;

	env = parse_env(envp);
	ft_putendl_fd(get_env_var(env, argv[1]), 1);
	return (0);
}
