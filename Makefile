# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/11/08 11:01:37 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make && make clean
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
