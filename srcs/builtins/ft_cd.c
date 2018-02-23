/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:10:17 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 13:54:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_setpwd(void)
{
	int		id;
	char	*cwd;
	char	*buf;
	char	**pwd;

	buf = NULL;
	cwd = getcwd(buf, 0);
	if ((id = ft_search("PWD")) < 0)
	{
		buf = ft_strdup("PWD= ");
		pwd = ft_strsplit(buf, ' ');
		ft_setenv(pwd);
		free(buf);
		ft_arraydel_2d(pwd, 0);
	}
	else
	{
		ft_strdel(&g_environ[id]);
		if ((buf = ft_strdup("PWD=")) != NULL)
			g_environ[id] = ft_strmerge(&buf, &cwd);
	}
	ft_strdel(&cwd);
}

void			ft_setoldpwd(void)
{
	int		id;
	char	*cwd;
	char	*buf;
	char	**oldpwd;

	buf = NULL;
	cwd = getcwd(buf, 0);
	if ((id = ft_search("OLDPWD")) < 0)
	{
		buf = ft_strdup("OLDPWD= ");
		oldpwd = ft_strsplit(buf, ' ');
		ft_setenv(oldpwd);
		free(buf);
		ft_arraydel_2d(oldpwd, 0);
	}
	else
	{
		ft_strdel(&g_environ[id]);
		if ((buf = ft_strdup("OLDPWD=")) != NULL)
			g_environ[id] = ft_strmerge(&buf, &cwd);
	}
	ft_strdel(&cwd);
}

static void		ft_cd_oldpwd(char **argv)
{
	int		ret;
	int		id;
	char	*cwd;
	char	*buf;

	buf = NULL;
	cwd = getcwd(buf, 0);
	if ((id = ft_search("OLDPWD")) < 0)
		ft_oldpwdnotset();
	else
	{
		buf = ft_strsub(g_environ[id], 7, (ft_strlen(g_environ[id]) - 1));
		if ((ret = chdir(buf)) < 0)
			ft_error_chdir("OLDPWD");
		free(g_environ[id]);
		free(buf);
		buf = ft_strdup("OLDPWD=");
		g_environ[id] = ft_strmerge(&buf, &cwd);
		free(buf);
		ft_pwd(argv);
	}
	ft_setpwd();
	ft_strdel(&cwd);
}

static void		ft_cd_home(void)
{
	int		ret;
	int		id;
	char	*buf;

	buf = NULL;
	ft_setoldpwd();
	if ((id = ft_search("HOME")) < 0)
		ft_putendl_fd("minishell: cd: HOME NOT SET", 2);
	else
	{
		buf = ft_strsub(g_environ[id], 5, (ft_strlen(g_environ[id]) - 1));
		if ((ret = chdir(buf)) < 0)
			ft_error_chdir("HOME");
		ft_strdel(&buf);
		ft_setpwd();
	}
}

void			ft_cd(char **argv)
{
	int		ret;
	int		size;

	if ((size = ft_arraysize_2d(&argv)) > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return ;
	}
	if (size > 1)
		argv++;
	if (ft_strcmp(*argv, "-") == 0)
		ft_cd_oldpwd(argv);
	else if ((ft_strcmp(*argv, "--") == 0) || size == 1)
		ft_cd_home();
	else
	{
		ft_setoldpwd();
		if ((ret = chdir(*argv)) < 0)
			ft_error_chdir(*argv);
		ft_setpwd();
	}
}
