NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
CFILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OFILES = ${CFILES:.c=.o}
INC = includes

all: ${NAME}

${NAME} : ${OFILES}
	ar rcs ${NAME} ${OFILES}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@ -I ${INC}

clean:
	rm -f ${OFILES}

fclean: clean
	rm -f ${NAME}

re : fclean all
