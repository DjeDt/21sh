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

void	is_quote(char q, char *c, int *type, int *statut)
{
	if (q == SQUOTE)
	{
		(*c) = SQUOTE;
		(*type) = TOKEN;
		(*statut) = IN_SQUOTE;
	}
	else if (q == DQUOTE)
	{
		(*c) = DQUOTE;
		(*type) = TOKEN;
		(*statut) = IN_DQUOTE;
	}
}

void	is_escape(char *c, char add, int *type)
{
	(*c) = add;
	(*type) = TOKEN;
}

void	is_char(char *c, char add, int *type)
{
	(*c) = add;
	(*type) = CHAR;
}

t_token *is_space(int *count2, int len, t_token *token)
{
	(*count2) = 0;
	token = next_token(len, token);
	return (token);
}

void	in_quote(int type, char *c, char add, int *statut)
{
	if ((*statut) == IN_DQUOTE)
	{
		(*c) = add;
		if (type == DQUOTE)
			(*statut) = NORMAL_STATE;
	}
	else if ((*statut) == IN_SQUOTE)
	{
		(*c) = add;
		if (type == SQUOTE)
			(*statut) = NORMAL_STATE;
	}
}
