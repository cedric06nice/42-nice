NAME	= 	ft_display_file

SRCS	= 	main.c

OBJS	= 	${SRCS:.c=.o}

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
RMF		= 	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re