/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:58:11 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/12 17:24:28 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int get_quotelen(char *quote)
{
	int i;

	i = 0;
	i++;
	while (quote[i] && quote[i] != '\'')
		i++;
	return (++i);
}

int expand_quote(char *quote)
{
	return (0);
}