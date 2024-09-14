/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:56:27 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:35:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destin;
	unsigned char	*source;

	destin = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (destin >= source)
	{
		while (len)
		{
			len--;
			destin[len] = source[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
