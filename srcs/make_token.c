/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:21 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:22 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_build_in(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (0);
	if (ft_strcmp(str, "cd") == 0)
		return (0);
	if (ft_strcmp(str, "pwd") == 0)
		return (0);
	if (ft_strcmp(str, "export") == 0)
		return (0);
	if (ft_strcmp(str, "unset") == 0)
		return (0);
	if (ft_strcmp(str, "env") == 0)
		return (0);
	if (ft_strcmp(str, "exit") == 0)
		return (0);
	else
	{
		g_status = 127;
		return (-1);
	}
}

char	*concat_path(char *s1, char *s2, int j)
{
	char	*tmp;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	tmp = malloc(sizeof(char) * (i + 5));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '/';
	i++;
	while (s2[j])
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}

int	is_cmd(t_data *data, char *str)
{
	t_path	*tmp;
	char	*path_str;
	int		j;

	j = 0;
	tmp = data->first_path;
	if (access(str, F_OK & X_OK) == 0)
		return (1);
	while (tmp)
	{
		path_str = concat_path(tmp->path, str, j);
		if (access(path_str, F_OK & X_OK) == 0)
		{
			free(path_str);
			return (0);
		}
		free(path_str);
		tmp = tmp->next;
	}
	return (-1);
}

int	make_token(t_data *data, char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (2);
	if (ft_strcmp(str, ">>") == 0)
		return (3);
	if (ft_strcmp(str, "<") == 0)
		return (4);
	if (ft_strcmp(str, "<<") == 0)
		return (5);
	if (ft_strcmp(str, "|") == 0)
		return (6);
	if (ft_strcmp(str, "$?") == 0)
		return (7);
	if (is_build_in(str) == 0 && access(str, F_OK) == 0)
		return (9);
	if (is_build_in(str) == 0)
		return (8);
	if (access(str, F_OK & X_OK) == 0)
		return (11);
	if (is_cmd(data, str) == 0)
		return (10);
	if (access(str, F_OK) == 0)
		return (1);
	else
		return (0);
}
