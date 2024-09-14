/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:50:57 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:36:28 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*str;

	counter = 0;
	str = (unsigned char *)b;
	while (counter < len)
	{
		str[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}
