/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:28:13 by andreasjehl       #+#    #+#             */
/*   Updated: 2024/02/15 12:35:35 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	temp = lst;
	if (!temp)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
