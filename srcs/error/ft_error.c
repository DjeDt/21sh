/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:28:45 by tribeiro          #+#    #+#             */
/*   Updated: 2017/05/25 21:27:20 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_error_syntaxe(int ret)
{
	ft_putendl_fd("shell: syntaxe error", 2);
	return (ret);
}

void		ft_error_chdir(char *argv)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(argv, 2);
}

void		ft_oldpwdnotset(void)
{
	ft_putendl_fd("OLDPWD NOT SET", 2);
	ft_setoldpwd();
}
