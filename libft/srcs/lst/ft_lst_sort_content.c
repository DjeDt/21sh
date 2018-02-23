/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:54:44 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:27:58 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_sort(t_list **lst, int (*cmp)())
{
	t_list		*begin_lst;
	t_list		*elem;
	t_list		*swap;

	if (!(*lst))
		(*lst) = NULL;
	begin_lst = *lst;
	while (*lst != NULL)
	{
		elem = begin_lst;
		while (elem->next)
		{
			if (cmp(elem->content, elem->next->content) > 0)
			{
				swap = elem->content;
				elem->content = elem->next->content;
				elem->next->content = swap;
			}
			elem = elem->next;
		}
		*lst = (*lst)->next;
	}
	*lst = begin_lst;
}
