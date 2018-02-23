/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttrrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:16:29 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/16 20:12:21 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		delimiteur(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	if (s)
	{
		i = 0;
		k = 0;
		j = ft_strlen(s);
		if (!(*s))
			return ((char*)s);
		while (delimiteur(s[i]))
			i++;
		while (delimiteur(s[j]))
			j--;
		if (i >= j)
			return (ft_strnew(0));
		if (!(ret = (char*)malloc(sizeof(char) * (j - i) + 2)))
			return (NULL);
		while (i <= j)
			ret[k++] = s[i++];
		ret[k] = '\0';
	}
	return ((s) ? ret : NULL);
}
