/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:10 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/1 13:14:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*parse_env(char **envp)
{
	int			i;
	char		*separator;
	t_list		*env;
	t_list		*node;	
	t_env_var	*env_var;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		separator = ft_strchr(envp[i], '=');
		env_var = malloc(1 * sizeof(t_env_var));
		if (!env_var)
			return (ft_lstclear_type(&env, clear_env_list), NULL);
		env_var->name = ft_substr(envp[i], 0, separator - envp[i]);
		env_var->value = ft_strdup(separator + 1);
		node = ft_lstnew_type(OTHER, (t_content)((void *)env_var));
		if (!node)
			return (free(env_var), ft_lstclear_type(&env, clear_env_list)
				, NULL);
		ft_lstadd_back(&env, node);
		i++;
	}
	set_qtmark(&env, 0);
	return (env);
}

static void	free_splitted_commands(t_content cnt, t_type type)
{
	(void) type;
	free(cnt.str);
}

t_input	*parse_line(t_list **env, char *line)
{
	t_input	*result;
	t_list	*buffer;
	t_list	*aux;

	if (g_signum == SIGINT)
	{
		set_qtmark(env, 130);
		g_signum = 0;
	}
	if (g_signum == 3)
	{
		set_qtmark(env, 131);
		g_signum = 0;
	}
	buffer = split_commands(line);
	aux = ft_lstmap_env(*env, buffer, create_token_list, NULL);
	ft_lstclear_type(&buffer, free_splitted_commands);
	buffer = aux;
	result = create_input(env, buffer);
	ft_lstclear_type(&buffer, NULL);
	return (result);
}
