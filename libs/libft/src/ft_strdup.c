/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:57:23 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/10 11:38:20 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy (ptr, s1, len + 1);
	return (ptr);
}
