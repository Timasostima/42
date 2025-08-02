#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FILE_DESC 1

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int ft_printf(const char *format, ...);
int ft_handle_format(char c, va_list args);

int ft_print_char(char c);
int ft_print_str(char *s);
int ft_print_percent(void);

int ft_print_int(int n);
int ft_print_unsigned(unsigned int n);

int ft_print_hex(unsigned long long n, int uppercase);

int ft_print_ptr(void *ptr);

#endif