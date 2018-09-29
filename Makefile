# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:25:50 by lucien            #+#    #+#              #
#    Updated: 2018/09/26 18:04:03 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC_D	= src
SRC	=	main.c						\
		parser/init_parsing.c		\
		parser/parse_links.c		\
		parser/parse_else.c			\
		parser/parse_rooms.c		\
		print_ants/print_ant.c		\
		print_ants/init_print_ant.c	\
		parser/error.c				\
		print_ants/paths.c			\
		utils/test/print_struct.c	\
		utils/free/free_lst.c

OBJ_D	= obj
OBJ		= $(addprefix $(OBJ_D)/,$(SRC:.c=.o))

LIB_D	:=	libft
LIBFTA	:= $(LIB_D)/libft.a
PRINTFA := $(LIB_D)/libftprintf.a
LIBINCL := -I$(LIB_D)/includes
LIBLINK	:= -L$(LIB_D) -lft -lftprintf

# TERMINAL COMMANDS
RM		:= /bin/rm -rf
MD		:= mkdir -p

# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

all: $(LIB_D) $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.c
	@$(MD) $(OBJ_D)
	@$(MD) $(OBJ_D)/utils
	@$(MD) $(OBJ_D)/utils/free
	@$(MD) $(OBJ_D)/utils/test
	@$(MD) $(OBJ_D)/parser
	@$(MD) $(OBJ_D)/print_ants
	@$(CC) $(CFLAGS) $(LIBINCL) -I includes -o $@ -c $<
	@echo "$(LOG_CLEAR)	👉  add $@	✅ $(LOG_NOCOLOR)"

$(LIB_D): $(LIBFTA) $(PRINTFA)

$(LIBFTA):
	@make -C ./libft
	@echo "\n"
	@echo "$(LOG_GREEN)$(LOG_CLIGNO)Begin compilation $(NAME) ...$(LOG_NOCOLOR)"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBLINK) $(CFLAGS)
	@echo "$(LOG_VIOLET)$(LOG_CLIGNO)$(NAME) compile successfully $(LOG_NOCOLOR)"

clean:
	@$(RM) $(OBJ_D)
	@make -C $(LIB_D)/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIB_D)/ fclean

re: fclean all

.PHONY: all clean fclean re
