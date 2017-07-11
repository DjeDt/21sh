/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:14:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 18:51:19 by ddinaut          ###   ########.fr       */
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

t_command		*new_command(void)
{
	t_command	*new;

	if (!(new = (t_command*)malloc(sizeof(t_command))))
		malloc_error("error in func init_command", -1);
	new->pipe = NULL;
	new->next = NULL;
	return (new);
}

void		next_command(t_command **command)
{
	t_command *tmp;

	if ((*command) == NULL)
		(*command) = new_command();
	else
	{
		tmp = (*command);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_command();
	}
}

void		core_parser(t_token **tok, t_command **cmd)
{
	int			count;
	char		**add;
	t_token		*token;
	t_command	*command;

	count = 0;
	token = (*tok);
	command = (*cmd);
	next_command(&command);
	while (token != NULL)
	{
		add = ft_memalloc(sizeof(char*) * (count_semi(token) + 1));
		while (token != NULL && token->data != NULL && token->type != 59)
		{
			add[count++] = token->data;
			token = token->next;
		}
		add[count] = NULL;
		count = 0;
		add_pipe(add, &command->pipe);
		next_command(&command);
		free(add);
		token != NULL ? token = token->next : NULL;
	}
}
