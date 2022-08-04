NAME	= 	bsq

SRCS	= 	bsq.c ./srcs/check_board.c ./srcs/check_first_line.c ./srcs/check_line_breaks.c ./srcs/errors.c ./srcs/file_exists.c ./srcs/file_size.c ./srcs/find_square.c ./srcs/ft_basic.c ./srcs/line_split.c ./srcs/print_board.c ./srcs/read_board.c

HEADERS	= 	-I ./includes/

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
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re