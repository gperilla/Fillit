# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 16:43:17 by gperilla          #+#    #+#              #
#    Updated: 2017/12/08 16:04:04 by gperilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

WARNINGS = -Werror -Wextra -Wall

LIB = -L libft/ -lft -I.

OBJC = main.c error.c lecture.c left4letters.c reset_map.c size_map.c resolv.c\
	   show_result.c

OBJ = $(OBJC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(WARNINGS) $(LIB) $(OBJ) -o $@

%.o: Rendu/%.c
	gcc -c $(WARNINGS) $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo 'removed .o'

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) .depend
	@echo 'All your base are belong to us'

re: fclean all

.PHONY: all clean fclean re
