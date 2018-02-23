/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:51:08 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/21 14:58:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		in_squote2(const char *s, char **ret, int *count, int *count2)
{
	int	statut;

	statut = 1;
	if (s[(*count)] == '\'')
		statut = 0;
	else
		(*ret)[(*count2)++] = s[(*count)];
	return (statut);
}

int		in_dquote2(const char *s, char **ret, int *count, int *count2)
{
	int statut;

	statut = 2;
	if (s[(*count)] == '\"')
		statut = 0;
	else
		(*ret)[(*count2)++] = s[(*count)];
	return (statut);
}

int		is_quote_or_not2(const char *s, char **ret, int *count, int *count2)
{
	int statut;

	statut = 0;
	if (s[(*count)] == '\'')
		statut = 1;
	else if (s[(*count)] == '\"')
		statut = 2;
	else
		(*ret)[(*count2)++] = s[(*count)];
	return (statut);
}

char	*split_str(char *s, int len, int mode, int *statut)
{
	int		count;
	int		count2;
	char	*ret;

	count = 0;
	count2 = 0;
	ret = ft_strnew(len + 1);
	while (s[count] != '\0' && count < len)
	{
		if (mode == 1)
		{
			if ((*statut) == 0)
				(*statut) = is_quote_or_not2(s, &ret, &count, &count2);
			else if ((*statut) == 1)
				(*statut) = in_squote2(s, &ret, &count, &count2);
			else if ((*statut) == 2)
				(*statut) = in_dquote2(s, &ret, &count, &count2);
			if (s[count] == '\0')
				break ;
			count++;
		}
		else
			ret[count2++] = s[count++];
	}
	return (ret);
}
