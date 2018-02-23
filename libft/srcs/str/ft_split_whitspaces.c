/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:22:08 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/15 17:07:19 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_delimitor(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static char		*ft_strncpy2(char *dest, char *src, unsigned int n)
{
	unsigned int	lenght;
	char			*x;

	x = dest;
	lenght = 0;
	while (src[lenght])
		lenght++;
	while (n--)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
	}
	*dest = '\0';
	return (x);
}

static int		strnbr_word(char *str)
{
	int		nbr_word;
	int		i;

	nbr_word = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0 && !(is_delimitor(str[i])))
			nbr_word++;
		if (is_delimitor(str[i - 1]) && !(is_delimitor(str[i])))
			nbr_word++;
		i++;
	}
	return (nbr_word);
}

static int		str_len(char *str)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (!(is_delimitor(str[i])) && str[i])
	{
		i++;
		size++;
	}
	return (size);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		i2;
	int		size;
	int		word;

	i = 0;
	i2 = 0;
	size = 0;
	word = strnbr_word(str);
	tab = (char**)malloc(sizeof(char*) * (word + 1));
	while (i2 < word)
	{
		while (is_delimitor(str[i]))
			i++;
		size = str_len(&str[i]);
		tab[i2] = (char*)malloc(sizeof(char) * size + 1);
		ft_strncpy2(tab[i2], str + i, size);
		i += size;
		i2++;
	}
	tab[i2] = 0;
	return (tab);
}
