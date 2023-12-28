/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:48 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:49 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	process(int sign)
{
	if (!kill(g_signal(GET, 0), sign))
	{
		if (sign == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_status = 131;
			error(SET, ERROR);
		}
		else if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			error(SET, ERROR);
		}
	}
	else if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 127;
		error(SET, ERROR);
		ft_putstr_fd("$>", 1);
	}
}

void	handler_signal(int sign)
{
	if ((sign == SIGINT || sign == SIGQUIT) && g_signal(GET, 0) != 0)
		process(sign);
	else if (sign == SIGINT || sign == SIGQUIT)
	{
		if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			error(SET, ERROR);
			ft_putstr_fd("$>", 1);
		}
		else if (sign == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}
