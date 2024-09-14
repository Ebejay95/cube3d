/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:36:58 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/08 15:46:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_ret(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr_ret(char *s)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = 0;
	if (!s)
		return (ft_putstr_ret("(null)"));
	while (s[i] != '\0')
	{
		temp = ft_putchar_ret(s[i]);
		if (temp == -1)
		{
			len = -1;
			break ;
		}
		len += temp;
		i++;
	}
	return (len);
}

int	ft_putnbr_ret(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = n * (-1);
		len += 1;
	}
	if (n > 9)
	{
		len += ft_putnbr_ret(n / 10);
		if (len <= -1)
			return (-1);
	}
	len += ft_conv(n % 10, "0123456789", 10);
	if (len <= -1)
		return (-1);
	return (len);
}

int	ft_conv(size_t nbr, const char *base, size_t len_base)
{
	int	len;

	len = 0;
	if (nbr >= len_base)
	{
		len += ft_conv(nbr / len_base, base, len_base);
		if (len <= -1)
			return (-1);
		len += ft_putchar_ret(base[nbr % len_base]);
		if (len <= -1)
			return (-1);
	}
	else
		len += ft_putchar_ret(base[nbr]);
	if (len <= -1)
		return (-1);
	return (len);
}

int	ft_putptr_ret(char *ptr)
{
	int	len;
	int	temp;

	temp = ft_putstr_ret("0x");
	if (temp <= -1)
		return (-1);
	len = temp;
	temp = ft_conv((size_t)ptr, "0123456789abcdef", 16);
	if (temp <= -1)
		return (-1);
	len += temp;
	return (len);
}
