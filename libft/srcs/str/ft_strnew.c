/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:16 by tribeiro          #+#    #+#             */
/*   Updated: 2016/11/12 22:15:26 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(dest, size + 1);
	return (dest);
}
