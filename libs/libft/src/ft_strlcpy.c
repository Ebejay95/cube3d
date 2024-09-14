/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:39:45 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:36:57 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_s;
	size_t	counter;

	len_s = ft_strlen(src);
	counter = 0;
	if (!src || !dst)
		return (0);
	if (dstsize == 0)
		return (len_s);
	while (src[counter] && counter < (dstsize - 1))
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (len_s);
}
