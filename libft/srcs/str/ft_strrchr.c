/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:09:02 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/16 18:05:02 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		len;

	s1 = (char *)s;
	len = ft_strlen(s);
	if (c == '\0')
		return (&s1[len]);
	while (len >= 0)
	{
		if (s1[len] == c)
			return (&s1[len]);
		len--;
	}
	return (0);
}
