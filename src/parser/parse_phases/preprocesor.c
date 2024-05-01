/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocesor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/01 17:47:43 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// not implemented
static int	proc_quoque(t_list *env, t_list **varlist, char *quoque)
{
	int		i;
	t_list	*node;
	t_list	*temp_list;
	char	*exp_quoque;

	i = 0;
	if (quoque[0] == '\'')
	{
		exp_quoque = ft_strdup(quoque);
		free(quoque);
		return (exp_quoque);
	}
	while (quoque[i])
	{
		if (quoque[i] == '$')
		{
			node = ft_lstnew(get_env_var(env, get_vaname(quoque - i)));
			ft_lstadd_back(temp_list, node);
		}
		i++;
	}
	exp_quoque = get_preprocesed_string(quoque, temp_list); //not implemented
	free(quoque);
	ft_lstclear(&temp_list, free);
	return (exp_quoque);
}

char	*preprocesor(t_list *env, char *str)
{
	int		i;
	char	*fquoque;
	t_list	*varlist;

	i = 0;
	varlist = NULL;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			fquoque = ft_strchr(str + i + 1, str[i]);
			if (!fquoque)
			{
				error(ERRFORMAT);
				return (NULL);
			}
			i += proc_quoque(env, &varlist, ft_substr(str, i, str - fquoque));
		}
	}
	return (NULL);
}
