/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_replace_blank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 22:17:28 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/15 15:33:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** statut : 0 = char normal
** statut : 1 = in_SQUOTE -> '  39
** statut : 2 = IN_DQUOTE -> "  34
*/

void		in_squote(char **s, int *count, int *count2, int *statut)
{
	if ((*s)[(*count)] == 39)
	{
		(*s)[(*count2)++] = (*s)[++(*count)];
		*statut = 0;
	}
	else
		(*s)[(*count2)++] = (*s)[(*count)];
}

void		in_dquote(char **s, int *count, int *count2, int *statut)
{
	if ((*s)[(*count)] == 34)
	{
		(*s)[(*count2)++] = (*s)[++(*count)];
		*statut = 0;
	}
	else
		(*s)[(*count2)++] = (*s)[(*count)];
}

void		is_quote_or_not(char **s, int *count, int *count2, int *statut)
{
	if ((*s)[(*count)] == 39)
	{
		*statut = 1;
		(*s)[(*count2)++] = (*s)[++(*count)];
	}
	else if ((*s)[(*count)] == 34)
	{
		*statut = 2;
		(*s)[(*count2)++] = (*s)[++(*count)];
	}
	else
		(*s)[(*count2)++] = (*s)[(*count)];
}

int			ft_replace(char **s, int *statut)
{
	int		count;
	int		count2;

	count = -1;
	count2 = 0;
	while ((*s)[++count] != '\0')
	{
		if ((*statut) == 0)
			is_quote_or_not(s, &count, &count2, statut);
		else if ((*statut) == 1)
			in_squote(s, &count, &count2, statut);
		else if ((*statut) == 2)
			in_dquote(s, &count, &count2, statut);
		if ((*s)[count] == '\0')
			break ;
	}
	(*s)[count2] = '\0';
	if ((*statut) != 0)
		if (add_missing_char(s, statut) == -1)
			return (-1);
	return (0);
}

int			ft_quote_replace_blank(char **argv)
{
	int	i;
	int	ret;
	int	statut;

	i = 0;
	ret = 1;
	while (argv[i] != NULL)
	{
		statut = 0;
		if (ft_replace(&argv[i], &statut) == -1)
			return (-1);
		i++;
	}
	return (0);
}
