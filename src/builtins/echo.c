/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:54:43 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/21 21:40:23 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_builtin(t_input *input, int i)
{
	if (ft_strncmp(input->cmds[i]->args[1], "-n", 2) == 0)
		printf("%s", input->cmds[i]->args[2]);
	else
		printf("%s\n", input->cmds[i]->args[1]);
}
