/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/30 16:32:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

char	which_token(int statut)
{
	if (statut == STATE_IN_DQUOTE)
		return (DQUOTE);
	else if (statut == STATE_IN_SQUOTE)
		return (SQUOTE);
	else
		return (0);
}

void change_statut(int *statut, const char c)
{
	if (c == DQUOTE)
		(*statut) = STATE_IN_DQUOTE;
	else if (c == SQUOTE)
		(*statut) = STATE_IN_SQUOTE;
}

void search_next_token(char *tok, int *stop, char *line, int *statut)
{
	(*tok) = which_token((*statut));
	while (line[(*stop)] != '\0')
	{
		if (line[(*stop)] == (*tok))
			break ;
		(*stop)++;
	}
	while (line[(*stop)] != '\0')
	{
		if (line[(*stop)] == ';')
			break ;
		(*stop)++;
	}
	(*statut) = STATE_GENERAL;
}

void cut_line(char *line, int delim, t_lexer **lexer)
{
	int		begin;
	int		stop;
	char	tok;

	begin = 0;
	stop = -1;
	tok = 0;
	while (line[++stop] != '\0')
	{
		if (line[stop] == DQUOTE || line[stop] == SQUOTE)
		{
			change_statut(&(*lexer)->statut, line[stop]);
			search_next_token(&tok, &stop, line, &(*lexer)->statut);
			add_node_input(line, begin, stop, &(*lexer)->token);
			begin = ++stop;
		}
		if (line[stop] == delim)
		{
			add_node_input(line, begin, stop, &(*lexer)->token);
			begin = ++stop;
		}
	}
	if (begin == 0 || stop == (int)ft_strlen(line))
		add_node_input(line, begin, stop, &(*lexer)->token);
}

char		**core_lexer(char *line, t_lexer **lexer)
{
	char	**ret;

	ret = NULL;
	cut_line(line, ';', lexer);
	core_parser(&(*lexer)->token);
	ret = list_to_tab(&(*lexer)->token);
	return (ret);
}
