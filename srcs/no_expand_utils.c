/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:35 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:36 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	end_word(char *str, int i)
{
	while (is_word(str[i]) == 1 && str[i])
		i++;
	return (i);
}

int	end_no_quote_j(char *str, int i, int j)
{
	char	c;

	c = str[i];
	i++;
	while (str[i] != c && str[i])
	{
		i++;
		j++;
	}
	return (j);
}
