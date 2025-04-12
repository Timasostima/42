NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

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
		toupper \
		tolower \
		strchr \
		strrchr \
		strncmp \
		memchr \
		memcmp \
		strnstr \
		atoi \
		putchar_fd \
		putstr_fd \
		putendl_fd \

SRCS = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ./ft_, $(addsuffix .o, $(FILES)))

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re