/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:02:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/02 13:06:45o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	creat_heredoc(char *delimitor, __int8_t type)
{
	int		fds[2];
	char	*line;

	(void) type;
	pipe(fds);
	line = readline("> ");
	while (line && ft_strncmp(line, delimitor, ft_strlen(delimitor) + 1))
	{
		ft_putendl_fd(line, fds[1]);
		free(line);
		line = readline("> ");
	}
	close(fds[1]);
	if (line)
		free(line);
	return (fds[0]);
}

int	ft_isredir(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}
