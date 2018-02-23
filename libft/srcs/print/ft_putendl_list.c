/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:41:12 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/30 18:56:12 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_list(t_list **list)
{
	t_list		*begin_list;

	begin_list = NULL;
	begin_list = (*list);
	while (begin_list)
	{
		ft_putendl(begin_list->content);
		begin_list = begin_list->next;
	}
}
