/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:29:19 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:29:34 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_binary(void *data, size_t size)
{
	int		i;

	i = 0;
	while (size--)
	{
		i = 0;
		while (i < 8)
		{
			if (*((char*)data + size) & (128 >> i))
				ft_putchar('1');
			else
				ft_putchar('0');
			i++;
		}
		ft_putchar(' ');
	}
}
