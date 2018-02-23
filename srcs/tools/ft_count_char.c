/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:16:58 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/18 19:42:30 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(const char *str, const char c)
{
	int ret;
	int count;

	ret = 0;
	count = -1;
	if (str == NULL)
		return (-1);
	while (str[++count] != '\0')
		str[count] == c ? ret++ : 0;
	return (ret);
}
