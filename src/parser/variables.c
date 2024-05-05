/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:09:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/05 14:15:36 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_varlen(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?')
		return (1);
	if (!ft_isalnum(str[i]))
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

char	*get_varname(char *str, int *i)
{
	int j;

	j = 0;
	while (ft_isalnum(str[j]))
		j++;	
	*i += j;
	return (ft_substr(str, 0, j));
}
