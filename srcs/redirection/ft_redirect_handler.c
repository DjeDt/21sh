/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 20:59:05 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 13:24:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_redirect_right_nofile(t_r *elem)
{
	if (elem->r_fd != -1)
		dup2(elem->r_fd, elem->fd);
	if (elem->r_fd != -1 && elem->r_close != -1)
		close(elem->r_fd);
	if (elem->r_fd == -1 && elem->r_close != -1)
		close(elem->fd);
}

int			ft_redirect_right(t_r *elem)
{
	int			file_fd;

	file_fd = -1;
	if (elem->r_fd == -1 && elem->r_close == -1)
	{
		if (check_file(elem) != 0)
			return (-1);
		if (elem->red == 3)
			file_fd = open(elem->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (elem->red == 4)
			file_fd = open(elem->file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	if (file_fd == -1)
		ft_redirect_right_nofile(elem);
	else
		dup2(file_fd, elem->fd);
	if (file_fd != -1)
		close(file_fd);
	return (0);
}

int			simple_red_left(t_r *elem, int *fd)
{
	struct stat		st;

	if (elem->r_fd == -1)
		elem->r_fd = 0;
	(*fd) = open(elem->file, O_RDONLY, 0644);
	if (fstat((*fd), &st) != -1 && (st.st_mode & S_IFMT) == S_IFREG)
	{
		dup2((*fd), elem->r_fd);
		close((*fd));
	}
	else
	{
		ft_error_create("shell: No such file or directory", elem->file);
		return (-1);
	}
	return (0);
}

int			ft_redirect_left(t_r *elem)
{
	int	fd;
	int	ret;

	fd = -1;
	ret = 0;
	if (elem->red == 1)
		ret = simple_red_left(elem, &fd);
	else if (elem->red == 2)
	{
		if (ft_strlen(elem->file) == 0)
			return (-1);
		if ((fd = open("/tmp/heredoc_file.txt", O_CREAT | O_RDWR)) == -1)
		{
			ft_error_open("shell: Error when opened heredoc_file");
			return (-1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (ret);
}

int			ft_redirect_core(t_r **r)
{
	t_r	*elem;
	int	ret;

	elem = NULL;
	ret = 0;
	if (*r != NULL)
	{
		elem = *r;
		while (elem != NULL)
		{
			if (elem->red == 3 || elem->red == 4)
				ret = ft_redirect_right(elem);
			else if (elem->red == 1 || elem->red == 2)
				ret = ft_redirect_left(elem);
			if (ret == -1)
				return (-1);
			elem = elem->next;
		}
	}
	return (0);
}
