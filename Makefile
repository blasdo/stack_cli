SRCS = cli.c
NAME = stack_cli
LIBFT_PATH = libft
LIBFT_LIB_PATH = $(LIBFT_PATH)/lib
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)/include
LIBFT = $(LIBFT_PATH)/libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -fuse-ld=lld

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)
$(NAME): $(LIBFR)
	$(CC) -L$(LIBFT_LIB_PATH) -lft -I$(LIBFT_INCLUDE_PATH) $(SRCS) -o $(NAME)
