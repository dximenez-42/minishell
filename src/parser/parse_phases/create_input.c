/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:54 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/19 21:11:14 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_input	*create_input(t_list **env, t_list *tokenized_commands)
{
	t_input		*result;
	t_command	**commands;
	uint8_t		noc;
	uint8_t		i;

	i = 0;
	result = ft_calloc(sizeof(t_input), 1);
	noc = ft_lstsize(tokenized_commands);
	commands = ft_calloc(noc + 1, sizeof(void *));
	result->noc = noc;
	result->cmds = commands;
	while (i < noc)
	{
		commands[i] = create_command(*env, tokenized_commands->content.oth);
		if (!commands[i])
		{
			return (clear_input(result), NULL);
		}
		tokenized_commands = tokenized_commands->next;
		i++;
	}
	result->env = env;
	return (result);
}
