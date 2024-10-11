/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:01:47 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/11 15:19:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cub3d_bonus.h"

/********************************************************/
/*	Function to check if angle is within radian values	*/
/********************************************************/
float	angle_check(float angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	else
		return (angle);
}

float	get_min(float a, float b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	is_blocked(t_game *game, int x, int y)
{
	char	cell;
	int		map_x;
	int		map_y;
	t_door	*door;

	cell = get_cellchar(game, x, y);
	if (cell == '1')
		return (1);
	if (cell == 'H' || cell == 'V')
	{
		map_x = x / CELL;
		map_y = y / CELL;
		door = get_door(game->map, map_x, map_y);
		if (door && !door->open)
			return (1);
	}
	return (0);
}
