/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 21:52:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/26 15:34:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void	free_readline(t_line *line)
{
	if (line->buf != NULL)
		ft_strdel(&line->buf);
	if (line->buf_hist != NULL)
		ft_strdel(&line->buf_hist);
}
