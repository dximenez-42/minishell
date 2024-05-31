/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:54:43 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/30 14:19:40 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_builtin(t_input *input, int i)
{
	int	j;

	if (input->cmds[i]->args[1] != NULL
		&& ft_strncmp(input->cmds[i]->args[1], "-n", 3) == 0)
		j = 2;
	else
		j = 1;
	while (input->cmds[i]->args[j] != NULL)
	{
		printf("%s", input->cmds[i]->args[j]);
		if (input->cmds[i]->args[j + 1])
			printf(" ");
		++j;
	}
	if (input->cmds[i]->args[1] == NULL
		|| ft_strncmp(input->cmds[i]->args[1], "-n", 3) != 0)
		printf("\n");
}
