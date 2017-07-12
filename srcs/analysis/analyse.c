/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/12 13:41:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

static void	init_lexer(t_lexer *lexer, t_command **command)
{
	lexer->statut = NORMAL_STATE;
	if (!(lexer->token = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in func init_lexer : var new->token", -1);
	(*command) = NULL;
}

char		**core_analyse(char *line, int len)
{
	char	**ret;
	t_lexer	lexer;
	t_token	*token;
	t_command *command;

	if (line == NULL)
		return (NULL);
	init_lexer(&lexer, &command);
	token = lexer.token;
	core_lexer(line, len, &lexer, token);
	core_parser(&token, &command);

	if (ft_strcmp(line, "exit") == 0)
		exit (1);

	free_lexer(&lexer);
	free_command(&command);
	ft_strdel(&line);

	ret = NULL;
	return (ret);
}
