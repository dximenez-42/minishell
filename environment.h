/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:01:58 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 19:15:42 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "minishell.h"

enum
{
	MISSINGNO = 1,
	MEMERROR = 2,
	SYSERROR = 3,
	NOT_FOUND = 4
};

typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

/*
 * Get an env variable, if not found return NULL pointer
 */
char	*get_env_var(t_list *env, char *name);
/*
 * Add Environment variable
 * if Envirnoment variable already  exist modify their value
 * If not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. MEMERROR
 * 3. SYSERROR
 */
int		set_env_var(t_list **env, char *name, char *value);
/*
 * Remove Environment variable
 * if not fail returns 0
 * in other case, returns an errcode
 * 1. MISSINGNO
 * 2. NOT_FOUND
 * 3. THERE AREN'T ENVIRONMENT
 */
int		rem_env_var(t_list **env, char *name);
/*
 * Get the environment with the same format of getenv 
*/
char	**ft_getenv(t_list *env);
/*
 * Print the environment
*/
int		print_env(t_list *env, int fd);

#endif