#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 22:20:08 by loucarpe          #+#    #+#              #
#    Updated: 2018/11/16 15:23:29 by jpelleti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

SRCS =	ft_memset.c					\
		ft_strcmp.c					\
		ft_strdup.c					\
		ft_strlen.c					\
		ft_strncmp.c				\
		ft_bzero.c					\
		ft_memcpy.c					\
		ft_memccpy.c				\
		ft_memmove.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_strcpy.c					\
		ft_strncpy.c				\
		ft_strcat.c					\
		ft_strncat.c				\
		ft_strlcat.c				\
		ft_strchr.c					\
		ft_strrchr.c				\
		ft_strstr.c					\
		ft_strnstr.c				\
		ft_atoi.c					\
		ft_isalpha.c				\
		ft_isdigit.c				\
		ft_isalnum.c				\
		ft_isascii.c				\
		ft_isprint.c				\
		ft_toupper.c				\
		ft_tolower.c				\
		ft_memalloc.c				\
		ft_memdel.c					\
		ft_strnew.c					\
		ft_strdel.c					\
		ft_strclr.c					\
		ft_striter.c				\
		ft_striteri.c				\
		ft_strmap.c					\
		ft_strmapi.c				\
		ft_strequ.c					\
		ft_strnequ.c				\
		ft_strsub.c					\
		ft_strjoin.c				\
		ft_strcrev.c				\
		ft_strtrim.c				\
		ft_iswap.c					\
		ft_strsplit.c				\
		ft_itoa.c					\
		ft_intlen.c					\
		ft_mesure_wor.c				\
		ft_mesure_let.c				\
		ft_cut_words.c				\
		ft_putchar.c				\
		ft_putstr.c					\
		ft_putendl.c				\
		ft_putnbr.c					\
		ft_putchar_fd.c				\
		ft_putstr_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_lstnew.c					\
		ft_lstdelone.c				\
		ft_lstdel.c					\
		ft_lstadd.c					\
		ft_lstiter.c				\
		ft_lstmap.c					\
		ft_putnbr_base.c			\
		ft_unsigned_nblen.c			\
		ft_putnbr_unsigned_base.c	\
		ft_power.c					\
		ft_printf.c					\
		parser.c					\
		misc_ptf.c					\
		find_fct.c					\
		alph.c						\
		num1.c						\
		misc_num1.c					\
		num2.c						\
		misc_num2.c					\
		misc_calc.c					\
		get_next_line.c				\
		ft_abs.c					

OBJ = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	@ar rc libft.a $(OBJ)
	@ranlib libft.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
