/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:44 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:45 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tabfd(t_data *data, int **tabfd)
{
	int	i;

	i = 0;
	while (i < data->n_cmd)
	{
		free(tabfd[i]);
		i++;
	}
	free(tabfd);
}

int	fill_tabfd(t_data *data, int **tabfd, t_cmd *cmd, int i)
{
	tabfd[i] = malloc(sizeof(int) * 2);
	if (!tabfd[i])
		return (-1);
	if (pipe(tabfd[i]) == -1)
		return (-1);
	if (i == 0)
		cmd->fdin = 0;
	else
		cmd->fdin = tabfd[i - 1][0];
	if (i == data->n_cmd - 1)
	{
		close(tabfd[i][0]);
		close(tabfd[i][1]);
		cmd->fdout = 1;
	}
	else
		cmd->fdout = tabfd[i][1];
	return (0);
}

int	ft_pipe(t_data *data)
{
	int		**tabfd;
	t_cmd	*cmd;
	int		res;
	int		i;

	i = 0;
	cmd = data->first_cmd;
	tabfd = malloc(sizeof(int *) * (data->n_cmd + 1));
	if (!tabfd)
		return (0);
	tabfd[data->n_cmd] = NULL;
	while (cmd)
	{
		res = fill_tabfd(data, tabfd, cmd, i);
		if (res == -1)
		{
			free_tabfd(data, tabfd);
			return (res);
		}
		cmd = cmd->next;
		i++;
	}
	free_tabfd(data, tabfd);
	return (res);
}
