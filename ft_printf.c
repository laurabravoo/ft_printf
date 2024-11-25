/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-los- <lde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:26:46 by lde-los-          #+#    #+#             */
/*   Updated: 2024/11/25 15:00:25 by lde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *f_arg, ...)
{
	int		cont;
	va_list	arg;

	cont = 0;
	va_start(arg, f_arg);
	while (*f_arg != '\0')
	{
		if (*f_arg == '%')
		{
			f_arg++;
			if (*f_arg == 'c')
			{
				cont += ft_putchar_cont(va_arg(arg, int));
			}
			else if (*f_arg == 's')
			{
				cont += ft_putstr_fd(va_arg(arg, char *));
			}
			else if (*f_arg == 'd' || *f_arg == 'i')
			{
				cont += ft_putchar_cont(va_arg(arg, int) + '0');
			}
		}
		else
			cont += ft_putchar_cont(*f_arg);
		f_arg++;
	}
	va_end(arg);
	return (cont);
}
int	main()
{
	int	i = ft_printf("%s\n", "Laura no te duermas");
	printf("%i", i);
}

