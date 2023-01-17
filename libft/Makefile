NAME		=	libft.a

LDIR		=	srcs

SRCS		=	${LDIR}/ft_abs.c				\
				${LDIR}/ft_atoi.c				\
				${LDIR}/ft_bzero.c				\
				${LDIR}/ft_calloc.c				\
				${LDIR}/ft_factorial.c			\
				${LDIR}/ft_fibonacci.c			\
				${LDIR}/ft_free.c				\
				${LDIR}/ft_intlen.c				\
				${LDIR}/ft_is_prime.c			\
				${LDIR}/ft_isalnum.c			\
				${LDIR}/ft_isalpha.c			\
				${LDIR}/ft_isascii.c			\
				${LDIR}/ft_isdigit.c			\
				${LDIR}/ft_isprint.c			\
				${LDIR}/ft_itoa.c				\
				${LDIR}/ft_lstadd_back.c		\
				${LDIR}/ft_lstadd_front.c		\
				${LDIR}/ft_lstclear.c			\
				${LDIR}/ft_lstdelone.c			\
				${LDIR}/ft_lstiter.c			\
				${LDIR}/ft_lstlast.c			\
				${LDIR}/ft_lstmap.c				\
				${LDIR}/ft_lstnew.c				\
				${LDIR}/ft_lstsize.c			\
				${LDIR}/ft_malloc.c				\
				${LDIR}/ft_memchr.c				\
				${LDIR}/ft_memcmp.c				\
				${LDIR}/ft_memcpy.c				\
				${LDIR}/ft_memmove.c			\
				${LDIR}/ft_memset.c				\
				${LDIR}/ft_pow.c				\
				$(LDIR)/ft_printf.c				\
				${LDIR}/ft_putchar_fd.c			\
				${LDIR}/ft_putendl_fd.c			\
				${LDIR}/ft_putnbr_base.c		\
				${LDIR}/ft_putnbr_fd.c			\
				${LDIR}/ft_putstr_fd.c			\
				${LDIR}/ft_sort_int_tab.c		\
				${LDIR}/ft_split.c				\
				${LDIR}/ft_sqrt.c				\
				${LDIR}/ft_strchr.c				\
				${LDIR}/ft_strcmp.c				\
				${LDIR}/ft_strdup.c				\
				${LDIR}/ft_striteri.c			\
				${LDIR}/ft_strjoin.c			\
				${LDIR}/ft_strlcat.c			\
				${LDIR}/ft_strlcpy.c			\
				${LDIR}/ft_strlen.c				\
				${LDIR}/ft_strmapi.c			\
				${LDIR}/ft_strncmp.c			\
				${LDIR}/ft_strnstr.c			\
				${LDIR}/ft_strrchr.c			\
				${LDIR}/ft_strrev.c				\
				${LDIR}/ft_strtrim.c			\
				${LDIR}/ft_substr.c				\
				$(LDIR)/ft_swap.c				\
				${LDIR}/ft_tolower.c			\
				${LDIR}/ft_toupper.c			\
				$(LDIR)/ft_uitoa.c				\
				${LDIR}/ft_wordcount.c			\
				${LDIR}/get_next_line.c

OBJS 		=	$(SRCS:%.c=%.o)

HEADERS		=	./includes/

CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
ARCH_FLAG 	=	-arch x86_64
AR			=	ar
ARFLAGS		=	rcs

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
				@$(CC) $(CFLAGS) $(ARCH_FLAG) -I $(HEADERS) -c $< -o $@

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
