#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int ft_result, printf_result;
    
    printf("=== Testing ft_printf ===\n\n");
    
    // Test character
    printf("Testing %%c:\n");
    ft_result = ft_printf("ft_printf: %c\n", 'A');
    printf_result = printf("printf:    %c\n", 'A');
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test string
    printf("Testing %%s:\n");
    ft_result = ft_printf("ft_printf: %s\n", "Hello World");
    printf_result = printf("printf:    %s\n", "Hello World");
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test NULL string
    printf("Testing %%s with NULL:\n");
    ft_result = ft_printf("ft_printf: %s\n", NULL);
    printf_result = printf("printf:    %s\n", "(null)");
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test integer
    printf("Testing %%i:\n");
    ft_result = ft_printf("ft_printf: %d\n", 42);
    printf_result = printf("printf:    %d\n", 42);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);

    
    // Test negative integer
    printf("Testing %%d with negative:\n");
    ft_result = ft_printf("ft_printf: %d\n", -42);
    printf_result = printf("printf:    %d\n", -42);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test unsigned
    printf("Testing %%u:\n");
    ft_result = ft_printf("ft_printf: %u\n", 42u);
    printf_result = printf("printf:    %u\n", 42u);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test hex lowercase
    printf("Testing %%x:\n");
    ft_result = ft_printf("ft_printf: %x\n", 16);
    printf_result = printf("printf:    %x\n", 16);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test hex uppercase
    printf("Testing %%X:\n");
    ft_result = ft_printf("ft_printf: %X\n", 255);
    printf_result = printf("printf:    %X\n", 255);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);

    
    // Test pointer
    printf("Testing %%p:\n");
    int var = 42;
    ft_result = ft_printf("ft_printf: %p\n", &var);
    printf_result = printf("printf:    %p\n", &var);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // Test NULL pointer
    printf("Testing %%p with NULL:\n");
    ft_result = ft_printf("ft_printf: %p\n", NULL);
    printf_result = printf("printf:    %p\n", NULL);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // // Test percent
    // printf("Testing %%%%:\n");
    // ft_result = ft_printf("ft_printf: %%\n");
    // printf_result = printf("printf:    %%\n");
    // printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    // // Test mixed
    // printf("Testing mixed format:\n");
    // ft_result = ft_printf("ft_printf: %s has %d apples and %u oranges (hex: %x)\n", "Alice", 5, 10u, 16);
    // printf_result = printf("printf:    %s has %d apples and %u oranges (hex: %x)\n", "Alice", 5, 10u, 16);
    // printf("ft_printf returned: %d, printf returned: %d\n\n", ft_result, printf_result);
    
    return 0;
}
