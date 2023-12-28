/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:02 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 18:27:03 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	main_more(t_data *data, char *str)
{
	init_cmd(data, data->first_link, 0);
	exec(data);
	if (str)
		free_link(data);
	free(str);
	free_cmd(data);
	free_path(data);
}

void	main_error_2(t_data *data, char *str)
{
	if (check_word(str, 0) == -1)
	{
		add_history(str);
		printf("Error\n");
	}
	free(str);
	free_path(data);
}

void	main_error(t_data *data, char *str)
{
	if (data->n_cmd == -1)
		printf("syntax error\n");
	if (data->n_cmd == -2)
		printf("command not found\n");
	free(str);
	free_link(data);
	free_path(data);
}

void	main_loop(t_data *data, char **envp, char *str)
{
	while (1)
	{
		fill_data(data, envp);
		str = readline("$>");
		if (ft_strcmp(str, "\0") == 0 || check_word(str, 0) < 0)
		{
			main_error_2(data, str);
			continue ;
		}
		add_history(str);
		lexer(str, data);
		data->n_cmd = parser(data);
		if (data->n_cmd < 0)
		{
			main_error(data, str);
			continue ;
		}
		main_more(data, str);
	}
}
