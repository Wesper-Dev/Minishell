/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:54 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:55 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	not_spe_c(char c)
{
	if (c == '>')
		return (0);
	if (c == '<')
		return (0);
	if (c == '|')
		return (0);
	return (1);
}

int	spe_next_word(char *str, int i)
{
	char	c;

	c = str[i];
	i++;
	if (str[i] == c)
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

char	*spe_word(char *str, char *tmp, int i)
{
	char	c;

	c = str[i];
	if (str[i + 1] == c)
	{
		tmp[0] = str[i];
		tmp[1] = str[i + 1];
		tmp[2] = '\0';
	}
	else
	{
		tmp[0] = str[i];
		tmp[1] = '\0';
	}
	return (tmp);
}

int	end_quote_i(char *str, int i)
{
	char	c;

	c = str[i];
	i++;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	end_quote_j(char *str, int i, int j)
{
	char	c;

	c = str[i];
	i++;
	j++;
	while (str[i] != c && str[i])
	{
		i++;
		j++;
	}
	return (j);
}
