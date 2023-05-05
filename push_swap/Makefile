NAME		= 	push_swap

SRCS		=	./srcs/move_push.c					\
				./srcs/move_rev_rotate.c			\
				./srcs/move_rotate.c				\
				./srcs/move_swap.c					\
				./srcs/nodes_bubble_sort.c			\
				./srcs/nodes_get_average.c			\
				./srcs/nodes_get_max.c				\
				./srcs/nodes_get_min.c				\
				./srcs/nodes_insert.c				\
				./srcs/nodes_remove.c				\
				./srcs/nodes_utils.c				\
				./srcs/program_init.c				\
				./srcs/program_print.c				\
				./srcs/program_sort_large_utils.c	\
				./srcs/program_sort_large.c			\
				./srcs/program_sort.c				\
				./srcs/push_swap.c

OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		= 	./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
ARCH_FLAG	=	-arch x86_64
RM			=	rm -f

LIBFT_PATH	=	./libft
LIBFT		=	./libft/libft.a

INCLUDES	= 	-I $(HEADERS) -I $(LIBFT_PATH)

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re norm

%.o 		:	%.c
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) -c $< -o $@

all			:	$(NAME)

$(NAME)		: 	$(OBJS)
				@$(MAKE) -C $(LIBFT_PATH)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(OBJS) $(LIBFT) -o $(NAME)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@$(MAKE) clean -C $(LIBFT_PATH)
				@$(RM) $(OBJS)
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@$(MAKE) fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}

norm		:
				@norminette $(SRCS) $(HEADERS) $(LIBFT_PATH)
				@echo ${GREEN} "> ✅ Norminette done - $(NAME)" ${END}
