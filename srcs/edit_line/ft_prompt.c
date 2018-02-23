/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:26:34 by tribeiro          #+#    #+#             */
/*   Updated: 2017/07/16 16:50:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void			ft_init_prompt(void)
{
	ft_default_term();
	ft_prompt();
	ft_init_term();
}

static void		ft_putseparator(char *str)
{
	ft_putstr("\033[34m");
	ft_putstr(str);
	ft_putstr("\033[32m");
}

static void		ft_putcwd(void)
{
	char		*cwd;
	char		*tmp;

	tmp = NULL;
	ft_putstr("[ ");
	cwd = getcwd(tmp, 0);
	ft_putstr(cwd);
	ft_putstr("]");
	free(cwd);
}

void			ft_prompt(void)
{
	char		buf[1024];

	ft_bzero(buf, 1024);
	ft_putseparator("\n<-__--");
	ft_putstr("[");
	getlogin_r(buf, 1024);
	ft_putstr(buf);
	ft_bzero(buf, 1024);
	ft_putstr(" @ ");
	gethostname(buf, 1024);
	ft_putstr(buf);
	ft_putstr("]");
	ft_putseparator("-__-");
	ft_putcwd();
	ft_putseparator("-__->\n");
	ft_putstr("\033[5m");
	ft_putstr("\033[31m");
	ft_putstr_fd("(\")> ", 1);
	ft_putstr("\033[0m");
}
