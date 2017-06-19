/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/19 15:54:30 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexer.h"

/* Fonction pour aller au prochain token */
void	next(t_token *test, char *line)
{
	if (*line)
		test->tok = (*line)++;
	return ;
}

void	expression(int level)
{
	(void)level;
	return ;
	/* */
}

void	global_declaration(t_token *test, char *line)
{

}

void	program(t_token *test, char *line)
{
	next(test, line);
	while (test->tok > 0)
	{
		ft_putstr("token = ");
		ft_putchar(test->tok);
		ft_putchar('\n');
		global_declaration(test, line);
//		next(test, line);
	}
	return ;
}

t_token	*init_token(void)
{
	t_token *new;

	if (!(new = (t_token*)malloc(sizeof(t_token))))
		malloc_error("error in file parse_line.c -> func init_token", -1);
	else
	{
		new->tok = 0;
		new->src = NULL;
		new->old_src = NULL;
		new->next = NULL;
	}
	return (new);
}

char	**parse_input(char *line)
{
	char	**ret;
	t_token	*test;

	ret = NULL;
	test = init_token();
	if (line == NULL)
		return (NULL);
	else
	{
		program(test, line);
		ft_putstr("\n\n");
		ret = ft_strsplit(line, ';');
		free(line);
	}
	return (ret);
}
