/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/29 20:56:34 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void	child(char **argv, int flags)
{
	char	**tmp;
	char	**save;

	tmp = NULL;
	save = NULL;
	if (flags == 1)
	{
		save = ft_arrdup(g_environ);
		if ((tmp = malloc(8)) == NULL)
			ft_error_malloc("env fail");
		g_environ = tmp;
	}
	ft_setenv(argv);
	ft_putendl_array2d(&g_environ);
	if (flags == 1)
	{
		g_environ = save;
	}
	exit(0);
}

int			ft_envset(char **argv, int flags)
{
	pid_t	father;
	int		sig;

	if (*(argv + 2))
		return (-1);
	father = fork();
	if (father == 0)
		child(argv, flags);
	wait(&sig);
	if (flags == -1)
		return (-1);
	return (0);
}

static void	ft_env_core(char **argv, int size)
{
	int		count;
	char	**tmp_env;

	count = -1;
	tmp_env = NULL;
	(void)size;
	if ((ft_strcmp(*(argv + 1), "-i")) == 0)
		ft_env_i(argv + 2);
	else
	{
		while (argv[++count] != NULL)
			if (ft_strchr(argv[count], '=') == NULL)
				break ;
		tmp_env = ft_arrldup(argv + 2, count);
		tmp_env = ft_arrjoin(g_environ, tmp_env);
		ft_env_get_path(argv[count], tmp_env, argv + count);
		ft_arraydel_2d(tmp_env, 0);
	}
}

void		ft_env(char **argv)
{
	int		size;

	if ((size = ft_arraysize_2d(&argv)) == 1)
		ft_putendl_array2d(&g_environ);
	if (size > 1)
		ft_env_core(argv, size);
}
