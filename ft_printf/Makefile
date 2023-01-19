# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 17:24:08 by vgoret            #+#    #+#              #
#    Updated: 2023/01/19 17:31:35 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = ft_printf.c ft_putstr.c ft_print_void.c ft_print_nb.c ft_print_unsigned.c \
	ft_print_hexa.c ft_print_pourc.c ft_putchar.c ft_strlen.c \
	ft_itoa.c

OBJ = ${SRC:.c=.o}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:${OBJ}
	ar rc ${NAME} ${OBJ}

all : ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re