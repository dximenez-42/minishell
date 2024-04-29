/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:31:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/21 18:59:57 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_command_location(char *cmd, t_list *env)
{
	int		i;
	char	**env_split;
	char	**cmd_split;
	char	*location;

	i = 0;
	env_split = ft_split(get_env_var(env, "PATH"), ':');
	cmd_split = ft_split(cmd, ' ');
	while (env_split[i])
	{
		location = ft_strjoin(ft_strjoin(env_split[i], "/"), cmd_split[0]);
		if (access(location, F_OK | X_OK) == 0)
        {
            //TODO free splits (env_split & cmd_split)
			return (location);
        }
		++i;
	}
    //TODO free splits (env_split & cmd_split)
	return (cmd);
}
