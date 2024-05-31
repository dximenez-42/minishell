/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:02:59 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 12:33:45 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "minishell.h"

/*
 * ARGS are the arguments of the command including the command itself (args[0])
 * FDS are the file descriptor of in, out and error of that command
 * info is an integer that give additional info:
 *  - 0 no additional info required (built_in)
 *  - >0 additional info required:
 *  	1. PROGRAM_RELATIVE_ROUTE OR PROGRAM_ABSOLUTE_ROUTE
 *  	2. PROGRAM_IN_PATH
 * 
 *  - <0 error in procces this command, (there are an enum with the list of
 *  	command parse erros):
 *  	-1. MISSINGNO (UNKNOWN ERROR)
 */
typedef struct s_commmand
{
	int			argc;
	char		**args;
	int			fds[3];
	__int8_t	info;
}				t_command;

#endif