# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/22 17:46:43 by abellion          #+#    #+#              #
#    Updated: 2015/03/26 20:28:30 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =		srcs/main.c \
			srcs/parser_controller.c \
			srcs/parser_make_parts.c \
			srcs/parser_checker.c \
			srcs/parser_make_termes.c \
			srcs/parser_sort_termes.c \
			srcs/parser_lst_manager.c \
			srcs/reduced_controller.c \
			srcs/termes_manager.c \
			srcs/polynomial_controller.c \
			srcs/operations_termes.c \
			srcs/solver_deg0.c \
			srcs/solver_deg1.c \
			srcs/solver_deg2.c \
			srcs/math.c \

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = computor

all: $(SOFT_NAME)

$(SOFT_NAME): $(SRC_C)
	make -C libft/
	gcc -g -Wall -Wextra -Werror -I libft/includes/ -c $(SRC_C)
	gcc -o $(SOFT_NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(SOFT_NAME)

re: fclean all
