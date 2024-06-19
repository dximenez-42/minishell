/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:06 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 00:52:00 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*expand_token(t_list *env, t_token_type type, char *raw_value);

static t_token_type	identify_token_type(char *value)
{
	int	i;

	i = 0;
	if (!ft_isredir(value[i]))
		return (ARG);
	if (value[0] == '<')
	{
		if (value[1] && value[1] == '<')
			return (HD);
	}
	return (RD);
}

char	*expand_var(t_list *env, char *var)
{
	char	*result;
	char	*varname;

	varname = get_varname(var);
	if (!varname)
		return (NULL);
	result = get_env_var(env, varname);
	free(varname);
	return (result);
}

static size_t	create_token(t_list *env, char *start, size_t len,
		t_list **list)
{
	t_list	*node;
	t_token	*tok;
	char	*substr;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (1);
	substr = ft_substr(start, 0, len);
	if (!substr)
		return (free(tok), 1);
	tok->type = identify_token_type(substr);
	tok->value = expand_token(env, tok->type, substr);
	free(substr);
	if (!tok->value)
		return (free(tok), 1);
	node = ft_lstnew_type(OTHER, (t_content)(void *)tok);
	if (!node)
		return (free(tok->value), free(tok), 1);
	ft_lstadd_back(list, node);
	return (0);
}

/* Converts a "raw_command" in t_token list (use with ft_lstmap_env) */
t_content	create_token_list(t_list *env, t_content line)
{
	t_list	*toklist;
	int		i;
	int		toklen;

	i = 0;
	toklist = NULL;
	while (line.str[i])
	{
		if (!ft_isspace(line.str[i]))
		{
			toklen = get_rawtoken_len(line.str + i);
			create_token(env, line.str + i, toklen, &toklist);
			i += toklen;
			continue ;
		}
		i++;
	}
	return (((t_content)(void *) toklist));
}
