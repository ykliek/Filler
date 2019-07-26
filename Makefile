# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 07:50:01 by ykliek            #+#    #+#              #
#    Updated: 2019/07/26 12:27:26 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ykliek.filler

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

SRCS = main.c \
		reader.c

INCLUDE = ./includes/fdf.h

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean 
	@rm -rf fdf.h.gch

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

cleanlib:
	make -C libft clean

fcleanlib:
	make -C libft fclean

relib:
	make -C libft re

filler:
	@gcc $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
