/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_reco.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:55:32 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 12:58:05 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** [& -> redirection fd] [- -> fermer le fd]
*/

int		ft_file_red(char *argv, int *i, t_r *elem, t_r **begin_list)
{
	if (elem->r_fd == -1 && elem->r_close == -1)
		if (ft_file_redirection(argv, i, elem) == -1)
		{
			ft_del_elem_redirection(&elem, 0);
			return (-1);
		}
	ft_push_back_redirection(begin_list, elem);
	return (0);
}

void	del_elem(t_r **elem, int *check)
{
	if (elem && *elem)
		ft_del_elem_redirection(elem, 0);
	(*check) = -1;
}

int		ft_boucle(char *argv, int *red_fd, int *check, t_r **begin_list)
{
	t_r *elem;

	elem = NULL;
	ft_argvadd_blanck(argv, red_fd[0], &red_fd[2], &red_fd[1]);
	elem = ft_create_elem_redirection(red_fd[0], red_fd[1]);
	if (ft_fdright(argv, &red_fd[2], elem, red_fd[0]) == 0)
		del_elem(&elem, check);
	else
	{
		if (ft_file_red(argv, &red_fd[2], elem, begin_list) != 0)
		{
			(*check) = -1;
			return (-1);
		}
	}
	if (red_fd[0] == 2)
		core_heredoc(elem);
	if (!argv[red_fd[2]])
		return (-1);
	return (0);
}

void	ft_redirect_reco(char *argv, int *cheack, t_r **begin_list)
{
	int	red_fd[3];

	red_fd[2] = -1;
	while (argv && argv[++red_fd[2]])
	{
		if (argv[red_fd[2]] == '\'' || argv[red_fd[2]] == '\"')
			red_fd[2] += ft_strlensplit(&argv[red_fd[2]], ' ');
		if ((red_fd[0] = ft_isredirection(argv, red_fd[2])) > -1)
		{
			if (ft_boucle(argv, red_fd, cheack, begin_list) != 0)
				return ;
		}
		if (red_fd[0] == -2)
		{
			(*cheack) = -1;
			return ;
		}
	}
}
