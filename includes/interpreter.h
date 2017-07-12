#ifndef INTERPRETER_H
# define INTERPRETER_H
# define NB_BUILTINS 6
# include "sh21.h"

/*
** STRUCTURE
*/

typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(const char **);
}				t_builtin;

/*
** PROTOTYPE BULTINS
*/

int				ft_echo(const char **input);
int				ft_env(const char **input);
int				env_no_arg(const char **input, char **path);
int				ft_setenv(const char **input);
int				ft_unsetenv(const char **input);
int				ft_exit(const char **input);
int				ft_cd(const char **input);

#endif
