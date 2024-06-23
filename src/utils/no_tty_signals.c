/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_tty_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:16:14 by bvelasco          #+#    #+#             */
/*   Updated: 2024/06/23 18:34:32 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	sigint_handler_notty(int signum)
{
	g_signum = signum;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
}

static void	sigquit_handler_notty(int signum)
{
	g_signum = signum;
	return ;
}

static void	sig_handler_notty(int status)
{
	g_signum = status;
	if (status == SIGINT)
		sigint_handler_notty(status);
	else if (status == SIGQUIT)
		sigquit_handler_notty(status);
}

void	signals_notty(void)
{
	signal(SIGINT, sig_handler_notty);
	signal(SIGQUIT, sig_handler_notty);
}
