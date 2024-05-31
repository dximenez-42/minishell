/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:26:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/31 18:59:31 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	go_home(t_input *input)
{
	char	cwd[512];
	char	*home;

	if (getcwd(cwd, 512) == NULL)
		return (perror("getcwd() error"));
	home = get_env_var(input->env, "HOME");
	if (home == NULL)
		return (perror("HOME not set"));
	if (chdir(home) == -1)
		return (perror(""));
	set_env_var(&input->env, "OLDPWD", cwd);
	if (getcwd(cwd, 512) == NULL)
		return (perror("getcwd() error"));
	set_env_var(&input->env, "PWD", cwd);
}

void	go_old(t_input *input)
{
	char	cwd[512];
	char	*old;

	old = get_env_var(input->env, "OLDPWD");
	if (old == NULL)
		return (perror("OLDPWD not set"));
	if (chdir(old) == -1)
		return (perror(""));
	set_env_var(&input->env, "OLDPWD", get_env_var(input->env, "PWD"));
	if (getcwd(cwd, 512) == NULL)
		return (perror("getcwd() error"));
	set_env_var(&input->env, "PWD", cwd);
}

void	cd_builtin(t_input *input, int i)
{
	char	cwd[512];

	if (input->cmds[i]->args[1] == NULL)
		go_home(input);
	else if (ft_strncmp(input->cmds[i]->args[1], "-", 1) == 0)
		go_old(input);
	else
	{
		if (getcwd(cwd, 512) == NULL)
			return (perror("getcwd() error"));
		if (chdir(input->cmds[i]->args[1]) == -1)
			return (perror(""));
		set_env_var(&input->env, "OLDPWD", cwd);
		if (getcwd(cwd, 512) == NULL)
			return (perror("getcwd() error"));
		set_env_var(&input->env, "PWD", cwd);
	}
}
