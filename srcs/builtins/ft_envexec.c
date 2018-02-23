/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envexec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:12:48 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/29 20:56:25 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void	ft_env_abs_path_bin(char *path, char **token, int f)
{
	pid_t	father;
	int		ret;
	int		sig;

	ret = 0;
	father = fork();
	if (father == 0)
	{
		if (f == 1)
		{
			ft_arraydel_2d(g_environ, 0);
			g_environ = NULL;
		}
		if ((ret = execve(path, token, g_environ)) < 0)
			ft_error_bin(path);
		exit(-1);
	}
	wait(&sig);
}

static void	ft_env_srch_abs_path(char **path, char **t, int flags)
{
	char	*buf;
	int		i;
	int		v;

	i = 0;
	v = 0;
	buf = NULL;
	while (path[i])
	{
		buf = ft_strjoin(path[i], "/");
		buf = ft_strjoin1(&buf, &(*t));
		if (access(buf, F_OK) == 0)
		{
			ft_env_abs_path_bin(buf, t, flags);
			ft_strdel(&buf);
			v = 1;
			break ;
		}
		else
			ft_strdel(&buf);
		i++;
	}
	if (v == 0)
		ft_putendl_fd("error: bin not found", 1);
}

static void	ft_env_r_path_bin(char **token, int flags)
{
	char	*env;
	char	**path;
	int		id;

	path = NULL;
	if ((id = ft_searchenv("PATH=")) < 0)
		return (ft_putendl_fd("ft_relativepath_bin: Bin not found", 2));
	if (!(env = ft_strsub(g_environ[id], 5, ft_strlen(g_environ[id]))))
		return (ft_putendl_fd("ft_strsub : return null", 2));
	if (!(path = (char**)ft_strsplit(env, ':')))
		return (ft_putendl_fd("strplit: return null", 2));
	ft_env_srch_abs_path(path, token, flags);
	ft_strdel(&env);
	ft_arraydel_2d(path, 0);
}

void		ft_envexec(char **token, int flags)
{
	if (ft_strchr(*token, '/') == 0)
		ft_env_r_path_bin(token, flags);
	else
		ft_env_abs_path_bin(*token, token, flags);
}
