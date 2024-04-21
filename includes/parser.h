/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:53:25 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/19 16:54:16 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

t_list	*parse_env(char **envp);

#endif