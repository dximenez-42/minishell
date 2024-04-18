/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borja <borja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:17:35 by bvelasco          #+#    #+#             */
/*   Updated: 2024/02/21 13:53:39 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	t_list	*clear_content_type(t_content content,
		t_type type, void (*del)(t_content, t_type))
{
	if (del)
		(*del)(content, type);
	return (0);
}

t_list	*ft_lstrmap_type(t_list *lst, t_type type,
		t_content (*f)(t_content, t_type), void (*del)(t_content, t_type))
{
	t_list		*ret;
	t_content	tmp_content;
	int			i;

	if (!lst || !f)
		return (0);
	tmp_content = (f)(lst -> content, lst -> type);
	ret = ft_lstnew_type(type, tmp_content);
	if (!ret)
		return (clear_content_type(tmp_content, type, del));
	i = 1;
	lst = lst -> prev;
	while (lst)
	{
		tmp_content = (*f)(lst -> content, type);
		ft_lstadd_front(&ret, (ft_lstnew_type(type, tmp_content)));
		i++;
		if (ft_lstsize(ret) != i)
		{
			ft_lstclear_type(&ret, del);
			return (clear_content_type(tmp_content, type, del));
		}
		lst = lst -> prev;
	}
	return (ret);
}

t_list	*ft_lstmap_type(t_list *lst, t_type type,
		t_content (*f)(t_content, t_type), void (*del)(t_content, t_type))
{
	t_list		*ret;
	t_content	tmp_content;
	int			i;

	if (!lst || !f)
		return (0);
	tmp_content = (f)(lst -> content, lst -> type);
	ret = ft_lstnew_type(type, tmp_content);
	if (!ret)
		return (clear_content_type(tmp_content, type, del));
	i = 1;
	lst = lst -> next;
	while (lst)
	{
		tmp_content = (*f)(lst -> content, type);
		ft_lstadd_back(&ret, (ft_lstnew_type(type, tmp_content)));
		i++;
		if (ft_lstsize(ret) != i)
		{
			ft_lstclear_type(&ret, del);
			return (clear_content_type(tmp_content, type, del));
		}
		lst = lst -> next;
	}
	return (ret);
}

//deprecated
static t_list	*clear_content(void *content, void (*del)(void *))
{
	(*del)(content);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*ret;
	t_content		tmp_content;
	int				i;

	if (!lst || !f || !del)
		return (0);
	tmp_content.ptr = (f)(lst -> content.ptr);
	ret = ft_lstnew(tmp_content.ptr);
	if (!ret)
		return (clear_content(tmp_content.ptr, del));
	i = 1;
	lst = lst -> next;
	while (lst)
	{
		tmp_content.ptr = (*f)(lst -> content.ptr);
		ft_lstadd_back((t_list **)&ret, (ft_lstnew(tmp_content.ptr)));
		i++;
		if (ft_lstsize((t_list *)ret) != i)
		{
			ft_lstclear((t_list **)&ret, del);
			return (clear_content(tmp_content.ptr, del));
		}
		lst = lst -> next;
	}
	return ((t_list *)ret);
}
