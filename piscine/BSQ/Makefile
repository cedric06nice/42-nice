NAME	= bsq
SRCS	= bsq.c ${wildcard ./srcs/*.c}
HEADERS	= ./includes

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RMF		= rm -f

.c.o:
			${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

#TODO: REMOVE

re :	fclean all

.PHONY:		all clean fclean re