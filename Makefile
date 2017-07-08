#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 14:14:43 by ddinaut           #+#    #+#              #
#    Updated: 2017/06/29 18:33:45 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output #
NAME =	21sh

# Compilation #
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
ADDFLAGS	=

# Directories #
OBJ_PATH = obj
SRC_PATH = srcs
LIB_PATH = libft
INC_PATH = includes/

# Sub_dirs #
CORE	= core/
BUILTIN = builtin/
READLINE = readline/
ANALYSIS = analysis/

# Sub sub dirs #
LEXER = $(ANALYSIS)lexer/
PARSER = $(ANALYSIS)parser/

# Colors #
BLACK  = \033[1;30m
RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
WHITE  = \033[1;37m
END_COL= \033[0m

LIBFT		= -L $(LIB_PATH)
LIBS		= $(LIBFT) -lft
INCLUDES	= -I./ -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH)

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Sources #
SRCS =	$(CORE)main.c \
		$(CORE)print_swag.c \
		$(CORE)env_utils.c \
		$(CORE)ft_prog.c \
		$(CORE)error.c \
		$(CORE)term_utils.c \
\
		$(BUILTIN)builtin_env.c \
		$(BUILTIN)builtin_env2.c \
		$(BUILTIN)builtin_echo.c \
		$(BUILTIN)builtin_setenv.c \
		$(BUILTIN)builtin_unsetenv.c \
		$(BUILTIN)builtin_exit.c \
		$(BUILTIN)builtin_cd.c \
\
		$(READLINE)change_term_mode.c \
		$(READLINE)read_line.c \
		$(READLINE)match_key.c \
		$(READLINE)add_char.c \
		$(READLINE)cursor_move.c \
		$(READLINE)key_delete.c \
		$(READLINE)history.c \
		$(READLINE)hist_utils.c \
\
		$(ANALYSIS)analyse.c \
		$(ANALYSIS)lexer.c \
		$(ANALYSIS)is_token.c
# 		$(LEXER)lexer.c \
# 		$(LEXER)token_utils.c \
# \
# 		$(PARSER)parser.c \
# 		$(PARSER)pipe_utils.c \
# 		$(PARSER)shell_split.c


# Rules #
.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ) $(LIBS)
	@printf "$(PURPLE)- 21sh completed -\n$(END_COL)"

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
	@printf "$(GREEN)%s -> %s                                \r$(END_COL)" $@ $<

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
