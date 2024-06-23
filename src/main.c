/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/22 15:45:23 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (1);
		line++;
	}
	return (0);
}

static void	executor(t_input *input, int *status)
{
	__int8_t	code;	

	signal(SIGINT, sigint_handler_notty);
	*status = 127;
	if (input && input->noc == 1)
	{
		if (input->cmds[0]->args && input->cmds[0]->args[0]
			&& !ft_strncmp(input->cmds[0]->args[0], "exit", 5))
		{
			if (input->cmds[0]->argc < 2)
				code = 0;
			else if (input->cmds[0]->argc > 2)
				return ((void)perror("exit: too many args\n"));
			else
				if (!ft_isnumber(input->cmds[0]->args[1]))
					return ((void)printf("The argument must be numeric\n"));
			else
				code = ft_atoi(input->cmds[0]->args[1]);
			(printf("exit\n"), exit(code));
		}
		exec_one(input, status);
	}
	else if (input && input->noc > 1)
		exec_multiple(input, status);
	signals();
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;
	int		status;

	((void) argc, (void) argv, signals(), get_cwd());
	env = parse_env(envp);
	rawline = readline("minishell: ");
	while (rawline)
	{
		if (rawline[0] != 0)
		{
			add_history(rawline);
			if (is_empty_line(rawline))
			{
				input = parse_line(&env, rawline);
				executor(input, &status);
				set_qtmark(&env, status);
				clear_input(input);
			}
		}
		free(rawline);
		rawline = readline("minishell: ");
	}
	return (ft_lstclear_type(&env, clear_env_list), 0);
}
