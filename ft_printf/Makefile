NAME = 			libftprintf.a

HEADERS = 		.

PRINTF_PATH =	.
SRCS_PRINTF =	ft_printf.c				\
				ft_print_csdi.c			\
				ft_print_hex.c			\
				ft_print_p.c			\
				ft_print_uper.c

LIBFT_MAKE =	./libft
LIBFT_PATH =	libft/srcs
SRCS_LIBFT =	is/ft_isalnum.c			\
				is/ft_isalpha.c			\
				is/ft_isascii.c			\
				is/ft_isdigit.c			\
				is/ft_isprint.c			\
				math/ft_abs.c			\
				lst/ft_lstadd_back.c	\
				lst/ft_lstadd_front.c	\
				lst/ft_lstclear.c		\
				lst/ft_lstdelone.c		\
				lst/ft_lstiter.c		\
				lst/ft_lstlast.c		\
				lst/ft_lstmap.c			\
				lst/ft_lstnew.c			\
				lst/ft_lstsize.c		\
				mem/ft_bzero.c			\
				mem/ft_calloc.c			\
				mem/ft_memchr.c			\
				mem/ft_memcmp.c			\
				mem/ft_memcpy.c			\
				mem/ft_memmove.c		\
				mem/ft_memset.c			\
				put/ft_putchar_fd.c		\
				put/ft_putendl_fd.c		\
				put/ft_putnbr_base.c	\
				put/ft_putnbr_fd.c		\
				put/ft_putstr_fd.c		\
				str/ft_split.c			\
				str/ft_strchr.c			\
				str/ft_strdup.c			\
				str/ft_striteri.c		\
				str/ft_strjoin.c		\
				str/ft_strlcat.c		\
				str/ft_strlcpy.c		\
				str/ft_strlen.c			\
				str/ft_strmapi.c		\
				str/ft_strncmp.c		\
				str/ft_strnstr.c		\
				str/ft_strrchr.c		\
				str/ft_strrev.c			\
				str/ft_strtrim.c		\
				str/ft_substr.c			\
				to/ft_atoi.c			\
				to/ft_itoa.c			\
				to/ft_itoa_base.c		\
				to/ft_tolower.c			\
				to/ft_toupper.c

LIB_FT =		$(addprefix $(LIBFT_PATH)/, $(SRCS_LIBFT))
LIB_PF =		$(addprefix $(PRINTF_PATH)/, $(SRCS_PRINTF))

OBJS_LIBFT =	$(LIB_FT:.c=.o)
OBJS_PRINTF =	$(LIB_PF:.c=.o)

CC =			gcc
CFLAGS =		-Wall -Wextra -Werror
ARCH_FLAG =		
AR =			ar
ARFLAGS =		rcs

.c.o :
				@$(CC) $(CFLAGS) $(ARCH_FLAG) -I $(HEADERS) -c $< -o $(<:.c=.o)

.PHONY:			clean fclean all re

$(NAME):		$(OBJS_PRINTF) $(SRCS_PRINTF) $(OBJS_LIBFT)
				@make -C $(LIBFT_MAKE)
				@$(CC) $(CFLAGS) $(ARCH_FLAG) -c $(SRCS_PRINTF)
				@$(AR) $(ARFLAGS) $(NAME) $(OBJS_PRINTF) $(OBJS_LIBFT)
				@ranlib $(NAME)
				@echo "------| $(NAME) - Compilation finished |------"

all:			$(NAME)

clean:
				@make -C $(LIBFT_MAKE) clean
				@rm -rf $(OBJS_PRINTF)
				@echo "------| $(NAME) - Cleaning complete |------"

fclean:			clean
				@make -C $(LIBFT_MAKE) fclean
				@rm -rf $(NAME)

re:				fclean all
