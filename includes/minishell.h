/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:24 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/11 18:08:43 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <stdint.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
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

void	exec_one(t_input *input, t_list *env);
void	exec_multiple(t_input *input, t_list *env);

void	redirs(t_input *input, int i, int **pipes);
void	init_pipes(t_input *input, int ***pipes);

char	*ft_joinpaths(char *p1, char *p2);

char	*get_cmd(char *cmd, t_list *env);

#endif
