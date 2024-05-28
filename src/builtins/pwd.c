/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:40:06 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/21 21:46:57 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_builtin(t_input *input, int i)
{
	char	cwd[512];

	if (getcwd(cwd, 512) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd() error");
}
