/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 03:53:13 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/08 17:16:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*ptr;
	size_t	i;

	i = 0;
	dst = NULL;
	ptr = NULL;
	if (s && start < len)
	{
		if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ptr = dst;
		while (i < len && s[start + i])
		{
			ptr[i] = s[start + i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (dst);
}
