/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_directions2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:58:17 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/05 20:21:52 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_looking_south(float angle)
{
	if (angle > 0 && angle < M_PI)
			return (1);
	return (0);
}

int is_looking_west(float angle)
{
	if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	return (0);
}
