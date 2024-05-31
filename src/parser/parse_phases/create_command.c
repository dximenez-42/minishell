/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:44:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/31 12:35:44 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	tokeniced_to_args(t_list *token_list, char ***args)
{
	int			noa;
	int			i;
	t_token		*tok;
	char		**result;

	i = 0;
	noa = ft_lstsize(token_list);
	if (noa == 0)
		return (*args = NULL, 0);
	result = malloc((noa + 1) * sizeof(void *));
	result[noa] = NULL;
	while (i < noa)
	{
		tok = token_list->content.oth;
		result[i] = ft_strdup(tok->value);
		token_list = token_list->next;
		i++;
	}
	*args = result;
	return (noa);
}

int	identify_redir_type(char *redir)
{
	if (*redir == '<')
	{
		if (*(++redir) == '<')
			return (0);
		return (1);
	}
	if (*redir == '>')
	{
		if (*(++redir) == '>')
			return (2);
		return (3);
	}
	return (-1);
}

void	open_redirs(t_command *command, t_list *token_list)
{
	t_token	*tok;
	int		redir_type;
	int		i;

	while (token_list)
	{
		i = 0;
		tok = token_list->content.oth;
		redir_type = identify_redir_type(tok->value);
		while (tok->value[i] && ft_isredir(tok->value[i]))
			i++;
		while (tok->value[i] && ft_isspace(tok->value[i]))
			i++;
		if (redir_type == 0)
			printf("<< Not implemented\n");
		else if (redir_type == 1)
			command->fds[0] = open(tok->value + i, O_RDONLY);
		else if (redir_type == 2)
			command->fds[1] = open(tok->value + i, O_CREAT | O_RDWR
					| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		else if (redir_type == 3)
			command->fds[1] = open(tok->value + i, O_CREAT | O_RDWR | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		token_list = token_list->next;
	}
}

static __int8_t	get_type(char **args)
{
	int			i;
	const char	*builtins[] = {"echo", "cd", "pwd", "export", "unset",
		"env", "exit", NULL};

	i = 0;
	if (args == NULL)
		return (-1);
	while (builtins[i])
	{
		if (!ft_strncmp(args[0], builtins[i], ft_strlen(builtins[i]) + 1))
			return (0);
		i++;
	}
	if (args[0][0] == '.' || args[0][0] == '/')
		return (1);
	return (2);
}

t_command	*create_command(t_list *token_list)
{
	t_command	*result;
	t_list		**token_lists;

	result = ft_calloc(1, sizeof(t_command));
	result->fds[1] = 1;
	result->fds[2] = 2;
	token_lists = separe_tokens(token_list);
	result->argc = tokeniced_to_args(token_lists[0], &result->args);
	open_redirs(result, token_lists[1]);
	result->info = get_type(result->args);
	ft_lstclear_type(&token_lists[0], del_token);
	ft_lstclear_type(&token_lists[1], del_token);
	free(token_lists);
	return (result);
}
