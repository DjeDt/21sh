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
	ft_bzero((char*)token->data, len + 1);
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
	token = lexer->token;
	init_token(len, token);
	while (line[++count] != '\0')
	{
		type = typeof_char(line[count]);
		if (lexer->statut == NORMAL_STATE)
		{
			if (type == DQUOTE || type == SQUOTE)
				is_quote(line[count], &token->data[count2++], &token->type, &lexer->statut);
			else if (type == ESCAPE)
				is_escape(&token->data[count2++], line[++count], &token->type);
			else if (type == CHAR)
				is_char(&token->data[count2++], line[count], &token->type);
			else if (type == SPACE && count2 > 0)
				token = is_space(&count2, len - count, token);
			else if (type == SEMICOLON || type == GREATER || type == LESSER || \
					  type == AMPERSAND || type == PIPE)
				token = is_token(&count2, len - count, type, token);
		}
		else if (lexer->statut == IN_DQUOTE || lexer->statut == IN_SQUOTE)
			in_quote(type, &token->data[count2++], line[count], &lexer->statut);
	}
	return (0);
}
