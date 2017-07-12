/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:45:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/12 19:22:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSE_H
# define ANALYSE_H

# include "sh21.h"

enum				is_token
{
	PIPE = '|',
	AMPERSAND = '&',
	SQUOTE = '\'',
	DQUOTE = '"',
	SEMICOLON = ';',
	SPACE = ' ',
	ESCAPE = '\\',
	TAB = '\t',
	NEWLINE = '\n',
	GREATER = '>',
	LESSER = '<',
	CLOSE = '-',
	CNUL = '\0',
	IO_NUM = 2,  // genre [ 5< ou 5>]
	CHAR = -1,
	TOKEN = -1
};

enum
{
	D_GREAT = 1, // >>
	D_LESS = 2, // <<
	FD_GREAT = 3, // 2>
	FD_LESS = 4, // 2<
	FD_DGREAT = 5, // 2>>
	FD_DLESS = 6, // 2<<
	GREATLESS = 7, // <>
	FD_GREATLESS = 8 // 2<>
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
void					clean_up_token(t_token **token);
void					core_parser(t_token **token, t_command **cmd);

void					init_token(int len, t_token *token);
t_token					*next_token(int len, t_token *token);

t_token					*is_space(int *count, int len, t_token *token);
t_token					*is_token(int *count, int len, int type, t_token *token);
int						is_char(char *line, int *count, char *c, int *type);
int						is_quote(char *line, int *count, char *c, int *type);

int						in_dquote(char *line, char **data, int *count, int *count2);
int						in_squote(char *line, char **data, int *count, int *count2);
int						escape_in_dquote(char *line, char **data, int *count, int *count2);
int						escape_in_squote(char *line, char **data, int *count, int *count2);

void					free_token(t_token **token);
void					free_lexer(t_lexer *lexer);
void					free_pipe(t_pipe **pipe);
void					free_command(t_command **command);

void					core_execution(t_command **cmd);

#endif
