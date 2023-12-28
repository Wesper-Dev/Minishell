/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:12 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:13 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_spe_check(int token)
{
	if (token == 2 || token == 3)
		return (0);
	if (token == 4 || token == 5)
		return (0);
	else
		return (1);
}

void	check_quote(t_link *tmp, int fd, t_data *data)
{
	int		i;

	if (tmp->next == NULL && ft_strcmp_built_in(tmp->word, "-n") == 0)
		return ;
	while (tmp && tmp->token != 6)
	{
		if ((is_spe_check(tmp->token) == 0) && tmp)
		{
			tmp = tmp->next;
			if (tmp && tmp->token != 6)
				tmp = tmp->next;
		}
		if (tmp == NULL || tmp->token == 6)
			return ;
		i = 0;
		while (tmp->word[i])
		{
			ft_putchar_fd(tmp->word[i], fd);
			i++;
		}
		if (tmp->next != NULL && tmp->next->token != 6)
			ft_putstr_fd(" ", fd);
		if (tmp)
			tmp = tmp->next;
	}
}
