/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:32:06 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/31 12:46:04 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_atl(char ***array)
{
	t_list		*begin_list;
	char		**tmp;

	begin_list = NULL;
	tmp = *array;
	while (*array && **array)
	{
		ft_list_push_back(&begin_list, **array, ft_strlen(**array));
		(*array)++;
	}
	*array = tmp;
	return (begin_list);
}
