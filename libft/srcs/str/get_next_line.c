/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_ligne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:29:30 by tribeiro          #+#    #+#             */
/*   Updated: 2016/12/13 15:07:36 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

static int		ft_cheak_line(char *buf)
{
	int		i;

	i = 0;
	if (buf)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
		return (i);
	}
	return (0);
}

static char		*ft_get_line(char *buf)
{
	int		size;
	char	*tmp;

	size = ft_cheak_line(buf);
	tmp = ft_strsub(buf, 0, size);
	return (tmp);
}

static int		cheack_save(char **line, char **save)
{
	*line = ft_get_line(*save);
	*save = ft_strsub(ft_strchr(*save, '\n'), 1, ft_strlen(*save));
	return (1);
}

static int		cheack_del_buf(char **buf, char **line, char **save, int ret)
{
	int		len;

	free(*buf);
	*buf = NULL;
	if (ret < 0)
	{
		free(*save);
		*save = NULL;
		return (-1);
	}
	if ((len = ft_strlen(*save)) == 0)
	{
		free(*save);
		*save = NULL;
		return (0);
	}
	*line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	int				ret;
	static char		*save = NULL;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (ft_strchr(save, '\n'))
		return (cheack_save(line, &save));
	((save == NULL) ? save = ft_strnew(0) : 0);
	if (!(buf = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ft_strchr(save, '\n')) == 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			return (cheack_del_buf(&buf, line, &save, ret));
		buf[ret] = '\0';
		save = ft_strjoin1(&save, &buf);
	}
	*line = ft_get_line(save);
	if ((ft_strchr(save, '\n')) != 0)
		save = ft_strsub(ft_strchr(save, '\n'), 1, ft_strlen(save));
	free(buf);
	buf = NULL;
	return (ret > 1) ? (1) : (ret);
}
