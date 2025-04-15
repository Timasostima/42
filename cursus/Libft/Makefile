NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJ_DIR = objs 

FILES = isalpha \
		isdigit \
		isalnum \
		isascii \
		isprint \
		strlen \
		memset \
		bzero \
		memcpy \
		memmove \
		strlcpy \
		strlcat \
		toupper \
		tolower \
		strchr \
		strrchr \
		strncmp \
		memchr \
		memcmp \
		strnstr \
		atoi \
		substr \
		putchar_fd \
		putstr_fd \
		putendl_fd \
		putnbr_fd \

SRCS = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(FILES)))

./objs/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(OBJ_DIR) $(NAME)

clean:
	$(RM) -rf objs

fclean: clean
	rm -f $(NAME)

work: all clean

re: clean all

.PHONY: all clean fclean re