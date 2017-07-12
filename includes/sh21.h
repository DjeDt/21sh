/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:02:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 16:42:41 by ddinaut          ###   ########.fr       */
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
# include "execution.h"

/* Builtins usage */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]"
# define SETENV_USAGE "usage: setenv [NAME=value]"
# define UNSETENV_USAGE "usage: unsetenv [NAME]"
# define CD_USAGE "usage: cd [path]"
# define EXIT_USAGE "usage: exit [status]"

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)

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
int				arg_error(char *str, char *usage, char c);
int				dir_error(const char *str, const char *file);

/* Prog func */
int				ft_launch_prog(const char **av);

/* Signal func */
void			get_signal(int signal);

/* Others */
void			print_prompt(void);
void			print_launch(void);

#endif
