/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/21 12:51:29 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_input(t_input *input)
{
	input = malloc(sizeof(t_input));
	input->noc = 1;
	input->cmds = malloc(1 * sizeof(t_command));
	input->cmds->info = 0;
	input->cmds->args = malloc(2 * sizeof(char *));
	input->cmds->args[0] = malloc(3 * sizeof(char));
	input->cmds->args[0] = "cd";
	input->cmds->args[1] = malloc(6 * sizeof(char));
	input->cmds->args[1] = "libft";
	input->cmds->fds[FDIN] = FDIN;
	input->cmds->fds[FDOUT] = FDOUT;
	input->cmds->fds[FDERROR] = FDERROR;
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
			init_input(input);
			if (input->noc == 1)
				exec_one(&input->cmds[0], input->env);
			else
				exec_multiple(&input->cmds, input->env);
		}
	}
	return (0);
}
