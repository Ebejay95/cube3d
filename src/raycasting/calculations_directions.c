/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_directions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:58:17 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/05 20:26:20 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_looking_right(float angle)
{
	if(angle >= 0 && angle < M_PI_2)
		return 1;
	return 0;
}

int is_looking_down(float angle)
{
	if(angle >= M_PI_2 && angle < M_PI)
		return 1;
	return 0;
}

int is_looking_left(float angle)
{
	if(angle >= M_PI && angle < 3 * M_PI_2)
		return 1;
	return 0;
}

int is_looking_up(float angle)
{
	if(angle >= 3 * M_PI_2 && angle < 2 * M_PI)
		return 1;
	return 0;
}
