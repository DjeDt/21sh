/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:13:45 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/23 13:28:43 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <sys/stat.h>

int		file_error(t_r *elem, int error)
{
	if (error == 1)
	{
		ft_putstr_fd("error: ", 2);
		ft_putstr_fd(elem->file, 2);
		ft_putendl_fd(": is a directory", 2);
	}
	return (-1);
}

int		check_file(t_r *elem)
{
	struct stat st;

	if (stat(elem->file, &st) > -1)
	{
		if (st.st_mode & S_IFMT)
		{
			if (st.st_mode & S_IFDIR)
				return (file_error(elem, 1));
		}
	}
	return (0);
}
