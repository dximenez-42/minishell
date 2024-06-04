/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:54:43 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/04 14:21:01 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_flag(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-')
	{
		while (str[i] == 'n')
			++i;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int	echo_builtin(t_input *input, int i)
{
	int	j;
	int	newline;

	j = 1;
	newline = 1;
	while (input->cmds[i]->args[j] != NULL)
	{
		if (check_flag(input->cmds[i]->args[j]))
			newline = 0;
		else
		{
			printf("%s", input->cmds[i]->args[j]);
			if (input->cmds[i]->args[j + 1])
				printf(" ");
		}
		++j;
	}
	if (newline == 1)
		printf("\n");
	return (0);
}
