/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:11:50 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:37:14 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		startp;
	int		endp;

	startp = 0;
	endp = 0;
	while (s1[startp] && check_set(s1[startp], set))
		startp++;
	endp = ft_strlen(s1);
	while (endp > startp && check_set(s1[endp - 1], set))
		endp--;
	endp++;
	trim = (char *)malloc(sizeof(char) * (endp - startp));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[startp], endp - startp);
	return (trim);
}
