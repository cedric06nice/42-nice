NAME	= libft.a
SRCS	= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
HEADERS	= ./includes/ft.h

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	=	-Wall -Wextra -Werror
RMF		= rm -f

.c.o:
			${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${HEADERS} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re