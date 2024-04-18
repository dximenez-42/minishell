/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:12:06 by bvelasco          #+#    #+#             */
/*   Updated: 2024/01/25 19:27:23 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstriter_type(t_list *lst, void (*f)(t_content, t_type))
{
	while (lst)
	{
		(*f)(lst -> content, lst -> type);
		lst = lst -> prev;
	}
}

void	ft_lstiter_type(t_list *lst, void (*f)(t_content, t_type))
{
	while (lst)
	{
		(*f)(lst -> content, lst -> type);
		lst = lst -> next;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst -> content.ptr);
		lst = lst -> next;
	}
}
