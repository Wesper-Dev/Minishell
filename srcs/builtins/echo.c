/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:17 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:18 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp_echo(char *s1, char c)
{
	size_t	pos;

	pos = 0;
	while (s1[pos] && s1[pos] != c)
		pos++;
	if (s1[pos] == c)
		return (0);
	return (1);
}

int	check_token(t_link *tmp, t_data *data)
{
	if (tmp->token == 2 || tmp->token == 3 || \
	tmp->token == 4 || tmp->token == 1)
		return (1);
	if (tmp->token == 5 || tmp->token == 6 || \
	tmp->token == 10)
		return (1);
	return (0);
}

int	with_carriage_return(t_link *tmp, t_data *data, int fd)
{
	int	check;

	while (tmp->next)
	{
		if (ft_strcmp_built_in(tmp->word, "echo") == 0 && \
		strcmp(tmp->next->word, "-n") == 0)
		{
			return (2);
		}
		else
			return (1);
	}
	return (1);
}

void	print_argument_to_standard_output(t_link *tmp, t_data *data, int fd)
{
	if (tmp->next)
		tmp = tmp->next;
	else
		return ;
	if (tmp->token == 7)
	{
		ft_putnbr_fd(g_status, fd);
		return ;
	}
	while (ft_strcmp_built_in(tmp->word, "-n") == 0 && tmp->next)
		tmp = tmp->next;
	if (tmp)
		check_quote(tmp, fd, data);
}

void	built_in_echo(t_link *tmp, t_data *data, int fd)
{
	int	start_index;

	start_index = with_carriage_return(tmp, data, fd);
	if (start_index == 1)
	{
		print_argument_to_standard_output(tmp, data, fd);
		ft_putstr_fd("\n", fd);
	}
	if (start_index == 2)
	{
		print_argument_to_standard_output(tmp, data, fd);
	}
}
