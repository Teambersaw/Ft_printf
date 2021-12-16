/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:09:18 by jrossett          #+#    #+#             */
/*   Updated: 2021/12/16 14:03:13 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putstr(char *s, int *i)
{
	int	j;

	j = 0;
	if (!s)
	{
		ft_putstr("(null)", i);
		return ;
	}
	while (s[j])
	{
		write(1, &s[j++], 1);
		*i += 1;
	}
}

void	ft_putnbr(int n, int *i)
{
	unsigned int	b;

	if (n < 0)
	{
		b = n * -1;
		write(1, "-", 1);
		*i += 1;
	}
	else
		b = n;
	if (b > 9)
	{
		ft_putnbr(b / 10, i);
		ft_putnbr(b % 10, i);
	}	
	if (b <= 9)
	{
		ft_putchar(b + '0', i);
	}
}

void	ft_putnbr_us(unsigned int n, int *i)
{
	if (n > 9)
	{
		ft_putnbr_us(n / 10, i);
		ft_putnbr_us(n % 10, i);
	}	
	if (n <= 9)
	{
		ft_putchar(n + '0', i);
	}
}
