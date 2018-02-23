/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:46:03 by tribeiro          #+#    #+#             */
/*   Updated: 2017/02/02 10:37:06 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arraydel_2d(char **array, int mode)
{
	int			i;

	i = 0;
	while (array && array[i])
	{
		if (mode)
		{
			ft_putstr("FREE ->");
			ft_putendl(array[i]);
		}
		ft_strdel(&(array[i]));
		i++;
	}
	free(array);
	if (mode)
		ft_putendl("PTR FREE AND NOT NULL");
}
