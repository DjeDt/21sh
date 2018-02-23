/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:59:09 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/12 22:13:52 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	d = 0;
	while (dst[d] && d < size)
		d++;
	s = d;
	while (src[d - s] && d < size - 1)
	{
		dst[d] = src[d - s];
		d++;
	}
	if (s < size)
		dst[d] = '\0';
	return (s + ft_strlen((char*)src));
}
