SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft_creator.sh

CC		= cc

CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c %< -o ${<:.c=.o}

${NAME}:	${OBJS}
			cc -o ${NAME} ${OBJS}

all:		