/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:50:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/20 14:05:05 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	creat_ext_heredoc(t_list *env, char *delimitor, int fd)
{
	char	*line;
	char	*ext;

	line = readline("> ");
	while (line && ft_strncmp(line, delimitor, ft_strlen(delimitor) + 1))
	{
		ext = string_expansor(env, line);
		ft_putendl_fd(ext, fd);
		free(ext);
		free(line);
		line = readline("> ");
	}
	close(fd);
	if (line)
		free(line);
}

static void	creat_not_ext_heredoc(char *delimitor, int fd)
{
	char	*line;

	if (!delimitor)
		return ;
	line = readline("> ");
	while (line && ft_strncmp(line, delimitor, ft_strlen(delimitor) + 1))
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	close(fd);
	if (line)
		free(line);
	free(delimitor);
}

static char	*remove_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	int		len_without_quotes;

	i = 0;
	len_without_quotes = 0;
	while (str[i])
	{
		if (!ft_isquote(str[i++]))
			len_without_quotes++;
	}
	i = 0;
	result = malloc(len_without_quotes + 1);
	if (!result)
		return (0);
	j = 0;
	while (str[i])
	{
		if (!ft_isquote(str[i]))
			result[j++] = str[i];
		i++;
	}
	result[j] = 0;
	return (result);
}

static __uint8_t	has_quotes(char	*str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '"')
			return (1);
		str++;
	}
	return (0);
}

int	creat_heredoc(t_list *env, char *delim)
{
	int		fds[2];
	pid_t	pid;

	g_signum = 0;
	signal(SIGINT, sigint_handler_notty);
	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		close(fds[0]);
		signal(SIGINT, heredoc_signal);
		if (has_quotes(delim))
			creat_not_ext_heredoc(remove_quotes(delim), fds[1]);
		else
			creat_ext_heredoc(env, delim, fds[1]);
		exit(0);
	}
	close(fds[1]);
	wait(NULL);
	if (g_signum == SIGINT)
		(close(fds[0]), fds[0] = -2);
	g_signum = 0;
	return (fds[0]);
}
