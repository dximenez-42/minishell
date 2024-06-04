/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:26:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/02 15:58:21 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	go_home(t_input *input)
{
	char	cwd[PATH_MAX];
	char	*home;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (perror("getcwd() error"), 1);
	home = get_env_var(input->env, "HOME");
	if (home == NULL)
		return (perror("HOME not set"), 1);
	if (chdir(home) == -1)
		return (perror(home), 1);
	set_env_var(&input->env, "OLDPWD", cwd);
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (perror("getcwd() error"), 1);
	set_env_var(&input->env, "PWD", cwd);
	return (0);
}

int	go_old(t_input *input)
{
	char	cwd[PATH_MAX];
	char	*old;

	old = get_env_var(input->env, "OLDPWD");
	if (old == NULL)
		return (perror("OLDPWD not set"), 1);
	if (chdir(old) == -1)
		return (perror(old), 1);
	set_env_var(&input->env, "OLDPWD", get_env_var(input->env, "PWD"));
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (perror("getcwd() error"), 1);
	set_env_var(&input->env, "PWD", cwd);
	return (0);
}

int	cd_builtin(t_input *input, int i)
{
	char	cwd[PATH_MAX];

	if (input->cmds[i]->args[1] == NULL)
		return (go_home(input));
	else if (ft_strncmp(input->cmds[i]->args[1], "-", 2) == 0)
		return (go_old(input));
	else
	{
		if (getcwd(cwd, PATH_MAX) == NULL)
			return (perror("getcwd() error"), 1);
		if (chdir(input->cmds[i]->args[1]) == -1)
			return (perror(input->cmds[i]->args[1]), 1);
		set_env_var(&input->env, "OLDPWD", cwd);
		if (getcwd(cwd, PATH_MAX) == NULL)
			return (perror("getcwd() error"), 1);
		set_env_var(&input->env, "PWD", cwd);
	}
	return (0);
}
