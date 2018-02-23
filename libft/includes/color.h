/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 22:11:53 by tribeiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:21:14 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
**	TEXT ATTRIBUTES
*/

# define TA_ALLOFF		"\033[00m"
# define TA_BOLD		"\033[01m"
# define TA_UNDERSCORE	"\033[04m"
# define TA_BLINK		"\033[05m"
# define TA_REVVIDEO	"\033[07m"
# define TA_CONCEALED	"\033[08m"

/*
**	FOREGROUND COLORS
*/

# define FC_BLACK	"\033[30m"
# define FC_RED		"\033[31m"
# define FC_GREEN	"\033[32m"
# define FC_YELLOW	"\033[33m"
# define FC_BLUE	"\033[34m"
# define FC_MAGENTA "\033[35m"
# define FC_CYAN	"\033[36m"
# define FC_RED		"\033[31m"
# define FC_WHITE	"\033[37m"

/*
**	BACKGROUND COLORS
*/

# define BC_BLACK	"\033[40m"
# define BC_RED		"\033[41m"
# define BC_GREEN	"\033[42m"
# define BC_YELLOW	"\033[43m"
# define BC_BLUE	"\033[44m"
# define BC_MAGENTA "\033[45m"
# define BC_CYAN	"\033[46m"
# define BC_RED		"\033[41m"
# define BC_WHITE	"\033[47m"

# define CLR_COLOR "\033[00m"

#endif
