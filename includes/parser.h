/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:09:50 by tribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 11:32:10 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "main.h"

int				ft_parser(char *cmd);
int				ft_parser_core(char *t, int last);
int				ft_parser_sub(char **token, int *i);
int				ft_replace(char **s, int *statut);

int				ft_quote_replace_blank(char **argv);
void			ft_quote_isclose(char **argv);
int				ft_quote_isclose_core(char *argv);
int				ft_quote_notclose(char **argv);
int				add_missing_char(char **s, int *statut);
void			ft_redirect_reco(char *argv, int *cheack, t_r **begin_list);
void			del_elem(t_r **elem, int *check);

void			ft_argvadd_blanck(char *argv, int red, int *y, int *fd);
int				ft_fdleft(char c, char c2, int *fd);
int				ft_fdright(char *argv, int *i, t_r *elem, int red);
int				ft_file_redirection(char *argv, int *i, t_r *elem);
int				ft_isredirection(char *s, int count);
int				ft_file_red(char *argv, int *i, t_r *elem, t_r **begin_list);
#endif
