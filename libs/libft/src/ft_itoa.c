/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:42:24 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 09:58:23 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_leng(long nbr)
{
	int	counter;

	counter = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		counter++;
	}
	return (counter);
}

static int	check_pre(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void	fill_ptr(char *ptr, int pre, long nbr, int lengc)
{
	if (nbr == 0)
	{
		ptr[0] = '0';
		return ;
	}
	if (pre)
	{
		ptr[0] = '-';
		nbr = nbr * (-1);
	}
	ptr[lengc] = '\0';
	lengc--;
	while (nbr != 0)
	{
		ptr[lengc] = nbr % 10 + 48;
		nbr = nbr / 10;
		lengc--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		lengc;

	lengc = count_leng(n) + check_pre(n);
	ptr = NULL;
	ptr = (char *)ft_calloc(sizeof(char), (lengc + 1));
	if (!ptr)
		return (NULL);
	fill_ptr(ptr, check_pre(n), n, lengc);
	return (ptr);
}
