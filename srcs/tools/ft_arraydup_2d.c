/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:04:45 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/23 19:04:48 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		**ft_arrdup(char **array)
{
	int		count;
	char	**ret;

	count = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * ft_arraysize_2d(&array) + 1)))
		ft_error_malloc("error in func arrdup");
	while (array[count] != NULL)
	{
		ret[count] = ft_strdup(array[count]);
		count++;
	}
	ret[count] = NULL;
	return (ret);
}
