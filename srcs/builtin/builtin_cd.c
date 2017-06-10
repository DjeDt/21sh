/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:42:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	new_oldpwd(void)
{
	char	*tmp[3];
	char	act_p[256];
	char	*value_add;

	getcwd(act_p, sizeof(act_p));
	value_add = ft_strjoin("OLDPWD=", act_p);
	tmp[0] = "setenv";
	tmp[1] = value_add;
	tmp[2] = NULL;
	ft_setenv((const char **)tmp);
	ft_strdel(&value_add);
}

static void	new_pwd(void)
{
	char	*tmp[3];
	char	act_p[256];
	char	*value_add;

	getcwd(act_p, sizeof(act_p));
	value_add = ft_strjoin("PWD=", act_p);
	tmp[0] = "setenv";
	tmp[1] = value_add;
	tmp[2] = NULL;
	ft_setenv((const char **)tmp);
	ft_strdel(&value_add);
}

static int	move_dir(const char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0)
		{
			new_oldpwd();
			if (chdir(path) == -1)
				return (dir_error("cd: is not a directory: ", path));
			new_pwd();
		}
		else
			return (dir_error("cd: permission denied: ", path));
	}
	else
		return (dir_error("cd: no such file or directory: ", path));
	return (0);
}

int			ft_cd(const char **input)
{
	int ret;

	ret = 0;
	if (ft_arrlen(input) > 2)
	{
		ft_putendl_fd(CD_USAGE, 2);
		return (-1);
	}
	if (ft_arrlen(input) == 1)
		ret = move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "~") == 0 || ft_strcmp(input[1], "--") == 0)
		ret = move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "-") == 0)
	{
		ft_putendl(get_var_value("OLDPWD"));
		ret = move_dir(get_var_value("OLDPWD"));
	}
	else
		ret = move_dir(input[1]);
	return (ret);
}
