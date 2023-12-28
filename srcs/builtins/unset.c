/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:28:47 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:28:48 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	write_fls(char *word, int fd)
{
	ft_putstr_fd("minishell: unset: `", fd);
	ft_putstr_fd(word, fd);
	ft_putstr_fd("': not a valid identifier\n", fd);
}

static void	unset_var(t_env *ret, t_data *data)
{
	t_env	*p;
	t_env	*n;

	p = ret->prev;
	if (ret->next == NULL)
	{
		p->next = NULL;
	}
	else
	{
		n = ret->next;
		p->next = n;
		n->prev = p;
	}
	free(ret->line);
	free(ret);
}

void	unset_built_in(t_link *tmp, t_data *data, int fd)
{
	int		i;
	int		c;
	char	*str;
	t_env	*ret;

	i = 0;
	if (tmp->next)
		tmp = tmp->next;
	else
		return ;
	while (tmp)
	{
		str = ft_strdup(tmp->word);
		while (str[i] != '=' && str[i])
			i++;
		str[i] = '\0';
		ret = is_alr_here(str, data->first_env);
		if (ret == NULL)
			write_fls(tmp->word, fd);
		else
			unset_var(ret, data);
		tmp = tmp->next;
		free(str);
	}
}
