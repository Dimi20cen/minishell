# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 13:23:33 by graja             #+#    #+#              #
#    Updated: 2021/10/25 11:42:33 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIBFT		= Libft
SRC		= init.c main.c utils.c ms_input_parser.c
CC		= gcc
FLAGS		= -Wall -Wextra -Werror -pthread 
RM		= rm -f

$(NAME)	:	$(SRC) $(LIBFT)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC) -L$(LIBFT) -lft -lreadline -o $(NAME)

all	: $(NAME)


fclean	: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean	: 
	make clean -C $(LIBFT)

re	: fclean all


