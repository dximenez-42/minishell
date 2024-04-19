/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:09:44 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 16:09:45 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "minishell.h"

typedef struct s_input
{
	__uint8_t	noc;
	t_command	*cmds;
	t_list		*env;
	__uint8_t	info;
}				t_input;
#endif