/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:00:52 by teambersaw        #+#    #+#             */
/*   Updated: 2021/12/14 16:16:50 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA 0123456789abcdef
# define CHEXA 0123456789ABCDEF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *i);
void	ft_putstr(char *s, int *i);
void	ft_putnbr_us(unsigned int n, int *i);
void	ft_putnbr(int n, int *i);
int		ft_args(const char	*str, va_list args, int *i);

#endif