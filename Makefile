# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 14:40:07 by jrossett          #+#    #+#              #
#    Updated: 2021/12/21 14:40:14 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c \

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

all: ${NAME} 

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re