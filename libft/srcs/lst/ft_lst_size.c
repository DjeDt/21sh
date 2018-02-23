/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:07:41 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/15 17:06:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_size(t_list *list)
{
	int		s;
	t_list	*begin;

	s = 0;
	if (list == NULL)
		return (0);
	begin = list;
	while (list != NULL)
	{
		s++;
		list = list->next;
	}
	list = begin;
	return (s);
}
