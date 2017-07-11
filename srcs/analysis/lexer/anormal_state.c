/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anormal_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 21:06:13 by ddinaut           #+#    #+#             */
/*   Updated: 2017/07/10 21:19:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyse.h"

void	missing_escape(void)
{
	ft_putendl("MISSING ESCAPE");
	return ;
}

void	escape_in_dquote(char *line, char **data, int *count, int *count2, int *statut)
{
	(*statut) = IN_ESCAPE;
	if (line[(*count) + 1] == '\0')
		missing_escape();
	else if (line[(*count) + 1] == ESCAPE || line[(*count) + 1] == DQUOTE)
		(*data)[(*count2)++] = line[++(*count)];
	else
		(*data)[(*count2)++] = line[(*count)];
	(*statut) = IN_DQUOTE;
}

void	escape_in_squote(char *line, char **data, int *count, int *count2, int *statut)
{
	(*statut) = IN_ESCAPE;
	if (line[(*count) + 1] == '\0')
		missing_escape();
	else if (line[(*count) + 1] == ESCAPE || line[(*count) + 1] == SQUOTE)
		(*data)[(*count2)++] = line[++(*count)];
	else
		(*data)[(*count2)++] = line[++(*count)];
	(*statut) = IN_SQUOTE;
}
