/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/29 17:55:00 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
