/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:36:17 by andreasjehl       #+#    #+#             */
/*   Updated: 2024/02/15 12:37:02 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	counter;

	counter = 0;
	if (!s || !f)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[counter] != '\0')
	{
		ptr[counter] = f(counter, s[counter]);
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
