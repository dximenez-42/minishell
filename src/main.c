/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 16:10:46 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	close_fds(t_command *cmd)
{
	if (cmd->fds[0] != 0 && cmd->fds[0] >= 0)
		close(cmd->fds[0]);
	if (cmd->fds[1] != 1 && cmd->fds[1] >= 0)
		close(cmd->fds[1]);
	if (cmd->fds[2] != 2 && cmd->fds[2] >= 0)
		close(cmd->fds[2]);
}

static void	clear_input(t_input *input)
{
	int	i;

	i = 0;
	while (i < input->noc)
	{
		close_fds(input->cmds[i]);
		ft_free_ptr_array(input->cmds[i]->args);
		free(input->cmds[i]);
		i++;
	}
	free(input->cmds);
	free(input);
}

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

	if (input->noc == 1)
	{
		if (input->cmds[0]->args && input->cmds[0]->args[0]
			&& !ft_strncmp(input->cmds[0]->args[0], "exit", 5))
		{
			if (input->cmds[0]->argc < 2)
				code = 0;
			else if (input->cmds[0]->argc > 2)
				return ((void)perror("exit: too many args\n"));
			else
			{
				if (ft_isnumber(input->cmds[0]->args[1]))
					code = ft_atoi(input->cmds[0]->args[1]);
				else
					return ((void)perror("The argument must be numeric\n"));
			}
			printf("exit\n");
			exit(code);
		}
		exec_one(input, status);
	}
	else if (input->noc > 1)
		exec_multiple(input, status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;
	int		status;

	((void) argc, (void) argv, signals());
	env = parse_env(envp);
	rawline = readline("minishell: ");
	while (rawline)
	{
		if (rawline[0] != 0)
		{
			add_history(rawline);
			if (is_empty_line(rawline))
			{
				input = parse_line(env, rawline);
				executor(input, &status);
				clear_input(input);
				set_qtmark(env, status);
			}
		}
		free(rawline);
		rawline = readline("minishell: ");
	}
	return (ft_lstclear_type(&env, clear_env_list), 0);
}
