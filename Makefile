# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:12:23 by luntiet-          #+#    #+#              #
#    Updated: 2022/12/20 10:05:13 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRC_DIR = src
OBJ_DIR = obj
DIR_DUP = mkdir -p $(@D)

SRC = push_swap.c \
		utils.c \
		ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		t_stack.c \
		t_stack_utils.c \
		t_stacks.c \
		index.c \
		chunk_sort.c \
		sort_three.c \
		sort_five.c \
		sort_utils.c \
		free_utils.c

SRC := $(SRC:%=$(SRC_DIR)/%)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@if [ ! -d "libft" ]; then git clone https://github.com/LaurinUB/libft; fi
	@cd libft && make && make clean

debug : CFLAGS += -g

debug : re

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
