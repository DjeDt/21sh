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

void	is_dquote(char *c, int *type, int *statut)
{
	(*c) = DQUOTE;
	(*type) = TOKEN;
	(*statut) = STATE_IN_DQUOTE;
}

void	is_squote(char *c, int *type, int *statut)
{
	(*c) = SQUOTE;
	(*type) = TOKEN;
	(*statut) = STATE_IN_SQUOTE;
}

void	is_escape(char *c, char add, int *type)
{
	(*c) = add;
	(*type) = TOKEN;
}

void	is_char(char *c, char add, int *type)
{
	(*c) = add;
	(*type) = TOKEN;
}

void	is_space(char *c, int *count2)
{
	(*c) = '\0';
	(*count2) = 0;
}

void	in_dquote(int type, char *c, char add, int *statut)
{
	(*c) = add;
	if (type == DQUOTE)
		(*statut) = NORMAL_STATE;
}

void	in_squote(int type, char *c, char add, int *statut)
{
	(*c) = add;
	if (type == SQUOTE)
		(*statut) = NORMAL_STATE;
}
