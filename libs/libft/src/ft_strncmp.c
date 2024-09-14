/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:19:18 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:37:05 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			c;
	int				diff;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	c = 0;
	while (c < n && ptr1[c] != '\0' && ptr2[c] != '\0')
	{
		diff = ft_memcmp(&ptr1[c], &ptr2[c], 1);
		if (diff != 0)
			return (diff);
		c++;
	}
	if (c == n)
		return (0);
	return (ptr1[c] - ptr2[c]);
}
