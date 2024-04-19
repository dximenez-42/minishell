/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:01:58 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 16:09:33 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "minishell.h"
/*ENV STRUCT AND FUNCTIONS*/
typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

/*
 * Get an env variable, if not found return NULL pointer
 */
char	*get_env_var(t_list *lst, char *name);
/*
 * Add Environment variable
 * if Envirnoment variable already  exist modify their value
 * If not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. MEMERROR
 * 3. SYSERROR
 */
int		set_env_var(t_list **lst, char *name, char *value);
/*
 * Remove Environment variable
 * if not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. NOT_FOUND
 * 3. THERE AREN'T ENVIRONMENT
 */
int		rem_env_var(t_list **lst, char *name);
/*
* Print the environment
*/
int		print_env(t_list *lst);
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

#endif