/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:53:31 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/23 18:59:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

void		exec_env(char *path, char **env, char **arg)
{
	pid_t	father;

	father = fork();
	if (father == 0)
	{
		execve(path, arg, env);
		exit(1);
	}
	wait(&father);
}

void		prog_check(char *prog, char **env, char **arg, char **path)
{
	int		count;
	char	*tmp;

	count = -1;
	if (ft_strchr(prog, '/') != NULL)
		exec_env(arg[0], env, arg);
	while (path[++count] != NULL)
	{
		tmp = ft_strjoin(path[count], "/");
		tmp = ft_strjoin1(&tmp, &prog);
		if (access(tmp, F_OK) == 0)
			exec_env(tmp, env, arg);
		ft_strdel(&tmp);
	}
	tmp != NULL ? ft_strdel(&tmp) : NULL;
}

void		ft_env_get_path(char *prog, char **env, char **arg)
{
	int		id;
	char	*tmp;
	char	**path;

	id = ft_searchenv("PATH=");
	if ((id = ft_searchenv("PATH=")) < 0)
		return (ft_putendl_fd("ft_relativepath_bin: Bin not found", 2));
	if (!(tmp = ft_strsub(g_environ[id], 5, ft_strlen(g_environ[id]))))
		return (ft_putendl_fd("ft_strsub : return null", 2));
	if (!(path = (char**)ft_strsplit(tmp, ':')))
		return (ft_putendl_fd("strplit: return null", 2));
	prog_check(prog, env, arg, path);
	ft_strdel(&tmp);
	ft_arraydel_2d(path, 0);
}

void		ft_env_i(char **argv)
{
	int		count;
	char	**tmp_env;
	char	**tmp_arg;

	count = 0;
	tmp_env = NULL;
	tmp_arg = NULL;
	while (argv[count] != NULL)
	{
		if (ft_strchr(argv[count], '=') == NULL)
			break ;
		++count;
	}
	tmp_env = ft_arrldup(argv, count);
	tmp_arg = ft_arrdup(argv + count);
	ft_env_get_path(tmp_arg[0], tmp_env, tmp_arg);
	ft_arraydel_2d(tmp_arg, 0);
	ft_arraydel_2d(tmp_env, 0);
}
