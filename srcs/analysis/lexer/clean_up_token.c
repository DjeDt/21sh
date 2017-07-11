/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:22:19 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 20:20:23 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

t_token		*check_token(t_token *current, t_token *next)
{
	t_token *save;

	if (current->next != NULL)
	{
		if ((current->type == GREATER && next->type == GREATER) ||	\
			(current->type == LESSER && next->type == LESSER))
		{
			current->data = ft_strjoin_fl(current->data, next->data);
			save = next->next;
			free(current->next);
			current->next = save;
			ft_putendl("return current");
			return (current);
		}
	}
	return (current);
}

void		clean_up_token(t_token **token)
{
	t_token *tok;

	tok = (*token);
	while (tok != NULL)
	{
		if (tok->type != -1)
			tok = check_token(tok, tok->next);
		tok = tok->next;
	}
}
