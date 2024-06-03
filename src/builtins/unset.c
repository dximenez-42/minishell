/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:04:56 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/01 13:41:15 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset_builtin(t_input *input, int i)
{
	rem_env_var(&input->env, input->cmds[i]->args[1]);
	return (0);
}
