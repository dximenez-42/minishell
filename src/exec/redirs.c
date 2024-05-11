/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:04:06 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/11 18:40:05 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	redir_first(t_input *input, int i, int **pipes)
{
	if (input->cmds[i]->fds[FDIN] != STDIN_FILENO)
		dup2(input->cmds[i]->fds[FDIN], STDIN_FILENO);
	if (input->cmds[i]->fds[FDOUT] == STDOUT_FILENO)
		dup2(pipes[i][FDOUT], STDOUT_FILENO);
	else
		dup2(input->cmds[i]->fds[FDOUT], STDOUT_FILENO);
}

static void	redir_between(t_input *input, int i, int **pipes)
{
	if (input->cmds[i]->fds[FDIN] == STDIN_FILENO)
		dup2(pipes[i][FDIN], STDIN_FILENO);
	else
		dup2(input->cmds[i]->fds[FDIN], STDIN_FILENO);
	if (input->cmds[i]->fds[FDOUT] == STDOUT_FILENO)
		dup2(pipes[i][FDOUT], STDOUT_FILENO);
	else
		dup2(input->cmds[i]->fds[FDOUT], STDOUT_FILENO);
}

static void	redir_last(t_input *input, int i, int **pipes)
{
	if (input->cmds[i]->fds[FDIN] == STDIN_FILENO)
		dup2(pipes[i][FDIN], STDIN_FILENO);
	else
		dup2(input->cmds[i]->fds[FDIN], STDIN_FILENO);
	if (input->cmds[i]->fds[FDOUT] != STDOUT_FILENO)
		dup2(input->cmds[i]->fds[FDOUT], STDOUT_FILENO);
}

void	redirs(t_input *input, int i, int **pipes)
{
	if (i == 0)
		redir_first(input, i, pipes);
	else if (i == input->noc - 1)
		redir_between(input, i, pipes);
	else
		redir_last(input, i, pipes);
	dup2(input->cmds[i]->fds[FDERROR], STDERR_FILENO);
	(close(pipes[i][FDIN]), close(pipes[i][FDOUT]));
}

void	init_pipes(t_input *input, int ***pipes)
{
	int	i;

	i = 0;
	*pipes = malloc(input->noc * sizeof(int *));
	if (*pipes == NULL)
		return ((void) printf("malloc failed\n"));		//TODO malloc failed
	while (i < input->noc)
	{
		(*pipes)[i] = malloc (2 * sizeof(int));
		if ((*pipes)[i] == NULL)
			return ((void) printf("malloc failed\n"));		//TODO malloc failed
		if (pipe((*pipes)[i]) == -1)
			return ((void) printf("pipe failed\n"));		//TODO pipe failed
		++i;
	}
}
