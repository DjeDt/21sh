/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:22:26 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/10 17:49:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void			ft_init_tline(t_line *l)
{
	ioctl(0, TIOCGWINSZ, &(l->w));
	l->cur = 0;
	l->lmax = 256;
	if (!(g_line = (char*)malloc(l->lmax)))
		ft_read_fail(NULL, "shell: malloc fail -> line buffer");
	ft_bzero(g_line, l->lmax);
	l->buf = NULL;
	l->prompt_size = 5;
	l->hist = NULL;
	l->buf_hist = NULL;
	l->max_hist = 0;
	l->cur_hist = 0;
	l->fd_hist = open(OPEN_HIST);
	close(l->fd_hist);
}

void			ft_realloc_line(t_line *l)
{
	g_line = ft_realloc_char(g_line, l->lmax + 256);
	l->lmax += 255;
	if (g_line == NULL)
		ft_read_fail(&(g_line), "shell: NULL -> read_line");
	ft_bzero(&(g_line[l->cur]), (l->lmax - l->cur));
}

void			reset_pos(int i)
{
	while (--i > 0)
		ft_putstr("\033[1D");
}
