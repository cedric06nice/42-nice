NAME		=	libft.a

SRCS		=	srcs/ft_gnl/get_next_line.c		\
				srcs/ft_gnl/gnl_utils.c			\
				srcs/ft_is/ft_isalnum.c			\
				srcs/ft_is/ft_isalpha.c			\
				srcs/ft_is/ft_isascii.c			\
				srcs/ft_is/ft_isdigit.c			\
				srcs/ft_is/ft_isprint.c			\
				srcs/ft_lst/ft_lstadd_back.c	\
				srcs/ft_lst/ft_lstadd_front.c	\
				srcs/ft_lst/ft_lstclear.c		\
				srcs/ft_lst/ft_lstdelone.c		\
				srcs/ft_lst/ft_lstiter.c		\
				srcs/ft_lst/ft_lstlast.c		\
				srcs/ft_lst/ft_lstmap.c			\
				srcs/ft_lst/ft_lstnew.c			\
				srcs/ft_lst/ft_lstsize.c		\
				srcs/ft_mat/ft_abs.c			\
				srcs/ft_mat/ft_factorial.c		\
				srcs/ft_mat/ft_fibonacci.c		\
				srcs/ft_mat/ft_is_prime.c		\
				srcs/ft_mat/ft_pow.c			\
				srcs/ft_mat/ft_sqrt.c			\
				srcs/ft_mem/ft_bzero.c			\
				srcs/ft_mem/ft_calloc.c			\
				srcs/ft_mem/ft_free.c			\
				srcs/ft_mem/ft_malloc.c			\
				srcs/ft_mem/ft_memchr.c			\
				srcs/ft_mem/ft_memcmp.c			\
				srcs/ft_mem/ft_memcpy.c			\
				srcs/ft_mem/ft_memmove.c		\
				srcs/ft_mem/ft_memset.c			\
				srcs/ft_oth/ft_realloc.c		\
				srcs/ft_oth/ft_intlen.c			\
				srcs/ft_oth/ft_sort_int_tab.c	\
				srcs/ft_oth/ft_swap.c			\
				srcs/ft_oth/ft_wordcount.c		\
				srcs/ft_prf/ft_printf.c			\
				srcs/ft_prf/print_csdi.c		\
				srcs/ft_prf/print_hex.c			\
				srcs/ft_prf/print_p.c			\
				srcs/ft_prf/print_uper.c		\
				srcs/ft_put/ft_putchar_fd.c		\
				srcs/ft_put/ft_putendl_fd.c		\
				srcs/ft_put/ft_putnbr_base.c	\
				srcs/ft_put/ft_putnbr_fd.c		\
				srcs/ft_put/ft_putstr_fd.c		\
				srcs/ft_to/ft_atoi.c			\
				srcs/ft_to/ft_itoa.c			\
				srcs/ft_to/ft_tolower.c			\
				srcs/ft_to/ft_toupper.c			\
				srcs/ft_to/ft_uitoa.c			\
				srcs/ft_str/ft_strchr.c			\
				srcs/ft_str/ft_strcmp.c			\
				srcs/ft_str/ft_strdup.c			\
				srcs/ft_str/ft_striteri.c		\
				srcs/ft_str/ft_strjoin.c		\
				srcs/ft_str/ft_strlcat.c		\
				srcs/ft_str/ft_strlcpy.c		\
				srcs/ft_str/ft_strlen.c			\
				srcs/ft_str/ft_strmapi.c		\
				srcs/ft_str/ft_strncmp.c		\
				srcs/ft_str/ft_strnstr.c		\
				srcs/ft_str/ft_strrchr.c		\
				srcs/ft_str/ft_strrev.c			\
				srcs/ft_str/ft_strtrim.c		\
				srcs/ft_sub/ft_split.c			\
				srcs/ft_sub/ft_substr.c

OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		=	./includes/

CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	rcs
# compile for M1 Mac
CFLAGS		+= 	-arch x86_64

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
				@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

all			:	$(NAME)

$(NAME) 	:	$(OBJS) $(HEADERS)
				@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
				@echo ${BLUE} "> 📚 Compilation finished - $(NAME)" ${END}

clean		:
				@rm -f $(OBJS)
				@echo ${PURPLE} "> 🧹 *.o files removed - $(NAME)" ${END}

fclean		:	clean
				@rm -f $(NAME)
				@echo ${PURPLE} "> 🧹 Binaries removed - $(NAME)" ${END}

re 			:	fclean all
				@echo ${YELLOW} "> 📚 Remake done - $(NAME)" ${END}

norm		:
				@norminette $(SRCS) $(HEADERS)
				@echo ${GREEN} "> ✅ Norminette done - $(NAME)" ${END}
