/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_missing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:31:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/15 15:31:55 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_decal_char(int rd, char **s)
{
	int		count;
	int		count2;
	char	ch;

	ch = 0;
	if (s != NULL && (*s) != NULL)
	{
		count = -1;
		count2 = 0;
		if (rd == RD_SQUOTE)
			ch = '\'';
		else if (rd == RD_DQUOTE)
			ch = '\"';
		while ((*s)[++count] != '\0')
		{
			while ((*s)[count2] == ch)
				count2++;
			(*s)[count] = (*s)[count2];
			count2++;
		}
		(*s)[count] = '\0';
	}
}

int		concat_str(int rd, int *statut)
{
	int ret;

	if (g_line != NULL)
		ft_strdel(&g_line);
	ft_putstr("$> ");
	ft_init_term();
	ret = ft_read_line(rd, statut);
	ft_default_term();
	return (ret);
}

int		add_missing_char(char **s, int *statut)
{
	int		rd;
	char	*swap;

	rd = 0;
	if (*statut == 1)
		rd = RD_SQUOTE;
	else if (*statut == 2)
		rd = RD_DQUOTE;
	while (*statut != 0)
	{
		if (concat_str(rd, statut) == -1)
			return (-1);
		swap = ft_strjoin("\n", g_line);
		ft_decal_char(rd, &swap);
		*s = ft_strjoin_1(s, swap);
		ft_strdel(&swap);
		if (g_line != NULL)
			ft_strdel(&g_line);
	}
	return (0);
}
