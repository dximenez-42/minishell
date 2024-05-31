/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:31:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/31 20:57:37 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_cmd(const t_command *cmd, t_input *input)
{
	int		i;
	char	**env_split;
	char	*location;
	char	*temp;

	i = 0;
	if (cmd->info == 1)
		return (cmd->args[0]);
	env_split = ft_split(get_env_var(input->env, "PATH"), ':');
	while (env_split[i])
	{
		temp = ft_strjoin(env_split[i], "/");
		location = ft_strjoin(temp, cmd->args[0]);
		free(temp);
		if (access(location, F_OK | X_OK) == 0)
		{
			ft_free_ptr_array(env_split);
			return (location);
		}
		free(location);
		++i;
	}
	ft_free_ptr_array(env_split);
	return (cmd->args[0]);
}
