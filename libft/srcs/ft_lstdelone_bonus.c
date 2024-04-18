/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:48:06 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone_type(t_list *lst, void (*del)(t_content, t_type))
{
	if (!lst)
		return ;
	if (del)
		(*del)(lst -> content, lst -> type);
	free(lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst -> content.ptr);
	free(lst);
}
