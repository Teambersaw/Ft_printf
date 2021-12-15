/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:02:35 by jrossett          #+#    #+#             */
/*   Updated: 2021/12/15 16:03:51 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long n, const char *base, int *i)
{
	size_t	j;

	j = ft_strlen(base);
	if (n < j)
		ft_putchar(base[n], i);
	else
	{
		ft_putnbr_base(n / j, base, i);
		ft_putnbr_base(n % j, base, i);
	}
}

void	ft_pointeur(void *str, int *i)
{
	unsigned long int	p;

	p = (unsigned long int)str;
	if (p == 0)
	{
		ft_putstr(NULL_PTR, i);
		return ;
	}
	ft_putstr("0x", i);
	ft_putnbr_base(p, HEXA, i);
}

void	ft_args(const char	*str, va_list args, int *i)
{	
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			ft_putchar(va_arg(args, int), i);
		if (*str == '%' && *(str + 1) == 's')
			ft_putstr(va_arg(args, char *), i);
		if (*str == '%' && *(str + 1) == 'p')
			ft_pointeur(va_arg(args, void *), i);
		if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
			ft_putnbr(va_arg(args, int), i);
		if (*str == '%' && *(str + 1) == 'u')
			ft_putnbr_us(va_arg(args, unsigned int), i);
		if (*str == '%' && *(str + 1) == 'x')
			ft_putnbr_base(va_arg(args, unsigned int), HEXA, i);
		if (*str == '%' && *(str + 1) == 'X')
			ft_putnbr_base(va_arg(args, unsigned int), CHEXA, i);
		if (*str == '%' && *(str + 1) == '%')
			ft_putchar(*str, i);
		if (*str == '%')
			str++;
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
/*
int	main(void)
{
	int i;
	char *str = 0;

	i = 0;
	printf("%p\n", str);
	ft_pointeur(str, &i);
	return (0);
}
*/