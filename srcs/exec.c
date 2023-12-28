/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:55 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:38:52 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_fork(int i, t_data *data, t_cmd *cmd, t_link *link)
{
	data->pid[i] = fork();
	if (data->pid[i] == -1)
		exit(1);
	if (data->pid[i] == 0)
	{
		do_cmd_built_in(data, cmd, link);
		exit(1);
	}
	if (cmd->fdin != 0)
		close(cmd->fdin);
	if (cmd->fdout != 1)
		close(cmd->fdout);
}

void	one_cmd(t_cmd *cmd, t_link *link, t_data *data, int i)
{
	if (cmd->arg[0] == NULL)
		return ;
	else if (is_build_in(cmd->arg[0]) == 0)
		exec_built_in(link, data, cmd->fdout);
	else
	{
		ft_fork(0, data, cmd, link);
		waitpid(data->pid[0], NULL, 0);
	}
}

void	multi_cmd(t_cmd *cmd, t_link *link, t_data *data, int i)
{
	while (i < data->n_cmd)
	{
		ft_fork(i, data, cmd, link);
		cmd = cmd->next;
		while (link && link->token != 6)
			link = link->next;
		if (link)
			link = link->next;
		i++;
	}
}

void	do_fork(t_data *data)
{
	t_cmd	*cmd;
	t_link	*link;
	int		i;

	i = 0;
	link = data->first_link;
	cmd = data->first_cmd;
	while (cmd)
	{
		change_fd(cmd, link);
		cmd = cmd->next;
		while (link && link->token != 6)
			link = link->next;
		if (link)
			link = link->next;
	}
	cmd = data->first_cmd;
	link = data->first_link;
	if (data->n_cmd == 1)
		one_cmd(cmd, link, data, i);
	else if (data->n_cmd > 1)
		multi_cmd(cmd, link, data, i);
}

int	exec(t_data *data)
{
	int		res;
	int		i;

	i = 0;
	res = ft_pipe(data);
	if (res != 0)
		return (res);
	data->pid = malloc(sizeof(pid_t *) * (data->n_cmd + 1));
	if (!data->pid)
		return (-1);
	do_fork(data);
	while (i < data->n_cmd && data->n_cmd > 1)
	{
		waitpid(data->pid[0], NULL, 0);
		i++;
	}
	free(data->pid);
	return (0);
}
