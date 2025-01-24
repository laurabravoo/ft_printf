/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-los- <lde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:46 by lde-los-          #+#    #+#             */
/*   Updated: 2025/01/24 13:40:54 by lde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_puthex(unsigned int a, char *base)
{
	char	resultado[16];
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	if (a == 0)
	{
		cont += ft_putchar_cont('0');
		return (cont);
	}
	while (a > 0)
	{
		resultado[i] = base[a % 16];
		a /= 16;
		i++;
	}
	while (i > 0)
	{
		cont += ft_putchar_cont(resultado[i - 1]);
		i--;
	}
	return (cont);
}

int	ft_putptr(unsigned long long a, char *base)
{
	char	resultado[18];
	int		i;
	int		cont;

	cont = 0;
	if (a == 0)
	{
		cont += write(1, "(nil)", 5);
		return (cont);
	}
	i = 2;
	while (a > 0)
	{
		resultado[i] = base[a % 16];
		a /= 16;
		i++;
	}
	cont += write(1, "0x", 2);
	while (i > 2)
	{
		cont += ft_putchar_cont(resultado[i - 1]);
		i--;
	}
	return (cont);
}

int	flags(va_list arg, char const *str, char *base, char *upbase)
{
	int	cont;

	cont = 0;
	if (*str == 'c')
		cont += ft_putchar_cont(va_arg(arg, int));
	else if (*str == 's')
		cont += ft_putstr_fd(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		cont += ft_putnbr(va_arg(arg, int));
	else if (*str == '%')
		cont += write(1, "%", 1);
	else if (*str == 'u')
		cont += ft_putunbr(va_arg(arg, unsigned int));
	else if (*str == 'x')
		cont += ft_puthex(va_arg(arg, unsigned int), base);
	else if (*str == 'X')
		cont += ft_puthex(va_arg(arg, unsigned int), upbase);
	else if (*str == 'p')
		cont += ft_putptr(va_arg(arg, unsigned long long), base);
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	int		cont;
	va_list	arg;
	char	*upbase;
	char	*base;

	base = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	cont = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			cont += flags(arg, str, base, upbase);
		}
		else
			cont += ft_putchar_cont(*str);
		str++;
	}
	va_end(arg);
	return (cont);
}
