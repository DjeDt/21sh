#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 17:23:34 by ddinaut           #+#    #+#              #
#    Updated: 2018/02/23 16:45:13 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#################################################
###                  Settings                 ###
#################################################

NAME = 21sh
CC = clang
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

INC_PATH = includes/
LIB_PATH = Libft/

SRCDIR= srcs/
OBJDIR = object/

#################################################
###                  Colors                   ###
#################################################

BLACK  = "\033[1;30m"
RED    = "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE  = "\033[1;37m"
ENDCOL = "\033[0m"

CLEAR = "\033[2K"
UP =	"\033[A"
DEF	=	"\033[0;0m"

#################################################
###                 Sources                   ###
#################################################

SRC =	$(SRCDIR)main.c \
\
		$(SRCDIR)edit_line/ft_prompt.c\
		$(SRCDIR)edit_line/prompt.c\
		$(SRCDIR)edit_line/term.c\
		$(SRCDIR)edit_line/ft_line.c\
		$(SRCDIR)edit_line/ft_read_line.c\
		$(SRCDIR)edit_line/ft_error_line.c\
		$(SRCDIR)edit_line/read_special_case.c\
		$(SRCDIR)edit_line/ft_keys.c\
		$(SRCDIR)edit_line/ft_keys_ctrl.c\
		$(SRCDIR)edit_line/ft_keys_maj.c\
		$(SRCDIR)edit_line/ft_keys_arrow.c\
		$(SRCDIR)edit_line/ft_shortcuts_keyboad.c\
		$(SRCDIR)edit_line/hist_utils.c\
		$(SRCDIR)edit_line/history.c\
		$(SRCDIR)edit_line/ft_strftrim.c\
		$(SRCDIR)edit_line/free_readline.c \
\
		$(SRCDIR)lexer/ft_strsplit_lexer.c\
		$(SRCDIR)lexer/lexer_utils.c\
\
		$(SRCDIR)parser/ft_parser.c\
		$(SRCDIR)parser/add_missing_char.c \
		$(SRCDIR)parser/analyse_redirection.c\
		$(SRCDIR)parser/ft_redirection_reco.c\
		$(SRCDIR)parser/ft_redirect_add.c\
\
		$(SRCDIR)interpreter/ft_interpreter.c\
		$(SRCDIR)interpreter/pipe_utils.c \
		$(SRCDIR)interpreter/ft_identification_builtins.c\
		$(SRCDIR)interpreter/ft_identification_bin.c\
\
		$(SRCDIR)builtins/ft_cd.c\
		$(SRCDIR)builtins/ft_echo.c\
		$(SRCDIR)builtins/ft_env.c\
		$(SRCDIR)builtins/env_utils.c\
		$(SRCDIR)builtins/ft_envexec.c\
		$(SRCDIR)builtins/ft_env_i.c\
		$(SRCDIR)builtins/ft_exit.c\
		$(SRCDIR)builtins/ft_setenv.c\
		$(SRCDIR)builtins/ft_unsetenv.c\
		$(SRCDIR)builtins/ft_pwd.c\
\
		$(SRCDIR)tools/ft_envdup.c\
		$(SRCDIR)tools/ft_searchenv.c\
		$(SRCDIR)tools/ft_isatty.c\
		$(SRCDIR)tools/gnl_dje.c \
		$(SRCDIR)tools/gnl_utils.c \
		$(SRCDIR)tools/ft_strjoin_f2.c \
		$(SRCDIR)tools/ft_count_char.c \
		$(SRCDIR)tools/ft_arraydup_2d.c \
\
		$(SRCDIR)signals/ft_signals.c\
\
		$(SRCDIR)error/ft_error.c\
		$(SRCDIR)error/ft_error_basics.c\
\
		$(SRCDIR)redirection/ft_create_elem_redirection.c\
		$(SRCDIR)redirection/ft_push_back_redirection.c\
		$(SRCDIR)redirection/ft_del_elem_redirection.c\
		$(SRCDIR)redirection/ft_del_list_redirection.c\
		$(SRCDIR)redirection/ft_redirect_handler.c\
		$(SRCDIR)redirection/check_file.c \
		$(SRCDIR)redirection/heredoc/core_heredoc.c

#################################################
###                   Format                  ###
#################################################

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC = -I./$(INC_PATH) -I./$(LIB_PATH)$(INC_PATH)
LIB = -L./$(LIB_PATH) -lft

#################################################
###                   Rules                   ###
#################################################

.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ) -o $@ $(LIB) $(INC) -lncurses

$(OBJDIR)%.o: $(SRCDIR)%.c $(CHECK)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)edit_line
	@mkdir -p $(OBJDIR)lexer
	@mkdir -p $(OBJDIR)parser
	@mkdir -p $(OBJDIR)interpreter
	@mkdir -p $(OBJDIR)builtins
	@mkdir -p $(OBJDIR)tools
	@mkdir -p $(OBJDIR)error
	@mkdir -p $(OBJDIR)signals
	@mkdir -p $(OBJDIR)redirection
	@mkdir -p $(OBJDIR)redirection/heredoc
	$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(CHECK):
	@echo "create  $(OBJDIR)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)edit_line
	@mkdir -p $(OBJDIR)lexer
	@mkdir -p $(OBJDIR)parser
	@mkdir -p $(OBJDIR)interpreter
	@mkdir -p $(OBJDIR)builtins
	@mkdir -p $(OBJDIR)tools
	@mkdir -p $(OBJDIR)error
	@mkdir -p $(OBJDIR)signals
	2mkdir -p $(OBJDIR)redirection

%.c:
	@echo "$(COL_RED) Missing file -> $@\n"

clean:
	@make -C $(LIB_PATH) clean
	@echo $(YELLOW)"[    CLEANING LIBFT    ]\n"$(DEF)
	@rm -rf $(OBJDIR)
	@echo $(YELLOW)"-> "$(BLACK)"object removed."

fclean: clean
	@rm -f $(NAME)
	@printf $(YELLOW)"-> "$(BLACK)"$(NAME) removed.\n"

re: fclean all
