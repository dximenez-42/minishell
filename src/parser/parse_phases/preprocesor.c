/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocesor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:26:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/04 18:47:59 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"



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

	i = 0;
	noc = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			noc += get_quotelen(str + i);
			i += get_quotelen(str + i);
			continue ;
		}
		if (str[i] == '$')
		{
			i = i + (get_varlen(str + ++i));
			noc += ft_strlen(varlist->content.str);
			varlist = varlist->next;
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
			copy_simple_quoute(rstr, str, &counters[0], &counters[1]);
		if (rstr[counters[0]] == '$')
		{
			counters[0] += get_varlen(rstr + ++counters[0]);
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

