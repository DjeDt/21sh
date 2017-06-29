/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/29 20:08:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

static int	count_list(t_token **token)
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

static char	**list_to_tab(t_token **token)
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
/*
static void print_list(t_token **token)
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
*/
char		**core_lexer(char *line, t_lexer **lexer)
{
	int		count;
	char	**ret;

	count = 0;
	ret = NULL;
	while (line[count] != '\0')
		count += next_token(line + count, ';', lexer) + 1;
	/*
	print_list(&(*lexer)->token);
	ft_putstr("\n\n\n");
	*/
	ret = list_to_tab(&(*lexer)->token);
	return (ret);
}

/*
   phase 1 : recup les pv ;   DONE
   phase 2 : recup les pipes |
   phase 3 : recup les redi < > << >>
   phase 4 : les arguments -sdfs
*/
