/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:57:28 by ajehle            #+#    #+#             */
/*   Updated: 2023/10/27 09:31:42 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_ret(int n);
int	ft_putchar_ret(char c);
int	ft_putstr_ret(char *s);
int	ft_conv(size_t nbr, const char *base, size_t len_base);
int	ft_putptr_ret(char *ptr);
#endif
