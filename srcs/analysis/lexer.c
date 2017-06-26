/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/19 15:54:30 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexer.h"

static int		search_token_type(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '&')
		return (AMPERSAND);
	else if (c == '\'')
		return (SQUOTE);
	else if (c == '"')
		return (DQUOTE);
	else if (c == ';')
		return (SEMICOLON);
	else if (c == ' ')
		return (SPACE);
	else if (c == '\\')
		return (ESCAPE);
	else if (c == '\t')
		return (TAB);
	else if (c == '<')
		return (LESSER);
	else if (c == '>')
		return (GREATER);
	else if (c == '\n')
		return (NEWLINE);
	else if (c == 0)
		return (NNULL);
	return (NORMAL);
}

void	init_token(t_token *token, int len)
{
	if (!(token = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in func init_lexer -> var token", -1);
	if (!(token->data = (char*)malloc(sizeof(char) * (len + 1))))
		malloc_error("error in func init_lexer -> var token->data", -1);
	token->type = 0;
	token->next = NULL;
}

void	init_lexer(t_lexer *lexer, int len)
{
	lexer->i_tok = 0;
	lexer->statut = STATE_GENERAL;
	init_token(lexer->token, len);
}

static void	add_quote_token(t_lexer *lexer, int count)
{
	if (lexer->c == SQUOTE)
	{
		lexer->statut = STATE_IN_SQUOTE;
		lexer->token->data[count++] = SQUOTE;
		lexer->token->type = TOKEN;
	}
	else if (lexer->c == DQUOTE)
	{
		lexer->statut = STATE_IN_DQUOTE;
		lexer->token->data[count++] = DQUOTE;
		lexer->token->type = TOKEN;
	}
}

static void add_escape_token(t_lexer *lexer, char *line, int c, int c2)
{
	lexer->token->data[c++] = line[c2++];
	lexer->token->type = TOKEN;
}

static void	add_normal_token(t_lexer *lexer, int c)
{
	lexer->token->data[c++] = lexer->c;
	lexer->token->type = TOKEN;
}

static void	add_space_token(t_lexer *lexer, int c, int c2, int len)
{
	if (c > 0)
	{
		lexer->token->data[c] = '\0';
		lexer->token = lexer->token->next;
		init_token(lexer->token, len - c2);
	}
}

#include <stdio.h>
void print_list(t_token **token)
{
	t_token *tmp;

	tmp = (*token);
	while (tmp->next != NULL)
	{
		printf("data = %s\n, type = %d\n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

char	**core_lexer(char *line, int len)
{
	int		count;
	int		count2;
	int		tmp_tok;
	char	**clean;
	t_token	*token;
	t_lexer	lexer;

	count = 0;
	count2 = 0;
	init_lexer(&lexer, len);
	token = lexer.token;
	while (lexer.c != '\0')
	{
		lexer.c = search_token_type(line[count]);
		if (lexer.statut == STATE_GENERAL)
		{
			ft_putendl("test");
			if (lexer.c == SQUOTE || lexer.c == DQUOTE)
				add_quote_token(&lexer, count2);
			else if (lexer.c == ESCAPE)
				add_escape_token(&lexer, line, count2, count);
			else if (lexer.c == NORMAL)
				add_normal_token(&lexer, count2);
			else if (lexer.c == SPACE)
			{
				add_space_token(&lexer, count2, count, len);
				count2 = 0;
			}
			else if (lexer.c == SEMICOLON || lexer.c == GREATER || lexer.c == LESSER || lexer.c == AMPERSAND || lexer.c == PIPE)
			{
				ft_putendl("test2");
				add_space_token(&lexer, count2, count, len);
				count2 = 0;
			}
			token->data[0] = lexer.c;
			token->data[1] = '\0';
			token->type = lexer.c;
			token = token->next;
			token = (t_token*)malloc(sizeof(t_token));
			init_token(token, len - count);
		}
		else if (lexer.statut == STATE_IN_DQUOTE)
		{
			ft_putendl("test3");
			token->data[count2++] = lexer.c;
			if (lexer.c == DQUOTE)
				lexer.statut = STATE_GENERAL;
		}
		else if (lexer.statut == STATE_IN_SQUOTE)
		{
			ft_putendl("Test4");
			token->data[count2++] = lexer.c;
			if (lexer.c == SQUOTE)
				lexer.statut = STATE_GENERAL;
		}
		if (lexer.c == NNULL)
		{
			ft_putendl("test5");
			if (count2 > 0)
			{
				token->data[count2] = '\0';
				tmp_tok++;
				count2 = 0;
			}
		}
		count++;
	}
	print_list(&token);
	clean = ft_strtok(line, ";");
	return (clean);
}
