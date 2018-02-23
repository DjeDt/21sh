/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:32:47 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/21 21:10:13 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_envdup(void)
{
	extern char		**environ;
	int				size;
	char			**tmp;

	g_environ = environ;
	size = ft_arraysize_2d(&g_environ);
	if (!(tmp = (char**)malloc(sizeof(char*) * (size + 1))))
	{
		ft_putendl_fd("Malloc fail -> array tmp", 2);
		exit(1);
	}
	tmp[size] = NULL;
	while (size--)
		tmp[size] = ft_strdup(g_environ[size]);
	g_environ = tmp;
}
