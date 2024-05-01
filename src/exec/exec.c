/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:51:48 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/01 14:50:21 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    exec_builtin()
{}

void	exec_one(t_command *cmd, t_list *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->info == 0)
			exec_builtin();
		else if (cmd->info > 0)
			execve(get_cmd(cmd->args[0], env), cmd->args, NULL);
	}
	waitpid(pid, &status, 0);
}

void	exec_multiple(t_command **cmd, t_list *env)
{
	
}
