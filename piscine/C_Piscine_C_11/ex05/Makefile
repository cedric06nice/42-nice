NAME	= 	do-op

SRCS	= 	main.c maths_func.c ft_atoi.c ft_func.c

HEADERS	= 	-I ./

OBJS	= 	${SRCS:.c=.o}

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
RMF		= 	rm -f

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${HEADERS} ${OBJS}

all:		${NAME}

clean:
			${RMF} ${OBJS}

fclean:		clean
			${RMF} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re