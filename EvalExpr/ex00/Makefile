# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 16:45:27 by wweng             #+#    #+#              #
#    Updated: 2018/08/12 16:54:03 by wweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRCS = main.c
OBJECTS = main.o

all: $(NAME)
		
make_lib:
	gcc -c -Wall -Wextra -Werror $(SRCS)
	gcc $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
