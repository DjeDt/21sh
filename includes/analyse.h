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
	WORD = 0,
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

typedef struct			s_command
{
	char				**arg;
	t_list				*redir_list;
	struct s_command	*next;
}						t_command;

typedef struct			s_pipe
{
	t_list				command_list;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_token
{
	int					type;
	char				*data;
	struct s_token		*next;
}						t_token;

typedef	struct			s_lexer
{
	int					statut;
	t_token				*token;
}						t_lexer;

char					**core_analyse(char *line);
char					**ft_strsplit_lexer(char *s, char c);

char**core_lexer(char *line, t_lexer **lexer);
int next_token(const char *line, int delim, t_lexer **lexer);
void add_node_input(const char *data, int begin, int stop, t_token **token);


#endif
