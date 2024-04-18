/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:08:34 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/20 22:39:26 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memdup(const void *mem, size_t len)
{
	void	*rtn;

	rtn = malloc(len);
	if (!rtn)
		return (0);
	ft_memcpy(rtn, mem, len);
	return (rtn);
}
