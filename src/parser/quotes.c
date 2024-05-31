/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:58:11 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 21:10:20 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_isquote(int c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	get_quotelen(char *quote)
{
	int	i;

	i = 0;
	i++;
	while (quote[i] && quote[i] != '\'')
		i++;
	return (++i);
}

int	expand_quote(char *quote)
{
	(void) quote;
	return (0);
}
