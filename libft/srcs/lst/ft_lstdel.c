/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:32:55 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/14 20:45:43 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**cp;
	t_list	*elem;

	cp = alst;
	elem = NULL;
	while (*cp)
	{
		del((*cp)->content, (*cp)->content_size);
		elem = (*cp)->next;
		free(*cp);
		*cp = elem;
	}
}
