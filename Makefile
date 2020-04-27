# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 11:55:15 by jpelleti          #+#    #+#              #
#    Updated: 2019/06/13 10:12:16 by jpelleti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = jpelleti.filler

HEADER = includes

SRC_DIR = srcs

SRC_FILES = filler.c		\
			read.c			\
			misc.c			\
			battle_plan.c	\
			misc_battle.c	\
			misc_piece.c	\
			set_heatmap.c	

LIBFT_DIR = libft

OBJS_DIR = objs
OBJS_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "\n\033[0;33mCompiling jpelleti.filler.. \033[0;32mSuccess!\033m\017"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a
	@echo "\033[0;31m------------- [ \033[0;36mEVERYTHING IS OK \033[0;31m] -----------\033m\017\033[0m"

$(OBJS_DIR):
	@echo "\033[0;31m------ [ \033[0;35m$(NAME) by jpelleti && gjuste \033[0;31m] ------"
	@echo "\033[0;33mLinking Libft..\033[0m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0;32mSuccess!\n\033[0m"
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER)
	@echo "\033[0;33mCompiling $<.. \033[0;32mSuccess!\033m\017\033[0m"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
