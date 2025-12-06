NAME = fract-ol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

MLX = mlx
MLX_LIB = $(MLX)/build/libmlx42.a
MLX_FLAGS = -L$(MLX) $(MLX_LIB) -lglfw -lm

FILES = main \
       parsing \
       parsing_utils \
       hooks \
       complex \
       fractal \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix ./objs/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

objs/%.o: %.c fract_ol.h
	mkdir -p objs
	$(CC) $(CFLAGS) -I $(LIBFT) -I mlx/include/MLX42/ -c $< -o $@

$(LIBFT_LIB): 
	if [ ! -d $(LIBFT) ]; then \
		echo "Cloning libft..."; \
		mkdir -p $(LIBFT) &&\
		cd $(LIBFT) && \
		git clone --depth=1 -n https://github.com/Timasostima/42.git && \
		cd 42 && \
		git sparse-checkout set cursus/Libft && \
		git checkout && \
		cd ../.. && \
		cp -r $(LIBFT)/42/cursus/Libft/* $(LIBFT)/ && \
		rm -rf $(LIBFT)/42; \
	fi
	make -C $(LIBFT)


$(MLX_LIB): 
	if [ ! -d $(MLX) ]; then \
		echo "Cloning mlx..."; \
		git clone --depth=1 https://github.com/codam-coding-college/MLX42.git $(MLX); \
	fi
	cd $(MLX) && cmake -B build && cmake --build build -j4

clean:
	$(RM)r objs/
	make -C $(LIBFT) clean
	rm -rf $(MLX)/build

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

erase_all: fclean
	$(RM)r $(LIBFT)
	$(RM)r $(MLX)

re: fclean all

.PHONY: all clean fclean re erase_all