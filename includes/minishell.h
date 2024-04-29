/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/29 22:23:09 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
// system 
# include <sys/types.h>
# include <sys/wait.h>
# include <stdint.h>
# include <stdlib.h>
// external libraries
# include <readline/history.h>
# include <readline/readline.h>
# include <libft.h>
// project include files
# include "environment.h"
# include "command.h"
# include "input.h"
# include "parser.h"
# include "cleaners.h"

//FDS
enum
{
	FDIN = 0,
	FDOUT = 1,
	FDERROR = 2
};
//GENERAL ERRORS
typedef enum e_error
{
	VIEW = 0,
	NOT_IDENTIFIED = 1,
	ERRMEM = 2,
	ERRNFOUND = 3,
}			t_error;
//ERROR FUNCTIONS
t_error	error(t_error errnum);

void	exec_one(t_command *cmd, t_list *env);
void	exec_multiple(t_command **cmd, t_list *env);

char	*ft_joinpaths(char *p1, char *p2);

char	*get_command_location(char *cmd, t_list *env);

#endif
