/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identification_bin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 21:48:12 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 14:50:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		ft_absolutepath_bin(char *path, char **token)
{
	pid_t	father;

	father = fork();
	save_pid(father);
	if (father == 0)
	{
		if (execve(path, token, (g_flg == -1) ? \
				(char *[]){ NULL } : g_environ) < 0)
			ft_error_bin(path);
	}
	else
		waitpid(father, NULL, 0);
}

void		ft_search_good_abs_path(char **path, char **t)
{
	char		*buf;
	int			i;
	int			v;

	i = 0;
	v = 0;
	buf = NULL;
	while (path[i])
	{
		buf = ft_strjoin(path[i], "/");
		buf = ft_strjoin1(&buf, &(*t));
		if (access(buf, F_OK) == 0)
		{
			ft_absolutepath_bin(buf, t);
			ft_strdel(&buf);
			v = 1;
			break ;
		}
		else
			ft_strdel(&buf);
		i++;
	}
	if (v == 0)
		ft_putendl_fd("error: bin not found", 2);
}

void		ft_relativepath_bin(char **token)
{
	char		*env;
	char		**path;
	int			id;

	path = NULL;
	if ((id = ft_searchenv("PATH=")) < 0)
		return (ft_putendl_fd("ft_relativepath_bin: Bin not found", 2));
	if (!(env = ft_strsub(g_environ[id], 5, ft_strlen(g_environ[id]))))
		return (ft_putendl_fd("ft_strsub : return null", 2));
	if (!(path = (char**)ft_strsplit(env, ':')))
		return (ft_putendl_fd("strplit: return null", 2));
	ft_search_good_abs_path(path, token);
	ft_strdel(&env);
	ft_arraydel_2d(path, 0);
}

void		ft_identification_bin(char **token)
{
	if (ft_strchr(*token, '/') == 0)
		ft_relativepath_bin(token);
	else
		ft_absolutepath_bin(*token, token);
}
