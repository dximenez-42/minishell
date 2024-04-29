/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:15:42 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/29 22:19:41 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_error	error(t_error errnum)
{
	static t_error	current_error = 0;
	if (errnum = VIEW)
		return (current_error);
	current_error = errnum;
	return (errnum);
}