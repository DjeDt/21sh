/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:54:36 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 18:11:56 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

void		init_token(int len, t_token *token)
{
	if (!(token->data = (char*)malloc(sizeof(char) * (len + 1))))
		malloc_error("error in func init_token", -1);
	ft_bzero((char*)token->data, len + 1);
	token->type = CHAR;
	token->next = NULL;
}

t_token		*next_token(int len, t_token *token)
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

int			is_else(int type)
{
	if (type == SEMICOLON || type == GREATER || type == LESSER || \
		type == AMPERSAND || type == PIPE)
		return (0);
	return (-1);
}

void print_list(t_token **token)
{
	t_token *tmp;

	tmp = (*token);
	while (tmp != NULL)
	{
		ft_putstr("data = ");
		ft_putendl(tmp->data);
		ft_putstr("type = ");
		ft_putnbr(tmp->type);
		ft_putchar('\n');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		core_lexer(char *line, int len, t_lexer *lex, t_token *tok)
{
	int		c;
	int		c2;

	c = -1;
	c2 = 0;
	init_token(len, tok);
	while (line[++c] != '\0')
	{
		lex->type = typeof_char(line[c]);
		if (lex->statut == NORMAL_STATE)
		{
			if (lex->type == DQUOTE || lex->type == SQUOTE)
				lex->statut = is_quote(line, &c, &tok->data[c2++], &tok->type);
			else if (lex->type == CHAR || lex->type == ESCAPE)
				lex->statut = is_char(line, &c, &tok->data[c2++], &tok->type);
			else if (lex->type == SPACE && c2 > 0)
				tok = is_space(&c2, len - c, tok);
			else if (is_else(lex->type) == 0)
				tok = is_token(&c2, len - c, lex->type, tok);
		}
		else if (lex->statut == IN_DQUOTE || lex->statut == IN_SQUOTE)
			anormal_state(line, &tok->data, &c, &c2, &lex->statut);
	}
	print_list(&lex->token);
}
