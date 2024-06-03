/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:02:59 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/02 15:40:56 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "minishell.h"

/*
 * ARGS are the arguments of the command including the command itself (args[0])
 * FDS are the file descriptor of in, out and error of that command
 * info is an integer that give additional info:
 *  - 0 regular built_in
 *  - 1 no redirections built_in
 *  - >=2 additional info required:
 *  	2. PROGRAM_RELATIVE_ROUTE OR PROGRAM_ABSOLUTE_ROUTE
 *  	3. PROGRAM_IN_PATH
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