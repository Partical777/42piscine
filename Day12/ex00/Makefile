# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 21:46:17 by wweng             #+#    #+#              #
#    Updated: 2018/08/08 21:52:28 by wweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEADERS = includes/ft.h

all: ft_display_file
		
make_lib:
	gcc -c -Wall -Wextra -Werror $(SRCS) -I $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

