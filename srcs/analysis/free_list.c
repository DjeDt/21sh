/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:57:00 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/11 17:58:22 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

void		free_token(t_token **token)
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

void		free_pipe(t_pipe **pipe)
{
	t_pipe *tmp;
	t_pipe	*tmp2;

	if ((*pipe) != NULL)
	{
		tmp = (*pipe);
		while (tmp != NULL)
		{
			ft_arrfree(&tmp->cmd);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
	}
}

void		free_command(t_command **command)
{
	t_command *tmp;
	t_command *tmp2;

	if ((*command) != NULL)
	{
		tmp = (*command);
		while (tmp != NULL)
		{
			free_pipe(&tmp->pipe);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
	}
}

