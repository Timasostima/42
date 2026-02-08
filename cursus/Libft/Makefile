NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
ARFLAGS = rcs
OBJ_DIR = objs

# Character conversion functions
CHAR_FILES = toupper tolower
CHAR_SRCS = $(addprefix ./char/ft_, $(addsuffix .c, $(CHAR_FILES)))
CHAR_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(CHAR_FILES)))

# Check functions
CHECK_FILES = isalpha isdigit isalnum isascii isprint isspace isupper islower isint isfloat
CHECK_SRCS = $(addprefix ./checks/ft_, $(addsuffix .c, $(CHECK_FILES)))
CHECK_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(CHECK_FILES)))

# String manipulation functions
STRING_FILES = strlen strchr strrchr strncmp strcmp strnstr strlcpy strlcat strdup substr strjoin strtrim split free_split strmapi striteri
STRING_SRCS = $(addprefix ./string/ft_, $(addsuffix .c, $(STRING_FILES)))
STRING_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(STRING_FILES)))

# Memory manipulation functions
MEMORY_FILES = memset bzero memcpy memmove memchr memcmp calloc
MEMORY_SRCS = $(addprefix ./memory/ft_, $(addsuffix .c, $(MEMORY_FILES)))
MEMORY_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(MEMORY_FILES)))

# Output functions
OUTPUT_FILES = putchar_fd putstr_fd putendl_fd putnbr_fd
OUTPUT_SRCS = $(addprefix ./output/ft_, $(addsuffix .c, $(OUTPUT_FILES)))
OUTPUT_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(OUTPUT_FILES)))

# Conversion functions
CONVERSION_FILES = atoi atol atof itoa utoa
CONVERSION_SRCS = $(addprefix ./conversion/ft_, $(addsuffix .c, $(CONVERSION_FILES)))
CONVERSION_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(CONVERSION_FILES)))

# Printf functions
PRINTF_FILES = printf printf_char printf_hex printf_int printf_ptr
PRINTF_SRCS = $(addprefix ./printf/ft_, $(addsuffix .c, $(PRINTF_FILES)))
PRINTF_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(PRINTF_FILES)))

# List functions
LIST_FILES = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
LIST_SRCS = $(addprefix ./lists/ft_, $(addsuffix .c, $(LIST_FILES)))
LIST_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(LIST_FILES)))

# Array functions
ARRAYS_FILES = ariteri armapi arsize
ARRAYS_SRCS = $(addprefix ./arrays/ft_, $(addsuffix .c, $(ARRAYS_FILES)))
ARRAYS_OBJS = $(addprefix ./objs/ft_, $(addsuffix .o, $(ARRAYS_FILES)))

# Combine all sources and objects
SRCS = $(CHAR_SRCS) $(CHECK_SRCS) $(STRING_SRCS) $(MEMORY_SRCS) $(OUTPUT_SRCS) $(CONVERSION_SRCS) $(PRINTF_SRCS) $(LIST_SRCS) $(ARRAYS_SRCS)
OBJS = $(CHAR_OBJS) $(CHECK_OBJS) $(STRING_OBJS) $(MEMORY_OBJS) $(OUTPUT_OBJS) $(CONVERSION_OBJS) $(PRINTF_OBJS) $(LIST_OBJS) $(ARRAYS_OBJS)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# Character functions
./objs/ft_%.o: ./char/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Check functions
./objs/ft_%.o: ./checks/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# String functions
./objs/ft_%.o: ./string/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Memory functions
./objs/ft_%.o: ./memory/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Output functions
./objs/ft_%.o: ./output/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Conversion functions
./objs/ft_%.o: ./conversion/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Printf functions
./objs/ft_%.o: ./printf/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# List functions
./objs/ft_%.o: ./lists/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# List functions
./objs/ft_%.o: ./arrays/ft_%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: clean all

work: all clean

.PHONY: all clean fclean re work