/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:42:52 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 12:12:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		main_init(void)
{
	signal(SIGINT, sig_handler);
	ft_init_prompt();
	ft_read_line(SHELL, NULL);
	ft_default_term();
}

void		main_prepare(int *statut, char ***cmd)
{
	(*cmd) = NULL;
	(*statut) = 0;
	ft_isatty();
	ft_envdup();
}

int			main(void)
{
	int		i;
	int		statut;
	char	**cmd;

	main_prepare(&statut, &cmd);
	while (1)
	{
		i = -1;
		main_init();
		if (g_line != 0)
		{
			cmd = ft_strsplit_lexer(g_line, ';', 0, &statut);
			while (cmd[++i] != NULL)
				if (ft_parser(cmd[i]) == -1)
					break ;
			while (waitpid(WAIT_ANY, NULL, WNOHANG) > 0)
				;
			ft_arraydel_2d(cmd, 0);
		}
		if (g_line != NULL)
			ft_strdel(&g_line);
	}
	ft_default_term();
	free_readline(&g_lstruct);
	return (0);
}
