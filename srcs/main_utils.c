/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:07 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:08 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	spe_check(char *str, int i)
{
	if (str[i] == '>' || str[i] == '<')
		return (0);
	if (str[i] == '|' || str[i] == '$')
		return (0);
	return (1);
}

int	check_word_utils(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>')
	{
		i++;
		if (str[i + 1] == '>')
			return (-1);
	}
	if (str[i] == '<' && str[i + 1] == '<')
	{
		i++;
		if (str[i + 1] == '<')
			return (-1);
	}
	if ((str[i] == '|' && str[i + 1] == '|')
		|| (str[i] == '$' && str[i + 1] == '$'))
		return (-1);
	return (i);
}

int	check_utils(char *str, int i)
{
	char	c;

	c = str[i];
	i++;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}
