/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:01:05 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/14 20:47:50 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*d;
	void	*ncontent;

	if (!(d = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if ((void*)content && content_size > 0)
	{
		if (!(ncontent = (void *)malloc(sizeof(void))))
			return (NULL);
		d->content_size = content_size;
		while (content_size--)
			*(unsigned char *)ncontent++ = *(unsigned char *)content++;
		d->content = ncontent - d->content_size;
	}
	else
	{
		d->content = NULL;
		d->content_size = 0;
	}
	d->next = NULL;
	return (d);
}
