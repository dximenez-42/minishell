/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_qtmark.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:07:40 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 19:12:21 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_qtmark(t_list **env, int status)
{
	char	*value;

	value = ft_itoa(status % 256);
	set_env_var(env, "?", value);
	free(value);
}
