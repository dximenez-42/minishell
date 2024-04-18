/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:47:56 by bvelasco          #+#    #+#             */
/*   Updated: 2024/02/23 10:18:52 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_ptr_array(void *to_free)
{
	int		i;
	void	**to_free_d;

	to_free_d = (void **)to_free;
	i = 0;
	if (!to_free)
		return ;
	while (to_free_d[i])
	{
		free (to_free_d[i++]);
	}
	free (to_free);
}
