/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 14:01:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/20 17:41:46 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		read_heredoc(t_r *redi, int fd)
{
	int	ret;

	if (g_line != NULL)
		ft_strdel(&g_line);
	while (1)
	{
		ft_putstr_fd("<heredoc> ", 2);
		ft_init_term();
		ret = ft_read_line(RD_HEREDOC, NULL);
		ft_default_term();
		if (ret == -1)
			break ;
		if (g_line != NULL && (ft_strcmp(g_line, redi->file)) == 0)
		{
			ft_strdel(&g_line);
			break ;
		}
		ft_putendl_fd(g_line, fd);
		ft_strdel(&g_line);
	}
}

void		core_heredoc(t_r *red)
{
	int		fd;

	if ((red->file == NULL) || (red->file != NULL && ft_strlen(red->file) == 0))
	{
		ft_putendl_fd("shell: missing word", 2);
		return ;
	}
	if ((fd = open(O_HEREDOC)) == -1)
		ft_error_open("shell: open heredoc error");
	read_heredoc(red, fd);
	close(fd);
}
