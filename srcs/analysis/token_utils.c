/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:24:27 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 20:05:22 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "analyse.h"

static void		token_error(const char *token)
{
	ft_putstr_fd("missing token : ", 2);
	ft_putendl_fd(token, 2);
}

static t_token	*create_token(const char *data, int len)
{
	t_token *new;

	if (!(new = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in finc create_token", -1);
	if (data == NULL)
	{
		new->data = NULL;
		new->ntok = NNULL;
	}
	else
	{
		new->data = ft_strndup(data, len);
		new->ntok = 0;
	}
	new->next = NULL;
	return (new);
}

void			add_token(const char *data, int len, t_token **token)
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

	count = 0;
	while (line[count] != '\0' && ft_isspace(line[count]) == 1)
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
	while (line[count] != '\0' && line[count] != delim)
		count++;
	return (count);
}
