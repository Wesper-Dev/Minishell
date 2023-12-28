/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:48 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:49 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error(int mode, int value)
{
	static int	error;

	if (mode == 1)
		error = value;
	return (error);
}

int	g_signal(int mode, int value)
{
	static int	sig;

	if (mode == 1)
		sig = value;
	return (sig);
}
