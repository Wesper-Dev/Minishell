/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:12 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:34:53 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_word_utils(char *s2, char *tmp, int cara, int j)
{
	while (s2[cara])
	{
		tmp[j] = s2[cara];
		j++;
		cara++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*expand_make_word(char *s1, int i, char *s2, int cara)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	while (j < cara)
	{
		tmp[j] = s2[j];
		j++;
	}
	while (s1[i])
	{
		tmp[j] = s1[i];
		j++;
		i++;
	}
	cara++;
	while (is_word(s2[cara]) == 1 && s2[cara])
		cara++;
	tmp = expand_word_utils(s2, tmp, cara, j);
	return (tmp);
}

char	*expand_utils(t_env *buf, char *str, int k)
{
	int	j;

	while (buf)
	{
		j = 0;
		if (expand_strcmp(&str[k], buf->line) == 0)
		{
			while (buf->line[j] == str[j + k] && str[j + k])
				j++;
			if (buf->line[j] == '=' && is_word(str[j + k]) == 0)
			{
				j++;
				str = expand_make_word(buf->line, j, str, k - 1);
				k = j + k;
				break ;
			}
		}
		buf = buf->next;
	}
	return (str);
}

char	*expand_double_quote(t_data *data, t_env *buf, char *str, int k)
{
	while (str[k] != '\"' && str[k])
	{
		if (str[k] == '$' && str[k + 1] && str[k + 1] != '$')
		{
			k++;
			buf = data->first_env;
			str = expand_utils(buf, str, k);
		}
		if (str[k] && str[k] != '\"')
			k++;
	}
	return (str);
}

char	*expand(t_data *data, char *str)
{
	t_env	*buf;
	int		k;

	k = 0;
	while (str[k])
	{
		if (str[k] == '\'')
			k = end_simple_quote(str, k);
		if (str[k] == '\"')
		{
			str = expand_double_quote(data, buf, str, k + 1);
			k = end_double_quote(str, k + 1);
		}
		if (str[k] == '$' && str[k + 1] && str[k + 1] != '$')
		{
			k++;
			buf = data->first_env;
			str = expand_utils(buf, str, k);
		}
		if (str[k])
			k++;
	}
	return (str);
}
