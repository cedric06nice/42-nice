NAME		= 	so_long

SRCS_DIR	=	./srcs/
SRCS		=	./srcs/main.c

OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		= 	./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
ARCH_FLAG	=	-arch x86_64
LIBMLX_FLAGS=	-framework OpenGL -framework AppKit
RM			=	rm -f

LIBFT_PATH	=	./libft
LIBFT		=	./libft/libft.a

LIBMLX_PATH	=	./minilibx
LIBMLX		=	./minilibx/libmlx.a $(LIBMLX_FLAGS)

INCLUDES	=	-I $(HEADERS) -I $(LIBFT_PATH) -I $(LIBMLX_PATH)

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re

%.o 		:	%.c
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) -c $< -o $@

all			:	$(NAME)

$(NAME)		: 	$(OBJS)
				@$(MAKE) -C $(LIBFT_PATH)
				@$(MAKE) -C $(LIBMLX_PATH)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@$(MAKE) clean -C $(LIBFT_PATH)
				@$(MAKE) clean -C $(LIBMLX_PATH)
				@$(RM) $(OBJS)
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@$(MAKE) fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}
