/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:52 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:25:53 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_all_fd(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->fdin != 0)
			close(cmd->fdin);
		if (cmd->fdout != 1)
			close(cmd->fdout);
		cmd = cmd->next;
	}
}

char	*r_path(char *str, t_path *path)
{
	char	*tmp;
	int		j;

	j = 0;
	while (path)
	{
		tmp = concat_path(path->path, str, j);
		if (access(tmp, F_OK & X_OK) == 0)
			return (tmp);
		path = path->next;
	}
	free(tmp);
	return (NULL);
}

char	**tab_env(t_data *data)
{
	t_env	*env;
	char	**tab;
	int		i;

	i = 0;
	env = data->first_env;
	while (env)
	{
		i++;
		env = env->next;
	}
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	env = data->first_env;
	i = 0;
	while (env)
	{
		tab[i] = env->line;
		i++;
		env = env->next;
	}
	tab[i] = NULL;
	return (tab);
}

void	do_cmd_built_in(t_data *data, t_cmd *cmd, t_link *link)
{
	dup2(cmd->fdin, STDIN_FILENO);
	dup2(cmd->fdout, STDOUT_FILENO);
	if (cmd->arg[0] == NULL || link == NULL)
	{
		exit(1);
	}
	else if (is_build_in(cmd->arg[0]) == 0)
	{
		exec_built_in(link, data, cmd->fdout);
	}
	else if (is_cmd(data, cmd->arg[0]) == 0 || is_cmd(data, cmd->arg[0]) == 1)
	{
		if (is_cmd(data, cmd->arg[0]) == 0)
		{
			close_all_fd(data->first_cmd);
			execve(r_path(link->word, data->first_path), cmd->arg,
				tab_env(data));
		}
		execve(cmd->arg[0], cmd->arg, tab_env(data));
	}
	exit(1);
}
