/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/10 19:41:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		get_environ(void)
{
	extern	char	**environ;

	g_env = ft_arrdup((const char **)environ);
}

char		*get_var_name(char *str)
{
	char	*ret;

	ret = NULL;
	if (str != NULL)
		ret = ft_strndup(str, ft_strnlen(str, '='));
	return (ret);
}

char		*get_var_value(const char *tf)
{
	size_t	count;
	char	*tmp;
	char	tc;

	count = 0;
	tmp = NULL;
	while (g_env[count] != NULL)
	{
		if ((tmp = ft_strchr(g_env[count], '=')))
		{
			tc = (*tmp);
			(*tmp) = 0;
			if (!ft_strcmp(tf, g_env[count]))
			{
				(*tmp) = tc;
				return (tmp + 1);
			}
			(*tmp) = tc;
			count++;
		}
		else
			count++;
	}
	return (NULL);
}
