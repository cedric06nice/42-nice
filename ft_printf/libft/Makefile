NAME =		libft.a

HEADERS =	includes/libft.h

LDIR =		srcs

SRCS = 		${LDIR}/is/ft_isalnum.c			\
			${LDIR}/is/ft_isalpha.c			\
			${LDIR}/is/ft_isascii.c			\
			${LDIR}/is/ft_isdigit.c			\
			${LDIR}/is/ft_isprint.c			\
			${LDIR}/lst/ft_lstadd_back.c	\
			${LDIR}/lst/ft_lstadd_front.c	\
			${LDIR}/lst/ft_lstclear.c		\
			${LDIR}/lst/ft_lstdelone.c		\
			${LDIR}/lst/ft_lstiter.c		\
			${LDIR}/lst/ft_lstlast.c		\
			${LDIR}/lst/ft_lstmap.c			\
			${LDIR}/lst/ft_lstnew.c			\
			${LDIR}/lst/ft_lstsize.c		\
			${LDIR}/math/ft_abs.c			\
			${LDIR}/mem/ft_bzero.c			\
			${LDIR}/mem/ft_calloc.c			\
			${LDIR}/mem/ft_memchr.c			\
			${LDIR}/mem/ft_memcmp.c			\
			${LDIR}/mem/ft_memcpy.c			\
			${LDIR}/mem/ft_memmove.c		\
			${LDIR}/mem/ft_memset.c			\
			${LDIR}/put/ft_putchar_fd.c		\
			${LDIR}/put/ft_putendl_fd.c		\
			${LDIR}/put/ft_putnbr_base.c	\
			${LDIR}/put/ft_putnbr_fd.c		\
			${LDIR}/put/ft_putstr_fd.c		\
			${LDIR}/str/ft_split.c			\
			${LDIR}/str/ft_strchr.c			\
			${LDIR}/str/ft_strdup.c			\
			${LDIR}/str/ft_striteri.c		\
			${LDIR}/str/ft_strjoin.c		\
			${LDIR}/str/ft_strlcat.c		\
			${LDIR}/str/ft_strlcpy.c		\
			${LDIR}/str/ft_strlen.c			\
			${LDIR}/str/ft_strmapi.c		\
			${LDIR}/str/ft_strncmp.c		\
			${LDIR}/str/ft_strnstr.c		\
			${LDIR}/str/ft_strrchr.c		\
			${LDIR}/str/ft_strrev.c			\
			${LDIR}/str/ft_strtrim.c		\
			${LDIR}/str/ft_substr.c			\
			${LDIR}/to/ft_atoi.c			\
			${LDIR}/to/ft_itoa.c			\
			${LDIR}/to/ft_itoa_base.c		\
			${LDIR}/to/ft_tolower.c			\
			${LDIR}/to/ft_toupper.c

OBJS =		$(SRCS:.c=.o)

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
ARCH_FLAG =	-arch x86_64
AR =		ar
ARFLAGS =	rcs

.c.o :
			$(CC) $(CFLAGS) $(ARCH_FLAG) -I $(HEADERS) -c $< -o $(<:.c=.o)

.PHONY: 	all clean fclean re

$(NAME) :	$(OBJS)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			@echo "------| $(NAME) - Compilation finished |------"

all :		$(NAME)

clean :
			@rm -f $(OBJS)
			@echo "------| $(NAME) - Cleaning complete |------"

fclean :	clean
			@rm -f $(NAME)

re :		fclean all
