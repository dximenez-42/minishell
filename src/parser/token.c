/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:32:51 by bvelasco          #+#    #+#             */
/*   Updated: 2024/05/25 18:07:01 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	del_token(t_content content, t_type type)
{
	t_token	*token;
	
	token = content.oth;
	free(token->value);
	free(token);
}