/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:49:32 by andreasjehl       #+#    #+#             */
/*   Updated: 2024/02/15 12:36:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	counter;

	counter = 0;
	if (!s)
		return ;
	while (s[counter] != '\0')
	{
		f(counter, &s[counter]);
		counter++;
	}
	return ;
}
