# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/12/16 13:00:51 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = ./src/push_swap.c \
		./src/utils.c \
		./src/ft_swap.c \
		./src/ft_push.c \
		./src/ft_rotate.c \
		./src/ft_reverse_rotate.c \
		./src/t_stack.c \
		./src/t_stack_utils.c \
		./src/t_stacks.c \
		./src/index.c \
		./src/chunk_sort.c \
		./src/sort_three.c \
		./src/sort_five.c \
		./src/sort_utils.c \
		./src/free_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

LSANLIB = /LeakSanitizer/liblsan.a
lsan: CFLAGS += -ILeakSanitizer -Wno-gnu-include-next
lsan: LINK_FLAGS += -LLeakSanitizer -llsan -lc++
lsan: fclean $(LSANLIB)
lsan: all

$(LSANLIB):
	@if [ ! -d "LeakSanitizer" ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
	@$(MAKE) -C LeakSanitizer

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@git clone https://github.com/LaurinUB/libft
	@cd libft && make && make clean

debug : CFLAGS += -g

debug : re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ./libft

re: fclean all

.PHONY: all clean fclean re
