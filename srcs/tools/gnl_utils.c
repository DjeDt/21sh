/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:01:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/16 17:08:10 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		malloc_error2(const char *str, const int ret)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": malloc error, abort prog", 2);
	exit(ret);
}

size_t		ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strnlen(const char *str, char c)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
	while ((str[count] != '\0') && (str[count] != c))
		count++;
	return (count);
}

char		*ft_strfsub2(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (s != NULL)
	{
		if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
			malloc_error2("error in func strfsub", -1);
		while (i < len && s[start])
		{
			ret[i] = s[start];
			i++;
			start++;
		}
		ret[i] = '\0';
		ft_strdel(&s);
	}
	return (ret);
}

char		*ft_strjoin_fl2(char *s1, const char *s2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (ret);
}
