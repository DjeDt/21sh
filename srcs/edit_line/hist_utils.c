/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:50:17 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/23 14:15:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

t_hist		*create_hist(const char *str, int cur)
{
	t_hist	*ret;

	ret = NULL;
	if (!(ret = (t_hist*)malloc(sizeof(t_hist))))
		return (NULL);
	if (str != NULL)
	{
		ret->cur = cur;
		ret->value = ft_strdup(str);
	}
	else
	{
		ret->cur = 0;
		ret->value = NULL;
	}
	ret->next = NULL;
	return (ret);
}

void		add_hist(const char *str, int cur, t_hist **hist)
{
	t_hist	*tmp;

	tmp = NULL;
	if (!(*hist))
		(*hist) = create_hist(str, cur);
	else
	{
		tmp = (*hist);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_hist(str, cur);
	}
}

void		init_hist(t_line *line)
{
	int		cur;
	char	*tmp;

	cur = 0;
	tmp = NULL;
	line->fd_hist = open(OPEN_HIST);
	while (ft_gnl(line->fd_hist, &tmp))
	{
		if (tmp == NULL)
			return ;
		tmp = ft_strftrim(tmp);
		add_hist(tmp, cur, &line->hist);
		ft_strdel(&tmp);
		line->max_hist += 1;
		cur++;
	}
	line->cur_hist = count_hist(&line->hist);
	close(line->fd_hist);
}

int			count_hist(t_hist **hist)
{
	int		count;
	t_hist	*tmp;

	if (*hist == NULL)
		return (0);
	count = 0;
	tmp = *hist;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void		free_hist(t_hist **hist)
{
	t_hist	*tmp;
	t_hist	*tmp2;

	if (hist && (*hist))
	{
		tmp = *hist;
		while (tmp != NULL)
		{
			if (tmp->value != NULL)
				ft_strdel(&tmp->value);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
	}
}
