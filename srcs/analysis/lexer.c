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

void		core_lexer(char *line, int len, t_lexer *lexer, t_token *token)
{
	int		count;
	int		count2;

	count = -1;
	count2 = 0;
	init_token(len, token);
	while (line[++count] != '\0')
	{
		lexer->type = typeof_char(line[count]);
		if (lexer->statut == NORMAL_STATE)
		{
			if (lexer->type == DQUOTE || lexer->type == SQUOTE)
				is_quote(line[count], &token->data[count2++], &token->type, &lexer->statut);
			else if (lexer->type == CHAR || lexer->type == ESCAPE)
				is_char(line, &count, &token->data[count2++], &token->type, &lexer->statut);
			else if (lexer->type == SPACE && count2 > 0)
				token = is_space(&count2, len - count, token);
			else if (lexer->type == SEMICOLON || lexer->type == GREATER || lexer->type == LESSER || \
					  lexer->type == AMPERSAND || lexer->type == PIPE)
				token = is_token(&count2, len - count, lexer->type, token);
		}
		else if (lexer->statut == IN_DQUOTE || lexer->statut == IN_SQUOTE)
			in_quote(lexer->type, &token->data[count2++], line[count], &lexer->statut);
	}
}
