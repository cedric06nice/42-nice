NAME		= 	test

SRCS		=	tests.c								\
				../srcs/bubble_sort.c				\
				../srcs/commands_print.c			\
				../srcs/commands.c					\
				../srcs/find_elements.c				\
				../srcs/get_max.c					\
				../srcs/get_min.c					\
				../srcs/init_stack.c				\
				../srcs/move_p.c					\
				../srcs/move_r.c					\
				../srcs/move_rr.c					\
				../srcs/move_s.c					\
				../srcs/node_get.c					\
				../srcs/node_insert.c				\
				../srcs/node_remove.c				\
				../srcs/node_set_average.c			\
				../srcs/node_sort.c					\
				../srcs/node_utils.c				\
				../srcs/parse_load.c				\
				../srcs/parse_transform.c			\
				../srcs/program_init.c				\
				../srcs/program_sort_large_utils.c	\
				../srcs/push_shortest.c				\
				../srcs/sort_large.c				\
				../srcs/sort.c						\
				../srcs/split_merge.c				\
				../srcs/x_print_testing.c


OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		= 	.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
ARCH_FLAG	=	-arch x86_64
RM			=	rm -f

LIBFT_PATH	=	../libft
LIBFT		=	../libft/libft.a

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

run			:	re
				@${MAKE} clean && ./$(NAME)
