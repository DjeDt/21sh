/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/16 20:28:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static	int		nbr_mots(const char *str, char c)
{
	int i;
	int nombremot;

	i = 0;
	nombremot = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			nombremot++;
			while ((str[i] != '\0') && (str[i] != c))
				i++;
		}
	}
	return (nombremot);
}

char			**split_line(const char *s, char c)
{
	int		i;
	int		j;
	int		taille;
	int		nbmot;
	char	**ret;

	i = 0;
	j = -1;
	taille = 0;
	if (s == NULL)
		return (NULL);
	nbmot = nbr_mots(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * nbmot + 1)))
		return (NULL);
	while (++j < nbmot)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		taille = ft_strnlen(s + i, c);
		ret[j] = ft_strndup(s + i, taille);
		i += taille;
	}
	ret[j] = NULL;
	return (ret);
}

char	**parse_input(char *line)
{
	char **ret;

	ret = NULL;
	if (line == NULL)
		return (NULL);
	else
	{
		ret = split_line(line, ';');
		free(line);
	}
	return (ret);
}
