# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/11/10 10:48:51 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c ./utils/ft_swap.c \
		./utils/ft_getnode.c \
		./utils/ft_getlstcontent.c \
		./utils/ft_push.c \
		./utils/ft_rotate.c \
		./utils/ft_reverse_rotate.c \
		./utils/t_stack.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@cd libft && make && make clean

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
