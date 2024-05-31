/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/31 19:01:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin(t_input *input, int i)
{
	t_command	*cmd;

	cmd = input->cmds[i];
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		echo_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		cd_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		pwd_builtin(input, i);
}

static void	exec_command(t_input *input, int i, int **pipes)
{
	pid_t			pid;
	const t_command	*cmd = input->cmds[i];

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		redirs(input, i, pipes);
		if (cmd->info == 0)
			exec_builtin(input, i);
		else if (cmd->info > 0)
			if (execve(get_cmd(cmd, input), cmd->args, ft_getenv(input->env)) == -1)
				(perror("Command not found"), exit(127));
	}
}

void	exec_one(t_input *input)
{
	pid_t			pid;
	const t_command	*cmd = input->cmds[0];

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		dup2(cmd->fds[FDIN], STDIN_FILENO);
		dup2(cmd->fds[FDOUT], STDOUT_FILENO);
		dup2(cmd->fds[FDERROR], STDERR_FILENO);
		if (cmd->info == 0)
			exec_builtin(input, 0);
		else if (cmd->info > 0)
			if (execve(get_cmd(cmd, input), cmd->args, ft_getenv(input->env)) == -1)
				(perror("Command not found"), exit(127));
	}
	wait(NULL);
}

void	exec_multiple(t_input *input)
{
	int	i;
	int	**pipes;

	i = -1;
	init_pipes(input, &pipes);
	while (++i < input->noc)
		exec_command(input, i, pipes);
	close_pipes(pipes, input->noc);
	i = -1;
	while (++i < input->noc)
		wait(NULL);
	free_pipes(pipes, input->noc);
}
