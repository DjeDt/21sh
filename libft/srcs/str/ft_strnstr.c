/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:30 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/12 22:15:36 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	if (!*to_find)
		return ((char *)s);
	while (i < len && s[i])
	{
		while (s[i + y] == to_find[y] && (i <= len))
		{
			if (ft_strlen(to_find) + i > len)
				return (NULL);
			if (to_find[y + 1] == '\0' && (i <= len))
				return ((char *)s + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
