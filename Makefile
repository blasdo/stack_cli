SRCS = cli.c stack.c utils.c commands.c
NAME = stack_cli
LIBFT_PATH = libft
LIBFT_LIB_PATH = $(LIBFT_PATH)/lib
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)/include
LIBFT = $(LIBFT_LIB_PATH)/libft.a
CC = clang
INCLUDE_FLAGS = -I$(LIBFT_INCLUDE_PATH) 
CFLAGS = -g3 -Wall -Wextra -Werror $(INCLUDE_FLAGS)
LFLAGS =  -L$(LIBFT_LIB_PATH) -lft -lreadline
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(LIBFT):
	git submodule init libft
	git submodule update libft
	make -C $(LIBFT_PATH)
$(NAME): $(LIBFT) $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
clean:
	make -C $(LIBFT_PATH) fclean
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:	fclean all

.PHONY: clean fclean re all
