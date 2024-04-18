/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:26:55 by bvelasco          #+#    #+#             */
/*   Updated: 2024/03/24 21:29:37 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	count_zeros(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
	{
		i++;
	}
	return (i);
}

// noz is number of spaces and left-sited zeros in string
static int	check_overflow(char *str)
{
	const char		*limits[2] = {ft_itoa(INT_MAX), ft_itoa(INT_MIN)};
	int				is_ok;
	const int		noz = count_zeros(str);

	is_ok = 1;
	if (ft_strlen(limits[0]) == 0 || ft_strlen(limits[1]) == 0)
		is_ok = 0;
	if (str[0] == '-')
	{
		if (ft_strlen(str + noz) > ft_strlen(limits[1]))
			is_ok = 0;
		if (ft_strlen(str + noz) == ft_strlen(limits[1]))
		{
			if (ft_strncmp(limits[1], str + noz, ft_strlen(str)) < 0)
				is_ok = 0;
		}
	}
	else if (ft_strlen(str + noz) > ft_strlen(limits[0]))
		is_ok = 0;
	else if (ft_strlen(str) == ft_strlen(limits[0]))
		if (ft_strncmp(limits[0], str + noz, ft_strlen(limits[0])) < 0)
			is_ok = 0;
	free((void *)limits[0]);
	free((void *)limits[1]);
	return (is_ok);
}

int	ft_isinteger(char *str)
{
	if (ft_isnumber(str, 1) && check_overflow(str))
		return (1);
	else
		return (0);
}
