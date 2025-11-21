NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

SRCS = pipex.c \
	pipex_utils.c \
	path_utils.c

all: $(NAME)

$(NAME): $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -I $(LIBFT) -o $(NAME)

$(LIBFT):
	mkdir -p $@

$(LIBFT_LIB): $(LIBFT)
	cd $(LIBFT) && git clone --depth=1 -n https://github.com/Timasostima/42.git && cd 42 && git sparse-checkout set cursus/Libft && git checkout
	make -C $(LIBFT)/42/cursus/Libft work
	cp $(LIBFT)/42/cursus/Libft/* $(LIBFT)
	rm -rf $(LIBFT)/42

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re