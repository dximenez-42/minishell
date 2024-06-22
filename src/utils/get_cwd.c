/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:30:29 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/22 22:42:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/**
 * @brief Get the current working directory
 * @param cwd The destination string
 * @return 1 if success, 0 if error
 */
char	*get_cwd(void)
{
	static char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		if (cwd != NULL)
			return (cwd);
		return (NULL);
	}
	return (cwd);
}
