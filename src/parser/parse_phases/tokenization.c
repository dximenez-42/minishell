/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:06 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/06 19:25:52by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token_type	identify_token_type(char *value)
{
	int	i;

	i = 0;
	if (!ft_isredir(value[i]))
		return (ARG);
	if (value[0] == '<')
	{
		if (value[1] && value[1] == '<')
			return(HD);
	}
	return(RD);
}

size_t	get_real_token_size(t_list *env, char *rawtoken)
{
	size_t	i;
	size_t	len;
	char	*varname;

	i = 0;
	len = 0;
	while (rawtoken[i])
	{
		if (ft_isquote(rawtoken[i]))
		{
			len += get_quotelen(env, rawtoken + i);
//			i += qet_unexpanded_quotelen(env, rawtoken + i);
		}
		else if (rawtoken[i] == '$')
		{
			varname = get_varname(rawtoken);
			len += get_env_var_len(env, varname);
			i += get_varname_len(rawtoken + i);
		}
		i++;
		len++;
	}
	return (len);
}

char	*expand_token(t_list *env, t_token_type type, char *raw_value)
{
	printf("%li\n", get_real_token_size(env, raw_value));
}

t_token	*create_token(t_list *env, char *rawstr, size_t start, size_t len,
		t_list **list)
{
	t_list	*node;
	t_token *tok;
	char	*substr;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (1);
	substr = ft_substr(rawstr, start, len);
	if (!substr)
		return (free(tok), 1);
	tok->type = identify_token_type(substr);
	tok->value = expand_token(env, tok->type, substr);
	free(substr);
	if (tok->value)
		return (free(tok), 1);
	node = ft_lstnew_type(OTHER, (t_content)(void *)tok);
	if (!node)
		return (free(tok->value), free(tok), 1);
	ft_lstadd_back(list, node);
	return (0);
};

/* Converts a "raw_command" in t_token list (use with ft_lstmap_env) */
t_content	create_token_list(t_list *env, t_content line)
{
	char	*str;
	t_token	*tok;
	t_list	*toklist;
	int		i;
	size_t	tok_info[2];
	
	i = 0;
	tok_info[0] = 0;
	str = line.str;
	toklist = NULL;
	while (str[i])
	{
		if (tok_info[0] == 0 && !ft_isspace(str[i]))
		{
			tok_info[0] = 1;
			tok_info[1] = i;
		}
		else if (tok_info[0] == 1 && ft_isspace(str[i]))	
		{
			tok_info[0] = 0;
			create_token(env, str, tok_info[1], i - tok_info[1], &toklist);
		}
		i++;
	}
	if (tok_info[0] == 1)
		create_token(env, str, tok_info[1], i - tok_info[1], &toklist);
	return (((t_content)(void *) toklist));
}
