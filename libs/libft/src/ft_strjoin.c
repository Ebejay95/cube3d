/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:46:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:36:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&join[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (join);
}
