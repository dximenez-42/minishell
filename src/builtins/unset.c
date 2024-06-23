/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:04:56 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/23 16:19:02 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset_builtin(t_input *input, int i)
{
	int	j;

	j = 1;
	while (j < input->cmds[i]->argc)
		rem_env_var(input->env, input->cmds[i]->args[j++]);
	return (0);
}
