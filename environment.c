/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:13:19 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 17:39:32 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_list *env, char *name)
{
	t_env_var	*var;
	t_list		*current;
	current = env;
	while (current)
	{
		var = current->content.oth;
		if (!ft_strncmp(name, var->name, ft_strlen(name) + 1))
			return (var->value);
		current = current->next;
	}
	return (NULL);
}

int	set_env_var(t_list **env, char *name, char *value)
{
	return (1);
}

int	rem_env_var(t_list **env, char *name)
{
	return (1);
}
char **ft_getenv(t_list *env);
int	print_env(t_list *env)
{
	return (1);
}
