/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:58 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:16:37 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*word_utils(char *str, char *tmp, int j, int i)
{
	char	c;

	c = str[i];
	tmp[j] = str[i];
	i++;
	j++;
	while (str[i] != c && str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int	next_word(char *str, int i)
{
	char	c;

	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		return (spe_next_word(str, i));
	while (str[i] != ' ' && str[i] && not_spe_c(str[i]) == 1)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

char	*make_word(char *str, int i, int j)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		return (spe_word(str, tmp, i));
	while (str[i] != ' ' && str[i] && not_spe_c(str[i]) == 1)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			tmp = word_utils(str, tmp, j, i);
			j = end_quote_j(str, i, j);
			i = end_quote_i(str, i);
		}
		if (str[i] != '\0')
		{
			tmp[j] = str[i];
			j++;
			i++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}

void	lexer(char *str, t_data *data)
{
	t_link	*link;
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i])
	{
		tmp = make_word(str, i, 0);
		tmp = expand(data, tmp);
		tmp = no_expand(tmp, 0);
		if (tmp[0] != '\0')
		{
			link = new_link(tmp);
			link->token = make_token(data, link->word);
			link->word = no_quote(link->word);
			add_link(data, link);
			free(tmp);
		}
		i = next_word(str, i);
	}
}
