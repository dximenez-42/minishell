/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/20 14:45:58 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_input *input;
	t_list	*env;
	char	*line;
	char 	**envc;

	env = parse_env(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (line != NULL && line[0] != '\0')
		{
			add_history(line);
			// parse();
			// exec();
		}
	}
	return (0);
}
