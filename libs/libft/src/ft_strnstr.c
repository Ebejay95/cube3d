/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:36:03 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:37:08 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*search(const char *haystack, const char *needle, size_t len)
{
	size_t	c_hay;
	size_t	c_ned;
	size_t	c_store;

	c_hay = 0;
	c_ned = 0;
	while (c_hay < len)
	{
		if (haystack[c_hay] == needle[c_ned])
		{
			c_store = c_hay;
			while (haystack[c_hay] == needle[c_ned] && c_hay < len)
			{
				c_hay++;
				c_ned++;
				if (needle[c_ned] == '\0')
					return ((char *)&haystack[c_store]);
			}
			c_ned = 0;
			c_hay = c_store;
		}
		c_hay++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0' || len < (size_t)ft_strlen(needle))
		return (NULL);
	return (search(haystack, needle, len));
}
