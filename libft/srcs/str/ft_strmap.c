/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:36:15 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/16 18:04:36 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cp;
	char	*dst;
	int		i;

	i = 0;
	if (s)
	{
		cp = (char *)s;
		if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (cp[i])
		{
			dst[i] = f(cp[i]);
			i++;
		}
		dst[i] = 0;
		return (dst);
	}
	return (NULL);
}
