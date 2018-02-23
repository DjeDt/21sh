/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:04:09 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/15 19:18:40 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "main.h"

typedef struct		s_hered
{
	char			*data;
	struct s_hered	*next;
}					t_hered;

typedef struct		s_r
{
	int				fd;
	int				r_fd;
	int				r_close;
	int				red;
	int				error;
	char			*file;
	struct s_r		*next;
}					t_r;

#endif
