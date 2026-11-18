NAME		= 	so_long

SRCS		=	./srcs/mandatory/main.c				\
				./srcs/mandatory/backtracking.c		\
				./srcs/mandatory/errors.c			\
				./srcs/mandatory/graphics.c			\
				./srcs/mandatory/map_check.c		\
				./srcs/mandatory/map_set.c			\
				./srcs/mandatory/map.c				\
				./srcs/mandatory/player.c			\
				./srcs/mandatory/print.c

SRCS_BONUS	=	./srcs/bonus/main_bonus.c			\
				./srcs/bonus/backtracking_bonus.c	\
				./srcs/bonus/errors_bonus.c			\
				./srcs/bonus/graphics_bonus.c		\
				./srcs/bonus/map_bonus.c			\
				./srcs/bonus/map_check_bonus.c		\
				./srcs/bonus/map_set_bonus.c		\
				./srcs/bonus/player_bonus.c			\
				./srcs/bonus/print_bonus.c

OBJS 		=	$(SRCS:%.c=%.o)
OBJS_BONUS 	=	$(SRCS_BONUS:%.c=%.o)

HEADERS		= 	./includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
ARCH_FLAG	=	
LIBMLX_FLAGS=	-framework OpenGL -framework AppKit
RM			=	rm -f

LIBFT_PATH	=	../libft
LIBFT		=	../libft/libft.a

LIBMLX_PATH	=	./libmlx
LIBMLX_REPO	=	https://github.com/cedric06nice/minilibx_opengl.git
LIBMLX_REF	=	180712b
# Build MiniLibX for the native architecture (its Makefile forces x86_64).
LIBMLX_CFLAGS	=	"-O2 -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION -Wno-deprecated-non-prototype"
LIBMLX		=	./libmlx/libmlx.a $(LIBMLX_FLAGS)

INCLUDES	=	-I $(HEADERS) -I $(LIBFT_PATH)/includes -I $(LIBMLX_PATH)

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY		:	all clean fclean re bonus norm

%.o 		:	%.c
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) -c $< -o $@

all			:	$(NAME)

# MiniLibX (macOS, OpenGL) is fetched on first build, not stored in this repo.
$(LIBMLX_PATH)	:
				@git clone --quiet $(LIBMLX_REPO) $(LIBMLX_PATH)
				@git -C $(LIBMLX_PATH) checkout --quiet $(LIBMLX_REF)

$(OBJS) $(OBJS_BONUS)	:	| $(LIBMLX_PATH)

$(NAME)		: 	$(OBJS)
				@$(MAKE) -C $(LIBFT_PATH)
				@$(MAKE) -C $(LIBMLX_PATH) CFLAGS=$(LIBMLX_CFLAGS)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

bonus		: 	$(OBJS_BONUS)
				@$(MAKE) -C $(LIBFT_PATH)
				@$(MAKE) -C $(LIBMLX_PATH) CFLAGS=$(LIBMLX_CFLAGS)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) $(OBJS_BONUS) $(LIBFT) $(LIBMLX) -o $(NAME)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@$(MAKE) clean -C $(LIBFT_PATH)
				@if [ -d $(LIBMLX_PATH) ]; then $(MAKE) clean -C $(LIBMLX_PATH); fi
				@$(RM) $(OBJS) $(OBJS_BONUS)
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@$(MAKE) fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}

norm		:
				@norminette $(SRCS) $(SRCS_BONUS) $(HEADERS) $(LIBFT_PATH)
				@echo ${GREEN} "> ✅ Norminette done - $(NAME)" ${END}
