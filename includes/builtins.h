/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:20:18 by dximenez          #+#    #+#             */
/*   Updated: 2024/06/01 13:23:08 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "input.h"

int	env_builtin(t_input *input, int i);
int	export_builtin(t_input *input, int i);
int	unset_builtin(t_input *input, int i);
int	echo_builtin(t_input *input, int i);
int	cd_builtin(t_input *input, int i);
int	pwd_builtin(t_input *input, int i);

#endif