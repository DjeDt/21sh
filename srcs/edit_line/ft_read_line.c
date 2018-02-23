/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:45 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 14:48:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_refrech(t_line *l, int i)
{
	ioctl(0, TIOCGWINSZ, l->w);
	if (i == l->lmax)
		ft_realloc_line(l);
}

int			ft_end(t_line *l, char tmp)
{
	if (tmp == 10)
	{
		if (l && l->buf != NULL)
			ft_strdel(&(l->buf));
	}
	if (l)
		maj_hist(l);
	l = NULL;
	if (tmp == EOF || tmp == 2)
		return (-1);
	return (0);
}

void		analyse_char(char tmp, int *i)
{
	if (ft_isprint(tmp))
		ft_addchar(i, &g_lstruct, tmp);
	else if (tmp == 27)
		ft_keys_nav(&g_lstruct, i, tmp);
	else if (tmp == 127)
		ft_delchar(&g_lstruct, i);
	else
		ft_shortcuts_keyboard(&g_lstruct, i, tmp);
}

int			ft_read_line(int where, int *statut)
{
	int		i;
	char	tmp;

	i = 0;
	ft_init_tline(&g_lstruct);
	init_hist(&g_lstruct);
	save_pid(0);
	while (1)
	{
		ft_refrech(&g_lstruct, i);
		if ((read(0, &tmp, 1)) < 0)
			ft_read_fail(&g_line, "shell: read fail");
		if (ft_ctrl_d(&g_lstruct, &i, &tmp, where) == -1)
			break ;
		if (statut != NULL && check_special_case(where, tmp, statut) == -1)
			break ;
		if (tmp == 10 || tmp == 4 || tmp == EOF)
			break ;
		analyse_char(tmp, &i);
	}
	return (ft_end(&g_lstruct, tmp));
}

void		ft_keys_nav(t_line *l, int *i, char tmp)
{
	read(0, &tmp, 1);
	if (tmp == '[')
	{
		read(0, &tmp, 1);
		if (tmp == 68 && l->cur > 0)
			ft_left_arrow(l);
		if (tmp == 67 && l->cur < *i)
			ft_right_arrow(l);
		if (tmp == '1')
			ft_maj_keys(l, i, tmp);
		if (tmp == 72)
			ft_go_begin(l);
		if (tmp == 70)
			ft_go_end(l, *i);
		if (tmp == 51)
		{
			read(0, &tmp, 1);
			ft_delchar_rev(l, i);
		}
		if (tmp == 65)
			history_up(l, i, &l->hist);
		if (tmp == 66)
			history_down(l, i, &l->hist);
	}
}
