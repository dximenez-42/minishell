/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:58:57 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/06 15:11:42 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//t_lstmap modified for work with envirnoments
t_list	*ft_lstmap_env(t_list *env, t_list *lst,
			t_content (*f)(t_list *, t_content),
			void (*del)(t_content, t_type))
{
	t_list		*result;
	t_content	tmp_content;

	if (!lst || !env || !f)
		return (0);
	result = 0;
	errno = 0;
	while (lst)
	{
		tmp_content = (f)(env, lst->content);
		ft_lstadd_back(&result, ft_lstnew_type(OTHER, tmp_content));
		if (errno)
			return (ft_lstclear_type(&result, del), NULL);
		lst = lst->next;
	}
	return (result);
}
