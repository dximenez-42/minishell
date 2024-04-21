/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/21 12:32:45 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <stdint.h>
# include "parser.h"
# include "environment.h"
# include "command.h"
# include "input.h"
# include <readline/readline.h>
# include <readline/history.h>

//FDS
enum
{
	FDIN = 0,
	FDOUT = 1,
	FDERROR = 2
};


void	exec_one(t_command *cmd, t_list *env);
void	exec_multiple(t_command **cmd, t_list *env);

void	cd_builtin(t_command *cmd, t_list *env);

// Utils
char	*ft_joinpaths(char *p1, char *p2);

#endif
