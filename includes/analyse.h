/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:45:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/10 21:30:59 by ddinaut          ###   ########.fr       */
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
	CNUL = '\0',
	CHAR = -1,
	TOKEN = -1
};

enum
{
	IN_DQUOTE,
	IN_SQUOTE,
	IN_ESCAPE,
	NORMAL_STATE,
};

typedef struct			s_pipe
{
	char				**cmd;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_command
{
	t_pipe				*pipe;
	struct s_command	*next;
}						t_command;

typedef struct			s_token
{
	int					type;
	char				*data;
	struct s_token		*next;
}						t_token;

typedef struct			s_lexer
{
	int					type;
	int					statut;
	int					nbr_tok;
	t_token				*token;
}						t_lexer;

char					**core_analyse(char *line, int len);
void					core_lexer(char *line, int len, t_lexer *lexer, t_token *token);
int						typeof_char(const char c);

void					core_parser(t_token **token, t_command *cmd);

void					init_token(int len, t_token *token);
t_token					*next_token(int len, t_token *token);

t_token					*is_space(int *count, int len, t_token *token);
t_token					*is_token(int *count, int len, int type, t_token *token);
void					is_char(char *line, int *count, char *c, int *type, int *statut);
void					is_quote(char *line, int *count, char *c, int *type, int *statut);
void					anormal_state(char *line, char **data, int *count, int *count2, int *statut);
void					escape_in_dquote(char *line, char **data, int *count, int *count2, int *statut);
void					escape_in_squote(char *line, char **data, int *count, int *count2, int *statut);

#endif
