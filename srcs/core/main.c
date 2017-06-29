/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 19:35:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static void	init_builtin_struct(t_builtin *builtin)
{
	builtin[0].ft = "env";
	builtin[0].func = &ft_env;
	builtin[1].ft = "setenv";
	builtin[1].func = &ft_setenv;
	builtin[2].ft = "unsetenv";
	builtin[2].func = &ft_unsetenv;
	builtin[3].ft = "echo";
	builtin[3].func = &ft_echo;
	builtin[4].ft = "cd";
	builtin[4].func = &ft_cd;
	builtin[5].ft = "exit";
	builtin[5].func = &ft_exit;
}

static int	check_builtins(const char *input)
{
	int			count;
	char		**tmp;
	t_builtin	builtin[6];

	count = 0;
	init_builtin_struct(builtin);
	tmp = ft_split_whitespaces((char*)input);
	while ((tmp && tmp[0]) && count < 6)
	{
		if (ft_strcmp(tmp[0], builtin[count].ft) == 0)
		{
			(*(builtin[count].func))((const char **)tmp);
			ft_arrfree(&tmp);
			return (0);
		}
		count++;
	}
	tmp[0] != NULL ? ft_launch_prog((const char **)tmp) : 0;
	tmp != NULL ? ft_arrfree(&tmp) : NULL;
	return (0);
}

static void	core(int term)
{
	int		count;
	char	*line;
	char	**cmd;

	line = NULL;
	cmd = NULL;
	print_launch();
	signal(SIGINT, get_signal);
	while (1)
	{
		count = 0;
		print_prompt();
		if (term == 0)
			read_line(0, &line);
		else
			get_next_line(0, &line);
		cmd = core_analyse(line);
		while (cmd != NULL && cmd[count] != NULL)
			check_builtins(cmd[count++]);
		cmd != NULL ? ft_arrfree(&cmd) : NULL;
	}
}

int			main(void)
{
	int	term;

	get_environ();
	term = change_term_mode();
	core(term);
	return (0);
}
