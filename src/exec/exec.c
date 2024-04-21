/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/04/21 18:51:24 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    exec_builtin()
{}

void	exec_one(t_command *cmd, t_list *env)
{
	pid_t	pid;
	int		status;

	if (cmd->info == 0)
	{
		exec_builtin();
	}
	else if (cmd->info > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(get_command_location(cmd->args[0], env), cmd->args, NULL);		//TODO en vez de NULL poner ft_getenv (cuando funcione)
		}
		waitpid(pid, &status, 0);
	}
}

void	exec_multiple(t_command **cmd, t_list *env)
{
	
}
