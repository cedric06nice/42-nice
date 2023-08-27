NAME		= 	philo

SRCS		=	./srcs/ft_lists.c		\
				./srcs/print.c			\
				./srcs/main.c 			\
				./srcs/philo.c			\
				./srcs/utils.c

OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		= 	./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread #-fsanitize=thread
RM			=	rm -f

INCLUDES	=	-I $(HEADERS)

RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re norm

%.o 		:	%.c
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all			:	$(NAME)

$(NAME)		: 	$(OBJS)
				@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@$(RM) $(OBJS)
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@$(RM) $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}

norm		:
				@norminette $(SRCS) $(HEADERS) $(LIBFT_PATH)
				@echo ${GREEN} "> ✅ Norminette done - $(NAME)" ${END}
