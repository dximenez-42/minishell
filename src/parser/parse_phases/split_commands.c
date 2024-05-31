/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:08:53 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 19:59:26 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	add_raw_command(t_list **clist, char *line, int cinit, int len)
{
	t_list	*node;

	node = ft_lstnew_type(STR, (t_content) ft_substr(line, cinit, len));
	if (!node)
		return (1);
	ft_lstadd_back(clist, node);
	return (0);
}

t_list	*split_commands(char *line)
{
	int		i;
	t_list	*raw_commands;
	int		ci;

	i = 0;
	raw_commands = NULL;
	ci = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			i += get_quotelen(line + i);
			continue ;
		}
		if (line [i] == '|')
		{
			add_raw_command(&raw_commands, line, ci, i - ci);
			ci = i + 1;
		}
		i++;
	}
	add_raw_command(&raw_commands, line, ci, i - ci);
	return (raw_commands);
}
