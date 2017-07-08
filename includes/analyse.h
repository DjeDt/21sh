/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:45:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/30 15:42:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "sh21.h"

enum				is_token
{
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
	CNUL = 0,
	CHAR = -1,
	TOKEN = -1
};

enum
{
	STATE_IN_DQUOTE,
	STATE_IN_SQUOTE,
	STATE_IN_ESCAPE,
	NORMAL_STATE,
	STATE_GENERAL,
};

typedef struct		s_token
{
	int				type;
	char			*data;
	struct s_token	*next;
}					t_token;

typedef struct		s_lexer
{
	int				type;
	int				statut;
	int				nbr_tok;
	t_token			*token;
}					t_lexer;


char				**core_analyse(char *line);
int					core_lexer(char *line, int len, t_lexer *lexer);

void				init_token(int len, t_token *token);
t_token				*next_token(int len, t_token *token);

t_token				*is_token(int *count, int len, int type, t_token *token);
void				is_dquote(char *c, int *type, int *statut);
void				is_squote(char *c, int *type, int *statut);
void				is_escape(char *c, char add, int *statut);
void				is_char(char *c, char add, int *statut);
void				is_space(char *c, int *count2);
void				in_dquote(int type, char *c, char add, int *statut);
void				in_squote(int type, char *c, char add, int *statut);

#endif
