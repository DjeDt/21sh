/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:31:10 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/12 22:14:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1);
	ptr = (char *)s2;
	while (n-- > 0 && *ptr)
	{
		s1[i] = *ptr;
		ptr++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
