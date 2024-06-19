/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:43:32 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/19 00:51:18 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sigint_handler(void)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigint_handler_heredoc(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
}

static void	sigquit_handler(void)
{
	if (isatty(STDIN_FILENO))
		rl_on_new_line();
}

static void	sig_handler(int status)
{
	if (status == SIGINT)
		sigint_handler();
	else if (status == SIGQUIT)
		sigquit_handler();
}

void	signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
