/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:45:54 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/19 00:46:11 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	**separe_tokens(t_list *token_list)
{
	t_list	**result;
	t_list	*temp;
	t_token	*tok;

	result = ft_calloc(2, sizeof(void *));
	if (!result)
		return (NULL);
	while (token_list)
	{
		tok = token_list->content.oth;
		temp = token_list->next;
		token_list->next = NULL;
		token_list->prev = NULL;
		if (tok->type == ARG)
			ft_lstadd_back(result, token_list);
		if (tok->type == RD || tok->type == HD)
			ft_lstadd_back(result + 1, token_list);
		token_list = temp;
	}
	return (result);
}
