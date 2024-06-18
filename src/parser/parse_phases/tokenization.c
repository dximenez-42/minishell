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
			i += get_unexpanded_quotelen(rawtoken + i);
			continue ;
		}
		else if (rawtoken[i] == '$')
		{
			varname = get_varname(rawtoken);
			len += get_env_var_len(env, varname);
			i += get_varname_len(rawtoken + i);
			free(varname);
			continue ;
		}
		i++;
		len++;
	}
	return (++len);
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

char	*expand_token(t_list *env, t_token_type type, char *raw_value)
{
	const size_t	real_size = get_real_token_size(env, raw_value);
	int				i;
	int				j;
	char			*result;
	char			*aux;

	i = 0;
	j = 0;
	if (type == HD)
		return (ft_strdup(raw_value));
	result = ft_calloc(real_size, 1);
	while (raw_value[i])
	{
		if (!ft_isquote(raw_value[i]) && raw_value[i] != '$')
		{
			result[j++] = raw_value[i++];
			continue ;
		}
		if (ft_isquote(raw_value[i]))
		{
			aux = expand_quote(env, raw_value + i);
			i += get_unexpanded_quotelen(raw_value + i);
		}
		else if (raw_value[i])
		{
			aux = expand_var(env, raw_value + i);
			i += get_varname_len(raw_value + i);
		}
		j = ft_strlcat(result, aux, real_size);
		free(aux);
	}
	return (result);
}

size_t create_token(t_list *env, char *start, size_t len,
		t_list **list)
{
	t_list	*node;
	t_token *tok;
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
};

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
