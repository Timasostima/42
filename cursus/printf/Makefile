NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = 
AR = ar
ARFLAGS = rcs
UTILS_DIR = utils_dir
DEPENDENCIES = dependencies

FILES = printf \

OBJS = $(addprefix ./utils_dir/ft_, $(addsuffix .o, $(FILES)))

all: $(UTILS_DIR) dependencies $(NAME) 

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

./utils_dir/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $< libft.a

$(UTILS_DIR):
	mkdir -p $@

dependencies:
	cd $(UTILS_DIR) && git clone --depth=1 --no-checkout https://github.com/Timasostima/42.git && cd 42 && git sparse-checkout set cursus/Libft && git checkout 
	cp -r $(UTILS_DIR)/42/cursus/Libft $(UTILS_DIR) 
	rm -rf $(UTILS_DIR)/42
	cd $(UTILS_DIR)/Libft && make work
	cp $(UTILS_DIR)/Libft/libft.a ./

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: clean all

work: all clean

.PHONY: all clean fclean re work bonus