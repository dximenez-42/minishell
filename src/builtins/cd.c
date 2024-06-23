/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:26:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/23 18:11:03 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	go_home(t_input *input)
{
	char	*cwd;
	char	*home;

	cwd = get_cwd();
	home = get_env_var(*input->env, "HOME");
	if (home == NULL)
		return (perror("HOME not set"), 1);
	if (chdir(home) == -1)
		return (perror(home), 1);
	set_env_var(input->env, "OLDPWD", cwd);
	cwd = get_cwd();
	if (cwd == NULL)
		return (perror("getcwd() error"), 1);
	set_env_var(input->env, "PWD", cwd);
	free(home);
	return (0);
}

int	go_old(t_input *input)
{
	char	*cwd;
	char	*old;
	char	*pwd;

	old = get_env_var(*input->env, "OLDPWD");
	if (old == NULL)
		return (perror("OLDPWD not set"), 1);
	if (chdir(old) == -1)
		return (perror(old), free(old), 1);
	free(old);
	pwd = get_env_var(*input->env, "PWD");
	set_env_var(input->env, "OLDPWD", pwd);
	free(pwd);
	cwd = get_cwd();
	if (cwd == NULL)
		return (perror("getcwd() error"), 1);
	set_env_var(input->env, "PWD", cwd);
	pwd_builtin(input, 0);
	return (0);
}

int	cd_builtin(t_input *input, int i)
{
	char	*cwd;

	if (input->cmds[i]->args[1] == NULL)
		return (go_home(input) << 8);
	else if (ft_strncmp(input->cmds[i]->args[1], "-", 2) == 0)
		return (go_old(input) << 8);
	else
	{
		cwd = get_cwd();
		if (cwd == NULL)
			return (perror("getcwd() error"), 1 << 8);
		if (chdir(input->cmds[i]->args[1]) == -1)
			return (perror(input->cmds[i]->args[1]), 1 << 8);
		set_env_var(input->env, "OLDPWD", cwd);
		cwd = get_cwd();
		if (cwd == NULL)
			return (perror("getcwd() error"), 1 << 8);
		set_env_var(input->env, "PWD", cwd);
	}
	get_cwd();
	return (0);
}
