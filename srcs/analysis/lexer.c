#include "analyse.h"
#include <stdio.h>

void print_list(t_token **token)
{
	t_token *tmp;

	tmp = (*token);
	while (tmp != NULL)
	{
		printf("\n data = %s\ntype = %d\n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

t_token *next_token(int len, t_token *token)
{
	token->next = ft_memalloc(sizeof(t_token));
	token = token->next;
	init_token(len, token);
	return (token);
}

int			typeof_char(const char c)
{
	if (c == DQUOTE)
		return (DQUOTE);
	else if (c == SQUOTE)
		return (SQUOTE);
	else if (c == ESCAPE)
		return (ESCAPE);
	else if (c == PIPE)
		return (PIPE);
	else if (c == AMPERSAND)
		return (AMPERSAND);
	else if (c == SPACE)
		return (SPACE);
	else if (c == SEMICOLON)
		return (SEMICOLON);
	else if (c == TAB)
		return (TAB);
	else if (c == NEWLINE)
		return (NEWLINE);
	else if (c == GREATER)
		return (GREATER);
	else if (c == LESSER)
		return (LESSER);
	else if (c == '\0')
		return (CNUL);
	return (CHAR);
}

void		init_token(int len, t_token *token)
{
	if (!(token->data = (char*)malloc(sizeof(char) * (len + 1))))
		malloc_error("error in func init_token", -1);
	token->data[0] = '\0';
	token->type = CHAR;
	token->next = NULL;
}

int			core_lexer(char *line, int len, t_lexer *lexer)
{
	int		type;
	int		count;
	int		count2;
	t_token	*token;

	type = 0;
	count = -1;
	count2 = 0;
	if (lexer == NULL || line == NULL)
		return (-1);
	token = lexer->token;
	init_token(len, token);
	while (line[++count] != '\0')
	{
		type = typeof_char(line[count]);
		if (lexer->statut == NORMAL_STATE)
		{
			if (type == DQUOTE)
				is_dquote(&token->data[count2++], &token->type, &lexer->statut);
			else if (type == SQUOTE)
				is_squote(&token->data[count2++], &token->type, &lexer->statut);
			else if (type == ESCAPE)
				is_escape(&token->data[count2++], line[++count], &token->type);
			else if (type == CHAR)
				is_char(&token->data[count2++], line[count], &token->type);
			else if (type == SPACE && count2 > 0)
			{
				is_space(&token->data[count2], &count2);
				token = next_token(len - count, token);
			}
			else if (type == SEMICOLON || type == GREATER || type == LESSER || \
					  type == AMPERSAND || type == PIPE)
				token = is_token(&count2, len - count, type, token);
		}
		else if (lexer->statut == STATE_IN_DQUOTE)
			in_dquote(type, &token->data[count2++], line[count], &lexer->statut);
		else if (lexer->statut == STATE_IN_SQUOTE)
			in_squote(type, &token->data[count2++], line[count], &lexer->statut);
		if (type == CNUL && count2 > 0)
		{
			token->data[count2] = '\0';
			lexer->nbr_tok += 1;
			count2 = 0;
		}
	}
	token->data[count2] = '\0';
	return (0);
}
