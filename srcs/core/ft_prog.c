/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:41:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static	void	not_found(const char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": not found", 2);
}

static	int		spawn_path(const char *path, const char **av)
{
	int		ret;
	pid_t	child;

	ret = 0;
	if (access(path, F_OK) == 0)
	{
		child = fork();
		if (child == 0)
		{
			ret = execve(path, (char **)av, g_env);
			exit(1);
		}
		wait(&child);
	}
	else
		return (-1);
	return (ret);
}

static int		search_prog(char **diff_p, const char **av)
{
	int		ret;
	int		count;
	char	*path;

	count = -1;
	while (diff_p != NULL && diff_p[++count] != NULL)
	{
		path = ft_strjoin(diff_p[count], "/");
		path = ft_strjoin_fl(path, av[0]);
		ret = spawn_path(path, av);
		ft_strdel(&path);
		if (ret == 0)
			break ;
	}
	ret < 0 ? not_found(av[0]) : 0;
	return (ret);
}

int				ft_launch_prog(const char **av)
{
	int		ret;
	char	**diff_p;

	ret = -1;
	if (ft_strchr(av[0], '/') != NULL)
		ret = spawn_path(av[0], av);
	else
	{
		diff_p = ft_strsplit(get_var_value("PATH"), ':');
		ret = search_prog(diff_p, av);
		diff_p != NULL ? ft_arrfree(&diff_p) : NULL;
	}
	return (ret);
}
