/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:08:50 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 12:56:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			ft_parser_core(char *t, int last)
{
	t_r		*redirect;
	char	**argv;
	int		cheack;
	int		statut;

	cheack = 0;
	statut = 0;
	redirect = NULL;
	ft_redirect_reco(t, &cheack, &redirect);
	if ((redirect != NULL && redirect->red == -2) || cheack == -1)
	{
		ft_del_list_redirection(&redirect, 0);
		return (-1);
	}
	if ((argv = ft_strsplit_lexer(t, ' ', 1, &statut)) == NULL)
		exit(1);
	if (argv && (*argv))
		pre_interpreter(argv, &redirect, last);
	ft_del_list_redirection(&redirect, 0);
	ft_arraydel_2d(argv, 0);
	return (0);
}

int			ft_parser(char *cmd)
{
	int		i;
	int		ret;
	int		statut;
	char	**token;

	i = -1;
	statut = 0;
	ret = 0;
	token = ft_strsplit_lexer(cmd, '|', 0, &statut);
	if (token != NULL && token[0] != NULL)
	{
		g_flg = (token[1] != NULL) ? 1 : 0;
		ret = ft_parser_sub(token, &i);
		g_backup = 0;
	}
	if (token != NULL)
		ft_arraydel_2d(token, 0);
	return (ret);
}

int			ft_parser_sub(char **token, int *i)
{
	int		last;
	int		y;
	int		ret;

	y = *i;
	ret = 0;
	while (token[++y])
	{
		last = (token[y + 1] == NULL) ? 1 : 0;
		if ((ret = ft_parser_core(token[y], last)) == -1)
			break ;
	}
	*i = y;
	return (ret);
}
