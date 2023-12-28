/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:23:04 by juaugry           #+#    #+#             */
/*   Updated: 2023/12/28 19:27:53 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <dirent.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# define SET 1
# define GET 0
# define ERROR -1

extern int	g_status;

typedef struct s_link
{
	char			*word;
	int				token;
	struct s_link	*next;
	struct s_link	*prev;
}	t_link;

typedef struct s_env
{
	char			*line;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_path
{
	char			*path;
	struct s_path	*next;
	struct s_path	*prev;
}	t_path;

typedef struct s_cmd
{
	char			**arg;
	int				fdin;
	int				fdout;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_link		*first_link;
	t_env		*first_env;
	t_path		*first_path;
	t_cmd		*first_cmd;
	char		**envp;
	int			n_cmd;
	pid_t		*pid;
}					t_data;

int					error(int mode, int value);
void				check_quote(t_link *tmp, int fd, t_data *data);
t_env				*is_alr_here(char *s1, t_env *env);
int					g_signal(int mode, int value);
void				handler_signal(int sign);

void				built_in_pwd(int fd);
void				built_in_exit(t_data *data, int fd);
void				built_in_export(t_link *tmp, t_data *data, int fd);
void				built_in_echo(t_link *built_in, t_data *data, int fd);
void				built_in_env(t_data *data, int fd);
void				built_in_cd(t_link *tmp, t_data *data, int fd, char *str);
int					is_check_c(t_link *tmp, int space, int c);
int					is_d_and_a(t_link *tmp, int c);
int					is_clear_c_2(t_link *tmp, int c, int nb);
void				write_export(t_env *tmp, t_data *data, int fd);
void				unset_built_in(t_link *tmp, t_data *data, int fd);

t_data				*init_data(char **envp);
void				fill_data(t_data *data, char **envp);
void				lexer(char *str, t_data *data);
int					make_token(t_data *data, char *str);
char				*expand(t_data *data, char *str);
int					ft_strcmp(char *s1, char *s2);
int					parser(t_data *data);
int					check_word(char *str, int i);
int					is_word(int c);
int					ft_pipe(t_data *data);
int					exec(t_data *data);
char				*concat_path(char *s1, char *s2, int j);
void				init_cmd(t_data *data, t_link *link, int i);
char				*r_path(char *str, t_path *path);
void				change_fd(t_cmd *cmd, t_link *link);
void				exec_built_in(t_link *built_in, t_data *data, int fd);
int					ft_strcmp_built_in(char *s1, char *s2);
int					not_spe_c(char c);
int					not_spe_link(t_link *link);
int					is_cmd(t_data *data, char *str);
int					is_build_in(char *str);
int					end_double_quote(char *str, int k);
int					end_simple_quote(char *str, int k);
int					expand_strcmp(char *s1, char *s2);
int					is_word(int c);
t_link				*next_link(t_link *link);
int					end_expand(t_env *buf, char *str, int k);
char				*do_split(char *str, int i);
char				*do_line(char *str);
int					spe_next_word(char *str, int i);
char				*spe_word(char *str, char *tmp, int i);
int					end_quote_i(char *str, int i);
int					end_quote_j(char *str, int i, int j);
char				*no_expand(char *str, int j);
char				*no_quote(char *str);
int					end_word(char *str, int i);
int					end_no_quote_j(char *str, int i, int j);
int					link_size(t_link *link);
char				*ft_strjoin_sp(const char *s1, const char *s2);
int					is_cmd_built_in(t_link *link);
void				close_all_fd(t_cmd *cmd);
void				do_cmd_built_in(t_data *data, t_cmd *cmd, t_link *link);
char				**tab_env(t_data *data);
int					check_word_utils(char *str, int i);
int					check_utils(char *str, int i);
int					spe_check(char *str, int i);
void				free_main(t_data *data, char *str);
void				main_error(t_data *data, char *str);
void				main_error_2(t_data *data, char *str);
void				main_loop(t_data *data, char **envp, char *str);
char				*ft_strdup(const char *s1);
char				*expand_make_word(char *s1, int i, char *s2, int cara);

t_link				*new_link(char *str);
t_env				*new_link_env(char *str);
t_path				*new_link_path(char *str);
t_cmd				*new_link_cmd(char **arg);

void				add_link(t_data *data, t_link *add_link);
void				add_link_path(t_data *data, t_path *add_link);
void				add_link_env(t_data *data, t_env *add_link);
void				add_link_cmd(t_data *data, t_cmd *add_link);

void				free_data(t_data *data);
void				free_env(t_data *data);
void				free_cmd(t_data *data);
void				free_path(t_data *data);
void				free_link(t_data *data);

#endif
