/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:13:19 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/24 15:08:27 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_env_var(t_list *env, char *name)
{
	t_env_var	*var;
	t_list		*current;

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
		return (MEMERROR);
	var->name = ft_strdup(name);
	var->value = ft_strdup(value);
	node = ft_lstnew_type(OTHER, (t_content)((void *) var));
	if (!node || !var->name || !var->value)
	{
		free(var->name);
		free(var->value);
		free(var);
		free(node);
		return (MEMERROR);
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
				current->next->prev = current->prev;
			free(var->name);
			free(var->value);
			free((void *)var);
			free(current);
			return (0);
		}
		current = current->next;
	}
	return (NOT_FOUND);
}

char	**ft_getenv(t_list *env)
{
	int		i;
	int		j;
	int		len;
	t_list	*current;
	char	**ret;

	i = 0;
	current = env;
	i = ft_lstsize(env);
	ret = malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		len = ft_strlen(((t_env_var *)env->content.oth)->name)
			+ ft_strlen(((t_env_var *)env->content.oth)->value) + 1;
		ret[j] = malloc(len);
		ft_strlcpy(ret[j], ((t_env_var *)env->content.oth)->name, len);
		ft_strlcat(ret[j], "=", len);
		ft_strlcat(ret[j], ((t_env_var *) env->content.oth)->value, len);
		env = env->next;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

int	print_env(t_list *env, int fd)
{
	t_list		*current;
	t_env_var	*var;

	current = env;
	while (current)
	{
		var = current->content.oth;
		ft_putstr_fd(var->name, fd);
		ft_putchar_fd('=', fd);
		ft_putendl_fd(var->value, fd);
		current = current->next;
	}
	return (0);
}