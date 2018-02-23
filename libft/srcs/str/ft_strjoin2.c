/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:42:04 by tribeiro          #+#    #+#             */
/*   Updated: 2016/12/09 14:46:57 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin2(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, *s2);
	free(*s2);
	*s2 = NULL;
	return (tmp);
}
