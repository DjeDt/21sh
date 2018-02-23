/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:28:09 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:28:31 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data, size_t size)
{
	t_list		*ptr;

	ptr = NULL;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data, size);
	else
	{
		ptr = (*begin_list);
		while (ptr->next != 0)
			ptr = ptr->next;
		ptr->next = ft_create_elem(data, size);
	}
}
