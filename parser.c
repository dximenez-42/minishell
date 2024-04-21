/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:10 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/21 13:56:52 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/minishell.h"

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
		env_var = malloc(sizeof(t_env_var));
		if (!env_var)
			return (ft_lstclear_type(&env, NULL), NULL);
		env_var->name = ft_substr(envp[i], 0, separator - envp[i]);
		env_var->value = ft_strdup(separator + 1);
		node = ft_lstnew_type(PTR, (t_content) ((void *)env_var));
		/*if (!node)
			return (free(env_var), NULL);*/
		ft_lstadd_back(&env, node);
		i++;
	}
	return (env);
}