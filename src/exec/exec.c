/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/30 14:34:24 by dximenez         ###   ########.fr       */
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
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		redirs(input, i, pipes);
	//	if (input->cmds[i]->info == 0)
	//		exec_builtin(input, i);
		// else if (input->cmds[i]->info > 0)
		if (execve(get_cmd(input->cmds[i]->args[0], input->env), input->cmds[i]->args, ft_getenv(input->env)) == -1)
			(perror("Command not found"), exit(127));
	}
}

void	exec_one(t_input *input)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		dup2(input->cmds[0]->fds[FDIN], STDIN_FILENO);
		dup2(input->cmds[0]->fds[FDOUT], STDOUT_FILENO);
		dup2(input->cmds[0]->fds[FDERROR], STDERR_FILENO);
	//	if (input->cmds[i]->info == 0)
			// exec_builtin(input, 0);
		// else if (input->cmds[i]->info > 0)
		if (execve(get_cmd(input->cmds[0]->args[0], input->env), input->cmds[0]->args, ft_getenv(input->env)) == -1)
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
