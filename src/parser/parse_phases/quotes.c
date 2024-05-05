/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:19:08 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/04 18:55:08 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_quotelen(char *quote)
{
	int	clen;

	clen = 0;
	++clen;
	while (quote[clen] && quote[clen] != '\'')
		clen++;
	clen++;
	return (clen);
}
void copy_simple_quoute(char *rstr, char *str, int *i, int *j)
{
	int	tcounter;

	tcounter = get_quotelen(rstr);
	*i += tcounter;
	*j += tcounter;
	ft_strlcat(str, rstr, tcounter + 1);
}

