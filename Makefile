# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 14:45:58 by dmylonas          #+#    #+#              #
#    Updated: 2021/10/24 17:50:47 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIB_PATH = ./Libft
LIB_NAME = libft.a

COMPILE = gcc -Wall -Werror -Wall -g -pthread -lreadline
COMPILE_DEV = gcc -g -pthread

SRCS = main.c \
	utils.c \
	ms_input_parser.c

all: $(LIB_NAME) $(NAME)

$(LIB_NAME): 
	make -C $(LIB_PATH)
	make -C $(LIB_PATH) clean

$(NAME): $(SRCS) minishell.h
	$(COMPILE_DEV) $(SRCS) -lreadline -L $(LIB_PATH) -lft -o $(NAME)

clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re