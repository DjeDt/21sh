/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_isclose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:02:50 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/10 17:50:06 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_quote_isclose_core(char *s)
{
	int		i;
	int		quote_s;
	int		quote_e;

	i = 0;
	while (s[i])
	{
		if ((quote_s = ft_isquote(s[i])) != 0)
		{
			i++;
			while (s[i])
			{
				if (((quote_e = ft_isquote(s[i])) == quote_s))
					return (0);
				i++;
			}
		}
		else
			i++;
	}
	return ((quote_s != 0) ? quote_s : 0);
}

char		*ft_strfjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s2);
	return (tmp);
}

char		*read_quote(int *ret)
{
	char	*str;

	str = NULL;
	ft_putstr("$> ");
	if (g_line != NULL)
		ft_strdel(&g_line);
	ft_init_term();
	(*ret) = ft_read_line(RD_DQUOTE, NULL);
	ft_default_term();
	str = ft_strjoin(str, g_line);
	if (g_line != NULL)
		ft_strdel(&g_line);
	return (str);
}

int			ft_quote_notclose(char **s)
{
	char	*buf;
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = read_quote(&ret);
	tmp = ft_strfjoin("\n", tmp);
	buf = ft_strjoin(*s, tmp);
	ft_strdel(s);
	ft_strdel(&tmp);
	(*s) = buf;
	return (ret);
}

void		ft_quote_isclose(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		while (ft_quote_isclose_core(argv[i]) != 0)
		{
			if (ft_quote_notclose(&argv[i]) == -1)
				break ;
		}
		i++;
	}
}
