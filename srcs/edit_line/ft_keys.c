/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:16:34 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/14 19:06:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_addchar(int *i, t_line *l, char tmp)
{
	char	*end;

	end = NULL;
	ft_putstr("\033[K");
	if ((end = ft_strdup(&(g_line[l->cur]))) == NULL)
		ft_error_line(l);
	ft_bzero((&g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
	g_line[l->cur] = tmp;
	ft_strcpy(&(g_line[l->cur + 1]), end);
	ft_strdel(&end);
	ft_putstr(g_line + l->cur);
	if (l->cur != *i)
		reset_pos(ft_strlen(&(g_line[l->cur])));
	l->cur += 1;
	*i += 1;
}

void		ft_delchar(t_line *l, int *i)
{
	char		*end;

	end = NULL;
	if (l->cur > 0)
	{
		*i -= 1;
		ft_putstr("\033[1D");
		ft_putstr("\033[K");
		if ((end = ft_strdup(&(g_line[l->cur]))) == NULL)
			ft_error_line(l);
		l->cur -= 1;
		ft_bzero((&g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		ft_strcpy(&(g_line[l->cur]), end);
		ft_strdel(&end);
		write(1, &(g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		if (l->cur != *i)
			reset_pos(ft_strlen(&(g_line[l->cur])) + 1);
	}
}

void		ft_delchar_rev(t_line *l, int *i)
{
	char		*end;

	end = NULL;
	if (l->cur < *i && *i > 0)
	{
		*i -= 1;
		ft_putstr("\033[J");
		if ((end = ft_strdup(&(g_line[l->cur + 1]))) == NULL)
			ft_error_line(l);
		ft_bzero((&g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		ft_strcpy(&(g_line[l->cur]), end);
		ft_strdel(&end);
		write(1, &(g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		if (l->cur != *i)
			reset_pos(ft_strlen(&(g_line[l->cur])) + 1);
	}
}

void		ft_go_begin(t_line *l)
{
	while (l->cur)
		ft_left_arrow(l);
}

void		ft_go_end(t_line *l, int i)
{
	while (l->cur < i)
		ft_right_arrow(l);
}
