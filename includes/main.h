/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:24:19 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/23 13:16:21 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>

/*
** MODULE
*/

# include "struct.h"
# include "edit_line.h"
# include "lexer.h"
# include "parser.h"
# include "interpreter.h"
# include "signals.h"

/*
** GLOBAL
*/

int					g_fd_term;
int					g_flg;
char				**g_environ;
char				*g_line;

/*
**	DEFINE
*/

# define O_HEREDOC "/tmp/heredoc_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664

/*
** TOOLS
*/

int					ft_searchenv(char *argv);
void				ft_envdup(void);
void				ft_setoldpwd(void);

int					ft_search(char *argv);
void				ft_error_malloc(char *error);
void				ft_error_open(char *e);
void				ft_error_create(char *error, char *file);
void				ft_error_bin(char *prog);
void				ft_oldpwdnotset(void);
void				ft_error_chdir(char *argv);
int					ft_error_syntaxe(int ret);
int					ft_isatty(void);

char				*ft_strjoin_f0(char *s1, char *s2);
char				*ft_strjoin_f1(char *s1, char *s2);
char				*ft_strjoin_f2(char *s1, char *s2);

char				**ft_arrdup(char **array);
int					ft_gnl(const int fd, char **line);
void				malloc_error2(const char *str, const int ret);
size_t				ft_strlen2(const char *str);
size_t				ft_strnlen(const char *str, char c);
char				*ft_strfsub2(char *s, unsigned int start, size_t len);
char				*ft_strftrim(char *s);
char				*ft_strjoin_fl2(char *s, const char *s2);
int					ft_count_char(const char *str, const char c);

/*
** PROTOTYPE REDIRECTION
*/

int					ft_redirect_core(t_r **r);
int					ft_strlensplit(char *s, char c);
char				*split_str(char *s, int len, int mode, int *statut);
t_r					*ft_create_elem_redirection(int red, int fd);
void				ft_push_back_redirection(t_r **begin_list, t_r *elem);
void				ft_redirect_handler(t_r *elem);
void				ft_redirect_right_nofile(t_r *elem);
void				ft_del_elem_redirection(t_r **r, int mode);
void				ft_del_list_redirection(t_r **r, int mode);
void				ft_print_list_redirection(t_r **list);
void				core_heredoc(t_r *redi);
int					check_file(t_r *elem);

#endif
