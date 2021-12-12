
CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = test.c \

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