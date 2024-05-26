/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:44:02 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/26 16:49:13 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//separe args from redirs

static t_list	**separe_tokens(t_list *token_list)
{
	t_list	**result;
	t_list	*temp;
	t_token	*tok;

	result = ft_calloc(2, sizeof(void *));
	if (!result)
		return (error(ERRMEM), NULL);
	while (token_list)
	{
		tok = token_list->content.oth;
		temp = token_list->next;
		token_list->next = NULL;
		token_list->prev = NULL;
		if (tok->type == ARG)
			ft_lstadd_back(result, token_list);
		if (tok->type == RD)
			ft_lstadd_back(result + 1, token_list);
		token_list = temp;
	}
	return (result);
}

static char	**tokeniced_to_args(t_list *token_list)
{
	int			noa;
	int			i;
	t_token		*tok;
	char		**result;

	i = 0;
	noa = ft_lstsize(token_list);
	if (noa == 0)
		return (NULL);
	result = malloc((noa + 1) * sizeof(void *));
	result[noa] = NULL;
	while (i < noa)
	{
		tok = token_list->content.oth;
		result[i] = ft_strdup(tok->value);
		token_list = token_list->next;
		i++;
	}
	return (result);
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
			printf("WARNING: << is not implemented, will be ignored\n");
//			command->fds[0] = process_heredoc();
		else if (redir_type == 1)
			command->fds[0] = open(tok->value + i, O_RDONLY);
		else if (redir_type == 2)
			command->fds[1] = open(tok->value + i, O_WRONLY | O_APPEND);
		else if (redir_type == 3)
			command->fds[1] = open(tok->value + i, O_WRONLY);
		token_list = token_list->next;
	}
}
t_command	*create_command(t_list *token_list)
{
	t_command	*result;
	t_list		**token_lists;
	
	result = ft_calloc(1, sizeof(t_command));
	result->fds[1] = 1;
	result->fds[2] = 2;
	token_lists = separe_tokens(token_list);
	result->args = tokeniced_to_args(token_lists[0]);
	open_redirs(result, token_lists[1]);
	result->info = 0;
	ft_lstclear_type(&token_lists[0], del_token);
	ft_lstclear_type(&token_lists[1], del_token);
	free(token_lists);
	return (result);
}