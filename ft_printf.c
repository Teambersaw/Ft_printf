/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:55:30 by teambersaw        #+#    #+#             */
/*   Updated: 2021/12/13 19:38:21 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"





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

int ft_printf(const char *str, ...)
{
    va_list args;
    int     i;
    int     j;

    i = ft_length(str);
    j = 0;
    va_start(args, i);

    while (j < i)
    {
        va_arg(args, int);
        j++;
    }
    va_end(args);
}


#include <stdio.h>
int main()
{
    ft_printf("u");
    return (0);
}