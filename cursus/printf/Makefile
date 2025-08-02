NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = 
AR = ar
ARFLAGS = rcs
UTILS_DIR = utils_dir
DEPENDENCIES = $(UTILS_DIR)/libft.a

FILES = printf \

OBJS = $(addprefix ./$(UTILS_DIR)/ft_, $(addsuffix .o, $(FILES)))

all: $(UTILS_DIR) $(DEPENDENCIES) $(NAME) 

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

./$(UTILS_DIR)/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(UTILS_DIR):
	mkdir -p $@

$(DEPENDENCIES): $(UTILS_DIR) 
	cd $(UTILS_DIR) && git clone --depth=1 -n https://github.com/Timasostima/42.git && cd 42 && git sparse-checkout set cursus/Libft && git checkout 
	make -C $(UTILS_DIR)/42/cursus/Libft work
	cp $(UTILS_DIR)/42/cursus/Libft/libft.a $(UTILS_DIR)/42/cursus/Libft/libft.h $(UTILS_DIR)

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: clean all

work: all clean

.PHONY: all clean fclean re work bonus