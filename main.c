/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/01 14:50:30 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	init_input(t_input **input, char *line)
{
	(*input) = malloc(sizeof(t_input));
	(*input)->noc = 1;
	(*input)->cmds = malloc(1 * sizeof(t_command));
	
	(*input)->cmds[0].info = 1;
	(*input)->cmds[0].args = ft_split(line, ' ');
	(*input)->cmds[0].fds[FDIN] = FDIN;
	(*input)->cmds[0].fds[FDOUT] = FDOUT;
	(*input)->cmds[0].fds[FDERROR] = FDERROR;
}

// void	init_input(t_input **input, char *line)
// {
// 	(*input) = malloc(sizeof(t_input));
// 	(*input)->noc = 3;
// 	(*input)->cmds = malloc(3 * sizeof(t_command));
	
// 	(*input)->cmds[0].info = 1;
// 	(*input)->cmds[0].args = malloc(3 * sizeof(char *));
// 	(*input)->cmds[0].args[0] = ft_strdup("ls");
// 	(*input)->cmds[0].args[1] = ft_strdup("-l");
// 	(*input)->cmds[0].args[2] = NULL;
// 	(*input)->cmds[0].fds[FDIN] = FDIN;
// 	(*input)->cmds[0].fds[FDOUT] = FDOUT;
// 	(*input)->cmds[0].fds[FDERROR] = FDERROR;
	
// 	(*input)->cmds[1].info = 1;
// 	(*input)->cmds[1].args = malloc(3 * sizeof(char *));
// 	(*input)->cmds[1].args[0] = ft_strdup("grep");
// 	(*input)->cmds[1].args[1] = ft_strdup("a");
// 	(*input)->cmds[1].args[2] = NULL;
// 	(*input)->cmds[1].fds[FDIN] = FDIN;
// 	(*input)->cmds[1].fds[FDOUT] = FDOUT;
// 	(*input)->cmds[1].fds[FDERROR] = FDERROR;
	
// 	(*input)->cmds[2].info = 1;
// 	(*input)->cmds[2].args = malloc(3 * sizeof(char *));
// 	(*input)->cmds[2].args[0] = ft_strdup("wc");
// 	(*input)->cmds[2].args[1] = ft_strdup("-l");
// 	(*input)->cmds[2].args[2] = NULL;
// 	(*input)->cmds[2].fds[FDIN] = FDIN;
// 	(*input)->cmds[2].fds[FDOUT] = FDOUT;
// 	(*input)->cmds[2].fds[FDERROR] = FDERROR;
// }


int	main(int argc, char *argv[], char *envp[])
{
	t_input *input;
	t_list	*env;
	char	*line;
	char 	**envc;

	env = parse_env(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line != NULL && line[0] != '\0')
		{
			add_history(line);
			// parse();
			init_input(&input, line);
			if (input->noc == 1)
				exec_one(&input->cmds[0], env);
			else
				exec_multiple(&input->cmds, env);
		}
	}
	return (0);
}
