/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_expand_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:31 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:32 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*spe_case(char *tmp, int j)
{
	tmp[j] = '\0';
	return (tmp);
}

char	*no_expand_utils(char *str, char *tmp, int i, int j)
{
	while (str[i])
	{
		if (str[i] == '\'')
			end_quote_i(str, i);
		else if (str[i] == '$' && str[i + 1] != '?')
		{
			j = i;
			i++;
			i = end_word(str, i);
			if (str[i] == '\0')
				return (spe_case(tmp, j));
			while (str[i])
			{
				tmp[j] = str[i];
				i++;
				j++;
			}
		}
		if (str[i])
			i++;
	}
	if (j != 0)
		tmp[j] = '\0';
	return (tmp);
}

char	*no_expand(char *str, int j)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	tmp = no_expand_utils(str, tmp, i, j);
	return (tmp);
}

char	*no_quote_utils(char *str, char *tmp, int i, int j)
{
	char	c;

	c = str[i];
	i++;
	while (str[i] != c && str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	return (tmp);
}

char	*no_quote(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			tmp = no_quote_utils(str, tmp, i, j);
			j = end_no_quote_j(str, i, j);
			i = end_quote_i(str, i) + 1;
		}
		if (str[i])
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}
