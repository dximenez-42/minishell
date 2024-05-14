/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:06 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/14 18:10:22by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*proc_arg_token(char *first_char, int *pos)
{

}
static char	*proc_var_token(char *first_char, int *pos)
{

}

static char *proc_redir_token(char *first_char, int *pos)
{

}


static int	process_token(t_list **tok_list, char *first_char, int *pos)
{
	int		i;
	char	*buffer;
	t_list	*node;
	t_token *tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (error(ERRMEM), 1);
	tok->type = ARG;
	if (first_char == '$')
	{
		buffer = proc_var_token(first_char, pos);
		tok->type = VAR;
	}
	else if (ft_isredir(first_char))
	{
		buffer = proc_redir_token(first_char, pos);
		tok->type = RD;
	}
	else
		buffer = proc_arg_token(first_char, pos);
	if (!buffer)
		return (free(tok), error(ERRMEM), 1);
	tok->value = buffer;
	return (0);
}

t_content	tokenize_command(t_type type, t_content content)
{ 
	int		i;
	t_list	*tok_list;
	t_list	*node;
	t_token	*token;
	char	*raw_cmd;

	i = 0;	
	tok_list = NULL;
	raw_cmd = content.str;
	while (raw_cmd[i])
	{
		if (!ft_isspace(raw_cmd[i]))
			if (process_token(&tok_list, raw_cmd + i, &i))
				return ((t_content) NULL);
	}
}