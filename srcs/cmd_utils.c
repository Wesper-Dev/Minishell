/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:48 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:25:49 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	not_spe_link(t_link *link)
{
	if (link->token == 2 || link->token == 3)
		return (0);
	if (link->token == 4 || link->token == 5)
		return (0);
	return (1);
}

t_link	*next_link(t_link *link)
{
	if (link && (not_spe_link(link) == 0))
	{
		link = link->next;
		if (link)
			link = link->next;
	}
	return (link);
}

int	is_cmd_built_in(t_link *link)
{
	if (link->token == 8 || link->token == 9)
		return (1);
	if (link->token == 10 || link->token == 11)
		return (1);
	return (0);
}

int	link_size(t_link *link)
{
	int	i;

	i = 0;
	while (link)
	{
		link = link->next;
		i++;
	}
	i++;
	return (i);
}

char	*ft_strjoin_sp(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = ' ';
	i++;
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
