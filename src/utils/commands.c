/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:31:36 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/18 22:13:47 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_cmd(const t_command *cmd, t_input *input)
{
	int		i;
	char	**env_split;
	char	*location;
	char	*temp;
	char	*env_var;

	i = 0;
	if (cmd->info == 2)
		return (cmd->args[0]);
	env_var = get_env_var(input->env, "PATH");
	if (env_var == NULL)
		return (cmd->args[0]);
	env_split = ft_split(env_var, ':');
	free(env_var);
	while (env_split[i])
	{
		temp = ft_strjoin(env_split[i], "/");
		location = ft_strjoin(temp, cmd->args[0]);
		free(temp);
		if (access(location, F_OK | X_OK) == 0)
			return (ft_free_ptr_array(env_split), location);
		free(location);
		++i;
	}
	return (ft_free_ptr_array(env_split), cmd->args[0]);
}
