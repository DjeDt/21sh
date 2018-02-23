/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/23 18:55:03 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static int		check_input(char **input)
{
	char	**tmp;

	tmp = NULL;
	if ((ft_count_char(input[1], '=') != 1))
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	tmp = ft_strsplit(input[1], '=');
	if (ft_arraysize_2d(&tmp) != 2)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		ft_arraydel_2d(tmp, 0);
		return (-1);
	}
	ft_arraydel_2d(tmp, 0);
	return (0);
}

static void		array_add_one(char **input)
{
	size_t		count;
	char		**new;

	count = 0;
	new = NULL;
	if (!(new = (char**)malloc(sizeof(char*) \
							* (ft_arraysize_2d(&g_environ) + 2))))
		ft_error_malloc("builtin_setenv->array_add_one : error malloc");
	while (g_environ[count] != NULL)
	{
		new[count] = g_environ[count];
		count++;
	}
	new[count] = ft_strdup(input[1]);
	new[++count] = NULL;
	free(g_environ);
	g_environ = new;
}

void			ft_setenv(char **input)
{
	int		count;
	int		len;

	if ((input == NULL) || (check_input(input) != 0))
		return ;
	count = 0;
	len = ft_strnlen(input[1], '=');
	while (g_environ[count] != NULL)
	{
		if (ft_strncmp(input[1], g_environ[count], len) == 0)
		{
			ft_strdel(&g_environ[count]);
			g_environ[count] = ft_strdup(input[1]);
			return ;
		}
		count++;
	}
	array_add_one(input);
}
