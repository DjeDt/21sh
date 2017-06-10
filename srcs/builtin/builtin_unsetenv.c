/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:09:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:43:10 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static	int		check_input(const char **input)
{
	if (ft_arrlen(input) != 2 || (ft_count_char(input[1], '=') != 0))
	{
		ft_putendl(UNSETENV_USAGE);
		return (-1);
	}
	return (0);
}

static void		ft_new(char **rm)
{
	size_t	len;

	len = 0;
	while (rm[len] != NULL)
		++len;
	free(*rm);
	ft_memcpy(rm, rm + 1, len * sizeof(*rm));
}

int				ft_unsetenv(const char **input)
{
	int		count;
	int		len;

	if (check_input(input) != 0)
		return (-1);
	count = 0;
	len = ft_strlen(input[1]);
	while (g_env[count] != NULL)
	{
		if (ft_strncmp(g_env[count], input[1], len) == 0)
		{
			ft_new(g_env + count);
			return (0);
		}
		count++;
	}
	return (0);
}
