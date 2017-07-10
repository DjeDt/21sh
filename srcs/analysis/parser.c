/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:14:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/10 21:46:26 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

t_pipe		*create_pipe(char **add)
{
	t_pipe	*new;

	if (!(new = (t_pipe*)malloc(sizeof(t_pipe))))
		malloc_error("error in func create_pipe", -1);
	new->cmd = ft_arrdup((const char **)add);
	new->next = NULL;
	return (new);
}

void		add_pipe(char **add, t_pipe **pipe)
{
	t_pipe *tmp;

	tmp = NULL;
	if (!(*pipe))
		(*pipe) = create_pipe(add);
	else
	{
		tmp = (*pipe);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_pipe(add);
	}
}

int			count_semi(t_token *token)
{
	int ret;

	ret = 0;
	while (token != NULL)
	{
		if (token->type == 59)
			break ;
		ret++;
		token = token->next;
	}
	return (ret);
}

void		init_command(t_command *cmd)
{
	if (!(cmd = (t_command*)malloc(sizeof(t_command))))
		malloc_error("error in func init_command", -1);
	cmd->pipe = NULL;
	cmd->next = NULL;
}

t_command	*next_command(t_command *command)
{
	command->next = ft_memalloc(sizeof(t_command));
	command = command->next;
	init_command(command);
	return (command);
}

void		core_parser(t_token **tok, t_command *cmd)
{
	int			count;
	char		**add;
	t_pipe		*pipe;
	t_token		*token;

	count = 0;
	token = (*tok);
	init_command(cmd);
	pipe = cmd->pipe;
	while (token != NULL)

	{
		if (!(add = (char**)malloc(sizeof(char*) * (count_semi(token) + 1))))
			malloc_error("error in func core_parser", -1);
		while (token->type != 59)
		{
			add[count++] = ft_strdup(token->data);
			token = token->next;
		}
		add[count] = NULL;
		add_pipe(add, &pipe);
		ft_arrfree(&add);
		cmd = next_command(cmd);
		token = token->next;
	}
}
