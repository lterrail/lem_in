# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucien <lucien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:25:50 by lucien            #+#    #+#              #
#    Updated: 2018/06/27 19:10:46 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC	=	main.c							\
		read_map.c						\
		exit_func.c						\
		check_errors.c					\
		parsing/process_find_paths.c	\
		parsing/delete_link.c			\
		parsing/next_solution.c			\
		parsing/backtracking.c			\
		parsing/no_path.c				\
		print/process_ants.c			\
		print/clear_solucs.c			\
		print/print_ants.c				\
		utils/ft_strstr.c				\
		utils/ft_cpy.c					\
		utils/ft_add.c					\
		utils/ft_remove.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft
LIBLINK	= -L./libft -lft

all: obj libft $(NAME)

obj:
	mkdir -p ./obj/utils/
	mkdir -p ./obj/parsing/
	mkdir -p ./obj/print/
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	$(CC) $(CFLAGS) $(LIBINCL) -Iincludes -o $@ -c $<

libft: $(LIBFTA)

$(LIBFTA):
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	rm -rf ./obj/
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
