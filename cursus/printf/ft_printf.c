#include "ft_printf.h"

// Helper function implementations
int ft_print_char(char c)
{
    ft_putchar_fd(c, 1);
    return 1;
}

int ft_print_str(char *s)
{
    int len;

    if (!s)
        s = "(null)";
    len = ft_strlen(s);
    ft_putstr_fd(s, 1);
    return len;
}

int ft_print_ptr(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    int printed = 0;
    char hex_digits[] = "0123456789abcdef";
    char buffer[20];
    int i = 0;

    if (!ptr)
    {
        ft_putstr_fd("(nil)", 1);
        return 5;
    }
    
    ft_putstr_fd("0x", 1);
    printed += 2;
    
    if (addr == 0)
    {
        ft_putchar_fd('0', 1);
        return printed + 1;
    }
    
    while (addr > 0)
    {
        buffer[i++] = hex_digits[addr % 16];
        addr /= 16;
    }
    
    while (--i >= 0)
    {
        ft_putchar_fd(buffer[i], 1);
        printed++;
    }
    
    return printed;
}

int ft_print_int(int n)
{
    char *str = ft_itoa(n);
    int len;

    if (!str)
        return 0;
    len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    free(str);
    return len;
}

int ft_print_unsigned(unsigned int n)
{
    char buffer[12];
    int i = 0;
    int printed = 0;

    if (n == 0)
    {
        ft_putchar_fd('0', 1);
        return 1;
    }
    
    while (n > 0)
    {
        buffer[i++] = '0' + (n % 10);
        n /= 10;
    }
    
    while (--i >= 0)
    {
        ft_putchar_fd(buffer[i], 1);
        printed++;
    }
    
    return printed;
}

int ft_print_hex(unsigned int n, int uppercase)
{
    char *hex_digits;
    char buffer[10];
    int i = 0;
    int printed = 0;

    if (uppercase)
        hex_digits = "0123456789ABCDEF";
    else
        hex_digits = "0123456789abcdef";
    
    if (n == 0)
    {
        ft_putchar_fd('0', 1);
        return 1;
    }
    
    while (n > 0)
    {
        buffer[i++] = hex_digits[n % 16];
        n /= 16;
    }
    
    while (--i >= 0)
    {
        ft_putchar_fd(buffer[i], 1);
        printed++;
    }
    
    return printed;
}

int ft_print_percent(void)
{
    ft_putchar_fd('%', 1);
    return 1;
}

int ft_handle_format(char c, va_list args)
{
    if (c == 'c')
        return ft_print_char(va_arg(args, int));
    if (c == 's')
        return ft_print_str(va_arg(args, char *));
    if (c == 'p')
        return ft_print_ptr(va_arg(args, void *));
    if (c == 'd' || c == 'i')
        return ft_print_int(va_arg(args, int));
    if (c == 'u')
        return ft_print_unsigned(va_arg(args, unsigned int));
    if (c == 'x')
        return ft_print_hex(va_arg(args, unsigned int), 0);
    if (c == 'X')
        return ft_print_hex(va_arg(args, unsigned int), 1);
    if (c == '%')
        return ft_print_percent();
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
            printed += ft_handle_format(format[++i], args);
        else
        {
            ft_putchar_fd(format[i], 1);
            printed++;
        }
        i++;
    }
    va_end(args);
    return printed;
}
