# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/11/18 09:17:34 by luntiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c ./operations/ft_swap.c \
		./operations/ft_push.c \
		./operations/ft_rotate.c \
		./operations/ft_reverse_rotate.c \
		./utils/t_stack.c \
		./utils/t_stack_utils.c \
		./utils/t_stacks.c \
		./utils/index.c \
		./printer/printing.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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
