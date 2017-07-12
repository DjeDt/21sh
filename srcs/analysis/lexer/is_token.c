/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:26:16 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/12 19:22:58 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

t_token	*is_space(int *count2, int len, t_token *token)
{
	(*count2) = 0;
	token = next_token(len, token);
	return (token);
}

t_token	*is_token(int *count, int len, int type, t_token *token)
{
	if ((*count) > 0)
	{
		token->data[(*count)] = '\0';
		token = next_token(len, token);
		(*count) = 0;
	}
	token->data[0] = type;
	token->data[1] = '\0';
	token->type = type;
	token = next_token(len, token);
	return (token);
}

int		is_quote(char *line, int *count, char *c, int *type)
{
	int statut;

	statut = NORMAL_STATE;
	if (line[(*count)] == SQUOTE)
	{
		(*c) = line[++(*count)];
		(*type) = TOKEN;
		statut = IN_SQUOTE;
	}
	else if (line[(*count)] == DQUOTE)
	{
		(*c) = line[++(*count)];
		(*type) = TOKEN;
		statut = IN_DQUOTE;
	}
	return (statut);
}

int		is_char(char *line, int *count, char *c, int *type)
{
	int statut;
	int c_type;

	statut = NORMAL_STATE;
	c_type = typeof_char(line[(*count)]);
	if (c_type == ESCAPE)
	{
		statut = IN_ESCAPE;
		c_type = typeof_char(line[++(*count)]);
		if (c_type != CNUL)
		{
			(*c) = line[(*count)];
			statut = NORMAL_STATE;
		}
		(*type) = TOKEN;
	}
	else if (c_type == CHAR || c_type == CLOSE)
	{
		(*c) = line[(*count)];
		(*type) = CHAR;
	}
	else if (c_type == IO_NUM)
	{
		(*c) = line[(*count)];
		(*type) = IO_NUM;
	}
	return (statut);
}

