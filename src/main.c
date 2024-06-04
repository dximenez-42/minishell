/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/03 12:32:37 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void check_status(int status) {
	if (WIFEXITED(status)) {
		int exit_status = WEXITSTATUS(status);
		printf("Process exited with status %d\n", exit_status);
	} else if (WIFSIGNALED(status)) {
		int signal_number = WTERMSIG(status);
		printf("Process was terminated by signal %d\n", signal_number);
	} else if (WIFSTOPPED(status)) {
		int stop_signal = WSTOPSIG(status);
		printf("Process was stopped by signal %d\n", stop_signal);
	} else if (WIFCONTINUED(status)) {
		printf("Process was resumed by SIGCONT\n");
	}
}

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

int	is_empty_line(char *line)
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
				return ((void)printf("exit: too many args\n"));
			else
			{
				if (ft_isnumber(input->cmds[0]->args[1]))
					code = ft_atoi(input->cmds[0]->args[1]);
				else
					return ((void)printf("The argument must be numeric\n"));
			}
			printf("exit\n");
			exit(code);
		}
		exec_one(input, status);
	}	
	else
		exec_multiple(input, status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;
	int		status;

	((void) argc, (void) argv);
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
			}
		}
		free(rawline);
		check_status(status);
		rawline = readline("minishell: ");
	}
	return (ft_lstclear_type(&env, clear_env_list), 0);
}
