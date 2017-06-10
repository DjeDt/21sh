/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:02:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:39:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "libft.h"
# include "readline.h"

# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]"
# define SETENV_USAGE "usage: setenv [NAME=value]"
# define UNSETENV_USAGE "usage: unsetenv [NAME]"
# define CD_USAGE "usage: cd [path]"
# define EXIT_USAGE "usage: exit [status]"

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)

typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(const char **);
}				t_builtin;

char			**g_env;

void			get_environ(void);
char			*get_var_name(char *str);
char			*get_var_value(const char *tf);

void			bin_error(const char *str);
void			malloc_error(char *str, int ret);
int				arg_error(char *str, char *usage, char c);
int				dir_error(const char *str, const char *file);

int				ft_echo(const char **input);
int				ft_env(const char **input);
int				env_no_arg(const char **input, char **path);
int				ft_setenv(const char **input);
int				ft_unsetenv(const char **input);
int				ft_exit(const char **input);
int				ft_cd(const char **input);

int				read_line(const int fd, char **line);
int				ft_launch_prog(const char **av);

void			get_signal(int signal);
void			print_prompt(void);
void			print_launch(void);

#endif
