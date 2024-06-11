/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:58:11 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/11 13:57:32 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_isquote(int c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

size_t	get_quotelen(t_list *env, char *raw_quote)
{
	size_t	len;
	size_t	i;
	char	*varname;

	i = 0;
	len = 0;
	if (raw_quote[i++] == '\'')
		return (get_unexpanded_quotelen(raw_quote) - 2);
	while (raw_quote[i] && raw_quote[i] != '"')
	{
		if (raw_quote[i] == '$')
		{
			varname = get_varname(raw_quote + i);
			if (!varname)
				return (0);
			len += get_env_var_len(env, varname);
			i += ft_strlen(varname) + 1;
			free(varname);
		}
		i++;
		len++;
	}
	return (len);
}

int	get_unexpanded_quotelen(char *quote)
{
	int	i;

	i = 0;
	if (quote[i] == '\'')
	{
		i++;
		while (quote[i] && quote[i] != '\'')
			i++;
	}
	else if (quote[i] == '"')
	{
		i++;
		while (quote[i] && quote[i] != '"')
			i++;
	}
	return (++i);
}

char	*expand_simple_quote(char *quote)
{
	return (NULL);
}

char	*expand_quote(t_list *env, char *quote)
{
	int	i;
	char	result;

	i = 0;
	if (quote[i] == '\'')
		return (expand_simple_quote);
	return (0);
}
