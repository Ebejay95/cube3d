/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:52:23 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:37:18 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	lenstr;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start > lenstr)
		return (ft_strdup(""));
	if (lenstr - start < len)
		len = lenstr - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
