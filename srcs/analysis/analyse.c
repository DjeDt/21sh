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
	new->statut = STATE_GENERAL;
	new->token = NULL;
	return (new);
}

char			**core_analyse(char *line)
{
	char	**ret;
	t_lexer	*lexer;

	if (line == NULL)
		return (NULL);
	lexer = init_lexer();
	ret = core_lexer(line, &lexer);
	free_lexer(&lexer);
	ft_strdel(&line);
	return (ret);
}
