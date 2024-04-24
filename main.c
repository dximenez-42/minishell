/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:29:48 by bvelasco          #+#    #+#             */
/*   Updated: 2024/04/24 15:05:25 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_input *input;
	t_list	*env;
	char	*line;
	char 	**envc;

	env = parse_env(envp);
	set_env_var(&env, "hola", "adios");
	envc = ft_getenv(env);
	set_env_var(&env, "hola", "mundo");
	ft_lstclear_type(&env, clear_env_list);
	ft_free_ptr_array(envc);
	return (0);
}
