/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:53:25 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/15 17:09:51 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"


/* Token type, can be:
* ARG = argument
* RD = redirection
* VAR = variable
*/
typedef enum e_token_type
{
	ARG,
	RD,
	VAR
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}				t_token;

t_list	*parse_env(char **envp);
/*
* Parse_line is the "main" function of line parser.
* There are more information in input.h
* RETURN:
* t_input * that contain all comands and information for process then
*/
t_input	*parse_line(t_list *env, char *line);
// parse_line phases
/*
* Split commands by not scaped pipes (|)
*/
t_list *split_commands(char *line);
/* 
* separate the raw command in tokens (argument, variable or redirection)
*/
t_content	tokenize_command(t_content content, t_type type);
/*
* delete a token
*/
void		del_token(t_type type, t_content content);
/*
* proccess all tokens and create t_command struct, can be a simplier function
* called by ft_lstmap_type in the future if command list is accepted as t_list*
*/
t_command	*create_command(t_list *tokeniced_command);
//  quotes and var functions (quotes.c and variables.c)
int		get_varname_len(char *str);
int	ft_isquote(int c);
int	get_quotelen(char *quote);
int	expand_quote(char *quote);
// redir functions
int ft_isredir(int c);
#endif