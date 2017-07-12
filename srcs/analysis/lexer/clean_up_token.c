/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:22:19 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/12 19:19:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

void		error_token(int cur_type, int next_type, int nn_type)
{
	(void)cur_type;
	(void)next_type;
	(void)nn_type;
	ft_putendl("token error");
}


t_token		*check_token(t_token *current, t_token *next)
{
	t_token *save;

	if (next != NULL)
	{
		if ((current->type == GREATER && next->type == GREATER) ||	\
			(current->type == LESSER && next->type == LESSER))
		{
			current->data = ft_strjoin_fl(current->data, next->data);
			save = next->next;
			free(current->next);
			current->next = save;
			return (current);
		}
	}
	return (current);
}

t_token		*join_node(t_token *current, t_token *next, int type)
{
	t_token *save;

	current->data = ft_strjoin_fl(current->data, next->data);
	current->type = type;
	save = next->next;
	free(current->next);
	current->next = save;
	return (current);
}

void		clean_up_token(t_token **token)
{
	int		len;
	t_token *tok;
	t_token *next;

	tok = (*token);
	while (tok != NULL)
	{
		next = tok->next;
		if (tok->type == GREATER && next->type == GREATER)
			tok = join_node(tok, next, D_GREAT);
		if (tok->type == LESSER && next->type == LESSER)
			tok = join_node(tok, next, D_LESS);
		if (tok->type == LESSER && next->type == GREATER)
			tok = join_node(tok, next, GREATLESS);
		tok = tok->next;
	}
	tok = (*token);
	while (tok != NULL && ((len = ft_strlen(tok->data))))
	{
		next = tok->next;
		if ((tok->type != -1 && len == 1) && next->type == GREATER)
			tok = join_node(tok, next, FD_GREAT);
		if (tok->type != -1 && len == 1 && next->type == LESSER)
			tok = join_node(tok, next, FD_LESS);
		if (tok->type != -1 && len == 1 && next->type == D_GREAT)
			tok = join_node(tok, next, FD_GREAT);
		if (tok->type != -1 && len == 1 && next->type == D_LESS)
			tok = join_node(tok, next, FD_LESS);
		if (tok->type != -1 && len == 1 && next->type == GREATLESS)
			tok = join_node(tok, next, FD_GREATLESS);
		tok = tok->next;
	}
}
