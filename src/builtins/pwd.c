/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:40:06 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/23 18:11:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_builtin(t_input *input, int i)
{
	char	*cwd;

	(void) input;
	(void) i;
	cwd = get_cwd();
	if (cwd != NULL)
		printf("%s\n", cwd);
	else
	{
		perror("getcwd error");
		return (1 << 8);
	}
	return (0);
}
