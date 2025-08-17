# NAME = libftprintf.a

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# AR = ar
# ARFLAGS = rcs
# UTILS_DIR = utils_dir
# # LIBFT = libft
# DEPENDENCIES = $(LIBFT)/libft.a

# FILES = printf \
# 	printf_char \
# 	printf_ptr \
# 	printf_int \
# 	printf_hex \

# MIN_LIB = calloc \ 
# 	itoa \
# 	memset \
# 	putchar_fd \
# 	putstr_fd \
# 	strdup \
# 	strlen \

# OBJS = $(addprefix ./$(UTILS_DIR)/ft_, $(addsuffix .o, $(FILES)))
# LIB_OBJS = $(addprefix ./minlib/ft_, $(addsuffix .o, $(FILES)))

# all: $(UTILS_DIR)  $(NAME) 

# $(NAME): $(OBJS)
# 	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# ./$(UTILS_DIR)/%.o: ./%.c
# 	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIBFT)

# ./minlib/%.o: ./%.c
# 	$(CC) $(CFLAGS) -c -o $@ $< -I $(LIBFT)

# test: all
# 	$(CC) $(CFLAGS) test_printf.c libftprintf.a utils_dir/libft.a -I $(UTILS_DIR)

# $(UTILS_DIR):
# 	mkdir -p $@

# clean:
# 	rm -rf $(UTILS_DIR)
# 	rm -rf $(LIBFT)

# fclean: clean
# 	rm -f $(NAME)

# re: clean all

# work: all clean

# .PHONY: all clean fclean re work

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
ARFLAGS_EXTRACT = xvo
UTILS_DIR = utils_dir
LIBFT = libft
DEPENDENCIES = $(LIBFT)/libft.a

FILES = printf \
	printf_char \
	printf_ptr \
	printf_int \
	printf_hex \

OBJS = $(addprefix ./$(UTILS_DIR)/ft_, $(addsuffix .o, $(FILES)))

OBJS2 = $(shell cd $(UTILS_DIR) && $(AR) $(ARFLAGS_EXTRACT) ../$(DEPENDENCIES) | sed "s/x - /.\/$(UTILS_DIR)\//g") 

all: $(UTILS_DIR) $(LIBFT) $(DEPENDENCIES) $(NAME) 

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS2) $(OBJS)

	
./$(UTILS_DIR)/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -I$(LIBFT)

test: all
	$(CC) $(CFLAGS) test_printf.c libftprintf.a libft/libft.a -I. -I $(UTILS_DIR) -I $(LIBFT) -o test

$(UTILS_DIR):
	mkdir -p $@

$(LIBFT):
	mkdir -p $@

$(DEPENDENCIES):
	cd $(LIBFT) && git clone --depth=1 -n https://github.com/Timasostima/42.git && cd 42 && git sparse-checkout set cursus/Libft && git checkout 
	make -C $(LIBFT)/42/cursus/Libft work
	cp $(LIBFT)/42/cursus/Libft/* $(LIBFT)
	rm -rf $(LIBFT)/42

clean:
	rm -rf $(UTILS_DIR)
	rm -rf $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

work: all clean

.PHONY: all clean fclean re work