/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:26:16 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/10 21:21:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

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

void	is_quote(char *line, int *count, char *c, int *type, int *statut)
{
	if (line[(*count)] == SQUOTE)
	{
		(*c) = line[++(*count)];
		(*type) = TOKEN;
		(*statut) = IN_SQUOTE;
	}
	else if (line[(*count)] == DQUOTE)
	{
		(*c) = line[++(*count)];
		(*type) = TOKEN;
		(*statut) = IN_DQUOTE;
	}
}

void	anormal_state(char *line, char **data, int *count, int *count2, int *statut)
{
	if (((*statut) == IN_DQUOTE) && (line[(*count)] == ESCAPE))
		escape_in_dquote(line, data, count, count2, statut);
	else if (((*statut) == IN_SQUOTE) && (line[(*count)] == ESCAPE))
		escape_in_squote(line, data, count, count2, statut);
	else
	{
		if ((*statut) == IN_DQUOTE)
		{
			if (line[(*count)] == DQUOTE)
				(*statut) = NORMAL_STATE;
			else
				(*data)[(*count2)++] = line[(*count)];
		}
		else if ((*statut) == IN_SQUOTE)
		{
			if (line[(*count)] == SQUOTE)
				(*statut) = NORMAL_STATE;
			else
				(*data)[(*count2)++] = line[(*count)];
		}
	}
}

void	is_char(char *line, int *count, char *c, int *type, int *statut)
{
	int c_type;

	c_type = typeof_char(line[(*count)]);
	if (c_type == ESCAPE)
	{
		(*statut) = IN_ESCAPE;
		c_type = typeof_char(line[++(*count)]);
		if (c_type != CNUL)
		{
			(*c) = line[(*count)];
			(*statut) = NORMAL_STATE;
		}
		(*type) = TOKEN;
	}
	else if (c_type == CHAR)
	{
		(*c) = line[(*count)];
		(*type) = CHAR;
	}
}

t_token	*is_space(int *count2, int len, t_token *token)
{
	(*count2) = 0;
	token = next_token(len, token);
	return (token);
}
