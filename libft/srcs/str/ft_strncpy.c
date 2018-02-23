/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:54:31 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/12 22:14:59 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	l;
	size_t	i;

	s = (char *)src;
	d = dst;
	l = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		if (i > l)
			d[i] = '\0';
		else
			d[i] = s[i];
		i++;
	}
	return (dst);
}
