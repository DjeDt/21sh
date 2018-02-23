/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:25:57 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/18 19:26:56 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t		ft_strnlen(const char *str, char c)
{
	size_t count;

	count = 0;
	if (str == NULL)
		return (0);
	while ((str[count] != '\0') && (str[count] != c))
		count++;
	return (count);
}
