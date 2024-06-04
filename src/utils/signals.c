/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:43:32 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/04 20:10:22 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_handler(void)
{
	rl_replace_line("", 0);
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_redisplay();
}

static void	sigquit_handler(void)
{
	if (isatty(STDIN_FILENO))
		rl_on_new_line();
}

void	sig_handler(int status)
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
