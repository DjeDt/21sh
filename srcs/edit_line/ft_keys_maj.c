/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcuts_keyboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:40:54 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 14:34:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_maj_keys(t_line *l, int *i, char tmp)
{
	read(0, &tmp, 1);
	read(0, &tmp, 1);
	read(0, &tmp, 1);
	if (tmp == 'A')
		ft_maj_top_arrow(l);
	if (tmp == 'B')
		ft_maj_down_arrow(l, *i);
	if (tmp == 'C')
		ft_maj_right_arrow(l, *i);
	if (tmp == 'D')
		ft_maj_left_arrow(l);
}

void		ft_maj_left_arrow(t_line *l)
{
	if (l->cur > 0 && g_line[l->cur] == ' ')
	{
		while (l->cur > 0 && g_line[l->cur] == ' ')
			ft_left_arrow(l);
	}
	if (l->cur != 0 && (ft_isprint(g_line[l->cur]) || g_line[l->cur] == 0))
	{
		while (l->cur > 0 && g_line[l->cur] != ' ')
			ft_left_arrow(l);
	}
}

void		ft_maj_right_arrow(t_line *l, int i)
{
	if (l->cur != i && ft_isprint(g_line[l->cur]))
	{
		while (l->cur != i && g_line[l->cur] != ' ')
			ft_right_arrow(l);
	}
	if (l->cur != i && g_line[l->cur] == ' ')
	{
		while (l->cur != i && g_line[l->cur] == ' ')
			ft_right_arrow(l);
	}
}

void		ft_maj_top_arrow(t_line *l)
{
	int		i;

	if ((l->cur - l->w.ws_col) >= 0)
	{
		i = l->w.ws_col;
		while (i--)
			ft_left_arrow(l);
	}
}

void		ft_maj_down_arrow(t_line *l, int i)
{
	int		y;

	if ((l->cur + l->w.ws_col) <= i)
	{
		y = l->w.ws_col;
		while (y--)
			ft_right_arrow(l);
	}
}
