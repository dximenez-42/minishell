/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:28:54 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/21 15:52:13 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// open redirs files in the most apropiate mode
static	int	open_redir(char *token)
{

}

// create t_command struct (open redirs files and create args)
static t_command	**create_commands(t_list *tokeniced_commands)
{
	t_command **commands;

	commands = malloc(ft_lstsize(tokeniced_commands));
	if (!commands)
		return (error(ERRMEM), NULL);
}

t_input	*create_input(t_list *tokenized_commands)
{
	t_command **commands;

	commands = create_commands(tokenized_commands);
}
