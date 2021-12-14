/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:02:35 by jrossett          #+#    #+#             */
/*   Updated: 2021/12/14 16:11:30 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_args(const char	*str, va_list args, int *i)
{	
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			ft_putchar(va_arg(args, int), i);
		else if (*str == '%' && *(str + 1) == 's')
			ft_putstr(va_arg(args, char *), i);
		else if (*str == '%' && *(str + 1) == 'p')
			va_arg(args, void *);
		else if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
			ft_putnbr(va_arg(args, int), i);
		else if (*str == '%' && *(str + 1) == 'u')
			ft_putnbr_us(va_arg(args, unsigned int), i);
		else if (*str == '%' && *(str + 1) == 'x')
			ft_putnbr_base(va_arg(args, int), HEXA, i);
		else if (*str == '%' && *(str + 1) == 'X')
			ft_putnbr_base(va_arg(args, int), CHEXA, i);
		else if (*str == '%' && *(str + 1) != '%')
			str++;
		else if (*str == '%' && *(str + 1) == '%')
			ft_putchar(*str++, i);
		else
			ft_putchar(*str, i);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	ft_args(str, args, &i);
	va_end(args);
	return (i);
}

int	main(void)
{
	char str[] = "coucou";
	printf("%p\n", str);
	printf("%lx", (unsigned long)str);
	ft_printf("u\n");
	return (0);
}
