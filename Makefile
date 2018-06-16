# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucien <lucien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:25:50 by lucien            #+#    #+#              #
#    Updated: 2018/06/15 14:48:14 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem_in

SRC	=	lem_in.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft
LIBLINK	= -L./libft -lft

all: obj libft $(NAME)

obj:
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
