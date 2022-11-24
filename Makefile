# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/11/24 19:17:20 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c ./operations/ft_swap.c \
		./operations/ft_push.c \
		./operations/ft_rotate.c \
		./operations/ft_reverse_rotate.c \
		./struct/t_stack.c \
		./struct/t_stack_utils.c \
		./struct/t_stacks.c \
		./struct/index.c \
		./sort/sort.c \
		./sort/sort_utils.c \
		./sort/sort_utils2.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@git clone https://github.com/LaurinUB/libft
	@cd libft && make && make clean

debug : CFLAGS += -g

debug : re

san : CFLAGS +=  -g -fsanitize=address

san : re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft

re: fclean all

.PHONY: all clean fclean re
