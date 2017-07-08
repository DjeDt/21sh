/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 19:57:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

static void		free_token(t_token **token)
{
	t_token *tmp;
	t_token	*tmp2;

	if ((*token) != NULL)
	{
		tmp = (*token);
		while (tmp != NULL)
		{
			ft_strdel(&tmp->data);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
	}
}

void		free_lexer(t_lexer *lexer)
{
	if (lexer != NULL)
		free_token(&lexer->token);
}

static void	init_lexer(t_lexer *lexer)
{
	lexer->statut = NORMAL_STATE;
	if (!(lexer->token = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in func init_lexer : var new->token", -1);
}

static void print(t_token **tok)
{
#include <stdio.h>

	t_token *tmp;

	tmp = *tok;
	while (tmp != NULL)
	{
		printf("\ndata = %s\ntype=%d\n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

char			**core_analyse(char *line)
{
	char	**ret;
	t_lexer	lexer;
	t_token	*token;

	if (line == NULL)
		return (NULL);
	init_lexer(&lexer);
	token = lexer.token;
	core_lexer(line, ft_strlen(line), &lexer, token);
	ret = NULL;
	print(&lexer.token);
	free_lexer(&lexer);
	ft_strdel(&line);
	return (ret);
}
