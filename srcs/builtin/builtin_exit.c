/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:12:56 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:42:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int	exit_error(const char *error)
{
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

static int	check_input(const char *input)
{
	int count;

	count = -1;
	while (input[++count] != '\0')
	{
		if (input[0] && input[0] == '-')
			continue ;
		else if (ft_isdigit(input[count]) != 1)
		{
			ft_putchar_fd('\'', 2);
			ft_putchar_fd(input[count], 2);
			return (exit_error("\': error: only numbers are allowed"));
		}
	}
	return (0);
}

int			ft_exit(const char **input)
{
	int ret;

	if (ft_arrlen(input) > 2)
		return (exit_error(EXIT_USAGE));
	if (ft_arrlen(input) == 1)
	{
		ft_arrfree((char ***)&input);
		ft_arrfree(&g_env);
		exit(0);
	}
	if (check_input(input[1]) != 0)
		return (-1);
	ret = ft_atoi(input[1]);
	ft_arrfree((char ***)&input);
	ft_arrfree(&g_env);
	exit(ret);
}
