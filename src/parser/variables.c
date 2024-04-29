/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:09:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/29 22:41:06by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_varname(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (str[i++] != '$')
		return (0);
	while (str[i] && !ft_isspace(str[i]))
		i++;
	result = ft_substr(str, 1, i - 1);
	if (!result)
		return (error(ERRMEM), NULL);
	return (result);
}