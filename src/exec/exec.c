/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/29 14:55:26 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin()
{}

static void	exec_command(t_input *input, int i, int **pipes)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		return ((void) printf("fork error\n"), exit(1));
	if (pid == 0)
	{
		if (pipes != NULL)
			redirs(input, i, pipes);
	//	if (input->cmds[i]->info == 0)
	//		exec_builtin();
		// else if (input->cmds[i]->info > 0)
		if (execve(get_cmd(input->cmds[i]->args[0], input->env), input->cmds[i]->args, ft_getenv(input->env)) == -1)
			(perror("Command not found"), exit(127));
	}
	if (pipes == NULL)
		waitpid(pid, NULL, 0);
}

void	exec_one(t_input *input)
{
	dup2(input->cmds[0]->fds[FDIN], STDIN_FILENO);
	dup2(input->cmds[0]->fds[FDOUT], STDOUT_FILENO);
	dup2(input->cmds[0]->fds[FDERROR], STDERR_FILENO);
	exec_command(input, 0, NULL);
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
