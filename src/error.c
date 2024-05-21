/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:15:42 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/21 13:00:24 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_error	error(t_error errnum)
{
	static t_error	current_error = 0;
	t_error			result;

	if (errnum == VIEW)
	{
		result = current_error;
		current_error = 0;
		return (result);
	}
	result = current_error;
	current_error = errnum;
	return (result);
}
