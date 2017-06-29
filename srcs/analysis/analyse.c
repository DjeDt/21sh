/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 16:39:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "analyse.h"

static void		free_token(t_token **token)
{
	t_token *tmp;

	if ((*token) != NULL)
	{
		tmp = (*token);
		while (tmp->next != NULL)
		{
			ft_strdel(&tmp->data);
			tmp = tmp->next;
		}
	}
}

static void		free_lexer(t_lexer **lexer)
{
	if ((*lexer) != NULL)
	{
		free_token(&(*lexer)->token);
		free((*lexer));
	}
}

static t_lexer	*init_lexer(void)
{
	t_lexer *new;

	if (!(new = (t_lexer*)malloc(sizeof(t_lexer))))
		malloc_error("error in func init_lexer", -1);
	new->c = 0;
	new->i_tok = 0;
	new->statut = STATE_GENERAL;
	new->token = NULL;
	return (new);
}

char		**core_analyse(char *line)
{
	char	**ret;
	t_lexer	*lexer;

	if (line == NULL)
		return (NULL);
	lexer = init_lexer();
	ret = core_lexer(line, &lexer);
	ft_strdel(&line);
	free_lexer(&lexer);
	return (ret);
}
