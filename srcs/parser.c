/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:39 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:20:37 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parser_utils(t_link *tmp)
{
	int	n_cmd;

	n_cmd = 1;
	while (tmp->next)
	{
		if (not_spe_link(tmp) == 0)
			if (tmp->next->token == 6)
				return (-1);
		if (tmp->token == 6)
		{
			if (tmp->next->token == 6)
				return (-1);
			n_cmd++;
		}
		tmp = tmp->next;
	}
	if ((not_spe_link(tmp) == 0) || tmp->token == 6)
		return (-1);
	return (n_cmd);
}

int	parser(t_data *data)
{
	t_link	*tmp;
	int		n_cmd;

	tmp = data->first_link;
	if (tmp->token == 6)
		return (-1);
	if (tmp->next == NULL)
		if (tmp->token == 0 || tmp->token == 1)
			return (-2);
	n_cmd = parser_utils(tmp);
	return (n_cmd);
}
