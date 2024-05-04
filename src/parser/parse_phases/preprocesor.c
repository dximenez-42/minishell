/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocesor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/03 18:20:49by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// not implemented

static char	*get_varname(char *str, int *i)
{
	int j;

	j = 0;
	while (ft_isalnum(str[j]))
		j++;	
	*i += j;
	return (ft_substr(str, 0, j));
}
static void proc_var(t_list *env, t_list **varlist, char *str, int *i)
{
	char	*space;
	char	*vname;
	t_list	*node;
	
	*i += 1;
	vname = get_varname(str + 1, i);
	node = ft_lstnew_type(STR, (t_content) get_env_var(env, vname));
	free(vname);
	if (!node)
	{
		free(node);
		error(ERRMEM);
	}
	ft_lstadd_back(varlist, node);
}

static int	get_real_size(t_list *varlist, char *str)
{
	int i;
	int	noc;
	t_list	*lst;

	i = 0;
	noc = 0;
	lst = varlist;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			while (str[++i] != '\'');
			i++;
		}
		if (str[i] == '$')
		{
			i++;
			while (ft_isalnum(str[i]))
				i++;
			noc += ft_strlen(lst->content.str);
			lst = lst->next;
			continue ;
		}
		noc++;
		i++;
	}
	return (noc);
}

/*
	counters[0] is the iterator of rstr
	countres[1] is the iterator of str
*/
static char	*get_preprocesed_line(t_list *varlist, char *rstr)
{
	char		*str;
	const int	len = get_real_size(varlist, rstr) + 1;
	int			counters[2];

	ft_bzero(counters, 2 * sizeof(int));
	str = ft_calloc(len, 1);
	if (!str)
		return (error(ERRMEM), NULL);
	str[0] = '\0';
	while (rstr[counters[0]])
	{
		if (rstr[counters[0]] == '\'')
		{
			str[counters[1]++] = rstr[counters[0]++];
			while (rstr[counters[0]] && rstr[counters[0]] != '\'')
				str[counters[1]++] = rstr[counters[0]++];
			str[counters[1]++] = rstr[counters[0]++];
			continue ;
		}
		if (rstr[counters[0]] == '$')
		{
			counters[0]++;
			if (rstr[counters[0]] == '?')
			{
				counters[0]++;
				continue ;
			}
			while (ft_isalnum(rstr[counters[0]]))
				counters[0]++;
			counters[1] = ft_strlcat(str, varlist->content.str, len);
			varlist = varlist->next;
			continue ;
		}
		str[counters[1]++] = rstr[counters[0]++];
	}	
	str[counters[1]] = '\0';
	return (str);
}

char	*preprocesor(t_list *env, char *str)
{
	int		i;
	char	*result;
	t_list	*varlist;

	i = 0;
	varlist = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
			continue ;
		}
		if (str[i] == '$')
		{
			proc_var(env, &varlist, str + i, &i);
			continue ;
		}
		i++;
	}
	result = get_preprocesed_line(varlist, str);
	ft_lstclear(&varlist, free);
	return (result);
}

