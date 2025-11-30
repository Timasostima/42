ORIG_DIR ?= ../Libft_og
LIB_NAME = libft.a
CC = cc
NAME = lib_tester
SRC = lib_tester.c
OBJ = $(SRC:.c=.o)

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(ORIG_DIR) all
	cp $(ORIG_DIR)/$(LIB_NAME) ./

$(NAME): $(OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_NAME) -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(ORIG_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(ORIG_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)
	$(MAKE) -C $(ORIG_DIR) fclean

re: fclean all

.PHONY: all clean fclean re