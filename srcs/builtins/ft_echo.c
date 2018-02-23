/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:01 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/08 18:55:44 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static int	ft_search_echo(char *argv)
{
	int		pos;
	int		id;

	pos = ft_strlen(argv);
	id = 0;
	while (g_environ[id] != 0)
	{
		if (ft_strncmp(argv, g_environ[id], pos) == 0)
			return (id);
		id++;
	}
	return (-1);
}

static void	ft_printenv(char *name)
{
	int		id;
	int		size;
	char	*buf;
	char	*result;

	buf = NULL;
	result = NULL;
	size = ft_strlen(name);
	buf = ft_strsub(name, 1, size);
	id = ft_search_echo(buf);
	if (id >= 0)
	{
		result = ft_strsub(g_environ[id], size, ft_strlen(g_environ[id]));
		ft_putstr(result);
		free(result);
	}
	free(buf);
}

static int	ft_echo_option(char *s)
{
	if ((ft_strcmp(s, "--")) == 0)
		return (-1);
	if ((ft_strcmp(s, "-n")) == 0)
		return (1);
	return (0);
}

void		ft_echo(char **argv)
{
	int		option;
	int		i;
	int		y;

	option = -1;
	i = 1;
	y = 0;
	if (argv[i])
		if ((ft_strncmp("-", argv[i], 1)) == 0)
			if ((option = ft_echo_option(argv[i])) >= 0)
				y++;
	while (argv[i + y])
	{
		if (ft_strncmp(argv[i + y], "$", 1) == 0)
			ft_printenv(argv[i + y]);
		else
		{
			ft_putstr(argv[i + y]);
			if (argv[i + y + 1])
				ft_putchar(' ');
		}
		i++;
	}
	if (option == -1)
		write(1, "\n", 1);
}
