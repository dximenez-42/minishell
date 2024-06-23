/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:05:22 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/23 14:56:09 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**export_split(char *raw)
{
	char	*separator;
	char	**splitted;

	separator = ft_strchr(raw, '=');
	if (!separator)
		return (0);
	*separator = 0;
	splitted = malloc(2 * sizeof(void *));
	if (!splitted)
		return (0);
	splitted[0] = raw;
	splitted[1] = separator + 1;
	return (splitted);
}

int	export_builtin(t_input *input, int i)
{
	char	**split;
	int		j;

	j = 1;
	if (input->cmds[i]->argc < 2)
		return (1 << 8);
	while (j < input->cmds[i]->argc)
	{
		split = export_split(input->cmds[i]->args[j++]);
		if (!split)
			continue;
		set_env_var(input->env, split[0], split[1]);
		free(split);
	}
	return (0);
}
