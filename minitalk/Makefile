NAME_SERVER			= 	server

NAME_CLIENT			= 	client

SRCS_SERVER			=	./srcs/mandatory/server.c	\
						./srcs/errors.c
OBJS_SERVER 		=	$(SRCS_SERVER:%.c=%.o)

SRCS_CLIENT			=	./srcs/mandatory/client.c	\
						./srcs/errors.c
OBJS_CLIENT 		=	$(SRCS_CLIENT:%.c=%.o)

SRCS_SERVER_BONUS	=	./srcs/bonus/server_bonus.c	\
						./srcs/errors_bonus.c
OBJS_SERVER_BONUS 	=	$(SRCS_SERVER_BONUS:%.c=%.o)

SRCS_CLIENT_BONUS	=	./srcs/bonus/client_bonus.c	\
						./srcs/errors_bonus.c
OBJS_CLIENT_BONUS 	=	$(SRCS_CLIENT_BONUS:%.c=%.o)

HEADERS				= 	./includes

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
ARCH_FLAG			=	-arch x86_64
RM					=	rm -f

LIBFT_PATH			=	./libft
LIBFT				=	./libft/libft.a

INCLUDES			=	-I $(HEADERS) -I $(LIBFT_PATH)

RED					=	"\033[1;31m"
BLUE				=	"\033[1;34m"
YELLOW				=	"\033[1;33m"
WHITE				=	"\033[1;37m"
GREEN				=	"\033[1;32m"
PURPLE				=	"\033[1;35m"
CYAN				=	"\033[1;36m"
GRAY				=	"\033[1;30m"
END					=	"\033[0m"

.PHONY				:	all clean fclean re bonus

%.o 				:	%.c
						@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) -c $< -o $@

all					:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER)		: 	$(OBJS_SERVER)
						@$(MAKE) -C $(LIBFT_PATH)
						@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)
						@echo ${BLUE} "> 📚 Compilation finished - $(NAME_SERVER)" ${END}

$(NAME_CLIENT)		: 	$(OBJS_CLIENT)
						@$(MAKE) -C $(LIBFT_PATH)
						@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
						@echo ${BLUE} "> 📚 Compilation finished - $(NAME_CLIENT)" ${END}

bonus				:	bonus_server bonus_client

bonus_server		: 	$(OBJS_SERVER_BONUS)
						@$(MAKE) -C $(LIBFT_PATH)
						@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER)
						@echo ${BLUE} "> 📚 Compilation finished - $(NAME_SERVER)" ${END}

bonus_client		: 	$(OBJS_CLIENT_BONUS)
						@$(MAKE) -C $(LIBFT_PATH)
						@$(CC) $(CFLAGS) $(ARCH_FLAG) $(INCLUDES) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT)
						@echo ${BLUE} "> 📚 Compilation finished - $(NAME_CLIENT)" ${END}

clean				:
						@$(MAKE) clean -C $(LIBFT_PATH)
						@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
						@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME_SERVER) & $(NAME_CLIENT)" ${END}

fclean				:	clean
						@$(MAKE) fclean -C $(LIBFT_PATH)
						@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
						@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME_SERVER) & $(NAME_CLIENT)" ${END}

re					:	fclean all
