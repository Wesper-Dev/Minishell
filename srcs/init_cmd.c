/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:29 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:23:46 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_link	*cmd_link(t_link *link, int i)
{
	while (link && link->token != 6)
	{
		if (not_spe_link(link) == 0)
		{
			link = link->next;
			if (link)
				link = link->next;
			if (link == NULL || link->token == 6)
				break ;
		}
		link = link->next;
		i++;
	}
	return (link);
}

int	cmd_i(t_link *link, int i)
{
	while (link && link->token != 6)
	{
		if (not_spe_link(link) == 0)
		{
			link = link->next;
			if (link)
				link = link->next;
			if (link == NULL || link->token == 6)
				break ;
		}
		link = link->next;
		i++;
	}
	return (i);
}

char	**cmd_utils(t_link *link, char **arg, int i)
{
	while (link && link->token != 6)
	{
		if (not_spe_link(link) == 0)
		{
			link = link->next;
			if (link)
				link = link->next;
			if (link == NULL || link->token == 6)
				break ;
		}
		arg[i] = ft_strdup(link->word);
		link = link->next;
		i++;
	}
	return (arg);
}

void	init_cmd(t_data *data, t_link *link, int i)
{
	t_cmd	*cmd;
	char	**arg;

	while (link)
	{
		i = 0;
		arg = malloc(sizeof(char *) * (link_size(link) + 1));
		if (!arg)
			return ;
		link = next_link(link);
		if (link && is_cmd_built_in(link) == 1)
		{
			arg = cmd_utils(link, arg, i);
			i = cmd_i(link, i);
			link = cmd_link(link, i);
		}
		arg[i] = NULL;
		cmd = new_link_cmd(arg);
		add_link_cmd(data, cmd);
		while (link && link->token != 6)
			link = link->next;
		if (link)
			link = link->next;
	}
}
