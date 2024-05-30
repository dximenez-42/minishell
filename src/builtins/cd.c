/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:26:57 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/30 13:54:13 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	go_home(t_input *input)
{
	char	cwd[512];
	char	*home;

	if (getcwd(cwd, 512) == NULL)
		return (perror("getcwd() error"));
	set_env_var(&input->env, "OLDPWD", cwd);
	home = get_env_var(input->env, "HOME");
	if (home == NULL)
		return (perror("HOME not set"));
	chdir(home);
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
	set_env_var(&input->env, "OLDPWD", get_env_var(input->env, "PWD"));
	chdir(old);
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
		set_env_var(&input->env, "OLDPWD", cwd);
		chdir(input->cmds[i]->args[1]);
		if (getcwd(cwd, 512) == NULL)
			return (perror("getcwd() error"));
		set_env_var(&input->env, "PWD", cwd);
	}
}
