/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:41:46 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 12:52:28 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		redirection_error(const int type, char **tmp)
{
	if (type == 1)
		ft_putendl_fd("error redirection '<' : missing word", 2);
	else if (type == 2)
		ft_putendl_fd("error redirection '<<' : missing word", 2);
	else if (type == 3)
		ft_putendl_fd("Error redirection '>' : missing word", 2);
	else if (type == 4)
		ft_putendl_fd("Error redirection '>>' : missing word", 2);
	else if (type == 5)
		ft_putendl_fd("syntax error near unexpected token", 2);
	ft_strdel(tmp);
	return (-1);
}

void	ft_argvadd_blanck(char *argv, int red, int *y, int *fd)
{
	int		i;

	i = *y;
	if (ft_fdleft(argv[i - 1], argv[i - 2], fd) == 1)
		argv[i - 1] = ' ';
	argv[i++] = ' ';
	if (red == 2 || red == 4 || red == 5)
		argv[i++] = ' ';
	*y = i;
}

int		ft_fdleft(char c, char c2, int *fd)
{
	if (ft_isdigit(c) && c2 == ' ')
	{
		(*fd) = (48 - c);
		if (*fd < 0)
			(*fd) = -(*fd);
		return (1);
	}
	(*fd) = 1;
	return (0);
}

int		ft_fdright(char *argv, int *i, t_r *elem, int red)
{
	int		y;

	y = (*i);
	if (argv[y] == '&')
	{
		if (red == 2 || red == 4 || red == 5)
			ft_error_syntaxe(0);
		argv[y++] = ' ';
		if (ft_isdigit(argv[y]))
		{
			if ((elem->r_fd = (48 - argv[y])) < 0)
				elem->r_fd = -elem->r_fd;
			argv[y++] = ' ';
		}
		if (argv[y] == '-')
		{
			elem->r_close = 1;
			argv[y++] = ' ';
		}
		(*i) = y;
	}
	return (1);
}

int		ft_file_redirection(char *argv, int *i, t_r *elem)
{
	char	*tmp;
	int		statut;
	int		y;

	statut = 0;
	while (argv[(*i)] != '\0' && argv[(*i)] == ' ')
		++(*i);
	y = ft_strlensplit(&argv[(*i)], ' ');
	if (!(tmp = split_str(&argv[(*i)], y, 1, &statut)))
		ft_error_malloc("malloc: split_str -> file: ft_redirect_add, line 92");
	if (ft_isredirection(tmp, 0) > -1)
		return (redirection_error(elem->red, &tmp));
	if (tmp && ft_strlen(tmp) == 0)
		return (redirection_error(elem->red, &tmp));
	if (statut != 0)
		add_missing_char(&tmp, &statut);
	while (y > 0)
	{
		argv[(*i)++] = ' ';
		--y;
	}
	if (!(elem->file = ft_strdup(tmp)))
		ft_error_malloc("list -> file");
	ft_strdel(&tmp);
	return (0);
}
