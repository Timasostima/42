NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

SRCS = push_swap.c \
	swap_ops.c \
	push_ops.c \
	rotate_ops.c \
	reverse_rotate_ops.c \
	small_sort.c \
	utils.c \
	error_check.c \
	parse_args.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I $(LIBFT) -c $< -o $@

$(LIBFT_LIB): 
	@if [ ! -f $(LIBFT) ]; then \
		echo "Cloning libft..."; \
		mkdir -p $(LIBFT) &&\
		cd $(LIBFT) && \
		git clone --depth=1 -n https://github.com/Timasostima/42.git && \
		cd 42 && \
		git sparse-checkout set cursus/Libft && \
		git checkout && \
		cd ../.. && \
		echo "Building libft..." && \
		make -C $(LIBFT)/42/cursus/Libft work && \
		cp -r $(LIBFT)/42/cursus/Libft/* $(LIBFT)/ && \
		rm -rf $(LIBFT)/42; \
	fi

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft only_app