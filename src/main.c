/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/12 18:32:38 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void proof(void)
{
	printf("hola\n");
}
int main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;

	env = parse_env(envp);
	rl_catch_signals = 0;
	print_env(env, 1);
	rawline = readline("mini$hell: ");
	while (rawline)
	{
		rl_signal_event_hook = proof;
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