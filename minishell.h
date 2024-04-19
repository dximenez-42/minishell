/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 13:30:54 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <stdint.h>
# include "parser.h"

/*Common Structs*/

enum
{
	FDIN = 0,
	FDOUT = 1,
	FDERROR = 2
};

typedef struct s_commmand
{
	char	**args;
	int		fds[3];
}				t_command;

/*
 * NOC is the number of commands (command + arguments)
 * cmds are the commands itself (array)
 * env is the complete environment ({"name", "value"}, {"name", "value"})
 * info is the additional info:
 * 	-If >=0 is information or warnings, see the information list
 * 	-if <0 is an error. 
 */
typedef struct s_input
{
	__uint8_t	noc;
	t_command	*cmds;
	char		***env;
	__uint8_t	info;
}				t_input;
/*End of common structs*/

#endif
