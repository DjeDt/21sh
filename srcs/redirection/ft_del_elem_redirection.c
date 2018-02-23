/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:51:16 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 13:07:58 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_del_elem_redirection(t_r **r, int mode)
{
	if (!(*r))
		return ;
	if (mode == 1)
	{
		ft_putendl("FILE FREE");
		if ((*r)->file != NULL)
		{
			ft_putstr("\nfile {");
			ft_putstr((*r)->file);
			ft_putendl("}");
			ft_putstr("addr {");
			ft_putaddr((*r)->file);
			ft_putendl("}");
		}
		ft_putendl("DONE");
	}
	if ((*r)->file)
		ft_strdel(&((*r)->file));
	free(*r);
	r = NULL;
}
