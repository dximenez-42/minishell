/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 15:59:19 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <stdint.h>
# include "parser.h"

/*Common Structs*/

//FDS
enum
{
	FDIN = 0,
	FDOUT = 1,
	FDERROR = 2
};

/*ENV STRUCT AND FUNCTIONS*/
typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

/*
 * Get an env variable, if not found return NULL pointer
 */
char *get_env_var(t_list *lst, char *name); 
/*
 * Add Environment variable
 * if Envirnoment variable already  exist modify their value
 * If not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. MEMERROR
 * 3. SYSERROR
 */
int	set_env_var(t_list **lst, char *name, char *value);
/*
 * Remove Environment variable
 * if not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. NOT_FOUND
 * 3. THERE AREN'T ENVIRONMENT
 */
int rem_env_var(t_list **lst, char *name);
/*
* Print the environment
*/
int print_env(t_list *lst);
/*END OF ENV STRUCT AND FUNCTIONS*/
/* COMMAND STRUCT AND FUNCTIONS*/
/*
 * ARGS are the arguments of the command including the command itself (args[0])
 * FDS are the file descriptor of in, out and error of that command
 * info is an integer that give additional info:
 *  - 0 no additional info required (built_in)
 *  - >0 additional info required:
 *  	1. PROGRAM_IN_PATH
 *  	2. PROGRAM_RELATIVE_ROUTE
 *  	3. PROGRAM_ABSOLUTE_ROUTE
 * 
 *  - <0 error in procces this command, (there are an enum with the list of
 *  	command parse erros):
 *  	-1. MISSINGNO (UNKNOWN ERROR)
 */
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
typedef struct s_input
{
	__uint8_t	noc;
	t_command	*cmds;
	t_list		*env;
	__uint8_t	info;
}				t_input;
/*End of common structs*/

#endif
