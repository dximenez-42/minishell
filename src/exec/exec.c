/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/11 18:26:03 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin()
{}

static void	exec_command(t_command *cmd, t_list *env)
{
	pid_t	pid;
	int		status;
	
	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"));
	if (pid == 0)
	{
		if (cmd->info == 0)
			exec_builtin();
		else if (cmd->info > 0)
			execve(get_cmd(cmd->args[0], env), cmd->args, NULL);
	}
	waitpid(pid, &status, 0);
}

void	exec_one(t_input *input, t_list *env)
{
	dup2(input->cmds[0]->fds[FDIN], STDIN_FILENO);
	dup2(input->cmds[0]->fds[FDOUT], STDOUT_FILENO);
	dup2(input->cmds[0]->fds[FDERROR], STDERR_FILENO);
	exec_command(input->cmds[0], env);
}

void	exec_multiple(t_input *input, t_list *env)
{
	int	i;
	int	**pipes;

	i = 0;
	init_pipes(input, &pipes);
	while (i < input->noc)
	{
		redirs(input, i, pipes);
		// if (input->cmds[i]->fds[FDIN] == STDIN_FILENO)
		// 	dup2(pipes[i][FDIN], STDIN_FILENO);
		// else
		// 	dup2(input->cmds[i]->fds[FDIN], STDIN_FILENO);
		// if (input->cmds[i]->fds[FDOUT] == STDOUT_FILENO)
		// 	dup2(pipes[i][FDOUT], STDOUT_FILENO);
		// else
		// 	dup2(input->cmds[i]->fds[FDOUT], STDOUT_FILENO);
		// (close(pipes[i][FDIN]), close(pipes[i][FDOUT]));
		exec_command(input->cmds[i], env);
		++i;
	}
	//TODO free pipes
}
