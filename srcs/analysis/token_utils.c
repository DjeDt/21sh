/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:24:27 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/30 15:52:37 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "analyse.h"

/* static void		token_error(const char *token) */
/* { */
/* 	ft_putstr_fd("missing token : ", 2); */
/* 	ft_putendl_fd(token, 2); */
/* } */


static t_token	*create_node_input(const char *data, int begin, int stop)
{
	t_token *new;

	if (!(new = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in func create_token", -1);
	if (data == NULL)
	{
		new->data = NULL;
		new->type = NNULL;
	}
	else
	{
		new->data = ft_strndup(data + begin, stop);
		new->type = 0;
	}
	new->next = NULL;
	return (new);
}

void			add_node_input(const char *data, int begin, int stop, t_token **token)
{
	t_token	*tmp;

	tmp = NULL;
	if (!(*token))
		(*token) = create_node_input(data, begin, stop);
	else
	{
		tmp = (*token);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_node_input(data, begin, stop);
	}
}
/*
static int		next_token2(const char *line, int *statut)
{
	int	count;
	int	max;

	count = 0;
	max = ft_strlen(line);
	if ((*statut) == STATE_IN_DQUOTE)
	{
		count = ft_strnlen(line, DQUOTE);
		if (count == max)
			token_error("\"");
		else
			(*statut) = STATE_GENERAL;
	}
	else if ((*statut) == STATE_IN_SQUOTE)
	{
		count = ft_strnlen(line, SQUOTE);
		if (count == max)
			token_error("'");
		else
			(*statut) = STATE_GENERAL;
	}
	return (count);
}

int				next_token(const char *line, int delim, t_lexer **lexer)
{
	int		count;
	char	*tmp;

	count = 0;
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
			break ;
		}
		count++;
	}
	tmp = clear_input(line, count);
	add_node_input(line, count, &(*lexer)->token);
	return (count);
}
*/
