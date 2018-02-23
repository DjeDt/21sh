/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:53:39 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/25 19:27:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		ft_read_fail(char **line, char *txt)
{
	ft_putendl_fd(txt, 2);
	free(*line);
	ft_default_term();
	exit(1);
}

void		ft_error_line(t_line *l)
{
	ft_putendl_fd("error_line: malloc fail", 2);
	free(g_line);
	free(l->buf);
	ft_default_term();
	exit(1);
}
