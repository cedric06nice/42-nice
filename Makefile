# Builds every project in this repository. so_long needs macOS (MiniLibX/OpenGL).
PROJECTS	=	libft ft_printf minitalk push_swap philosophers
ifeq ($(shell uname -s),Darwin)
PROJECTS	+=	so_long
endif

.PHONY: all clean fclean re norm $(PROJECTS) get_next_line

all: $(PROJECTS) get_next_line

$(PROJECTS):
	@$(MAKE) --no-print-directory -C $@

# get_next_line is delivered as source files (no Makefile in the subject): compile its demo.
get_next_line:
	@cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c get_next_line/main.c -o get_next_line/gnl_demo
	@echo "get_next_line: get_next_line/gnl_demo built"

clean:
	@for p in $(PROJECTS); do $(MAKE) --no-print-directory -C $$p clean; done

fclean:
	@for p in $(PROJECTS); do $(MAKE) --no-print-directory -C $$p fclean; done
	@rm -f get_next_line/gnl_demo

re: fclean all

# 42's coding standard (pip install norminette)
norm:
	@norminette libft ft_printf/ft_*.c ft_printf/*.h get_next_line/get_next_line* \
		minitalk/srcs minitalk/includes so_long/srcs so_long/includes \
		push_swap/srcs push_swap/includes philosophers/srcs philosophers/includes \
		| grep -v 'OK!' || echo "norminette: all files OK"
