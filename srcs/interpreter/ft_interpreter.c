/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpreter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:46:29 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 14:43:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void	ft_initbuildtins(t_builtins *builtins)
{
	builtins[0] = &ft_echo;
	builtins[1] = &ft_cd;
	builtins[2] = &ft_setenv;
	builtins[3] = &ft_unsetenv;
	builtins[4] = &ft_env;
	builtins[5] = &ft_exit;
	builtins[6] = &ft_pwd;
	builtins[NB_BUILTINS] = 0;
}

void		ft_interpreter(char **token, t_r **r)
{
	t_builtins	builtins[NB_BUILTINS + 1];
	int			id;

	if (ft_redirect_core(r) == -1)
		return ;
	ft_initbuildtins(builtins);
	id = ft_identification_builtins(*token);
	if (id >= 0)
		builtins[id](token);
	else
		ft_identification_bin(token);
	dup2(g_fd_term, STDIN_FILENO);
	dup2(g_fd_term, STDOUT_FILENO);
	dup2(g_fd_term, STDERR_FILENO);
}

void		ft_child_bin(char **token, int *fd, t_r **r, int last)
{
	dup2(g_backup, 0);
	if (!last)
		dup2(fd[1], 1);
	ft_interpreter(token, r);
	close(fd[1]);
}

void		cmd_pipe(char **token, t_r **r, int last)
{
	pid_t	father;
	int		fd[2];
	int		ret;

	if (last == 0)
		pipe(fd);
	father = fork();
	save_pid(father);
	if (father == 0)
	{
		if (last == 1)
			dup2(fd[1], 1);
		close(fd[0]);
		ft_child_bin(token, fd, r, last);
		exit(-1);
	}
	close(fd[1]);
	if (last)
	{
		dup2(g_fd_term, STDIN_FILENO);
		dup2(g_fd_term, STDOUT_FILENO);
		dup2(g_fd_term, STDERR_FILENO);
		waitpid(father, &ret, WUNTRACED);
	}
	end_pipe(last, fd);
}

void		pre_interpreter(char **token, t_r **r, int last)
{
	if (g_flg == 1)
		cmd_pipe(token, r, last);
	else
		ft_interpreter(token, r);
}
