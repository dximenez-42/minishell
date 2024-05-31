/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:13:25 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/31 20:57:01 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_pipes(t_input *input, int ***pipes)
{
	int	i;

	i = 0;
	*pipes = malloc((input->noc - 1) * sizeof(int *));
	if (*pipes == NULL)
		return ((void) printf("malloc 1 failed\n"));
	while (i < input->noc - 1)
	{
		(*pipes)[i] = malloc (2 * sizeof(int));
		if ((*pipes)[i] == NULL)
			return ((void) printf("malloc 2 failed\n"));
		if (pipe((*pipes)[i]) == -1)
			return ((void) printf("pipe failed\n"));
		++i;
	}
}

void	close_pipes(int **pipes, int noc)
{
	int	i;

	i = 0;
	while (i < noc - 1)
	{
		close(pipes[i][FDIN]);
		close(pipes[i][FDOUT]);
		++i;
	}
}

void	free_pipes(int **pipes, int noc)
{
	int	i;

	i = 0;
	while (i < noc - 1)
	{
		free(pipes[i]);
		++i;
	}
	free(pipes);
}
