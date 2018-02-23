/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:49:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/21 16:47:32 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"

/*
**	mode == 0 ? garde les quotes
**	mode == 1 ? supprime les quotes
*/

int		ft_nbrword(char *s, char c)
{
	int		nbr_word;
	int		quote;
	int		buf;
	int		i;

	nbr_word = 0;
	i = 0;
	buf = 0;
	while (s != NULL && s[i])
	{
		if (i == 0 && s[i] != c)
			nbr_word++;
		else if (i > 0 && s[i - 1] == c && s[i] != c)
			nbr_word++;
		if ((quote = ft_isquote(s[i])) != 0)
			while ((s[i]) && ((buf = ft_isquote(s[++i])) != quote))
			{
				if (s[i] == 0)
					return (nbr_word);
			}
		i++;
	}
	return (nbr_word);
}

int		ft_strlensplit(char *s, char c)
{
	int		i;
	char	quote;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quote = s[i++];
			while (s[i] != '\0' && s[i] != quote)
				++i;
		}
		++i;
	}
	return (i);
}

void	init_split(int *cpt_word, int *i, int *len, char ***ret)
{
	(*cpt_word) = 0;
	(*i) = 0;
	(*len) = 0;
	(*ret) = NULL;
}

char	**ft_strsplit_lexer(char *s, char c, int mode, int *statut)
{
	char	**ret;
	int		nbr_word;
	int		cpt_word;
	int		i;
	int		len;

	init_split(&cpt_word, &i, &len, &ret);
	nbr_word = ft_nbrword(s, c);
	if ((!s) || (!(ret = (char **)malloc(sizeof(char*) * (nbr_word + 1)))))
		return (NULL);
	while (cpt_word < nbr_word)
	{
		while (s[i] == c)
			i++;
		len = ft_strlensplit(&(s[i]), c);
		if ((ret[cpt_word] = split_str(&s[i], len, mode, statut)) == NULL)
			return (NULL);
		if (statut != 0)
			add_missing_char(&ret[cpt_word], statut);
		i += len;
		cpt_word++;
	}
	ret[cpt_word] = NULL;
	return (ret);
}
