/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:35 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:36 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	write_export(t_env *tmp, t_data *data, int fd)
{
	int		i;
	int		count;

	ft_putstr_fd("declare -x ", fd);
	i = 0;
	count = 0;
	while (tmp->line[i] && tmp->line)
	{
		if (tmp->line[i] == '=' && count == 0)
		{
			ft_putchar_fd(tmp->line[i], fd);
			i++;
			ft_putchar_fd('\"', fd);
			count = 1;
		}
		ft_putchar_fd(tmp->line[i], fd);
		i++;
	}
	if (tmp && count == 1)
		ft_putchar_fd('\"', fd);
	ft_putchar_fd('\n', fd);
}
