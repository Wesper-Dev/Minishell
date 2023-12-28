/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:25:42 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:25:43 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fill_heredoc(int fd, char *str)
{
	char	*tmp;

	while (1)
	{
		tmp = readline(">");
		if (tmp == NULL)
			return (0);
		if (ft_strcmp(str, tmp) == 0)
			break ;
		write(fd, str, ft_strlen(str) + 1);
		write(fd, "\n", 1);
	}
	return (0);
}

int	new_fdout(t_cmd *cmd, t_link *link)
{
	if (link->token == 2)
	{
		if (cmd->fdout != 1)
			close(cmd->fdout);
		cmd->fdout = open(link->next->word, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cmd->fdout == -1)
			return (-1);
	}
	else if (link->token == 3)
	{
		if (cmd->fdout != 1)
			close(cmd->fdout);
		cmd->fdout = open(link->next->word, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (cmd->fdout == -1)
			return (-1);
	}
	return (0);
}

int	new_fdin(t_cmd *cmd, t_link *link)
{
	if (link->token == 4)
	{
		if (cmd->fdin != 0)
			close(cmd->fdin);
		cmd->fdin = open(link->next->word, O_RDONLY);
		if (cmd->fdin == -1)
			return (-1);
	}
	else if (link->token == 5)
	{
		if (cmd->fdin != 0)
			close(cmd->fdin);
		cmd->fdin = open("./heredoc", O_CREAT | O_RDWR, 0644);
		if (cmd->fdin != -1)
		{
			fill_heredoc(cmd->fdin, link->next->word);
			unlink("./heredoc");
		}
		if (cmd->fdin == -1)
			return (-1);
	}
	return (0);
}

void	change_fd(t_cmd *cmd, t_link *link)
{
	while (link && link->token != 6)
	{
		if (link->token == 2 || link->token == 3)
			if (new_fdout(cmd, link) == -1)
				return ;
		if (link->token == 4 || link->token == 5)
			if (new_fdin(cmd, link) == -1)
				return ;
		link = link->next;
	}
}
