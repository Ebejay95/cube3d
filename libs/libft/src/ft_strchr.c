/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:48:38 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:36:44 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(char *s, int c)
{
	char	*ret;

	ret = NULL;
	if ((char)c == '\0')
		return (&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	if (!c)
		ret = s;
	return (ret);
}
