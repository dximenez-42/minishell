/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:54 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/25 19:55:36 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_input	*create_input(t_list *env, t_list *tokenized_commands)
{
	t_input		*result;
	t_command	**commands;
	t_list		*original;
	uint8_t		noc;
	uint8_t		i;

	i = 0;
	result = malloc(sizeof(t_input));
	noc = ft_lstsize(tokenized_commands);
	commands = malloc(noc * sizeof(void *));
	original = tokenized_commands;
	while (i < noc)
	{
		commands[i] = create_command(tokenized_commands->content.oth);
		tokenized_commands = tokenized_commands->next;
		i++;
	}
	result->noc = noc;
	result->cmds = commands;
	result->env = env;
	return (result);
}
