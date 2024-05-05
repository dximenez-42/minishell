/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:19:08 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/05 15:16:29 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_quotelen(char *quote)
{
	int	clen;

	clen = 0;
	while (quote[++clen] && quote[clen] != '\'');
	if (quote[clen] == '\'')
		clen++;
	return (clen);
}
void copy_simple_quoute(char *rstr, char *str, int *rc, int *pc)
{
	int	limit;
	int	i;

	i = 0;
	limit = get_quotelen(rstr + *rc);
	while (i <= limit)
	{
		*(str + *pc + i) = *(rstr + *rc + i);
		i++;
	}
	*rc += i;
	*pc += i;
}

