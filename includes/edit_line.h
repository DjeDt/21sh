/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:23:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/08/15 17:23:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_LINE_H
# define EDIT_LINE_H

# include "main.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <term.h>
# include <ncurses.h>
# include <unistd.h>
# include <sys/ioctl.h>

/*
**  DEBIAN
*/

# include <sys/types.h>
# include <sys/wait.h>

# define OPEN_HIST "/tmp/.history", O_CREAT | O_RDWR | O_APPEND, 0644
# define SHELL 1
# define RD_HEREDOC 2
# define RD_SQUOTE 3
# define RD_DQUOTE 4
# define RD_ESCAPE 5

void				ft_init_prompt(void);
void				ft_prompt(void);
void				prompt(void);
void				ft_init_term(void);
void				ft_default_term(void);

char				*g_buf_cut;

typedef struct		s_hist
{
	int				cur;
	char			*value;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_line
{
	struct winsize	w;
	int				cur;
	int				lmax;
	char			*buf;
	int				prompt_size;
	int				cur_hist;
	int				max_hist;
	int				fd_hist;
	char			*buf_hist;
	t_hist			*hist;
}					t_line;

t_line				g_lstruct;

int					ft_read_line(int where, int *statut);
void				ft_init_tline(t_line *l);
void				ft_realloc_line(t_line *l);
int					ft_end(t_line *l, char tmp);

void				ft_error_line(t_line *l);
void				ft_read_fail(char **line, char *txt);

void				reset_pos(int i);

int					check_special_case(int where, char tmp, int *statut);
void				ft_keys_nav(t_line *l, int *i, char tmp);
void				ft_maj_keys(t_line *l, int *i, char tmp);

void				ft_right_arrow(t_line *l);
void				ft_left_arrow(t_line *l);
void				ft_top_arrow(t_line *l);
void				ft_down_arrow(t_line *l, int i);

void				ft_maj_left_arrow(t_line *l);
void				ft_maj_right_arrow(t_line *l, int i);
void				ft_maj_top_arrow(t_line *l);
void				ft_maj_down_arrow(t_line *l, int i);

void				ft_addchar(int *i, t_line *l, char tmp);
void				ft_delchar(t_line *l, int *i);
void				ft_delchar_rev(t_line *l, int *i);

void				ft_go_end(t_line *t, int i);
void				ft_go_begin(t_line *t);
int					ft_ctrl_d(t_line *l, int *i, char *tmp, int where);

void				ft_shortcuts_keyboard(t_line *l, int *i, char tmp);
void				ft_cut_line(t_line *l, int *i);
void				ft_past_line(t_line *l, int *i);

void				ft_clear(void);

t_hist				*create_hist(const char *str, int cur);
int					read_hist(const int fd, char **buf);
void				free_hist(t_hist **hist);
void				init_hist(t_line *line);
void				add_hist(const char *str, int cur, t_hist **hist);
int					count_hist(t_hist **hist);
void				maj_hist(t_line *line);
void				save_current_buf(t_line *line);

int					history_up(t_line *line, int *i, t_hist **hist);
int					history_down(t_line *line, int *i, t_hist **hist);

void				free_readline(t_line *line);

#endif
