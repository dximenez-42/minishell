/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:10:59 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear_type(t_list **lst, void (*del)(t_content, t_type))
{
	t_list	*next_node;

	if (!lst || !(*lst))
		return ;
	while ((*lst))
	{
		next_node = (*lst)-> next;
		ft_lstdelone_type(*lst, del);
		*lst = next_node;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (!lst || !del || !(*lst))
		return ;
	while ((*lst))
	{
		next_node = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
}
