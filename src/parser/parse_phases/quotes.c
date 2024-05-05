/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:19:08 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/05 19:57:34 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	get total len of quotes (not expanded)
*/
int	get_quotelen(char *quote, t_list *varlist)
{
	int	i;

	i = 0;
	if (*quote == '"')
		while (quote[++i] && quote[i] != '"');
	else if (*quote == '\'')
		while (quote[++i] && quote[i] != '\'');
	if (quote[i] == '\'' || quote[i] == '\"')
		i++;
	return (i);
}
void	copy_simple_quoute(char *rstr, char *str, int *rc, int *pc)
{
	int	limit;
	int	i;

	i = 0;
	limit = get_quotelen(rstr + *rc, NULL);
	while (i <= limit)
	{
		*(str + *pc + i) = *(rstr + *rc + i);
		i++;
	}
	*rc += i;
	*pc += i;
}

void	proc_quotes(char *rstr, char *str, int *counters[])
{
	int	i;
	int	j;

	if (rstr[j]);
}