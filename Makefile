SRCS = cli.c utils.c error.c commands.c
NAME = stack_cli
LIBFT_PATH = libft
LIBFT_LIB_PATH = $(LIBFT_PATH)/lib
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)/include
LIBFT = $(LIBFT_LIB_PATH)/libft.a
CC = gcc
INCLUDE_FLAGS = -I$(LIBFT_INCLUDE_PATH) 
CFLAGS = -Wall -Wextra -Werror $(INCLUDE_FLAGS)
LDFLAGS = -fuse-ld=lld
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_LIB_PATH) -lft $(OBJS) -o $(NAME) 
clean:
	make -C $(LIBFT_PATH) fclean
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:	fclean all

.PHONY: clean fclean re all
