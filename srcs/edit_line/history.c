/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:44:33 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/23 14:19:55 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		save_current_buf(t_line *line)
{
	if (line->buf_hist != NULL)
		ft_strdel(&line->buf_hist);
	line->buf_hist = ft_strdup(line->buf);
}

void		maj_hist(t_line *line)
{
	line->fd_hist = open(OPEN_HIST);
	if (line->fd_hist == -1)
		return ;
	if (g_line && g_line[0] != '\0' && ft_strlen(g_line) > 0)
		ft_putendl_fd(g_line, line->fd_hist);
	close(line->fd_hist);
	if (line->hist != NULL)
		free_hist(&line->hist);
	if (line && line->buf_hist != NULL)
		ft_strdel(&line->buf_hist);
}

static void	put_in_buf(const char *str, int *i, t_line *line)
{
	int	len;

	len = ft_strlen(str);
	ft_go_begin(line);
	ft_putstr("\033[J");
	ft_bzero(&(g_line[g_lstruct.cur]), (g_lstruct.lmax - g_lstruct.cur));
	while (((*i) + len) >= line->lmax)
		ft_realloc_line(line);
	while (str && str[line->cur] != '\0')
	{
		g_line[line->cur] = str[line->cur];
		line->cur += 1;
	}
	(*i) = line->cur;
	ft_putstr(g_line);
}

int			history_up(t_line *line, int *i, t_hist **hist)
{
	t_hist	*tmp;

	if (*hist == NULL)
		return (-1);
	tmp = *hist;
	if (line->cur_hist > 0)
		line->cur_hist -= 1;
	while (tmp->next != NULL)
	{
		if (line->cur_hist == tmp->cur)
			break ;
		tmp = tmp->next;
	}
	put_in_buf(tmp->value, i, line);
	return (0);
}

int			history_down(t_line *line, int *i, t_hist **hist)
{
	t_hist	*tmp;

	if (*hist == NULL)
		return (-1);
	tmp = (*hist);
	if (line->cur_hist < line->max_hist)
		line->cur_hist += 1;
	while (tmp->next != NULL)
	{
		if (line->cur_hist == tmp->cur)
			break ;
		tmp = tmp->next;
	}
	if (line->cur_hist > tmp->cur)
		put_in_buf("", i, line);
	else
		put_in_buf(tmp->value, i, line);
	return (0);
}
