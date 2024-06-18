/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/10 20:23:32 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin_parent(t_input *input, int i, int *status)
{
	t_command	*cmd;

	cmd = input->cmds[i];
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		*status = cd_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		*status = export_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		*status = unset_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		*status = 0;
}

void	exec_builtin_child(t_input *input, int i)
{
	t_command	*cmd;
	int			status;

	cmd = input->cmds[i];
	status = 1;
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		status = echo_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		status = 0;
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		status = pwd_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		status = env_builtin(input, i);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		status = 0;
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		status = 0;
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		status = 0;
	exit(status);
}

static void	exec_command(t_input *input, int i, int **pipes)
{
	pid_t			pid;
	const t_command	*cmd = input->cmds[i];
	char			*location;

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		redirs(input, i, pipes);
		if (cmd->info == 0 || cmd->info == 1)
			exec_builtin_child(input, i);
		else if (cmd->info >= 2)
		{
			location = get_cmd(cmd, input);
			if (execve(location, cmd->args, ft_getenv(input->env)) == -1)
				(perror("Command not found"), exit(127));
			free(location);
		}
	}
}

void	exec_one(t_input *input, int *status)
{
	pid_t			pid;
	const t_command	*cmd = input->cmds[0];
	char			*location;

	if (cmd->info == 1)
		return (exec_builtin_parent(input, 0, status));
	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		dup2(cmd->fds[FDIN], STDIN_FILENO);
		dup2(cmd->fds[FDOUT], STDOUT_FILENO);
		dup2(cmd->fds[FDERROR], STDERR_FILENO);
		if (cmd->info == 0 || cmd->argc == 0)
			exec_builtin_child(input, 0);
		else if (cmd->info >= 2)
		{
			location = get_cmd(cmd, input);
			if (execve(location, cmd->args, ft_getenv(input->env)) == -1)
				(perror("Command not found"), exit(127));
			free(location);
		}
	}
	waitpid(-1, status, 0);
}

void	exec_multiple(t_input *input, int *status)
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
		waitpid(-1, status, 0);
		// if (input->cmds[i]->info >= 0 && input->cmds[i]->info != 1)
	free_pipes(pipes, input->noc);
}
