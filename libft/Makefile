#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 13:51:03 by tribeiro          #+#    #+#              #
#    Updated: 2017/08/15 17:25:59 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#################################################
###                  Settings                 ###
#################################################

NAME = libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs/
INC_PATH = -I./includes/

#################################################
###                  Colors                   ###
#################################################

COL_BLACK  = \033[1;30m
COL_RED    = \033[1;31m
COL_GREEN  = \033[1;32m
COL_YELLOW = \033[1;33m
COL_BLUE   = \033[1;34m
COL_PURPLE = \033[1;35m
COL_WHITE  = \033[1;37m

#################################################
###                 Sources                   ###
#################################################

SRC =\
\
str/ft_isalnum.c \
str/ft_isalpha.c \
str/ft_isascii.c \
str/ft_isdigit.c \
str/ft_isprint.c \
str/ft_tolower.c \
str/ft_toupper.c \
str/ft_isquote.c \
\
conv/ft_atoi.c \
conv/ft_itoa.c \
conv/ft_itoa_base.c \
conv/ft_atl.c \
\
lst/ft_create_elem.c \
lst/ft_push_back.c \
lst/ft_lstadd.c \
lst/ft_lstdel.c \
lst/ft_lstdelone.c \
lst/ft_lstiter.c \
lst/ft_lstmap.c \
lst/ft_lstnew.c \
lst/ft_lst_size.c \
lst/ft_lst_sort_content.c \
\
mem/ft_bzero.c \
mem/ft_memalloc.c \
mem/ft_memcpy.c \
mem/ft_memdel.c \
mem/ft_memchr.c \
mem/ft_memcmp.c \
mem/ft_memccpy.c \
mem/ft_memmove.c \
mem/ft_memset.c \
mem/ft_realloc_char.c\
\
print/ft_putchar.c \
print/ft_putnchar.c \
print/ft_putchar_fd.c \
print/ft_putendl.c \
print/ft_putendl_fd.c \
print/ft_putendl_array2d.c \
print/ft_putendl_list.c \
print/ft_putnbr.c \
print/ft_putnbr_fd.c \
print/ft_putstr.c \
print/ft_putstr_fd.c \
print/ft_putaddr.c \
print/ft_putbase.c \
print/ft_puthex.c \
print/ft_print_binary.c \
\
str/ft_strcat.c \
str/ft_strchr.c \
str/ft_strclr.c \
str/ft_strcmp.c \
str/ft_strcpy.c \
str/ft_strdel.c \
str/ft_strdup.c \
str/ft_strequ.c \
str/ft_striter.c \
str/ft_striteri.c \
str/ft_strjoin.c \
str/ft_strlcat.c \
str/ft_strlen.c \
str/ft_strmap.c \
str/ft_strmapi.c \
str/ft_strncat.c \
str/ft_strncmp.c \
str/ft_strncpy.c \
str/ft_strnequ.c \
str/ft_strnew.c \
str/ft_strnstr.c \
str/ft_strrchr.c \
str/ft_strrev.c \
str/ft_strsplit.c \
str/ft_strstr.c \
str/ft_strsub.c \
str/ft_strjoin1.c \
str/ft_strjoin_1.c \
str/ft_strjoin2.c \
str/ft_strmerge.c \
str/ft_strtrim.c\
str/ft_split_whitspaces.c\
str/get_next_line.c\
\
array/ft_arraydel_2d.c\
array/ft_arraysize_2d.c

#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_PATH), $(SRC))
O = $(notdir $(SRC))
OB = $(basename $(O))
OBJ = $(addsuffix .o ,$(OB))

#################################################
###                   Rules                   ###
#################################################

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	@echo "$(COL_YELLOW)[    BUILDING LIBFT    ]\n"
	@$(CC) -c $(FLAGS) $(INC_PATH) $(SRCS)
	@echo "$(COL_YELLOW)->$(COL_BLACK) compilation done."
	@echo "$(COL_YELLOW)-> $(COL_BLACK)object created."

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@echo "$(COL_YELLOW)-> $(COL_BLACK)$@ created."
	@ranlib $@
	@echo "$(COL_YELLOW)-> $(COL_BLACK)$@ sorted.\n"

clean:
	@echo "$(COL_YELLOW)[    CLEANING LIBFT    ]\n"
	@rm -rf $(OBJ)
	@echo "$(COL_YELLOW)-> $(COL_BLACK)object removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(COL_YELLOW)-> $(COL_BLACK)$(NAME) removed.\n"

re: fclean all
