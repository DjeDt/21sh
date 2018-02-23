/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:55:19 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 11:54:07 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_del_list_redirection(t_r **r, int mode)
{
	t_r		*l;

	l = NULL;
	while ((*r) != NULL)
	{
		l = (*r)->next;
		ft_del_elem_redirection(r, mode);
		(*r) = l;
	}
}
