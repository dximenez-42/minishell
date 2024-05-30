/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:20:18 by dximenez          #+#    #+#             */
/*   Updated: 2024/05/30 14:22:18 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "input.h"

void	echo_builtin(t_input *input, int i);
void	cd_builtin(t_input *input, int i);
void	pwd_builtin(t_input *input, int i);

#endif