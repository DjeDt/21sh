/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:33:21 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:26:00 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenword(int n, int base)
{
	int		lw;

	lw = 1;
	while (n /= base)
		lw++;
	return (lw);
}

char			*ft_itoa_base(int n, int base)
{
	char	*dest;
	int		len;

	dest = NULL;
	len = ft_lenword(n, base);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len + 1] = '\0';
	while (len--)
	{
		dest[len] = BASE[(n % base)];
		n /= base;
	}
	return (dest);
}
