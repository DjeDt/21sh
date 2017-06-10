/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:42:29 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	arg_check(const char **input)
{
	int				count;
	int				count2;
	unsigned int	flags;
	char			*mask;

	count = 0;
	flags = 0;
	mask = ft_strdup("i");
	while (input[++count] && input[count][0] == '-')
	{
		count2 = 1;
		while (input[count][count2] != '\0' && input[count][0] == '-')
		{
			if (ft_strchr(mask, input[count][count2]) != NULL)
				flags |= (1 << (ft_strchr(mask, input[count][count2]) - mask));
			else
			{
				ft_memdel((void*)&mask);
				return (arg_error("env", ENV_USAGE, input[count][count2]));
			}
			count2++;
		}
	}
	ft_memdel((void*)&mask);
	return (flags);
}

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

static int	env_option_i(const char **input, char **path)
{
	int		count;
	char	**tmp_env;
	char	**tmp_arg;

	count = 0;
	tmp_env = NULL;
	tmp_arg = NULL;
	while (input[count] != NULL && (ft_strchr(input[count], '=') != NULL))
		count++;
	tmp_env = ft_arrldup(input, count);
	tmp_arg = ft_arrdup(input + count);
	if (tmp_arg == NULL || ft_arrlen((const char **)tmp_arg) < 1)
		ft_arrprint((const char **)tmp_env);
	else
		prog_env(input[count], tmp_arg, tmp_env, path);
	ft_arrfree(&tmp_env);
	ft_arrfree(&tmp_arg);
	return (0);
}

int			ft_env(const char **input)
{
	int		flags;
	char	**path;

	if (ft_arrlen(input) == 1)
		ft_arrprint((const char **)g_env);
	else
	{
		if ((flags = arg_check(input)) == -1)
			return (-1);
		path = ft_strsplit(get_var_value("PATH"), ':');
		if (flags & FLAG_1)
			env_option_i(input + 2, path);
		else if (ft_strchr(input[1], '=') != NULL)
			env_no_arg(input + 1, path);
		else
			ft_launch_prog(input + 1);
		path != NULL ? ft_arrfree(&path) : NULL;
	}
	return (0);
}
