/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:26 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:27 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_check_c(t_link *tmp, int space, int c)
{
	while (tmp->word[c])
	{
		if (ft_isdigit(tmp->word[c]) == 1 && space == 1)
			return (-1);
		c++;
	}
	return (0);
}

int	is_d_and_a(t_link *tmp, int c)
{
	while (tmp->word[c])
	{
		if (ft_isdigit(tmp->word[c]) == 0
			&& ft_strcmp_built_in(tmp->word, " ") != 0)
			return (-1);
		c++;
	}
	return (0);
}

int	is_clear_c_2(t_link *tmp, int c, int nb)
{
	while (tmp->word[c])
	{
		if (ft_isdigit(tmp->word[c]) == 1)
			nb = 1;
		c++;
	}
	return (nb);
}
