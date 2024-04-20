/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:26:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/19 22:19:50 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cd_builtin(t_command *cmd, t_list *env)
{
	char	*path;
	char	*old;

	old = get_env_var(env, "PWD");
	if (cmd->args[1] == NULL)
		path = get_env_var(env, "PATH");
	else if (cmd->args[1] == "-")
		path = get_env_var(env, "OLDPWD");
	else
		path = ft_joinpaths(get_env_var(env, "PWD"), cmd->args[1]);
	set_env_var(&env, "OLDPWD", old);
	set_env_var(&env, "PWD", path);
}
