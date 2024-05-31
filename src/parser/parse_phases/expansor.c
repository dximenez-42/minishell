/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:10:46 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 21:11:43 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*get_varlist(t_list *env, char *str)
{
	t_list	*result;
	t_list	*node;
	char	*varname;
	char	*value;
	int		i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			varname = get_varname(str + i, &i);
			value = get_env_var(env, varname);
			node = ft_lstnew_type(STR, (t_content) value);
			if (!node)
				return (free(value), ft_lstclear(&result, free), NULL);
			ft_lstadd_back(&result, node);
			continue ;
		}
		i++;
	}
	return (result);
}

size_t	get_real_len(t_list *varlist, char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (varlist)
	{
		result += ft_strlen(varlist->content.str);
		varlist = varlist->next;
	}
	while (str[i])
	{
		if (str[i] == '$')
		{
			i += get_varname_len(str + i);
		}
		result++;
		i++;
	}
	return (result);
}

char	*string_expansor(t_list *env, char *str)
{
	t_list	*vars;
	size_t	real_len;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars = get_varlist(env, str);
	real_len = get_real_len(env, str) + 1;
	result = ft_calloc(real_len, 1);
	if (errno == ENOMEM)
		return (ft_lstclear(&vars, free), free(result), NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			i += get_varname_len(str + i);
			j = ft_strlcat(result, vars->content.str, real_len);
			vars = vars->next;
			continue ;
		}
		result[j++] = str[i++];
	}
	return (result);
}
