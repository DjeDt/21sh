/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/10 21:34:52 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"
#include <stdio.h>

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

static void		free_lexer(t_lexer *lexer)
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
	t_token *tmp;

	tmp = *tok;
	while (tmp != NULL)
	{
		printf("\ndata = %s\ntype=%d\n", tmp->data, tmp->type);
		tmp = tmp->next;
	}
}

char			**core_analyse(char *line, int len)
{
	char	**ret;
	t_lexer	lexer;
	t_token	*token;
	t_command *command;

	if (line == NULL)
		return (NULL);
	command = NULL;
	init_lexer(&lexer);
	token = lexer.token;
	core_lexer(line, len, &lexer, token);
	core_parser(&token, command);

	if (ft_strcmp(line, "exit") == 0)
		exit (1);


	print(&lexer.token);
	free_lexer(&lexer);
	ft_strdel(&line);


	ret = NULL;
	return (ret);
}
