/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:44:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/26 16:33:40 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "analyse.h"

char		**core_analyse(char *line)
{
	char	**ret;
	t_token	*token;

	if (line == NULL)
		return (NULL);
	token = NULL;
	ret = core_lexer(line, &token);
	ft_strdel(&line);
	return (ret);
}
