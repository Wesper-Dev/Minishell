/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:22 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:23 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_env(t_env *tmp)
{
	int	i;
	int	len;

	i = 0;
	while (tmp->line[i])
	{
		if (tmp->line[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	built_in_env(t_data *data, int fd)
{
	t_env	*tmp;

	tmp = data->first_env;
	while (tmp)
	{
		if (check_env(tmp) == 0)
		{
			ft_putstr_fd(tmp->line, fd);
			ft_putchar_fd('\n', fd);
		}
		tmp = tmp->next;
	}
}
