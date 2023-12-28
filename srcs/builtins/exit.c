/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:30 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:31 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	c_value(int first_cara)
{
	int	c;

	if (first_cara == 1)
		c = 1;
	else
		c = 0;
	return (c);
}

int	check_argument(t_link *tmp, int nb, int space, int first_cara)
{
	int		c;

	if (ft_strcmp_built_in(tmp->word, "-") == 0
		|| ft_strcmp_built_in(tmp->word, "+") == 0)
		first_cara = 1;
	while (tmp)
	{
		c = c_value(first_cara);
		if (is_d_and_a(tmp, c) == -1)
			return (-1);
		c = c_value(first_cara);
		nb = is_clear_c_2(tmp, c, nb);
		c = c_value(first_cara);
		if (ft_strcmp_built_in(tmp->word, " ") == 0 && nb == 1)
			space = 1;
		if (is_check_c(tmp, space, c) == -1)
			return (-1);
		if (tmp->next)
			return (-2);
		tmp = tmp->next;
	}
	return (0);
}

int	write_error(t_data *data, int fd)
{
	ft_putstr_fd("minishell: exit: numeric argument required\n", fd);
	return (255);
}

void	built_in_exit(t_data *data, int fd)
{
	int		nb;
	t_link	*tmp;

	tmp = data->first_link;
	nb = g_status;
	if (tmp->next)
	{
		if (check_argument(tmp->next, 0, 0, 0) == -2)
		{
			ft_putstr_fd("exit\nbash: exit: too many arguments\n", fd);
			return ;
		}
		if (check_argument(tmp->next, 0, 0, 0) == -1)
			nb = write_error(data, fd);
		else
		{
			nb = ft_atoi(tmp->next->word);
			nb = nb % 256;
			if (nb <= 0 && ft_strlen(tmp->next->word) > 14)
				nb = write_error(data, fd);
		}
	}
	free(data->pid);
	free_data(data);
	exit(nb);
}
