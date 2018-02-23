/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:07:13 by tribeiro          #+#    #+#             */
/*   Updated: 2016/08/06 09:58:30 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		count;
	int		end;
	char	tmp;

	count = 0;
	end = 0;
	while (str[end] != 0)
		end++;
	end--;
	while (end > count)
	{
		tmp = str[count];
		str[count] = str[end];
		str[end] = tmp;
		end--;
		count++;
	}
	return (str);
}
