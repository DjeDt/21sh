/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:24:05 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/20 17:33:43 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "main.h"

# define NB_BUILTINS 7

typedef void	(*t_builtins)(char **argv);
int				g_backup;

/*
** MAIN PROTOTYPE
*/

void		pre_interpreter(char **token, t_r **r, int last);
void		ft_interpreter(char **token, t_r **r);
int			ft_identification_builtins(char *token);
void		ft_identification_bin(char **token);
void		ft_absolutepath_bin(char *path, char **token);
void		ft_search_good_abs_path(char **path, char **token);
void		ft_relativepath_bin(char **token);
void		ft_child_bin(char **token, int *fd, t_r **r, int last);

void		end_pipe(int last, int *fd);

/*
** BUILTINS
*/

# define UNSETENV_USAGE "usage: unsetenv [NAME]"
# define SETENV_USAGE "usage: setenv [NAME=value]"

void		ft_echo(char **argv);
void		ft_cd(char **argv);
void		ft_setenv(char **argv);
void		ft_unsetenv(char **argv);
void		ft_env(char **argv);
void		ft_exit(char **argv);
void		ft_pwd(char **argv);

/*
** TOOLS
*/

size_t		ft_arrlen(char **array);
char		**ft_arrjoin(char **base, char **add);
char		**ft_arrldup(char **arr, size_t max);
void		ft_envexec(char **argv, int flags);
void		ft_env_get_path(char *prog, char **env, char **arg);
void		ft_env_i(char **argv);
int			ft_setenv_usage(char **argv);
void		ft_error_chdir(char *argv);
void		ft_oldpwdnotset(void);

#endif
