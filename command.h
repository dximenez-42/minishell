/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:02:59 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 16:08:48 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "minishell.h"

typedef struct s_commmand
{
	char		**args;
	int			fds[3];
	__uint8_t	info;
}				t_command;

/*END OF COMMAND STRUCT AND FUNCTIONS*/
/*
 * NOC is the number of commands (command + arguments)
 * cmds are the commands itself (array)
 * env is the complete environment (check diagram for more information) 
 * info is the additional info:
 *  - 0 no additional info required
 *  - >0 additional info required, (there are an enum with the list of
 *  	general parse additional info)
 *  - <0 error in general parse, (there are an enum with the list of
 * 		general_parse errors)
 */
#endif