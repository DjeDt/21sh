/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/23 18:56:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static int		check_input(char **input)
{
	if (ft_arraysize_2d(&input) != 2 || (ft_count_char(input[1], '=') != 0))
	{
		ft_putendl(UNSETENV_USAGE);
		return (-1);
	}
	return (0);
}

static void		ft_new(char **rm)
{
	size_t		len;

	len = 0;
	while (rm[len] != NULL)
		++len;
	free(*rm);
	ft_memcpy(rm, rm + 1, len * sizeof(*rm));
}

void			ft_unsetenv(char **input)
{
	int		count;
	int		len;

	if (check_input(input) != 0)
		return ;
	count = 0;
	len = ft_strlen(input[1]);
	while (g_environ[count] != NULL)
	{
		if (ft_strncmp(g_environ[count], input[1], len) == 0)
			ft_new(g_environ + count);
		count++;
	}
}
