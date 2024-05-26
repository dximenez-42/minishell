/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:27:44 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/29 22:28:30 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cleaners.h"

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
