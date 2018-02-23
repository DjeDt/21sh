/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_array2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:49:57 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/21 16:47:21 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_array2d(char ***array)
{
	char	**tmp;

	tmp = *array;
	while (*array && **array)
	{
		ft_putendl(**array);
		(*array)++;
	}
	*array = tmp;
}
