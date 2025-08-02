NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
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
		calloc \
		strdup \
		substr \
		strjoin \
		strtrim \
		split \
		itoa \
		utoa \
		strmapi \
		striteri \
		putchar_fd \
		putstr_fd \
		putendl_fd \
		putnbr_fd \

SRCS = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(FILES)))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

./objs/%.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: clean all

work: all clean

.PHONY: all clean fclean re work bonus