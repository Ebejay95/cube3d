/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:44:49 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/09 14:33:51 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// void	*gnl_calloc(size_t count, size_t size)
// {
// 	char	*ptr;
// 	size_t	i;

// 	i = 0;
// 	if (size == 0 || count == 0)
// 		return (NULL);
// 	if ((count != 0) && ((size * count) / count != size))
// 		return (NULL);
// 	ptr = malloc(size * count);
// 	if (!ptr)
// 		return (NULL);
// 	while (i < (size * count))
// 	{
// 		ptr[i] = 0;
// 		i++;
// 	}
// 	return (ptr);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	char	*ret;

// 	ret = NULL;
// 	if ((char)c == '\0')
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == (unsigned char)c)
// 			return (s);
// 		s++;
// 	}
// 	if (!c)
// 		ret = s;
// 	return (ret);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	len_s;
// 	size_t	counter;

// 	len_s = 0;
// 	while (src[len_s] != '\0')
// 		len_s++;
// 	counter = 0;
// 	if (!src || !dst)
// 		return (0);
// 	if (dstsize == 0)
// 		return (len_s);
// 	while (src[counter] && counter < (dstsize - 1))
// 	{
// 		dst[counter] = src[counter];
// 		counter++;
// 	}
// 	dst[counter] = '\0';
// 	return (len_s);
// }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	len;
// 	char	*ptr;

// 	len = 0;
// 	while (s1[len] != '\0')
// 		len++;
// 	ptr = (char *)malloc(sizeof(char) * len + 1);
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy (ptr, s1, len + 1);
// 	return (ptr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*join;
// 	size_t	len;
// 	int		str_len1;
// 	int		str_len2;

// 	len = 0;
// 	while (s1[len] != '\0')
// 		len++;
// 	str_len1 = len;
// 	len = 0;
// 	while (s2[len] != '\0')
// 		len++;
// 	str_len2 = len;
// 	len = str_len1 + str_len2;
// 	join = (char *)malloc(sizeof(char) * len + 1);
// 	if (!join)
// 		return (NULL);
// 	ft_strlcpy(join, s1, str_len1 + 1);
// 	ft_strlcpy(&join[str_len1], s2, str_len2 + 1);
// 	return (join);
// }
