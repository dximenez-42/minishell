/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:27:44 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 20:35:02 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cleaners.h"

static void	close_fds(t_command *cmd)
{
	if (cmd->fds[0] != 0 && cmd->fds[0] >= 0)
		close(cmd->fds[0]);
	if (cmd->fds[1] != 1 && cmd->fds[1] >= 0)
		close(cmd->fds[1]);
	if (cmd->fds[2] != 2 && cmd->fds[2] >= 0)
		close(cmd->fds[2]);
}

void	clear_input(t_input *input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	while (i < input->noc)
	{
		close_fds(input->cmds[i]);
		ft_free_ptr_array(input->cmds[i]->args);
		free(input->cmds[i]);
		i++;
	}
	free(input->cmds);
	free(input);
}

void	clear_env_list(t_content cnt, t_type type)
{
	const t_env_var	*var = cnt.oth;

	if (type != OTHER)
		return ;
	if (!var)
		return ;
	free(var->name);
	free(var->value);
	free((void *)var);
}
