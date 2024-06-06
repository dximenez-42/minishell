/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:09:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/06 19:13:48 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_varname_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '$')
		return (0);
	i++;
	if (str[i] == '?')
		return (1);
	if (!ft_isalnum(str[i]))
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

char	*get_varname(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '$')
		return (NULL);
	i++;
	while (ft_isalnum(str[i]))
		i++;
	return (ft_substr(str, 1, i - 1));
}
