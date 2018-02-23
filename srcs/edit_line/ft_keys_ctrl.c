/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:05:16 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/15 15:43:43 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void	ft_past_line(t_line *l, int *i)
{
	char	*end;

	end = NULL;
	if (g_buf_cut != NULL)
	{
		if ((end = ft_strjoin(g_buf_cut, &(g_line[l->cur]))) == NULL)
			ft_error_line(l);
		ft_bzero((&g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		*i += ft_strlen(g_buf_cut);
		while (*i >= l->lmax)
			ft_realloc_line(l);
		ft_strcpy(&(g_line[l->cur]), end);
		ft_strdel(&end);
		ft_putstr("\033[J");
		write(1, &(g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
		l->cur += ft_strlen(g_buf_cut);
		if (l->cur != *i)
			reset_pos(ft_strlen(&(g_line[l->cur])) + 1);
	}
}

void	ft_cut_line(t_line *l, int *i)
{
	if (g_buf_cut != NULL)
		ft_strdel(&(g_buf_cut));
	if ((g_buf_cut = ft_strdup(&(g_line[l->cur]))) == NULL)
		ft_error_line(l);
	*i -= ft_strlen(g_buf_cut);
	ft_bzero((&g_line[l->cur]), ft_strlen(&(g_line[l->cur])));
	ft_putstr("\033[J");
}

void	handle_ctrl_d(t_line *l, int *i, char *tmp, int where)
{
	if (where == SHELL)
	{
		ft_default_term();
		ft_putstr("exit");
		if (g_line != NULL)
			ft_strdel(&g_line);
		if (g_buf_cut != NULL)
			ft_strdel(&g_buf_cut);
		exit(1);
	}
	else if (where == RD_HEREDOC)
	{
		if ((*i) == 0)
			(*tmp) = EOF;
		else
			ft_addchar(i, l, '\n');
	}
	else if (where == 3 || where == 4)
	{
		ft_putstr_fd("un ctrl+d sauvage est apparu: ", 2);
		ft_putendl_fd("syntax error: unexpected end of file", 2);
		(*tmp) = EOF;
	}
}

int		handle_ctrl_c(void)
{
	pid_t	tmp;

	tmp = save_pid(-1);
	if (tmp)
		kill(tmp, 2);
	ft_strdel(&g_line);
	ft_strdel(&g_buf_cut);
	return (-1);
}

int		ft_ctrl_d(t_line *l, int *i, char *tmp, int where)
{
	int count;

	count = l->cur;
	if ((*tmp) == 2)
		return (handle_ctrl_c());
	if ((*tmp) == 4)
	{
		if (where == 3 || where == 4)
			handle_ctrl_d(l, i, tmp, where);
		else if ((*i) == 0)
			handle_ctrl_d(l, i, tmp, where);
		else if (l->cur < (*i))
		{
			ft_delchar_rev(l, i);
			(*tmp) = 0;
		}
		else
			(*tmp) = EOF;
	}
	return (0);
}
