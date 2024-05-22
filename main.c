/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/22 23:07:19 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// void	init_input(t_input **input, char *line)
// {
// 	(*input) = malloc(sizeof(t_input));
// 	(*input)->noc = 1;
// 	(*input)->cmds = malloc(sizeof(t_command *));
	
// 	(*input)->cmds[0] = malloc(sizeof(t_command));
// 	(*input)->cmds[0]->info = 1;
// 	(*input)->cmds[0]->args = ft_split(line, ' ');
// 	(*input)->cmds[0]->fds[FDIN] = FDIN;
// 	(*input)->cmds[0]->fds[FDOUT] = FDOUT;
// 	(*input)->cmds[0]->fds[FDERROR] = FDERROR;
// }

void	init_input(t_input **input, t_list *env, char *line)
{
	(*input) = malloc(sizeof(t_input));
	(*input)->noc = 3;
	(*input)->env = env;
	(*input)->cmds = malloc(4 * sizeof(t_command *));

	(*input)->cmds[0] = malloc(sizeof(t_command));
	(*input)->cmds[0]->info = 1;
	(*input)->cmds[0]->args = malloc(3 * sizeof(char *));
	(*input)->cmds[0]->args[0] = ft_strdup("ls");
	(*input)->cmds[0]->args[1] = NULL;
	(*input)->cmds[0]->fds[FDIN] = STDIN_FILENO;
	(*input)->cmds[0]->fds[FDOUT] = STDOUT_FILENO;
	(*input)->cmds[0]->fds[FDERROR] = STDERR_FILENO;

	(*input)->cmds[1] = malloc(sizeof(t_command));
	(*input)->cmds[1]->info = 1;
	(*input)->cmds[1]->args = malloc(3 * sizeof(char *));
	(*input)->cmds[1]->args[0] = ft_strdup("grep");
	(*input)->cmds[1]->args[1] = ft_strdup("a");
	(*input)->cmds[1]->args[2] = NULL;
	(*input)->cmds[1]->fds[FDIN] = STDIN_FILENO;
	(*input)->cmds[1]->fds[FDOUT] = STDOUT_FILENO;
	(*input)->cmds[1]->fds[FDERROR] = STDERR_FILENO;

	(*input)->cmds[2] = malloc(sizeof(t_command));
	(*input)->cmds[2]->info = 1;
	(*input)->cmds[2]->args = malloc(3 * sizeof(char *));
	(*input)->cmds[2]->args[0] = ft_strdup("wc");
	(*input)->cmds[2]->args[1] = ft_strdup("-l");
	(*input)->cmds[2]->args[2] = NULL;
	(*input)->cmds[2]->fds[FDIN] = STDIN_FILENO;
	(*input)->cmds[2]->fds[FDOUT] = STDOUT_FILENO;
	(*input)->cmds[2]->fds[FDERROR] = STDERR_FILENO;

	(*input)->cmds[3] = NULL;
}

// void	init_input(t_input **input, t_list *env, char *line)
// {
// 	(*input) = malloc(sizeof(t_input));
// 	(*input)->noc = 2;
// 	(*input)->env = env;
// 	(*input)->cmds = malloc(3 * sizeof(t_command *));

// 	(*input)->cmds[0] = malloc(sizeof(t_command));
// 	(*input)->cmds[0]->info = 1;
// 	(*input)->cmds[0]->args = malloc(3 * sizeof(char *));
// 	(*input)->cmds[0]->args[0] = ft_strdup("ls");
// 	(*input)->cmds[0]->args[1] = NULL;
// 	(*input)->cmds[0]->fds[FDIN] = STDIN_FILENO;
// 	(*input)->cmds[0]->fds[FDOUT] = STDOUT_FILENO;
// 	(*input)->cmds[0]->fds[FDERROR] = STDERR_FILENO;

// 	(*input)->cmds[1] = malloc(sizeof(t_command));
// 	(*input)->cmds[1]->info = 1;
// 	(*input)->cmds[1]->args = malloc(3 * sizeof(char *));
// 	(*input)->cmds[1]->args[0] = ft_strdup("wc");
// 	(*input)->cmds[1]->args[1] = ft_strdup("-l");
// 	(*input)->cmds[1]->args[2] = NULL;
// 	(*input)->cmds[1]->fds[FDIN] = STDIN_FILENO;
// 	(*input)->cmds[1]->fds[FDOUT] = STDOUT_FILENO;
// 	(*input)->cmds[1]->fds[FDERROR] = STDERR_FILENO;
	
// 	(*input)->cmds[2] = NULL;
// }

int	main(int argc, char *argv[], char *envp[])
{
	t_input *input;
	t_list	*env;
	char	*line;
	char 	**envc;

	env = parse_env(envp);
	// while (1)
	// {
	// 	line = readline("minishell$ ");
	// 	if (line != NULL && line[0] != '\0')
	// 	{
			// add_history(line);
			// parse();
			init_input(&input, env, line);
			// if (input->noc == 1)
			// exec_one(input);
			// else
			exec_multiple(input);
	// 	}
	// }
	return (0);
}
