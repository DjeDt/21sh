/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:45:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 15:46:58 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

enum				is_token
{
	NORMAL = -1,
	PIPE = '|',
	AMPERSAND = '&',
	SQUOTE = '\'',
	DQUOTE = '\"',
	SEMICOLON = ';',
	SPACE = ' ',
	ESCAPE = '\\',
	TAB = '\t',
	NEWLINE = '\n',
	GREATER = '>',
	LESSER = '<',
	NNULL = 0,
	TOKEN = -1,
};

enum
{
	STATE_IN_DQUOTE,
	STATE_IN_SQUOTE,
	STATE_IN_ESCAPESEQ,
	STATE_GENERAL,
};

typedef struct		s_token
{
	char			*data;
	struct s_token	*next;
}					t_token;

typedef	struct		s_lexer
{
	int				c;
	int				i_tok;
	int				statut;
	t_token			*token;
}					t_lexer;

char				**core_analyse(char *line);
char				**core_lexer(char *line, t_lexer **lexer);

#endif