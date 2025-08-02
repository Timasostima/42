#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "utils_dir/libft.h"

int ft_printf(const char *format, ...);

// Format handlers
int ft_print_char(char c);
int ft_print_str(char *s);
int ft_print_ptr(void *ptr);
int ft_print_int(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int n, int uppercase);
int ft_print_percent(void);

#endif