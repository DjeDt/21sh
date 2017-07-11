/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:26:16 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 17:01:15 by ddinaut          ###   ########.fr       */
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

int		is_quote(char *line, int *count, char *c, int *type)
{
	int statut;

	statut = 0;
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

void	anormal_state(char *line, char **data, int *ct, int *ct2, int *stat)
{
	if (((*stat) == IN_DQUOTE) && (line[(*ct)] == ESCAPE))
		escape_in_dquote(line, data, ct, ct2, stat);
	else if (((*stat) == IN_SQUOTE) && (line[(*ct)] == ESCAPE))
		escape_in_squote(line, data, ct, ct2, stat);
	else
	{
		if ((*stat) == IN_DQUOTE)
		{
			if (line[(*ct)] == DQUOTE)
				(*stat) = NORMAL_STATE;
			else
				(*data)[(*ct2)++] = line[(*ct)];
		}
		else if ((*stat) == IN_SQUOTE)
		{
			if (line[(*ct)] == SQUOTE)
				(*stat) = NORMAL_STATE;
			else
				(*data)[(*ct2)++] = line[(*ct)];
		}
	}
}

int		is_char(char *line, int *count, char *c, int *type)
{
	int ret;
	int c_type;

	ret = NORMAL_STATE;
	c_type = typeof_char(line[(*count)]);
	if (c_type == ESCAPE)
	{
		ret = IN_ESCAPE;
		c_type = typeof_char(line[++(*count)]);
		if (c_type != CNUL)
		{
			(*c) = line[(*count)];
			ret = NORMAL_STATE;
		}
		(*type) = TOKEN;

	}
	else if (c_type == CHAR)
	{
		(*c) = line[(*count)];
		(*type) = CHAR;
	}
	return (ret);
}

t_token	*is_space(int *count2, int len, t_token *token)
{
	(*count2) = 0;
	token = next_token(len, token);
	return (token);
}
