/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-los- <lde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:48:17 by lde-los-          #+#    #+#             */
/*   Updated: 2025/01/24 13:41:21 by lde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_cont(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putstr_fd(char *s)
{
	int	cont;

	cont = 0;
	if (!s)
		cont += write(1, "(null)", 6);
	else
		cont += write(1, s, ft_strlen(s));
	return (cont);
}

int	ft_putnbr(int a)
{
	int			cont;

	cont = 0;
	if (a == -2147483648)
	{
		cont += ft_putchar_cont('-');
		cont += ft_putchar_cont('2');
		cont += ft_putnbr(147483648);
	}
	else if (a < 0)
	{
		cont += ft_putchar_cont('-');
		a *= -1;
		cont += ft_putnbr(a);
	}
	else if (a >= 10)
	{
		cont += ft_putnbr(a / 10);
		cont += ft_putchar_cont((a % 10) + '0');
	}
	else
	{
		cont += ft_putchar_cont((a % 10) + '0');
	}
	return (cont);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putunbr(unsigned int a)
{
	int	cont;

	cont = 0;
	if (a >= 10)
	{
		cont += ft_putunbr(a / 10);
		cont += ft_putchar_cont((a % 10) + '0');
	}
	else
	{
		cont += ft_putchar_cont(a + '0');
	}
	return (cont);
}
