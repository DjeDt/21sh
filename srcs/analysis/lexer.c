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


int	count_list(t_token **token)
{
	int		count;
	t_token	*tmp;

	count = 0;
	if ((*token) != NULL)
	{
		tmp = (*token);
		while (tmp != NULL)
		{
			++count;
			tmp = tmp->next;
		}
	}
	return (count);
}

char	**list_to_tab(t_token **token)
{
	int		count;
	char	**ret;
	t_token *tmp;

	ret = NULL;
	if ((*token) != NULL)
	{
		count = 0;
		if (!(ret = (char**)malloc(sizeof(char*) * (count_list(token) + 1))))
			malloc_error("error in func list_to_tab", -1);
		tmp = (*token);
		while (tmp != NULL)
		{
			ret[count] = ft_strdup(tmp->data);
			++count;
			tmp = tmp->next;
		}
		ret[count] = NULL;
	}
	return (ret);
}

void print_list(t_token **token)
{
	t_token *tmp;

	if ((*token) != NULL)
	{
		tmp = (*token);
		while (tmp != NULL)
		{
			ft_putstr("data = ");
			ft_putendl(tmp->data);
			tmp = tmp->next;
		}
	}
}

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
	if (line[(*stop)] == '\0')
		ft_putendl("mising token");
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
}

char		**core_lexer(char *line, t_lexer **lexer)
{
	char	**ret;

	ret = NULL;

	cut_line(line, ';', lexer);
	ret = list_to_tab(&(*lexer)->token);
	return (ret);
}

/*
   phase 1 : recup les pv ;
   phase 2 : recup les pipes |
   phase 3 : recup les redi < > << >>
   phase 4 : les arguments -sdfs
*/
