#include <stdio.h>

void	ft_putstr_fd(char *s, int fd);

int ft_printf(const char *str, ...)
{
	ft_putstr_fd("hola", 1);
}

int main(int argc, char *argv[])
{
	printf("lalaal%c", 'c');
	ft_printf("lalaal%c", 'c');
}
