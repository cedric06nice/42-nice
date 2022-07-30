NAME	= rush-02
SRCS	= ./*.c
HEADERS	= ./*.h

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	=	-Wall -Wextra -Werror
RMF		= rm -f

.c.o:
			${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${NAME} ${HEADERS} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re