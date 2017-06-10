/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:55:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:42:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static	int	prog_check(const char *path, char **tmp_arg, char **tmp_env)
{
	int		ret;
	pid_t	child;

	ret = 0;
	if (access(path, F_OK) == 0)
	{
		child = fork();
		if (child == 0)
		{
			ret = execve(path, tmp_arg, tmp_env);
			exit(1);
		}
		wait(&child);
	}
	else
		return (-1);
	return (ret);
}

static int	prog_env(const char *prog, char **arg, char **env, char **path)
{
	int		ret;
	int		count;
	char	*tmp;

	ret = -1;
	if (prog == NULL)
		return (ret);
	if (ft_strchr(prog, '/') != NULL)
		ret = prog_check(prog, arg, env);
	else
	{
		count = -1;
		while (path != NULL && path[++count] != NULL)
		{
			tmp = ft_strjoin(path[count], "/");
			tmp = ft_strjoin_fl(tmp, prog);
			ret = prog_check(tmp, arg, env);
			ft_strdel(&tmp);
			if (ret == 0)
				break ;
		}
	}
	ret < 0 ? bin_error(prog) : 0;
	return (ret);
}

int			env_no_arg(const char **input, char **path)
{
	int		count;
	char	**tmp_env;
	char	**tmp_add;

	count = 0;
	tmp_env = NULL;
	tmp_env = ft_arrdup((const char **)g_env);
	while (input[count] != NULL)
	{
		if (ft_strchr(input[count], '=') == NULL)
			break ;
		count++;
	}
	tmp_add = ft_arrldup(input, count);
	tmp_env = ft_arrfjoin(tmp_env, tmp_add);
	tmp_add != NULL ? ft_arrfree(&tmp_add) : NULL;
	if (input[count] != NULL)
		prog_env(input[count], (char**)input + count, tmp_env, path);
	else
		ft_arrprint((const char **)tmp_env);
	tmp_env != NULL ? ft_arrfree(&tmp_env) : NULL;
	return (0);
}
