/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:50:22 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/20 02:43:31 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	creat_ext_heredoc(t_list *env, char *delimitor)
{
	int		fds[2];
	char	*line;
	char	*ext;

	pipe(fds);
	line = readline("> ");
	while (line && ft_strncmp(line, delimitor, ft_strlen(delimitor) + 1))
	{
		ext = string_expansor(env, line);
		ft_putendl_fd(ext, fds[1]);
		free(ext);
		free(line);
		line = readline("> ");
	}
	close(fds[1]);
	if (line)
		free(line);
	return (fds[0]);
}

static int	creat_not_ext_heredoc(char *delimitor)
{
	int		fds[2];
	char	*line;

	if (!delimitor)
		return (-1);
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
	free(delimitor);
	return (fds[0]);
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
	int	fd;

	if (has_quotes(delim))
		fd = creat_not_ext_heredoc(remove_quotes(delim));
	else
		fd = creat_ext_heredoc(env, delim);
	return (fd);
}
