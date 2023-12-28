/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:07 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 21:42:23 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_utils(t_link *tmp, int fd, char *str, char *path)
{
	if (tmp->next->next)
	{
		ft_putstr_fd("cd: too many arguments\n", fd);
		g_status = 1;
		return ;
	}
	else if (tmp->next && chdir(tmp->next->word) == -1)
	{
		str == ft_strjoin("cd: ", path);
		perror (str);
		free (str);
		g_status = 1;
		return ;
	}
}

static char	*ft_parse_dir(void)
{
	char	*home;

	home = getenv("HOME");
	if (home == NULL)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		g_status = 1;
		return (NULL);
	}
	else
		return (ft_strdup(home));
}

void	built_in_cd(t_link *tmp, t_data *data, int fd, char *str)
{
	char	*path;

	if (tmp->next)
		cd_utils(tmp, fd, str, path);
	else if (!tmp->next)
	{
		path = ft_parse_dir();
		if (path == NULL)
			return ;
		else if (chdir(path) == -1)
		{
			str = ft_strjoin("cd: ", path);
			perror (str);
			free (str);
			g_status = 1;
		}
		free (path);
	}
}
