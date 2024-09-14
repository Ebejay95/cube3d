/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:53:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/08 15:46:55 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printing_function(va_list args, const char format)
{
	int	len;

	len = -1;
	if (format == 'c')
		len = ft_putchar_ret(va_arg(args, int));
	else if (format == 's')
		len = ft_putstr_ret(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = ft_putnbr_ret(va_arg(args, int));
	else if (format == 'p')
		len = ft_putptr_ret(va_arg(args, char *));
	else if (format == 'u')
		len = ft_conv(va_arg(args, unsigned int), "0123456789", 10);
	else if (format == 'x')
		len = ft_conv(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		len = ft_conv(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (format == '%')
		len = ft_putchar_ret('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		c;
	int		len;
	int		temp;

	c = 0;
	len = 0;
	va_start(arguments, str);
	while (str[c] != '\0')
	{
		if (str[c] == '%')
			temp = printing_function(arguments, str[c++ + 1]);
		else
			temp = ft_putchar_ret(str[c]);
		if (temp == -1)
		{
			len = -1;
			break ;
		}
		len += temp;
		c++;
	}
	va_end(arguments);
	return (len);
}
