/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:15 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 20:53:42 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdbool.h>

int	g_status;

void	exec_built_in(t_link *built_in, t_data *data, int fd)
{
	char	*str;
	
	if (ft_strcmp_built_in(built_in->word, "pwd") == 0)
		built_in_pwd(fd);
	else if (ft_strcmp_built_in(built_in->word, "cd") == 0)
		built_in_cd(built_in, data, fd, str);
	else if (ft_strcmp_built_in(built_in->word, "exit") == 0)
		built_in_exit(data, fd);
	else if (ft_strcmp_built_in(built_in->word, "echo") == 0)
		built_in_echo(built_in, data, fd);
	else if (ft_strcmp_built_in(built_in->word, "env") == 0)
		built_in_env(data, fd);
	else if (ft_strcmp_built_in(built_in->word, "export") == 0)
		built_in_export(built_in, data, fd);
	else if (ft_strcmp_built_in(built_in->word, "unset") == 0)
		unset_built_in(built_in, data, fd);
}

int	space_and_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_word(char *str, int i)
{
	if (!str)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (space_and_tab(str) == 1)
		return (-2);
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			i = check_utils(str, i);
		if (i < 0)
			return (i);
		else if (spe_check(str, i) == 0)
			i = check_word_utils(str, i);
		if (i < 0)
			return (i);
		if (str[i])
			i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_data	*data;

	(void)argv;
	g_signal(SET, 0);
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	if (argc != 1)
		return (0);
	data = init_data(envp);
	main_loop(data, envp, str);
	free_env(data);
	free(data);
	return (0);
}
