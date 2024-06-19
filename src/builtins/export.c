/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:05:22 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/19 17:03:10 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_builtin(t_input *input, int i)
{
	char	**split;

	if (input->cmds[i]->argc != 2)
		return (1);
	split = ft_split(input->cmds[i]->args[1], '=');
	if (split[1] == NULL || split[2] != NULL)
		return (1);
	set_env_var(input->env, split[0], split[1]);
	ft_free_ptr_array(split);
	return (0);
}
