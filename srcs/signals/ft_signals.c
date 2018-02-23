/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 20:38:34 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 15:06:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

pid_t		save_pid(pid_t father)
{
	static pid_t save;

	if (father != -1)
		save = father;
	return (save);
}

void		sig_handler(int i)
{
	pid_t	tmp;

	tmp = save_pid(-1);
	if (tmp)
		kill(tmp, i);
	else
		ioctl(0, TIOCSTI, "\x2");
}
