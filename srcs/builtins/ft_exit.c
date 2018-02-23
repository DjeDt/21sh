/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:07:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/23 20:49:05 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

void			ft_exit(char **argv)
{
	if (ft_arraysize_2d(&argv) < 2)
	{
		ft_arraydel_2d(g_environ, 0);
		free_readline(&g_lstruct);
		exit(0);
	}
	if (ft_isdigit(*argv[1]))
	{
		ft_arraydel_2d(g_environ, 0);
		free_readline(&g_lstruct);
		exit(ft_atoi(argv[1]));
	}
	ft_putendl_fd("exit: numeric argument required", 2);
	exit(-1);
}
