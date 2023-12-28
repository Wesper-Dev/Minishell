/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:40 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:41 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	next_start(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i] && str[i] != ':')
		i++;
	if (str[i] == ':')
		i++;
	return (i);
}

int	ft_strncmp_init(char *s1, char *s2, size_t n)
{
	size_t	pos;

	if (n != 0)
	{
		pos = 0;
		while ((s1[pos] != '\0' || s2[pos] != '\0') && pos < n)
		{
			if (s1[pos] != s2[pos])
				return (1);
			pos++;
		}
	}
	return (0);
}

void	fill_data(t_data *data, char **envp)
{
	t_path	*path;
	char	*tmp;
	int		line;
	int		i;

	i = 5;
	line = 0;
	data->first_link = NULL;
	data->first_path = NULL;
	data->first_cmd = NULL;
	while (envp[line] && (ft_strncmp_init(envp[line], "PATH=", 5) == 1))
		line++;
	if (envp[line] == NULL)
		data->first_path = NULL;
	while (envp[line][i])
	{
		tmp = do_split(envp[line], i);
		path = new_link_path(tmp);
		add_link_path(data, path);
		i = next_start(envp[line], i);
	}
}

t_data	*init_data(char **envp)
{
	t_data	*data;
	t_env	*env;
	char	*tmp;
	int		line;

	line = 0;
	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->first_link = NULL;
	data->first_env = NULL;
	while (envp[line])
	{
		tmp = do_line(envp[line]);
		env = new_link_env(tmp);
		add_link_env(data, env);
		line++;
	}
	data->first_path = NULL;
	data->first_path = NULL;
	data->envp = envp;
	return (data);
}
