#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int ft_length(const char  *str)
{
    int length;
    int i;

    i = 0;
    length = 0;

    if (str == NULL)
        return (0);
    while (str[i])
    {
        if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'c' || str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x'))
        {
            length++;
            i += 2;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            ft_putchar_fd(str[i], 1);
            i += 2;
        }
        else
            ft_putchar_fd(str[i++], 1);
    }    
    return (length);
}

int main(void)
{
    const char  *str;

    str = "ou%ioui%%ou%zgrgr  efe feff ef \nio%dui"; 
    printf("\n%d\n", ft_length(str));
    return (0);
}