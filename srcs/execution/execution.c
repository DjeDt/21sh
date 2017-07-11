/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:31:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 17:01:30 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int		parse_cmd(t_pipe **pipe)
{
	t_pipe *tmp;

	if ((*pipe) == NULL)
		return (-1);
	tmp = (*pipe);
	while (tmp != NULL)
	{
		tmp = tmp->next;
	}
	return (0);
}

void	core_execution(t_command **cmd)
{
	t_command	*command;

	command = (*cmd);
	while (command != NULL)
	{
		if (command->pipe != NULL)
			parse_cmd(&command->pipe);
		command = command->next;
	}
}
