/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:21 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:22 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmd(t_data *data)
{
	t_cmd	*tmp;
	t_cmd	*curr;
	int		i;

	tmp = data->first_cmd;
	curr = data->first_cmd;
	while (curr)
	{
		i = 0;
		while (curr->arg[i])
		{
			free(curr->arg[i]);
			i++;
		}
		free(curr->arg);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

void	free_link(t_data *data)
{
	t_link		*tmp;

	tmp = data->first_link;
	if (tmp->next == NULL)
		free(tmp->word);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp = tmp->prev;
		while (tmp->prev)
		{
			free(tmp->next->word);
			free(tmp->next);
			tmp = tmp->prev;
		}
		free(tmp->next->word);
		free(tmp->next);
		free(tmp->word);
	}
	free(tmp);
}

void	free_env(t_data *data)
{
	t_env		*tmp;

	tmp = data->first_env;
	if (tmp->next == NULL)
		free(tmp->line);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp = tmp->prev;
		while (tmp->prev)
		{
			free(tmp->next->line);
			free(tmp->next);
			tmp = tmp->prev;
		}
		free(tmp->next->line);
		free(tmp->next);
		free(tmp->line);
	}
	free(tmp);
}

void	free_path(t_data *data)
{
	t_path		*tmp;

	tmp = data->first_path;
	if (tmp->next == NULL)
		free(tmp->path);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp = tmp->prev;
		while (tmp->prev)
		{
			free(tmp->next->path);
			free(tmp->next);
			tmp = tmp->prev;
		}
		free(tmp->next->path);
		free(tmp->next);
		free(tmp->path);
	}
	free(tmp);
}

void	free_data(t_data *data)
{
	free_link(data);
	free_env(data);
	free_path(data);
	free(data);
}
