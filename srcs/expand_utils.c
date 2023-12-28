/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:05 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:06 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	expand_strcmp(char *s1, char *s2)
{
	size_t	pos;

	pos = 0;
	while ((s1[pos] || s2[pos]))
	{
		if (pos > 0 && s2[pos] == '=')
			return (0);
		if (s1[pos] != s2[pos])
			return (s1[pos] - s2[pos]);
		pos++;
	}
	return (0);
}

int	end_simple_quote(char *str, int k)
{
	k++;
	while (str[k] != '\'' && str[k])
		k++;
	if (str[k])
		k++;
	return (k);
}

int	end_double_quote(char *str, int k)
{
	while (str[k] != '\"' && str[k])
		k++;
	if (str[k])
		k++;
	return (k);
}

int	end_expand(t_env *buf, char *str, int k)
{
	int	j;

	while (buf)
	{
		j = 0;
		if (expand_strcmp(&str[k], buf->line) == 0)
		{
			while (buf->line[j] == str[j + k] && str[j + k])
				j++;
			if (buf->line[j] == '=' && is_word(str[j + k]) == 0 && str[j + k])
			{
				j++;
				str = expand_make_word(buf->line, j, str, k - 1);
				k = j + k;
				return (j);
			}
		}
		buf = buf->next;
	}
	return (0);
}

int	is_word(int c)
{
	if (ft_isalpha(c) == 1)
		return (1);
	if (ft_isdigit(c) == 1)
		return (1);
	if (c == '_')
		return (1);
	return (0);
}
