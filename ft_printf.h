/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-los- <lde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:47:41 by lde-los-          #+#    #+#             */
/*   Updated: 2025/01/24 13:41:05 by lde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *f_arg, ...);
int		ft_putchar_cont(char c);
int		ft_strlen(char const *s);
int		ft_putstr_fd(char *s);
int		ft_putnbr(int a);
int		ft_putunbr(unsigned int a);
int		ft_puthex(unsigned int a, char *base);
int		ft_putptr(unsigned long long a, char *base);
int		flags(va_list arg, char const *str, char *base, char *upbase);

#endif