/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:07:41 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/15 17:06:35 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_char(char *tab, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (((new = (char*)malloc(sizeof(char) * len + 1)) == NULL) || (len == 0))
		return (tab);
	ft_bzero(new, len);
	while (tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	ft_strdel(&tab);
	return (new);
}
