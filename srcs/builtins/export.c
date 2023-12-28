/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:39 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:40 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp_export(char *s1, char *s2)
{
	size_t	pos;

	pos = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[pos] || s2[pos])
	{
		if (s1[pos] == '=' && s2[pos] == '=')
			return (0);
		else if (s1[pos] == '\0' && s2[pos] == '=')
			return (0);
		if (s1[pos] != s2[pos])
			return (s1[pos] - s2[pos]);
		pos++;
	}
	return (0);
}

t_env	*is_alr_here(char *s1, t_env *env)
{
	int		i;

	i = 0;
	while (env)
	{
		if (ft_strcmp_export(s1, env->line) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	modif_utils(t_data *data, t_link *tmp, t_env *add)
{
	char	*str;

	str = ft_strdup(tmp->word);
	add = new_link_env(str);
	add_link_env(data, add);
}

void	modif_env(t_link *tmp, t_data *data, int fd, t_env *env)
{
	t_env	*add;
	char	*str;
	int		i;

	add = NULL;
	while (tmp)
	{
		i = 0;
		env = data->first_env;
		str = ft_strdup(tmp->word);
		while (str[i] != '=' && str[i])
			i++;
		str[i] = '\0';
		env = is_alr_here(str, env);
		if (env != NULL)
		{
			str = ft_strdup(tmp->word);
			env->line = str;
		}
		else
			modif_utils(data, tmp, add);
		tmp = tmp->next;
		free(str);
	}
}

void	built_in_export(t_link *prompt, t_data *data, int fd)
{
	t_env	*tmp;
	int		i;
	int		count;

	tmp = data->first_env;
	if (prompt->next)
		modif_env(prompt->next, data, fd, data->first_env);
	else
	{
		while (tmp)
		{
			write_export(tmp, data, fd);
			tmp = tmp->next;
		}
	}
}
