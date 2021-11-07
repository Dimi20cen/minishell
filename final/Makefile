# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 13:23:33 by graja             #+#    #+#              #
#    Updated: 2021/11/07 13:36:53 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = Libft			
SRCS = $(wildcard srcs_and_h/*.c)
CC = clang
FLAGS = -g -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFT)
	make clean -C $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -L$(LIBFT) -lft -lreadline -o $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean: 
	make clean -C $(LIBFT)

re: fclean all