/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:36:25 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/24 13:41:20 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_push_back_redirection(t_r **begin_list, t_r *elem)
{
	t_r		*ptr;

	ptr = NULL;
	if (!(*begin_list))
		*begin_list = elem;
	else
	{
		ptr = (*begin_list);
		while (ptr->next != 0)
			ptr = ptr->next;
		ptr->next = elem;
	}
}
