/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:32:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/15 17:03:09 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_rawtoken_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isredir(s[i]))
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != ' ')
	{
		if (s[i] == '"')
			i += get_unexpanded_quotelen(s + i);
		else if (s[i] == '\'')
			i += get_unexpanded_quotelen(s + i);
		else if (ft_isredir(s[i]))
			return (i);
		else
			i++;
	}
	return (i);
}

void	del_token(t_content content, t_type type)
{
	t_token	*token;

	(void)type;
	token = content.oth;
	free(token->value);
	free(token);
}
