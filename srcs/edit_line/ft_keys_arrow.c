/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:40:07 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 14:21:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_right_arrow(t_line *l)
{
	l->cur += 1;
	if (((l->cur + l->prompt_size) % l->w.ws_col) == 0)
		ft_putstr("\033[1E");
	else
		ft_putstr("\033[1C");
}

void		ft_left_arrow(t_line *l)
{
	if (l->cur > 0)
	{
		l->cur -= 1;
		ft_putstr("\033[1D");
	}
}
