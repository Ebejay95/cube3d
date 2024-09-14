/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:27:24 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:34:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	long	pre;

	nbr = 0;
	pre = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pre = pre * (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10;
		nbr = nbr + (*str - 48);
		str++;
	}
	return (pre * nbr);
}
