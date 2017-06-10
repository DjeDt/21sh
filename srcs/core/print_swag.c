/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:57:47 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 20:10:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	print_launch(void)
{
	ft_putstr("\033[0;32m");
	ft_putendl("  ____  _     _     ");
	ft_putendl(" |___ \\/ |___| |__  ");
	ft_putendl("   __) | / __| '_ \\ ");
	ft_putendl("  / __/| \\__ \\ | | |");
	ft_putendl(" |_____|_|___/_| |_|");
	ft_putendl("                    ");
	ft_putstr("\033[0;m");
	ft_putendl("\033[0;31m[djelali.dinaut@gmail.com] - [minishell]\n\033[0;m");
}

void	print_prompt(void)
{
	ft_putstr("\033[32;m");
	ft_putstr("$> ");
	ft_putstr("\033[0;m");
}
