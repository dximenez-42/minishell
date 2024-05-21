/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:37:10 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/1 13:14:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*parse_env(char **envp)
{
	int			i;
	char		*separator;
	t_list		*env;
	t_list		*node;	
	t_env_var	*env_var;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		separator = ft_strchr(envp[i], '=');
		env_var = malloc(1 * sizeof(t_env_var));
		if (!env_var)
			return (ft_lstclear_type(&env, clear_env_list), NULL);
		env_var->name = ft_substr(envp[i], 0, separator - envp[i]);
		env_var->value = ft_strdup(separator + 1);
		node = ft_lstnew_type(OTHER, (t_content)((void *)env_var));
		if (!node)
			return (free(env_var), ft_lstclear_type(&env, clear_env_list)
				, NULL);
		ft_lstadd_back(&env, node);
		i++;
	}
	return (env);
}
t_list	*split_raw_commands(char *line);
void	print_token_node(t_content content, t_type type)
{
	t_token *tok;
	
	tok = content.oth;
	printf("%i, %s\n", tok->type, tok->value);
}
void	print_token_list(t_content content, t_type type)
{
	t_list *ltok;

	ltok = content.oth;
	ft_lstiter_type(ltok, print_token_node);
}
t_input	*parse_line(t_list *env, char *line)
{
	t_input *result;
	char	*pproc_line;
	t_list	*buffer;
	t_list	*aux;

	buffer = split_commands(line);
	aux = ft_lstmap_type(buffer, OTHER, tokenize_command, NULL);
	int i = 0;
	while (aux)
	{
		printf("command %i\n", i);
		if ((!aux->content.ptr))
		{
			printf("error: %i\n", error(VIEW));
		}
		print_token_list(aux->content, aux->type);
		i++;
		aux = aux->next;
	}
	return (NULL);
}