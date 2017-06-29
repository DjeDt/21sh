/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 16:39:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "analyse.h"


#include <stdio.h>

/*
static int		search_token_type(const char c)
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
*/

static t_token	*create_token(const char *data, int len)
{
	t_token *new;

	if (!(new = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in finc create_token", -1);
	if (data == NULL)
		new->data = NULL;
	else
		new->data = ft_strndup(data, len);
	new->next = NULL;
	return (new);
}

static void	add_token(const char *data, int len, t_token **token)
{
	t_token	*tmp;

	tmp = NULL;
	if (!(*token))
		(*token) = create_token(data, len);
	else
	{
		tmp = (*token);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_token(data, len);
	}
}

void print_list(t_token **token)
{
	t_token *tmp;

	tmp = (*token);
	while (tmp != NULL)
	{
		printf("data = %s\n", tmp->data);
		tmp = tmp->next;
	}
}

static int		next_token2(const char *line, int *statut)
{
	int count;

	count = 0;
	if ((*statut) == STATE_IN_DQUOTE)
	{
		count = ft_strnlen(line, DQUOTE);
		(*statut) = STATE_GENERAL;
	}
	else if ((*statut) == STATE_IN_SQUOTE)
	{
		count = ft_strnlen(line, SQUOTE);
		(*statut) = STATE_GENERAL;
	}
	return (count);
}

static int		next_token(const char *line, int delim, t_lexer **lexer)
{
	int		count;

	count = 0;
	while (ft_isspace(line[count]) == 1)
		count++;
	while (line[count] != '\0')
	{
		if (line[count] == DQUOTE)
			(*lexer)->statut = STATE_IN_DQUOTE;
		else if (line[count] == SQUOTE)
			(*lexer)->statut = STATE_IN_SQUOTE;
		else if ((*lexer)->statut != STATE_GENERAL)
			count += next_token2(line + count, &(*lexer)->statut);
		if ((*lexer)->statut == STATE_GENERAL && line[count] == delim)
		{
			while (ft_isspace(line[count]) == 1)
				count--;
			break ;
		}
		count++;
	}
	add_token(line, count, &(*lexer)->token);
	while (line[count] != delim && line[count] != '\0')
		count++;
	return (count);
}

char	**core_lexer(char *line, t_lexer **lexer)
{
	int		count;
	char	**ret;

	count = 0;
	ret = NULL;
	while (line[count] != '\0')
		count += next_token(line + count, ';', lexer) + 1;
	ret = ft_strsplit(line, ';');
	return (ret);
}

/*
   phase 1 : recup les pv ;   DONE
   phase 2 : recup les pipes |
   phase 3 : recup les redi < > << >>
   phase 4 : les arguments -sdfs
*/
