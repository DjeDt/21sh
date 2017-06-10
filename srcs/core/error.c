/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:45:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:41:21 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	malloc_error(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": Error malloc, abort prog", 2);
	exit(ret);
}

int		arg_error(char *str, char *usage, char c)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": option invalide -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(usage, 2);
	return (-1);
}

int		dir_error(const char *error, const char *file)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

void	bin_error(const char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": no such file or directory", 2);
}
