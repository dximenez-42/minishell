/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_to_intarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:46 by bvelasco          #+#    #+#             */
/*   Updated: 2024/02/26 18:56:32 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	*strarr_to_intarr(char **sarr)
{
	int		*result;
	size_t	size;
	size_t	i;

	if (!sarr || !(*sarr))
		return (NULL);
	size = strarr_len(sarr);
	result = malloc((size + 1) * sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	result[0] = (int) size;
	while (i < size)
	{
		if (ft_isinteger(sarr[i]))
			result[i + 1] = ft_atoi(sarr[i]);
		else
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
