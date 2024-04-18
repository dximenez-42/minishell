/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:33:23 by bvelasco          #+#    #+#             */
/*   Updated: 2024/02/06 12:02:17 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstdup(t_list *lst, void (*del)(t_content, t_type))
{
	t_list		*result;
	t_list		*node;
	t_content	content;

	result = NULL;
	while (lst)
	{
		content = lst->content;
		node = ft_lstnew_type(lst->type, content);
		if (!node)
		{
			ft_lstclear_type(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
