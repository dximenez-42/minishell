/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/13 23:08:29 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;

	env = parse_env(envp);
	rawline = readline("mini$hell: ");
	while (rawline)
	{
		add_history(rawline);
		input = parse_line(env, rawline);
		//executer(input);
		free(input);
		free(rawline);
		rawline = readline("mini$hell: ");
	}
	ft_lstclear_type(&env, clear_env_list);
	return (0);
}