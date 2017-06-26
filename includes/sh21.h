/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:02:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/26 15:10:20 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "libft.h"
# include "readline.h"
# include "analyse.h"

/* Builtins usage */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]"
# define SETENV_USAGE "usage: setenv [NAME=value]"
# define UNSETENV_USAGE "usage: unsetenv [NAME]"
# define CD_USAGE "usage: cd [path]"
# define EXIT_USAGE "usage: exit [status]"

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)

/* Struct for builtins*/
typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(const char **);
}				t_builtin;

/* const var */
char			**g_env;

/* parsing func */
char			**parse_input(char *str);

/* env func */
void			get_environ(void);
char			*get_var_name(char *str);
char			*get_var_value(const char *tf);

/* Error func */
void			bin_error(const char *str);
//void			malloc_error(char *str, int ret);
int				arg_error(char *str, char *usage, char c);
int				dir_error(const char *str, const char *file);

/* Builtins */
int				ft_echo(const char **input);
int				ft_env(const char **input);
int				env_no_arg(const char **input, char **path);
int				ft_setenv(const char **input);
int				ft_unsetenv(const char **input);
int				ft_exit(const char **input);
int				ft_cd(const char **input);

/* Prog func */
int				ft_launch_prog(const char **av);

/* Signal func */
void			get_signal(int signal);

/* Others */
void			print_prompt(void);
void			print_launch(void);

#endif
