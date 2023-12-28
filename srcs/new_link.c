/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:26 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:27 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_link	*new_link(char *str)
{
	t_link	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	if (!str)
		link->word = NULL;
	else
		link->word = str;
	link->token = 0;
	return (link);
}

t_env	*new_link_env(char *str)
{
	t_env	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	if (!str)
		link->line = NULL;
	else
		link->line = str;
	return (link);
}

t_path	*new_link_path(char *str)
{
	t_path	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	if (!str)
		link->path = NULL;
	else
		link->path = str;
	return (link);
}

t_cmd	*new_link_cmd(char **arg)
{
	t_cmd	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	else if (!arg)
		link->arg = NULL;
	else
		link->arg = arg;
	return (link);
}
