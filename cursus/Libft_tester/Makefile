ORIG_DIR ?= ../Libft
LIB_NAME = libft.a

all: $(LIB_NAME)

$(LIB_NAME):
	$(MAKE) -C $(ORIG_DIR) all
	cp $(ORIG_DIR)/$(LIB_NAME) ./

clean:
	$(MAKE) -C $(ORIG_DIR) clean

fclean: clean
	rm -f $(LIB_NAME)
	$(MAKE) -C $(ORIG_DIR) fclean

re: fclean all

.PHONY: all clean fclean re