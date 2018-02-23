/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:02:37 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/30 18:44:22 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# define HEX "0123456789abcdef"

void				ft_putchar(char c);
void				ft_putnchar(char c, int n);
void				ft_putchar_fd(char c, int fd);

void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_list(t_list **list);
void				ft_putendl_array2d(char ***array);
void				ft_putnbr(int n);

void				ft_putaddr(void *ptr);
void				ft_putbase(int n, int b);
void				ft_puthex(unsigned long l);
void				ft_print_binary(void *data, size_t size);

#endif
