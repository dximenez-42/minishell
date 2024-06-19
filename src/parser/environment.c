/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:13:19 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 19:29:26 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_var(t_list *env, char *name)
{
	t_env_var	*var;
	t_list		*current;

	if (!env || !name)
		return (NULL);
	current = env;
	while (current)
	{
		var = current->content.oth;
		if (!ft_strncmp(name, var->name, ft_strlen(name) + 1))
			return (ft_strdup(var->value));
		current = current->next;
	}
	return (NULL);
}

int	set_env_var(t_list **env, char *name, char *value)
{
	t_env_var	*var;
	t_list		*node;
	char		*buff;

	var = malloc(sizeof(t_env_var));
	if (!var)
		return (ERRMEM);
	var->name = ft_strdup(name);
	var->value = ft_strdup(value);
	node = ft_lstnew_type(OTHER, (t_content)((void *) var));
	if (!node || !var->name || !var->value)
	{
		free(var->name);
		free(var->value);
		free(var);
		free(node);
		return (ERRMEM);
	}
	buff = get_env_var(*env, name);
	if (buff)
		rem_env_var(env, name);
	free(buff);
	ft_lstadd_back(env, node);
	return (0);
}

int	rem_env_var(t_list **env, char *name)
{
	t_env_var	*var;
	t_list		*current;

	current = *env;
	while (current)
	{
		var = current->content.oth;
		if (!ft_strncmp(name, var->name, ft_strlen(name) + 1))
		{
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
			{
				current->next->prev = current->prev;
				if (*env == current)
					*env = current->next;
			}
			if (!current->next && !current->prev)
				*env = NULL;
			(free(var->name), free(var->value));
			return (free((void *)var), free(current), 0);
		}
		current = current->next;
	}
	return (ERRNFOUND);
}

char	**ft_getenv(t_list *env)
{
	int		i;
	int		j;
	int		len;
	char	**ret;

	i = 0;
	i = ft_lstsize(env);
	ret = ft_calloc((i + 1), sizeof(char *));
	j = 0;
	while (j < i)
	{
		if (ft_strncmp(((t_env_var *)env->content.oth)->name, "?", 2))
		{
		len = ft_strlen(((t_env_var *)env->content.oth)->name)
			+ ft_strlen(((t_env_var *)env->content.oth)->value) + 2;
		ret[j] = malloc(len);
		ft_strlcpy(ret[j], ((t_env_var *)env->content.oth)->name, len);
		ft_strlcat(ret[j], "=", len);
		ft_strlcat(ret[j], ((t_env_var *) env->content.oth)->value, len);
		}
		env = env->next;
		j++;
	}
	return (ret);
}

size_t	get_env_var_len(t_list *env, char *varname)
{
	t_env_var	*var;

	while (env)
	{
		var = env->content.oth;
		if (!ft_strncmp(varname, var->name, ft_strlen(varname) + 1))
		{
			return (ft_strlen(var->value));
		}
		env = env->next;
	}
	return (0);
}
