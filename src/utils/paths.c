/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:27:51 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/21 18:59:15 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_joinpaths(char *p1, char *p2)
{
	int		i;
	int		j;
	char	*ret;
	
	i = 0;
	j = 0;
	ret = malloc((ft_strlen(p1) + ft_strlen(p2) + 2) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (p1[j] != '\0')
		ret[i++] = p1[j++];
	ret[i++] = '/';
	j = 0;
	while (p2[j] != '\0')
		ret[i++] = p2[j++];
	ret[i] = '\0';
	return (ret);
}

// char	*ft_reversepath(char *path, int times)
// {
// 	int	i;

// 	i = ft_strlen(path);
// 	while (i > 0 && times > 0)
// 	{
// 		if (path[i] == '/')
// 		--i;
// 	}
// }
