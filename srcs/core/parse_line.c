/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:02 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/16 20:28:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char	**parse_input(char *line)
{
	char **ret;

	ret = NULL;
	if (line == NULL)
		return (NULL);
	else
	{
		ret = split_line(line, ';');
		free(line);
	}
	return (ret);
}
