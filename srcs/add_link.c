/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:38 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:39:19 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_link(t_data *data, t_link *add_link)
{
	t_link	*tmp;

	if (data->first_link == NULL)
	{
		add_link->prev = NULL;
		data->first_link = add_link;
	}
	else
	{
		tmp = data->first_link;
		while (tmp->next != NULL)
			tmp = tmp->next;
		add_link->prev = tmp;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_path(t_data *data, t_path *add_link)
{
	t_path	*tmp;

	if (data->first_path == NULL)
	{
		add_link->prev = NULL;
		data->first_path = add_link;
	}
	else
	{
		tmp = data->first_path;
		while (tmp->next != NULL)
			tmp = tmp->next;
		add_link->prev = tmp;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_cmd(t_data *data, t_cmd *add_link)
{
	t_cmd	*tmp;

	if (data->first_cmd == NULL)
		data->first_cmd = add_link;
	else
	{
		tmp = data->first_cmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}

void	add_link_env(t_data *data, t_env *add_link)
{
	t_env	*tmp;

	if (data->first_env == NULL)
	{
		add_link->prev = NULL;
		data->first_env = add_link;
	}
	else
	{
		tmp = data->first_env;
		while (tmp->next != NULL)
			tmp = tmp->next;
		add_link->prev = tmp;
		tmp->next = add_link;
	}
	add_link->next = NULL;
}
