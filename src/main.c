/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:21 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 19:53:05 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//for debug pruporses
// static void	print_input(t_input *input)
// {
// 	int i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	printf("PROCESED INPUT:\n");
// 	printf("COMMANDS: %d\n", input->noc);
// 	while (i < input->noc)
// 	{
// 		j = 0;
// 		k = 0;
// 		printf("Command %i: \n", i);
// 		while (input->cmds[i]->args[j] != NULL)
// 			printf(" %s\n", input->cmds[i]->args[j++]);
// 		while (k < 3)
// 			printf(" %i", input->cmds[i]->fds[k++]);
// 		printf("\n");
// 		i++;
// 	}
// }
static void	close_fds(t_command *cmd)
{
	if (cmd->fds[0] != 0 && cmd->fds[0] >= 0)
		close(cmd->fds[0]);
	if (cmd->fds[1] != 1 && cmd->fds[1] >= 0)
		close(cmd->fds[1]);
	if (cmd->fds[2] != 2 && cmd->fds[2] >= 0)
		close(cmd->fds[2]);
}
static void	clear_input(t_input *input)
{
	int i;

	i = 0;
	while (i < input->noc)
	{
		close_fds(input->cmds[i]);
		ft_free_ptr_array(input->cmds[i]->args);
		free(input->cmds[i]);
		i++;
	}
	free(input->cmds);
	free(input);
}

int is_empty_line(char *line)
{
	while (*line)	
	{
		if (!ft_isspace(*line))
			return(1);
		line++;
	}
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	t_list	*env;
	t_input	*input;
	char	*rawline;

	(void) argc;
	(void) argv;
	env = parse_env(envp);
	rawline = readline("minishell: ");
	while (rawline)
	{
		//ft_printf("%s\n", string_expansor(env, rawline));
		
		if (rawline[0] != 0)
		{
			add_history(rawline);
			if (is_empty_line(rawline))
			{
				input = parse_line(env, rawline);
				// print_input(input);
				if (input->noc == 1)
					exec_one(input);
				else
					exec_multiple(input);
				clear_input(input);
			}
		}
		free(rawline);
		rawline = readline("minishell: ");
	}
	ft_lstclear_type(&env, clear_env_list);
	return (0);
}