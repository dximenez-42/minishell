/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borja <borja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:45:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/01/21 16:42:53 by borja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s1 || !n)
		return (0);
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return (0);
}
