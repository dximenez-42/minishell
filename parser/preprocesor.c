/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocesor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/23 21:27:34 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*proc_quoques(char *quoque, char type, int len)
{
	int		i;
	t_list	*expanded;
	t_list	*node;
	char	*result;

	i = 0;
	expanded = NULL;
	if (type == '/')
		return (quoque);
	else
	{
		while (quoque[i] && i < len);
		{
			if (quoque[i] == '$')
			{
				node = ft_lstnew_type(STR, (t_content ) expand_var(quoque[i + 1]));
				if (!node)
					ft_lstclear(node, free);
				while (quoque[i] || quoque[i] != ' ' || quoque[i] != '$')
					i++;
				continue ;
			}
		}
		result = expand_vars(quoque, expanded);
	}
	return (result);
}
//not implemented
char *preprocesor(char *str, t_list *env)
{
	return (NULL);
}