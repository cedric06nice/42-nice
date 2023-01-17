NAME		= 	push_swap

SRCS		=	./srcs/move_push.c			\
				./srcs/move_rev_rotate.c	\
				./srcs/move_rotate.c		\
				./srcs/move_swap.c			\
				./srcs/nodes_insert.c		\
				./srcs/nodes_maths.c		\
				./srcs/nodes_remove.c		\
				./srcs/nodes_utils.c		\
				./srcs/program_init.c		\
				./srcs/program_print.c		\
				./srcs/program_sort_large.c	\
				./srcs/program_sort.c		\
				./srcs/push_swap.c

OBJS 		=	$(SRCS:%.c=%.o)

INCLUDES	= 	-I ./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
ARCH_FLAG	=	-arch x86_64
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -f

LIBFT		=	./libft/libft.a
LIBFT_PATH	=	./libft

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re libft

libft		:
				@$(MAKE) -C $(LIBFT_PATH)

%.o 		:	%.c $(LIBFT)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) -c $< -o $@

all			:	libft $(NAME)

$(NAME)		: 	$(LIBFT) $(OBJS)
				@$(CC) $(ARCH_FLAG) $(INCLUDES) $(LIBFT) -o $(NAME) $(OBJS)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@$(RM) $(OBJS)
				@$(MAKE) -C $(LIBFT_PATH) clean
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@$(MAKE) -C $(LIBFT_PATH) fclean
				@$(RM) $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}
