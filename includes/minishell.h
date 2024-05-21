/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/21 15:23:45 by bvelasco         ###   ########.fr       */
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
	VIEW = 1,
	NOT_IDENTIFIED = 2,
	ERRMEM = 3,
	ERRNFOUND = 4,
	ERRFORMAT = 5,
	ERROEMPTY = 6
}			t_error;
// error fuctions
t_error	error(t_error errnum);
// end of error functions
void	exec_one(t_command *cmd, t_list *env);
void	exec_multiple(t_command **cmd, t_list *env);
char	*ft_joinpaths(char *p1, char *p2);
char	*get_command_location(char *cmd, t_list *env);
#endif
