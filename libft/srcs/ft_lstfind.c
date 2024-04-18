/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:15:52 by bvelasco          #+#    #+#             */
/*   Updated: 2024/02/15 17:16:37 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstfind(t_content content, t_type type, t_list *list)
{
	while (list)
	{
		if (type == INT)
			if (list->content.i == content.i)
				return (list);
		if (type == CHAR)
			if (list->content.c == content.c)
				return (list);
		if (type == FLOAT)
			if (list->content.f == content.f)
				return (list);
		if (type == DOUBLE)
			if (list->content.d == content.d)
				return (list);
		if (type == PTR)
			if (list->content.ptr == content.ptr)
				return (list);
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstrfind(t_content content, t_type type, t_list *list)
{
	while (list)
	{
		if (type == INT)
			if (list->content.i == content.i)
				return (list);
		if (type == CHAR)
			if (list->content.c == content.c)
				return (list);
		if (type == FLOAT)
			if (list->content.f == content.f)
				return (list);
		if (type == DOUBLE)
			if (list->content.d == content.d)
				return (list);
		if (type == PTR)
			if (list->content.ptr == content.ptr)
				return (list);
		list = list->prev;
	}
	return (0);
}
